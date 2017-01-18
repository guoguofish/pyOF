#include "ofApp.h"
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
// #include "openframeworks_api.h"
#include <iostream>
namespace py = pybind11;
// ofApp::ofApp(PyObject* o): pyobj(o) {
	// if (import_openframeworks()==0) {
	// 	Py_XINCREF(pyobj);
	// }
// }

ofApp::~ofApp(){
	// if (pyobj) {
	// 	Py_XDECREF(this->pyobj);
	// }
}

//--------------------------------------------------------------
void ofApp::setup(){
	if (this->pyobj) {
		int error;
		// call_setup(this->pyobj, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def setup(self)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] in setup()\n";
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (this->pyobj) {
		int error;
		// call_update(this->pyobj, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def update(self)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] in update()\n";
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (this->pyobj) {
		int error;
		// call_draw(this->pyobj, &error);
		if (error) {
			std::cerr << "** you must override 'def draw(self)' in your App class\n";
		}
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] in draw()\n";
	}
}
//--------------------------------------------------------------
void ofApp::exit(){
	if (this->pyobj) {
		int error;
		// call_exit(this->pyobj, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def exit(self)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] in exit()\n";
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (this->pyobj) {
		int error;
		// call_keyPressed(this->pyobj, key, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def keyPressed(self, key)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] in keyPressed("<< key <<")\n";
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (this->pyobj) {
		int error;
		// call_keyReleased(this->pyobj, key, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def keyReleased(self, key)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] in keyReleased("<< key <<")\n";
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	if (this->pyobj) {
		int error;
		// call_mouseMoved(this->pyobj, x, y, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def mouseMoved(self, x ,y)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (this->pyobj) {
		int error;
		// call_mouseDragged(this->pyobj, x, y, button, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def mouseDragged(self, x, y, button)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (this->pyobj) {
		int error;
		// call_mousePressed(this->pyobj, x, y, button, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def mousePressed(self, x, y, button)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (this->pyobj) {
		int error;
		// call_mouseReleased(this->pyobj, x, y, button, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def mouseReleased(self, x, y, button)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (this->pyobj) {
		int error;
		// call_mouseEntered(this->pyobj, x, y, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def mouseEntered(self, x, y)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (this->pyobj) {
		int error;
		// call_mouseExited(this->pyobj, x, y, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def mouseExited(self, x, y)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (this->pyobj) {
		int error;
		// call_windowResized(this->pyobj, w, h, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def windowResized(self, w, h)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (this->pyobj) {
		int error;
		// call_gotMessage(this->pyobj, msg, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def gotMessage(self, msgDict)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (this->pyobj) {
		int error;
		// call_dragEvent(this->pyobj, dragInfo, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def dragEvent(self, dragInfoDict)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

void ofApp::touchDown(int x, int y, int id) {
	if (this->pyobj) {
		int error;
		// call_touchDown(this->pyobj, x, y, id, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def touchDown(self, x, y, id)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}
void ofApp::touchMoved(int x, int y, int id) {
	if (this->pyobj) {
		int error;
		// call_touchMoved(this->pyobj, x, y, id, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def touchMoved(self, x, y, id)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}
void ofApp::touchUp(int x, int y, int id) {
	if (this->pyobj) {
		int error;
		// call_touchUp(this->pyobj, x, y, id, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def touchUp(self, x, y, id)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}
void ofApp::touchDoubleTap(int x, int y, int id) {
	if (this->pyobj) {
		int error;
		// call_touchDoubleTap(this->pyobj, x, y, id, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def touchDoubleTap(self, x, y, id)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}
void ofApp::touchCancelled(int x, int y, int id) {
	if (this->pyobj) {
		int error;
		// call_touchCancelled(this->pyobj, x, y, id, &error);
		// if (error) {
		// 	std::cerr << "** you might need to override 'def touchCancelled(self, x, y, id)' in your App class\n";
		// }
	}
	else {
		std::cerr << "** invalid PyObject: obj [" << this->pyobj << "] "<<std::endl;
	}
}

void ofApp::run( int w, int h, ofWindowMode screenMode ){ 
	ofSetupOpenGL(w,h, screenMode);
	ofRunApp( this );
}