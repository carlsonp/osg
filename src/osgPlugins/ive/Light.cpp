/**********************************************************************
 *
 *    FILE:            Light.cpp
 *
 *    DESCRIPTION:    Read/Write osg::Light in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerated
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 21.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "Light.h"
#include "Object.h"

using namespace ive;

void Light::write(DataOutputStream* out){
    // Write Light's identification.
    out->writeInt(IVELIGHT);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Object*  obj = dynamic_cast<osg::Object*>(this);
    if(obj){
        ((ive::Object*)(obj))->write(out);
    }
    else
        throw Exception("Light::write(): Could not cast this osg::Light to an osg::Object.");
    // Write Light's properties.
    out->writeInt(getLightNum());
    out->writeVec4(getAmbient());
    out->writeVec4(getDiffuse());
    out->writeVec4(getSpecular());
    out->writeVec4(getPosition());
    out->writeVec3(getDirection());
    out->writeFloat(getConstantAttenuation());
    out->writeFloat(getLinearAttenuation ());
    out->writeFloat(getQuadraticAttenuation());
    out->writeFloat(getSpotExponent());
    out->writeFloat(getSpotCutoff());

}

void Light::read(DataInputStream* in){
    // Peek on Light's identification.
    int id = in->peekInt();
    if(id == IVELIGHT){
        // Read Light's identification.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::Object*  obj = dynamic_cast<osg::Object*>(this);
        if(obj){
            ((ive::Object*)(obj))->read(in);
        }
        else
            throw Exception("Light::read(): Could not cast this osg::Light to an osg::Object.");
        // Read Light's properties
        setLightNum(in->readInt());
        setAmbient(in->readVec4());
        setDiffuse(in->readVec4());
        setSpecular(in->readVec4());
        setPosition(in->readVec4());
        setDirection(in->readVec3());
        setConstantAttenuation(in->readFloat());
        setLinearAttenuation (in->readFloat());
        setQuadraticAttenuation(in->readFloat());
        setSpotExponent(in->readFloat());
        setSpotCutoff(in->readFloat());
    }
    else{
        throw Exception("Light::read(): Expected Light identification.");
    }
}
