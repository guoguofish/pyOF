#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// #include "Python.h"
namespace py = pybind11;

void pybind_ofxGui(py::module &m) {
    using namespace py::literals;

    m.def("ofxGuiSetFont", &ofxGuiSetFont, "ofxGuiSetFont(fontPath, fontsize, _bAntiAliased=True, _bFullCharacterSet=False, dpi=0)");
    m.def("ofxGuiSetBitmapFont",    &ofxGuiSetBitmapFont,    "ofxGuiSetBitmapFont()");
    m.def("ofxGuiSetHeaderColor",   &ofxGuiSetHeaderColor,   "ofxGuiSetHeaderColor( ofColor )");
    m.def("ofxGuiSetBorderColor",   &ofxGuiSetBorderColor,   "ofxGuiSetBorderColor( ofColor )");
    m.def("ofxGuiSetTextColor",     &ofxGuiSetTextColor,     "ofxGuiSetTextColor( ofColor )");
    m.def("ofxGuiSetFillColor",     &ofxGuiSetFillColor,     "ofxGuiSetFillColor( ofColor )");
    m.def("ofxGuiSetTextPadding",   &ofxGuiSetTextPadding,   "ofxGuiSetTextPadding( padding )");
    m.def("ofxGuiSetDefaultWidth",  &ofxGuiSetDefaultWidth,  "ofxGuiSetDefaultWidth( width   )");
    m.def("ofxGuiSetDefaultHeight", &ofxGuiSetDefaultHeight, "ofxGuiSetDefaultHeight( height  )");
    m.def("ofxGuiSetBackgroundColor", &ofxGuiSetBackgroundColor, "ofxGuiSetBackgroundColor( ofColor  )");

    py::class_<ofxBaseGui>(m, "ofxBaseGui")
        .def_static("setDefaultHeaderBackgroundColor", &ofxBaseGui::setDefaultHeaderBackgroundColor)
        .def_static("setDefaultBackgroundColor", &ofxBaseGui::setDefaultBackgroundColor)
        .def_static("setDefaultBorderColor", &ofxBaseGui::setDefaultBorderColor)
        .def_static("setDefaultTextColor", &ofxBaseGui::setDefaultTextColor)
        .def_static("setDefaultFillColor", &ofxBaseGui::setDefaultFillColor)
        .def_static("setDefaultTextPadding", &ofxBaseGui::setDefaultTextPadding)
        .def_static("setDefaultWidth", &ofxBaseGui::setDefaultWidth)
        .def_static("setDefaultHeight", &ofxBaseGui::setDefaultHeight)
        .def_static("loadFont", &ofxBaseGui::loadFont, "filename"_a, "fontsize"_a, "_bAntiAliased"_a=true, "_bFullCharacterSet"_a=false, "dpi"_a=0)
        .def_static("setUseTTF", &ofxBaseGui::setUseTTF);

    py::class_<ofxToggle, ofxBaseGui>(m, "ofxToggle")
        .def(py::init<>())
        .def("getParameter", [](ofxToggle &m){ return dynamic_cast<ofParameter<bool>&>(m.getParameter());})
        .def("getParent",    &ofxToggle::getParent)
        .def("setParent", [](ofxToggle &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("draw",                     &ofxToggle::draw)
        .def("saveToFile",               &ofxToggle::saveToFile)
        .def("loadFromFile",             &ofxToggle::loadFromFile)
        .def("saveTo",                   &ofxToggle::saveTo)
        .def("loadFrom",                 &ofxToggle::loadFrom)
        .def("getName",                  &ofxToggle::getName)
        .def("setName",                  &ofxToggle::setName)
        .def("getPosition",              &ofxToggle::getPosition)
        .def("setPosition", (void (ofxToggle::*)(const ofPoint &)) &ofxToggle::setPosition)
        .def("setPosition", (void (ofxToggle::*)(float,float)) &ofxToggle::setPosition)
        .def("getShape",                 &ofxToggle::getShape)
        .def("setShape", (void (ofxToggle::*)(ofRectangle)) &ofxToggle::setShape)
        .def("setShape", (void (ofxToggle::*)(float,float,float,float)) &ofxToggle::setShape)
        .def("setSize",                  &ofxToggle::setSize)
        .def("getWidth",                 &ofxToggle::getWidth)
        .def("getHeight",                &ofxToggle::getHeight)
        .def("getHeaderBackgroundColor", &ofxToggle::getHeaderBackgroundColor)
        .def("setHeaderBackgroundColor", &ofxToggle::setHeaderBackgroundColor)
        .def("getBackgroundColor",       &ofxToggle::getBackgroundColor)
        .def("setBackgroundColor",       &ofxToggle::setBackgroundColor)
        .def("getBorderColor",           &ofxToggle::getBorderColor)
        .def("setBorderColor",           &ofxToggle::setBorderColor)
        .def("getTextColor",             &ofxToggle::getTextColor)
        .def("setTextColor",             &ofxToggle::setTextColor)
        .def("getFillColor",             &ofxToggle::getFillColor)
        .def("setFillColor",             &ofxToggle::setFillColor)
        .def_property("name", &ofxToggle::getName, &ofxToggle::setName)
        .def_property("thisHeaderBackgroundColor", &ofxToggle::getHeaderBackgroundColor, &ofxToggle::setHeaderBackgroundColor)
        .def_property("thisBackgroundColor", &ofxToggle::getBackgroundColor, &ofxToggle::setBackgroundColor)
        .def_property("thisBorderColor", &ofxToggle::getBorderColor, &ofxToggle::setBorderColor)
        .def_property("thisTextColor", &ofxToggle::getTextColor, &ofxToggle::setTextColor)
        .def_property("thisFillColor", &ofxToggle::getFillColor, &ofxToggle::setFillColor)
        .def_property("parent", &ofxToggle::getParent, [](ofxToggle &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("setup", (ofxToggle* (ofxToggle::*)(const string &, bool, float, float)) &ofxToggle::setup, py::return_value_policy::reference, "name"_a, "value"_a, "width"_a=200, "height"_a=18);

    py::class_<ofxButton, ofxToggle>(m, "ofxButton")
        .def(py::init<>())
        .def("getParameter", [](ofxButton &m){ return dynamic_cast<ofParameter<bool>&>(m.getParameter());})
        .def("getParent",    &ofxButton::getParent)
        .def("setParent", [](ofxButton &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("draw",                     &ofxButton::draw)
        .def("saveToFile",               &ofxButton::saveToFile)
        .def("loadFromFile",             &ofxButton::loadFromFile)
        .def("saveTo",                   &ofxButton::saveTo)
        .def("loadFrom",                 &ofxButton::loadFrom)
        .def("getName",                  &ofxButton::getName)
        .def("setName",                  &ofxButton::setName)
        .def("getPosition",              &ofxButton::getPosition)
        .def("setPosition", (void (ofxButton::*)(const ofPoint &)) &ofxButton::setPosition)
        .def("setPosition", (void (ofxButton::*)(float,float)) &ofxButton::setPosition)
        .def("getShape",                 &ofxButton::getShape)
        .def("setShape", (void (ofxButton::*)(ofRectangle)) &ofxButton::setShape)
        .def("setShape", (void (ofxButton::*)(float,float,float,float)) &ofxButton::setShape)
        .def("setSize",                  &ofxButton::setSize)
        .def("getWidth",                 &ofxButton::getWidth)
        .def("getHeight",                &ofxButton::getHeight)
        .def("getHeaderBackgroundColor", &ofxButton::getHeaderBackgroundColor)
        .def("setHeaderBackgroundColor", &ofxButton::setHeaderBackgroundColor)
        .def("getBackgroundColor",       &ofxButton::getBackgroundColor)
        .def("setBackgroundColor",       &ofxButton::setBackgroundColor)
        .def("getBorderColor",           &ofxButton::getBorderColor)
        .def("setBorderColor",           &ofxButton::setBorderColor)
        .def("getTextColor",             &ofxButton::getTextColor)
        .def("setTextColor",             &ofxButton::setTextColor)
        .def("getFillColor",             &ofxButton::getFillColor)
        .def("setFillColor",             &ofxButton::setFillColor)
        .def_property("name", &ofxButton::getName, &ofxButton::setName)
        .def_property("thisHeaderBackgroundColor", &ofxButton::getHeaderBackgroundColor, &ofxButton::setHeaderBackgroundColor)
        .def_property("thisBackgroundColor", &ofxButton::getBackgroundColor, &ofxButton::setBackgroundColor)
        .def_property("thisBorderColor", &ofxButton::getBorderColor, &ofxButton::setBorderColor)
        .def_property("thisTextColor", &ofxButton::getTextColor, &ofxButton::setTextColor)
        .def_property("thisFillColor", &ofxButton::getFillColor, &ofxButton::setFillColor)
        .def_property("parent", &ofxButton::getParent, [](ofxButton &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("setup", (ofxButton* (ofxButton::*)(const string &, float, float)) &ofxButton::setup, py::return_value_policy::reference, "name"_a, "width"_a=200, "height"_a=18);

    py::class_<ofxIntSlider>(m, "ofxIntSlider")
        .def(py::init<>())
        .def("getParameter", [](ofxIntSlider &m){ return dynamic_cast<ofParameter<int>&>(m.getParameter());})
        .def("getParent",    &ofxIntSlider::getParent)
        .def("setParent", [](ofxIntSlider &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("draw",                     &ofxIntSlider::draw)
        .def("saveToFile",               &ofxIntSlider::saveToFile)
        .def("loadFromFile",             &ofxIntSlider::loadFromFile)
        .def("saveTo",                   &ofxIntSlider::saveTo)
        .def("loadFrom",                 &ofxIntSlider::loadFrom)
        .def("getName",                  &ofxIntSlider::getName)
        .def("setName",                  &ofxIntSlider::setName)
        .def("getPosition",              &ofxIntSlider::getPosition)
        .def("setPosition", (void (ofxIntSlider::*)(const ofPoint &)) &ofxIntSlider::setPosition)
        .def("setPosition", (void (ofxIntSlider::*)(float,float))     &ofxIntSlider::setPosition)
        .def("getShape",                 &ofxIntSlider::getShape)
        .def("setShape", (void (ofxIntSlider::*)(ofRectangle)) &ofxIntSlider::setShape)
        .def("setShape", (void (ofxIntSlider::*)(float,float,float,float)) &ofxIntSlider::setShape)
        .def("setSize",                  &ofxIntSlider::setSize)
        .def("getWidth",                 &ofxIntSlider::getWidth)
        .def("getHeight",                &ofxIntSlider::getHeight)
        .def("getHeaderBackgroundColor", &ofxIntSlider::getHeaderBackgroundColor)
        .def("setHeaderBackgroundColor", &ofxIntSlider::setHeaderBackgroundColor)
        .def("getBackgroundColor",       &ofxIntSlider::getBackgroundColor)
        .def("setBackgroundColor",       &ofxIntSlider::setBackgroundColor)
        .def("getBorderColor",           &ofxIntSlider::getBorderColor)
        .def("setBorderColor",           &ofxIntSlider::setBorderColor)
        .def("getTextColor",             &ofxIntSlider::getTextColor)
        .def("setTextColor",             &ofxIntSlider::setTextColor)
        .def("getFillColor",             &ofxIntSlider::getFillColor)
        .def("setFillColor",             &ofxIntSlider::setFillColor)
        .def_property("name", &ofxIntSlider::getName, &ofxIntSlider::setName)
        .def_property("thisHeaderBackgroundColor", &ofxIntSlider::getHeaderBackgroundColor, &ofxIntSlider::setHeaderBackgroundColor)
        .def_property("thisBackgroundColor", &ofxIntSlider::getBackgroundColor, &ofxIntSlider::setBackgroundColor)
        .def_property("thisBorderColor", &ofxIntSlider::getBorderColor, &ofxIntSlider::setBorderColor)
        .def_property("thisTextColor", &ofxIntSlider::getTextColor, &ofxIntSlider::setTextColor)
        .def_property("thisFillColor", &ofxIntSlider::getFillColor, &ofxIntSlider::setFillColor)
        .def_property("parent", &ofxIntSlider::getParent, [](ofxIntSlider &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("setup", (ofxIntSlider* (ofxIntSlider::*)(const string &, int, int, int, float, float)) &ofxIntSlider::setup, py::return_value_policy::reference, "sliderName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);

    py::class_<ofxFloatSlider>(m, "ofxFloatSlider")
        .def(py::init<>())
        .def("getParameter", [](ofxFloatSlider &m){ return dynamic_cast<ofParameter<float>&>(m.getParameter());})
        .def("getParent",    &ofxFloatSlider::getParent)
        .def("setParent", [](ofxFloatSlider &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("draw",                     &ofxFloatSlider::draw)
        .def("saveToFile",               &ofxFloatSlider::saveToFile)
        .def("loadFromFile",             &ofxFloatSlider::loadFromFile)
        .def("saveTo",                   &ofxFloatSlider::saveTo)
        .def("loadFrom",                 &ofxFloatSlider::loadFrom)
        .def("getName",                  &ofxFloatSlider::getName)
        .def("setName",                  &ofxFloatSlider::setName)
        .def("getPosition",              &ofxFloatSlider::getPosition)
        .def("setPosition", (void (ofxFloatSlider::*)(const ofPoint &)) &ofxFloatSlider::setPosition)
        .def("setPosition", (void (ofxFloatSlider::*)(float,float))     &ofxFloatSlider::setPosition)
        .def("getShape",                 &ofxFloatSlider::getShape)
        .def("setShape", (void (ofxFloatSlider::*)(ofRectangle)) &ofxFloatSlider::setShape)
        .def("setShape", (void (ofxFloatSlider::*)(float,float,float,float)) &ofxFloatSlider::setShape)
        .def("setSize",                  &ofxFloatSlider::setSize)
        .def("getWidth",                 &ofxFloatSlider::getWidth)
        .def("getHeight",                &ofxFloatSlider::getHeight)
        .def("getHeaderBackgroundColor", &ofxFloatSlider::getHeaderBackgroundColor)
        .def("setHeaderBackgroundColor", &ofxFloatSlider::setHeaderBackgroundColor)
        .def("getBackgroundColor",       &ofxFloatSlider::getBackgroundColor)
        .def("setBackgroundColor",       &ofxFloatSlider::setBackgroundColor)
        .def("getBorderColor",           &ofxFloatSlider::getBorderColor)
        .def("setBorderColor",           &ofxFloatSlider::setBorderColor)
        .def("getTextColor",             &ofxFloatSlider::getTextColor)
        .def("setTextColor",             &ofxFloatSlider::setTextColor)
        .def("getFillColor",             &ofxFloatSlider::getFillColor)
        .def("setFillColor",             &ofxFloatSlider::setFillColor)
        .def_property("name", &ofxFloatSlider::getName, &ofxFloatSlider::setName)
        .def_property("thisHeaderBackgroundColor", &ofxFloatSlider::getHeaderBackgroundColor, &ofxFloatSlider::setHeaderBackgroundColor)
        .def_property("thisBackgroundColor", &ofxFloatSlider::getBackgroundColor, &ofxFloatSlider::setBackgroundColor)
        .def_property("thisBorderColor", &ofxFloatSlider::getBorderColor, &ofxFloatSlider::setBorderColor)
        .def_property("thisTextColor", &ofxFloatSlider::getTextColor, &ofxFloatSlider::setTextColor)
        .def_property("thisFillColor", &ofxFloatSlider::getFillColor, &ofxFloatSlider::setFillColor)
        .def_property("parent", &ofxFloatSlider::getParent, [](ofxFloatSlider &m, ofxPanel *parent){ return m.setParent(parent);})
        .def("setup", (ofxFloatSlider* (ofxFloatSlider::*)(const string &, float, float, float, float, float)) &ofxFloatSlider::setup, py::return_value_policy::reference, "sliderName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);

    py::class_<ofxVec2Slider>(m, "ofxVec2Slider")
        .def(py::init<>())
        .def("setup", (ofxVec2Slider* (ofxVec2Slider::*)(const string &, const ofVec2f&,const ofVec2f&,const ofVec2f&, float, float)) &ofxVec2Slider::setup, py::return_value_policy::reference, "controlName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);
    py::class_<ofxVec3Slider>(m, "ofxVec3Slider")
        .def(py::init<>())
        .def("setup", (ofxVec3Slider* (ofxVec3Slider::*)(const string &,const ofVec3f&, const ofVec3f&, const ofVec3f&, float, float)) &ofxVec3Slider::setup, py::return_value_policy::reference, "controlName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);
    py::class_<ofxVec4Slider>(m, "ofxVec4Slider")
        .def(py::init<>())
        .def("setup", (ofxVec4Slider* (ofxVec4Slider::*)(const string &, const ofVec4f&, const ofVec4f&, const ofVec4f&, float, float)) &ofxVec4Slider::setup, py::return_value_policy::reference, "controlName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);
    m.attr("ofxPointSlider") = m.attr("ofxVec3Slider");
    // py::class_<ofxPointSlider>(m, "ofxPointSlider")
    //     .def(py::init<>())
    //     .def("setup", (ofxPointSlider* (ofxPointSlider::*)(const string &, const ofPoint&, const ofPoint&, const ofPoint&, float, float)) &ofxPointSlider::setup, py::return_value_policy::reference);

    py::class_<ofxColorSlider>(m, "ofxColorSlider")
        .def(py::init<>())
        .def("setup", (ofxColorSlider* (ofxColorSlider::*)(const string &, const ofColor&, const ofColor&, const ofColor&, float, float)) &ofxColorSlider::setup, py::return_value_policy::reference, "controlName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);
    py::class_<ofxShortColorSlider>(m, "ofxShortColorSlider")
        .def(py::init<>())
        .def("setup", (ofxShortColorSlider* (ofxShortColorSlider::*)(const string &, const ofShortColor&, const ofShortColor&, const ofShortColor&, float, float)) &ofxShortColorSlider::setup, py::return_value_policy::reference, "controlName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);
    py::class_<ofxFloatColorSlider>(m, "ofxFloatColorSlider")
        .def(py::init<>())
        .def("setup", (ofxFloatColorSlider* (ofxFloatColorSlider::*)(const string &, const ofFloatColor&, const ofFloatColor&, const ofFloatColor&, float, float)) &ofxFloatColorSlider::setup, py::return_value_policy::reference, "controlName"_a, "value"_a, "min"_a, "max"_a, "width"_a=200, "height"_a=18);


    py::class_<ofxPanel>(m, "ofxPanel")
        .def(py::init<>())
        .def(py::init<const ofParameterGroup &, const string&, float, float>(), "parameters"_a, "filename"_a="settings.xml", "x"_a=10, "y"_a=10)
        .def("setup", (ofxPanel* (ofxPanel::*)(const ofParameterGroup&, const string&, float, float)) &ofxPanel::setup, "parameters"_a, "filename"_a="settings.xml", "x"_a=10, "y"_a=10)
        .def("setup", (ofxPanel* (ofxPanel::*)(const string&, const string&, float, float)) &ofxPanel::setup, "collectionName"_a, "filename"_a="settings.xml", "x"_a=10, "y"_a=10)
        .def("add", [](ofxPanel &m, ofxToggle *gui)      { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxPanel *gui)       { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxButton *gui)      { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxIntSlider *gui)   { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxFloatSlider *gui) { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxVec2Slider *gui)  { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxVec3Slider *gui)  { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxVec4Slider *gui)  { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxPointSlider *gui) { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxColorSlider *gui) { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxShortColorSlider *gui) { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", [](ofxPanel &m, ofxFloatColorSlider *gui) { return m.add(gui);}, py::keep_alive<1,2>())
        .def("add", (void (ofxPanel::*)(const ofParameterGroup &)) &ofxPanel::add)
        // .def("test", [](ofxPanel &m, ofxToggle &toggle){ return m.add( toggle.setup("my toggle", true, 20, 20) );})
        .def("draw", [](ofxPanel &m){ return m.draw( );});
        



}