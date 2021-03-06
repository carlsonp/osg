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

#include <osgWidget/EventInterface>
#include <osgWidget/Widget>
#include <osgWidget/Window>
#include <osgWidget/WindowManager>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgWidget::Callback)
	I_DeclaringFile("osgWidget/EventInterface");
	I_BaseType(osg::Referenced);
	I_Constructor0(____Callback,
	               "",
	               "");
	I_Constructor1(IN, const osgWidget::Callback &, rhs,
	               Properties::NON_EXPLICIT,
	               ____Callback__C5_Callback_R1,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, osgWidget::EventType, type, , IN, void *, data, 0,
	                           ____Callback__EventType__void_P1,
	                           "",
	                           "");
	I_Method0(osgWidget::EventType, getType,
	          Properties::NON_VIRTUAL,
	          __EventType__getType,
	          "",
	          "");
	I_Method0(void *, getData,
	          Properties::NON_VIRTUAL,
	          __void_P1__getData,
	          "",
	          "");
	I_Method0(const void *, getData,
	          Properties::NON_VIRTUAL,
	          __C5_void_P1__getData,
	          "",
	          "");
	I_SimpleProperty(void *, Data, 
	                 __void_P1__getData, 
	                 0);
	I_SimpleProperty(osgWidget::EventType, Type, 
	                 __EventType__getType, 
	                 0);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgWidget::CallbackInterface)
	I_DeclaringFile("osgWidget/EventInterface");
	I_BaseType(osg::Referenced);
	I_Constructor0(____CallbackInterface,
	               "",
	               "");
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgWidget::Event)
	I_DeclaringFile("osgWidget/EventInterface");
	I_ConstructorWithDefaults2(IN, osgWidget::WindowManager *, wm, , IN, osgWidget::EventType, _type, osgWidget::EVENT_NONE,
	                           ____Event__WindowManager_P1__EventType,
	                           "",
	                           "");
	I_Method1(osgWidget::Event &, makeType, IN, osgWidget::EventType, _type,
	          Properties::NON_VIRTUAL,
	          __Event_R1__makeType__EventType,
	          "",
	          "");
	I_MethodWithDefaults3(osgWidget::Event &, makeMouse, IN, double, _x, , IN, double, _y, , IN, osgWidget::EventType, _type, osgWidget::EVENT_NONE,
	                      Properties::NON_VIRTUAL,
	                      __Event_R1__makeMouse__double__double__EventType,
	                      "",
	                      "");
	I_MethodWithDefaults3(osgWidget::Event &, makeKey, IN, int, _key, , IN, int, _keyMask, , IN, osgWidget::EventType, _type, osgWidget::EVENT_NONE,
	                      Properties::NON_VIRTUAL,
	                      __Event_R1__makeKey__int__int__EventType,
	                      "",
	                      "");
	I_Method0(osgWidget::WindowManager *, getWindowManager,
	          Properties::NON_VIRTUAL,
	          __WindowManager_P1__getWindowManager,
	          "",
	          "");
	I_Method0(const osgWidget::WindowManager *, getWindowManager,
	          Properties::NON_VIRTUAL,
	          __C5_WindowManager_P1__getWindowManager,
	          "",
	          "");
	I_Method0(osgWidget::Window *, getWindow,
	          Properties::NON_VIRTUAL,
	          __Window_P1__getWindow,
	          "",
	          "");
	I_Method0(const osgWidget::Window *, getWindow,
	          Properties::NON_VIRTUAL,
	          __C5_Window_P1__getWindow,
	          "",
	          "");
	I_Method0(osgWidget::Widget *, getWidget,
	          Properties::NON_VIRTUAL,
	          __Widget_P1__getWidget,
	          "",
	          "");
	I_Method0(const osgWidget::Widget *, getWidget,
	          Properties::NON_VIRTUAL,
	          __C5_Widget_P1__getWidget,
	          "",
	          "");
	I_Method0(void *, getData,
	          Properties::NON_VIRTUAL,
	          __void_P1__getData,
	          "",
	          "");
	I_Method0(const void *, getData,
	          Properties::NON_VIRTUAL,
	          __C5_void_P1__getData,
	          "",
	          "");
	I_Method1(void, setData, IN, void *, data,
	          Properties::NON_VIRTUAL,
	          __void__setData__void_P1,
	          "",
	          "");
	I_SimpleProperty(void *, Data, 
	                 __void_P1__getData, 
	                 __void__setData__void_P1);
	I_SimpleProperty(osgWidget::Widget *, Widget, 
	                 __Widget_P1__getWidget, 
	                 0);
	I_SimpleProperty(osgWidget::Window *, Window, 
	                 __Window_P1__getWindow, 
	                 0);
	I_SimpleProperty(osgWidget::WindowManager *, WindowManager, 
	                 __WindowManager_P1__getWindowManager, 
	                 0);
	I_PublicMemberProperty(osgWidget::EventType, type);
	I_PublicMemberProperty(double, x);
	I_PublicMemberProperty(double, y);
	I_PublicMemberProperty(int, key);
	I_PublicMemberProperty(int, keyMask);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgWidget::EventInterface)
	I_DeclaringFile("osgWidget/EventInterface");
	I_Constructor0(____EventInterface,
	               "",
	               "");
	I_Constructor1(IN, const osgWidget::EventInterface &, ei,
	               Properties::NON_EXPLICIT,
	               ____EventInterface__C5_EventInterface_R1,
	               "",
	               "");
	I_Method1(bool, focus, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__focus__WindowManager_P1,
	          "",
	          "");
	I_Method1(bool, unfocus, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__unfocus__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mouseEnter, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mouseEnter__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mouseOver, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mouseOver__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mouseLeave, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mouseLeave__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mouseDrag, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mouseDrag__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mousePush, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mousePush__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mouseRelease, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mouseRelease__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, mouseScroll, IN, double, x, IN, double, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__mouseScroll__double__double__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, keyDown, IN, int, x, IN, int, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__keyDown__int__int__WindowManager_P1,
	          "",
	          "");
	I_Method3(bool, keyUp, IN, int, x, IN, int, x, IN, osgWidget::WindowManager *, x,
	          Properties::VIRTUAL,
	          __bool__keyUp__int__int__WindowManager_P1,
	          "",
	          "");
	I_Method1(void, setEventMask, IN, unsigned int, mask,
	          Properties::NON_VIRTUAL,
	          __void__setEventMask__unsigned_int,
	          "",
	          "");
	I_Method1(void, addEventMask, IN, unsigned int, mask,
	          Properties::NON_VIRTUAL,
	          __void__addEventMask__unsigned_int,
	          "",
	          "");
	I_Method1(void, removeEventMask, IN, unsigned int, mask,
	          Properties::NON_VIRTUAL,
	          __void__removeEventMask__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getEventMask,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getEventMask,
	          "",
	          "");
	I_Method1(void, addCallback, IN, osgWidget::Callback *, cb,
	          Properties::NON_VIRTUAL,
	          __void__addCallback__Callback_P1,
	          "",
	          "");
	I_Method1(bool, callCallbacks, IN, osgWidget::Event &, ev,
	          Properties::NON_VIRTUAL,
	          __bool__callCallbacks__Event_R1,
	          "",
	          "");
	I_Method1(bool, callMethodAndCallbacks, IN, osgWidget::Event &, ev,
	          Properties::NON_VIRTUAL,
	          __bool__callMethodAndCallbacks__Event_R1,
	          "",
	          "");
	I_Method0(bool, canFocus,
	          Properties::NON_VIRTUAL,
	          __bool__canFocus,
	          "",
	          "");
	I_Method0(bool, canUnfocus,
	          Properties::NON_VIRTUAL,
	          __bool__canUnfocus,
	          "",
	          "");
	I_Method0(bool, canMouseEnter,
	          Properties::NON_VIRTUAL,
	          __bool__canMouseEnter,
	          "",
	          "");
	I_Method0(bool, canMouseOver,
	          Properties::NON_VIRTUAL,
	          __bool__canMouseOver,
	          "",
	          "");
	I_Method0(bool, canMouseLeave,
	          Properties::NON_VIRTUAL,
	          __bool__canMouseLeave,
	          "",
	          "");
	I_Method0(bool, canMouseDrag,
	          Properties::NON_VIRTUAL,
	          __bool__canMouseDrag,
	          "",
	          "");
	I_Method0(bool, canMousePush,
	          Properties::NON_VIRTUAL,
	          __bool__canMousePush,
	          "",
	          "");
	I_Method0(bool, canMouseRelease,
	          Properties::NON_VIRTUAL,
	          __bool__canMouseRelease,
	          "",
	          "");
	I_Method0(bool, canMouseScroll,
	          Properties::NON_VIRTUAL,
	          __bool__canMouseScroll,
	          "",
	          "");
	I_Method0(bool, canKeyDown,
	          Properties::NON_VIRTUAL,
	          __bool__canKeyDown,
	          "",
	          "");
	I_Method0(bool, canKeyUp,
	          Properties::NON_VIRTUAL,
	          __bool__canKeyUp,
	          "",
	          "");
	I_SimpleProperty(unsigned int, EventMask, 
	                 __unsigned_int__getEventMask, 
	                 __void__setEventMask__unsigned_int);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgWidget::EventType)
	I_DeclaringFile("osgWidget/EventInterface");
	I_EnumLabel(osgWidget::EVENT_NONE);
	I_EnumLabel(osgWidget::EVENT_FOCUS);
	I_EnumLabel(osgWidget::EVENT_UNFOCUS);
	I_EnumLabel(osgWidget::EVENT_MOUSE_ENTER);
	I_EnumLabel(osgWidget::EVENT_MOUSE_OVER);
	I_EnumLabel(osgWidget::EVENT_MOUSE_LEAVE);
	I_EnumLabel(osgWidget::EVENT_MOUSE_DRAG);
	I_EnumLabel(osgWidget::EVENT_MOUSE_PUSH);
	I_EnumLabel(osgWidget::EVENT_MOUSE_RELEASE);
	I_EnumLabel(osgWidget::EVENT_MOUSE_SCROLL);
	I_EnumLabel(osgWidget::EVENT_KEY_DOWN);
	I_EnumLabel(osgWidget::EVENT_KEY_UP);
	I_EnumLabel(osgWidget::EVENT_ALL);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgWidget::EventMask)
	I_DeclaringFile("osgWidget/EventInterface");
	I_EnumLabel(osgWidget::EVENT_MASK_FOCUS);
	I_EnumLabel(osgWidget::EVENT_MASK_MOUSE_MOVE);
	I_EnumLabel(osgWidget::EVENT_MASK_MOUSE_CLICK);
	I_EnumLabel(osgWidget::EVENT_MASK_MOUSE_DRAG);
	I_EnumLabel(osgWidget::EVENT_MASK_KEY);
END_REFLECTOR

