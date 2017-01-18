#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;

void pybind_video(py::module &m) {
    using namespace py::literals;

    py::class_<ofVideoGrabber>(m, "ofVideoGrabber", "捕捉实时摄像头画面")
        .def(py::init<>())
        .def("listDevices", &ofVideoGrabber::listDevices)
        .def("isFrameNew",  &ofVideoGrabber::isFrameNew)
        .def("update",      &ofVideoGrabber::update)
        .def("close",       &ofVideoGrabber::close)
        .def("setup", (bool (ofVideoGrabber::*)(int, int)) &ofVideoGrabber::setup)
        .def("setup", (bool (ofVideoGrabber::*)(int, int, bool)) &ofVideoGrabber::setup)
        .def("setPixelFormat",      &ofVideoGrabber::setPixelFormat)
        .def("getPixelFormat",      &ofVideoGrabber::getPixelFormat)
        .def("videoSettings",       &ofVideoGrabber::videoSettings)
        .def("getPixels",  (ofPixels&  (ofVideoGrabber::*)()) &ofVideoGrabber::getPixels)
        .def("getTexture", (ofTexture& (ofVideoGrabber::*)()) &ofVideoGrabber::getTexture)
        .def("getTexturePlanes", (vector<ofTexture>& (ofVideoGrabber::*)()) &ofVideoGrabber::getTexturePlanes)
        .def("setVerbose",          &ofVideoGrabber::setVerbose)
        .def("setDeviceID",         &ofVideoGrabber::setDeviceID)
        .def("setDesiredFrameRate", &ofVideoGrabber::setDesiredFrameRate)
        .def("setUseTexture",       &ofVideoGrabber::setUseTexture)
        .def("isUsingTexture",      &ofVideoGrabber::isUsingTexture)
        .def("draw", (void (ofVideoGrabber::*)(float, float, float,float) const) &ofVideoGrabber::draw)
        .def("draw", (void (ofVideoGrabber::*)(float, float) const) &ofVideoGrabber::draw)
        .def("bind",             &ofVideoGrabber::bind)
        .def("unbind",           &ofVideoGrabber::unbind)
        .def("setAnchorPercent", &ofVideoGrabber::setAnchorPercent)
        .def("setAnchorPoint",   &ofVideoGrabber::setAnchorPoint)
        .def("resetAnchor",      &ofVideoGrabber::resetAnchor)
        .def("getHeight",        &ofVideoGrabber::getHeight)
        .def("getWidth",         &ofVideoGrabber::getWidth)
        .def("isInitialized",    &ofVideoGrabber::isInitialized);
        // .def("setGrabber", &ofVideoGrabber::setGrabber)
        // .def("getGrabber", (shared_ptr<ofBaseVideoGrabber> (ofVideoGrabber::*)()) &ofVideoGrabber::getGrabber);

    py::class_<ofVideoPlayer>(m, "ofVideoPlayer", "播放视频文件")
        .def(py::init<>())
        .def("load",           &ofVideoPlayer::load)
        .def("loadAsync",      &ofVideoPlayer::loadAsync)
        .def("getMoviePath",   &ofVideoPlayer::getMoviePath)
        .def("setPixelFormat", &ofVideoPlayer::setPixelFormat)
        .def("getPixelFormat", &ofVideoPlayer::getPixelFormat)
        .def("closeMovie",     &ofVideoPlayer::closeMovie)
        .def("close",          &ofVideoPlayer::close)
        .def("update",         &ofVideoPlayer::update)
        .def("play",           &ofVideoPlayer::play)
        .def("stop",           &ofVideoPlayer::stop)
        .def("isFrameNew",     &ofVideoPlayer::isFrameNew)
        .def("getPixels", (ofPixels& (ofVideoPlayer::*)()) &ofVideoPlayer::getPixels)
        .def("getPosition",    &ofVideoPlayer::getPosition)
        .def("getSpeed",       &ofVideoPlayer::getSpeed)
        .def("getDuration",    &ofVideoPlayer::getDuration)
        .def("getIsMovieDone", &ofVideoPlayer::getIsMovieDone)
        .def("setPosition",    &ofVideoPlayer::setPosition)
        .def("setVolume",      &ofVideoPlayer::setVolume)
        .def("setLoopState",   &ofVideoPlayer::setLoopState)
        .def("getLoopState",   &ofVideoPlayer::getLoopState)
        .def("setSpeed",       &ofVideoPlayer::setSpeed)
        .def("setFrame",       &ofVideoPlayer::setFrame)
        .def("setUseTexture",  &ofVideoPlayer::setUseTexture)
        .def("isUsingTexture", &ofVideoPlayer::isUsingTexture)
        .def("getTexture", (ofTexture& (ofVideoPlayer::*)()) &ofVideoPlayer::getTexture)
        .def("getTexturePlanes", (vector<ofTexture>& (ofVideoPlayer::*)()) &ofVideoPlayer::getTexturePlanes)
        .def("draw", (void (ofVideoPlayer::*)(float, float, float,float) const) &ofVideoPlayer::draw)
        .def("draw", (void (ofVideoPlayer::*)(float, float) const) &ofVideoPlayer::draw)
        .def("bind",              &ofVideoPlayer::bind)
        .def("unbind",            &ofVideoPlayer::unbind)
        .def("setAnchorPercent",  &ofVideoPlayer::setAnchorPercent)
        .def("setAnchorPoint",    &ofVideoPlayer::setAnchorPoint)
        .def("resetAnchor",       &ofVideoPlayer::resetAnchor)
        .def("setPaused",         &ofVideoPlayer::setPaused)
        .def("getCurrentFrame",   &ofVideoPlayer::getCurrentFrame)
        .def("getTotalNumFrames", &ofVideoPlayer::getTotalNumFrames)
        .def("firstFrame",        &ofVideoPlayer::firstFrame)
        .def("nextFrame",         &ofVideoPlayer::nextFrame)
        .def("previousFrame",     &ofVideoPlayer::previousFrame)
        .def("getHeight",         &ofVideoPlayer::getHeight)
        .def("getWidth",          &ofVideoPlayer::getWidth)
        .def("isPaused",          &ofVideoPlayer::isPaused)
        .def("isLoaded",          &ofVideoPlayer::isLoaded)
        .def("isPlaying",         &ofVideoPlayer::isPlaying)
        .def("isInitialized",     &ofVideoPlayer::isInitialized);
        // .def("setPlayer", &ofVideoPlayer::setPlayer)
        // .def("getPlayer", (shared_ptr<ofBaseVideoPlayer> (ofVideoPlayer::*)()) &ofVideoPlayer::getPlayer);


}