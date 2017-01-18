#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <locale>

// #include "Python.h"
namespace py = pybind11;

// ================== Class =============
// ofEventArgs
// ofAudioEventArgs
// ofEntryEventArgs
// ofResizeEventArgs
// ofKeyEventArgs
// ofMouseEventArgs
// ofTouchEventArgs
// ofEvent
// ofBaseEvent
// ofFastEvent
// ofCoreEvents
// ofMessage
// ofDragInfo
// =========  Global Functions ==========
// ofEvents::::::
// ofCoreEvents & ofEvents()
// bool ofGetKeyPressed(   int key)
// bool ofGetMousePressed( int button)
// int  ofGetMouseX()
// int  ofGetMouseY()
// int  ofGetPreviousMouseX()
// int  ofGetPreviousMouseY()
// void ofSendMessage( ofMessage msg)
// void ofSendMessage( string    messageString)
// void ofRegisterDragEvents(    ListenerClass *listener, int prio)
// void ofRegisterGetMessages(   ListenerClass *listener, int prio)
// void ofRegisterKeyEvents(     ListenerClass *listener, int prio)
// void ofRegisterMouseEvents(   ListenerClass *listener, int prio)
// void ofRegisterTouchEvents(   ListenerClass *listener, int prio)
// void ofUnregisterDragEvents(  ListenerClass *listener, int prio)
// void ofUnregisterGetMessages( ListenerClass *listener, int prio)
// void ofUnregisterKeyEvents(   ListenerClass *listener, int prio)
// void ofUnregisterMouseEvents( ListenerClass *listener, int prio)
// void ofUnregisterTouchEvents( ListenerClass *listener, int prio)
// ofEventUtils::::::
// void ofAddListener(    ofEvent   &event, ListenerClass *listener, bool (ListenerClass::*)() listenerMethod,   int prio)
// void ofRemoveListener( ofEvent   &event, ListenerClass *listener, bool (ListenerClass::*)() listenerMethod,   int prio)
// void ofAddListener(    ofEvent   &event, ListenerClass *listener, bool (ListenerClass::*)(const void *) listenerMethod,   int prio)
// void ofRemoveListener( ofEvent   &event, ListenerClass *listener, bool (ListenerClass::*)(const void *) listenerMethod,   int prio)
// void ofAddListener(    EventType &event, ListenerClass *listener, bool (ListenerClass::*)(ArgumentsType &) listenerMethod, int prio)
// void ofRemoveListener( EventType &event, ListenerClass *listener, bool (ListenerClass::*)(ArgumentsType &) listenerMethod, int prio)
// void ofAddListener(    EventType &event, ListenerClass *listener, bool (ListenerClass::*)(const void *,  ArgumentsType &) listenerMethod, int prio)
// void ofRemoveListener( EventType &event, ListenerClass *listener, bool (ListenerClass::*)(const void *,  ArgumentsType &) listenerMethod, int prio)
// void ofAddListener(    ofEvent   &event, ListenerClass *listener, void (ListenerClass::*)() listenerMethod,   int prio)
// void ofRemoveListener( ofEvent   &event, ListenerClass *listener, void (ListenerClass::*)() listenerMethod,   int prio)
// void ofAddListener(    ofEvent   &event, ListenerClass *listener, void (ListenerClass::*)(const void *)  listenerMethod,   int   prio)
// void ofRemoveListener( ofEvent   &event, ListenerClass *listener, void (ListenerClass::*)(const void *)  listenerMethod,   int   prio)
// void ofAddListener(    EventType &event, ListenerClass *listener, void (ListenerClass::*)(ArgumentsType &) listenerMethod, int prio)
// void ofRemoveListener( EventType &event, ListenerClass *listener, void (ListenerClass::*)(ArgumentsType &) listenerMethod, int prio)
// void ofAddListener(    EventType &event, ListenerClass *listener, void (ListenerClass::*)(const void *, ArgumentsType &)listenerMethod, int prio)
// void ofRemoveListener( EventType &event, ListenerClass *listener, void (ListenerClass::*)(const void *, ArgumentsType &)listenerMethod, int prio)
// void ofAddListener(    EventType &event, void (*)(const void *, ArgumentsType &) listenerFunction, int prio)
// void ofRemoveListener( EventType &event, void (*)(const void *, ArgumentsType &) listenerFunction, int prio)
// void ofAddListener(    EventType &event, void (*)(ArgumentsType &)   listenerFunction, int prio)
// void ofRemoveListener( EventType &event, void (*)(ArgumentsType &)   listenerFunction, int prio)
// void ofAddListener(    ofEvent   &event, void (*)(const void *) listenerFunction, int   prio)
// void ofRemoveListener( ofEvent   &event, void (*)(const void *) listenerFunction, int   prio)
// void ofAddListener(    ofEvent   &event, void (*)() listenerFunction, int prio)
// void ofRemoveListener( ofEvent   &event, void (*)() listenerFunction, int prio)
// void ofAddListener(    EventType &event, bool (*)(const void *,  ArgumentsType &) listenerFunction, int prio)
// void ofRemoveListener( EventType &event, bool (*)(const void *,  ArgumentsType &) listenerFunction, int prio)
// void ofAddListener(    EventType &event, bool (*)(ArgumentsType &)   listenerFunction, int  prio)
// void ofRemoveListener( EventType &event, bool (*)(ArgumentsType &)   listenerFunction, int  prio)
// void ofAddListener(    ofEvent   &event, bool (*)(const void *) listenerFunction, int   prio)
// void ofRemoveListener( ofEvent   &event, bool (*)(const void *) listenerFunction, int   prio)
// void ofAddListener(    ofEvent   &event, bool (*)() listenerFunction, int prio)
// void ofRemoveListener( ofEvent   &event, bool (*)() listenerFunction, int prio)

// void ofNotifyEvent( EventType &event, ArgumentsType &args)
// void ofNotifyEvent( EventType &event, ArgumentsType &args,        SenderType *sender)
// void ofNotifyEvent( EventType &event, const ArgumentsType &args,  SenderType *sender)
// void ofNotifyEvent( EventType &event, const ArgumentsType &args)
// void ofNotifyEvent( ofEvent   &event, SenderType *sender)
// void ofNotifyEvent( ofEvent   &event)

class ofPyBaseEvent {
public:
	 ofPyBaseEvent() { 
	 	ofRegisterMouseEvents(this);
	 	ofRegisterKeyEvents(this);
	 	ofRegisterTouchEvents(this);
	 }
	virtual ~ofPyBaseEvent() {
		ofUnregisterKeyEvents(this);
		ofUnregisterMouseEvents(this);
		ofUnregisterTouchEvents(this);
	}
	virtual void mouseMoved(   ofMouseEventArgs & args){}
	virtual void mouseDragged( ofMouseEventArgs & args){}
	virtual void mousePressed( ofMouseEventArgs & args){}
	virtual void mouseReleased(ofMouseEventArgs & args){}
	virtual void mouseScrolled(ofMouseEventArgs & args){}
	virtual void mouseEntered( ofMouseEventArgs & args){}
	virtual void mouseExited(  ofMouseEventArgs & args){}

	virtual void keyPressed( ofKeyEventArgs & args){}
	virtual void keyReleased(ofKeyEventArgs & args){}

	virtual void touchUp(       ofTouchEventArgs & args){}
	virtual void touchDown(     ofTouchEventArgs & args){}
	virtual void touchMoved(    ofTouchEventArgs & args){}
	virtual void touchDoubleTap(ofTouchEventArgs & args){}
	virtual void touchCancelled(ofTouchEventArgs & args){}
};

class ofPyEvent: public ofPyBaseEvent {
public:
	using ofPyBaseEvent::ofPyBaseEvent;
	void mouseMoved(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mouseMoved, args); }
	void mouseDragged(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mouseDragged, args); }
	void mousePressed(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mousePressed, args); }
	void mouseReleased(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mouseReleased, args); }
	void mouseScrolled(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mouseScrolled, args); }
	void mouseEntered(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mouseEntered, args); }
	void mouseExited(ofMouseEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, mouseExited, args); }
	void keyPressed( ofKeyEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, keyPressed, args); }
	void keyReleased(ofKeyEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, keyReleased, args); }
	void touchUp(       ofTouchEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, touchUp, args); }
	void touchDown(     ofTouchEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, touchDown, args); }
	void touchMoved(    ofTouchEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, touchMoved, args); }
	void touchDoubleTap(ofTouchEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, touchDoubleTap, args); }
	void touchCancelled(ofTouchEventArgs & args) override { PYBIND11_OVERLOAD(void, ofPyBaseEvent, touchCancelled, args); }
};

void pybind_events(py::module  &m) {

	py::enum_<ofEventOrder>(m, "ofEventOrder")
        .value("OF_EVENT_ORDER_BEFORE_APP", ofEventOrder::OF_EVENT_ORDER_BEFORE_APP)
        .value("OF_EVENT_ORDER_APP",        ofEventOrder::OF_EVENT_ORDER_APP)
        .value("OF_EVENT_ORDER_AFTER_APP",  ofEventOrder::OF_EVENT_ORDER_AFTER_APP)
        .export_values();

	py::class_<ofDragInfo>(m, "ofDragInfo")
		.def(py::init<>())
		.def_readwrite("files", &ofDragInfo::files)
		.def_readwrite("position", &ofDragInfo::position);

	py::class_<ofMessage>(m, "ofMessage")
		.def(py::init<string>())
		.def_readwrite("message", &ofMessage::message);

	m.def("ofGetKeyPressed", &ofGetKeyPressed);
	m.def("ofGetMousePressed", &ofGetMousePressed);
	m.def("ofGetMouseX", &ofGetMouseX);
	m.def("ofGetMouseY", &ofGetMouseY);
	m.def("ofGetPreviousMouseX", &ofGetPreviousMouseX);
	m.def("ofSendMessage", (void (*)(ofMessage)) &ofSendMessage);
	m.def("ofSendMessage", (void (*)(string)) &ofSendMessage);

	py::class_<ofResizeEventArgs>(m, "ofResizeEventArgs")
		.def(py::init<>());
	// py::class_<ofEntryEventArgs>(m, "ofEntryEventArgs")
	// 	.def(py::init<>());
	// py::class_<ofAudioEventArgs>(m, "ofAudioEventArgs")
	// 	.def(py::init<>());
	// py::enum_<ofKeyEventArgs::Type>(m, "Type")
	//     .value("Pressed", ofKeyEventArgs::Type::Pressed)
	//     .value("Released",   ofKeyEventArgs::Type::Released);

	py::class_<ofKeyEventArgs>(m, "ofKeyEventArgs")
		.def(py::init<>())
		.def(py::init<ofKeyEventArgs::Type, int, int, int, unsigned int>())
		.def(py::init<ofKeyEventArgs::Type, int>())
		.def_readwrite("type", &ofKeyEventArgs::type)
		.def_readwrite("key", &ofKeyEventArgs::key)
		.def_readwrite("keycode", &ofKeyEventArgs::keycode)
		.def_readwrite("scancode", &ofKeyEventArgs::scancode)
		.def_readwrite("codepoint", &ofKeyEventArgs::codepoint);

	py::class_<ofMouseEventArgs, ofVec2f>(m, "ofMouseEventArgs", py::multiple_inheritance())
		.def(py::init<>())
		.def(py::init<ofMouseEventArgs::Type, float, float, int>())
		.def(py::init<ofMouseEventArgs::Type, float, float>())
		.def_readwrite("type", &ofMouseEventArgs::type)
		.def_readwrite("button", &ofMouseEventArgs::button)
		.def_readwrite("scrollX", &ofMouseEventArgs::scrollX)
		.def_readwrite("scrollY", &ofMouseEventArgs::scrollY);

	py::class_<ofTouchEventArgs>(m, "ofTouchEventArgs")
		.def(py::init<>());

	py::class_<ofPyBaseEvent, ofPyEvent>(m, "BaseEvent", py::dynamic_attr())
		.def(py::init<>())
		.def("mouseMoved",     &ofPyEvent::mouseMoved)
		.def("mouseDragged",   &ofPyEvent::mouseDragged)
		.def("mousePressed",   &ofPyEvent::mousePressed)
		.def("mouseReleased",  &ofPyEvent::mouseReleased)
		.def("mouseScrolled",  &ofPyEvent::mouseScrolled)
		.def("mouseEntered",   &ofPyEvent::mouseEntered)
		.def("mouseExited",    &ofPyEvent::mouseExited)
		.def("keyPressed",     &ofPyEvent::keyPressed)
		.def("keyReleased",    &ofPyEvent::keyReleased)
		.def("touchUp",        &ofPyEvent::touchUp)
		.def("touchDown",      &ofPyEvent::touchDown)
		.def("touchMoved",     &ofPyEvent::touchMoved)
		.def("touchDoubleTap", &ofPyEvent::touchDoubleTap)
		.def("touchCancelled", &ofPyEvent::touchCancelled);
}