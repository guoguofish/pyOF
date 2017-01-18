#pragma once
#include "ofMain.h"
#include "ofxOpenCV.h"
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;
// ofxCvBlob 类
// ofxCvImage 基类
// ofxCvShortImage 类
// ofxCvFloatImage 类
// ofxCvColorImage 类
// ofxCvGrayscaleImage 类
// ofxCvHaarFinder 类
// ofxCvContourFinder 类
void pybind_ofxOpenCV(py::module &m) {
    using namespace py::literals;
    enum SubPixelInterpolationMethods
    {
        CV_INTER_NN        =0,
        CV_INTER_LINEAR    =1,
        CV_INTER_CUBIC     =2,
        CV_INTER_AREA      =3,
        CV_INTER_LANCZOS4  =4
    };
    py::enum_<SubPixelInterpolationMethods>(m, "InterpolationMethods")
        .value("CV_INTER_NN",    SubPixelInterpolationMethods::CV_INTER_NN)
        .value("CV_INTER_LINEAR", SubPixelInterpolationMethods::CV_INTER_LINEAR)
        .value("CV_INTER_CUBIC", SubPixelInterpolationMethods::CV_INTER_CUBIC)
        .value("CV_INTER_AREA", SubPixelInterpolationMethods::CV_INTER_AREA)
        .value("CV_INTER_LANCZOS4", SubPixelInterpolationMethods::CV_INTER_LANCZOS4)
        .export_values();

    // 不完整
    py::class_<IplImage>(m, "IplImage")
        .def_readwrite("nSize", &IplImage::nSize)
        .def_readwrite("ID", &IplImage::ID)
        .def_readwrite("nChannels", &IplImage::nChannels)
        .def_readwrite("alphaChannel", &IplImage::alphaChannel)
        .def_readwrite("depth", &IplImage::depth)
        .def_readwrite("dataOrder", &IplImage::dataOrder)
        .def_readwrite("origin", &IplImage::origin)
        .def_readwrite("align", &IplImage::align)
        .def_readwrite("width", &IplImage::width)
        .def_readwrite("height", &IplImage::height)
        .def_readwrite("imageSize", &IplImage::imageSize)
        .def_readwrite("widthStep", &IplImage::widthStep)
        .def_readwrite("imageDataOrigin", &IplImage::imageDataOrigin);

    py::enum_<ofxCvRoiMode>(m, "ofxCvRoiMode")
        .value("OFX_CV_ROI_MODE_INTERSECT",    ofxCvRoiMode::OFX_CV_ROI_MODE_INTERSECT)
        .value("OFX_CV_ROI_MODE_NONINTERSECT", ofxCvRoiMode::OFX_CV_ROI_MODE_NONINTERSECT)
        .export_values();

    py::class_<ofxCvBlob>(m, "ofxCvBlob")
        .def(py::init<>())
        .def_readwrite("area", &ofxCvBlob::area)
        .def_readwrite("length", &ofxCvBlob::length)
        .def_readwrite("boundingRect", &ofxCvBlob::boundingRect)
        .def_readwrite("centroid", &ofxCvBlob::centroid)
        .def_readwrite("hole", &ofxCvBlob::hole)
        .def_readwrite("pts", &ofxCvBlob::pts)
        .def_readwrite("nPts", &ofxCvBlob::nPts)
        .def("draw", &ofxCvBlob::draw, "x"_a=0, "y"_a=0);

    // py::class_<ofxCvImage>(m, "ofxCvImage");
        // .def(py::init<>())
        // .def("__init__", [](ofxCvImage &m) { new (&m) ofxCvImage(); })
    py::class_<ofxCvGrayscaleImage>(m, "ofxCvGrayscaleImage")
        .def(py::init<>())
        .def(py::init<const ofxCvGrayscaleImage&>())
        // from Base class: ofxCvImage
        .def("allocate", [](ofxCvGrayscaleImage &m, int w, int h){return m.allocate(w,h);})
        .def("clear", [](ofxCvGrayscaleImage &m){return m.clear();})
        .def("getWidth", [](ofxCvGrayscaleImage &m){return m.getWidth();})
        .def("getHeight", [](ofxCvGrayscaleImage &m){return m.getHeight();})
        .def("setUseTexture", [](ofxCvGrayscaleImage &m, bool bUse){return m.setUseTexture( bUse );})
        .def("getTextureReference", [](ofxCvGrayscaleImage &m){return m.getTextureReference();})
        .def("setROI", [](ofxCvGrayscaleImage &m, int x, int y, int w, int h ){return m.setROI(x,y,w,h);})
        .def("setROI", [](ofxCvGrayscaleImage &m, ofRectangle& rect) {return m.setROI(rect);})
        .def("getROI", [](ofxCvGrayscaleImage &m) {return m.getROI();})
        .def("resetROI", [](ofxCvGrayscaleImage &m) {return m.resetROI();})
        .def("getIntersectionROI", [](ofxCvGrayscaleImage &m, ofRectangle& rec1, ofRectangle& rec2) {return m.getIntersectionROI(rec1, rec2);})
        .def("__isub__", [](ofxCvGrayscaleImage &m, float val){ return m-=val;}, py::is_operator())
        .def("__iadd__", [](ofxCvGrayscaleImage &m, float val){ return m+=val;}, py::is_operator())
        .def("__isub__", [](ofxCvGrayscaleImage &m, ofxCvGrayscaleImage& mom){ return m-=mom;}, py::is_operator())
        .def("__iadd__", [](ofxCvGrayscaleImage &m, ofxCvGrayscaleImage& mom){ return m+=mom;}, py::is_operator())
        .def("__imul__", [](ofxCvGrayscaleImage &m, ofxCvGrayscaleImage& mom){ return m*=mom;}, py::is_operator())
        .def("__iand__", [](ofxCvGrayscaleImage &m, ofxCvGrayscaleImage& mom){ return m&=mom;}, py::is_operator())
        .def("getPixels",    [](ofxCvGrayscaleImage &m){return m.getPixels();})
        .def("getRoiPixels", [](ofxCvGrayscaleImage &m){return m.getRoiPixels();})
        .def("getCvImage",   [](ofxCvGrayscaleImage &m){return m.getCvImage();})
        .def("draw",   [](ofxCvGrayscaleImage &m, float x, float y){return m.draw(x,y);})
        .def("drawROI",[](ofxCvGrayscaleImage &m, float x, float y){return m.drawROI(x,y);})
        .def("draw",   [](ofxCvGrayscaleImage &m, float x, float y, float w, float h){return m.draw(x,y,w,h);})
        .def("drawROI",[](ofxCvGrayscaleImage &m, float x, float y, float w, float h){return m.drawROI(x,y,w,h);})
        .def("setAnchorPercent",[](ofxCvGrayscaleImage &m, float xPct, float yPct){return m.setAnchorPercent(xPct,yPct);})
        .def("setAnchorPoint",[](ofxCvGrayscaleImage &m, float x, float y){return m.setAnchorPoint(x,y);})
        .def("resetAnchor",[](ofxCvGrayscaleImage &m, float x, float y){return m.resetAnchor();})
        .def("erode", [](ofxCvGrayscaleImage &m){return m.erode();})
        .def("dilate",[](ofxCvGrayscaleImage &m){return m.dilate();})
        .def("blur",[](ofxCvGrayscaleImage &m, int value){return m.blur(value);}, "value"_a=3)
        .def("blurGaussian",[](ofxCvGrayscaleImage &m, int value){return m.blurGaussian(value);}, "value"_a=3)
        .def("invert",[](ofxCvGrayscaleImage &m){return m.invert();})
        .def("mirror", [](ofxCvGrayscaleImage &m, bool bFlipVertically, bool bFlipHorizontally){return m.mirror(bFlipVertically, bFlipHorizontally);})
        .def("translate", [](ofxCvGrayscaleImage &m, float x, float y){return m.translate(x, y);})
        .def("rotate", [](ofxCvGrayscaleImage &m, float angle, float centerX, float centerY){return m.rotate( angle, centerX, centerY);})
        .def("scale", [](ofxCvGrayscaleImage &m, float scaleX, float sclaeY ){return m.scale( scaleX, sclaeY );})
        .def("transform", [](ofxCvGrayscaleImage &m, float angle, float centerX, float centerY, float scaleX, float scaleY, float moveX, float moveY){return m.transform( angle, centerX, centerY, scaleX, scaleY, moveX, moveY);})
        .def("undistort", [](ofxCvGrayscaleImage &m, float radialDistX, float radialDistY,float tangentDistX, float tangentDistY, float focalX, float focalY, float centerX, float centerY){return m.undistort( radialDistX, radialDistY, tangentDistX, tangentDistY, focalX, focalY, centerX, centerY);})
        .def("remap", [](ofxCvGrayscaleImage &m, IplImage* mapX, IplImage* mapY ){return m.remap( mapX, mapY );})
        .def("warpPerspective", [](ofxCvGrayscaleImage &m, ofPoint& A, ofPoint& B, ofPoint& C, ofPoint& D ){return m.warpPerspective(A,B,C,D);})
        .def("countNonZeroInRegion", [](ofxCvGrayscaleImage &m, int x, int y, int w, int h){return m.countNonZeroInRegion(x,y,w,h);})
        // .def("warpIntoMe", [](ofxCvGrayscaleImage &m, ofxCvGrayscaleImage &mom, ofPoint src[4], ofPoint dst[4]){return m.warpIntoMe(mom, src, dst);})
        // from ofxCvGrayscaleImage
        .def("set", &ofxCvGrayscaleImage::set)
        .def("setFromPixels", (void (ofxCvGrayscaleImage::*)(const unsigned char*, int, int)) &ofxCvGrayscaleImage::setFromPixels)
        .def("setRoiFromPixels", &ofxCvGrayscaleImage::setRoiFromPixels)
        .def("assign",[](ofxCvGrayscaleImage &m, const ofPixels &_pixels){ m = _pixels; return m; })
        .def("assign",[](ofxCvGrayscaleImage &m, const ofxCvGrayscaleImage &mom){ m =mom; return m; })
        .def("assign",[](ofxCvGrayscaleImage &m, const ofxCvColorImage &mom){ m =mom; return m; })
        .def("assign",[](ofxCvGrayscaleImage &m, const ofxCvFloatImage &mom){ m =mom; return m; })
        .def("assign",[](ofxCvGrayscaleImage &m, const ofxCvShortImage &mom){ m =mom; return m; })
        .def("assign",[](ofxCvGrayscaleImage &m, const IplImage* mom){ m = mom; return m;}, py::keep_alive<1,2>())
        .def("absDiff", (void (ofxCvGrayscaleImage::*)( ofxCvGrayscaleImage& mom)) &ofxCvGrayscaleImage::absDiff)
        .def("absDiff", (void (ofxCvGrayscaleImage::*)( ofxCvGrayscaleImage& mom, ofxCvGrayscaleImage& dad)) &ofxCvGrayscaleImage::absDiff)
        .def("contrastStretch", &ofxCvGrayscaleImage::contrastStretch)
        .def("convertToRange", &ofxCvGrayscaleImage::convertToRange)
        .def("threshold", &ofxCvGrayscaleImage::threshold)
        .def("adaptiveThreshold", &ofxCvGrayscaleImage::adaptiveThreshold)
        .def("brightnessContrast", &ofxCvGrayscaleImage::brightnessContrast)
        .def("resize", &ofxCvGrayscaleImage::resize)
        .def("blurHeavily", &ofxCvGrayscaleImage::blurHeavily)
        .def("erode_3x3", &ofxCvGrayscaleImage::erode_3x3)
        .def("dilate_3x3", &ofxCvGrayscaleImage::dilate_3x3)
        .def("setFromColorImage", &ofxCvGrayscaleImage::setFromColorImage)
        .def("setFromFloatImage", &ofxCvGrayscaleImage::setFromFloatImage)
        .def("scaleIntoMe", [](ofxCvGrayscaleImage &m, ofxCvGrayscaleImage &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvGrayscaleImage &m, ofxCvShortImage     &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvGrayscaleImage &m, ofxCvFloatImage     &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvGrayscaleImage &m, ofxCvColorImage     &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN);

    py::class_<ofxCvShortImage>(m, "ofxCvShortImage")
        .def(py::init<>())
        .def(py::init<const ofxCvShortImage&>())
        // from Base class: ofxCvImage
        .def("allocate",           [](ofxCvShortImage &m,int w, int h){ return m.allocate(w, h);} )
        .def("getWidth",           [](ofxCvShortImage &m){return m.getWidth();} )
        .def("getHeight",          [](ofxCvShortImage &m){return m.getHeight();} )
        .def("setUseTexture",      [](ofxCvShortImage &m, bool bUse){return m.setUseTexture(bUse);} )
        .def("getROI",             [](ofxCvShortImage &m){return m.getROI();})
        .def("resetROI",           [](ofxCvShortImage &m){return m.resetROI();} )
        .def("getIntersectionROI", [](ofxCvShortImage &m, ofRectangle& rec1, ofRectangle& rec2){return m.getIntersectionROI(rec1, rec2);})
        .def("setROI", [](ofxCvShortImage &m, int x, int y, int w, int h){return m.setROI(x,y,w,h);})
        .def("setROI", [](ofxCvShortImage &m, const ofRectangle &rect){return m.setROI(rect);})
        .def("getPixels", [](ofxCvShortImage &m){return m.getPixels();} )
        .def("getRoiPixels",[](ofxCvShortImage &m){return m.getRoiPixels();})
        .def("getCvImage", [](ofxCvShortImage &m ){return m.getCvImage();})
        .def("draw", [](ofxCvShortImage &m, float x, float y){ return m.draw(x,y);})
        .def("draw", [](ofxCvShortImage &m, float x, float y, float w, float h){return m.draw(x,y,w,h);})
        .def("drawROI", [](ofxCvShortImage &m, float x, float y){ return m.drawROI(x,y);})
        .def("drawROI", [](ofxCvShortImage &m, float x, float y, float w, float h){return m.drawROI(x,y,w,h);})
        .def("setAnchorPercent", [](ofxCvShortImage &m, float xPct, float yPct){ return m.setAnchorPercent(xPct,yPct);})
        .def("setAnchorPoint", [](ofxCvShortImage &m, float x, float y){ return m.setAnchorPoint(x,y);})
        .def("resetAnchor", [](ofxCvShortImage &m){ return m.resetAnchor();})
        .def("erode",           [](ofxCvShortImage &m){return m.erode();})
        .def("dilate",          [](ofxCvShortImage &m){return m.dilate();})
        .def("blur",            [](ofxCvShortImage &m, int value){return m.blur(value);})
        .def("blurGaussian",    [](ofxCvShortImage &m, int value){return m.blurGaussian(value);})
        .def("invert",          [](ofxCvShortImage &m){return m.invert();})
        .def("mirror",          [](ofxCvShortImage &m, bool bFlipVertically, bool bFlipHorizontally){return m.mirror(bFlipVertically, bFlipHorizontally);})
        .def("translate",       [](ofxCvShortImage &m, float x, float y){return m.translate(x, y);})
        .def("rotate",          [](ofxCvShortImage &m, float angle, float centerX, float centerY ){return m.rotate(angle, centerX, centerY);})
        .def("scale",           [](ofxCvShortImage &m, float scaleX, float sclaeY ){return m.scale( scaleX, sclaeY );})
        .def("transform",       [](ofxCvShortImage &m, float angle, float centerX, float centerY,float scaleX, float scaleY, float moveX, float moveY){return m.transform( angle, centerX, centerY, scaleX, scaleY, moveX, moveY);})
        .def("undistort",       [](ofxCvShortImage &m, float radialDistX, float radialDistY,float tangentDistX, float tangentDistY,float focalX, float focalY,float centerX, float centerY){return m.undistort( radialDistX, radialDistY, tangentDistX, tangentDistY, focalX, focalY, centerX, centerY);})
        .def("remap",           [](ofxCvShortImage &m, IplImage* mapX, IplImage* mapY){return m.remap( mapX, mapY);})
        .def("warpPerspective", [](ofxCvShortImage &m, ofPoint& A, ofPoint& B, ofPoint& C, ofPoint& D){return m.warpPerspective(A, B, C, D);})
        .def("countNonZeroInRegion", [](ofxCvShortImage &m, int x, int y, int w, int h){ return m.countNonZeroInRegion( x, y, w, h);})
        // .def("warpIntoMe", [](ofxCvShortImage &m, ofxCvShortImage& mom, ofPoint src[4], ofPoint dst[4]){ return m.warpIntoMe(mom, src, dst);})
        // from ofxCvShortImage
        .def("clear", &ofxCvShortImage::clear)
        .def("flagImageChanged", &ofxCvShortImage::flagImageChanged)
        .def("set", &ofxCvShortImage::set)
        .def("setFromPixels", &ofxCvShortImage::setFromPixels)
        .def("setRoiFromPixels", &ofxCvShortImage::setRoiFromPixels)
        .def("__isub__", [](ofxCvShortImage &m, float val){ return m-=val;}, py::is_operator())
        .def("__iadd__", [](ofxCvShortImage &m, float val){ return m+=val;}, py::is_operator())
        .def("__isub__", [](ofxCvShortImage &m, ofxCvShortImage& mom){ return m-=mom;}, py::is_operator())
        .def("__iadd__", [](ofxCvShortImage &m, ofxCvShortImage& mom){ return m+=mom;}, py::is_operator())
        .def("addWeighted",          &ofxCvShortImage::addWeighted)
        .def("contrastStretch",      &ofxCvShortImage::contrastStretch)
        .def("convertToRange",       &ofxCvShortImage::convertToRange)
        .def("resize",               &ofxCvShortImage::resize)
        .def("getShortPixelsRef",    &ofxCvShortImage::getShortPixelsRef)
        .def("getRoiShortPixelsRef", &ofxCvShortImage::getRoiShortPixelsRef)
        .def("assign", [](ofxCvShortImage &m, const ofxCvGrayscaleImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvShortImage &m, const ofxCvColorImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvShortImage &m, const ofxCvFloatImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvShortImage &m, const ofxCvShortImage &mom){ m=mom; return m;})
        .def("scaleIntoMe", [](ofxCvShortImage &m, ofxCvGrayscaleImage &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvShortImage &m, ofxCvShortImage     &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvShortImage &m, ofxCvFloatImage     &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvShortImage &m, ofxCvColorImage     &mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN);
        // .def("assign", [](ofxCvShortImage &m, const IplImage *mom){ m = mom;return m;})
        // .def("assign", [](ofxCvShortImage &m, unsigned char* _pixels){ m = _pixels;return m;}, py::keep_alive<1,2>());

    py::class_<ofxCvFloatImage>(m, "ofxCvFloatImage")
        .def(py::init<>())
        .def(py::init<const ofxCvFloatImage&>())
        // from Base class: ofxCvImage
        .def("allocate",            [](ofxCvFloatImage &m,int w, int h){ return m.allocate(w, h);} )
        .def("getWidth",            [](ofxCvFloatImage &m){return m.getWidth();}  )
        .def("getHeight",           [](ofxCvFloatImage &m){return m.getHeight();} )
        .def("setUseTexture",       [](ofxCvFloatImage &m, bool bUse){return m.setUseTexture(bUse);} )
        .def("getTextureReference", [](const ofxCvFloatImage &m){return m.getTextureReference();} )
        .def("setROI", [](ofxCvFloatImage &m, int x, int y, int w, int h){return m.setROI(x,y,w,h);} )
        .def("setROI", [](ofxCvFloatImage &m, const ofRectangle &rect){return m.setROI(rect);} )
        .def("getROI", [](ofxCvFloatImage &m){return m.getROI();} )
        .def("resetROI", [](ofxCvFloatImage &m){return m.resetROI();} )
        .def("getIntersectionROI",[](ofxCvFloatImage &m, ofRectangle& rec1, ofRectangle& rec2){return m.getIntersectionROI(rec1, rec2);})
        .def("__isub__", [](ofxCvFloatImage &m, float val){ return m-=val;}, py::is_operator())
        .def("__iadd__", [](ofxCvFloatImage &m, float val){ return m+=val;}, py::is_operator())
        .def("__isub__", [](ofxCvFloatImage &m, ofxCvFloatImage &mom){ return m-=mom;}, py::is_operator())
        .def("__iadd__", [](ofxCvFloatImage &m, ofxCvFloatImage &mom){ return m+=mom;}, py::is_operator())
        .def("draw", [](ofxCvFloatImage &m, float x, float y){ return m.draw(x,y);})
        .def("draw", [](ofxCvFloatImage &m, float x, float y, float w, float h){ return m.draw(x,y,w,h);})
        .def("drawROI", [](ofxCvFloatImage &m, float x, float y){ return m.drawROI(x,y);})
        .def("drawROI", [](ofxCvFloatImage &m, float x, float y, float w, float h){ return m.drawROI(x,y,w,h);})
        .def("setAnchorPercent", [](ofxCvFloatImage &m, float xPct, float yPct){ return m.setAnchorPercent(xPct,yPct);})
        .def("setAnchorPoint", [](ofxCvFloatImage &m, float x, float y){ return m.setAnchorPoint(x,y);})
        .def("resetAnchor", [](ofxCvFloatImage &m){ return m.resetAnchor();})
        .def("erode",        [](ofxCvFloatImage &m){ return m.erode();} )
        .def("dilate",       [](ofxCvFloatImage &m){ return m.dilate();} )
        .def("blur",         [](ofxCvFloatImage &m, int value){ return m.blur(value);}, "value"_a=3)
        .def("blurGaussian", [](ofxCvFloatImage &m, int value){ return m.blurGaussian(value);}, "value"_a=3)
        .def("invert",       [](ofxCvFloatImage &m){ return m.invert();})
        .def("mirror",       [](ofxCvFloatImage &m, bool bFlipVertically, bool bFlipHorizontally ){ return m.mirror(bFlipVertically, bFlipHorizontally);})
        .def("translate",    [](ofxCvFloatImage &m, float x, float y){ return m.translate(x, y);} )
        .def("rotate",       [](ofxCvFloatImage &m, float angle, float centerX, float centerY){ return m.rotate( angle, centerX, centerY );} )
        .def("scale",        [](ofxCvFloatImage &m, float scaleX, float scaleY){ return m.scale(scaleX, scaleY);} )
        .def("transform", [](ofxCvFloatImage &m, float angle, float centerX, float centerY, float scaleX, float scaleY, float moveX, float moveY){ return m.transform( angle, centerX, centerY, scaleX, scaleY, moveX, moveY);} )
        .def("undistort", [](ofxCvFloatImage &m, float radialDistX, float radialDistY, float tangentDistX, float tangentDistY,float focalX, float focalY,float centerX, float centerY) { return m.undistort( radialDistX, radialDistY, tangentDistX, tangentDistY, focalX, focalY, centerX, centerY);} )
        .def("remap", [](ofxCvFloatImage &m, IplImage* mapX, IplImage* mapY){return m.remap(mapX, mapY);} )
        .def("warpPerspective", [](ofxCvFloatImage &m, ofPoint& A, ofPoint& B, ofPoint& C, ofPoint& D){return m.warpPerspective(A, B, C, D);} )
        .def("countNonZeroInRegion", [](ofxCvFloatImage &m, int x, int y, int w, int h){return m.countNonZeroInRegion(x,y,w,h);})
        // .def("warpIntoMe", [](ofxCvFloatImage &m, ofxCvFloatImage& mom, ofPoint src[4], ofPoint dst[4]){ return m.warpIntoMe(mom, src, dst);})
        // from ofxCvFloatImage
        .def("clear", &ofxCvFloatImage::clear)
        .def("flagImageChanged", &ofxCvFloatImage::flagImageChanged)
        .def("setNativeScale", &ofxCvFloatImage::setNativeScale)
        .def("getNativeScaleMin", &ofxCvFloatImage::getNativeScaleMin)
        .def("getNativeScaleMax", &ofxCvFloatImage::getNativeScaleMax)
        .def("__imul__",     [](ofxCvFloatImage &m, float scalar){ return m *= scalar;}, py::is_operator())
        .def("__imul__",     [](ofxCvFloatImage &m, ofxCvFloatImage &mom){ return m *= mom;}, py::is_operator())
        .def("__iand__",     [](ofxCvFloatImage &m, ofxCvFloatImage &mom){ return m &= mom;}, py::is_operator())
        .def("__itruediv__", [](ofxCvFloatImage &m, float scalar){ return m /= scalar;}, py::is_operator())
        .def("setFromPixels", (void (ofxCvFloatImage::*)(const unsigned char*, int, int)) &ofxCvFloatImage::setFromPixels)
        .def("setFromPixels", (void (ofxCvFloatImage::*)(float*, int, int)) &ofxCvFloatImage::setFromPixels)
        .def("setRoiFromPixels", (void (ofxCvFloatImage::*)(const unsigned char*, int, int)) &ofxCvFloatImage::setRoiFromPixels)
        .def("setRoiFromPixels", (void (ofxCvFloatImage::*)(float*, int, int)) &ofxCvFloatImage::setRoiFromPixels)
        .def("assign", [](ofxCvFloatImage &m, const ofxCvGrayscaleImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvFloatImage &m, const ofxCvColorImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvFloatImage &m, const ofxCvFloatImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvFloatImage &m, const ofxCvShortImage &mom){ m=mom; return m;})
        // .def("assign", [](ofxCvFloatImage &m, const IplImage *mom){ m = mom;return m;})
        // .def("assign", [](ofxCvFloatImage &m, unsigned char* _pixels){ m = _pixels;return m;}, py::keep_alive<1,2>())
        .def("assign", [] (ofxCvFloatImage &m, py::array_t<float> numpy2DArray) { 
                auto buffinfo =  numpy2DArray.request();
                int width = m.getWidth();
                int height = m.getHeight();
                if (buffinfo.ndim != 2) {
                    throw std::runtime_error("numpy arg Dimensions must be 2");
                }
                if (width == 0 || height == 0) {
                    ofLogError("ofxCvFloatImage") << "Need call allocate(w,h) first";
                }
                if (width != buffinfo.shape[1] || height!= buffinfo.shape[0]) {
                    ofLogError("ofxCvFloatImage") << "numpy arg Dimensions does not match ofxCvFloatImage Dimensions";
                }
                if (width == buffinfo.shape[1] && height == buffinfo.shape[0]) {
                    // ofLogNotice("ofxCvFloatImage")<<"shape = "<<buffinfo.shape[0] <<" "<< buffinfo.shape[1]; //行数 列数
                    // ofLogNotice("ofxCvFloatImage")<<"strides = "<<buffinfo.strides[0] <<" "<< buffinfo.strides[1];// 每行占几个字节，一个元素占几个字节
                    float * pdata = (float*)buffinfo.ptr;
                    m = pdata;
                }
                return m;
            }, py::keep_alive<1,2>())
        .def("addWeighted",          &ofxCvFloatImage::addWeighted)
        .def("getPixelsAsFloats",    &ofxCvFloatImage::getPixelsAsFloats)
        .def("getFloatPixelsRef",    &ofxCvFloatImage::getFloatPixelsRef)
        .def("getRoiPixelsAsFloats", &ofxCvFloatImage::getRoiPixelsAsFloats)
        .def("getRoiFloatPixelsRef", &ofxCvFloatImage::getRoiFloatPixelsRef)
        .def("contrastStretch",      &ofxCvFloatImage::contrastStretch)
        .def("convertToRange",       &ofxCvFloatImage::convertToRange)
        .def("resize",               &ofxCvFloatImage::resize)
        .def("scaleIntoMe", [](ofxCvFloatImage &m, ofxCvGrayscaleImage& mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvFloatImage &m, ofxCvShortImage&     mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvFloatImage &m, ofxCvFloatImage&     mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvFloatImage &m, ofxCvColorImage&     mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN);

    py::class_<ofxCvColorImage>(m, "ofxCvColorImage")
        .def(py::init<>())
        .def(py::init<const ofxCvColorImage&>())
        // from Base class: ofxCvImage
        .def("allocate", [](ofxCvColorImage &m,int w, int h){ return m.allocate(w, h);} )
        .def("getWidth", [](ofxCvColorImage &m){ return m.getWidth();} )
        .def("getHeight", [](ofxCvColorImage &m){ return m.getHeight();} )
        .def("setUseTexture", [](ofxCvColorImage &m, bool bUse){ return m.setUseTexture( bUse );} )
        .def("getTextureReference", [](ofxCvColorImage &m){ return m.getTextureReference();} )
        .def("setROI", [](ofxCvColorImage &m, int x, int y, int w, int h){return m.setROI(x,y,w,h);} )
        .def("setROI", [](ofxCvColorImage &m, const ofRectangle &rect){return m.setROI(rect);} )
        .def("getROI", [](ofxCvColorImage &m){return m.getROI();} )
        .def("resetROI", [](ofxCvColorImage &m){return m.resetROI();} )
        .def("getIntersectionROI",[](ofxCvColorImage &m, ofRectangle& rec1, ofRectangle& rec2){return m.getIntersectionROI(rec1, rec2);})
        .def("draw", [](ofxCvColorImage &m, float x, float y){ return m.draw(x,y);})
        .def("draw", [](ofxCvColorImage &m, float x, float y, float w, float h){ return m.draw(x,y,w,h);})
        .def("drawROI", [](ofxCvColorImage &m, float x, float y){ return m.drawROI(x,y);})
        .def("drawROI", [](ofxCvColorImage &m, float x, float y, float w, float h){ return m.drawROI(x,y,w,h);})
        .def("setAnchorPercent", [](ofxCvColorImage &m, float xPct, float yPct){ return m.setAnchorPercent(xPct,yPct);})
        .def("setAnchorPoint", [](ofxCvColorImage &m, float x, float y){ return m.setAnchorPoint(x,y);})
        .def("resetAnchor", [](ofxCvColorImage &m){ return m.resetAnchor();})
        .def("erode",        [](ofxCvColorImage &m){ return m.erode();} )
        .def("dilate",       [](ofxCvColorImage &m){ return m.dilate();} )
        .def("blur",         [](ofxCvColorImage &m, int value){ return m.blur(value);}, "value"_a=3)
        .def("blurGaussian", [](ofxCvColorImage &m, int value){ return m.blurGaussian(value);}, "value"_a=3)
        .def("invert",       [](ofxCvColorImage &m){ return m.invert();})
        .def("mirror",       [](ofxCvColorImage &m, bool bFlipVertically, bool bFlipHorizontally ){ return m.mirror(bFlipVertically, bFlipHorizontally);})
        .def("translate",    [](ofxCvColorImage &m, float x, float y){ return m.translate(x, y);} )
        .def("rotate",       [](ofxCvColorImage &m, float angle, float centerX, float centerY){ return m.rotate( angle, centerX, centerY );} )
        .def("scale",        [](ofxCvColorImage &m, float scaleX, float scaleY){ return m.scale(scaleX, scaleY);} )
        .def("transform", [](ofxCvColorImage &m, float angle, float centerX, float centerY, float scaleX, float scaleY, float moveX, float moveY){ return m.transform( angle, centerX, centerY, scaleX, scaleY, moveX, moveY);} )
        .def("undistort", [](ofxCvColorImage &m, float radialDistX, float radialDistY, float tangentDistX, float tangentDistY,float focalX, float focalY,float centerX, float centerY) { return m.undistort( radialDistX, radialDistY, tangentDistX, tangentDistY, focalX, focalY, centerX, centerY);} )
        .def("remap", [](ofxCvColorImage &m, IplImage* mapX, IplImage* mapY){return m.remap(mapX, mapY);} )
        .def("warpPerspective", [](ofxCvColorImage &m, ofPoint& A, ofPoint& B, ofPoint& C, ofPoint& D){return m.warpPerspective(A, B, C, D);} )
        .def("countNonZeroInRegion", [](ofxCvColorImage &m, int x, int y, int w, int h){return m.countNonZeroInRegion(x,y,w,h);})
        // .def("warpIntoMe", [](ofxCvColorImage &m, ofxCvFloatImage& mom, ofPoint src[4], ofPoint dst[4]){ return m.warpIntoMe(mom, src, dst);})
        // from ofxCvColorImage
        .def("clear", &ofxCvColorImage::clear)
        .def("set", (void (ofxCvColorImage::*)(float)) &ofxCvColorImage::set)
        .def("set", (void (ofxCvColorImage::*)(int, int, int)) &ofxCvColorImage::set)
        .def("__isub__", [](ofxCvColorImage &m, float value){ m -= value; return m;}, py::is_operator())
        .def("__iadd__", [](ofxCvColorImage &m, float value){ m += value; return m;}, py::is_operator())

        .def("__isub__", [](ofxCvColorImage &m, ofxCvGrayscaleImage &mom){ m -= mom; return m;}, py::is_operator())
        .def("__iadd__", [](ofxCvColorImage &m, ofxCvGrayscaleImage &mom){ m += mom; return m;}, py::is_operator())
        .def("__imul__", [](ofxCvColorImage &m, ofxCvGrayscaleImage &mom){ m *= mom; return m;}, py::is_operator())
        .def("__iand__", [](ofxCvColorImage &m, ofxCvGrayscaleImage &mom){ m &= mom; return m;}, py::is_operator())

        .def("__isub__", [](ofxCvColorImage &m, ofxCvShortImage &mom){ m -= mom; return m;}, py::is_operator())
        .def("__iadd__", [](ofxCvColorImage &m, ofxCvShortImage &mom){ m += mom; return m;}, py::is_operator())
        .def("__imul__", [](ofxCvColorImage &m, ofxCvShortImage &mom){ m *= mom; return m;}, py::is_operator())
        .def("__iand__", [](ofxCvColorImage &m, ofxCvShortImage &mom){ m &= mom; return m;}, py::is_operator())

        .def("__isub__", [](ofxCvColorImage &m, ofxCvFloatImage &mom){ m -= mom; return m;}, py::is_operator())
        .def("__iadd__", [](ofxCvColorImage &m, ofxCvFloatImage &mom){ m += mom; return m;}, py::is_operator())
        .def("__imul__", [](ofxCvColorImage &m, ofxCvFloatImage &mom){ m *= mom; return m;}, py::is_operator())
        .def("__iand__", [](ofxCvColorImage &m, ofxCvFloatImage &mom){ m &= mom; return m;}, py::is_operator())

        .def("__isub__", [](ofxCvColorImage &m, ofxCvColorImage &mom){ m -= mom; return m;}, py::is_operator())
        .def("__iadd__", [](ofxCvColorImage &m, ofxCvColorImage &mom){ m += mom; return m;}, py::is_operator())
        .def("__imul__", [](ofxCvColorImage &m, ofxCvColorImage &mom){ m *= mom; return m;}, py::is_operator())
        .def("__iand__", [](ofxCvColorImage &m, ofxCvColorImage &mom){ m &= mom; return m;}, py::is_operator())

        .def("assign", [](ofxCvColorImage &m, const ofxCvGrayscaleImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvColorImage &m, const ofxCvColorImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvColorImage &m, const ofxCvFloatImage &mom){ m=mom; return m;})
        .def("assign", [](ofxCvColorImage &m, const ofxCvShortImage &mom){ m=mom; return m;})
        // .def("assign", [](ofxCvColorImage &m, const IplImage* mom){ m=mom; return m;})
        .def("assign", [](ofxCvColorImage &m, const ofPixels & _pixels){ m=_pixels; return m;})
        .def("convertToGrayscalePlanarImages", &ofxCvColorImage::convertToGrayscalePlanarImages)
        .def("convertToGrayscalePlanarImage", &ofxCvColorImage::convertToGrayscalePlanarImage)
        .def("contrastStretch", &ofxCvColorImage::contrastStretch)
        .def("convertToRange", &ofxCvColorImage::convertToRange)
        .def("resize", &ofxCvColorImage::resize)
        .def("convertRgbToHsv", &ofxCvColorImage::convertRgbToHsv)
        .def("convertHsvToRgb", &ofxCvColorImage::convertHsvToRgb)
        .def("scaleIntoMe", [](ofxCvColorImage &m, ofxCvGrayscaleImage& mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvColorImage &m, ofxCvShortImage&     mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvColorImage &m, ofxCvFloatImage&     mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN)
        .def("scaleIntoMe", [](ofxCvColorImage &m, ofxCvColorImage&     mom, int interpolationMethod){ return m.scaleIntoMe(mom, interpolationMethod);}, "mom"_a, "interpolationMethod"_a=SubPixelInterpolationMethods::CV_INTER_NN);

    py::class_<ofxCvHaarFinder>(m, "ofxCvHaarFinder")
        .def(py::init<>());
    py::class_<ofxCvContourFinder>(m, "ofxCvContourFinder")
        .def(py::init<>());
}