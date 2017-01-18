#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <locale>

// #include "Python.h"
namespace py = pybind11;

// wstring StringToWString(const string &str) {
//     std::wstring wstr(str.length(),L' ');
//     copy(str.begin(), str.end(), wstr.begin());
//     return wstr;
// }
// //只拷贝低字节至string中
// string WStringToString(const wstring &wstr) {
//     std::string str(wstr.length(), ' ');
//     copy(wstr.begin(), wstr.end(), str.begin());
//     return str;
// }

// ============ Class =============
// ofBuffer
// ofBuffer::Line 
// ofBuffer::Lines
// ofDirectory
// ofFilePath
// ofFpsCounter
// ofLog 
// ofThread
// ofTimer
// ofFile 
// ofHttpRequest 
// ofThreadChannel
// ofUTF8Iterator
// ofFileDialogResult
// ofHttpResponse
// ofURLFileLoader
// ofXml

// ==========  Global Functions ==========
// ofSystemUtils ofUtils ofFileUtils

// bool         ofContains(const vector<T> &values, const T &target)
// size_t       ofFind    (const vector<T> &values, const T &target) 
// const char * ofFromString(const string &value) 
//            T ofFromString(const string &value) 
// void    ofRandomize(vector<T> &values) 
// void    ofRemove(vector<T> &values, BoolFunction shouldErase)
// void    ofSort(vector<T> &values)
// void    ofSort(vector<T> &values, BoolFunction compare)
// string         ofJoinString (const vector<string>& stringElements, const string& delimiter)
// vector<string> ofSplitString(const string& source, const string& delimiter, bool ignoreEmpty = false, bool trim = false)

// string  ofToBinary(const T &value) ok
// string  ofToHex(const T &value)    ok

// string  ofToString(const T &value)
// string  ofToString(const T &value, int precision)
// string  ofToString(const vector<T> &values)
// string  ofToString(const T &value, int width, char fill)
// string  ofToString(const T &value, int precision, int width, char fill)

// string  ofVAArgsToString(const char *format, ...)         //变长参数， overload 函数
// string  ofVAArgsToString(const char *format, va_list args) //变长参数， overload 函数 
    // m.def("ofVAArgsToString", (string (*)(const char *, ...)) &ofVAArgsToString);
    // m.def("ofVAArgsToString", (string (*)(const char *, va_list)) &ofVAArgsToString);


void pybind_utils(py::module &m) {
    using namespace py::literals;

    py::class_<ofFpsCounter>(m, "ofFpsCounter")
        .def(py::init<>())
        .def(py::init<double>())
        .def("getFps", &ofFpsCounter::getFps)
        .def("getLastFrameNanos", &ofFpsCounter::getLastFrameNanos)
        .def("getLastFrameSecs", &ofFpsCounter::getLastFrameSecs)
        .def("getNumFrames", &ofFpsCounter::getNumFrames)
        .def("newFrame", &ofFpsCounter::newFrame)
        .def("update", (void (ofFpsCounter::*)()) &ofFpsCounter::update)
        .def_property_readonly("fps", &ofFpsCounter::getFps);

    // Functions I wrapped :
    // m.def("ofToBinary", (string (*)(float)) &pyofToBinary);

    // Functionsopen from openFrameworks:
    m.def("ofHexToChar",   &ofHexToChar);
    m.def("ofHexToFloat",  &ofHexToFloat);
    m.def("ofHexToInt",    &ofHexToInt);
    m.def("ofHexToString", &ofHexToString);
    m.def("ofIsStringInString",        &ofIsStringInString);
    m.def("ofLaunchBrowser",           &ofLaunchBrowser);
    m.def("ofResetElapsedTimeCounter", &ofResetElapsedTimeCounter);
    m.def("ofRestoreWorkingDirectoryToDefault", &ofRestoreWorkingDirectoryToDefault);
    m.def("ofSaveFrame",           &ofSaveFrame);
    m.def("ofSaveScreen",          &ofSaveScreen);
    m.def("ofSaveViewport",        &ofSaveViewport);
    m.def("ofSetDataPathRoot",     &ofSetDataPathRoot);
    m.def("ofSleepMillis",         &ofSleepMillis);
    m.def("ofStringReplace",       &ofStringReplace);
    m.def("ofStringTimesInString", &ofStringTimesInString);
    m.def("ofSystem",              &ofSystem);
    m.def("ofToBinary", (string (*)(const string &)) &ofToBinary);
    m.def("ofToBinary", (string (*)(const char *))   &ofToBinary);
    m.def("ofToBool", &ofToBool);
    m.def("ofToChar", &ofToChar);
    m.def("ofToDataPath", &ofToDataPath);
    m.def("ofToDouble", &ofToDouble);
    m.def("ofToFloat", &ofToFloat);
    m.def("ofToHex", (string (*)(const string &)) &ofToHex);
    m.def("ofToHex", (string (*)(const char *)) &ofToHex);
    m.def("ofToInt", &ofToInt);
    m.def("ofToInt64", &ofToInt64);
    m.def("ofToLower", &ofToLower);
    m.def("ofToUpper", &ofToLower);
    m.def("ofTrim", &ofTrim);
    m.def("ofTrimBack", &ofTrimBack);
    m.def("ofTrimFront", &ofTrimFront);
    m.def("ofSystemAlertDialog", &ofSystemAlertDialog);
    m.def("ofSystemLoadDialog", &ofSystemLoadDialog);
    m.def("ofSystemSaveDialog", &ofSystemSaveDialog);
    m.def("ofSystemTextBoxDialog", &ofSystemTextBoxDialog);
    m.def("ofAppendUTF8",   &ofAppendUTF8);
    m.def("ofBinaryToChar", &ofBinaryToChar);
    m.def("ofBinaryToFloat", &ofBinaryToFloat);
    m.def("ofBinaryToInt", &ofBinaryToInt);
    m.def("ofBinaryToString", &ofBinaryToString);
    m.def("ofFromString", (string (*)(const string &)) &ofFromString);
    m.def("ofGetDay", &ofGetDay);
    m.def("ofGetElapsedTimeMicros", &ofGetElapsedTimeMicros);
    m.def("ofGetElapsedTimeMillis", &ofGetElapsedTimeMillis);
    m.def("ofGetElapsedTimef", &ofGetElapsedTimef);
    m.def("ofGetFrameNum", &ofGetFrameNum);
    m.def("ofGetHours", &ofGetHours);
    m.def("ofGetMinutes", &ofGetMinutes);
    m.def("ofGetMonth", &ofGetMonth);
    m.def("ofGetSeconds", &ofGetSeconds);
    m.def("ofGetSystemTimeMicros", &ofGetSystemTimeMicros);
    m.def("ofGetTargetPlatform",   &ofGetTargetPlatform);
    m.def("ofGetTimestampString", (string (*)())               &ofGetTimestampString);
    m.def("ofGetTimestampString", (string (*)(const string &)) &ofGetTimestampString);
    m.def("ofGetUnixTime", &ofGetUnixTime);
    m.def("ofGetVersionInfo", &ofGetVersionInfo);
    m.def("ofGetVersionMajor", &ofGetVersionMajor);
    m.def("ofGetVersionMinor", &ofGetVersionMinor);
    m.def("ofGetVersionPatch", &ofGetVersionPatch);
    m.def("ofGetVersionPreRelease", &ofGetVersionPreRelease);
    m.def("ofGetWeekday", &ofGetWeekday);
    m.def("ofGetYear", &ofGetYear);
    m.def("ofHexToChar", &ofHexToChar);
    m.def("ofHexToFloat", &ofHexToFloat);
    m.def("ofHexToInt", &ofHexToInt);
    m.def("ofHexToString", &ofHexToString);
    m.def("ofIsStringInString", &ofIsStringInString);
    m.def("ofJoinString", &ofJoinString);
    m.def("ofLaunchBrowser", &ofLaunchBrowser);
    m.def("ofResetElapsedTimeCounter", &ofResetElapsedTimeCounter);
    m.def("ofRestoreWorkingDirectoryToDefault", &ofRestoreWorkingDirectoryToDefault);
    m.def("ofSaveFrame", &ofSaveFrame, py::arg("bUseViewport")=false);
    m.def("ofToHex", [](const long &data){
        // ofToHex
        if (data>=0) {
            if (data<256) {
                return ofToHex<uint8_t>(data);
            }else if (data <= numeric_limits<uint16_t>::max()) {
                return ofToHex<uint16_t>(data);
            }else if (data <= numeric_limits<uint32_t>::max()) {
                return ofToHex<uint32_t>(data);
            }else {
                return ofToHex<uint64_t>(data);
            }
        } else {
            if (data >= -127) {
                return ofToHex<int8_t>(data);
            }else if (data >= numeric_limits<int16_t>::min()) {
                return ofToHex<int16_t>(data);
            }else if (data >= numeric_limits<int32_t>::min()) {
                return ofToHex<int32_t>(data);
            }else {
                return ofToHex<int64_t>(data);
            }
        }
    });
    m.def("ofToBinary", [](const long &data){
        if (data>=0) {
            if (data<256) {
                return ofToBinary<uint8_t>(data);
            }else if (data <= numeric_limits<uint16_t>::max()) {
                return ofToBinary<uint16_t>(data);
            }else if (data <= numeric_limits<uint32_t>::max()) {
                return ofToBinary<uint32_t>(data);
            }else {
                return ofToBinary<uint64_t>(data);
            }
        } else {
            if (data >= -127) {
                return ofToBinary<int8_t>(data);
            }else if (data >= numeric_limits<int16_t>::min()) {
                return ofToBinary<int16_t>(data);
            }else if (data >= numeric_limits<int32_t>::min()) {
                return ofToBinary<int32_t>(data);
            }else {
                return ofToBinary<int64_t>(data);
            }
        }
        // cout<< "data:" << data << endl;
        // cout<< "short" << numeric_limits<short>::min() << "------" <<numeric_limits<short>::max() << endl;
    });
    m.def("ofToBinary", [](const double &data){
        float d = float(data);
        if (abs(data-d)<=0.000001) {
            return ofToBinary<float>(d);
        } else {
            return ofToBinary<double>(data);
        }
        // cout<< "short" << numeric_limits<short>::min() << "------" <<numeric_limits<short>::max() << endl;
    });

    py::enum_<ofFillFlag>(m, "ofFillFlag")
		.value("OF_OUTLINE", ofFillFlag::OF_OUTLINE)
	    .value("OF_FILLED",  ofFillFlag::OF_FILLED)
	    .export_values();
	py::enum_<ofWindowMode>(m, "ofWindowMode")
        .value("OF_WINDOW",     ofWindowMode::OF_WINDOW)
        .value("OF_FULLSCREEN", ofWindowMode::OF_FULLSCREEN)
        .value("OF_GAME_MODE",  ofWindowMode::OF_GAME_MODE)
        .export_values();
    py::enum_<ofAspectRatioMode>(m, "ofAspectRatioMode")
        .value("OF_ASPECT_RATIO_IGNORE",             ofAspectRatioMode::OF_ASPECT_RATIO_IGNORE)
        .value("OF_ASPECT_RATIO_KEEP",               ofAspectRatioMode::OF_ASPECT_RATIO_KEEP)
        .value("OF_ASPECT_RATIO_KEEP_BY_EXPANDING",  ofAspectRatioMode::OF_ASPECT_RATIO_KEEP_BY_EXPANDING)
        .export_values();
    py::enum_<ofAlignVert>(m, "ofAlignVert")
        .value("OF_ALIGN_VERT_IGNORE",  ofAlignVert::OF_ALIGN_VERT_IGNORE)
        .value("OF_ALIGN_VERT_TOP",     ofAlignVert::OF_ALIGN_VERT_TOP)
        .value("OF_ALIGN_VERT_BOTTOM",  ofAlignVert::OF_ALIGN_VERT_BOTTOM)
        .value("OF_ALIGN_VERT_CENTER",  ofAlignVert::OF_ALIGN_VERT_CENTER)
        .export_values();
    py::enum_<ofAlignHorz>(m, "ofAlignHorz")
        .value("OF_ALIGN_HORZ_IGNORE", ofAlignHorz::OF_ALIGN_HORZ_IGNORE)
        .value("OF_ALIGN_HORZ_LEFT",   ofAlignHorz::OF_ALIGN_HORZ_LEFT)
        .value("OF_ALIGN_HORZ_RIGHT",  ofAlignHorz::OF_ALIGN_HORZ_RIGHT)
        .value("OF_ALIGN_HORZ_CENTER", ofAlignHorz::OF_ALIGN_HORZ_CENTER)
        .export_values();
    py::enum_<ofRectMode>(m, "ofRectMode")
	    .value("OF_RECTMODE_CENTER", ofRectMode::OF_RECTMODE_CENTER)
	    .value("OF_RECTMODE_CORNER", ofRectMode::OF_RECTMODE_CORNER)
        .export_values();
    py::enum_<ofScaleMode>(m, "ofScaleMode")
	    .value("OF_SCALEMODE_FIT",             ofScaleMode::OF_SCALEMODE_FIT)
	    .value("OF_SCALEMODE_FILL",            ofScaleMode::OF_SCALEMODE_FILL)
	    .value("OF_SCALEMODE_CENTER",          ofScaleMode::OF_SCALEMODE_CENTER)
	    .value("OF_SCALEMODE_STRETCH_TO_FILL", ofScaleMode::OF_SCALEMODE_STRETCH_TO_FILL)
        .export_values();
    py::enum_<ofImageType>(m, "ofImageType")
    	.value("OF_IMAGE_GRAYSCALE",             ofImageType::OF_IMAGE_GRAYSCALE)
	    .value("OF_IMAGE_COLOR",            ofImageType::OF_IMAGE_COLOR)
	    .value("OF_IMAGE_COLOR_ALPHA",          ofImageType::OF_IMAGE_COLOR_ALPHA)
	    .value("OF_IMAGE_UNDEFINED", ofImageType::OF_IMAGE_UNDEFINED)
        .export_values();
    py::enum_<ofBlendMode>(m, "ofBlendMode")
	    .value("OF_BLENDMODE_DISABLED" , ofBlendMode::OF_BLENDMODE_DISABLED)
	    .value("OF_BLENDMODE_ALPHA"    , ofBlendMode::OF_BLENDMODE_ALPHA)
	    .value("OF_BLENDMODE_ADD"      , ofBlendMode::OF_BLENDMODE_ADD)
	    .value("OF_BLENDMODE_SUBTRACT" , ofBlendMode::OF_BLENDMODE_SUBTRACT)
	    .value("OF_BLENDMODE_MULTIPLY" , ofBlendMode::OF_BLENDMODE_MULTIPLY)
	    .value("OF_BLENDMODE_SCREEN"   , ofBlendMode::OF_BLENDMODE_SCREEN)
        .export_values();
    py::enum_<ofOrientation>(m, "ofOrientation")
    	.value("OF_ORIENTATION_DEFAULT"  , ofOrientation::OF_ORIENTATION_DEFAULT)
    	.value("OF_ORIENTATION_180"      , ofOrientation::OF_ORIENTATION_180)
    	.value("OF_ORIENTATION_90_LEFT"  , ofOrientation::OF_ORIENTATION_90_LEFT)
    	.value("OF_ORIENTATION_90_RIGHT" , ofOrientation::OF_ORIENTATION_90_RIGHT)
    	.value("OF_ORIENTATION_UNKNOWN"  , ofOrientation::OF_ORIENTATION_UNKNOWN)
        .export_values();
    py::enum_<ofGradientMode>(m, "ofGradientMode")
        .value("OF_GRADIENT_LINEAR"   , ofGradientMode::OF_GRADIENT_LINEAR)
        .value("OF_GRADIENT_CIRCULAR" , ofGradientMode::OF_GRADIENT_CIRCULAR)
        .value("OF_GRADIENT_BAR"      , ofGradientMode::OF_GRADIENT_BAR)
        .export_values();
	py::enum_<ofPolyWindingMode>(m, "ofPolyWindingMode")
	    .value("OF_POLY_WINDING_ODD"         , ofPolyWindingMode::OF_POLY_WINDING_ODD)
	    .value("OF_POLY_WINDING_NONZERO"     , ofPolyWindingMode::OF_POLY_WINDING_NONZERO)
	    .value("OF_POLY_WINDING_POSITIVE"    , ofPolyWindingMode::OF_POLY_WINDING_POSITIVE)
	    .value("OF_POLY_WINDING_NEGATIVE"    , ofPolyWindingMode::OF_POLY_WINDING_NEGATIVE)
	    .value("OF_POLY_WINDING_ABS_GEQ_TWO" , ofPolyWindingMode::OF_POLY_WINDING_ABS_GEQ_TWO)
        .export_values();
	py::enum_<ofHandednessType>(m, "ofHandednessType")
        .value("OF_LEFT_HANDED"  , ofHandednessType::OF_LEFT_HANDED)
        .value("OF_RIGHT_HANDED" , ofHandednessType::OF_RIGHT_HANDED)
        .export_values();
	py::enum_<ofMatrixMode>(m, "ofMatrixMode")
        .value("OF_MATRIX_MODELVIEW"  , ofMatrixMode::OF_MATRIX_MODELVIEW)
        .value("OF_MATRIX_PROJECTION" , ofMatrixMode::OF_MATRIX_PROJECTION)
        .value("OF_MATRIX_TEXTURE"    , ofMatrixMode::OF_MATRIX_TEXTURE)
        .export_values();
    py::enum_<ofPixelFormat>(m, "ofPixelFormat")
        .value("OF_PIXELS_GRAY",        ofPixelFormat::OF_PIXELS_GRAY)
        .value("OF_PIXELS_GRAY_ALPHA",  ofPixelFormat::OF_PIXELS_GRAY_ALPHA)
        .value("OF_PIXELS_RGB",         ofPixelFormat::OF_PIXELS_RGB)
        .value("OF_PIXELS_BGR",         ofPixelFormat::OF_PIXELS_BGR)
        .value("OF_PIXELS_RGBA",        ofPixelFormat::OF_PIXELS_RGBA)
        .value("OF_PIXELS_BGRA",        ofPixelFormat::OF_PIXELS_BGRA)
        .value("OF_PIXELS_RGB565",      ofPixelFormat::OF_PIXELS_RGB565)
        .value("OF_PIXELS_NV12",        ofPixelFormat::OF_PIXELS_NV12)
        .value("OF_PIXELS_NV21",        ofPixelFormat::OF_PIXELS_NV21)
        .value("OF_PIXELS_YV12",        ofPixelFormat::OF_PIXELS_YV12)
        .value("OF_PIXELS_I420",        ofPixelFormat::OF_PIXELS_I420)
        .value("OF_PIXELS_YUY2",        ofPixelFormat::OF_PIXELS_YUY2)
        .value("OF_PIXELS_UYVY",        ofPixelFormat::OF_PIXELS_UYVY)
        .value("OF_PIXELS_Y",           ofPixelFormat::OF_PIXELS_Y)
        .value("OF_PIXELS_U",           ofPixelFormat::OF_PIXELS_U)
        .value("OF_PIXELS_V",           ofPixelFormat::OF_PIXELS_V)
        .value("OF_PIXELS_UV",          ofPixelFormat::OF_PIXELS_UV)
        .value("OF_PIXELS_VU",          ofPixelFormat::OF_PIXELS_VU)
        .value("OF_PIXELS_NUM_FORMATS", ofPixelFormat::OF_PIXELS_NUM_FORMATS)
        .value("OF_PIXELS_UNKNOWN",     ofPixelFormat::OF_PIXELS_UNKNOWN)
        .value("OF_PIXELS_NATIVE",      ofPixelFormat::OF_PIXELS_NATIVE)
        .export_values();
    py::enum_<ofDrawBitmapMode>(m, "ofDrawBitmapMode")
        .value("OF_BITMAPMODE_SIMPLE",          ofDrawBitmapMode::OF_BITMAPMODE_SIMPLE)
        .value("OF_BITMAPMODE_SCREEN",          ofDrawBitmapMode::OF_BITMAPMODE_SCREEN)
        .value("OF_BITMAPMODE_VIEWPORT",        ofDrawBitmapMode::OF_BITMAPMODE_VIEWPORT)
        .value("OF_BITMAPMODE_MODEL",           ofDrawBitmapMode::OF_BITMAPMODE_MODEL)
        .value("OF_BITMAPMODE_MODEL_BILLBOARD", ofDrawBitmapMode::OF_BITMAPMODE_MODEL_BILLBOARD)
        .export_values();
    py::enum_<ofTextEncoding>(m, "ofTextEncoding")
        .value("OF_ENCODING_UTF8"  ,       ofTextEncoding::OF_ENCODING_UTF8)
        .value("OF_ENCODING_ISO_8859_15" , ofTextEncoding::OF_ENCODING_ISO_8859_15)
        .export_values();

    py::class_<ofFile> fileobj(m, "ofFile");
    py::enum_<ofFile::Mode>(fileobj, "Mode")
        .value("Reference", ofFile::Mode::Reference)
        .value("ReadOnly", ofFile::Mode::ReadOnly)
        .value("WriteOnly", ofFile::Mode::WriteOnly)
        .value("ReadWrite", ofFile::Mode::ReadWrite)
        .value("Append", ofFile::Mode::Append);
    fileobj.def(py::init<>())
        .def(py::init<const std::filesystem::path &, ofFile::Mode, bool>(), "path"_a, "mode"_a=ofFile::Mode::ReadOnly, "binary"_a=true)
        .def(py::init<const ofFile &>())
        .def("open", &ofFile::open, "path"_a, "mode"_a=ofFile::Mode::ReadOnly, "binary"_a=false)
        .def("changeMode", &ofFile::changeMode, "mode"_a, "binary"_a=false)
        .def("close", &ofFile::close)
        .def("create", &ofFile::create)
        .def("exists", &ofFile::exists)
        .def("path", &ofFile::path)
        .def("getExtension", &ofFile::getExtension)
        .def("getFileName", &ofFile::getFileName)
        .def("getBaseName", &ofFile::getBaseName)
        .def("getEnclosingDirectory", &ofFile::getEnclosingDirectory)
        .def("getAbsolutePath", &ofFile::getAbsolutePath)
        .def("canRead", &ofFile::canRead)
        .def("canWrite", &ofFile::canWrite)
        .def("canExecute", &ofFile::canExecute)
        .def("isFile", &ofFile::isFile)
        .def("isLink", &ofFile::isLink)
        .def("isDirectory", &ofFile::isDirectory)
        .def("isDevice", &ofFile::isDevice)
        .def("isHidden", &ofFile::isHidden)
        .def("setWriteable", &ofFile::setWriteable, "writeable"_a=true)
        .def("setReadOnly", &ofFile::setReadOnly, "readable"_a=true)
        .def("setExecutable", &ofFile::setExecutable, "executable"_a=true)
        .def("copyTo", &ofFile::copyTo,     "path"_a, "bRelativeToData"_a=true, "overwrite"_a=false)
        .def("moveTo", &ofFile::moveTo,     "path"_a, "bRelativeToData"_a=true, "overwrite"_a=false)
        .def("renameTo", &ofFile::renameTo, "path"_a, "bRelativeToData"_a=true, "overwrite"_a=false)
        .def("remove", &ofFile::remove, "recursive"_a=false)
        .def("getSize", &ofFile::getSize)
        .def("readToBuffer", &ofFile::readToBuffer)
        .def("writeFromBuffer", &ofFile::writeFromBuffer)
        .def("getFileBuffer", &ofFile::getFileBuffer)
        .def(py::self == ofFile())
        .def(py::self != ofFile())
        .def(py::self < ofFile())
        .def(py::self <= ofFile())
        .def(py::self > ofFile())
        .def(py::self >= ofFile())
        .def_static("copyFromTo",    &ofFile::copyFromTo, "pathSrc"_a, "pathDst"_a, "bRelativeToData"_a=true, "overwrite"_a=false)
        .def_static("moveFromTo",    &ofFile::moveFromTo, "pathSrc"_a, "pathDst"_a, "bRelativeToData"_a=true, "overwrite"_a=false)
        .def_static("doesFileExist", &ofFile::doesFileExist, "fPath"_a, "bRelativeToData"_a=true)
        .def_static("removeFile",    &ofFile::removeFile,    "path"_a,  "bRelativeToData"_a=true);

    py::class_<ofBuffer>(m, "ofBuffer")
        .def(py::init<>())
        .def(py::init<const char *, size_t>())
        .def(py::init<const string &>())
        .def("set", (void (ofBuffer::*)(const char *, size_t)) &ofBuffer::set)
        .def("set", (void (ofBuffer::*)(const string &)) &ofBuffer::set)
        .def("append", (void (ofBuffer::*)(const char *, size_t)) &ofBuffer::append)
        .def("append", (void (ofBuffer::*)(const string &)) &ofBuffer::append)
        .def("clear", &ofBuffer::clear)
        .def("allocate", &ofBuffer::allocate)
        .def("getText", &ofBuffer::getText)
        .def("size", &ofBuffer::size)
        .def("getData", (char* (ofBuffer::*)()) &ofBuffer::getData)
        .def("__str__", [](const ofBuffer &b){ return b.getText();});
        

    m.def("ofBufferFromFile", &ofBufferFromFile, "path"_a, "binary"_a=false);
    m.def("ofBufferToFile", &ofBufferToFile, "path"_a, "buffer"_a, "binary"_a=false);
}