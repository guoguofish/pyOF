#pragma once
#include "ofMain.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ofJY901.h"

// #include "Python.h"
namespace py = pybind11;

enum arduinoUNO {
    FIRMATA_MAJOR_VERSION_        = FIRMATA_MAJOR_VERSION,
    FIRMATA_MINOR_VERSION_        = FIRMATA_MINOR_VERSION,
    FIRMATA_MAX_DATA_BYTES_       = FIRMATA_MAX_DATA_BYTES,
    FIRMATA_DIGITAL_MESSAGE_      = FIRMATA_DIGITAL_MESSAGE,
    FIRMATA_ANALOG_MESSAGE_       = FIRMATA_ANALOG_MESSAGE,
    FIRMATA_REPORT_ANALOG_        = FIRMATA_REPORT_ANALOG,
    FIRMATA_REPORT_DIGITAL_       = FIRMATA_REPORT_DIGITAL,
    FIRMATA_SET_PIN_MODE_         = FIRMATA_SET_PIN_MODE,
    FIRMATA_REPORT_VERSION_       = FIRMATA_REPORT_VERSION,
    FIRMATA_SYSTEM_RESET_         = FIRMATA_SYSTEM_RESET,
    FIRMATA_START_SYSEX_          = FIRMATA_START_SYSEX,
    FIRMATA_END_SYSEX_            = FIRMATA_END_SYSEX,
    FIRMATA_INPUT_                = FIRMATA_INPUT,
    FIRMATA_OUTPUT_               = FIRMATA_OUTPUT,
    FIRMATA_ANALOG_               = FIRMATA_ANALOG,
    FIRMATA_PWM_                  = FIRMATA_PWM,
    FIRMATA_SERVO_                = FIRMATA_SERVO,
    SHIFT_                        = SHIFT,
    I2C_                          = I2C,
    TOTAL_PIN_MODES_              = TOTAL_PIN_MODES,
    FIRMATA_SYSEX_SERVO_CONFIG_   = FIRMATA_SYSEX_SERVO_CONFIG,
    FIRMATA_SYSEX_FIRMATA_STRING_ = FIRMATA_SYSEX_FIRMATA_STRING,
    SHIFT_DATA_                   = SHIFT_DATA,
    I2C_REQUEST_                  = I2C_REQUEST,
    I2C_REPLY_                    = I2C_REPLY,
    I2C_CONFIG_                   = I2C_CONFIG,
    EXTENDED_ANALOG_              = EXTENDED_ANALOG,
    PIN_STATE_QUERY_              = PIN_STATE_QUERY,
    PIN_STATE_RESPONSE_           = PIN_STATE_RESPONSE,
    CAPABILITY_QUERY_             = CAPABILITY_QUERY,
    CAPABILITY_RESPONSE_          = CAPABILITY_RESPONSE,
    ANALOG_MAPPING_QUERY_         = ANALOG_MAPPING_QUERY,
    ANALOG_MAPPING_RESPONSE_      = ANALOG_MAPPING_RESPONSE,
    FIRMATA_SYSEX_REPORT_FIRMWARE_ = FIRMATA_SYSEX_REPORT_FIRMWARE,
    SAMPLING_INTERVAL_             = SAMPLING_INTERVAL,
    FIRMATA_SYSEX_NON_REALTIME_    = FIRMATA_SYSEX_NON_REALTIME,
    FIRMATA_SYSEX_REALTIME_        = FIRMATA_SYSEX_REALTIME,
    // arduino board settings
    ARD_TOTAL_DIGITAL_PINS_ = ARD_TOTAL_DIGITAL_PINS,
    ARD_TOTAL_ANALOG_PINS_  = ARD_TOTAL_ANALOG_PINS,
    ARD_TOTAL_PORTS_        = ARD_TOTAL_PORTS,
    // pin modes
    ARD_INPUT_              = ARD_INPUT,
    ARD_OUTPUT_             = ARD_OUTPUT,
    ARD_ANALOG_             = ARD_ANALOG,
    ARD_PWM_                = ARD_PWM,
    ARD_SERVO_              = ARD_SERVO,
    ARD_HIGH_               = ARD_HIGH,
    ARD_LOW_                = ARD_LOW,
    ARD_ON_                 = ARD_ON,
    ARD_OFF_                = ARD_OFF
};

class ofArduinoDevice {
public:
    ofArduinoDevice() { }
    virtual ~ofArduinoDevice() { clear(); }

    bool connect(const std::string & device, int baud = 57600) {  
        bSetupArduino = false;
        ard.sendReset();
        ofAddListener(ard.EInitialized, this, &ofArduinoDevice::onSetupArduino); 
        bool ret = ard.connect(device, baud);
        if (!ret) 
            ofRemoveListener(ard.EInitialized, this, &ofArduinoDevice::onSetupArduino);
        return ret;
    }

    void clear() { 
        if (bSetupArduino) {
            ofRemoveListener(ard.EDigitalPinChanged, this, &ofArduinoDevice::onDigitalPinChanged); 
            ofRemoveListener(ard.EAnalogPinChanged, this, &ofArduinoDevice::onAnalogPinChanged); 
            ofRemoveListener(ard.EStringReceived, this, &ofArduinoDevice::onStringReceived); 
            ofRemoveListener(ard.ESysExReceived, this, &ofArduinoDevice::onSysExReceived); 
        }
    }
    // virtual void draw() {}

    void update() {
        ard.update();
        if (bSetupArduino) {
            loopArduino();
        }
    }

    ofArduino ard;
    bool bSetupArduino; //是否已经初始化配置过 Arduino
    virtual void setupArduino() {}
    virtual void loopArduino() {}

    // Arduino 事件:
    void onSetupArduino(const int &version) {
        ofRemoveListener(ard.EInitialized, this, &ofArduinoDevice::onSetupArduino); 
        bSetupArduino = true;
        ofLogNotice() << ard.getFirmwareName(); 
        ofLogNotice() << "Firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
        setupArduino();
        ofAddListener(ard.EDigitalPinChanged, this, &ofArduinoDevice::onDigitalPinChanged); 
        ofAddListener(ard.EAnalogPinChanged, this, &ofArduinoDevice::onAnalogPinChanged); 
        ofAddListener(ard.EStringReceived, this, &ofArduinoDevice::onStringReceived); 
        ofAddListener(ard.ESysExReceived, this, &ofArduinoDevice::onSysExReceived); 
        // ofAddListener(ard.EProtocolVersionReceived, this, &ofArduinoDevice::onProtocolVersionReceived); 
        // ofAddListener(ard.EFirmwareVersionReceived, this, &ofArduinoDevice::onFirmwareVersionReceived); 
    }
    virtual void onDigitalPinChanged(const int &pin) {}
    virtual void onAnalogPinChanged(const int &pin) {}
    virtual void onStringReceived(const string &content) {}
    virtual void onSysExReceived(const vector<unsigned char> &msg) {}
    void onProtocolVersionReceived(const int &version) {
        ofLogNotice() << "Protocol Version = " << version;
    }
    void onFirmwareVersionReceived(const int &version) {
        ofLogNotice() << "Firmware Version = " << version;
    }
 
};

class pyArduinoDevice: public ofArduinoDevice {
public:
    using ofArduinoDevice::ofArduinoDevice;
    // void draw() override { PYBIND11_OVERLOAD(void, ofArduinoDevice, draw); }
    void setupArduino() override { PYBIND11_OVERLOAD(void, ofArduinoDevice, setupArduino); }
    void loopArduino()  override { PYBIND11_OVERLOAD(void, ofArduinoDevice, loopArduino); }
    // void onSetupArduino(const int &version) override { PYBIND11_OVERLOAD(void, ofArduinoDevice, onSetupArduino, version); }
    void onDigitalPinChanged(const int &pin) override { PYBIND11_OVERLOAD(void, ofArduinoDevice, onDigitalPinChanged, pin);}
    void onAnalogPinChanged(const int &pin) override { PYBIND11_OVERLOAD(void, ofArduinoDevice, onAnalogPinChanged, pin);}
    void onStringReceived(const string &content) override { PYBIND11_OVERLOAD(void, ofArduinoDevice, onStringReceived, content); }
    void onSysExReceived(const vector<unsigned char> &msg) override { PYBIND11_OVERLOAD(void, ofArduinoDevice, onSysExReceived, msg);}
};

    


void pybind_comm( py::module &m) {

    py::enum_<arduinoUNO>(m, "arduinoUNO")
        .value("ARD_INPUT",  arduinoUNO::ARD_INPUT_)
        .value("ARD_OUTPUT", arduinoUNO::ARD_OUTPUT_)
        .value("ARD_ANALOG", arduinoUNO::ARD_ANALOG_)
        .value("ARD_PWM",    arduinoUNO::ARD_PWM_)
        .value("ARD_SERVO",  arduinoUNO::ARD_SERVO_)
        .value("ARD_HIGH",   arduinoUNO::ARD_HIGH_)
        .value("ARD_LOW",    arduinoUNO::ARD_LOW_)
        .value("ARD_ON",     arduinoUNO::ARD_ON_)
        .value("ARD_OFF",    arduinoUNO::ARD_OFF_);

    py::class_<ofSerial>(m, "ofSerial")
        .def(py::init<>())
        .def("listDevices", &ofSerial::listDevices)
        .def("getDeviceList", &ofSerial::getDeviceList)
        .def("close", &ofSerial::close)
        .def("available", &ofSerial::available)
        .def("setup", (bool (ofSerial::*)()) &ofSerial::setup)
        .def("setup", (bool (ofSerial::*)(string, int)) &ofSerial::setup)
        .def("setup", (bool (ofSerial::*)(int, int)) &ofSerial::setup)
        .def("readByte", &ofSerial::readByte)
        .def("readBytes", &ofSerial::readBytes)
        .def("writeBytes", &ofSerial::writeBytes)
        .def("writeByte", &ofSerial::writeByte)
        .def("flush", &ofSerial::flush)
        .def("drain", &ofSerial::drain);

    py::class_<ofJY901>(m, "ofJY901")
        .def(py::init<>())
        .def("connect",    &ofJY901::connect)
        .def("isReady",    &ofJY901::isReady)
        .def("disconnect", &ofJY901::disconnect)
        .def("update",     &ofJY901::update)
        // .def("printData",  &ofJY901::printData)
        .def("getYear",    [] ( ofJY901 &m) {return (unsigned short)m.stcTime.ucYear + 2000;})
        .def("getMonth",   [] ( ofJY901 &m) {return m.stcTime.ucMonth;})
        .def("getDay",     [] ( ofJY901 &m) {return m.stcTime.ucDay;})
        .def("getHour",    [] ( ofJY901 &m) {return m.stcTime.ucHour;})
        .def("getMinute",  [] ( ofJY901 &m) {return m.stcTime.ucMinute;})
        .def("getSecond",     [] ( ofJY901 &m) {return m.stcTime.ucSecond;})
        .def("getMiliSecond", [] ( ofJY901 &m) {return m.stcTime.usMiliSecond;})
        .def("getTemperature", [] ( ofJY901 &m) {return (float)m.stcAngle.T/100;})
        .def("getAcc",        [] ( ofJY901 &m) {return py::make_tuple((float)m.stcAcc.a[0]/32768*16, (float)m.stcAcc.a[1]/32768*16, (float)m.stcAcc.a[2]/32768*16);})
        .def("getAngularVel", [] ( ofJY901 &m) {return py::make_tuple((float)m.stcGyro.w[0]/32768*2000, (float)m.stcGyro.w[1]/32768*2000, (float)m.stcGyro.w[2]/32768*2000);})
        .def("getAngle",      [] ( ofJY901 &m) {return py::make_tuple((float)m.stcAngle.Angle[0]/32768*180, (float)m.stcAngle.Angle[1]/32768*180, (float)m.stcAngle.Angle[2]/32768*180);})
        .def("getMag",        [] ( ofJY901 &m) {return py::make_tuple(m.stcMag.h[0], m.stcMag.h[1], m.stcMag.h[2]);})
        .def("getQuat",       [] ( ofJY901 &m) {return py::make_tuple((float)m.stcQuat.sR/32768, (float)m.stcQuat.sI/32768, (float)m.stcQuat.sJ/32768, (float)m.stcQuat.sK/32768);})
        .def("getPress",      [] ( ofJY901 &m) {return py::make_tuple(m.stcPress.lPressure, (float)m.stcPress.lAltitude/100);})
        .def("getGPS",        [] ( ofJY901 &m) {return py::make_tuple((float)m.stcGPSV.sGPSHeight/10, (float)m.stcGPSV.sGPSYaw/10, (double)m.stcGPSV.lGPSVelocity/1000);})
        .def("getLonLat",     [] ( ofJY901 &m) {
            py::tuple londdmm= py::make_tuple((double)m.stcLonLat.lLon/1e7, (double)(m.stcLonLat.lLon % 10000000)/1e5);
            py::tuple latddmm= py::make_tuple((double)m.stcLonLat.lLat/1e7, (double)(m.stcLonLat.lLat % 10000000)/1e5);
            return py::make_tuple(londdmm, latddmm);
        });

    py::class_<ofArduino>(m, "ofArduino")
        .def(py::init<>())
        .def("connect", &ofArduino::connect)
        .def("isInitialized", &ofArduino::isInitialized)
        .def("isArduinoReady", &ofArduino::isArduinoReady)
        .def("disconnect", &ofArduino::disconnect)
        .def("update", &ofArduino::update)
        .def("sendDigitalPinMode", &ofArduino::sendDigitalPinMode)
        .def("sendAnalogPinReporting", &ofArduino::sendAnalogPinReporting)
        .def("setUseDelay", &ofArduino::setUseDelay)
        .def("setDigitalHistoryLength", &ofArduino::setDigitalHistoryLength)
        .def("setAnalogHistoryLength", &ofArduino::setAnalogHistoryLength)
        .def("setStringHistoryLength", &ofArduino::setStringHistoryLength)
        .def("setSysExHistoryLength", &ofArduino::setSysExHistoryLength)
        .def("sendDigital", &ofArduino::sendDigital)
        .def("sendPwm", &ofArduino::sendPwm)
        .def("sendSysEx", &ofArduino::sendSysEx)
        .def("sendString", &ofArduino::sendString)
        .def("sendProtocolVersionRequest", &ofArduino::sendProtocolVersionRequest)
        .def("sendFirmwareVersionRequest", &ofArduino::sendFirmwareVersionRequest)
        .def("sendReset", &ofArduino::sendReset)
        .def("sendSysExBegin", &ofArduino::sendSysExBegin)
        .def("sendSysExEnd", &ofArduino::sendSysExEnd)
        .def("sendByte", &ofArduino::sendByte)
        .def("sendValueAsTwo7bitBytes", &ofArduino::sendValueAsTwo7bitBytes)
        .def("getPwm", &ofArduino::getPwm)
        .def("getDigital", &ofArduino::getDigital)
        .def("getAnalog", &ofArduino::getAnalog)
        .def("getSysEx", &ofArduino::getSysEx)
        .def("getMajorProtocolVersion", &ofArduino::getMajorProtocolVersion)
        .def("getMinorProtocolVersion", &ofArduino::getMinorProtocolVersion)
        .def("getMajorFirmwareVersion", &ofArduino::getMajorFirmwareVersion)
        .def("getMinorFirmwareVersion", &ofArduino::getMinorFirmwareVersion)
        .def("getFirmwareName", &ofArduino::getFirmwareName)
        .def("getDigitalHistory", &ofArduino::getDigitalHistory, py::return_value_policy::reference)
        .def("getAnalogHistory", &ofArduino::getAnalogHistory, py::return_value_policy::reference)
        .def("getSysExHistory", &ofArduino::getSysExHistory, py::return_value_policy::reference)
        .def("getStringHistory", &ofArduino::getStringHistory, py::return_value_policy::reference)
        .def("getDigitalPinMode", &ofArduino::getDigitalPinMode)
        .def("getAnalogPinReporting", &ofArduino::getAnalogPinReporting)
        .def("getValueFromTwo7bitBytes", &ofArduino::getValueFromTwo7bitBytes)
        .def_readonly("EDigitalPinChanged", &ofArduino::EDigitalPinChanged)
        .def_readonly("EAnalogPinChanged", &ofArduino::EAnalogPinChanged)
        .def_readonly("ESysExReceived", &ofArduino::ESysExReceived)
        .def_readonly("EProtocolVersionReceived", &ofArduino::EProtocolVersionReceived)
        .def_readonly("EFirmwareVersionReceived", &ofArduino::EFirmwareVersionReceived)
        .def_readonly("EInitialized", &ofArduino::EInitialized)
        .def_readonly("EStringReceived", &ofArduino::EStringReceived);

    m.attr("ofStandardFirmata") = m.attr("ofArduino");

    py::class_<ofArduinoDevice, pyArduinoDevice>(m, "ArduinoDevice", py::dynamic_attr())
        .def(py::init<>())
        .def("connect",             &pyArduinoDevice::connect, "connect(serialDeviceName, baud=57600)")
        .def("update",              &pyArduinoDevice::update)
        .def("setupArduino",        &pyArduinoDevice::setupArduino)
        .def("loopArduino",         &pyArduinoDevice::loopArduino)
        .def("onDigitalPinChanged", &pyArduinoDevice::onDigitalPinChanged)
        .def("onAnalogPinChanged",  &pyArduinoDevice::onAnalogPinChanged)
        .def("onStringReceived",    &pyArduinoDevice::onStringReceived)
        .def("onSysExReceived",     &pyArduinoDevice::onSysExReceived)
        .def_readonly("ard",        &pyArduinoDevice::ard);
        // .def("clear",  &pyArduinoDevice::clear)
}