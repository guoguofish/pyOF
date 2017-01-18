#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;

void pybind_sound(py::module &m) {
    using namespace py::literals;

    m.def("ofSoundStopAll",     &ofSoundStopAll);
    m.def("ofSoundShutdown",    &ofSoundShutdown);
    m.def("ofSoundSetVolume",   &ofSoundSetVolume);
    m.def("ofSoundUpdate",      &ofSoundUpdate);
    m.def("ofSoundGetSpectrum", &ofSoundGetSpectrum);
    // m.def("ofStereoVolumes",    &ofStereoVolumes);

    #ifdef TARGET_LINUX_ARM
    m.def("ofSoundShutdown", &ofSoundShutdown);
    #endif

    py::class_<ofSoundDevice>(m, "ofSoundDevice")
        .def(py::init<>())
        .def_readwrite("name", &ofSoundDevice::name)
        .def_readwrite("deviceID", &ofSoundDevice::deviceID)
        .def_readwrite("inputChannels", &ofSoundDevice::inputChannels)
        .def_readwrite("outputChannels", &ofSoundDevice::outputChannels)
        .def_readwrite("isDefaultInput", &ofSoundDevice::isDefaultInput)
        .def_readwrite("isDefaultOutput", &ofSoundDevice::isDefaultOutput)
        .def_readwrite("sampleRates", &ofSoundDevice::sampleRates);

    py::class_<ofSoundPlayer>(m, "ofSoundPlayer")
        .def(py::init<>())
        .def("load",          &ofSoundPlayer::load, "fileName"_a, "stream"_a=false)
        .def("unload",        &ofSoundPlayer::unload)
        .def("play",          &ofSoundPlayer::play)
        .def("stop",          &ofSoundPlayer::stop)
        .def("setVolume",     &ofSoundPlayer::setVolume)
        .def("setPan",        &ofSoundPlayer::setPan)
        .def("setSpeed",      &ofSoundPlayer::setSpeed)
        .def("setPaused",     &ofSoundPlayer::setPaused)
        .def("setLoop",       &ofSoundPlayer::setLoop)
        .def("setMultiPlay",  &ofSoundPlayer::setMultiPlay)
        .def("setPosition",   &ofSoundPlayer::setPosition)
        .def("getPosition",   &ofSoundPlayer::getPosition)
        .def("setPositionMS", &ofSoundPlayer::setPositionMS)
        .def("getPositionMS", &ofSoundPlayer::getPositionMS)
        .def("isPlaying",     &ofSoundPlayer::isPlaying)
        .def("getSpeed",      &ofSoundPlayer::getSpeed)
        .def("getPan",        &ofSoundPlayer::getPan)
        .def("getVolume",     &ofSoundPlayer::getVolume)
        .def("isLoaded",      &ofSoundPlayer::isLoaded);
        // .def("setPlayer", &ofSoundPlayer::setPlayer)
        // .def("getPlayer", &ofSoundPlayer::getPlayer)
        // .def_property("player", &ofSoundPlayer::getPlayer, &ofSoundPlayer::setPlayer)
    m.def("ofSoundStreamSetup", (void (*)(int, int, int, int, int)) &ofSoundStreamSetup);
    m.def("ofSoundStreamStop",  &ofSoundStreamStop);
    m.def("ofSoundStreamStart",  &ofSoundStreamStart);
    m.def("ofSoundStreamClose",  &ofSoundStreamClose);
    m.def("ofSoundStreamListDevices",  &ofSoundStreamListDevices);

    py::class_<ofSoundStream>(m, "ofSoundStream")
        .def(py::init<>())
        .def("setup", (bool (ofSoundStream::*)(int, int, int, int, int)) &ofSoundStream::setup)
        .def("setDevice",   &ofSoundStream::setDevice)
        .def("setDeviceID",   &ofSoundStream::setDeviceID)
        .def("printDeviceList", &ofSoundStream::printDeviceList)
        .def("getDeviceList",   &ofSoundStream::getDeviceList)
        .def("getMatchingDevices",   &ofSoundStream::getMatchingDevices)
        // .def("setup", (bool (ofSoundStream::*)(ofBaseApp*, int, int, int, int)) &ofSoundStream::setup)
        // .def("setInput", (void (ofSoundStream::*)(ofBaseSoundInput *)) &ofSoundStream::setInput)
        // .def("setInput", (void (ofSoundStream::*)(ofBaseSoundInput &)) &ofSoundStream::setInput)
        // .def("setOutput", (void (ofSoundStream::*)(ofBaseSoundOutput *)) &ofSoundStream::setOutput)
        // .def("setOutput", (void (ofSoundStream::*)(ofBaseSoundOutput &)) &ofSoundStream::setOutput)
        .def("start",   &ofSoundStream::start)
        .def("stop",   &ofSoundStream::stop)
        .def("close",   &ofSoundStream::close)
        .def("getTickCount",   &ofSoundStream::getTickCount)
        .def("getNumInputChannels",   &ofSoundStream::getNumInputChannels)
        .def("getNumOutputChannels",   &ofSoundStream::getNumOutputChannels)
        .def("getSampleRate",   &ofSoundStream::getSampleRate)
        .def("getBufferSize",   &ofSoundStream::getBufferSize);
        // .def("setSoundStream", &ofSoundStream::setSoundStream)
        // .def("getSoundStream", &ofSoundStream::getSoundStream)
        // .def_property("soundStream", &ofSoundStream::getSoundStream, &ofSoundStream::setSoundStream)
    py::class_<ofSoundBuffer> mSoundBuf(m,"ofSoundBuffer", py::metaclass());
    py::enum_<ofSoundBuffer::InterpolationAlgorithm>(mSoundBuf, "InterpolationAlgorithm")
        .value("Linear",  ofSoundBuffer::InterpolationAlgorithm::Linear)
        .value("Hermite", ofSoundBuffer::InterpolationAlgorithm::Hermite);
    mSoundBuf.def(py::init<>())
        .def_readwrite_static("defaultAlgorithm", &ofSoundBuffer::defaultAlgorithm)
        .def("allocate", &ofSoundBuffer::allocate)
        .def("getSampleRate", &ofSoundBuffer::getSampleRate)
        .def("setSampleRate", &ofSoundBuffer::setSampleRate)
        .def("resample", &ofSoundBuffer::resample, "speed"_a, "algorithm"_a=ofSoundBuffer::defaultAlgorithm)
        .def("getNumChannels", &ofSoundBuffer::getNumChannels)
        .def("setNumChannels", &ofSoundBuffer::setNumChannels)
        .def("getNumFrames", &ofSoundBuffer::getNumFrames)
        .def("getTickCount", &ofSoundBuffer::getTickCount)
        .def("setTickCount", &ofSoundBuffer::setTickCount)
        .def("getDurationMS", &ofSoundBuffer::getDurationMS)
        .def("getDurationMicros", &ofSoundBuffer::getDurationMicros)
        .def("getDurationNanos", &ofSoundBuffer::getDurationNanos)
        .def("getDeviceID", &ofSoundBuffer::getDeviceID)
        .def("setDeviceID", &ofSoundBuffer::setDeviceID)
        .def("getSample", (float& (ofSoundBuffer::*)(size_t, size_t)) &ofSoundBuffer::getSample)
        .def("__mul__", [](ofSoundBuffer& m, float value){ return m*value;}, py::is_operator())
        .def("__imul__", [](ofSoundBuffer& m, float value){ return m*=value;}, py::is_operator())
        .def("stereoPan", &ofSoundBuffer::stereoPan)
        .def("copyFrom", (void (ofSoundBuffer::*)(const short *, size_t, size_t, unsigned int)) &ofSoundBuffer::copyFrom)
        .def("copyFrom", (void (ofSoundBuffer::*)(const float *, size_t, size_t, unsigned int)) &ofSoundBuffer::copyFrom)
        .def("copyFrom", (void (ofSoundBuffer::*)(const vector<short> &, size_t, unsigned int)) &ofSoundBuffer::copyFrom)
        .def("copyFrom", (void (ofSoundBuffer::*)(const vector<float> &, size_t, unsigned int)) &ofSoundBuffer::copyFrom)
        .def("toShortPCM", (void (ofSoundBuffer::*)(vector<short> &) const) &ofSoundBuffer::toShortPCM)
        .def("toShortPCM", (void (ofSoundBuffer::*)(short *) const) &ofSoundBuffer::toShortPCM)
        .def("copyTo", (void (ofSoundBuffer::*)(ofSoundBuffer&, size_t, size_t, size_t, bool) const) &ofSoundBuffer::copyTo, "outBuffer"_a, "outNumFrames"_a, "outNumChannels"_a, "fromFrame"_a, "loop"_a=false)
        .def("addTo",  (void (ofSoundBuffer::*)(ofSoundBuffer&, size_t, size_t, size_t, bool) const) &ofSoundBuffer::addTo,  "outBuffer"_a, "outNumFrames"_a, "outNumChannels"_a, "fromFrame"_a, "loop"_a=false)
        .def("copyTo", (void (ofSoundBuffer::*)(ofSoundBuffer&, size_t, bool) const) &ofSoundBuffer::copyTo, "outBuffer"_a, "fromFrame"_a=0, "loop"_a=false)
        .def("addTo",  (void (ofSoundBuffer::*)(ofSoundBuffer&, size_t, bool) const) &ofSoundBuffer::addTo,  "outBuffer"_a, "fromFrame"_a=0, "loop"_a=false)
        .def("copyTo", (void (ofSoundBuffer::*)(float*, size_t, size_t, size_t, bool) const) &ofSoundBuffer::copyTo, "outBuffer"_a, "outNumFrames"_a, "outNumChannels"_a, "fromFrame"_a, "loop"_a=false)
        .def("addTo",  (void (ofSoundBuffer::*)(float*, size_t, size_t, size_t, bool) const) &ofSoundBuffer::addTo,  "outBuffer"_a, "outNumFrames"_a, "outNumChannels"_a, "fromFrame"_a, "loop"_a=false)
        .def("append", &ofSoundBuffer::append)
        .def("resampleTo", &ofSoundBuffer::resampleTo, "outBuffer"_a, "fromFrame"_a, "numFrames"_a, "speed"_a, "loop"_a=false, "algorithm"_a=ofSoundBuffer::defaultAlgorithm)
        .def("getChannel", &ofSoundBuffer::getChannel)
        .def("setChannel", &ofSoundBuffer::setChannel)
        .def("getRMSAmplitude", &ofSoundBuffer::getRMSAmplitude)
        .def("getRMSAmplitudeChannel", &ofSoundBuffer::getRMSAmplitudeChannel)
        .def("linearResampleTo", &ofSoundBuffer::linearResampleTo)
        .def("hermiteResampleTo", &ofSoundBuffer::hermiteResampleTo)
        .def("fillWithNoise", &ofSoundBuffer::fillWithNoise, "amplitude"_a=1.0f)
        .def("fillWithTone", &ofSoundBuffer::fillWithTone, "pitchHz"_a=440.0f, "phase"_a=0.0f)
        .def("normalize", &ofSoundBuffer::normalize, "level"_a=1)
        .def("trimSilence", &ofSoundBuffer::trimSilence, "threshold"_a=0.0001f, "trimStart"_a=true, "trimEnd"_a=true)
        .def("size", &ofSoundBuffer::size)
        .def("resize", &ofSoundBuffer::resize)
        .def("clear", &ofSoundBuffer::clear)
        .def("set", &ofSoundBuffer::set)
        .def("swap", &ofSoundBuffer::swap)
        .def("getBuffer",(vector<float>& (ofSoundBuffer::*)()) &ofSoundBuffer::getBuffer);

}