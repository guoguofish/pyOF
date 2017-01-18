#pragma once

#include "ofMain.h"
#include "Python.h"


class ofApp : public ofBaseApp{
	public:
		ofApp(){ pyobj = NULL; }
		// ofApp(PyObject* obj);
		~ofApp();

		// virtual functions
		void setup();
		void update();
		void draw();
		void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);

		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);

		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void touchDown(int x, int y, int id);
		void touchMoved(int x, int y, int id);
		void touchUp(int x, int y, int id);
		void touchDoubleTap(int x, int y, int id);
		void touchCancelled(int x, int y, int id);
		
		void run(int w, int h, ofWindowMode screenMode);
	private:
		PyObject* pyobj;
};
