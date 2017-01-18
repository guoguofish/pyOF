#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;

//-------- 类 -------
// of3dPrimitive ok
// of3dGraphics ok
// ofBoxPrimitive ok
// ofCylinderPrimitive ok
// ofPlanePrimitive ok
// ofSpherePrimitive ok
// ofConePrimitive ok
// ofIcoSpherePrimitive ok
// ofMesh     ok
// ofMeshFace ok
// ofCamera   ok
// ofEasyCam  ok
// ofNode     ok
//--------全局函数-------
// void ofDrawArrow(const ofVec3f &start, const ofVec3f &end, float headSize=0.05f)
// void ofDrawAxis(float size)
// void ofDrawGrid(float stepSize=1.25f, size_t numberOfSteps, bool labels=false, bool x=true, bool y=true, bool z=true)
// void ofDrawGridPlane(float stepSize=1.25f, size_t numberOfSteps, bool labels=false)
// void ofDrawRotationAxes(float radius, float stripWidth, int circleRes=60)
class pyOfNode: public ofNode {
public:
	using ofNode::ofNode;
	void customDraw() override { PYBIND11_OVERLOAD(void, ofNode, customDraw);}
	// void customDraw(const ofBaseRenderer * renderer) const override { PYBIND11_OVERLOAD(void, ofNode, customDraw, renderer);}
	// void draw() const override { PYBIND11_OVERLOAD(void, ofNode, draw);}
	void onPositionChanged() override { PYBIND11_OVERLOAD(void, ofNode, onPositionChanged);}
	void onOrientationChanged() override { PYBIND11_OVERLOAD(void, ofNode, onOrientationChanged);}
	void onScaleChanged() override { PYBIND11_OVERLOAD(void, ofNode, onScaleChanged);}
	void createMatrixPublic() { createMatrix(); }
	void updateAxisPublic() { updateAxis();}
	// void lookAt(const pyOfNode& lookAtNode){ lookAt(lookAtNode.getGlobalPosition());}
	// void lookAt(const pyOfNode& lookAtNode, const ofVec3f& upVector) { lookAt(lookAtNode.getGlobalPosition(), upVector);}
};


void pybind_3d(py::module &m) {
	using namespace py::literals;

	py::enum_<ofTexCompression>(m, "ofTexCompression")
        .value("OF_COMPRESS_NONE",   ofTexCompression::OF_COMPRESS_NONE)
        .value("OF_COMPRESS_SRGB",   ofTexCompression::OF_COMPRESS_SRGB)
        .value("OF_COMPRESS_ARB",    ofTexCompression::OF_COMPRESS_ARB)
        .export_values();
        
    py::enum_<ofLightType>(m, "ofLightType")
        .value("OF_LIGHT_POINT",       ofLightType::OF_LIGHT_POINT)
        .value("OF_LIGHT_DIRECTIONAL", ofLightType::OF_LIGHT_DIRECTIONAL)
        .value("OF_LIGHT_SPOT",        ofLightType::OF_LIGHT_SPOT)
        .value("OF_LIGHT_AREA",        ofLightType::OF_LIGHT_AREA)
        .export_values();

    py::enum_<ofPolyRenderMode>(m, "ofPolyRenderMode")
        .value("OF_MESH_POINTS",    ofPolyRenderMode::OF_MESH_POINTS)
        .value("OF_MESH_WIREFRAME", ofPolyRenderMode::OF_MESH_WIREFRAME)
        .value("OF_MESH_FILL",      ofPolyRenderMode::OF_MESH_FILL)
        .export_values();

    py::enum_<ofPrimitiveMode>(m, "ofPrimitiveMode")
        .value("OF_PRIMITIVE_TRIANGLES",                ofPrimitiveMode::OF_PRIMITIVE_TRIANGLES)
        .value("OF_PRIMITIVE_TRIANGLE_STRIP",           ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_STRIP)
        .value("OF_PRIMITIVE_TRIANGLE_FAN",             ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN)
        .value("OF_PRIMITIVE_LINE_STRIP",               ofPrimitiveMode::OF_PRIMITIVE_LINE_STRIP)
        .value("OF_PRIMITIVE_LINE_LOOP",                ofPrimitiveMode::OF_PRIMITIVE_LINE_LOOP)
        .value("OF_PRIMITIVE_POINTS",                   ofPrimitiveMode::OF_PRIMITIVE_POINTS)
        #ifndef TARGET_OPENGLES
        .value("OF_PRIMITIVE_LINES_ADJACENCY",          ofPrimitiveMode::OF_PRIMITIVE_LINES_ADJACENCY)
        .value("OF_PRIMITIVE_LINE_STRIP_ADJACENCY",     ofPrimitiveMode::OF_PRIMITIVE_LINE_STRIP_ADJACENCY)
        .value("OF_PRIMITIVE_TRIANGLES_ADJACENCY",      ofPrimitiveMode::OF_PRIMITIVE_TRIANGLES_ADJACENCY)
        .value("OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY", ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY)
        .value("OF_PRIMITIVE_PATCHES",                  ofPrimitiveMode::OF_PRIMITIVE_PATCHES)
        #endif
        .export_values();

	py::class_<ofNode>(m,"ofNode")
		.def(py::init<>())
		.def(py::init<const ofNode&>())
		.def("setParent",   &ofNode::setParent,   "parent"_a, "bMaintainGlobalTransform"_a=false)
		.def("clearParent", &ofNode::clearParent, "bMaintainGlobalTransform"_a=false)
		.def("getParent",   &ofNode::getParent)
		.def("getPosition", &ofNode::getPosition)
		.def("getX", &ofNode::getX)
		.def("getY", &ofNode::getY)
		.def("getZ", &ofNode::getZ)
		.def("getXAxis", &ofNode::getXAxis)
		.def("getYAxis", &ofNode::getYAxis)
		.def("getZAxis", &ofNode::getZAxis)
		.def("getSideDir", &ofNode::getSideDir)
		.def("getLookAtDir", &ofNode::getLookAtDir)
		.def("getUpDir", &ofNode::getUpDir)
		.def("getPitch", &ofNode::getPitch)
		.def("getHeading", &ofNode::getHeading)
		.def("getRoll", &ofNode::getRoll)
		.def("getOrientationQuat", &ofNode::getOrientationQuat)
		.def("getOrientationEuler", &ofNode::getOrientationEuler)
		.def("getScale", &ofNode::getScale)
		.def("getLocalTransformMatrix", &ofNode::getLocalTransformMatrix)
		.def("getGlobalTransformMatrix", &ofNode::getGlobalTransformMatrix)
		.def("getGlobalPosition", &ofNode::getGlobalPosition)
		.def("getGlobalOrientation", &ofNode::getGlobalOrientation)
		.def("getGlobalScale", &ofNode::getGlobalScale)
		.def("setTransformMatrix", &ofNode::setTransformMatrix)
		.def("setPosition", (void (ofNode::*)(float, float, float)) &ofNode::setPosition)
		.def("setPosition", (void (ofNode::*)(const ofVec3f &)) &ofNode::setPosition)
		.def("setGlobalPosition", (void (ofNode::*)(float, float, float)) &ofNode::setGlobalPosition)
		.def("setGlobalPosition", (void (ofNode::*)(const ofVec3f &)) &ofNode::setGlobalPosition)
		.def("setOrientation", (void (ofNode::*)(const ofQuaternion&)) &ofNode::setOrientation)
		.def("setOrientation", (void (ofNode::*)(const ofVec3f &)) &ofNode::setOrientation)
		.def("setGlobalOrientation", &ofNode::setGlobalOrientation)
		.def("setScale", (void (ofNode::*)(float)) &ofNode::setScale)
		.def("setScale", (void (ofNode::*)(float, float, float)) &ofNode::setScale)
		.def("setScale", (void (ofNode::*)(const ofVec3f &)) &ofNode::setScale)
		.def("move", (void (ofNode::*)(float, float, float)) &ofNode::move)
		.def("move", (void (ofNode::*)(const ofVec3f &)) &ofNode::move)
		.def("truck", &ofNode::truck)
		.def("boom", &ofNode::boom)
		.def("dolly", &ofNode::dolly)
		.def("tilt", &ofNode::tilt)
		.def("pan", &ofNode::pan)
		.def("roll", &ofNode::roll)
		.def("rotate", (void (ofNode::*)(const ofQuaternion &)) &ofNode::rotate)
		.def("rotate", (void (ofNode::*)(float, const ofVec3f &)) &ofNode::rotate)
		.def("rotate", (void (ofNode::*)(float, float, float, float)) &ofNode::rotate)
		.def("rotateAround", (void (ofNode::*)(const ofQuaternion&, const ofVec3f&)) &ofNode::rotateAround)
		.def("rotateAround", (void (ofNode::*)(float, const ofVec3f&, const ofVec3f&)) &ofNode::rotateAround)
		.def("lookAt", (void (ofNode::*)(const ofVec3f &)) &ofNode::lookAt)
		.def("lookAt", (void (ofNode::*)(const ofVec3f &, ofVec3f)) &ofNode::lookAt)
		.def("lookAt", (void (ofNode::*)(const ofNode &)) &ofNode::lookAt)
		.def("lookAt", (void (ofNode::*)(const ofNode &, const ofVec3f&)) &ofNode::lookAt)
		.def("orbit", (void (ofNode::*)(float, float,float, const ofVec3f&)) &ofNode::orbit, "longitude"_a, "latitude"_a, "radius"_a, "centerPoint"_a=ofVec3f(0, 0, 0))
		.def("orbit", (void (ofNode::*)(float, float,float, ofNode&)) &ofNode::orbit)
		.def("resetTransform", &ofNode::resetTransform)
		.def_property("parent", &ofNode::getParent, &ofNode::setParent);
	// 	.def("createMatrix", &pyOfNode::createMatrixPublic)
	// 	.def("updateAxis", &pyOfNode::updateAxisPublic)
	//  .def("customDraw", (void (pyOfNode::*)(const ofBaseRenderer *)) &pyOfNode::customDraw)
	// 	.def("customDraw", (void (pyOfNode::*)()) &pyOfNode::customDraw)
	// 	.def("onPositionChanged", &pyOfNode::onPositionChanged)
	// 	.def("onOrientationChanged", &pyOfNode::onOrientationChanged)
	// 	.def("onScaleChanged", &pyOfNode::onScaleChanged);

	py::class_<of3dPrimitive, ofNode>(m, "of3dPrimitive")
		.def(py::init<>())
		.def(py::init<const of3dPrimitive&>())
		.def(py::init<const ofMesh&>())
		.def("mapTexCoords", &of3dPrimitive::mapTexCoords)
		.def("mapTexCoordsFromTexture", &of3dPrimitive::mapTexCoordsFromTexture)
		.def("getMeshPtr", (ofMesh* (of3dPrimitive::*)()) &of3dPrimitive::getMeshPtr, py::return_value_policy::reference)
		.def("getMesh", (ofMesh& (of3dPrimitive::*)()) &of3dPrimitive::getMesh, py::return_value_policy::reference)
		.def("getTexCoordsPtr",(ofVec4f* (of3dPrimitive::*)()) &of3dPrimitive::getTexCoordsPtr, py::return_value_policy::reference)
		.def("getTexCoords", (ofVec4f& (of3dPrimitive::*)()) &of3dPrimitive::getTexCoords, py::return_value_policy::reference)
		.def("hasScaling", &of3dPrimitive::hasScaling)
		.def("hasNormalsEnabled", &of3dPrimitive::hasNormalsEnabled)
		.def("enableNormals", &of3dPrimitive::enableNormals)
		.def("enableTextures", &of3dPrimitive::enableTextures)
		.def("enableColors", &of3dPrimitive::enableColors)
		.def("disableNormals", &of3dPrimitive::disableNormals)
		.def("disableTextures", &of3dPrimitive::disableTextures)
		.def("disableColors", &of3dPrimitive::disableColors)
		.def("drawVertices", &of3dPrimitive::drawVertices)
		.def("drawWireframe", &of3dPrimitive::drawWireframe)
		.def("drawFaces", &of3dPrimitive::drawFaces)
		.def("drawNormals", &of3dPrimitive::drawNormals, "length"_a, "bFaceNormals"_a=false)
		.def("drawAxes", &of3dPrimitive::drawAxes)
		.def("draw", (void (of3dPrimitive::*) () const) &of3dPrimitive::draw)
		.def("draw", (void (of3dPrimitive::*) (ofPolyRenderMode) const) &of3dPrimitive::draw)
		.def("setUseVbo", &of3dPrimitive::setUseVbo)
		.def("isUsingVbo", &of3dPrimitive::isUsingVbo);

	py::class_<ofBoxPrimitive, of3dPrimitive> box(m, "ofBoxPrimitive");
	py::enum_<ofBoxPrimitive::BoxSides>(box, "BoxSides")
		.value("SIDE_FRONT",  ofBoxPrimitive::BoxSides::SIDE_FRONT)
		.value("SIDE_RIGHT",  ofBoxPrimitive::BoxSides::SIDE_RIGHT)
		.value("SIDE_LEFT",   ofBoxPrimitive::BoxSides::SIDE_LEFT)
		.value("SIDE_BACK",   ofBoxPrimitive::BoxSides::SIDE_BACK)
		.value("SIDE_TOP",    ofBoxPrimitive::BoxSides::SIDE_TOP)
		.value("SIDE_BOTTOM", ofBoxPrimitive::BoxSides::SIDE_BOTTOM)
		.value("SIDES_TOTAL", ofBoxPrimitive::BoxSides::SIDES_TOTAL);
	box.def(py::init<>())
		.def(py::init<float, float, float, int, int, int>(), "width"_a, "height"_a, "depth"_a, "resWidth"_a=2, "resHeight"_a=2, "resDepth"_a=2)
		.def("set", (void (ofBoxPrimitive::*)(float)) &ofBoxPrimitive::set)
		.def("set", (void (ofBoxPrimitive::*)(float, float, float)) &ofBoxPrimitive::set)
		.def("set", (void (ofBoxPrimitive::*)(float, float, float, int, int, int)) &ofBoxPrimitive::set)
		.def("setWidth", &ofBoxPrimitive::setWidth)
		.def("setHeight", &ofBoxPrimitive::setHeight)
		.def("setDepth", &ofBoxPrimitive::setDepth)
		.def("resizeToTexture", &ofBoxPrimitive::resizeToTexture)
		.def("getSideIndices", &ofBoxPrimitive::getSideIndices)
		.def("getSideMesh", &ofBoxPrimitive::getSideMesh)
		.def("setResolutionWidth", &ofBoxPrimitive::setResolutionWidth)
		.def("getResolutionWidth", &ofBoxPrimitive::getResolutionWidth)
		.def("setResolutionHeight", &ofBoxPrimitive::setResolutionHeight)
		.def("getResolutionHeight", &ofBoxPrimitive::getResolutionHeight)
		.def("setResolutionDepth", &ofBoxPrimitive::setResolutionDepth)
		.def("getResolutionDepth", &ofBoxPrimitive::getResolutionDepth)
		.def("setResolution", (void (ofBoxPrimitive::*)(int)) &ofBoxPrimitive::setResolution)
		.def("setResolution", (void (ofBoxPrimitive::*)(int,int,int)) &ofBoxPrimitive::setResolution)
		.def("setMode", &ofBoxPrimitive::setMode)
		.def("setSideColor", &ofBoxPrimitive::setSideColor)
		.def("getResolution", &ofBoxPrimitive::getResolution)
		.def("getWidth", &ofBoxPrimitive::getWidth)
		.def("getHeight", &ofBoxPrimitive::getHeight)
		.def("getDepth", &ofBoxPrimitive::getDepth)
		.def("getSize", &ofBoxPrimitive::getSize)
		.def_property("width", &ofBoxPrimitive::getWidth, &ofBoxPrimitive::setWidth)
		.def_property("height", &ofBoxPrimitive::getHeight, &ofBoxPrimitive::setHeight)
		.def_property("depth", &ofBoxPrimitive::getDepth, &ofBoxPrimitive::setDepth)
		.def_property("resWidth", &ofBoxPrimitive::getResolutionWidth, &ofBoxPrimitive::setResolutionWidth)
		.def_property("resHeight", &ofBoxPrimitive::getResolutionHeight, &ofBoxPrimitive::setResolutionHeight)
		.def_property("resDepth", &ofBoxPrimitive::getResolutionDepth, &ofBoxPrimitive::setResolutionDepth);

	py::class_<ofCylinderPrimitive, of3dPrimitive>(m, "ofCylinderPrimitive")
		.def(py::init<>())
		.def(py::init<float, float, int, int, int, bool, ofPrimitiveMode>(), "radius"_a, "height"_a, "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2, "bCapped"_a=true, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", (void (ofCylinderPrimitive::*)(float, float, int, int, int, bool, ofPrimitiveMode)) &ofCylinderPrimitive::set, "radius"_a, "height"_a, "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2, "bCapped"_a=true, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", (void (ofCylinderPrimitive::*)(float, float, bool)) &ofCylinderPrimitive::set, "radius"_a, "height"_a, "bCapped"_a=true)
		.def("setResolutionRadius", &ofCylinderPrimitive::setResolutionRadius)
		.def("getResolutionRadius", &ofCylinderPrimitive::getResolutionRadius)
		.def("getResolutionHeight", &ofCylinderPrimitive::getResolutionHeight)
		.def("setResolutionHeight", &ofCylinderPrimitive::setResolutionHeight)
		.def("setResolutionCap", &ofCylinderPrimitive::setResolutionCap)
		.def("getResolutionCap", &ofCylinderPrimitive::getResolutionCap)
		.def("getResolution", &ofCylinderPrimitive::getResolution)
		.def("setResolution", &ofCylinderPrimitive::setResolution, "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2)
		.def("setMode", &ofCylinderPrimitive::setMode)
		.def("setTopCapColor", &ofCylinderPrimitive::setTopCapColor)
		.def("setCylinderColor", &ofCylinderPrimitive::setCylinderColor)
		.def("setBottomCapColor", &ofCylinderPrimitive::setBottomCapColor)
		.def("getTopCapIndices", &ofCylinderPrimitive::getTopCapIndices)
		.def("getCylinderIndices", &ofCylinderPrimitive::getCylinderIndices)
		.def("getBottomCapIndices", &ofCylinderPrimitive::getBottomCapIndices)
		.def("getTopCapMesh", &ofCylinderPrimitive::getTopCapMesh)
		.def("getCylinderMesh", &ofCylinderPrimitive::getCylinderMesh)
		.def("getBottomCapMesh", &ofCylinderPrimitive::getBottomCapMesh)
		.def_property("radius", &ofCylinderPrimitive::getRadius, &ofCylinderPrimitive::setRadius)
		.def_property("height", &ofCylinderPrimitive::getHeight, &ofCylinderPrimitive::setHeight)
		.def_property("bCapped", &ofCylinderPrimitive::getCapped, &ofCylinderPrimitive::setCapped);

	py::class_<ofConePrimitive, of3dPrimitive>(m, "ofConePrimitive")
		.def(py::init<>())
		.def(py::init<float, float, int, int, int, ofPrimitiveMode>(), "radius"_a, "height"_a, "radiusSegments"_a, "heightSegments"_a,"capSegments"_a=2, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", (void (ofConePrimitive::*)(float, float, int, int, int, ofPrimitiveMode)) &ofConePrimitive::set, "radius"_a, "height"_a, "radiusSegments"_a, "heightSegments"_a,"capSegments"_a=2, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", (void (ofConePrimitive::*)(float, float)) &ofConePrimitive::set)
		.def("setResolutionRadius", &ofConePrimitive::setResolutionRadius)
		.def("getResolutionRadius", &ofConePrimitive::getResolutionRadius)
		.def("setResolutionHeight", &ofConePrimitive::setResolutionHeight)
		.def("getResolutionHeight", &ofConePrimitive::getResolutionHeight)
		.def("setResolutionCap", &ofConePrimitive::setResolutionCap)
		.def("getResolutionCap", &ofConePrimitive::getResolutionCap)
		.def("setResolution", &ofConePrimitive::setResolution)
		.def("getResolution", &ofConePrimitive::getResolution)
		.def("setMode", &ofConePrimitive::setMode)
		.def("setTopColor", &ofConePrimitive::setTopColor)
		.def("setCapColor", &ofConePrimitive::setCapColor)
		.def("getConeIndices", &ofConePrimitive::getConeIndices, py::return_value_policy::reference)
		.def("getCapIndices", &ofConePrimitive::getCapIndices, py::return_value_policy::reference)
		.def("getConeMesh", &ofConePrimitive::getConeMesh, py::return_value_policy::reference)
		.def("getCapMesh", &ofConePrimitive::getCapMesh, py::return_value_policy::reference)
		.def_property("radius",     &ofConePrimitive::getRadius,     &ofConePrimitive::setRadius)
		.def_property("height",     &ofConePrimitive::getHeight,     &ofConePrimitive::setHeight)
		.def_property("resRadius",  &ofConePrimitive::getResolutionRadius,     &ofConePrimitive::setResolutionRadius)
		.def_property("resHeight",  &ofConePrimitive::getResolutionHeight,     &ofConePrimitive::setResolutionHeight)
		.def_property("resCap",     &ofConePrimitive::getResolutionCap,        &ofConePrimitive::setResolutionCap);

	py::class_<ofIcoSpherePrimitive, of3dPrimitive>(m, "ofIcoSpherePrimitive")
		.def(py::init<>())
		.def(py::init<float,int>())
		.def("set", &ofIcoSpherePrimitive::set)
		.def("setMode", &ofIcoSpherePrimitive::setMode)
		.def_property("radius",     &ofIcoSpherePrimitive::getRadius,     &ofIcoSpherePrimitive::setRadius)
		.def_property("resolution", &ofIcoSpherePrimitive::getResolution, &ofIcoSpherePrimitive::setResolution);

	py::class_<ofSpherePrimitive, of3dPrimitive>(m, "ofSpherePrimitive")
		.def(py::init<>())
		.def(py::init<float, int, ofPrimitiveMode >(),"radius"_a, "res"_a, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", &ofSpherePrimitive::set, "radius"_a, "res"_a, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("setMode", &ofSpherePrimitive::setMode)
		.def_property("radius",     &ofSpherePrimitive::getRadius,     &ofSpherePrimitive::setRadius)
		.def_property("resolution", &ofSpherePrimitive::getResolution, &ofSpherePrimitive::setResolution);

	py::class_<ofPlanePrimitive, of3dPrimitive>(m, "ofPlanePrimitive")
		.def(py::init<>())
		.def(py::init<float, float, int, int, ofPrimitiveMode>(), "width"_a, "height"_a, "columns"_a, "rows"_a, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", (void (ofPlanePrimitive::*)(float, float, int, int, ofPrimitiveMode)) &ofPlanePrimitive::set, "width"_a, "height"_a, "columns"_a, "rows"_a, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def("set", (void (ofPlanePrimitive::*)(float, float)) &ofPlanePrimitive::set)
		.def("resizeToTexture", &ofPlanePrimitive::resizeToTexture, "inTexture"_a, "scale"_a=1.f)
		.def("setWidth",        &ofPlanePrimitive::setWidth)
		.def("getWidth",        &ofPlanePrimitive::getWidth)
		.def("setHeight",       &ofPlanePrimitive::setHeight)
		.def("getHeight",       &ofPlanePrimitive::getHeight)
		.def("setColumns",      &ofPlanePrimitive::setColumns)
		.def("getNumColumns",   &ofPlanePrimitive::getNumColumns)
		.def("setRows",         &ofPlanePrimitive::setRows)
		.def("getNumRows",      &ofPlanePrimitive::getNumRows)
		.def("setResolution",   &ofPlanePrimitive::setResolution)
		.def("getResolution",   &ofPlanePrimitive::getResolution)
		.def("setMode",         &ofPlanePrimitive::setMode)
		.def_property("width",  &ofPlanePrimitive::getWidth,  &ofPlanePrimitive::setWidth)
		.def_property("height", &ofPlanePrimitive::getHeight, &ofPlanePrimitive::setHeight)
		.def_property("resolution", &ofPlanePrimitive::getResolution, &ofPlanePrimitive::setResolution);

	py::class_<of3dGraphics>(m, "of3dGraphics")
		.def(py::init<ofBaseRenderer *>())
		.def("setPlaneResolution", &of3dGraphics::setPlaneResolution)
		.def("getPlaneResolution", &of3dGraphics::getPlaneResolution)
		.def("drawPlane", (void (of3dGraphics::*)(float, float, float, float) const) &of3dGraphics::drawPlane)
		.def("drawPlane", (void (of3dGraphics::*)(float, float, float, float, float) const) &of3dGraphics::drawPlane)
		.def("drawPlane", (void (of3dGraphics::*)(ofPoint&, float, float) const) &of3dGraphics::drawPlane)
		.def("drawPlane", (void (of3dGraphics::*)(float, float) const) &of3dGraphics::drawPlane)
		.def("setSphereResolution", &of3dGraphics::setSphereResolution)
		.def("getSphereResolution", &of3dGraphics::getSphereResolution)
		.def("drawSphere", (void (of3dGraphics::*)(float, float, float) const) &of3dGraphics::drawSphere)
		.def("drawSphere", (void (of3dGraphics::*)(float, float, float, float) const) &of3dGraphics::drawSphere)
		.def("drawSphere", (void (of3dGraphics::*)(const ofPoint&, float) const) &of3dGraphics::drawSphere)
		.def("drawSphere", (void (of3dGraphics::*)(float) const) &of3dGraphics::drawSphere)
		.def("setIcoSphereResolution", &of3dGraphics::setIcoSphereResolution)
		.def("getIcoSphereResolution", &of3dGraphics::getIcoSphereResolution)
		.def("drawIcoSphere", (void (of3dGraphics::*)(float, float,    float, float) const) &of3dGraphics::drawIcoSphere)
		.def("drawIcoSphere", (void (of3dGraphics::*)(float, float,    float)        const) &of3dGraphics::drawIcoSphere)
		.def("drawIcoSphere", (void (of3dGraphics::*)(const  ofPoint&, float)        const) &of3dGraphics::drawIcoSphere)
		.def("drawIcoSphere", (void (of3dGraphics::*)(float) const)    						&of3dGraphics::drawIcoSphere)
		.def("setCylinderResolution", &of3dGraphics::setCylinderResolution, "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2)
		.def("getCylinderResolution", &of3dGraphics::getCylinderResolution)
		.def("drawCylinder", (void (of3dGraphics::*)(float, float,      float, float) const) &of3dGraphics::drawCylinder)
		.def("drawCylinder", (void (of3dGraphics::*)(float, float, float,float,float) const) &of3dGraphics::drawCylinder)
		.def("drawCylinder", (void (of3dGraphics::*)(const  ofPoint&, float, float)   const) &of3dGraphics::drawCylinder)
		.def("drawCylinder", (void (of3dGraphics::*)(float, float) const)    		         &of3dGraphics::drawCylinder)
		.def("setConeResolution", &of3dGraphics::setConeResolution, "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2)
		.def("getConeResolution", &of3dGraphics::getConeResolution)
		.def("drawCone", (void (of3dGraphics::*)(float, float, float,float, float) const) &of3dGraphics::drawCone)
		.def("drawCone", (void (of3dGraphics::*)(float, float, float,float) const)        &of3dGraphics::drawCone)
		.def("drawCone", (void (of3dGraphics::*)(const  ofPoint&, float, float)   const)  &of3dGraphics::drawCone)
		.def("drawCone", (void (of3dGraphics::*)(float, float) const)    		          &of3dGraphics::drawCone)
		.def("setBoxResolution", (void (of3dGraphics::*)(int) ) &of3dGraphics::setBoxResolution)
		.def("setBoxResolution", (void (of3dGraphics::*)(int, int,int) ) &of3dGraphics::setBoxResolution)
		.def("getBoxResolution", &of3dGraphics::getBoxResolution)
		.def("drawBox", (void (of3dGraphics::*)(float) const) &of3dGraphics::drawBox)
		.def("drawBox", (void (of3dGraphics::*)(const ofPoint&, float) const) &of3dGraphics::drawBox)
		.def("drawBox", (void (of3dGraphics::*)(const ofPoint&, float, float, float) const) &of3dGraphics::drawBox)
		.def("drawBox", (void (of3dGraphics::*)(float, float, float) const) &of3dGraphics::drawBox)
		.def("drawBox", (void (of3dGraphics::*)(float, float, float, float) const) &of3dGraphics::drawBox)
		.def("drawBox", (void (of3dGraphics::*)(float, float, float, float, float, float) const) &of3dGraphics::drawBox)
		.def("drawAxis", &of3dGraphics::drawAxis)
		.def("drawGrid", &of3dGraphics::drawGrid)
		.def("drawGridPlane", &of3dGraphics::drawGridPlane)
		.def("drawArrow", &of3dGraphics::drawArrow)
		.def("drawRotationAxes", &of3dGraphics::drawRotationAxes);
	// ofMesh 有许多虚函数没有封装.
	// typedef TESSindex ofIndexType;
	// typedef float TESSreal;
    // #if TARGET_OS_IPHONE || ANDROID || __ARMEL__ || EMSCRIPTEN
    //    typedef unsigned short TESSindex;
    // #else
    //   typedef unsigned int TESSindex;
    // #endif
	py::class_<ofMesh>(m, "ofMesh")
		.def(py::init<>())
		.def(py::init<ofPrimitiveMode, const vector<ofVec3f>&>())
		.def("setFromTriangles", &ofMesh::setFromTriangles, "tris"_a, "bUseFaceNormal"_a=false)
		.def("setMode", &ofMesh::setMode)
		.def("getMode", &ofMesh::getMode)
		.def_static("plane", &ofMesh::plane, "width"_a, "height"_a, "columns"_a=2, "rows"_a=2, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def_static("sphere", &ofMesh::sphere, "radius"_a, "res"_a, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def_static("icosphere", &ofMesh::icosphere, "radius"_a, "iterations"_a=2)
		.def_static("icosahedron", &ofMesh::icosahedron)
		.def_static("cylinder", &ofMesh::cylinder, "radius"_a, "height"_a, "radiusSegments"_a=12, "heightSegments"_a=6, "numCapSegments"_a=2, "bCapped"_a=true, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def_static("cone", &ofMesh::cone, "radius"_a, "height"_a, "radiusSegments"_a=12, "heightSegments"_a=6, "capSegments"_a=2, "mode"_a=OF_PRIMITIVE_TRIANGLE_STRIP)
		.def_static("box", &ofMesh::box, "width"_a, "height"_a, "depth"_a, "resX"_a=2, "resY"_a=2, "resZ"_a=2)
		.def_static("axis", &ofMesh::axis, "size"_a=1.0)
		.def("addVertex", &ofMesh::addVertex)
		.def("removeVertex", &ofMesh::removeVertex)
		.def("setVertex", &ofMesh::setVertex)
		.def("clearVertices", &ofMesh::clearVertices)
		.def("clear", &ofMesh::clear)
		.def("getNumVertices", &ofMesh::getNumVertices)
		.def("getVerticesPointer",(ofVec3f* (ofMesh::*)()) &ofMesh::getVerticesPointer)
		.def("getVertex", &ofMesh::getVertex)
		.def("haveVertsChanged", &ofMesh::haveVertsChanged)
		.def("hasVertices", &ofMesh::hasVertices)
		.def("append", &ofMesh::append)
		.def("mergeDuplicateVertices", &ofMesh::mergeDuplicateVertices)
		.def("getCentroid", &ofMesh::getCentroid)
		.def("getNormal", &ofMesh::getNormal)
		.def("addNormal", &ofMesh::addNormal)
		.def("removeNormal", &ofMesh::removeNormal)
		.def("setNormal", &ofMesh::removeNormal)
		.def("clearNormals", &ofMesh::clearNormals)
		.def("getNumNormals", &ofMesh::getNumNormals)
		.def("hasNormals", &ofMesh::hasNormals)
		.def("haveNormalsChanged", &ofMesh::haveNormalsChanged)
		.def("smoothNormals", &ofMesh::smoothNormals)
		.def("getFace", &ofMesh::getFace)
		.def("getUniqueFaces", &ofMesh::getUniqueFaces)
		.def("getNormalsPointer", (ofVec3f* (ofMesh::*)()) &ofMesh::getNormalsPointer)
		.def("getVertices", (vector<ofVec3f>& (ofMesh::*)()) &ofMesh::getVertices)
		.def("getNormals",  (vector<ofVec3f>& (ofMesh::*)()) &ofMesh::getNormals)
		.def("addVertices", (void (ofMesh::*)(const vector<ofVec3f>&)) &ofMesh::addVertices)
		.def("addVertices", (void (ofMesh::*)(const ofVec3f*, size_t)) &ofMesh::addVertices)
		.def("addNormals",  (void (ofMesh::*)(const vector<ofVec3f>&)) &ofMesh::addNormals)
		.def("addNormals",  (void (ofMesh::*)(const ofVec3f*, size_t)) &ofMesh::addNormals)
		.def("getFaceNormals",  (vector<ofVec3f> (ofMesh::*)(bool) const) &ofMesh::getFaceNormals, "perVetex"_a=false)
		.def("getColor", &ofMesh::getColor)
		.def("addColor", &ofMesh::addColor)
		.def("addColors",  (void (ofMesh::*)(const vector<ofFloatColor>&)) &ofMesh::addColors)
		.def("addColors",  (void (ofMesh::*)(const ofFloatColor*, size_t)) &ofMesh::addColors)
		.def("removeColor", &ofMesh::removeColor)
		.def("setColor", &ofMesh::setColor)
		.def("clearColors", &ofMesh::clearColors)
		.def("getNumColors", &ofMesh::getNumColors)
		.def("getColorsPointer",  (ofFloatColor* (ofMesh::*)()) &ofMesh::getColorsPointer)
		.def("getColors",  (vector<ofFloatColor>& (ofMesh::*)()) &ofMesh::getColors)
		.def("haveColorsChanged", &ofMesh::haveColorsChanged)
		.def("hasColors", &ofMesh::hasColors)
		.def("getTexCoord", &ofMesh::getTexCoord)
		.def("addTexCoord", &ofMesh::addTexCoord)
		.def("addTexCoords",  (void (ofMesh::*)( const vector<ofVec2f>& )) &ofMesh::addTexCoords)
		.def("addTexCoords",  (void (ofMesh::*)( const ofVec2f*, size_t )) &ofMesh::addTexCoords)
		.def("removeTexCoord", &ofMesh::removeTexCoord)
		.def("setTexCoord", &ofMesh::setTexCoord)
		.def("clearTexCoords", &ofMesh::clearTexCoords)
		.def("getNumTexCoords", &ofMesh::getNumTexCoords)
		.def("getTexCoordsPointer", (ofVec2f*  (ofMesh::*)()) &ofMesh::getTexCoordsPointer)
		.def("getTexCoords", (vector<ofVec2f>& (ofMesh::*)()) &ofMesh::getTexCoords)
		.def("haveTexCoordsChanged", &ofMesh::haveTexCoordsChanged)
		.def("hasTexCoords", &ofMesh::hasTexCoords)
		.def("setupIndicesAuto", &ofMesh::setupIndicesAuto)
		.def("getIndices", (vector<ofIndexType>& (ofMesh::*)()) &ofMesh::getIndices)
		.def("getIndex", &ofMesh::getIndex)
		.def("addIndex", &ofMesh::addIndex)
		.def("addIndices", (void (ofMesh::*) (const vector<ofIndexType>&)) &ofMesh::addIndices)
		.def("addIndices", (void (ofMesh::*) (const ofIndexType*, size_t)) &ofMesh::addIndices)
		.def("removeIndex", &ofMesh::removeIndex)
		.def("setIndex", &ofMesh::setIndex)
		.def("clearIndices", &ofMesh::clearIndices)
		.def("getNumIndices", &ofMesh::getNumIndices)
		.def("getIndexPointer", (ofIndexType* (ofMesh::*)()) &ofMesh::getIndexPointer)
		.def("haveIndicesChanged", &ofMesh::haveIndicesChanged)
		.def("hasIndices", &ofMesh::hasIndices)
		.def("addTriangle", &ofMesh::addTriangle)
		.def("addTriangle", &ofMesh::addTriangle)
		.def("setColorForIndices", &ofMesh::setColorForIndices)
		.def("getMeshForIndices", (ofMesh (ofMesh::*)(ofIndexType, ofIndexType) const) &ofMesh::getMeshForIndices)
		.def("getMeshForIndices", (ofMesh (ofMesh::*)(ofIndexType, ofIndexType, ofIndexType, ofIndexType) const) &ofMesh::getMeshForIndices)
		.def("drawVertices",  &ofMesh::drawVertices)
		.def("drawWireframe", &ofMesh::drawWireframe)
		.def("drawFaces", &ofMesh::drawFaces)
		.def("draw", (void (ofMesh::*)() const) &ofMesh::draw)
		.def("load", &ofMesh::load)
		.def("save", &ofMesh::save, "path"_a, "useBinary"_a=false);

	py::class_<ofMeshFace>(m, "ofMeshFace")
		.def(py::init<>())
		.def("getFaceNormal",   &ofMeshFace::getFaceNormal)
		.def("setVertex",       &ofMeshFace::setVertex)
		.def("getVertex",       &ofMeshFace::getVertex)
		.def("setNormal",       &ofMeshFace::setNormal)
		.def("getNormal",       &ofMeshFace::getNormal)
		.def("setColor",        &ofMeshFace::setColor)
		.def("getColor",        &ofMeshFace::getColor)
		.def("setTexCoord",     &ofMeshFace::setTexCoord)
		.def("getTexCoord",     &ofMeshFace::getTexCoord)
		.def("setHasColors",    &ofMeshFace::setHasColors)
		.def("setHasNormals",   &ofMeshFace::setHasNormals)
		.def("setHasTexcoords", &ofMeshFace::setHasTexcoords)
		.def("hasColors",       &ofMeshFace::hasColors)
		.def("hasNormals",      &ofMeshFace::hasNormals)
		.def("hasTexcoords",    &ofMeshFace::hasTexcoords);

	py::class_<ofCamera, ofNode>(m,"ofCamera")
		.def(py::init<>())
		.def("begin",        &ofCamera::begin, "viewport"_a=ofRectangle())
		.def("end",          &ofCamera::end)
		.def("enableOrtho",  &ofCamera::enableOrtho)
		.def("disableOrtho", &ofCamera::disableOrtho)
		.def("getOrtho",     &ofCamera::getOrtho)
		.def("cameraToWorld", &ofCamera::cameraToWorld, "CameraXYZ"_a, "viewport"_a=ofRectangle())
		.def("getAspectRatio",      &ofCamera::getAspectRatio)
		.def("getNearClip",         &ofCamera::getNearClip)
		.def("getFarClip",          &ofCamera::getFarClip)
		.def("getForceAspectRatio", &ofCamera::getForceAspectRatio)
		.def("getFov",              &ofCamera::getFov)
		.def("getImagePlaneDistance", &ofCamera::getImagePlaneDistance, "viewport"_a=ofRectangle())
		.def("getLensOffset", &ofCamera::getLensOffset)
		.def("getModelViewMatrix", &ofCamera::getModelViewMatrix)
		.def("getModelViewProjectionMatrix", &ofCamera::getModelViewProjectionMatrix, "viewport"_a=ofRectangle())
		.def("getProjectionMatrix", &ofCamera::getProjectionMatrix, "viewport"_a=ofRectangle())
		.def("isVFlipped",          &ofCamera::isVFlipped)
		.def("screenToWorld",       &ofCamera::screenToWorld, "ScreenXYZ"_a, "viewport"_a=ofRectangle())
		.def("setAspectRatio",      &ofCamera::setAspectRatio)
		.def("setFarClip",          &ofCamera::setFarClip)
		.def("setForceAspectRatio", &ofCamera::setForceAspectRatio)
		.def("setFov",              &ofCamera::setFov)
		.def("setLensOffset",       &ofCamera::setLensOffset)
		.def("setNearClip",         &ofCamera::setNearClip)
		.def("setVFlip",            &ofCamera::setVFlip)
		.def("setupOffAxisViewPortal", &ofCamera::setupOffAxisViewPortal)
		.def("setupPerspective", &ofCamera::setupPerspective, "vFlip"_a=true, "fov"_a=60, "nearDist"_a=0, "farDist"_a=0, "lensOffset"_a=ofVec2f(0.0f, 0.0f))
		.def("worldToCamera", &ofCamera::worldToCamera, "WorldXYZ"_a, "viewport"_a=ofRectangle())
		.def("worldToScreen", &ofCamera::worldToScreen, "WorldXYZ"_a, "viewport"_a=ofRectangle());
		// .def("setRenderer", &ofCamera::setRenderer)

	py::class_<ofEasyCam, ofCamera>(m,"ofEasyCam")
		.def(py::init<>())
		.def("begin"                       , &ofEasyCam::begin, "viewport"_a=ofRectangle())
		.def("disableMouseInput"           , &ofEasyCam::disableMouseInput)
		.def("enableMouseInput"            , &ofEasyCam::enableMouseInput)
		.def("disableMouseMiddleButton"    , &ofEasyCam::disableMouseMiddleButton)
		.def("enableMouseMiddleButton"     , &ofEasyCam::enableMouseMiddleButton)
		.def("getDistance"                 , &ofEasyCam::getDistance)
		.def("getDrag"                     , &ofEasyCam::getDrag)
		.def("getMouseInputEnabled"        , &ofEasyCam::getMouseInputEnabled)
		.def("getMouseMiddleButtonEnabled" , &ofEasyCam::getMouseMiddleButtonEnabled)
		.def("getTarget"                   , &ofEasyCam::getTarget)
		.def("getTranslationKey"           , &ofEasyCam::getTranslationKey)
		.def("reset"                       , &ofEasyCam::reset)
		.def("setAutoDistance"             , &ofEasyCam::setAutoDistance)
		.def("setDistance"                 , (void (ofEasyCam::*)(float)) &ofEasyCam::setDistance)
		.def("setDrag"                     , &ofEasyCam::setDrag)
		.def("setTranslationKey"           , &ofEasyCam::setTranslationKey)
		.def("setTarget"                   , (void (ofEasyCam::*)(const ofVec3f &))  &ofEasyCam::setTarget)
		.def("setTarget"                   , (void (ofEasyCam::*)(ofNode &))  &ofEasyCam::setTarget);
		
	m.def("ofDrawBox", (void (*)(float)) &ofDrawBox);
	m.def("ofDrawBox", (void (*)(const ofPoint&, float)) &ofDrawBox);
	m.def("ofDrawBox", (void (*)(const ofPoint&, float, float, float)) &ofDrawBox);
	m.def("ofDrawBox", (void (*)(float, float, float)) &ofDrawBox);
	m.def("ofDrawBox", (void (*)(float, float, float, float)) &ofDrawBox);
	m.def("ofDrawBox", (void (*)(float, float, float, float, float, float)) &ofDrawBox);
	m.def("ofDrawCone", (void (*)(float, float, float, float, float)) &ofDrawCone);
	m.def("ofDrawCone", (void (*)(float, float, float, float)) &ofDrawCone);
	m.def("ofDrawCone", (void (*)(const ofPoint&, float, float)) &ofDrawCone);
	m.def("ofDrawCone", (void (*)(float, float)) &ofDrawCone);
	m.def("ofDrawCylinder", (void (*)(float, float, float, float)) &ofDrawCone);
	m.def("ofDrawCylinder", (void (*)(float, float, float, float, float)) &ofDrawCone);
	m.def("ofDrawCylinder", (void (*)(const ofPoint&, float, float)) &ofDrawCone);
	m.def("ofDrawCylinder", (void (*)(float, float)) &ofDrawCylinder);
	m.def("ofDrawIcoSphere", (void (*)(float, float, float, float)) &ofDrawIcoSphere);
	m.def("ofDrawIcoSphere", (void (*)(float, float, float)) &ofDrawIcoSphere);
	m.def("ofDrawIcoSphere", (void (*)(const ofPoint&, float)) &ofDrawIcoSphere);
	m.def("ofDrawIcoSphere", (void (*)(float)) &ofDrawIcoSphere);
	m.def("ofDrawPlane", (void (*)(float, float, float, float)) &ofDrawPlane);
	m.def("ofDrawPlane", (void (*)(float, float, float, float, float)) &ofDrawPlane);
	m.def("ofDrawPlane", (void (*)(ofPoint&, float, float)) &ofDrawPlane);
	m.def("ofDrawPlane", (void (*)(float, float)) &ofDrawPlane);
	m.def("ofDrawSphere", (void (*)(float, float, float)) &ofDrawSphere);
	m.def("ofDrawSphere", (void (*)(float, float, float, float)) &ofDrawSphere);
	m.def("ofDrawSphere", (void (*)(const ofPoint&, float)) &ofDrawSphere);
	m.def("ofDrawSphere", (void (*)(float)) &ofDrawSphere);
	m.def("ofGetBoxResolution", &ofGetBoxResolution);
	m.def("ofGetConeResolution", &ofGetConeResolution);
	m.def("ofGetCylinderResolution", &ofGetCylinderResolution);
	m.def("ofGetIcoSphereResolution", &ofGetIcoSphereResolution);
	m.def("ofGetPlaneResolution", &ofGetPlaneResolution);
	m.def("ofGetSphereResolution", &ofGetSphereResolution);
	m.def("ofSetBoxResolution", (void (*)(int)) &ofSetBoxResolution);
	m.def("ofSetBoxResolution", (void (*)(int, int, int)) &ofSetBoxResolution);
	m.def("ofSetConeResolution",     &ofSetConeResolution,     "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2);
	m.def("ofSetCylinderResolution", &ofSetCylinderResolution, "radiusSegments"_a, "heightSegments"_a, "capSegments"_a=2);
	m.def("ofSetIcoSphereResolution", &ofSetIcoSphereResolution);
	m.def("ofSetPlaneResolution", &ofSetPlaneResolution);
	m.def("ofSetSphereResolution", &ofSetSphereResolution);

	m.def("ofDrawArrow", &ofDrawArrow, py::arg("start"), py::arg("end"), py::arg("headSize")=0.05f);
	m.def("ofDrawAxis", &ofDrawAxis);
	m.def("ofDrawGrid", &ofDrawGrid, py::arg("stepSize")=1.25f, py::arg("numberOfSteps"), py::arg("labels")=false, py::arg("x")=true, py::arg("y")=true, py::arg("z")=true);
	m.def("ofDrawGridPlane", &ofDrawGridPlane, py::arg("stepSize")=1.25f, py::arg("numberOfSteps"), py::arg("labels")=false);
	m.def("ofDrawRotationAxes", &ofDrawRotationAxes, py::arg("radius")=1.25f, py::arg("stripWidth"), py::arg("circleRes")=60);
}
