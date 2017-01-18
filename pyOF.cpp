#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include "pybind_app.h"
#include "pybind_math.h"
#include "pybind_utils.h"
#include "pybind_types.h"
#include "pybind_events.h"
#include "pybind_graphics.h"
#include "pybind_comm.h"
#include "pybind_gl.h"
#include "pybind_3d.h"
#include "pybind_video.h"
#include "pybind_sound.h"
#include "pybind_ofxGui.h"
#include "pybind_ofxAssimpModelLoader.h"
#include "pybind_ofxOpenCV.h"

namespace py = pybind11;

// template<typename T> class iterator_t : public py::iterator {
// public:
//     using iterator::iterator;
//     // cheap/lazy way of doing this as it could be done in advance(), 
//     // but then py::iterator needs to be changed
//     auto operator*() const {
//         return this->iterator::operator*().cast<T>(); //Error!!!
//     }
// };

// template<typename T> class iterable_t : public py::iterable {
// public:
//     using iterable::iterable;
//     iterator_t<T> begin() { return {PyObject_GetIter(ptr()), false}; }
//     iterator_t<T> end() { return {nullptr, false}; }
// };

// m.def("dump", [](iterable_t<Foo> x) {
//         for (auto v : x)
//             std::cout << v.method();
//     });
// python代码 : 
// generate(5)       返回一个List
// dump(generate(5)) 接受一个可迭代对象
// dump(f for f in generate(5) if f.x % 2 == 0) 接受一个生成器表达式

class ofApp: public ofBaseApp {
public:
    using ofBaseApp::ofBaseApp;
    void setup() override {
        PYBIND11_OVERLOAD(void, ofBaseApp, setup);
    }
    void update() override {
        PYBIND11_OVERLOAD(void, ofBaseApp, update);
    }
    void draw() override {
        PYBIND11_OVERLOAD(void, ofBaseApp, draw);
    }
    void exit() override {
        PYBIND11_OVERLOAD(void, ofBaseApp, exit);
    }
    void windowResized(int w, int h) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, windowResized, w, h);
    }
    void keyPressed( int key ) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, keyPressed, key);
    }
    void keyReleased( int key ) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, keyReleased, key);
    }
    void mouseMoved(int x, int y) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, mouseMoved, x, y);
    }
    void mouseDragged(int x, int y, int button) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, mouseDragged, x, y, button);
    }
    void mousePressed(int x, int y, int button) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, mousePressed, x, y, button);
    }
    void mouseReleased(int x, int y, int button) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, mouseReleased, x, y, button);
    }
    void mouseEntered(int x, int y) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, mouseEntered, x, y);
    }
    void mouseExited(int x, int y) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, mouseExited, x, y);
    }

    // ofDragInfo 在pybind11_events里有绑定
    void dragEvent(ofDragInfo dragInfo) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, dragEvent, dragInfo);
    }
    // ofMessage 在pybind11_events里有绑定
    void gotMessage(ofMessage msg) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, gotMessage, msg);
    }

    void touchDown(int x, int y, int id) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, touchDown, x, y, id);
    }
    void touchMoved(int x, int y, int id) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, touchMoved, x, y, id);
    }
    void touchUp(int x, int y, int id) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, touchUp, x, y, id);
    }
    void touchDoubleTap(int x, int y, int id) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, touchDoubleTap, x, y, id);
    }
    void touchCancelled(int x, int y, int id) override {
        PYBIND11_OVERLOAD(void, ofBaseApp, touchCancelled, x, y, id);
    }

    void run(int w, int h, ofWindowMode screenMode) {
        self = py::cast(this);           // C++ class pointer --> py::object
        self.inc_ref();                  // 增加引用计数
        ofSetupOpenGL(w,h, screenMode);
        // ofRunApp(this);
        ofRunApp( self.cast<ofApp*>() ); // py::object --> C++ class pointer
    }

    // void runCairo(int w, int h, ofWindowMode screenMode) {
    //     shared_ptr<ofCairoRenderer> ren(new ofCairoRenderer);
    //     ofSetCurrentRenderer(ren, true);
    //     self = py::cast(this);           // C++ class pointer --> py::object
    //     self.inc_ref();                  // 增加引用计数
    //     ofSetupOpenGL(w,h, screenMode);
    //     ofRunApp( self.cast<ofApp*>() ); // py::object --> C++ class pointer
    // }

    void runGL(int w, int h, ofWindowMode screenMode, int major=3, int minor=2) {
                         
    	ofGLWindowSettings settings;
		settings.setGLVersion(major, minor);
		settings.width = w;
		settings.height = h;
		settings.windowMode = screenMode;

        ofCreateWindow(settings);
        self = py::cast(this);          // C++ class pointer --> py::object
        self.inc_ref(); 				// 增加引用计数		
		ofRunApp( this );// py::object --> C++ class pointer
        
        // shared_ptr<ofAppGlutWindow> pwin(new ofAppGlutWindow()); // GLUT库 不支持 x86_64 架构，导致编译失败
        // auto window = make_shared<ofAppGlutWindow>(pwin);
        // pwin->setup(settings);
        // pwin->setGlutDisplayString("rgba double depth samples>=4");
        // window.setGlutDisplayString("rgba double samples>=4");
        // ofRunApp( window, make_shared<ofBaseApp>(this) );
        // ofRunApp( window, self.cast<ofApp*>() );// py::object --> C++ class pointer

    }

private:
    py::object self;
    // py::handle handle;
};


PYBIND11_PLUGIN(pyOF) {
    using namespace py::literals;
    py::module m("pyOF", "python binding for openFrameworks");
    
    pybind_app( m);
    pybind_math( m);
    pybind_utils( m);
    pybind_types( m);
    pybind_events(m);
    pybind_graphics( m);

    py::class_<ofBaseApp,ofApp>(m, "BaseApp", py::dynamic_attr())
        .def(py::init<>())
        .def("__init__", [](const ofApp & a) {})
        .def("setup",          &ofApp::setup)
        .def("update",         &ofApp::update)
        .def("draw",           &ofApp::draw)
        .def("exit",           &ofApp::exit)
        .def("windowResized",  &ofApp::windowResized)
        .def("keyPressed",     &ofApp::keyPressed)
        .def("keyReleased",    &ofApp::keyReleased)
        .def("mouseMoved",     &ofApp::mouseMoved)
        .def("mouseDragged",   &ofApp::mouseDragged)
        .def("mousePressed",   &ofApp::mousePressed)
        .def("mouseReleased",  &ofApp::mouseReleased)
        .def("mouseEntered",   &ofApp::mouseEntered)
        .def("mouseExited",    &ofApp::mouseExited)
        .def("dragEvent",      &ofApp::dragEvent)
        .def("gotMessage",     &ofApp::gotMessage)
        .def("touchDown",      &ofApp::touchDown)
        .def("touchMoved",     &ofApp::touchMoved)
        .def("touchUp",        &ofApp::touchUp)
        .def("touchDoubleTap", &ofApp::touchDoubleTap)
        .def("touchCancelled", &ofApp::touchCancelled)
        .def("run",            &ofApp::run)
        .def("runGL", (void (ofApp::*)(int,int,ofWindowMode,int,int)) &ofApp::runGL, "runGL(width,height,screenMode,major,minor)","w"_a, "h"_a, "screenMode"_a, "major"_a=3, "minor"_a=2) 
        // .def("runCairo",       &ofApp::runCairo)
        .def_readonly("mouseX", &ofApp::mouseX)
        .def_readonly("mouseY", &ofApp::mouseY);
        // .def_property("me", &ofApp::getSelf, &ofApp::setSelf);
    py::module hdm = m.def_submodule("hd", "All kinds of hardwares module, such as Arduino... ");
    pybind_comm( hdm );
    pybind_3d( m );
    pybind_gl( m );
    pybind_video( m );
    pybind_sound( m );
    py::module ofxGuiMod = m.def_submodule("gui", "ofxGui module. ");
    pybind_ofxGui( ofxGuiMod );
    py::module ofxAssimpMod = m.def_submodule("assimp", "ofxAssimpModelLoader module. ");
    pybind_ofxAssimp( ofxAssimpMod );
    py::module openCVmod = m.def_submodule("opencv", "ofxOpenCV module. ");
    pybind_ofxOpenCV( openCVmod );

    m.attr("__version__") = py::str("0.9.8");
    m.attr("__author__")  = py::str("guoguofish");
    m.attr("__Email__")   = py::str("guo129@hotmail.com");
    return m.ptr();
};