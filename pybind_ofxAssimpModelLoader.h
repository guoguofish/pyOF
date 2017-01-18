#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxAssimpUtils.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py=pybind11;

void pybind_ofxAssimp( py::module &m ) {
    using namespace py::literals;

    // m.def("aiVecToOfVec", &aiVecToOfVec);
    // m.def("aiMeshToOfMesh", &aiMeshToOfMesh);
    // m.def("aiMatrix4x4ToOfMatrix4x4", &aiMatrix4x4ToOfMatrix4x4);

    py::class_<ofxAssimpModelLoader>(m, "ofxAssimpModelLoader")
        .def(py::init<>())
        .def("draw", &ofxAssimpModelLoader::draw)
        .def("update", &ofxAssimpModelLoader::update)
        .def("drawFaces", &ofxAssimpModelLoader::drawFaces)
        .def("drawWireframe", &ofxAssimpModelLoader::drawWireframe)
        .def("enableColors", &ofxAssimpModelLoader::enableColors)
        .def("enableMaterials", &ofxAssimpModelLoader::enableMaterials)
        .def("enableTextures", &ofxAssimpModelLoader::enableTextures)
        .def("hasAnimations", &ofxAssimpModelLoader::hasAnimations)
        .def("hasMeshes", &ofxAssimpModelLoader::hasMeshes)
        .def("getNumMeshes", &ofxAssimpModelLoader::getNumMeshes)
        .def("loadModel", (bool (ofxAssimpModelLoader::*)(ofBuffer &, bool, const char*)) &ofxAssimpModelLoader::loadModel)
        .def("loadModel", (bool (ofxAssimpModelLoader::*)(string, bool)) &ofxAssimpModelLoader::loadModel, "modelName"_a, "optimize"_a=false)
        .def("setPosition", &ofxAssimpModelLoader::setPosition,"setPosition(fx, fy, fz)")
        .def("setRotation", &ofxAssimpModelLoader::setRotation,"setRotation(iWhich, fAngle, rx, ry, rz)")
        .def("setScale", &ofxAssimpModelLoader::setScale,"setScale(fx,fy,fz)")
        .def("setScaleNormalization", &ofxAssimpModelLoader::setScaleNormalization,"setScaleNormalization(bNormalize)");

}