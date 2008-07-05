/* OpenSceneGraph example, osgintersection.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*  THE SOFTWARE.
*/


#include "fixeddivision.h"

namespace fixeddivision
{

struct TriangleIndicesCollector
{
    TriangleIndicesCollector():
        _indices(0)
    {
    }

    inline void operator () (unsigned int v1, unsigned int v2, unsigned int v3)
    {
        _indices->push_back(v1);
        _indices->push_back(v2);
        _indices->push_back(v3);
    }
    
    Indices* _indices;

};

KDTree* KDTreeBuilder::createKDTree(osg::Geometry* geometry)
{
#ifdef VERBOSE_OUTPUT    
    osg::notify(osg::NOTICE)<<"osg::KDTreeBuilder::createKDTree()"<<std::endl;
#endif

    osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geometry->getVertexArray());
    if (!vertices) return 0;
    
    if (vertices->size() <= _targetNumVerticesPerLeaf) return 0;

    osg::ref_ptr<KDTree> kdTree = new KDTree;
    kdTree->_geometry = geometry;
    kdTree->_bb = kdTree->_geometry->getBound();
    kdTree->_vertices = vertices;
    
    unsigned int estimatedSize = (unsigned int)(2.0*float(vertices->size())/float(_targetNumVerticesPerLeaf));

#ifdef VERBOSE_OUTPUT    
    osg::notify(osg::NOTICE)<<"kdTree->_kdNodes.reserve()="<<estimatedSize<<std::endl<<std::endl;
#endif

    kdTree->_kdNodes.reserve(estimatedSize);
    kdTree->_kdLeaves.reserve(estimatedSize);
    
    computeDivisions(*kdTree);


    _numVerticesProcessed += vertices->size();

    if (_processTriangles)
    {

        osg::TriangleIndexFunctor<TriangleIndicesCollector> collectTriangleIndices;
        collectTriangleIndices._indices = &(kdTree->_vertexIndices);
        geometry->accept(collectTriangleIndices);

        KDPrimitiveLeaf* primitiveLeaf = createKDPrimitiveLeaf();
        primitiveLeaf->_indices.insert(primitiveLeaf->_indices.end(),
                                       kdTree->_vertexIndices.begin(),
                                       kdTree->_vertexIndices.end());

        // osg::notify(osg::NOTICE)<<"kdTree->_vertexIndices.size()="<<kdTree->_vertexIndices.size()<<std::endl;
        int leafNum = kdTree->addPrimitiveLeaf(primitiveLeaf);

        osg::BoundingBox bb = kdTree->_bb;
        int nodeNum = divideTriangles(*kdTree, bb, leafNum, 0);
    
        std::cout<<"_vertexIndices.size() = "<<kdTree->_vertexIndices.size()<<std::endl;
        std::cout<<"_primtiveLeaf.size() = "<<kdTree->_primitiveList.size()<<std::endl;
        unsigned int numIndices = 0;
        for(KDTree::KDPrimitiveList::iterator itr = kdTree->_primitiveList.begin();
            itr != kdTree->_primitiveList.end();
            ++itr)
        {
            numIndices += (*itr)->_indices.size();
        }
        std::cout<<"total numIndices = "<<numIndices<<std::endl;

        typedef std::map<Triangle, unsigned int> TriangleMap;
        TriangleMap triangleMap;
        for(KDTree::KDPrimitiveList::iterator itr = kdTree->_primitiveList.begin();
            itr != kdTree->_primitiveList.end();
            ++itr)
        {
            Indices& indices = (*itr)->_indices;
            for(unsigned int i=0; i<indices.size(); i+=3)
            {
                ++triangleMap[Triangle(indices[i],indices[i+1], indices[i+2])];
            }
        }

        int totalNumTriangles = triangleMap.size();
        int totalNumReferences = 0;
        for(TriangleMap::iterator tm_itr = triangleMap.begin();
            tm_itr != triangleMap.end();
            ++tm_itr)
        {   
            totalNumReferences += tm_itr->second;
        }
        std::cout<<"Average number of references = "<<double(totalNumReferences)/double(totalNumTriangles)<<std::endl;

    }
    else
    {
        kdTree->_vertexIndices.reserve(vertices->size());
        for(unsigned int i=0; i<vertices->size(); ++i)
        {
            kdTree->_vertexIndices.push_back(i);
        }



        KDLeaf leaf(0, kdTree->_vertexIndices.size());

        int leafNum = kdTree->addLeaf(leaf);

        osg::BoundingBox bb = kdTree->_bb;
        int nodeNum = dividePoints(*kdTree, bb, leafNum, 0);

    #ifdef VERBOSE_OUTPUT    
        osg::notify(osg::NOTICE)<<"Root nodeNum="<<nodeNum<<std::endl;
    #endif
    }
    
    
#ifdef VERBOSE_OUTPUT    
    
    KDTreeTraverser traverser;
    traverser.traverse(*kdTree);
    
    
    osg::notify(osg::NOTICE)<<"Final kdTree->_kdNodes.size()="<<kdTree->_kdNodes.size()<<std::endl;
    osg::notify(osg::NOTICE)<<"Final kdTree->_kdLeaves.size()="<<kdTree->_kdLeaves.size()<<std::endl;

    osg::notify(osg::NOTICE)<<"osg::KDTreeBuilder::createKDTree() completed"<<std::endl<<std::endl;
#endif

//    osg::notify(osg::NOTICE)<<"kdTree->_kdNodes.size()="<<kdTree->_kdNodes.size()<<"  estimated size = "<<estimatedSize<<std::endl;
//    osg::notify(osg::NOTICE)<<"kdTree->_kdLeaves.size()="<<kdTree->_kdLeaves.size()<<"  estimated size = "<<estimatedSize<<std::endl<<std::endl;



    return kdTree.release();
}    

void KDTreeBuilder::computeDivisions(KDTree& kdTree)
{


    osg::Vec3 dimensions(kdTree._bb.xMax()-kdTree._bb.xMin(),
                         kdTree._bb.yMax()-kdTree._bb.yMin(),
                         kdTree._bb.zMax()-kdTree._bb.zMin());

#ifdef VERBOSE_OUTPUT    
    osg::notify(osg::NOTICE)<<"computeDivisions("<<_maxNumLevels<<") "<<dimensions<< " { "<<std::endl;
#endif

    kdTree._axisStack.reserve(_maxNumLevels);
 
    int level = 0;
    for(unsigned int level=0; level<_maxNumLevels; ++level)
    {
        int axis = 0;
        if (dimensions[0]>=dimensions[1])
        {
            if (dimensions[0]>=dimensions[2]) axis = 0;
            else axis = 2;
        }
        else if (dimensions[1]>=dimensions[2]) axis = 1;
        else axis = 2;

        kdTree._axisStack.push_back(axis);
        dimensions[axis] /= 2.0f;

#ifdef VERBOSE_OUTPUT    
        osg::notify(osg::NOTICE)<<"  "<<level<<", "<<dimensions<<", "<<axis<<std::endl;
#endif
    }

#ifdef VERBOSE_OUTPUT    
    osg::notify(osg::NOTICE)<<"}"<<std::endl;
#endif
}

int KDTreeBuilder::divideTriangles(KDTree& kdTree, osg::BoundingBox& bb, int nodeIndex, unsigned int level)
{
    if (kdTree._axisStack.size()<=level) return nodeIndex;


    int axis = kdTree._axisStack[level];

#ifdef VERBOSE_OUTPUT    
    osg::notify(osg::NOTICE)<<"divideTriangles("<<nodeIndex<<", "<<level<< "), axis="<<axis<<std::endl;
#endif

    if (nodeIndex>=0)
    {
#ifdef VERBOSE_OUTPUT    
        osg::notify(osg::NOTICE)<<"  divide node"<<std::endl;
#endif
        KDNode& node = kdTree.getNode(nodeIndex);
        return nodeIndex;
    }
    else
    {    

        if (kdTree.getPrimitiveLeaf(nodeIndex)->_indices.size()<=_targetNumIndicesPerLeaf) return nodeIndex;

#ifdef VERBOSE_OUTPUT    
        osg::notify(osg::NOTICE)<<"  divide leaf"<<std::endl;
#endif
        
        int nodeNum = kdTree.addNode(KDNode());

        float original_min = bb._min[axis];
        float original_max = bb._max[axis];

        float mid = (original_min+original_max)*0.5f;

        {
            KDPrimitiveLeaf* leaf = kdTree.getPrimitiveLeaf(nodeIndex);

            osg::Vec3Array* vertices = kdTree._vertices.get();
            Indices& indices = leaf->_indices;

#ifdef VERBOSE_OUTPUT    
            osg::notify(osg::NOTICE)<<"  divide leaf->_indices.size()="<<leaf->_indices.size()<<std::endl;
#endif

            osg::ref_ptr<KDPrimitiveLeaf> leftLeaf = createKDPrimitiveLeaf();
            osg::ref_ptr<KDPrimitiveLeaf> rightLeaf = createKDPrimitiveLeaf();

            for(int i = 0; i<indices.size(); )
            {
                int numLeft = 0;
                int numRight = 0;

                int i1 = indices[i++];
                if ((*vertices)[i1][axis]<=mid) ++numLeft;
                else ++numRight;

                int i2 = indices[i++];
                if ((*vertices)[i2][axis]<=mid) ++numLeft;
                else ++numRight;

                int i3 = indices[i++];
                if ((*vertices)[i3][axis]<=mid) ++numLeft;
                else ++numRight;
                
                if (numLeft>0) 
                {
                    leftLeaf->_indices.push_back(i1);                    leftLeaf->_indices.push_back(i2);
                    leftLeaf->_indices.push_back(i3);
                }
                                
                if (numRight>0) 
                {
                    rightLeaf->_indices.push_back(i1);
                    rightLeaf->_indices.push_back(i2);
                    rightLeaf->_indices.push_back(i3);
                }
#if 0                
                if (numRight>0 && numLeft>0) 
                {
                    std::cout<<"In both"<<std::endl;
                }
                else
                {
                    std::cout<<"In one"<<std::endl;
                }
#endif
            }

            disposeKDPrimitiveLeaf(leaf);
            
 
            if (leftLeaf->_indices.empty())
            {
#ifdef VERBOSE_OUTPUT    
                osg::notify(osg::NOTICE)<<"LeftLeaf empty"<<std::endl;
#endif
                kdTree.getNode(nodeNum).first = 0;
                kdTree.getNode(nodeNum).second = kdTree.replacePrimitiveLeaf(nodeIndex, rightLeaf.get());
            }
            else if (rightLeaf->_indices.empty())
            {
#ifdef VERBOSE_OUTPUT    
                osg::notify(osg::NOTICE)<<"RightLeaf empty"<<std::endl;
#endif
                kdTree.getNode(nodeNum).first = kdTree.replacePrimitiveLeaf(nodeIndex, leftLeaf.get());
                kdTree.getNode(nodeNum).second = 0;
            }
            else
            {
                kdTree.getNode(nodeNum).first = kdTree.replacePrimitiveLeaf(nodeIndex, leftLeaf.get());
                kdTree.getNode(nodeNum).second = kdTree.addPrimitiveLeaf(rightLeaf.get());
            }
        }
        

        
        int originalLeftChildIndex = kdTree.getNode(nodeNum).first;
        int originalRightChildIndex = kdTree.getNode(nodeNum).second;


        float restore = bb._max[axis];
        bb._max[axis] = mid;

        //osg::notify(osg::NOTICE)<<"  divide leftLeaf "<<kdTree.getNode(nodeNum).first<<std::endl;
        int leftChildIndex = divideTriangles(kdTree, bb, originalLeftChildIndex, level+1);

        bb._max[axis] = restore;
        
        restore = bb._min[axis];
        bb._min[axis] = mid;

        //osg::notify(osg::NOTICE)<<"  divide rightLeaf "<<kdTree.getNode(nodeNum).second<<std::endl;
        int rightChildIndex = divideTriangles(kdTree, bb, originalRightChildIndex, level+1);
        
        bb._min[axis] = restore;
        
        kdTree.getNode(nodeNum).first = leftChildIndex;
        kdTree.getNode(nodeNum).second = rightChildIndex; 
        
        return nodeNum;        
    }


}



int KDTreeBuilder::dividePoints(KDTree& kdTree, osg::BoundingBox& bb, int nodeIndex, unsigned int level)
{
    if (kdTree._axisStack.size()<=level) return nodeIndex;


    int axis = kdTree._axisStack[level];

#ifdef VERBOSE_OUTPUT    
    //osg::notify(osg::NOTICE)<<"divide("<<nodeIndex<<", "<<level<< "), axis="<<axis<<std::endl;
#endif

    if (nodeIndex>=0)
    {
#ifdef VERBOSE_OUTPUT    
        osg::notify(osg::NOTICE)<<"  divide node"<<std::endl;
#endif
        KDNode& node = kdTree.getNode(nodeIndex);
        return nodeIndex;
    }
    else
    {    

        if (kdTree.getLeaf(nodeIndex).second<=_targetNumVerticesPerLeaf) return nodeIndex;

        //osg::notify(osg::NOTICE)<<"  divide leaf"<<std::endl;
        
        int nodeNum = kdTree.addNode(KDNode());

        float original_min = bb._min[axis];
        float original_max = bb._max[axis];

        float mid = (original_min+original_max)*0.5f;

        {
            KDLeaf& leaf = kdTree.getLeaf(nodeIndex);

            osg::Vec3Array* vertices = kdTree._vertices.get();

            //osg::notify(osg::NOTICE)<<"  divide leaf->_vertexIndices.size()="<<leaf->_vertexIndices.size()<<std::endl;

            int end = leaf.first+leaf.second-1;
            int left = leaf.first;
            int right = leaf.first+leaf.second-1;
            
            while(left<right)
            {
                while(left<right && ((*vertices)[kdTree._vertexIndices[left]])[axis]<=mid) { ++left; }
                
                while(left<right && ((*vertices)[kdTree._vertexIndices[right]])[axis]>mid) { --right; }

                if (left<right)
                {
                    std::swap(kdTree._vertexIndices[left], kdTree._vertexIndices[right]);
                    ++left;
                    --right;
                }
            }
            
            if (left==right)
            {
                if (((*vertices)[kdTree._vertexIndices[left]])[axis]<=mid) ++left;
                else --right;
            }
            
            KDLeaf leftLeaf(leaf.first, (right-leaf.first)+1);
            KDLeaf rightLeaf(left, (end-left)+1);

#if 0            
            osg::notify(osg::NOTICE)<<"In  leaf.first     ="<<leaf.first     <<" leaf.second     ="<<leaf.second<<std::endl;
            osg::notify(osg::NOTICE)<<"    leftLeaf.first ="<<leftLeaf.first <<" leftLeaf.second ="<<leftLeaf.second<<std::endl;
            osg::notify(osg::NOTICE)<<"    rightLeaf.first="<<rightLeaf.first<<" rightLeaf.second="<<rightLeaf.second<<std::endl;
            osg::notify(osg::NOTICE)<<"    left="<<left<<" right="<<right<<std::endl;

            if (leaf.second != (leftLeaf.second +rightLeaf.second))
            {
                osg::notify(osg::NOTICE)<<"*** Error in size, leaf.second="<<leaf.second
                                        <<", leftLeaf.second="<<leftLeaf.second
                                        <<", rightLeaf.second="<<rightLeaf.second<<std::endl;
            }
            else
            {
                osg::notify(osg::NOTICE)<<"Size OK, leaf.second="<<leaf.second
                                        <<", leftLeaf.second="<<leftLeaf.second
                                        <<", rightLeaf.second="<<rightLeaf.second<<std::endl;
            }
#endif
            if (leftLeaf.second<=0)
            {
                //osg::notify(osg::NOTICE)<<"LeftLeaf empty"<<std::endl;
                kdTree.getNode(nodeNum).first = 0;
                kdTree.getNode(nodeNum).second = kdTree.replaceLeaf(nodeIndex, rightLeaf);
            }
            else if (rightLeaf.second<=0)
            {
                //osg::notify(osg::NOTICE)<<"RightLeaf empty"<<std::endl;
                kdTree.getNode(nodeNum).first = kdTree.replaceLeaf(nodeIndex, leftLeaf);
                kdTree.getNode(nodeNum).second = 0;
            }
            else
            {
                kdTree.getNode(nodeNum).first = kdTree.replaceLeaf(nodeIndex, leftLeaf);
                kdTree.getNode(nodeNum).second = kdTree.addLeaf(rightLeaf);
            }
        }

        
        int originalLeftChildIndex = kdTree.getNode(nodeNum).first;
        int originalRightChildIndex = kdTree.getNode(nodeNum).second;


        float restore = bb._max[axis];
        bb._max[axis] = mid;

        //osg::notify(osg::NOTICE)<<"  divide leftLeaf "<<kdTree.getNode(nodeNum).first<<std::endl;
        int leftChildIndex = dividePoints(kdTree, bb, originalLeftChildIndex, level+1);

        bb._max[axis] = restore;
        
        restore = bb._min[axis];
        bb._min[axis] = mid;

        //osg::notify(osg::NOTICE)<<"  divide rightLeaf "<<kdTree.getNode(nodeNum).second<<std::endl;
        int rightChildIndex = dividePoints(kdTree, bb, originalRightChildIndex, level+1);
        
        bb._min[axis] = restore;
        
        kdTree.getNode(nodeNum).first = leftChildIndex;
        kdTree.getNode(nodeNum).second = rightChildIndex; 
        
        return nodeNum;        
    }


}

}