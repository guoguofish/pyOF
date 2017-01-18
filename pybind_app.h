#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
// #include "Python.h"
namespace py = pybind11;

// class :
// ofAppBaseGLESWindow
// ofAppBaseGLWindow
// ofAppEGLWiondow
// ofAppBaseWindow
// ofAppGLFWWindow
// ofAppGlutWindow
// ofAppNoWindow
// ofBaseApp
// ofDragInfo
// ofGLESWindowSettings
// ofGLFWWindowSettings
// ofWindowSettings
// ofMainLoop

// ofAppRunner.h function:
// noopDeleter()
// ofCreateWindow()
// ofDoesHWOrientation()
// ofEvents()
// ofExit()
// ofGetAppPtr()
// ofGetCurrentRenderer()
// ofGetFrameNum()
// ofGetFrameRate()
// ofGetGLXContext()
// ofGetHeight()
// ofGetLastFrameTime()
// ofGetMainLoop()
// ofGetOrientation()
// ofGetScreenHeight()
// ofGetScreenWidth()
// ofGetTargetFrameRate()
// ofGetWidth()
// ofGetWindowHeight()
// ofGetWindowMode()
// ofGetWindowPositionX()
// ofGetWindowPositionY()
// ofGetWindowPtr()
// ofGetWindowRect()
// ofGetWindowSize()
// ofGetWindowWidth()
// ofGetX11Display()
// ofGetX11Window()
// ofHideCursor()
// void ofInit()
// ofRandomHeight()
// ofRandomWidth()
// ofRunApp()
// ofRunMainLoop()
// ofSetAppPtr()
// ofSetCurrentRenderer()
// ofSetEscapeQuitsApp()
// ofSetFrameRate()
// ofSetFullscreen()
// ofSetMainLoop()
// ofSetOrientation()
// ofSetVerticalSync()
// ofSetWindowPosition()
// ofSetWindowShape()
// ofSetWindowTitle()
// ofShowCursor()
// ofToggleFullscreen()

void pybind_app(py::module &m) {
	m.def("ofInit", &ofInit);
	m.def("ofExit", &ofExit, "Exit from openFrameworks", py::arg("status"));
	m.def("ofGetFrameNum", &ofGetFrameNum,"This returns the current frame as an int");
	m.def("ofGetFrameRate", &ofGetFrameRate,"This returns the current frame Rate as a float");
	m.def("ofGetHeight", &ofGetHeight,"This gets the height of your app window");
	m.def("ofGetWidth", &ofGetWidth,"This gets the width of your app window");
	m.def("ofGetWindowMode", &ofGetWindowMode,"This returns window mode as int");
	m.def("ofHideCursor", &ofHideCursor);
	m.def("ofShowCursor", &ofShowCursor);
	m.def("ofRandomHeight", &ofRandomHeight,"Returns a random number (float) between 0 and the height of the window");
	m.def("ofRandomWidth", &ofRandomWidth,"Returns a random number (float) between 0 and the width of the window");
	m.def("ofSetEscapeQuitsApp", &ofSetEscapeQuitsApp,"ofSetEscapeQuitsApp(True|False)");
	m.def("ofSetFrameRate", &ofSetFrameRate);
	m.def("ofSetFullscreen", &ofSetFullscreen,"ofSetFullscreen(True|False)");
	m.def("ofSetVerticalSync", &ofSetVerticalSync,"ofSetVerticalSync(True|False)");
	m.def("ofSetWindowPosition", &ofSetWindowPosition,"ofSetWindowPosition(int x, int y)");
	m.def("ofSetWindowShape", &ofSetWindowShape,"ofSetWindowShape(int width, int height)");
	m.def("ofSetWindowTitle", &ofSetWindowTitle,"ofSetWindowTitle(string title)");
	m.def("ofToggleFullscreen", &ofToggleFullscreen);

}