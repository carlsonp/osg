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

#include <osg/Geode>
#include <osg/Node>
#include <osgAnimation/Animation>
#include <osgAnimation/LinkVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgAnimation::LinkVisitor)
	I_DeclaringFile("osgAnimation/LinkVisitor");
	I_BaseType(osg::NodeVisitor);
	I_Constructor0(____LinkVisitor,
	               "",
	               "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the library name/namespapce of the visitor's. ",
	          "Should be defined by derived classes. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the visitor's class type. ",
	          "Should be defined by derived classes. ");
	I_Method1(void, apply, IN, osg::Node &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Node_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Geode &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Geode_R1,
	          "",
	          "");
	I_Method0(osgAnimation::AnimationList &, getAnimationList,
	          Properties::NON_VIRTUAL,
	          __AnimationList_R1__getAnimationList,
	          "",
	          "");
	I_Method0(void, reset,
	          Properties::VIRTUAL,
	          __void__reset,
	          "Method to call to reset visitor. ",
	          "Useful if your visitor accumulates state during a traversal, and you plan to reuse the visitor. To flush that state for the next traversal: call reset() prior to each traversal. ");
	I_Method0(unsigned int, getNbLinkedTarget,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNbLinkedTarget,
	          "",
	          "");
	I_ProtectedMethod1(void, handle_stateset, IN, osg::StateSet *, stateset,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__handle_stateset__osg_StateSet_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, link, IN, osgAnimation::AnimationUpdateCallbackBase *, cb,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__link__osgAnimation_AnimationUpdateCallbackBase_P1,
	                   "",
	                   "");
	I_SimpleProperty(osgAnimation::AnimationList &, AnimationList, 
	                 __AnimationList_R1__getAnimationList, 
	                 0);
	I_SimpleProperty(unsigned int, NbLinkedTarget, 
	                 __unsigned_int__getNbLinkedTarget, 
	                 0);
END_REFLECTOR

