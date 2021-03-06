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

#include <osg/Node>
#include <osg/NodeTrackerCallback>
#include <osg/NodeVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< osg::observer_ptr< osg::Node > >, osg::NodeTrackerCallback::ObserverNodePath)

BEGIN_OBJECT_REFLECTOR(osg::NodeTrackerCallback)
	I_DeclaringFile("osg/NodeTrackerCallback");
	I_BaseType(osg::NodeCallback);
	I_Constructor0(____NodeTrackerCallback,
	               "",
	               "");
	I_Method1(void, setTrackNodePath, IN, const osg::NodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNodePath__C5_osg_NodePath_R1,
	          "",
	          "");
	I_Method1(void, setTrackNodePath, IN, const osg::NodeTrackerCallback::ObserverNodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNodePath__C5_ObserverNodePath_R1,
	          "",
	          "");
	I_Method0(osg::NodeTrackerCallback::ObserverNodePath &, getTrackNodePath,
	          Properties::NON_VIRTUAL,
	          __ObserverNodePath_R1__getTrackNodePath,
	          "",
	          "");
	I_Method1(void, setTrackNode, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getTrackNode,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getTrackNode,
	          "",
	          "");
	I_Method0(const osg::Node *, getTrackNode,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getTrackNode,
	          "",
	          "");
	I_Method1(void, update, IN, osg::Node &, node,
	          Properties::NON_VIRTUAL,
	          __void__update__osg_Node_R1,
	          "Update the node to track the nodepath. ",
	          "");
	I_Method0(bool, validateNodePath,
	          Properties::NON_VIRTUAL,
	          __bool__validateNodePath,
	          "",
	          "");
	I_SimpleProperty(osg::Node *, TrackNode, 
	                 __osg_Node_P1__getTrackNode, 
	                 __void__setTrackNode__osg_Node_P1);
	I_SimpleProperty(osg::NodeTrackerCallback::ObserverNodePath &, TrackNodePath, 
	                 __ObserverNodePath_R1__getTrackNodePath, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::observer_ptr< osg::Node >)
	I_DeclaringFile("osg/observer_ptr");
	I_BaseType(osg::Observer);
	I_Constructor0(____observer_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::Node *, t,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::observer_ptr< osg::Node > &, rp,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__C5_observer_ptr_R1,
	               "",
	               "");
	I_Method1(void, objectDeleted, IN, void *, x,
	          Properties::VIRTUAL,
	          __void__objectDeleted__void_P1,
	          "",
	          "");
	I_Method0(osg::Node *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_SimpleProperty(osg::Node *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::observer_ptr< osg::Node > >)

