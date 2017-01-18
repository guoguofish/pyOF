#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;

void pybind_gl(py::module &m) {
    using namespace py::literals;

    m.def("ofGetUsingArbTex",               &ofGetUsingArbTex);
    m.def("ofEnableArbTex",                 &ofEnableArbTex);
    m.def("ofDisableArbTex",                &ofDisableArbTex);
    m.def("ofGetUsingNormalizedTexCoords",  &ofGetUsingNormalizedTexCoords);
    m.def("ofEnableNormalizedTexCoords",    &ofEnableNormalizedTexCoords);
    m.def("ofDisableNormalizedTexCoords",   &ofDisableNormalizedTexCoords);
    m.def("ofEnableLighting",               &ofEnableLighting);
    m.def("ofDisableLighting",              &ofDisableLighting);
    m.def("ofEnableSeparateSpecularLight",  &ofEnableSeparateSpecularLight);
    m.def("ofDisableSeparateSpecularLight", &ofDisableSeparateSpecularLight);
    m.def("ofGetLightingEnabled",           &ofGetLightingEnabled);
    m.def("ofSetSmoothLighting",            &ofSetSmoothLighting);
    m.def("ofSetGlobalAmbientColor",        &ofSetGlobalAmbientColor);
    m.def("ofGetGlobalAmbientColor",        &ofGetGlobalAmbientColor);

    py::class_<ofLight, ofNode> mlight(m, "ofLight");
    py::class_<ofLight::Data>(mlight, "Data")
        .def(py::init<>())
        .def_readwrite("ambientColor",          &ofLight::Data::ambientColor)
        .def_readwrite("diffuseColor",          &ofLight::Data::diffuseColor)
        .def_readwrite("specularColor",         &ofLight::Data::specularColor)
        .def_readwrite("attenuation_constant",  &ofLight::Data::attenuation_constant)
        .def_readwrite("attenuation_linear",    &ofLight::Data::attenuation_linear)
        .def_readwrite("attenuation_quadratic", &ofLight::Data::attenuation_quadratic)
        .def_readwrite("lightType",             &ofLight::Data::lightType)
        .def_readwrite("glIndex",               &ofLight::Data::glIndex)
        .def_readwrite("isEnabled",             &ofLight::Data::isEnabled)
        .def_readwrite("spotCutOff",            &ofLight::Data::spotCutOff)
        .def_readwrite("exponent",              &ofLight::Data::exponent)
        .def_readwrite("position",              &ofLight::Data::position)
        .def_readwrite("direction",             &ofLight::Data::direction)
        .def_readwrite("width",                 &ofLight::Data::width)
        .def_readwrite("height",                &ofLight::Data::height)
        .def_readwrite("up",                    &ofLight::Data::up)
        .def_readwrite("right",                 &ofLight::Data::right);
    mlight.def(py::init<>())
        .def("setup",                   &ofLight::setup)
        .def("enable",                  &ofLight::enable)
        .def("disable",                 &ofLight::disable)
        .def("getIsEnabled",            &ofLight::getIsEnabled)
        .def("setDirectional",          &ofLight::setDirectional)
        .def("getIsDirectional",        &ofLight::getIsDirectional)
        .def("setSpotlight",            &ofLight::setSpotlight, "spotCutOff"_a=45.f, "exponent"_a=0.f)
        .def("getIsSpotlight",          &ofLight::getIsSpotlight)
        .def("setSpotlightCutOff",      &ofLight::setSpotlightCutOff)
        .def("getSpotlightCutOff",      &ofLight::getSpotlightCutOff)
        .def("setSpotConcentration",    &ofLight::setSpotConcentration)
        .def("getSpotConcentration",    &ofLight::getSpotConcentration)
        .def("setPointLight",           &ofLight::setPointLight)
        .def("getIsPointLight",         &ofLight::getIsPointLight)
        .def("setAttenuation",          &ofLight::setAttenuation, "constant"_a=1.f, "linear"_a=0.f, "quadratic"_a=0.f)
        .def("getAttenuationConstant",  &ofLight::getAttenuationConstant)
        .def("getAttenuationLinear",    &ofLight::getAttenuationLinear)
        .def("getAttenuationQuadratic", &ofLight::getAttenuationQuadratic)
        .def("setAreaLight",            &ofLight::setAreaLight)
        .def("getIsAreaLight",          &ofLight::getIsAreaLight)
        .def("getType",                 &ofLight::getType)
        .def("setAmbientColor",         &ofLight::setAmbientColor)
        .def("setDiffuseColor",         &ofLight::setDiffuseColor)
        .def("setSpecularColor",        &ofLight::setSpecularColor)
        .def("getAmbientColor",         &ofLight::getAmbientColor)
        .def("getDiffuseColor",         &ofLight::getDiffuseColor)
        .def("getSpecularColor",        &ofLight::getSpecularColor)
        .def("getLightID",              &ofLight::getLightID);
        
    m.def("ofLightsData", &ofLightsData);

    py::class_<ofTextureData>(m, "ofTextureData")
        .def(py::init<>())
        .def_readwrite("textureID", &ofTextureData::textureID)
        .def_readwrite("glInternalFormat", &ofTextureData::glInternalFormat)
        .def_readwrite("textureTarget",    &ofTextureData::textureTarget)
        .def_readwrite("tex_t",    &ofTextureData::tex_t)
        .def_readwrite("tex_u",    &ofTextureData::tex_u)
        .def_readwrite("tex_w",    &ofTextureData::tex_w)
        .def_readwrite("tex_h",    &ofTextureData::tex_h)
        .def_readwrite("width",    &ofTextureData::width)
        .def_readwrite("height",   &ofTextureData::height)
        .def_readwrite("bFlipTexture",    &ofTextureData::bFlipTexture)
        .def_readwrite("compressionType", &ofTextureData::compressionType)
        .def_readwrite("bAllocated",  &ofTextureData::bAllocated)
        .def_readwrite("minFilter",   &ofTextureData::minFilter)
        .def_readwrite("magFilter",   &ofTextureData::magFilter)
        .def_readwrite("wrapModeHorizontal", &ofTextureData::wrapModeHorizontal)
        .def_readwrite("wrapModeVertical",   &ofTextureData::wrapModeVertical)
        .def_readwrite("bufferId",   &ofTextureData::bufferId);

    py::class_<ofTexture>(m, "ofTexture")
        .def(py::init<>())
        .def(py::init<const ofTexture&>())
        .def("allocate", (void (ofTexture::*) (const ofTextureData &)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (const ofTextureData &, int, int)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (int, int, int)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (int, int, int, int, int)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (int, int, int, bool)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (int, int, int, bool, int, int)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (const ofPixels &)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (const ofShortPixels &)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (const ofFloatPixels &)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (const ofPixels &, bool)) &ofTexture::allocate)
        .def("allocate", (void (ofTexture::*) (const ofFloatPixels &, bool)) &ofTexture::allocate)
        #ifndef TARGET_OPENGLES
        .def("allocateAsBufferTexture", (void (ofTexture::*) (const ofBufferObject &, int)) &ofTexture::allocateAsBufferTexture)
        #endif
        .def("isAllocated", &ofTexture::isAllocated)
        .def("clear", &ofTexture::clear)
        .def("setUseExternalTextureID", &ofTexture::setUseExternalTextureID)
        .def("loadData", (void (ofTexture::*) (const unsigned char*const,int,int,int)) &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const unsigned short*,int,int,int))     &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const float*,int,int,int))              &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const ofPixels &))           &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const ofPixels&, int))       &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const ofShortPixels &))      &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const ofShortPixels &, int)) &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const ofFloatPixels &))      &ofTexture::loadData)
        .def("loadData", (void (ofTexture::*) (const ofFloatPixels &, int)) &ofTexture::loadData)
        #ifndef TARGET_OPENGLES
        .def("loadData", (void (ofTexture::*) (const ofBufferObject &, int, int)) &ofTexture::loadData)
        #endif
        .def("loadScreenData", &ofTexture::loadScreenData)
        .def("draw", (void (ofTexture::*) (float, float, float, float, float) const) &ofTexture::draw)
        .def("draw", (void (ofTexture::*) (const ofPoint &, const ofPoint &, const ofPoint &, const ofPoint &) const) &ofTexture::draw)
        .def("drawSubsection", (void (ofTexture::*) (float, float, float, float, float, float) const) &ofTexture::drawSubsection)
        .def("drawSubsection", (void (ofTexture::*) (float, float, float, float, float, float, float) const) &ofTexture::drawSubsection)
        .def("drawSubsection", (void (ofTexture::*) (float, float, float, float, float, float, float, float) const) &ofTexture::drawSubsection)
        .def("drawSubsection", (void (ofTexture::*) (float, float, float, float, float, float, float, float, float) const) &ofTexture::drawSubsection)
        .def("getQuad", (void (ofTexture::*) (const ofPoint &, const ofPoint &, const ofPoint &, const ofPoint &) const) &ofTexture::getQuad)
        .def("getMeshForSubsection", &ofTexture::getMeshForSubsection)
        .def("bind",   &ofTexture::bind,   "textureLocation"_a=0)
        .def("unbind", &ofTexture::unbind, "textureLocation"_a=0)
        #if !defined(TARGET_OPENGLES) && defined(glBindImageTexture)
        .def("bindAsImage", &ofTexture::bindAsImage, "unit"_a, "access"_a, "level"_a=0, "layered"_a=0, "layer"_a=0)
        #endif
        .def("getAlphaMask",           &ofTexture::getAlphaMask)
        .def("getHeight",              &ofTexture::getHeight)
        .def("getWidth",               &ofTexture::getWidth)
        .def("setAnchorPercent",       &ofTexture::setAnchorPercent)
        .def("setAnchorPoint",         &ofTexture::setAnchorPoint)
        .def("resetAnchor",            &ofTexture::resetAnchor)
        .def("getCoordFromPoint",      &ofTexture::getCoordFromPoint)
        .def("getCoordFromPercent",    &ofTexture::getCoordFromPercent)
        .def("setAlphaMask",           &ofTexture::setAlphaMask)
        .def("disableAlphaMask",       &ofTexture::disableAlphaMask)
        .def("setTextureWrap",         &ofTexture::setTextureWrap)
        .def("setTextureMinMagFilter", &ofTexture::setTextureMinMagFilter)
        .def("setTextureMatrix",       &ofTexture::setTextureMatrix)
        .def("getTextureMatrix",       &ofTexture::getTextureMatrix)
        .def("isUsingTextureMatrix",   &ofTexture::isUsingTextureMatrix)
        .def("disableTextureMatrix",   &ofTexture::disableTextureMatrix)
        .def("setCompression",         &ofTexture::setCompression)
        .def("setRGToRGBASwizzles",    &ofTexture::setRGToRGBASwizzles)
        .def("setSwizzle",             &ofTexture::setSwizzle)
        .def("readToPixels", (void (ofTexture::*)(ofPixels &) const) &ofTexture::readToPixels)
        .def("readToPixels", (void (ofTexture::*)(ofShortPixels &) const) &ofTexture::readToPixels)
        .def("readToPixels", (void (ofTexture::*)(ofFloatPixels &) const) &ofTexture::readToPixels)
        #ifndef TARGET_OPENGLES
        .def("copyTo", &ofTexture::copyTo, "copyTo( ofBufferObject )")
        #endif
        .def("getTextureData", (ofTextureData& (ofTexture::*)()) &ofTexture::getTextureData)
        .def("enableMipmap", &ofTexture::enableMipmap)
        .def("disableMipmap", &ofTexture::disableMipmap)
        .def("generateMipmap", &ofTexture::generateMipmap)
        .def("hasMipmap", &ofTexture::hasMipmap);

    py::class_<ofShader> mshader(m, "ofShader");
    py::enum_<ofShader::defaultAttributes>(mshader, "defaultAttributes")
        .value("POSITION_ATTRIBUTE", ofShader::defaultAttributes::POSITION_ATTRIBUTE)
        .value("COLOR_ATTRIBUTE",    ofShader::defaultAttributes::COLOR_ATTRIBUTE)
        .value("NORMAL_ATTRIBUTE",   ofShader::defaultAttributes::NORMAL_ATTRIBUTE)
        .value("TEXCOORD_ATTRIBUTE", ofShader::defaultAttributes::TEXCOORD_ATTRIBUTE)
        .value("INDEX_ATTRIBUTE",    ofShader::defaultAttributes::INDEX_ATTRIBUTE);
    mshader.def(py::init<>())
        .def(py::init<const ofShader &>())
        .def("load", (bool (ofShader::*)(string)) &ofShader::load)
        .def("load", (bool (ofShader::*)(string, string, string)) &ofShader::load, "vertName"_a, "fragName"_a, ""_a="")
        .def("setGeometryInputType", &ofShader::setGeometryInputType)
        .def("setGeometryOutputType", &ofShader::setGeometryOutputType)
        .def("setGeometryOutputCount", &ofShader::setGeometryOutputCount)
        .def("getGeometryMaxOutputCount", &ofShader::getGeometryMaxOutputCount)
        .def("unload", &ofShader::unload)
        .def("isLoaded", &ofShader::isLoaded)
        .def("begin", &ofShader::begin)
        .def("end", &ofShader::end)
        #if !defined(TARGET_OPENGLES) && defined(glDispatchCompute)
        .def("dispatchCompute", &ofShader::dispatchCompute)
        #endif
        // .def("setUniformTexture", (void (ofShader::*)(const string&, const ofBaseHasTexture&, int) const) &ofShader::setUniformTexture)
        .def("setUniformTexture", (void (ofShader::*)(const string&, const ofTexture&, int) const) &ofShader::setUniformTexture)
        .def("setUniformTexture", (void (ofShader::*)(const string&, int, GLint, int) const) &ofShader::setUniformTexture)
        .def("setUniform1i", &ofShader::setUniform1i)
        .def("setUniform2i", &ofShader::setUniform2i)
        .def("setUniform3i", &ofShader::setUniform3i)
        .def("setUniform4i", &ofShader::setUniform4i)
        .def("setUniform1f", &ofShader::setUniform1f)
        .def("setUniform2f", (void (ofShader::*)(const string&, float, float) const) &ofShader::setUniform2f)
        .def("setUniform3f", (void (ofShader::*)(const string&, float, float, float) const) &ofShader::setUniform3f)
        .def("setUniform4f", (void (ofShader::*)(const string&, float, float, float, float) const) &ofShader::setUniform4f)
        .def("setUniform2f", (void (ofShader::*)(const string&, const ofVec2f &) const) &ofShader::setUniform2f)
        .def("setUniform3f", (void (ofShader::*)(const string&, const ofVec3f &) const) &ofShader::setUniform3f)
        .def("setUniform4f", (void (ofShader::*)(const string&, const ofVec4f &) const) &ofShader::setUniform4f)
        .def("setUniform1iv", &ofShader::setUniform1iv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform2iv", &ofShader::setUniform2iv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform3iv", &ofShader::setUniform3iv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform4iv", &ofShader::setUniform4iv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform1fv", &ofShader::setUniform1fv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform2fv", &ofShader::setUniform2fv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform3fv", &ofShader::setUniform3fv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniform4fv", &ofShader::setUniform4fv, "name"_a, "v"_a, "count"_a=1)
        .def("setUniforms", &ofShader::setUniforms)
        .def("setUniformMatrix3f", &ofShader::setUniformMatrix3f, "name"_a, "m"_a, "count"_a=1)
        .def("setUniformMatrix4f", &ofShader::setUniformMatrix4f, "name"_a, "m"_a, "count"_a=1)
        .def("getUniformLocation", &ofShader::getUniformLocation)
        .def("getAttributeLocation", &ofShader::getAttributeLocation)
        #ifndef TARGET_OPENGLES
        .def("setAttribute1s", &ofShader::setAttribute1s)
        .def("setAttribute2s", &ofShader::setAttribute2s)
        .def("setAttribute3s", &ofShader::setAttribute3s)
        .def("setAttribute4s", &ofShader::setAttribute4s)
        .def("setAttribute1d", &ofShader::setAttribute1d)
        .def("setAttribute2d", &ofShader::setAttribute2d)
        .def("setAttribute3d", &ofShader::setAttribute3d)
        .def("setAttribute4d", &ofShader::setAttribute4d)
        #endif
        .def("setAttribute1f", &ofShader::setAttribute1f)
        .def("setAttribute2f", &ofShader::setAttribute2f)
        .def("setAttribute3f", &ofShader::setAttribute3f)
        .def("setAttribute4f", &ofShader::setAttribute4f)
        .def("setAttribute1fv", &ofShader::setAttribute1fv, "name"_a, "v"_a, "stride"_a=sizeof(float))
        .def("setAttribute2fv", &ofShader::setAttribute2fv, "name"_a, "v"_a, "stride"_a=sizeof(float)*2)
        .def("setAttribute3fv", &ofShader::setAttribute3fv, "name"_a, "v"_a, "stride"_a=sizeof(float)*3)
        .def("setAttribute4fv", &ofShader::setAttribute4fv, "name"_a, "v"_a, "stride"_a=sizeof(float)*4)
        .def("bindAttribute", &ofShader::bindAttribute)
        .def("printActiveUniforms", &ofShader::printActiveUniforms)
        .def("printActiveAttributes", &ofShader::printActiveAttributes)
        .def("setupShaderFromSource", &ofShader::setupShaderFromSource, "type"_a, "source"_a, "sourceDirectoryPath"_a="")
        .def("setupShaderFromFile", &ofShader::setupShaderFromFile)
        .def("linkProgram", &ofShader::linkProgram)
        .def("bindDefaults", &ofShader::bindDefaults)
        .def("getProgram", &ofShader::getProgram)
        .def("getShader", &ofShader::getShader)
        .def(py::self == py::self)
        .def(py::self != py::self)
        .def("getShaderSource", &ofShader::getShaderSource);

    py::class_<ofMaterial> mMaterial(m, "ofMaterial");
    py::class_<ofMaterial::Data>(mMaterial, "Data")
        .def(py::init<>())
        .def_readwrite("diffuse",   &ofMaterial::Data::diffuse)
        .def_readwrite("ambient",   &ofMaterial::Data::ambient)
        .def_readwrite("specular",  &ofMaterial::Data::specular)
        .def_readwrite("emissive",  &ofMaterial::Data::emissive)
        .def_readwrite("shininess", &ofMaterial::Data::shininess);
    mMaterial.def(py::init<>())
        .def("setColors",        &ofMaterial::setColors)
        .def("setDiffuseColor",  &ofMaterial::setDiffuseColor)
        .def("setAmbientColor",  &ofMaterial::setAmbientColor)
        .def("setSpecularColor", &ofMaterial::setSpecularColor)
        .def("setEmissiveColor", &ofMaterial::setEmissiveColor)
        .def("setShininess",     &ofMaterial::setShininess)
        .def("getDiffuseColor",  &ofMaterial::getDiffuseColor)
        .def("getAmbientColor",  &ofMaterial::getAmbientColor)
        .def("getSpecularColor", &ofMaterial::getSpecularColor)
        .def("getEmissiveColor", &ofMaterial::getEmissiveColor)
        .def("getShininess",     &ofMaterial::getShininess)
        .def("getData",          &ofMaterial::getData)
        .def("setData",          &ofMaterial::setData)
        .def("begin",            &ofMaterial::begin)
        .def("end",              &ofMaterial::end);

    m.def("ofGetGlInternalFormat", (int (*)(const ofPixels&))      &ofGetGlInternalFormat);
    m.def("ofGetGlInternalFormat", (int (*)(const ofShortPixels&)) &ofGetGlInternalFormat);
    m.def("ofGetGlInternalFormat", (int (*)(const ofFloatPixels&)) &ofGetGlInternalFormat);
    m.def("ofGetGlType",           (int (*)(const ofPixels&))      &ofGetGlType);
    m.def("ofGetGlType",           (int (*)(const ofShortPixels&)) &ofGetGlType);
    m.def("ofGetGlType",           (int (*)(const ofFloatPixels&)) &ofGetGlType);
    m.def("ofGetGlInternalFormatName",            &ofGetGlInternalFormatName);
    m.def("ofGetGLFormatFromInternal",            &ofGetGLFormatFromInternal);
    m.def("ofGetGlTypeFromInternal",              &ofGetGlTypeFromInternal);
    m.def("ofGetImageTypeFromGLType",             &ofGetImageTypeFromGLType);
    m.def("ofGetGLPolyMode",                      &ofGetGLPolyMode);
    m.def("ofGetOFPolyMode",                      &ofGetOFPolyMode);
    m.def("ofGetGLPrimitiveMode",                 &ofGetGLPrimitiveMode);
    m.def("ofGetOFPrimitiveMode",                 &ofGetOFPrimitiveMode);
    m.def("ofGetGLInternalFormatFromPixelFormat", &ofGetGLInternalFormatFromPixelFormat);
    m.def("ofGetGLFormatFromPixelFormat",         &ofGetGLFormatFromPixelFormat);
    m.def("ofGetBytesPerChannelFromGLType",       &ofGetBytesPerChannelFromGLType);
    m.def("ofGetNumChannelsFromGLFormat",         &ofGetNumChannelsFromGLFormat);
    m.def("ofSetPixelStoreiAlignment",            (void (*)(GLenum, int, int, int)) &ofSetPixelStoreiAlignment);
    m.def("ofSetPixelStoreiAlignment",            (void (*)(GLenum, int))           &ofSetPixelStoreiAlignment);
    m.def("ofGLSupportedExtensions",              &ofGLSupportedExtensions);
    m.def("ofGLCheckExtension",                   &ofGLCheckExtension);
    m.def("ofGLSupportsNPOTTextures",             &ofGLSupportsNPOTTextures);
    m.def("ofIsGLProgrammableRenderer",           &ofIsGLProgrammableRenderer);
    m.def("ofGetGlFormat",                        (int (*)(const ofPixels      &)) &ofGetGlFormat);
    m.def("ofGetGlFormat",                        (int (*)(const ofShortPixels &)) &ofGetGlFormat);
    m.def("ofGetGlFormat",                        (int (*)(const ofFloatPixels &)) &ofGetGlFormat);
    m.def("ofGLSLVersionFromGL",                  &ofGLSLVersionFromGL);

    py::class_<ofBufferObject>(m, "ofBufferObject")
        .def(py::init<>())
        .def("allocate", (void (ofBufferObject::*)()) &ofBufferObject::allocate)
        .def("allocate", (void (ofBufferObject::*)(GLsizeiptr, GLenum)) &ofBufferObject::allocate)
        .def("allocate", (void (ofBufferObject::*)(GLsizeiptr, const void *, GLenum)) &ofBufferObject::allocate)
        // .def("allocate", (void (ofBufferObject::*)(const vector<T> &, GLenum, GLenum)) &ofBufferObject::allocate)
        // .def("allocate", (void (ofBufferObject::*)(const ofPixels_<T> &, GLenum, GLenum)) &ofBufferObject::allocate)
        .def("isAllocated", &ofBufferObject::isAllocated)
        .def("bind", &ofBufferObject::bind)
        .def("unbind", &ofBufferObject::unbind)
        #ifndef TARGET_OPENGLES
        .def("bindBase", &ofBufferObject::bindBase)
        .def("unbindBase", &ofBufferObject::unbindBase)
        .def("bindRange", &ofBufferObject::bindRange)
        .def("unbindRange", &ofBufferObject::unbindRange)
        #endif
        .def("getId", &ofBufferObject::getId)
        .def("setData", (void (ofBufferObject::*)(GLsizeiptr, const void *, GLenum)) &ofBufferObject::setData)
        // .def("setData", (void (ofBufferObject::*)(const vector<T> &, GLenum, GLenum)) &ofBufferObject::setData)
        // .def("setData", (void (ofBufferObject::*)(const ofPixels_<T> &, GLenum, GLenum)) &ofBufferObject::setData)
        .def("updateData", (void (ofBufferObject::*)(GLintptr, GLsizeiptr, const void *)) &ofBufferObject::updateData)
        .def("updateData", (void (ofBufferObject::*)(GLsizeiptr, const void *)) &ofBufferObject::updateData)
        // .def("updateData", (void (ofBufferObject::*)(GLintptr, const vector<T> &)) &ofBufferObject::updateData)
        // .def("updateData", (void (ofBufferObject::*)(const vector<T> &)) &ofBufferObject::updateData)
        .def("size", &ofBufferObject::size);

    py::class_<ofVbo>(m, "ofVbo")
        .def(py::init<>())
        .def(py::init<const ofVbo&>())
        .def("setMesh", (void (ofVbo::*)(const ofMesh &, int)) &ofVbo::setMesh)
        .def("setMesh", (void (ofVbo::*)(const ofMesh &, int, bool,bool,bool)) &ofVbo::setMesh)
        .def("setVertexData", (void (ofVbo::*)(const ofVec3f *, int, int)) &ofVbo::setVertexData)
        .def("setVertexData", (void (ofVbo::*)(const ofVec2f *, int, int)) &ofVbo::setVertexData)
        .def("setVertexData", (void (ofVbo::*)(const float *, int, int, int, int)) &ofVbo::setVertexData, "vert0x"_a, "numCoords"_a, "total"_a, "usage"_a, "stride"_a=0)
        .def("setColorData", (void (ofVbo::*)(const ofFloatColor *, int, int)) &ofVbo::setColorData)
        .def("setColorData", (void (ofVbo::*)(const float *, int, int, int))   &ofVbo::setColorData, "color0r"_a, "total"_a, "usage"_a, "stride"_a=0)
        .def("setNormalData", (void (ofVbo::*)(const ofVec3f *, int, int))    &ofVbo::setNormalData)
        .def("setNormalData", (void (ofVbo::*)(const float *, int, int, int)) &ofVbo::setNormalData, "normal0x"_a, "total"_a, "usage"_a, "stride"_a=0)
        .def("setTexCoordData", (void (ofVbo::*)(const ofVec2f *, int, int))    &ofVbo::setTexCoordData)
        .def("setTexCoordData", (void (ofVbo::*)(const float *, int, int, int)) &ofVbo::setTexCoordData, "texCoord0x"_a, "total"_a, "usage"_a, "stride"_a=0)
        .def("setIndexData", &ofVbo::setIndexData)
        .def("setAttributeData", &ofVbo::setAttributeData, "location"_a, "vert0x"_a, "numCoords"_a, "total"_a, "usage"_a, "stride"_a=0)
        #ifndef TARGET_OPENGLES
        .def("setAttributeDivisor", &ofVbo::setAttributeDivisor)
        #endif
        .def("setVertexBuffer",    &ofVbo::setVertexBuffer,    "buffer"_a,   "numCoords"_a, "stride"_a,    "offset"_a=0)
        .def("setColorBuffer",     &ofVbo::setColorBuffer,     "buffer"_a,   "stride"_a,    "offset"_a=0)
        .def("setNormalBuffer",    &ofVbo::setNormalBuffer,    "buffer"_a,   "stride"_a,    "offset"_a=0)
        .def("setTexCoordBuffer",  &ofVbo::setTexCoordBuffer,  "buffer"_a,   "stride"_a,    "offset"_a=0)
        .def("setIndexBuffer",     &ofVbo::setIndexBuffer)
        .def("setAttributeBuffer", &ofVbo::setAttributeBuffer, "location"_a, "buffer"_a,    "numCoords"_a, "stride"_a,   "offset"_a=0)
        .def("getVertexBuffer",    (ofBufferObject& (ofVbo::*)())    &ofVbo::getVertexBuffer,   py::return_value_policy::reference)
        .def("getColorBuffer",     (ofBufferObject& (ofVbo::*)())    &ofVbo::getColorBuffer,    py::return_value_policy::reference)
        .def("getNormalBuffer",    (ofBufferObject& (ofVbo::*)())    &ofVbo::getNormalBuffer,   py::return_value_policy::reference)
        .def("getTexCoordBuffer",  (ofBufferObject& (ofVbo::*)())    &ofVbo::getTexCoordBuffer, py::return_value_policy::reference)
        .def("getIndexBuffer",     (ofBufferObject& (ofVbo::*)())    &ofVbo::getIndexBuffer,    py::return_value_policy::reference)
        .def("getAttributeBuffer", (ofBufferObject& (ofVbo::*)(int)) &ofVbo::getAttributeBuffer,py::return_value_policy::reference)
        .def("updateMesh", &ofVbo::updateMesh)
        .def("updateVertexData",   (void (ofVbo::*)(const ofVec3f*, int))      &ofVbo::updateVertexData)
        .def("updateVertexData",   (void (ofVbo::*)(const ofVec2f*, int))      &ofVbo::updateVertexData)
        .def("updateVertexData",   (void (ofVbo::*)(const float*, int))        &ofVbo::updateVertexData)
        .def("updateColorData",    (void (ofVbo::*)(const ofFloatColor*, int)) &ofVbo::updateColorData)
        .def("updateColorData",    (void (ofVbo::*)(const float*, int))        &ofVbo::updateColorData)
        .def("updateNormalData",   (void (ofVbo::*)(const ofVec3f*, int))      &ofVbo::updateNormalData)
        .def("updateNormalData",   (void (ofVbo::*)(const float*, int))        &ofVbo::updateNormalData)
        .def("updateTexCoordData", (void (ofVbo::*)(const ofVec2f*, int))      &ofVbo::updateTexCoordData)
        .def("updateTexCoordData", (void (ofVbo::*)(const float*, int))        &ofVbo::updateTexCoordData)
        .def("updateIndexData",       &ofVbo::updateIndexData)
        .def("updateAttributeData",   &ofVbo::updateAttributeData)
        .def("enableColors",          &ofVbo::enableColors)
        .def("enableNormals",         &ofVbo::enableNormals)
        .def("enableTexCoords",       &ofVbo::enableTexCoords)
        .def("enableIndices",         &ofVbo::enableIndices)
        .def("disableColors",         &ofVbo::disableColors)
        .def("disableNormals",        &ofVbo::disableNormals)
        .def("disableTexCoords",      &ofVbo::disableTexCoords)
        .def("disableIndices",        &ofVbo::disableIndices)
        .def("getVaoId",              &ofVbo::getVaoId)
        .def("getVertId",             &ofVbo::getVertId)
        .def("getColorId",            &ofVbo::getColorId)
        .def("getNormalId",           &ofVbo::getNormalId)
        .def("getTexCoordId",         &ofVbo::getTexCoordId)
        .def("getIndexId",            &ofVbo::getIndexId)
        .def("getAttributeId",        &ofVbo::getAttributeId)
        .def("getIsAllocated",        &ofVbo::getIsAllocated)
        .def("getUsingVerts",         &ofVbo::getUsingVerts)
        .def("getUsingColors",        &ofVbo::getUsingColors)
        .def("getUsingNormals",       &ofVbo::getUsingNormals)
        .def("getUsingTexCoords",     &ofVbo::getUsingTexCoords)
        .def("getUsingIndices",       &ofVbo::getUsingIndices)
        .def("draw",                  &ofVbo::draw)
        .def("drawElements",          &ofVbo::drawElements)
        .def("drawInstanced",         &ofVbo::drawInstanced)
        .def("drawElementsInstanced", &ofVbo::drawElementsInstanced)
        .def("bind",                  &ofVbo::bind)
        .def("unbind",                &ofVbo::unbind)
        .def("clear",                 &ofVbo::clear)
        .def("clearVertices",         &ofVbo::clearVertices)
        .def("clearNormals",          &ofVbo::clearNormals)
        .def("clearColors",           &ofVbo::clearColors)
        .def("clearTexCoords",        &ofVbo::clearTexCoords)
        .def("clearIndices",          &ofVbo::clearIndices)
        .def("clearAttribute",        &ofVbo::clearAttribute)
        .def("getNumVertices",        &ofVbo::getNumVertices)
        .def("getNumIndices",         &ofVbo::getNumIndices)
        .def("hasAttribute",          &ofVbo::hasAttribute);

    py::class_<ofVboMesh, ofMesh>(m, "ofVboMesh")
        .def(py::init<>())
        .def(py::init<const ofMesh &>())
        .def("setUsage",        &ofVboMesh::setUsage)
        .def("enableColors",    &ofVboMesh::enableColors)
        .def("enableTextures",  &ofVboMesh::enableTextures)
        .def("enableNormals",   &ofVboMesh::enableNormals)
        .def("enableIndices",   &ofVboMesh::enableIndices)
        .def("disableColors",   &ofVboMesh::disableColors)
        .def("disableTextures", &ofVboMesh::disableTextures)
        .def("disableNormals",  &ofVboMesh::disableNormals)
        .def("disableIndices",  &ofVboMesh::disableIndices)
        .def("usingColors",     &ofVboMesh::usingColors)
        .def("usingTextures",   &ofVboMesh::usingTextures)
        .def("usingNormals",    &ofVboMesh::usingNormals)
        .def("usingIndices",    &ofVboMesh::usingIndices)
        .def("draw",(void (ofVboMesh::*)(ofPolyRenderMode) const) &ofVboMesh::draw)
        .def("drawInstanced",   &ofVboMesh::drawInstanced)
        .def("getVbo",(ofVbo& (ofVboMesh::*)()) &ofVboMesh::getVbo);

    py::class_<ofFbo, shared_ptr<ofFbo>> mFbo(m, "ofFbo");
    py::class_<ofFbo::Settings>(mFbo, "Settings")
        // .def(py::init<>())
        .def(py::init<std::shared_ptr<ofBaseGLRenderer>>(), "renderer"_a=nullptr)
        .def_readwrite("width", &ofFbo::Settings::width)
        .def_readwrite("height", &ofFbo::Settings::height)
        .def_readwrite("numColorbuffers", &ofFbo::Settings::numColorbuffers)
        .def_readwrite("colorFormats", &ofFbo::Settings::colorFormats)
        .def_readwrite("useDepth", &ofFbo::Settings::useDepth)
        .def_readwrite("useStencil", &ofFbo::Settings::useStencil)
        .def_readwrite("depthStencilAsTexture", &ofFbo::Settings::depthStencilAsTexture)
        .def_readwrite("textureTarget", &ofFbo::Settings::textureTarget)
        .def_readwrite("internalformat", &ofFbo::Settings::internalformat)
        .def_readwrite("depthStencilInternalFormat", &ofFbo::Settings::depthStencilInternalFormat)
        .def_readwrite("wrapModeHorizontal", &ofFbo::Settings::wrapModeHorizontal)
        .def_readwrite("wrapModeVertical", &ofFbo::Settings::wrapModeVertical)
        .def_readwrite("minFilter", &ofFbo::Settings::minFilter)
        .def_readwrite("maxFilter", &ofFbo::Settings::maxFilter)
        .def_readwrite("numSamples", &ofFbo::Settings::numSamples);
        // .def(py::self != py::self);
    mFbo.def(py::init<>())
        .def(py::init<const ofFbo &>())
        .def("allocate", (void (ofFbo::*)(int, int, int, int)) &ofFbo::allocate, "width"_a, "height"_a, "internalformat"_a=GL_RGBA, "numSamples"_a=0)
        .def("allocate", (void (ofFbo::*)(ofFbo::Settings)) &ofFbo::allocate, "settings"_a=ofFbo::Settings(nullptr))
        .def("draw", (void (ofFbo::*)(float, float) const) &ofFbo::draw)
        .def("draw", (void (ofFbo::*)(float, float, float, float) const) &ofFbo::draw)
        .def("setAnchorPercent", &ofFbo::setAnchorPercent)
        .def("setAnchorPoint", &ofFbo::setAnchorPoint)
        .def("resetAnchor", &ofFbo::resetAnchor)
        .def("setDefaultTextureIndex", &ofFbo::setDefaultTextureIndex)
        .def("getDefaultTextureIndex", &ofFbo::getDefaultTextureIndex)
        .def("getTexture", (ofTexture& (ofFbo::*)()) &ofFbo::getTexture)
        .def("getTexture", (ofTexture& (ofFbo::*)(int)) &ofFbo::getTexture)
        .def("getDepthTexture", (ofTexture& (ofFbo::*)()) &ofFbo::getDepthTexture)
        .def("begin", &ofFbo::begin, "setupScreen"_a=true)
        .def("end", &ofFbo::end)
        .def("readToPixels", (void (ofFbo::*)(ofPixels&, int) const) &ofFbo::readToPixels, "pixels"_a, "attachmentPoint"_a=0)
        .def("readToPixels", (void (ofFbo::*)(ofShortPixels&, int) const) &ofFbo::readToPixels, "pixels"_a, "attachmentPoint"_a=0)
        .def("readToPixels", (void (ofFbo::*)(ofFloatPixels&, int) const) &ofFbo::readToPixels, "pixels"_a, "attachmentPoint"_a=0)
        .def("getWidth",  &ofFbo::getWidth)
        .def("getHeight", &ofFbo::getHeight)
        .def("bind", &ofFbo::bind)
        .def("unbind", &ofFbo::unbind)
        .def("flagDirty", &ofFbo::flagDirty)
        .def("updateTexture", &ofFbo::updateTexture)
        .def("checkStatus", &ofFbo::checkStatus)
        .def("createAndAttachTexture", &ofFbo::createAndAttachTexture)
        .def("attachTexture", &ofFbo::attachTexture)
        .def("createAndAttachRenderbuffer", &ofFbo::createAndAttachRenderbuffer)
        .def("createAndAttachDepthStencilTexture", (void (ofFbo::*)(GLenum, GLint, GLenum)) &ofFbo::createAndAttachDepthStencilTexture)
        .def("createAndAttachDepthStencilTexture", (void (ofFbo::*)(GLenum, GLint, GLenum, GLenum, GLenum)) &ofFbo::createAndAttachDepthStencilTexture)
        .def("getNumTextures", &ofFbo::getNumTextures)
        .def("setActiveDrawBuffer", &ofFbo::setActiveDrawBuffer)
        .def("setActiveDrawBuffers", &ofFbo::setActiveDrawBuffers)
        .def("activateAllDrawBuffers", &ofFbo::activateAllDrawBuffers)
        .def("getId", &ofFbo::getId)
        .def("getIdDrawBuffer", &ofFbo::getIdDrawBuffer)
        .def_static("checkGLSupport", &ofFbo::checkGLSupport)
        .def_static("maxColorAttachments", &ofFbo::maxColorAttachments)
        .def_static("maxDrawBuffers", &ofFbo::maxDrawBuffers)
        .def_static("maxSamples", &ofFbo::maxSamples)
        .def("getDepthBuffer", &ofFbo::getDepthBuffer)
        .def("getStencilBuffer", &ofFbo::getStencilBuffer);


}