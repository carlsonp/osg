// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Array>
#include <osg/CopyOp>
#include <osg/Geometry>
#include <osgUtil/TangentSpaceGenerator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::TangentSpaceGenerator)
	I_DeclaringFile("osgUtil/TangentSpaceGenerator");
	I_BaseType(osg::Referenced);
	I_Constructor0(____TangentSpaceGenerator,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgUtil::TangentSpaceGenerator &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____TangentSpaceGenerator__C5_TangentSpaceGenerator_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_MethodWithDefaults2(void, generate, IN, osg::Geometry *, geo, , IN, int, normal_map_tex_unit, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__generate__osg_Geometry_P1__int,
	                      "",
	                      "");
	I_Method0(osg::Vec4Array *, getTangentArray,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4Array_P1__getTangentArray,
	          "",
	          "");
	I_Method0(const osg::Vec4Array *, getTangentArray,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4Array_P1__getTangentArray,
	          "",
	          "");
	I_Method1(void, setTangentArray, IN, osg::Vec4Array *, array,
	          Properties::NON_VIRTUAL,
	          __void__setTangentArray__osg_Vec4Array_P1,
	          "",
	          "");
	I_Method0(osg::Vec4Array *, getNormalArray,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4Array_P1__getNormalArray,
	          "",
	          "");
	I_Method0(const osg::Vec4Array *, getNormalArray,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4Array_P1__getNormalArray,
	          "",
	          "");
	I_Method1(void, setNormalArray, IN, osg::Vec4Array *, array,
	          Properties::NON_VIRTUAL,
	          __void__setNormalArray__osg_Vec4Array_P1,
	          "",
	          "");
	I_Method0(osg::Vec4Array *, getBinormalArray,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4Array_P1__getBinormalArray,
	          "",
	          "");
	I_Method0(const osg::Vec4Array *, getBinormalArray,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4Array_P1__getBinormalArray,
	          "",
	          "");
	I_Method1(void, setBinormalArray, IN, osg::Vec4Array *, array,
	          Properties::NON_VIRTUAL,
	          __void__setBinormalArray__osg_Vec4Array_P1,
	          "",
	          "");
	I_Method0(osg::IndexArray *, getIndices,
	          Properties::NON_VIRTUAL,
	          __osg_IndexArray_P1__getIndices,
	          "",
	          "");
	I_ProtectedMethod7(void, compute, IN, osg::PrimitiveSet *, pset, IN, const osg::Array *, vx, IN, const osg::Array *, nx, IN, const osg::Array *, tx, IN, int, iA, IN, int, iB, IN, int, iC,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__compute__osg_PrimitiveSet_P1__C5_osg_Array_P1__C5_osg_Array_P1__C5_osg_Array_P1__int__int__int,
	                   "",
	                   "");
	I_SimpleProperty(osg::Vec4Array *, BinormalArray, 
	                 __osg_Vec4Array_P1__getBinormalArray, 
	                 __void__setBinormalArray__osg_Vec4Array_P1);
	I_SimpleProperty(osg::IndexArray *, Indices, 
	                 __osg_IndexArray_P1__getIndices, 
	                 0);
	I_SimpleProperty(osg::Vec4Array *, NormalArray, 
	                 __osg_Vec4Array_P1__getNormalArray, 
	                 __void__setNormalArray__osg_Vec4Array_P1);
	I_SimpleProperty(osg::Vec4Array *, TangentArray, 
	                 __osg_Vec4Array_P1__getTangentArray, 
	                 __void__setTangentArray__osg_Vec4Array_P1);
END_REFLECTOR

