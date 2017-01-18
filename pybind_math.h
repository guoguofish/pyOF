#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
// #include "Python.h"
namespace py = pybind11;

//=========== class =============


// ======== Global function =========


void pybind_math(py::module &m) {
	py::class_<ofMatrix3x3>(m, "ofMatrix3x3")
		.def(py::init<float, float, float, float, float, float, float, float, float>())
		.def("transpose", (void (ofMatrix3x3::*)()) &ofMatrix3x3::transpose)
		.def("transpose", (ofMatrix3x3 (ofMatrix3x3::*)(const ofMatrix3x3& )) &ofMatrix3x3::transpose)
		.def("determinant", (float (ofMatrix3x3::*)() const) &ofMatrix3x3::determinant)
		.def("determinant", (float (ofMatrix3x3::*)(const ofMatrix3x3&)) &ofMatrix3x3::determinant)
		.def("entrywiseTimes", &ofMatrix3x3::entrywiseTimes)
		.def("inverse", &ofMatrix3x3::inverse)
		.def("invert", &ofMatrix3x3::invert)
		.def("set", (void (ofMatrix3x3::*)(float, float, float, float, float, float, float, float, float)) &ofMatrix3x3::set)
		.def_readwrite("a", &ofMatrix3x3::a)
		.def_readwrite("b", &ofMatrix3x3::b)
		.def_readwrite("c", &ofMatrix3x3::c)
		.def_readwrite("d", &ofMatrix3x3::d)
		.def_readwrite("e", &ofMatrix3x3::e)
		.def_readwrite("f", &ofMatrix3x3::f)
		.def_readwrite("g", &ofMatrix3x3::g)
		.def_readwrite("h", &ofMatrix3x3::h)
		.def_readwrite("i", &ofMatrix3x3::i)
		.def("__add__", [](const ofMatrix3x3 &A, const ofMatrix3x3 &B){
			ofMatrix3x3 result;
			result.a = A.a + B.a;
			result.b = A.b + B.b;
			result.c = A.c + B.c;
			result.d = A.d + B.d;
			result.e = A.e + B.e;
			result.f = A.f + B.f;
			result.g = A.g + B.g;
			result.h = A.h + B.h;
			result.i = A.i + B.i;
			return result;
		}, py::is_operator())
		.def("__iadd__", [](ofMatrix3x3 &A, const ofMatrix3x3 &B){
			A.a += B.a;
			A.b += B.b;
			A.c += B.c;
			A.d += B.d;
			A.e += B.e;
			A.f += B.f;
			A.g += B.g;
			A.h += B.h;
			A.i += B.i;
			return A;
		}, py::is_operator())
		.def("__sub__", [](const ofMatrix3x3 &A, const ofMatrix3x3 &B){
			ofMatrix3x3 result;
			result.a = A.a - B.a;
			result.b = A.b - B.b;
			result.c = A.c - B.c;
			result.d = A.d - B.d;
			result.e = A.e - B.e;
			result.f = A.f - B.f;
			result.g = A.g - B.g;
			result.h = A.h - B.h;
			result.i = A.i - B.i;
			return result;
		}, py::is_operator())
		.def("__isub__", [](ofMatrix3x3 &A, const ofMatrix3x3 &B){
			A.a -= B.a;
			A.b -= B.b;
			A.c -= B.c;
			A.d -= B.d;
			A.e -= B.e;
			A.f -= B.f;
			A.g -= B.g;
			A.h -= B.h;
			A.i -= B.i;
			return A;
		}, py::is_operator())
		.def("__mul__", [](const ofMatrix3x3 &A, const ofMatrix3x3 &B){
			ofMatrix3x3 C;
			C.a = A.a * B.a + A.b * B.d + A.c * B.g;
			C.b = A.a * B.b + A.b * B.e + A.c * B.h;
			C.c = A.a * B.c + A.b * B.f + A.c * B.i;
			C.d = A.d * B.a + A.e * B.d + A.f * B.g;
			C.e = A.d * B.b + A.e * B.e + A.f * B.h;
			C.f = A.d * B.c + A.e * B.f + A.f * B.i;
			C.g = A.g * B.a + A.h * B.d + A.i * B.g;
			C.h = A.g * B.b + A.h * B.e + A.i * B.h;
			C.i = A.g * B.c + A.h * B.f + A.i * B.i;
			return C;
		}, py::is_operator())
		.def("__imul__", [](ofMatrix3x3 &A, const ofMatrix3x3 &B){
			ofMatrix3x3 C;
			C.a = A.a * B.a + A.b * B.d + A.c * B.g;
			C.b = A.a * B.b + A.b * B.e + A.c * B.h;
			C.c = A.a * B.c + A.b * B.f + A.c * B.i;
			C.d = A.d * B.a + A.e * B.d + A.f * B.g;
			C.e = A.d * B.b + A.e * B.e + A.f * B.h;
			C.f = A.d * B.c + A.e * B.f + A.f * B.i;
			C.g = A.g * B.a + A.h * B.d + A.i * B.g;
			C.h = A.g * B.b + A.h * B.e + A.i * B.h;
			C.i = A.g * B.c + A.h * B.f + A.i * B.i;
			A.a = C.a;
			A.b = C.b;
			A.c = C.c;
			A.d = C.d;
			A.e = C.e;
			A.f = C.f;
			A.g = C.g;
			A.h = C.h;
			A.i = C.i;
			return A;
		}, py::is_operator())
		.def("__mul__", [](const ofMatrix3x3 &A, float scalar){
			ofMatrix3x3 result;
			result.a = A.a * scalar;
			result.b = A.b * scalar;
			result.c = A.c * scalar;
			result.d = A.d * scalar;
			result.e = A.e * scalar;
			result.f = A.f * scalar;
			result.g = A.g * scalar;
			result.h = A.h * scalar;
			result.i = A.i * scalar;
			return result;
		}, py::is_operator())
		.def("__imul__", [](ofMatrix3x3 &A, float scalar){
			A.a *= scalar;
			A.b *= scalar;
			A.c *= scalar;
			A.d *= scalar;
			A.e *= scalar;
			A.f *= scalar;
			A.g *= scalar;
			A.h *= scalar;
			A.i *= scalar;
			return A;
		}, py::is_operator())
		.def("__div__", [](const ofMatrix3x3 &A, float scalar){
			ofMatrix3x3 result;
			result.a = A.a / scalar;
			result.b = A.b / scalar;
			result.c = A.c / scalar;
			result.d = A.d / scalar;
			result.e = A.e / scalar;
			result.f = A.f / scalar;
			result.g = A.g / scalar;
			result.h = A.h / scalar;
			result.i = A.i / scalar;
			return result;
		}, py::is_operator())
		.def("__idiv__", [](ofMatrix3x3 &A, float scalar){
			A.a /= scalar;
			A.b /= scalar;
			A.c /= scalar;
			A.d /= scalar;
			A.e /= scalar;
			A.f /= scalar;
			A.g /= scalar;
			A.h /= scalar;
			A.i /= scalar;
			return A;
		}, py::is_operator())
		// .def(py::self + py::self)
		// .def(py::self -  py::self)
		// .def(py::self += py::self)
		// .def(py::self -= py::self)
		// .def(py::self *  float())
		// .def(py::self /  float())
		// .def(py::self *= float())
		// .def(py::self *  py::self)
		// .def(py::self *  py::self)
		// .def(py::self /  py::self)
		// .def(py::self /= py::self)
		.def("__str__", [](const ofMatrix3x3 &m) { 
				string tmp =  "[ "+std::to_string(m.a)+", " + std::to_string(m.b) +", "+ std::to_string(m.c) + " ]\n";
				tmp += "[ "+std::to_string(m.d)+", " + std::to_string(m.e) +", "+ std::to_string(m.f) + " ]\n";
				tmp += "[ "+std::to_string(m.g)+", " + std::to_string(m.h) +", "+ std::to_string(m.i) + " ]";
				return tmp;
			} 
		);

	py::class_<ofMatrix4x4>(m, "ofMatrix4x4", py::metaclass())
		.def(py::init<>())
		.def(py::init<const ofMatrix4x4&>())
		.def(py::init<float const * const>())
		.def(py::init<const ofQuaternion&>())
		.def(py::init<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>())
		.def("makeIdentityMatrix", &ofMatrix4x4::makeIdentityMatrix)
		.def("makeScaleMatrix", (void (ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::makeScaleMatrix)
		.def("makeScaleMatrix", (void (ofMatrix4x4::*)(float, float, float)) &ofMatrix4x4::makeScaleMatrix)
		.def("makeTranslationMatrix", (void (ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::makeTranslationMatrix)
		.def("makeTranslationMatrix", (void (ofMatrix4x4::*)(float, float, float)) &ofMatrix4x4::makeTranslationMatrix)
		.def("makeRotationMatrix", (void (ofMatrix4x4::*)(const ofVec3f&, const ofVec3f&)) &ofMatrix4x4::makeRotationMatrix)
		.def("makeRotationMatrix", (void (ofMatrix4x4::*)(float, const ofVec3f&)) &ofMatrix4x4::makeRotationMatrix)
		.def("makeRotationMatrix", (void (ofMatrix4x4::*)(float, float, float, float)) &ofMatrix4x4::makeRotationMatrix)
		.def("makeRotationMatrix", (void (ofMatrix4x4::*)(const ofQuaternion&)) &ofMatrix4x4::makeRotationMatrix)
		.def("makeRotationMatrix", (void (ofMatrix4x4::*)(float, const ofVec3f&, float, const ofVec3f&, float, const ofVec3f&)) &ofMatrix4x4::makeRotationMatrix)
		.def("makeInvertOf", &ofMatrix4x4::makeInvertOf)
		.def("makeOrthoNormalOf", &ofMatrix4x4::makeOrthoNormalOf)
		.def("makeFromMultiplicationOf", &ofMatrix4x4::makeFromMultiplicationOf)
		.def("makeOrthoMatrix",   &ofMatrix4x4::makeOrthoMatrix, "需要6个doble参数: left, right, bottom, top, zNear, zFar")
		.def("makeFrustumMatrix",   &ofMatrix4x4::makeFrustumMatrix, "需要6个doble参数: left, right, bottom, top, zNear, zFar")
		.def("makeOrtho2DMatrix", &ofMatrix4x4::makeOrtho2DMatrix, "需要4个doble参数: left, right, bottom, top")
		.def("makePerspectiveMatrix", &ofMatrix4x4::makePerspectiveMatrix, "需要4个doble参数: fovy, aspectRatio, zNear, zFar")
		.def("makeLookAtMatrix", &ofMatrix4x4::makeLookAtMatrix, "需要3个ofVec3f参数: eye, center, up")
		.def("makeLookAtViewMatrix", &ofMatrix4x4::makeLookAtViewMatrix, "需要3个ofVec3f参数: eye, center, up")
		.def_static("newIdentityMatrix", &ofMatrix4x4::newIdentityMatrix)
		.def("newScaleMatrix", [](const ofMatrix4x4 &m, const ofVec3f& v){ return m.newScaleMatrix(v.x, v.y, v.z );})
		.def("newScaleMatrix", [](const ofMatrix4x4 &m, float sx, float sy, float sz){return m.newScaleMatrix(sx, sy, sz);})
		.def("newTranslationMatrix", [](const ofMatrix4x4 &m, const ofVec3f& v){ return m.newTranslationMatrix(v.x, v.y, v.z ); })
		.def("newTranslationMatrix", [](const ofMatrix4x4 &m, float tx, float ty, float tz){return m.newTranslationMatrix(tx, ty, tz);})
		.def("newRotationMatrix", [](const ofMatrix4x4 &m, const ofQuaternion& q) { return m.newRotationMatrix(q);})
		.def("newRotationMatrix", [](const ofMatrix4x4 &m, const ofVec3f& from, const ofVec3f& to) {return m.newRotationMatrix(from, to);})
		.def("newRotationMatrix", [](const ofMatrix4x4 &m, float angle, const ofVec3f& axis) {return m.newRotationMatrix(angle, axis);})
		.def("newRotationMatrix", [](const ofMatrix4x4 &m, float angle, float x, float y, float z) {})
		.def("newRotationMatrix", [](const ofMatrix4x4 &m, float angle1, const ofVec3f& axis1, float angle2, const ofVec3f& axis2, float angle3, const ofVec3f& axis3) {return m.newRotationMatrix(angle1, axis1, angle2, axis2, angle3, axis3);})
		.def_static("newOrthoMatrix", &ofMatrix4x4::newOrthoMatrix, "需要6个doble参数: left, right, bottom, top, zNear, zFar")
		.def_static("newFrustumMatrix", &ofMatrix4x4::newFrustumMatrix, "需要6个doble参数: left, right, bottom, top, zNear, zFar")
		.def_static("newOrtho2DMatrix", &ofMatrix4x4::newOrtho2DMatrix, "需要4个doble参数: left, right, bottom, top")
		.def_static("newPerspectiveMatrix", &ofMatrix4x4::newPerspectiveMatrix, "需要4个doble参数: fovy, aspectRatio, zNear, zFar")
		.def_static("newLookAtMatrix", &ofMatrix4x4::newLookAtMatrix, "需要3个ofVec3f参数: eye, center, up")
		.def("getRowAsVec3f", &ofMatrix4x4::getRowAsVec3f)
		.def("getRowAsVec4f", &ofMatrix4x4::getRowAsVec4f)
		// .def("getPtr", (      float* (ofMatrix4x4::*)()) &ofMatrix4x4::getPtr, py::return_value_policy::reference)
		// .def("getPtr", (const float* (ofMatrix4x4::*)()) &ofMatrix4x4::getPtr, py::return_value_policy::reference)
		.def("__str__", [](const ofMatrix4x4 &m) { 
				string tmp =  "[ "+std::to_string(m._mat[0].x)+", " + std::to_string(m._mat[0].y) +", "+ std::to_string(m._mat[0].z) +", "+ std::to_string(m._mat[0].w) +" ]\n";
				tmp += "[ "+std::to_string(m._mat[1].x)+", " + std::to_string(m._mat[1].y) +", "+ std::to_string(m._mat[1].z) +", "+ std::to_string(m._mat[1].w) +" ]\n";
				tmp += "[ "+std::to_string(m._mat[2].x)+", " + std::to_string(m._mat[2].y) +", "+ std::to_string(m._mat[2].z) +", "+ std::to_string(m._mat[2].w) +" ]\n";
				tmp += "[ "+std::to_string(m._mat[3].x)+", " + std::to_string(m._mat[3].y) +", "+ std::to_string(m._mat[3].z) +", "+ std::to_string(m._mat[3].w) +" ]";
				return tmp;
			} 
		);


	py::class_<ofVec2f>(m, "ofVec2f")
		.def(py::init<>())
		.def(py::init<float>())
		.def(py::init<float, float>())
		.def(py::init<const ofVec3f&>())
		.def(py::init<const ofVec4f&>())
		.def("set",(void (ofVec2f::*)(float, float)) &ofVec2f::set)
		.def("set",(void (ofVec2f::*)(float))        &ofVec2f::set)
		.def("set",(void (ofVec2f::*)(const ofVec2f &)) &ofVec2f::set)
		.def("match",            &ofVec2f::match)
		.def("isAligned",        &ofVec2f::isAligned)
		.def("isAlignedRad",     &ofVec2f::isAlignedRad)
		.def("align",            &ofVec2f::align)
		.def("alignRad",         &ofVec2f::alignRad)
		.def("average",          &ofVec2f::average)
		.def("distance",         &ofVec2f::distance)
		.def("getScaled",        &ofVec2f::getScaled)
		.def("scale",            &ofVec2f::scale)
		.def("getMapped",        &ofVec2f::getMapped)
		.def("map",              &ofVec2f::map)
		.def("squareDistance",   &ofVec2f::squareDistance)
		.def("interpolate",      &ofVec2f::interpolate)
		.def("getInterpolated",  &ofVec2f::getInterpolated)
		.def("middle",           &ofVec2f::middle)
		.def("getMiddle",        &ofVec2f::getMiddle)
		.def("getNormalized",    &ofVec2f::getNormalized)
		.def("normalize",        &ofVec2f::normalize)
		.def("getLimited",       &ofVec2f::getLimited)
		.def("limit",            &ofVec2f::limit)
		.def("length",           &ofVec2f::length)
		.def("lengthSquared",    &ofVec2f::lengthSquared)
		.def("angle",            &ofVec2f::angle)
		.def("angleRad",         &ofVec2f::angleRad)
		.def("perpendicular",    &ofVec2f::perpendicular)
		.def("getPerpendicular", &ofVec2f::getPerpendicular)
		// .def("getCrossed",       &ofVec2f::getCrossed)
		// .def("cross",            &ofVec2f::cross)
		.def("dot",              &ofVec2f::dot)
		.def("zero",             &ofVec2f::zero)
		.def("one",              &ofVec2f::one)
		.def("getRotated",    (ofVec2f (ofVec2f::*)(float) const) &ofVec2f::getRotated)
		.def("getRotated",    (ofVec2f (ofVec2f::*)(float, const ofVec2f&) const) &ofVec2f::getRotated)
		.def("getRotatedRad",    (ofVec2f (ofVec2f::*)(float) const) &ofVec2f::getRotatedRad)
		.def("getRotatedRad",    (ofVec2f (ofVec2f::*)(float, const ofVec2f&) const) &ofVec2f::getRotatedRad)
		.def("rotate",    (ofVec2f& (ofVec2f::*)(float)) &ofVec2f::rotate)
		.def("rotate",    (ofVec2f& (ofVec2f::*)(float, const ofVec2f&)) &ofVec2f::rotate)
		.def("rotateRad",    (ofVec2f& (ofVec2f::*)(float)) &ofVec2f::rotateRad)
		.def("rotateRad",    (ofVec2f& (ofVec2f::*)(float, const ofVec2f&)) &ofVec2f::rotateRad)
		.def_readwrite("x", &ofVec2f::x)
		.def_readwrite("y", &ofVec2f::y)
		.def(py::self +  py::self)
		.def(py::self +  float())
		.def(py::self += py::self)
		.def(py::self += float())
		.def(py::self -  py::self)
		.def(py::self -  float())
		.def(py::self -= py::self)
		.def(py::self -= float())
		.def(py::self *  py::self)
		.def(py::self *  float())
		.def(py::self *= py::self)
		.def(py::self *= float())
		.def(py::self /  py::self)
		.def(py::self /= py::self)
		.def(py::self /  float())
		.def(py::self /= float())
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(float()  +  py::self)
		.def(float()  -  py::self)
		.def(float()  *  py::self)
		.def(float()  /  py::self)
		.def("__neg__", [](const  ofVec2f &v ){
			ofVec2f vv(-v.x, -v.y);
			return vv;
		}, py::is_operator())
		.def("__str__", [](const ofVec2f &v) { return "["+std::to_string(v.x)+", " + std::to_string(v.y) + "]";} );

	py::class_<ofVec3f>(m, "ofVec3f")
		.def(py::init<>())
		.def(py::init<const ofVec2f &>())
		.def(py::init<const ofVec4f &>())
		.def(py::init<float>())
		.def(py::init<float,float,float>())
		.def("set",(void (ofVec3f::*)(float, float, float)) &ofVec3f::set)
		.def("set",(void (ofVec3f::*)(float))           &ofVec3f::set)
		.def("set",(void (ofVec3f::*)(const ofVec3f &)) &ofVec3f::set)
		.def("match",            &ofVec3f::match)
		.def("isAligned",        &ofVec3f::isAligned)
		.def("isAlignedRad",     &ofVec3f::isAlignedRad)
		.def("align",            &ofVec3f::align)
		.def("alignRad",         &ofVec3f::alignRad)
		.def("average",          &ofVec3f::average)
		.def("distance",         &ofVec3f::distance)
		.def("getScaled",        &ofVec3f::getScaled)
		.def("scale",            &ofVec3f::scale)
		.def("getMapped",        &ofVec3f::getMapped)
		.def("map",              &ofVec3f::map)
		.def("squareDistance",   &ofVec3f::squareDistance)
		.def("interpolate",      &ofVec3f::interpolate)
		.def("getInterpolated",  &ofVec3f::getInterpolated)
		.def("middle",           &ofVec3f::middle)
		.def("getMiddle",        &ofVec3f::getMiddle)
		.def("getNormalized",    &ofVec3f::getNormalized)
		.def("normalize",        &ofVec3f::normalize)
		.def("getLimited",       &ofVec3f::getLimited)
		.def("limit",            &ofVec3f::limit)
		.def("length",           &ofVec3f::length)
		.def("lengthSquared",    &ofVec3f::lengthSquared)
		.def("angle",            &ofVec3f::angle)
		.def("angleRad",         &ofVec3f::angleRad)
		.def("perpendicular",    &ofVec3f::perpendicular)
		.def("getPerpendicular", &ofVec3f::getPerpendicular)
		.def("getCrossed",       &ofVec3f::getCrossed)
		.def("cross",            &ofVec3f::cross)
		.def("dot",              &ofVec3f::dot)
		.def("zero",             &ofVec3f::zero)
		.def("one",              &ofVec3f::one)
		.def("getRotated",    (ofVec3f (ofVec3f::*)(float, float, float) const) &ofVec3f::getRotated)
		.def("getRotated",    (ofVec3f (ofVec3f::*)(float, const ofVec3f &) const) &ofVec3f::getRotated)
		.def("getRotated",    (ofVec3f (ofVec3f::*)(float, const ofVec3f &, const ofVec3f &) const) &ofVec3f::getRotated)
		.def("getRotatedRad", (ofVec3f (ofVec3f::*)(float, float, float) const) &ofVec3f::getRotatedRad)
		.def("getRotatedRad", (ofVec3f (ofVec3f::*)(float, const ofVec3f &) const) &ofVec3f::getRotatedRad)
		.def("getRotatedRad", (ofVec3f (ofVec3f::*)(float, const ofVec3f &, const ofVec3f &) const) &ofVec3f::getRotatedRad)
		.def("rotate",        (ofVec3f& (ofVec3f::*)(float, float, float))                     &ofVec3f::rotate)
		.def("rotate",        (ofVec3f& (ofVec3f::*)(float, const ofVec3f &))                  &ofVec3f::rotate)
		.def("rotate",        (ofVec3f& (ofVec3f::*)(float, const ofVec3f &, const ofVec3f &)) &ofVec3f::rotate)
		.def("rotateRad",     (ofVec3f& (ofVec3f::*)(float, float, float))                     &ofVec3f::rotateRad)
		.def("rotateRad",     (ofVec3f& (ofVec3f::*)(float, const ofVec3f &))                  &ofVec3f::rotateRad)
		.def("rotateRad",     (ofVec3f& (ofVec3f::*)(float, const ofVec3f &, const ofVec3f &)) &ofVec3f::rotateRad)
		.def_readwrite("x", &ofVec3f::x)
		.def_readwrite("y", &ofVec3f::y)
		.def_readwrite("z", &ofVec3f::z)
		.def(py::self +  py::self)
		.def(py::self +  float())
		.def(py::self += py::self)
		.def(py::self += float())
		.def(py::self -  py::self)
		.def(py::self -  float())
		.def(py::self -= py::self)
		.def(py::self -= float())
		.def(py::self *  py::self)
		.def(py::self *  float())
		.def(py::self *= py::self)
		.def(py::self *= float())
		.def(py::self /  py::self)
		.def(py::self /= py::self)
		.def(py::self /  float())
		.def(py::self /= float())
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(float()  +  py::self)
		.def(float()  -  py::self)
		.def(float()  *  py::self)
		.def(float()  /  py::self)
		.def("__neg__", [](const  ofVec3f &v ){
			ofVec3f vv(-v.x, -v.y, -v.z);
			return vv;
		}, py::is_operator())
		.def("__str__", [](const ofVec3f &v) { return "["+std::to_string(v.x)+", "+std::to_string(v.y)+", "+std::to_string(v.z)+"]" ;} );

	py::class_<ofVec4f>(m, "ofVec4f")
		.def(py::init<>())
		.def(py::init<float, float, float, float>())
		.def(py::init<const ofVec2f&>())
		.def(py::init<const ofVec3f&>())
		.def("set",(void (ofVec4f::*)(float)) &ofVec4f::set)
		.def("set",(void (ofVec4f::*)(float, float, float, float)) &ofVec4f::set)
		.def("set",(void (ofVec4f::*)(const ofVec4f&)) &ofVec4f::set)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(py::self + py::self)
		.def(py::self - py::self)
		.def(py::self * py::self)
		.def(py::self / py::self)
		.def(py::self += py::self)
		.def(py::self -= py::self)
		.def(py::self *= py::self)
		.def(py::self /= py::self)
		.def(py::self + float())
		.def(py::self - float())
		.def(py::self * float())
		.def(py::self / float())
		.def(py::self += float())
		.def(py::self -= float())
		.def(py::self *= float())
		.def(py::self /= float())
		.def(float()  +  py::self)
		.def(float()  -  py::self)
		.def(float()  *  py::self)
		.def(float()  /  py::self)
		.def("__neg__", [](const  ofVec4f &v ) {
			ofVec4f vv(-v.x, -v.y, -v.z, -v.w);
			return vv;
		}, py::is_operator())
		.def("match",           &ofVec4f::match)
		.def("getScaled",       &ofVec4f::getScaled)
		.def("scale",           &ofVec4f::scale)
		.def("distance",        &ofVec4f::distance)
		.def("getInterpolated", &ofVec4f::getInterpolated)
		.def("interpolate",     &ofVec4f::interpolate)
		.def("getMiddle",       &ofVec4f::getMiddle)
		.def("middle",          &ofVec4f::middle)
		.def("getNormalized",   &ofVec4f::getNormalized)
		.def("normalize",       &ofVec4f::normalize)
		.def("average",         &ofVec4f::average)
		.def("getLimited",      &ofVec4f::getLimited)
		.def("limit",           &ofVec4f::limit)
		.def("length",          &ofVec4f::length)
		.def("lengthSquared",   &ofVec4f::lengthSquared)
		.def("dot",             &ofVec4f::dot)
		.def("zero",            &ofVec4f::zero)
		.def("one",             &ofVec4f::one)
		.def_readwrite("x", &ofVec4f::x)
		.def_readwrite("y", &ofVec4f::y)
		.def_readwrite("z", &ofVec4f::z)
		.def_readwrite("w", &ofVec4f::w)
		.def("__str__", [](const ofVec4f &v) { return "["+std::to_string(v.x)+", "+std::to_string(v.y)+", "+std::to_string(v.z)+", "+std::to_string(v.w)+"]" ;} );

	py::class_<ofQuaternion>(m, "ofQuaternion")
		.def(py::init<>())
		.def(py::init<float, float, float, float>())
		.def(py::init<const ofVec4f&>())
		.def(py::init<float, const ofVec3f&>())
		.def(py::init<float, const ofVec3f&, float, const ofVec3f&, float, const ofVec3f&>())
		.def("set", (void (ofQuaternion::*)(float, float, float, float)) &ofQuaternion::set)
		.def("set", (void (ofQuaternion::*)(const ofVec4f&)) &ofQuaternion::set)
		.def("set", (void (ofQuaternion::*)(const ofMatrix4x4&)) &ofQuaternion::set)
		.def("get", &ofQuaternion::get)
		.def("asVec4", &ofQuaternion::asVec4)
		.def("asVec3", &ofQuaternion::asVec3)
		.def("zeroRotation", &ofQuaternion::zeroRotation)
		.def("length", &ofQuaternion::length)
		.def("length2", &ofQuaternion::length2)
		.def("conj", &ofQuaternion::conj)
		.def("inverse", &ofQuaternion::inverse)
		.def("makeRotate", (void (ofQuaternion::*)(float, float, float, float)) &ofQuaternion::makeRotate)
		.def("makeRotate", (void (ofQuaternion::*)(float, const ofVec3f&)) &ofQuaternion::makeRotate)
		.def("makeRotate", (void (ofQuaternion::*)(float, const ofVec3f&, float, const ofVec3f&, float, const ofVec3f&)) &ofQuaternion::makeRotate)
		.def("makeRotate", (void (ofQuaternion::*)(const ofVec3f&, const ofVec3f&)) &ofQuaternion::makeRotate)
		.def("makeRotate_original", &ofQuaternion::makeRotate_original)
		.def("getRotate", (void (ofQuaternion::*)(float&, float&, float&, float&) const) &ofQuaternion::getRotate)
		.def("getRotate", (void (ofQuaternion::*)(float&, ofVec3f&) const) &ofQuaternion::getRotate)
		.def("getEuler", &ofQuaternion::getEuler)
		.def("slerp", &ofQuaternion::slerp)
		.def("normalize", &ofQuaternion::normalize)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(py::self + py::self)
		.def(py::self - py::self)
		.def(py::self += py::self)
		.def(py::self -= py::self)
		.def(py::self *  py::self)
		.def(py::self *= py::self)
		.def(py::self /  py::self)
		.def(py::self /= py::self)
		.def(py::self *  float())
		.def(py::self /  float())
		.def(py::self *= float())
		.def(py::self * ofVec3f())
		.def_property("x", (float (ofQuaternion::*)() const) &ofQuaternion::x, [](ofQuaternion& Q, float val){ Q._v.x=val; })
		.def_property("y", (float (ofQuaternion::*)() const) &ofQuaternion::y, [](ofQuaternion& Q, float val){ Q._v.y=val; })
		.def_property("z", (float (ofQuaternion::*)() const) &ofQuaternion::z, [](ofQuaternion& Q, float val){ Q._v.z=val; })
		.def_property("w", (float (ofQuaternion::*)() const) &ofQuaternion::w, [](ofQuaternion& Q, float val){ Q._v.w=val; })
		.def("__str__", [](const ofQuaternion &Q) { return "["+std::to_string(Q._v.x)+", "+std::to_string(Q._v.y)+", "+std::to_string(Q._v.z)+", "+std::to_string(Q._v.w)+"]" ;} );

	m.attr("ofPoint") = m.attr("ofVec3f");
	m.def("ofMap", &ofMap);
	m.def("ofNextPow2", &ofNextPow2);
	m.def("ofSeedRandom", (void (*)()) &ofSeedRandom);
	m.def("ofSeedRandom", (void (*)(int)) &ofSeedRandom);
	m.def("ofRandom", (float (*)(float)) &ofRandom);
	m.def("ofRandom", (float (*)(float, float)) &ofRandom);
	m.def("ofRandomf",   &ofRandomf);
	m.def("ofRandomuf",  &ofRandomuf);
	m.def("ofNormalize", &ofNormalize);
	m.def("ofClamp",     &ofClamp);
	m.def("ofSign",      &ofSign);
	m.def("ofInRange",   &ofInRange);
	m.def("ofRadToDeg",  &ofRadToDeg);
	m.def("ofDegToRad",  &ofDegToRad);
	m.def("ofLerp",      &ofLerp);
	m.def("ofWrap",      &ofWrap);
	m.def("ofWrapRadians",  &ofWrapRadians);
	m.def("ofWrapDegrees",  &ofWrapDegrees);
	m.def("ofLerpDegrees",  &ofLerpDegrees);
	m.def("ofLerpRadians",  &ofLerpRadians);
	m.def("ofDist", (float (*)(float, float, float, float)) &ofDist);
	m.def("ofDist", (float (*)(float, float, float, float, float, float)) &ofDist);
	m.def("ofDistSquared", (float (*)(float, float, float, float)) &ofDistSquared);
	m.def("ofDistSquared", (float (*)(float, float, float, float, float, float)) &ofDistSquared);
	m.def("ofNoise", (float (*)(float)) &ofNoise);
	m.def("ofNoise", (float (*)(float, float)) &ofNoise);
	m.def("ofNoise", (float (*)(float, float, float)) &ofNoise);
	m.def("ofNoise", (float (*)(float, float, float, float)) &ofNoise);
	m.def("ofNoise", (float (*)(const ofVec2f&)) &ofNoise);
	m.def("ofNoise", (float (*)(const ofVec3f&)) &ofNoise);
	m.def("ofNoise", (float (*)(const ofVec4f&)) &ofNoise);
	m.def("ofSignedNoise", (float (*)(float)) &ofSignedNoise);
	m.def("ofSignedNoise", (float (*)(float, float)) &ofSignedNoise);
	m.def("ofSignedNoise", (float (*)(float, float, float)) &ofSignedNoise);
	m.def("ofSignedNoise", (float (*)(float, float, float, float)) &ofSignedNoise);
	m.def("ofSignedNoise", (float (*)(const ofVec2f&)) &ofSignedNoise);
	m.def("ofSignedNoise", (float (*)(const ofVec3f&)) &ofSignedNoise);
	m.def("ofSignedNoise", (float (*)(const ofVec4f&)) &ofSignedNoise);
	m.def("ofInsidePoly", (bool (*)(float, float,   const vector<ofPoint>&)) &ofInsidePoly);
	m.def("ofInsidePoly", (bool (*)(const ofPoint&, const vector<ofPoint>&)) &ofInsidePoly);
	m.def("ofLineSegmentIntersection", &ofLineSegmentIntersection);
	m.def("ofBezierPoint",             &ofBezierPoint);
	m.def("ofCurvePoint",              &ofCurvePoint);
	m.def("ofBezierTangent",           &ofBezierTangent);
	m.def("ofCurveTangent",            &ofCurveTangent);
	m.def("ofAngleDifferenceDegrees",  &ofAngleDifferenceDegrees);
	m.def("ofAngleDifferenceRadians",  &ofAngleDifferenceRadians);


}