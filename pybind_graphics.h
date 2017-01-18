#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;


// ======Class ========
// ofBitmapFont
// ofImage
// ofPixels
// ofPixels::ConstLine
// ofPixels::ConstLines
// ofPixels::Lines
// ofPixels::ConstPixel
// ofPixels::ConstPixels
// ofPixels::Pixels
// ofTTFCharacter
// ofCairoRenderer
// ofPath          ok
// ofPath::Command ok
// ofPolyline      ok
// ofTessellator   ok
// ofTrueTypeFont  ok

// ========== ofGraphics.h Global Functions:==========

void pyOfBackground(py::args args, py::kwargs kwargs) {
	py::list argslist;
	// std::map<py::str, py::int> kw(kwargs);
	int ll = py::len(args);
	int ld = py::len(kwargs);
	auto r=0;
	auto g=0;
	auto b=0;
	auto a=255;
	auto brightness=0;

	if (ll > 0) {
		for (auto item : args) {
			argslist.append(item);
			// py::print(item);
			// cout << py::str(item.attr("__class__")).cast<string>() <<endl; //<type 'int'>
		}
	}
	
	if ( ll > 0 ) {
		switch ( ll ) {
			case 1:
				brightness = argslist[0].cast<int>();
				ofBackground( brightness,brightness,brightness );
				break;
			case 2:
				brightness = argslist[0].cast<int>();
				a = argslist[1].cast<int>();
				ofBackground( brightness, a);
				break;
			case 3:
				r = argslist[0].cast<int>();
				g = argslist[1].cast<int>();
				b = argslist[2].cast<int>();
				if (ld > 0) {
					auto alpha = kwargs.attr("get")(py::str("a")) ;
					try {
						a = alpha.cast<int>();
					} catch (py::cast_error) {
						cout << "Key parameter [a] don't exist.\nOr, value of [a] is not Int, 0-255"<< endl;
					}
				}
				ofBackground( r,g,b );
				break;
			case 4:
				r = argslist[0].cast<int>();
				g = argslist[1].cast<int>();
				b = argslist[2].cast<int>();
				a = argslist[3].cast<int>();
				ofBackground( r,g,b,a );
				break;
			default:
				ofBackground(100,120,150, a);
		}
	}else{
		ofBackground(100,120,150, a);
	}
	
	//不分析关键字参数
}
// ofBackgroundGradient()
// ofBackgroundHex()
// ofBeginSaveScreenAsPDF()
// ofBeginSaveScreenAsSVG()
// ofBeginShape()
// ofBezierVertex()
// ofClear()
// ofClearAlpha()
// ofCurveVertex()
// ofCurveVertices()
// ofDisableAlphaBlending()
// ofDisableAntiAliasing()
// ofDisableBlendMode()
// ofDisableDepthTest()
// ofDisablePointSprites()
// ofDisableSmoothing()
// ofDrawBezier()
// ofDrawBitmapString()
// ofDrawBitmapStringHighlight()
// ofDrawCircle()
// ofDrawCurve()
// ofDrawEllipse()
// ofDrawLine()
// ofDrawRectRounded()
// ofDrawRectangle()
// ofDrawTriangle()
// ofEnableAlphaBlending()
// ofEnableAntiAliasing()
// ofEnableBlendMode()
// ofEnableDepthTest()
// ofEnablePointSprites()
// ofEnableSmoothing()
// ofEndSaveScreenAsPDF()
// ofEndSaveScreenAsSVG()
// ofEndShape()
// ofFill()
// ofGetBackgroundAuto()
// ofGetBackgroundColor()
// ofGetCoordHandedness()
// ofGetCurrentMatrix()
// ofGetCurrentNormalMatrix()
// ofGetCurrentOrientationMatrix()
// ofGetCurrentViewMatrix()
// ofGetCurrentViewport()
// ofGetFill()
// ofGetNativeViewport()
// ofGetRectMode()
// ofGetStyle()
// ofGetViewportHeight()
// ofGetViewportWidth()
// ofIsVFlipped()
// ofLoadIdentityMatrix()
// ofLoadMatrix()
// ofLoadViewMatrix()
// ofMultMatrix()
// ofMultViewMatrix()
// ofNextContour()
// ofNoFill()
// ofOrientationToDegrees()
// ofPopMatrix()
// ofPopStyle()
// ofPopView()
// ofPushMatrix()
// ofPushStyle()
// ofPushView()
// ofRotate()
// ofRotateX()
// ofRotateY()
// ofRotateZ()
// ofScale()
// ofSetBackgroundAuto()
// ofSetBackgroundColor()
// ofSetBackgroundColorHex()
// ofSetCircleResolution()
// ofSetColor()
// ofSetCoordHandedness()
// ofSetCurveResolution()
// ofSetDepthTest()
// ofSetDrawBitmapMode()
// ofSetHexColor()
// ofSetLineWidth()
// ofSetMatrixMode()
// ofSetPolyMode()
// ofSetRectMode()
// ofSetStyle()
// ofSetupScreen()
// ofSetupScreenOrtho()
// ofSetupScreenPerspective()
// ofTranslate()
// ofVertex()
// ofVertices()
// ofViewport()

void pybind_graphics(py::module &m) {
	using namespace py::literals;
	
	m.def("ofBackground", (void (*)(int, int, int, int)) &ofBackground, py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a")=255);
	m.def("ofBackground", (void (*)(int, int)) &ofBackground, py::arg("brightness"), py::arg("alpha")=255);
	m.def("ofBackground", (void (*)(const ofColor &)) &ofBackground);
	m.def("ofBackgroundGradient", &ofBackgroundGradient,"在背景的基础上又绘画了一个有梯度的背景.\nOF_GRADIENT_CIRCULAR\nOF_GRADIENT_LINEAR\nOF_GRADIENT_BAR");
	m.def("ofBackgroundHex", &ofBackgroundHex, "ofBackgroundHex(int_color, int_alpha=255)", py::arg("color"), py::arg("alpha")=255);

	char * _helpdoc = "ofSetPolyMode(OF_POLY_WINDING_NONZERO);\
ofBeginShape();\
  ofVertex(400,135);\
  ofVertex(215,135);\
  ofVertex(365,25);\
  ofVertex(305,200);\
  ofVertex(250,25);\
ofEndShape();";

	m.def("ofBeginShape", &ofBeginShape, _helpdoc);
	m.def("ofEndShape",   &ofEndShape,   _helpdoc);

	m.def("ofEnableAlphaBlending",&ofEnableAlphaBlending,   "Enable alpha blending");
	m.def("ofEnableAntiAliasing", &ofEnableAntiAliasing,    "Enable lines anti-aliasing");
	m.def("ofEnableSmoothing",    &ofEnableSmoothing,    "Enable lines smoothing");
	m.def("ofEnablePointSprites", &ofEnablePointSprites,    "Turns on point sprite. Textures can be mapped onto points. By default, point size is 1pt. So texture is not shown correctly. You can change point size by glPointSize(GLfloat size)");
	m.def("ofEnableDepthTest",    &ofEnableDepthTest,    "Turns on depth testing so rendering happens according to z-depth rather than draw order");
	m.def("ofEnableBlendMode",    &ofEnableBlendMode, "Enable blend mode for frawing.\nThe options are:\nOF_BLENDMODE_DISABLED\nOF_BLENDMODE_ALPHA\nOF_BLENDMODE_ADD\nOF_BLENDMODE_SUBTRACT\nOF_BLENDMODE_MULTIPLY\nOF_BLENDMODE_SCREEN");

	m.def("ofDisableAlphaBlending",&ofDisableAlphaBlending);
	m.def("ofDisableAntiAliasing", &ofDisableAntiAliasing);
	m.def("ofDisableSmoothing",    &ofDisableSmoothing) ;
	m.def("ofDisablePointSprites", &ofDisablePointSprites) ;
	m.def("ofDisableDepthTest",    &ofDisableDepthTest) ;
	m.def("ofDisableBlendMode",    &ofDisableBlendMode);

	m.def("ofClear", (void (*)(float,float,float, float)) &ofClear);
	m.def("ofClear", (void (*)(float,float)) &ofClear);
	m.def("ofClear", (void (*)(const ofColor &)) &ofClear);

	m.def("ofSetColor", (void (*)(int,int,int)) &ofSetColor);
	m.def("ofSetColor", (void (*)(int,int,int,int)) &ofSetColor);
	m.def("ofSetColor", (void (*)(int)) &ofSetColor);
	m.def("ofSetColor", (void (*)(const ofColor &)) &ofSetColor);
	m.def("ofSetColor", (void (*)(const ofColor &, int)) &ofSetColor);

	m.def("ofSetHexColor",  &ofSetHexColor);

	m.def("ofClearAlpha", &ofClearAlpha);
	m.def("ofFill", &ofFill);
	m.def("ofNoFill", &ofNoFill);
	m.def("ofSetLineWidth", &ofSetLineWidth);
	m.def("ofSetMatrixMode", &ofSetMatrixMode, "OF_MATRIX_MODELVIEW | OF_MATRIX_PROJECTION | OF_MATRIX_TEXTURE");
	m.def("ofSetPolyMode", &ofSetPolyMode, "ofSetPolyMode(ofPolyWindingMode)");
	m.def("ofSetRectMode", &ofSetRectMode, "ofSetRectMode(ofRectMode)");
	m.def("ofSetCurveResolution", &ofSetCurveResolution);
	m.def("ofSetCircleResolution", &ofSetCircleResolution);
	m.def("ofSetupScreen", &ofSetupScreen);
	m.def("ofGetStyle", &ofGetStyle);
	m.def("ofGetBackgroundColor", &ofGetBackgroundColor);
	m.def("ofGetCoordHandedness", &ofGetCoordHandedness);
	m.def("ofGetCurrentMatrix", &ofGetCurrentMatrix);
	m.def("ofGetCurrentNormalMatrix", &ofGetCurrentNormalMatrix);
	m.def("ofGetCurrentOrientationMatrix", &ofGetCurrentOrientationMatrix);
	m.def("ofGetCurrentViewMatrix", &ofGetCurrentViewMatrix);
	m.def("ofGetCurrentViewport", &ofGetCurrentViewport);
	m.def("ofGetFill", &ofGetFill);
	m.def("ofGetNativeViewport", &ofGetNativeViewport);
	m.def("ofGetRectMode", &ofGetRectMode);
	m.def("ofGetViewportWidth", &ofGetViewportWidth);
	m.def("ofGetViewportHeight", &ofGetViewportHeight);
	m.def("ofSetStyle", &ofSetStyle);
	m.def("ofLoadIdentityMatrix", &ofLoadIdentityMatrix);

	m.def("ofLoadMatrix", (void (*)(const ofMatrix4x4 &)) &ofLoadMatrix);
	m.def("ofLoadMatrix", (void (*)(const float *)) &ofLoadMatrix);
	m.def("ofMultMatrix", (void (*)(const ofMatrix4x4 &)) &ofMultMatrix);
	m.def("ofMultMatrix", (void (*)(const float *)) &ofMultMatrix);
	m.def("ofLoadViewMatrix", &ofLoadViewMatrix);
	m.def("ofMultViewMatrix", &ofMultViewMatrix);

	m.def("ofPushStyle", &ofPushStyle);
	m.def("ofPopStyle", &ofPopStyle);
	m.def("ofPushView", &ofPushView);
	m.def("ofPopView", &ofPopView);	
	m.def("ofPushMatrix", &ofPushMatrix);
	m.def("ofPopMatrix", &ofPopMatrix);
	m.def("ofNextContour", &ofNextContour, "Allows you to draw multiple contours within one shape\nofNextContour(bool)");
	m.def("ofSetDepthTest", &ofSetDepthTest, "ofSetDepthTest(bool)");
	m.def("ofSetupScreenOrtho", (void (*)(float,float,float,float)) &ofSetupScreenOrtho, "平行透视.\n函数参数:(float width, float height, float nearDist, float farDist)");
	m.def("ofSetupScreenPerspective", (void (*)(float,float,float,float,float)) &ofSetupScreenPerspective, "近大远小透视.\n函数参数:(float width, float height, float fov, float nearDist, float farDist)");


	m.def("ofRotate", (void (*)(float,float,float,float)) &ofRotate);
	m.def("ofRotate", (void (*)(float)) &ofRotate);
	m.def("ofScale", (void (*)(float,float,float)) &ofScale);
	m.def("ofTranslate", (void (*)(float,float,float)) &ofScale);
	m.def("ofTranslate", (void (*)(const ofPoint &)) &ofScale);
	
	m.def("ofDrawBitmapString", (void (*)(const string &, const ofPoint &))     &ofDrawBitmapString<string>);
	m.def("ofDrawBitmapString", (void (*)(const string &, float, float))        &ofDrawBitmapString<string>);
	m.def("ofDrawBitmapString", (void (*)(const string &, float, float, float)) &ofDrawBitmapString<string>);
	m.def("ofDrawBitmapString", (void (*)(const string &, float, float, float)) &ofDrawBitmapString);

	m.def("ofSetBackgroundColor", (void (*)(int,int,int,int)) &ofSetBackgroundColor);
	m.def("ofSetBackgroundColor", (void (*)(int,int)) &ofSetBackgroundColor);
	m.def("ofSetBackgroundColor", (void (*)(const ofColor &)) &ofSetBackgroundColor);
	m.def("ofSetBackgroundColorHex", &ofSetBackgroundColorHex);
	m.def("ofSetCoordHandedness", &ofSetCoordHandedness);
	m.def("ofSetDrawBitmapMode", &ofSetDrawBitmapMode);

	m.def("ofDrawBitmapStringHighlight", (void (*)(string, const ofPoint &, const ofColor &, const ofColor &)) &ofDrawBitmapStringHighlight);
	m.def("ofDrawBitmapStringHighlight", (void (*)(string, int, int, const ofColor &, const ofColor &)) &ofDrawBitmapStringHighlight);
	// m.def("ofDrawBitmapString", (void (*)(const py, const ofPoint &))       &ofDrawBitmapString<const char*>);
	// m.def("ofDrawBitmapString", (void (*)(const char *, float, float))          &ofDrawBitmapString<const char*>);
	// m.def("ofDrawBitmapString", (void (*)(const char *, float, float, float))   &ofDrawBitmapString<const char*>);

	m.def("ofDrawCircle", (void (*)(float,float,float)) &ofDrawCircle);
	m.def("ofDrawCircle", (void (*)(float,float, float, float)) &ofDrawCircle);
	m.def("ofDrawCircle", (void (*)(const ofPoint &, float)) &ofDrawCircle);

	m.def("ofDrawEllipse", (void (*)(float,float,float,float)) &ofDrawEllipse);
	m.def("ofDrawEllipse", (void (*)(float,float, float, float,float)) &ofDrawEllipse);
	m.def("ofDrawEllipse", (void (*)(const ofPoint &, float, float)) &ofDrawEllipse);

	m.def("ofBezierVertex", (void (*)(const ofPoint &, const ofPoint &, const ofPoint &)) &ofBezierVertex);
	m.def("ofBezierVertex", (void (*)(float,float,float,float,float,float)) &ofBezierVertex);
	m.def("ofBezierVertex", (void (*)(float,float,float,float,float,float, float, float, float)) &ofBezierVertex);

	m.def("ofDrawBezier", (void (*)(float,float,float,float,float,float,float,float)) &ofDrawBezier);
	m.def("ofDrawBezier", (void (*)(float,float,float,float,float,float,float,float,float,float,float,float)) &ofDrawBezier);

	m.def("ofCurveVertex", (void (*)(float,float)) &ofCurveVertex);
	m.def("ofCurveVertex", (void (*)(ofPoint &)) &ofCurveVertex);
	m.def("ofCurveVertex", (void (*)(float,float,float)) &ofCurveVertex);

	m.def("ofVertex", (void (*)(float,float)) &ofVertex);
	m.def("ofVertex", (void (*)(ofPoint &)) &ofVertex);
	m.def("ofVertex", (void (*)(float,float,float)) &ofVertex);

	m.def("ofVertices", (void (*)(const vector<float> &)) &ofVertices); // ******

	m.def("ofDrawLine", (void (*)(float,float,float,float)) &ofDrawLine);
	m.def("ofDrawLine", (void (*)(const ofPoint &, const ofPoint &)) &ofDrawLine);
	m.def("ofDrawLine", (void (*)(float,float,float,float,float,float)) &ofDrawLine);
	
	m.def("ofDrawRectangle", (void (*)(float,float,float,float))       &ofDrawRectangle);
	m.def("ofDrawRectangle", (void (*)(const ofRectangle &))           &ofDrawRectangle);
	m.def("ofDrawRectangle", (void (*)(const ofPoint &, float, float)) &ofDrawRectangle);
	m.def("ofDrawRectangle", (void (*)(float,float,float,float,float)) &ofDrawRectangle);
	
	m.def("ofDrawRectRounded", (void (*)(const ofRectangle &,float))                                &ofDrawRectRounded);
	m.def("ofDrawRectRounded", (void (*)(const ofPoint &,float,float,float))                        &ofDrawRectRounded);
	m.def("ofDrawRectRounded", (void (*)(float,float,float,float, float))                           &ofDrawRectRounded);
	m.def("ofDrawRectRounded", (void (*)(float,float,float,float,float,float))                      &ofDrawRectRounded);
	m.def("ofDrawRectRounded", (void (*)(const ofPoint &,float,float,float,float,float,float))      &ofDrawRectRounded);
	m.def("ofDrawRectRounded", (void (*)(const ofRectangle &,float,float,float,float))              &ofDrawRectRounded);
	m.def("ofDrawRectRounded", (void (*)(float, float,float,float, float,float,float, float,float)) &ofDrawRectRounded);

	m.def("ofDrawTriangle", (void (*)(float,float,float,float,float,float)) &ofDrawTriangle);
	m.def("ofDrawTriangle", (void (*)(float, float,float,float, float,float,float, float,float)) &ofDrawTriangle);
	m.def("ofDrawTriangle", (void (*)(const ofPoint &,const ofPoint &,const ofPoint &)) &ofDrawTriangle);

	m.def("ofDrawCurve", (void (*)(float,float, float, float,float,float, float, float)) &ofDrawCurve);
	m.def("ofDrawCurve", (void (*)(float,float, float, float,float,float, float, float,float,float, float, float)) &ofDrawCurve);
	// m.def("ofDrawEllipse", &ofDrawEllipse);
	// m.def("ofClear",   &ofClear, 	 "ofClear(float r, float g, float b, float a)",py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a"));

	py::class_<ofPath> opath(m, "ofPath");
	py::enum_<ofPath::Mode>(opath, "Mode")
		.value("COMMANDS",  ofPath::Mode::COMMANDS)
		.value("POLYLINES", ofPath::Mode::POLYLINES);
	py::class_<ofPath::Command> opathType(opath, "Command");
	py::enum_<ofPath::Command::Type>(opathType, "Type")
		.value("moveTo",       ofPath::Command::moveTo)
		.value("lineTo",       ofPath::Command::lineTo)
		.value("curveTo",      ofPath::Command::curveTo)
		.value("bezierTo",     ofPath::Command::bezierTo)
		.value("quadBezierTo", ofPath::Command::quadBezierTo)
		.value("arc",          ofPath::Command::arc)
		.value("arcNegative",  ofPath::Command::arcNegative)
		.value("close",        ofPath::Command::close);
	opathType.def(py::init<ofPath::Command::Type>())
		.def(py::init<ofPath::Command::Type, const ofPoint &>())
		.def(py::init<ofPath::Command::Type, const ofPoint &, const ofPoint &, const ofPoint &>())
		.def(py::init<ofPath::Command::Type, const ofPoint &, float, float, float, float>())
		.def_readwrite("type",       &ofPath::Command::type)
		.def_readwrite("to",         &ofPath::Command::to)
		.def_readwrite("cp1",        &ofPath::Command::cp1)
		.def_readwrite("cp2",        &ofPath::Command::cp2)
		.def_readwrite("radiusX",    &ofPath::Command::radiusX)
		.def_readwrite("radiusY",    &ofPath::Command::radiusY)
		.def_readwrite("angleBegin", &ofPath::Command::angleBegin)
		.def_readwrite("angleEnd",   &ofPath::Command::angleEnd);
	opath.def(py::init<>())
		.def("clear", &ofPath::clear)
		.def("close", &ofPath::close)
		.def("newSubPath", &ofPath::newSubPath)
		.def("lineTo", (void (ofPath::*)(const ofPoint &)) &ofPath::lineTo)
		.def("lineTo", (void (ofPath::*)(float, float)) &ofPath::lineTo)
		.def("lineTo", (void (ofPath::*)(float, float, float)) &ofPath::lineTo)
		.def("moveTo", (void (ofPath::*)(const ofPoint &)) &ofPath::moveTo)
		.def("moveTo", (void (ofPath::*)(float, float, float)) &ofPath::moveTo)
		.def("curveTo", (void (ofPath::*)(const ofPoint &)) &ofPath::curveTo)
		.def("curveTo", (void (ofPath::*)(float, float)) &ofPath::curveTo)
		.def("curveTo", (void (ofPath::*)(float, float, float)) &ofPath::curveTo)
		.def("bezierTo", (void (ofPath::*)(const ofPoint &, const ofPoint &, const ofPoint &)) &ofPath::bezierTo)
		.def("bezierTo", (void (ofPath::*)(float, float, float, float, float, float)) &ofPath::bezierTo)
		.def("bezierTo", (void (ofPath::*)(float, float, float, float, float, float, float, float, float)) &ofPath::bezierTo)
		.def("quadBezierTo", (void (ofPath::*)(const ofPoint &, const ofPoint &, const ofPoint &)) &ofPath::quadBezierTo)
		.def("quadBezierTo", (void (ofPath::*)(float, float, float, float, float, float)) &ofPath::quadBezierTo)
		.def("quadBezierTo", (void (ofPath::*)(float, float, float, float, float, float, float, float, float)) &ofPath::quadBezierTo)
		.def("arc", (void (ofPath::*)(const ofPoint &, float, float, float, float)) &ofPath::arc)
		.def("arc", (void (ofPath::*)(const ofPoint &, float, float, float, float, bool)) &ofPath::arc)
		.def("arc", (void (ofPath::*)(float, float, float, float, float, float)) &ofPath::arc)
		.def("arc", (void (ofPath::*)(float, float, float, float, float, float, float)) &ofPath::arc)
		.def("arcNegative", (void (ofPath::*)(const ofPoint &, float, float, float, float)) &ofPath::arcNegative)
		.def("arcNegative", (void (ofPath::*)(float, float, float, float, float, float)) &ofPath::arcNegative)
		.def("arcNegative", (void (ofPath::*)(float, float, float, float, float, float, float)) &ofPath::arcNegative)
		.def("triangle", (void (ofPath::*)(float, float, float, float, float, float)) &ofPath::triangle)
		.def("triangle", (void (ofPath::*)(float, float, float, float, float, float, float, float, float)) &ofPath::triangle)
		.def("triangle", (void (ofPath::*)(const ofPoint &, const ofPoint &, const ofPoint &)) &ofPath::triangle)
		.def("circle", (void (ofPath::*)(float, float, float)) &ofPath::circle)
		.def("circle", (void (ofPath::*)(float, float, float, float)) &ofPath::circle)
		.def("circle", (void (ofPath::*)(const ofPoint &, float)) &ofPath::circle)
		.def("ellipse", (void (ofPath::*)(float, float, float, float)) &ofPath::ellipse)
		.def("ellipse", (void (ofPath::*)(float, float, float, float, float)) &ofPath::ellipse)
		.def("ellipse", (void (ofPath::*)(const ofPoint &, float, float)) &ofPath::ellipse)
		.def("rectangle", (void (ofPath::*)(const ofRectangle &)) &ofPath::rectangle)
		.def("rectangle", (void (ofPath::*)(const ofPoint &, float, float)) &ofPath::rectangle)
		.def("rectangle", (void (ofPath::*)(float, float, float, float)) &ofPath::rectangle)
		.def("rectangle", (void (ofPath::*)(float, float, float, float, float)) &ofPath::rectangle)
		.def("rectRounded", (void (ofPath::*)(const ofRectangle &, float)) &ofPath::rectRounded)
		.def("rectRounded", (void (ofPath::*)(const ofPoint &, float, float, float)) &ofPath::rectRounded)
		.def("rectRounded", (void (ofPath::*)(float, float, float, float, float)) &ofPath::rectRounded)
		.def("rectRounded", (void (ofPath::*)(const ofPoint &, float, float, float, float, float, float)) &ofPath::rectRounded)
		.def("rectRounded", (void (ofPath::*)(const ofRectangle &, float, float, float, float)) &ofPath::rectRounded)
		.def("rectRounded", (void (ofPath::*)(float, float, float, float, float, float, float, float, float)) &ofPath::rectRounded)
		.def("setPolyWindingMode",  &ofPath::setPolyWindingMode)
		.def("getWindingMode",      &ofPath::getWindingMode)
		.def("setFilled",           &ofPath::setFilled)
		.def("setStrokeWidth",      &ofPath::setStrokeWidth)
		.def("setColor",            &ofPath::setColor)
		.def("setHexColor",         &ofPath::setHexColor)
		.def("setFillColor",        &ofPath::setFillColor)
		.def("setFillHexColor",     &ofPath::setFillHexColor)
		.def("setStrokeColor",      &ofPath::setStrokeColor)
		.def("setStrokeHexColor",   &ofPath::setStrokeHexColor)
		.def("isFilled",            &ofPath::isFilled)
		.def("getFillColor",        &ofPath::getFillColor)
		.def("getStrokeColor",      &ofPath::getStrokeColor)
		.def("hasOutline",          &ofPath::hasOutline)
		.def("setCurveResolution",  &ofPath::setCurveResolution)
		.def("getCurveResolution",  &ofPath::getCurveResolution)
		.def("setCircleResolution", &ofPath::setCircleResolution)
		.def("getCircleResolution", &ofPath::getCircleResolution)
		.def("setUseShapeColor",    &ofPath::setUseShapeColor)
		.def("getUseShapeColor",    &ofPath::getUseShapeColor)
		.def("draw", (void (ofPath::*)() const) &ofPath::draw) 
		.def("draw", (void (ofPath::*)(float, float) const) &ofPath::draw)
		.def("getTessellation", &ofPath::getTessellation)
		.def("getOutline", &ofPath::getOutline)
		.def("tessellate", &ofPath::tessellate)
		.def("simplify",   &ofPath::simplify)
		.def("translate",  &ofPath::translate)
		.def("rotate",     &ofPath::rotate)
		.def("scale",      &ofPath::scale)
		.def("append",     &ofPath::append)
		.def("setMode",    &ofPath::setMode)
		.def("getMode",    &ofPath::getMode)
		.def("getCommands", (      vector<ofPath::Command> & (ofPath::*)())       &ofPath::getCommands)
		.def("getCommands", (const vector<ofPath::Command> & (ofPath::*)() const) &ofPath::getCommands);

	// 启动就让程序崩溃 
	py::class_<ofPolyline>(m, "ofPolyline")
		.def(py::init<>())
		.def(py::init<const vector<ofPoint>&>())
		.def("clear", &ofPolyline::clear)
		.def("resize", &ofPolyline::resize)
		.def("size", &ofPolyline::size)
		.def("addVertex", (void (ofPolyline::*)(const ofPoint&)) &ofPolyline::addVertex)
		.def("addVertex", (void (ofPolyline::*)(float, float, float)) &ofPolyline::addVertex, "x"_a, "y"_a, "z"_a=0)
		.def("addVertices", (void (ofPolyline::*)(const vector<ofPoint>&)) &ofPolyline::addVertices)
	// 	// .def("addVertices", (void (ofPolyline::*)(const ofPoint* verts, int numverts)) &ofPolyline::addVertices)
		.def("insertVertex", (void (ofPolyline::*)(const ofPoint&, int)) &ofPolyline::insertVertex)
		.def("insertVertex", (void (ofPolyline::*)(float, float, float, int)) &ofPolyline::insertVertex)
		.def("getVertices", (vector<ofPoint>& (ofPolyline::*)()) &ofPolyline::getVertices)
		.def("lineTo", (void (ofPolyline::*)(const ofPoint &)) &ofPolyline::lineTo)
		.def("lineTo", (void (ofPolyline::*)(float, float, float)) &ofPolyline::lineTo, py::arg("x"), py::arg("y"), py::arg("z")=0)
		.def("arc", (void (ofPolyline::*)(const ofPoint &, float, float, float, float, bool, int)) &ofPolyline::arc, 
			py::arg("center"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("clockwise"), py::arg("circleResolution")=20)
		.def("arc", (void (ofPolyline::*)(const ofPoint &, float, float, float, float, int)) &ofPolyline::arc, 
			py::arg("center"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("circleResolution")=20)
		.def("arc", (void (ofPolyline::*)(float, float, float, float, float, float, int)) &ofPolyline::arc, 
			py::arg("x"),py::arg("y"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("circleResolution")=20)
		.def("arc", (void (ofPolyline::*)(float, float, float, float, float, float,float, int)) &ofPolyline::arc, 
			py::arg("x"),py::arg("y"),py::arg("z"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("circleResolution")=20)
		.def("arcNegative", (void (ofPolyline::*)(const ofPoint &, float, float, float, float, int)) &ofPolyline::arcNegative, 
			py::arg("center"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("circleResolution")=20)
		.def("arcNegative", (void (ofPolyline::*)(float, float, float, float, float, float, int)) &ofPolyline::arcNegative, 
			py::arg("x"),py::arg("y"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("circleResolution")=20)
		.def("arcNegative", (void (ofPolyline::*)(float, float, float, float, float, float,float, int)) &ofPolyline::arcNegative, 
			py::arg("x"),py::arg("y"),py::arg("z"), py::arg("radiusX"), py::arg("radiusY"), py::arg("angleBegin"), py::arg("angleEnd"), py::arg("circleResolution")=20)
		.def("curveTo", (void (ofPolyline::*)( const ofPoint &, int)) &ofPolyline::curveTo, py::arg("to"), py::arg("curveResolution")=20)
		.def("curveTo", (void (ofPolyline::*)( float, float, float, int)) &ofPolyline::curveTo, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("curveResolution")=20)
		.def("bezierTo", (void (ofPolyline::*)(const ofPoint &, const ofPoint &, const ofPoint &, int)) &ofPolyline::bezierTo)
		.def("bezierTo", (void (ofPolyline::*)(float, float, float, float, float, float, int)) &ofPolyline::bezierTo)
		.def("bezierTo", (void (ofPolyline::*)(float, float, float, float, float, float,float, float, float, int)) &ofPolyline::bezierTo)
		.def("quadBezierTo", (void (ofPolyline::*)(const ofPoint &, const ofPoint &, const ofPoint &, int)) &ofPolyline::quadBezierTo)
		.def("quadBezierTo", (void (ofPolyline::*)(float, float, float, float, float, float, int)) &ofPolyline::quadBezierTo)
		.def("quadBezierTo", (void (ofPolyline::*)(float, float, float, float, float, float,float, float, float, int)) &ofPolyline::quadBezierTo)
		.def("getSmoothed", &ofPolyline::getSmoothed)
		.def("getResampledBySpacing", &ofPolyline::getResampledBySpacing)
		.def("getResampledByCount", &ofPolyline::getResampledByCount)
		.def("close", &ofPolyline::close)
		.def("setClosed", &ofPolyline::setClosed)
		.def("isClosed", &ofPolyline::isClosed)
		.def("hasChanged", &ofPolyline::hasChanged)
		.def("flagHasChanged", &ofPolyline::flagHasChanged)
		.def("inside", (bool (ofPolyline::*)(float, float) const) &ofPolyline::inside)
		.def("inside", (bool (ofPolyline::*)(const ofPoint &) const) &ofPolyline::inside)
		.def("simplify", &ofPolyline::simplify, py::arg("tolerance")=0.3f)
		.def("getBoundingBox", &ofPolyline::getBoundingBox)
		.def("getPerimeter", &ofPolyline::getPerimeter)
		.def("getArea", &ofPolyline::getArea)
		.def("getCentroid2D", &ofPolyline::getCentroid2D)
		.def("getIndexAtLength", &ofPolyline::getIndexAtLength)
		.def("getIndexAtPercent", &ofPolyline::getIndexAtPercent)
		.def("getLengthAtIndex", &ofPolyline::getLengthAtIndex)
		.def("getLengthAtIndexInterpolated", &ofPolyline::getLengthAtIndexInterpolated)
		.def("getPointAtLength", &ofPolyline::getPointAtLength)
		.def("getPointAtPercent", &ofPolyline::getPointAtPercent)
		.def("getPointAtIndexInterpolated", &ofPolyline::getPointAtIndexInterpolated)
		.def("getAngleAtIndex", &ofPolyline::getAngleAtIndex)
		.def("getAngleAtIndexInterpolated", &ofPolyline::getAngleAtIndexInterpolated)
		.def("getRotationAtIndex", &ofPolyline::getRotationAtIndex)
		.def("getRotationAtIndexInterpolated", &ofPolyline::getRotationAtIndexInterpolated)
		.def("getTangentAtIndex", &ofPolyline::getTangentAtIndex)
		.def("getTangentAtIndexInterpolated", &ofPolyline::getTangentAtIndexInterpolated)
		.def("getNormalAtIndex", &ofPolyline::getNormalAtIndex)
		.def("getNormalAtIndexInterpolated", &ofPolyline::getNormalAtIndexInterpolated)
		.def("getWrappedIndex", &ofPolyline::getWrappedIndex)
		.def("setRightVector", &ofPolyline::setRightVector)
		.def("getRightVector", &ofPolyline::getRightVector)
		.def("getClosestPoint", [](const ofPolyline& po, const ofPoint& target, uint nearestIndex) { return po.getClosestPoint(target, &nearestIndex);}, "target"_a, "nearestIndex"_a=0)
		.def_static("fromRectangle", &ofPolyline::fromRectangle)
		.def("draw", &ofPolyline::draw);

	py::class_<charProps>(m, "charProps")
		.def_readwrite("characterIndex", &charProps::characterIndex)
		.def_readwrite("glyph",          &charProps::glyph)
		.def_readwrite("height",         &charProps::height)
		.def_readwrite("width",          &charProps::width)
		.def_readwrite("bearingX",       &charProps::bearingX)
		.def_readwrite("bearingY",       &charProps::bearingY)
		.def_readwrite("xmin",           &charProps::xmin)
		.def_readwrite("xmax",           &charProps::xmax)
		.def_readwrite("ymin",           &charProps::ymin)
		.def_readwrite("ymax",           &charProps::ymax)
		.def_readwrite("tW",             &charProps::tW)
		.def_readwrite("tH",             &charProps::tH)
		.def_readwrite("t1",             &charProps::t1)
		.def_readwrite("t2",             &charProps::t2)
		.def_readwrite("v1",             &charProps::v1)
		.def_readwrite("v2",             &charProps::v2);
	m.def("ofTrueTypeShutdown", &ofTrueTypeShutdown);

	py::class_<ofBitmapFont>(m, "ofBitmapFont")
		.def(py::init<>())
		.def("getBoundingBox", &ofBitmapFont::getBoundingBox)
		.def("getMesh", &ofBitmapFont::getMesh)
		.def("getTexture", &ofBitmapFont::getTexture);

	py::class_<ofTrueTypeFont>(m, "ofTrueTypeFont")
		.def(py::init<>())
		.def(py::init<const ofTrueTypeFont&>())
		// .def(py::init<ofTrueTypeFont&&>())
		.def("load",                 &ofTrueTypeFont::load)
		.def("isLoaded",             &ofTrueTypeFont::isLoaded)
		.def("isAntiAliased",        &ofTrueTypeFont::isAntiAliased)
		.def("hasFullCharacterSet",  &ofTrueTypeFont::hasFullCharacterSet)
		.def("getNumCharacters",     &ofTrueTypeFont::getNumCharacters)
		.def("getSize",              &ofTrueTypeFont::getSize)
		.def("getLineHeight",        &ofTrueTypeFont::getLineHeight)
		.def("setLineHeight",        &ofTrueTypeFont::setLineHeight)
		.def("getAscenderHeight",    &ofTrueTypeFont::getAscenderHeight)
		.def("getDescenderHeight",   &ofTrueTypeFont::getDescenderHeight)
		.def("getGlyphBBox",         &ofTrueTypeFont::getGlyphBBox)
		.def("getLetterSpacing",     &ofTrueTypeFont::getLetterSpacing)
		.def("setLetterSpacing",     &ofTrueTypeFont::setLetterSpacing)
		.def("getSpaceSize",         &ofTrueTypeFont::getSpaceSize)
		.def("setSpaceSize",         &ofTrueTypeFont::setSpaceSize)
		.def("stringWidth",          &ofTrueTypeFont::stringWidth)
		.def("stringHeight",         &ofTrueTypeFont::stringHeight)
		.def("getStringBoundingBox", &ofTrueTypeFont::getStringBoundingBox)
		.def("drawString",           &ofTrueTypeFont::drawString)
		.def("drawStringAsShapes",   &ofTrueTypeFont::drawStringAsShapes)
		.def("getCharacterAsPoints", &ofTrueTypeFont::getCharacterAsPoints)
		.def("getStringAsPoints",    &ofTrueTypeFont::getStringAsPoints)
		.def("getStringMesh",        &ofTrueTypeFont::getStringMesh)
		.def("getFontTexture",       &ofTrueTypeFont::getFontTexture);

	m.attr("ofTTFCharacter") = m.attr("ofPath");

	py::class_<ofTessellator>(m, "ofTessellator")
		.def(py::init<>())
		.def(py::init<const ofTessellator &>())
		.def("tessellateToMesh", (void (ofTessellator::*)(const vector<ofPolyline>&, ofPolyWindingMode, ofMesh&, bool)) &ofTessellator::tessellateToMesh,
			py::arg("src"), py::arg("polyWindingMode"), py::arg("dstmesh"), py::arg("bIs2D")=false)
		.def("tessellateToMesh", (void (ofTessellator::*)(const ofPolyline&, ofPolyWindingMode, ofMesh&, bool)) &ofTessellator::tessellateToMesh,
			py::arg("src"), py::arg("polyWindingMode"), py::arg("dstmesh"), py::arg("bIs2D")=false)
		.def("tessellateToPolylines", (void (ofTessellator::*)(const vector<ofPolyline>&, ofPolyWindingMode, vector<ofPolyline>&, bool)) &ofTessellator::tessellateToPolylines,
			py::arg("src"), py::arg("polyWindingMode"), py::arg("dstpoly"), py::arg("bIs2D")=false)
		.def("tessellateToPolylines", (void (ofTessellator::*)(const ofPolyline&, ofPolyWindingMode, vector<ofPolyline>&, bool)) &ofTessellator::tessellateToPolylines,
			py::arg("src"), py::arg("polyWindingMode"), py::arg("dstpoly"), py::arg("bIs2D")=false);

	py::enum_<ofImageQualityType>(m, "ofImageQualityType")
		.value("OF_IMAGE_QUALITY_BEST", ofImageQualityType::OF_IMAGE_QUALITY_BEST)
		.value("OF_IMAGE_QUALITY_HIGH", ofImageQualityType::OF_IMAGE_QUALITY_HIGH)
		.value("OF_IMAGE_QUALITY_MEDIUM", ofImageQualityType::OF_IMAGE_QUALITY_MEDIUM)
		.value("OF_IMAGE_QUALITY_LOW", ofImageQualityType::OF_IMAGE_QUALITY_LOW)
		.value("OF_IMAGE_QUALITY_WORST", ofImageQualityType::OF_IMAGE_QUALITY_WORST)
		.export_values();

	py::enum_<ofImageFormat>(m, "ofImageFormat")
		.value("OF_IMAGE_FORMAT_BMP", ofImageFormat::OF_IMAGE_FORMAT_BMP)
		.value("OF_IMAGE_FORMAT_ICO", ofImageFormat::OF_IMAGE_FORMAT_ICO)
		.value("OF_IMAGE_FORMAT_JPEG", ofImageFormat::OF_IMAGE_FORMAT_JPEG)
		.value("OF_IMAGE_FORMAT_JNG", ofImageFormat::OF_IMAGE_FORMAT_JNG)
		.value("OF_IMAGE_FORMAT_KOALA", ofImageFormat::OF_IMAGE_FORMAT_KOALA)
		.value("OF_IMAGE_FORMAT_LBM", ofImageFormat::OF_IMAGE_FORMAT_LBM)
		.value("OF_IMAGE_FORMAT_IFF", ofImageFormat::OF_IMAGE_FORMAT_LBM)
		.value("OF_IMAGE_FORMAT_MNG", ofImageFormat::OF_IMAGE_FORMAT_MNG)
		.value("OF_IMAGE_FORMAT_PBM", ofImageFormat::OF_IMAGE_FORMAT_PBM)
		.value("OF_IMAGE_FORMAT_PBMRAW", ofImageFormat::OF_IMAGE_FORMAT_PBMRAW)
		.value("OF_IMAGE_FORMAT_PCD", ofImageFormat::OF_IMAGE_FORMAT_PCD)
		.value("OF_IMAGE_FORMAT_PCX", ofImageFormat::OF_IMAGE_FORMAT_PCX)
		.value("OF_IMAGE_FORMAT_PGM", ofImageFormat::OF_IMAGE_FORMAT_PGM)
		.value("OF_IMAGE_FORMAT_PGMRAW", ofImageFormat::OF_IMAGE_FORMAT_PGMRAW)
		.value("OF_IMAGE_FORMAT_PNG", ofImageFormat::OF_IMAGE_FORMAT_PNG)
		.value("OF_IMAGE_FORMAT_PPM", ofImageFormat::OF_IMAGE_FORMAT_PPM)
		.value("OF_IMAGE_FORMAT_PPMRAW", ofImageFormat::OF_IMAGE_FORMAT_PPMRAW)
		.value("OF_IMAGE_FORMAT_RAS", ofImageFormat::OF_IMAGE_FORMAT_RAS)
		.value("OF_IMAGE_FORMAT_TARGA", ofImageFormat::OF_IMAGE_FORMAT_TARGA)
		.value("OF_IMAGE_FORMAT_TIFF", ofImageFormat::OF_IMAGE_FORMAT_TIFF)
		.value("OF_IMAGE_FORMAT_WBMP", ofImageFormat::OF_IMAGE_FORMAT_WBMP)
		.value("OF_IMAGE_FORMAT_PSD", ofImageFormat::OF_IMAGE_FORMAT_PSD)
		.value("OF_IMAGE_FORMAT_CUT", ofImageFormat::OF_IMAGE_FORMAT_CUT)
		.value("OF_IMAGE_FORMAT_XBM", ofImageFormat::OF_IMAGE_FORMAT_XBM)
		.value("OF_IMAGE_FORMAT_XPM", ofImageFormat::OF_IMAGE_FORMAT_XPM)
		.value("OF_IMAGE_FORMAT_DDS", ofImageFormat::OF_IMAGE_FORMAT_DDS)
		.value("OF_IMAGE_FORMAT_GIF", ofImageFormat::OF_IMAGE_FORMAT_GIF)
		.value("OF_IMAGE_FORMAT_HDR", ofImageFormat::OF_IMAGE_FORMAT_HDR)
		.value("OF_IMAGE_FORMAT_FAXG3", ofImageFormat::OF_IMAGE_FORMAT_FAXG3)
		.value("OF_IMAGE_FORMAT_SGI", ofImageFormat::OF_IMAGE_FORMAT_SGI)
		.value("OF_IMAGE_FORMAT_EXR", ofImageFormat::OF_IMAGE_FORMAT_EXR)
		.value("OF_IMAGE_FORMAT_J2K", ofImageFormat::OF_IMAGE_FORMAT_J2K)
		.value("OF_IMAGE_FORMAT_JP2", ofImageFormat::OF_IMAGE_FORMAT_JP2)
		.value("OF_IMAGE_FORMAT_PFM", ofImageFormat::OF_IMAGE_FORMAT_PFM)
		.value("OF_IMAGE_FORMAT_PICT", ofImageFormat::OF_IMAGE_FORMAT_PICT)
		.value("OF_IMAGE_FORMAT_RAW", ofImageFormat::OF_IMAGE_FORMAT_RAW)
		.export_values();

	m.def("ofLoadImage", (bool (*)(ofPixels &,      string)) &ofLoadImage);
	m.def("ofLoadImage", (bool (*)(ofTexture &,     string)) &ofLoadImage);
	m.def("ofLoadImage", (bool (*)(ofFloatPixels &, string)) &ofLoadImage);
	m.def("ofLoadImage", (bool (*)(ofShortPixels &, string)) &ofLoadImage);

	m.def("ofLoadImage", (bool (*)(ofPixels &,      const ofBuffer &)) &ofLoadImage);
	m.def("ofLoadImage", (bool (*)(ofTexture &,     const ofBuffer &)) &ofLoadImage);
	m.def("ofLoadImage", (bool (*)(ofFloatPixels &, const ofBuffer &)) &ofLoadImage);
	m.def("ofLoadImage", (bool (*)(ofShortPixels &, const ofBuffer &)) &ofLoadImage);

	m.def("ofSaveImage", (void (*)(ofPixels &,      string, ofImageQualityType)) &ofSaveImage, 
		"pix"_a, "path"_a, "qualityLevel"_a=OF_IMAGE_QUALITY_BEST);
	m.def("ofSaveImage", (void (*)(ofShortPixels &, string, ofImageQualityType)) &ofSaveImage,
		"pix"_a, "path"_a, "qualityLevel"_a=OF_IMAGE_QUALITY_BEST);
	m.def("ofSaveImage", (void (*)(ofFloatPixels &, string, ofImageQualityType)) &ofSaveImage, 
		"pix"_a, "path"_a, "qualityLevel"_a=OF_IMAGE_QUALITY_BEST);

	m.def("ofSaveImage", (void (*)(ofPixels &,      ofBuffer&, ofImageFormat, ofImageQualityType)) &ofSaveImage,
		"pix"_a, "bufer"_a, "format"_a=OF_IMAGE_FORMAT_PNG, "qualityLevel"_a=OF_IMAGE_QUALITY_BEST);
	m.def("ofSaveImage", (void (*)(ofShortPixels &, ofBuffer&, ofImageFormat, ofImageQualityType)) &ofSaveImage,
		"pix"_a, "bufer"_a, "format"_a=OF_IMAGE_FORMAT_PNG, "qualityLevel"_a=OF_IMAGE_QUALITY_BEST);
	m.def("ofSaveImage", (void (*)(ofFloatPixels &, ofBuffer&, ofImageFormat, ofImageQualityType)) &ofSaveImage,
		"pix"_a, "bufer"_a, "format"_a=OF_IMAGE_FORMAT_PNG, "qualityLevel"_a=OF_IMAGE_QUALITY_BEST);

	py::enum_<ofInterpolationMethod>(m, "ofInterpolationMethod")
		.value("OF_INTERPOLATE_NEAREST_NEIGHBOR", ofInterpolationMethod::OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.value("OF_INTERPOLATE_BILINEAR", ofInterpolationMethod::OF_INTERPOLATE_BILINEAR)
		.value("OF_INTERPOLATE_BICUBIC", ofInterpolationMethod::OF_INTERPOLATE_BICUBIC)
		.export_values();


	py::class_<ofPixels>(m, "ofPixels")
		.def(py::init<>())
		.def(py::init<const ofPixels&>())
		.def("allocate", (void (ofPixels::*)(size_t, size_t,size_t)) &ofPixels::allocate)
		.def("allocate", (void (ofPixels::*)(size_t, size_t, ofPixelFormat)) &ofPixels::allocate)
		.def("allocate", (void (ofPixels::*)(size_t, size_t, ofImageType)) &ofPixels::allocate)
		.def("set", (void (ofPixels::*)(unsigned char)) &ofPixels::set)
		.def("set", (void (ofPixels::*)(size_t, unsigned char)) &ofPixels::set)
		.def("setFromPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, size_t)) &ofPixels::setFromPixels)
		.def("setFromPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, ofPixelFormat)) &ofPixels::setFromPixels)
		.def("setFromPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, ofImageType)) &ofPixels::setFromPixels)
		.def("setFromExternalPixels", (void (ofPixels::*)(unsigned char *, size_t, size_t, size_t)) &ofPixels::setFromExternalPixels)
		.def("setFromExternalPixels", (void (ofPixels::*)(unsigned char *, size_t, size_t, ofPixelFormat)) &ofPixels::setFromExternalPixels)
		.def("setFromAlignedPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, size_t, size_t)) &ofPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, ofPixelFormat, size_t)) &ofPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, ofPixelFormat, vector<size_t>)) &ofPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofPixels::*)(const unsigned char *, size_t, size_t, ofPixelFormat, vector<int>)) &ofPixels::setFromAlignedPixels)
		.def("isAllocated", &ofPixels::isAllocated)
		.def("clear",       &ofPixels::clear)
		.def("swap",        &ofPixels::swap)
		.def("crop",        &ofPixels::crop)
		.def("cropTo",      &ofPixels::cropTo)
		.def("rotate90",    &ofPixels::rotate90)
		.def("rotate90To",  &ofPixels::rotate90To)
		.def("mirrorTo",    &ofPixels::mirrorTo)
		.def("mirror",      &ofPixels::mirror)
		.def("pasteInto",   &ofPixels::pasteInto)
		.def("blendInto",   &ofPixels::blendInto)
		.def("swapRgb",     &ofPixels::swapRgb)
		.def("resize", &ofPixels::resize,     "dstWidth"_a, "dstHeight"_a, "interpMethod"_a=OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.def("resizeTo", &ofPixels::resizeTo, "dst"_a, "interpMethod"_a=OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.def("getPixelIndex",      &ofPixels::getPixelIndex)
		.def("getWidth",           &ofPixels::getWidth)
		.def("getHeight",          &ofPixels::getHeight)
		.def("getBytesPerPixel",   &ofPixels::getBytesPerPixel)
		.def("getBitsPerPixel",    &ofPixels::getBitsPerPixel)
		.def("getBytesPerChannel", &ofPixels::getBytesPerChannel)
		.def("getBitsPerChannel",  &ofPixels::getBitsPerChannel)
		.def("getBytesStride",     &ofPixels::getBytesStride)
		.def("getNumChannels",     &ofPixels::getNumChannels)
		.def("getTotalBytes",      &ofPixels::getTotalBytes)
		.def("getNumPlanes",       &ofPixels::getNumPlanes)
		.def("getPlane",           &ofPixels::getPlane)
		.def("getChannel",         &ofPixels::getChannel)
		.def("getPixelFormat",     &ofPixels::getPixelFormat)
		.def("size",               &ofPixels::size)
		.def("getImageType",       &ofPixels::getImageType)
		.def("getColor", (ofColor (ofPixels::*)(size_t,size_t) const) &ofPixels::getColor)
		.def("getColor", (ofColor (ofPixels::*)(size_t) const) &ofPixels::getColor)
		.def("setColor", (void (ofPixels::*)(size_t, size_t, const ofColor&)) &ofPixels::setColor)
		.def("setColor", (void (ofPixels::*)(size_t, const ofColor&)) &ofPixels::setColor)
		.def("setColor", (void (ofPixels::*)(const ofColor&)) &ofPixels::setColor)
		.def("setChannel",     &ofPixels::getImageType)
		.def("setImageType",   &ofPixels::setImageType)
		.def("setNumChannels", &ofPixels::setNumChannels)
		.def_static("pixelBitsFromPixelFormat", &ofPixels::pixelBitsFromPixelFormat)
		.def_static("bytesFromPixelFormat",     &ofPixels::bytesFromPixelFormat);

	py::class_<ofFloatPixels>(m, "ofFloatPixels")
		.def(py::init<>())
		.def(py::init<const ofFloatPixels&>())
		.def("allocate", (void (ofFloatPixels::*)(size_t, size_t,size_t)) &ofFloatPixels::allocate)
		.def("allocate", (void (ofFloatPixels::*)(size_t, size_t, ofPixelFormat)) &ofFloatPixels::allocate)
		.def("allocate", (void (ofFloatPixels::*)(size_t, size_t, ofImageType)) &ofFloatPixels::allocate)
		.def("set", (void (ofFloatPixels::*)(float)) &ofFloatPixels::set)
		.def("set", (void (ofFloatPixels::*)(size_t, float)) &ofFloatPixels::set)
		.def("setFromPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, size_t)) &ofFloatPixels::setFromPixels)
		.def("setFromPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, ofPixelFormat)) &ofFloatPixels::setFromPixels)
		.def("setFromPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, ofImageType)) &ofFloatPixels::setFromPixels)
		.def("setFromExternalPixels", (void (ofFloatPixels::*)(float *, size_t, size_t, size_t)) &ofFloatPixels::setFromExternalPixels)
		.def("setFromExternalPixels", (void (ofFloatPixels::*)(float *, size_t, size_t, ofPixelFormat)) &ofFloatPixels::setFromExternalPixels)
		.def("setFromAlignedPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, size_t, size_t)) &ofFloatPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, ofPixelFormat, size_t)) &ofFloatPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, ofPixelFormat, vector<size_t>)) &ofFloatPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofFloatPixels::*)(const float *, size_t, size_t, ofPixelFormat, vector<int>)) &ofFloatPixels::setFromAlignedPixels)
		.def("isAllocated", &ofFloatPixels::isAllocated)
		.def("clear",       &ofFloatPixels::clear)
		.def("swap",        &ofFloatPixels::swap)
		.def("crop",        &ofFloatPixels::crop)
		.def("cropTo",      &ofFloatPixels::cropTo)
		.def("rotate90",    &ofFloatPixels::rotate90)
		.def("rotate90To",  &ofFloatPixels::rotate90To)
		.def("mirrorTo",    &ofFloatPixels::mirrorTo)
		.def("mirror",      &ofFloatPixels::mirror)
		.def("pasteInto",   &ofFloatPixels::pasteInto)
		.def("blendInto",   &ofFloatPixels::blendInto)
		.def("swapRgb",     &ofFloatPixels::swapRgb)
		.def("resize", &ofFloatPixels::resize,     "dstWidth"_a, "dstHeight"_a, "interpMethod"_a=OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.def("resizeTo", &ofFloatPixels::resizeTo, "dst"_a, "interpMethod"_a=OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.def("getPixelIndex",      &ofFloatPixels::getPixelIndex)
		.def("getWidth",           &ofFloatPixels::getWidth)
		.def("getHeight",          &ofFloatPixels::getHeight)
		.def("getBytesPerPixel",   &ofFloatPixels::getBytesPerPixel)
		.def("getBitsPerPixel",    &ofFloatPixels::getBitsPerPixel)
		.def("getBytesPerChannel", &ofFloatPixels::getBytesPerChannel)
		.def("getBitsPerChannel",  &ofFloatPixels::getBitsPerChannel)
		.def("getBytesStride",     &ofFloatPixels::getBytesStride)
		.def("getNumChannels",     &ofFloatPixels::getNumChannels)
		.def("getTotalBytes",      &ofFloatPixels::getTotalBytes)
		.def("getNumPlanes",       &ofFloatPixels::getNumPlanes)
		.def("getPlane",           &ofFloatPixels::getPlane)
		.def("getChannel",         &ofFloatPixels::getChannel)
		.def("getPixelFormat",     &ofFloatPixels::getPixelFormat)
		.def("size",               &ofFloatPixels::size)
		.def("getImageType",       &ofFloatPixels::getImageType)
		.def("getColor", (ofFloatColor (ofFloatPixels::*)(size_t,size_t) const) &ofFloatPixels::getColor)
		.def("getColor", (ofFloatColor (ofFloatPixels::*)(size_t) const) &ofFloatPixels::getColor)
		.def("setColor", (void (ofFloatPixels::*)(size_t, size_t, const ofFloatColor&)) &ofFloatPixels::setColor)
		.def("setColor", (void (ofFloatPixels::*)(size_t, const ofFloatColor&)) &ofFloatPixels::setColor)
		.def("setColor", (void (ofFloatPixels::*)(const ofFloatColor&)) &ofFloatPixels::setColor)
		.def("setChannel",     &ofFloatPixels::getImageType)
		.def("setImageType",   &ofFloatPixels::setImageType)
		.def("setNumChannels", &ofFloatPixels::setNumChannels)
		.def_static("pixelBitsFromPixelFormat", &ofFloatPixels::pixelBitsFromPixelFormat)
		.def_static("bytesFromPixelFormat",     &ofFloatPixels::bytesFromPixelFormat);

	py::class_<ofShortPixels>(m, "ofShortPixels")
		.def(py::init<>())
		.def(py::init<const ofShortPixels&>())
		.def("allocate", (void (ofShortPixels::*)(size_t, size_t,size_t)) &ofShortPixels::allocate)
		.def("allocate", (void (ofShortPixels::*)(size_t, size_t, ofPixelFormat)) &ofShortPixels::allocate)
		.def("allocate", (void (ofShortPixels::*)(size_t, size_t, ofImageType)) &ofShortPixels::allocate)
		.def("set", (void (ofShortPixels::*)(unsigned short)) &ofShortPixels::set)
		.def("set", (void (ofShortPixels::*)(size_t, unsigned short)) &ofShortPixels::set)
		.def("setFromPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, size_t)) &ofShortPixels::setFromPixels)
		.def("setFromPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, ofPixelFormat)) &ofShortPixels::setFromPixels)
		.def("setFromPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, ofImageType)) &ofShortPixels::setFromPixels)
		.def("setFromExternalPixels", (void (ofShortPixels::*)(unsigned short *, size_t, size_t, size_t)) &ofShortPixels::setFromExternalPixels)
		.def("setFromExternalPixels", (void (ofShortPixels::*)(unsigned short *, size_t, size_t, ofPixelFormat)) &ofShortPixels::setFromExternalPixels)
		.def("setFromAlignedPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, size_t, size_t)) &ofShortPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, ofPixelFormat, size_t)) &ofShortPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, ofPixelFormat, vector<size_t>)) &ofShortPixels::setFromAlignedPixels)
		.def("setFromAlignedPixels", (void (ofShortPixels::*)(const unsigned short *, size_t, size_t, ofPixelFormat, vector<int>)) &ofShortPixels::setFromAlignedPixels)
		.def("isAllocated", &ofShortPixels::isAllocated)
		.def("clear",       &ofShortPixels::clear)
		.def("swap",        &ofShortPixels::swap)
		.def("crop",        &ofShortPixels::crop)
		.def("cropTo",      &ofShortPixels::cropTo)
		.def("rotate90",    &ofShortPixels::rotate90)
		.def("rotate90To",  &ofShortPixels::rotate90To)
		.def("mirrorTo",    &ofShortPixels::mirrorTo)
		.def("mirror",      &ofShortPixels::mirror)
		.def("pasteInto",   &ofShortPixels::pasteInto)
		.def("blendInto",   &ofShortPixels::blendInto)
		.def("swapRgb",     &ofShortPixels::swapRgb)
		.def("resize", &ofShortPixels::resize,     "dstWidth"_a, "dstHeight"_a, "interpMethod"_a=OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.def("resizeTo", &ofShortPixels::resizeTo, "dst"_a, "interpMethod"_a=OF_INTERPOLATE_NEAREST_NEIGHBOR)
		.def("getPixelIndex",      &ofShortPixels::getPixelIndex)
		.def("getWidth",           &ofShortPixels::getWidth)
		.def("getHeight",          &ofShortPixels::getHeight)
		.def("getBytesPerPixel",   &ofShortPixels::getBytesPerPixel)
		.def("getBitsPerPixel",    &ofShortPixels::getBitsPerPixel)
		.def("getBytesPerChannel", &ofShortPixels::getBytesPerChannel)
		.def("getBitsPerChannel",  &ofShortPixels::getBitsPerChannel)
		.def("getBytesStride",     &ofShortPixels::getBytesStride)
		.def("getNumChannels",     &ofShortPixels::getNumChannels)
		.def("getTotalBytes",      &ofShortPixels::getTotalBytes)
		.def("getNumPlanes",       &ofShortPixels::getNumPlanes)
		.def("getPlane",           &ofShortPixels::getPlane)
		.def("getChannel",         &ofShortPixels::getChannel)
		.def("getPixelFormat",     &ofShortPixels::getPixelFormat)
		.def("size",               &ofShortPixels::size)
		.def("getImageType",       &ofShortPixels::getImageType)
		.def("getColor", (ofShortColor (ofShortPixels::*)(size_t,size_t) const) &ofShortPixels::getColor)
		.def("getColor", (ofShortColor (ofShortPixels::*)(size_t) const) &ofShortPixels::getColor)
		.def("setColor", (void (ofShortPixels::*)(size_t, size_t, const ofShortColor&)) &ofShortPixels::setColor)
		.def("setColor", (void (ofShortPixels::*)(size_t, const ofShortColor&)) &ofShortPixels::setColor)
		.def("setColor", (void (ofShortPixels::*)(const ofShortColor&)) &ofShortPixels::setColor)
		.def("setChannel",     &ofShortPixels::getImageType)
		.def("setImageType",   &ofShortPixels::setImageType)
		.def("setNumChannels", &ofShortPixels::setNumChannels)
		.def_static("pixelBitsFromPixelFormat", &ofShortPixels::pixelBitsFromPixelFormat)
		.def_static("bytesFromPixelFormat",     &ofShortPixels::bytesFromPixelFormat);


	py::class_<ofImage>(m, "ofImage")
		.def(py::init<>())
		.def(py::init<const ofPixels&>())
		.def(py::init<const ofFile&>())
		.def(py::init<const string&>())
		.def(py::init<const ofImage&>())
		.def("allocate", &ofImage::allocate)
		.def("isAllocated", &ofImage::isAllocated)
		.def("clear", &ofImage::clear)
		.def("clone", (void (ofImage::*)(const ofImage &)) &ofImage::clone)
		.def("load", (bool (ofImage::*)(const string &)) &ofImage::load)
		.def("load", (bool (ofImage::*)(const ofBuffer &)) &ofImage::load)
		.def("load", (bool (ofImage::*)(const ofFile &)) &ofImage::load)
		.def("draw", (void (ofImage::*)(float, float) const) &ofImage::draw)
		.def("draw", (void (ofImage::*)(float, float, float) const) &ofImage::draw)
		.def("draw", (void (ofImage::*)(float, float, float, float) const) &ofImage::draw)
		.def("draw", (void (ofImage::*)(float, float, float, float, float) const) &ofImage::draw)
		.def("drawSubsection", (void (ofImage::*)(float, float, float, float, float, float) const) &ofImage::drawSubsection)
		.def("drawSubsection", (void (ofImage::*)(float, float, float, float, float, float, float) const) &ofImage::drawSubsection)
		.def("drawSubsection", (void (ofImage::*)(float, float, float, float, float, float, float, float) const) &ofImage::drawSubsection)
		.def("drawSubsection", (void (ofImage::*)(float, float, float, float, float, float, float, float, float) const) &ofImage::drawSubsection)
		.def("update", &ofImage::update)
		.def("setUseTexture", &ofImage::setUseTexture)
		.def("isUsingTexture", &ofImage::isUsingTexture)
		.def("getTexture", (ofTexture& (ofImage::*)()) &ofImage::getTexture)
		.def("getPixels", (ofPixels& (ofImage::*)()) &ofImage::getPixels)
		.def("getColor", (ofColor (ofImage::*)(int, int) const) &ofImage::getColor)
		.def("getColor", (ofColor (ofImage::*)(int) const) &ofImage::getColor)
		// .def("getTexture", (const ofTexture& (ofImage::*)() const) &ofImage::getTexture)
		.def("bind", &ofImage::bind, "textureLocation"_a=0)
		.def("unbind", &ofImage::unbind, "textureLocation"_a=0)
		.def("setCompression", &ofImage::setCompression)
		.def("getHeight", &ofImage::getHeight)
		.def("getWidth", &ofImage::getWidth)
		.def("setColor", (void (ofImage::*)(int, int, const ofColor&)) &ofImage::setColor)
		.def("setColor", (void (ofImage::*)(     int, const ofColor&)) &ofImage::setColor)
		.def("setColor", (void (ofImage::*)(          const ofColor&)) &ofImage::setColor)
		.def("setFromPixels", (void (ofImage::*)(const ofPixels &)) &ofImage::setFromPixels)
		.def("setFromPixels", (void (ofImage::*)(const unsigned char *, int, int, ofImageType, bool)) &ofImage::setFromPixels,
			 "pixels"_a, "w"_a, "h"_a, "type"_a, "bOrderIsRGB"_a=true)
		.def("grabScreen", &ofImage::grabScreen)
		.def("setImageType", &ofImage::setImageType)
		.def("getImageType", &ofImage::getImageType)
		.def("resize", &ofImage::resize)
		.def("crop", &ofImage::crop)
		.def("cropFrom", &ofImage::cropFrom)
		.def("rotate90", &ofImage::rotate90)
		.def("mirror", &ofImage::mirror)
		.def("setAnchorPercent", &ofImage::setAnchorPercent)
		.def("setAnchorPoint", &ofImage::setAnchorPoint)
		.def("resetAnchor", &ofImage::resetAnchor)
		.def("save", (void (ofImage::*)(string, ofImageQualityType)) &ofImage::save, "fileName"_a, "compressionLevel"_a=OF_IMAGE_QUALITY_BEST)
		.def("save", (void (ofImage::*)(ofBuffer &, ofImageQualityType)) &ofImage::save, "buffer"_a, "compressionLevel"_a=OF_IMAGE_QUALITY_BEST)
		.def("save", (void (ofImage::*)(const ofFile &, ofImageQualityType)) &ofImage::save, "file"_a, "compressionLevel"_a=OF_IMAGE_QUALITY_BEST);

	py::class_<ofShortImage>(m, "ofShortImage")
		.def(py::init<>())
		.def(py::init<const ofShortPixels&>())
		.def(py::init<const ofFile&>())
		.def(py::init<const string&>())
		.def(py::init<const ofShortImage&>())
		.def("allocate", &ofShortImage::allocate)
		.def("isAllocated", &ofShortImage::isAllocated)
		.def("clear", &ofShortImage::clear)
		.def("clone", (void (ofShortImage::*)(const ofShortImage &)) &ofShortImage::clone)
		.def("load", (bool (ofShortImage::*)(const string &)) &ofShortImage::load)
		.def("load", (bool (ofShortImage::*)(const ofBuffer &)) &ofShortImage::load)
		.def("load", (bool (ofShortImage::*)(const ofFile &)) &ofShortImage::load)
		.def("draw", (void (ofShortImage::*)(float, float) const) &ofShortImage::draw)
		.def("draw", (void (ofShortImage::*)(float, float, float) const) &ofShortImage::draw)
		.def("draw", (void (ofShortImage::*)(float, float, float, float) const) &ofShortImage::draw)
		.def("draw", (void (ofShortImage::*)(float, float, float, float, float) const) &ofShortImage::draw)
		.def("drawSubsection", (void (ofShortImage::*)(float, float, float, float, float, float) const) &ofShortImage::drawSubsection)
		.def("drawSubsection", (void (ofShortImage::*)(float, float, float, float, float, float, float) const) &ofShortImage::drawSubsection)
		.def("drawSubsection", (void (ofShortImage::*)(float, float, float, float, float, float, float, float) const) &ofShortImage::drawSubsection)
		.def("drawSubsection", (void (ofShortImage::*)(float, float, float, float, float, float, float, float, float) const) &ofShortImage::drawSubsection)
		.def("update", &ofShortImage::update)
		.def("setUseTexture", &ofShortImage::setUseTexture)
		.def("isUsingTexture", &ofShortImage::isUsingTexture)
		.def("getTexture", (ofTexture& (ofShortImage::*)()) &ofShortImage::getTexture)
		.def("getPixels", (ofShortPixels& (ofShortImage::*)()) &ofShortImage::getPixels)
		.def("getColor", (ofShortColor (ofShortImage::*)(int, int) const) &ofShortImage::getColor)
		.def("getColor", (ofShortColor (ofShortImage::*)(int) const) &ofShortImage::getColor)
		// .def("getTexture", (const ofTexture& (ofShortImage::*)() const) &ofShortImage::getTexture)
		.def("bind",   &ofShortImage::bind,   "textureLocation"_a=0)
		.def("unbind", &ofShortImage::unbind, "textureLocation"_a=0)
		.def("setCompression", &ofShortImage::setCompression)
		.def("getHeight", &ofShortImage::getHeight)
		.def("getWidth", &ofShortImage::getWidth)
		.def("setColor", (void (ofShortImage::*)(int, int, const ofShortColor&)) &ofShortImage::setColor)
		.def("setColor", (void (ofShortImage::*)(     int, const ofShortColor&)) &ofShortImage::setColor)
		.def("setColor", (void (ofShortImage::*)(          const ofShortColor&)) &ofShortImage::setColor)
		.def("setFromPixels", (void (ofShortImage::*)(const ofShortPixels &)) &ofShortImage::setFromPixels)
		.def("setFromPixels", (void (ofShortImage::*)(const unsigned short *, int, int, ofImageType, bool)) &ofShortImage::setFromPixels,
			 "pixels"_a, "w"_a, "h"_a, "type"_a, "bOrderIsRGB"_a=true)
		.def("grabScreen",       &ofShortImage::grabScreen)
		.def("setImageType",     &ofShortImage::setImageType)
		.def("getImageType",     &ofShortImage::getImageType)
		.def("resize",           &ofShortImage::resize)
		.def("crop",             &ofShortImage::crop)
		.def("cropFrom",         &ofShortImage::cropFrom)
		.def("rotate90",         &ofShortImage::rotate90)
		.def("mirror",           &ofShortImage::mirror)
		.def("setAnchorPercent", &ofShortImage::setAnchorPercent)
		.def("setAnchorPoint",   &ofShortImage::setAnchorPoint)
		.def("resetAnchor",      &ofShortImage::resetAnchor)
		.def("save", (void (ofShortImage::*)(string,         ofImageQualityType)) &ofShortImage::save, "fileName"_a, "compressionLevel"_a=OF_IMAGE_QUALITY_BEST)
		.def("save", (void (ofShortImage::*)(ofBuffer &,     ofImageQualityType)) &ofShortImage::save, "buffer"_a,   "compressionLevel"_a=OF_IMAGE_QUALITY_BEST)
		.def("save", (void (ofShortImage::*)(const ofFile &, ofImageQualityType)) &ofShortImage::save, "file"_a,     "compressionLevel"_a=OF_IMAGE_QUALITY_BEST);

	py::class_<ofFloatImage>(m, "ofFloatImage")
		.def(py::init<>())
		.def(py::init<const ofFloatPixels&>())
		.def(py::init<const ofFile&>())
		.def(py::init<const string&>())
		.def(py::init<const ofFloatImage&>())
		.def("allocate", &ofFloatImage::allocate)
		.def("isAllocated", &ofFloatImage::isAllocated)
		.def("clear", &ofFloatImage::clear)
		.def("clone", (void (ofFloatImage::*)(const ofFloatImage &)) &ofFloatImage::clone)
		.def("load", (bool (ofFloatImage::*)(const string &)) &ofFloatImage::load)
		.def("load", (bool (ofFloatImage::*)(const ofBuffer &)) &ofFloatImage::load)
		.def("load", (bool (ofFloatImage::*)(const ofFile &)) &ofFloatImage::load)
		.def("draw", (void (ofFloatImage::*)(float, float) const) &ofFloatImage::draw)
		.def("draw", (void (ofFloatImage::*)(float, float, float) const) &ofFloatImage::draw)
		.def("draw", (void (ofFloatImage::*)(float, float, float, float) const) &ofFloatImage::draw)
		.def("draw", (void (ofFloatImage::*)(float, float, float, float, float) const) &ofFloatImage::draw)
		.def("drawSubsection", (void (ofFloatImage::*)(float, float, float, float, float, float) const) &ofFloatImage::drawSubsection)
		.def("drawSubsection", (void (ofFloatImage::*)(float, float, float, float, float, float, float) const) &ofFloatImage::drawSubsection)
		.def("drawSubsection", (void (ofFloatImage::*)(float, float, float, float, float, float, float, float) const) &ofFloatImage::drawSubsection)
		.def("drawSubsection", (void (ofFloatImage::*)(float, float, float, float, float, float, float, float, float) const) &ofFloatImage::drawSubsection)
		.def("update", &ofFloatImage::update)
		.def("setUseTexture", &ofFloatImage::setUseTexture)
		.def("isUsingTexture", &ofFloatImage::isUsingTexture)
		.def("getTexture", (ofTexture& (ofFloatImage::*)()) &ofFloatImage::getTexture)
		.def("getPixels", (ofFloatPixels& (ofFloatImage::*)()) &ofFloatImage::getPixels)
		.def("getColor", (ofFloatColor (ofFloatImage::*)(int, int) const) &ofFloatImage::getColor)
		.def("getColor", (ofFloatColor (ofFloatImage::*)(int) const) &ofFloatImage::getColor)
		// .def("getTexture", (const ofTexture& (ofFloatImage::*)() const) &ofFloatImage::getTexture)
		.def("bind",   &ofFloatImage::bind,   "textureLocation"_a=0)
		.def("unbind", &ofFloatImage::unbind, "textureLocation"_a=0)
		.def("setCompression", &ofFloatImage::setCompression)
		.def("getHeight", &ofFloatImage::getHeight)
		.def("getWidth", &ofFloatImage::getWidth)
		.def("setColor", (void (ofFloatImage::*)(int, int, const ofFloatColor&)) &ofFloatImage::setColor)
		.def("setColor", (void (ofFloatImage::*)(     int, const ofFloatColor&)) &ofFloatImage::setColor)
		.def("setColor", (void (ofFloatImage::*)(          const ofFloatColor&)) &ofFloatImage::setColor)
		.def("setFromPixels", (void (ofFloatImage::*)(const ofFloatPixels &)) &ofFloatImage::setFromPixels)
		.def("setFromPixels", (void (ofFloatImage::*)(const float *, int, int, ofImageType, bool)) &ofFloatImage::setFromPixels,
			 "pixels"_a, "w"_a, "h"_a, "type"_a, "bOrderIsRGB"_a=true)
		.def("grabScreen",       &ofFloatImage::grabScreen)
		.def("setImageType",     &ofFloatImage::setImageType)
		.def("getImageType",     &ofFloatImage::getImageType)
		.def("resize",           &ofFloatImage::resize)
		.def("crop",             &ofFloatImage::crop)
		.def("cropFrom",         &ofFloatImage::cropFrom)
		.def("rotate90",         &ofFloatImage::rotate90)
		.def("mirror",           &ofFloatImage::mirror)
		.def("setAnchorPercent", &ofFloatImage::setAnchorPercent)
		.def("setAnchorPoint",   &ofFloatImage::setAnchorPoint)
		.def("resetAnchor",      &ofFloatImage::resetAnchor)
		.def("save", (void (ofFloatImage::*)(string,         ofImageQualityType)) &ofFloatImage::save, "fileName"_a, "compressionLevel"_a=OF_IMAGE_QUALITY_BEST)
		.def("save", (void (ofFloatImage::*)(ofBuffer &,     ofImageQualityType)) &ofFloatImage::save, "buffer"_a,   "compressionLevel"_a=OF_IMAGE_QUALITY_BEST)
		.def("save", (void (ofFloatImage::*)(const ofFile &, ofImageQualityType)) &ofFloatImage::save, "file"_a,     "compressionLevel"_a=OF_IMAGE_QUALITY_BEST);

}