// JY901 是一种姿态传感器，集成陀螺仪，加速度计，地磁场传感器, 可连接GPS。支持串口和IIC接口
// 测量维度:加速度:3 维,角速度:3 维,磁场:3 维,角度:3 维,气压:1 维,GPS:3 维
// 量程:加速度:±16g,角速度:±2000°/s,角度±180°
// 分辨率:加速度:6.1e-5g,角速度:7.6e-3°/s
// 稳定性:加速度:0.01g,角速度 0.05°/s。
// 姿态测量稳定度:0.01°
// 数据输出内容:时间、加速度、角速度、角度、磁场、端口状态、气压(JY-901B)、高度 (JY-901B)、经纬度(需连接 GPS)、地速(需连接 GPS)
// 数据输出频率 0.1Hz~200Hz
// 数据接口: 串口(TTL 电平,波特率支持 2400、4800、9600、19200、38400、57600、115200、230400、460800、921600),   I2C(最大支持高速 IIC 速率 400K)
#pragma once
#include "ofUtils.h"
#include "ofSerial.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

namespace JY901 {
	#define SAVE        0x00
	#define CALSW       0x01
	#define RSW         0x02
	#define RRATE       0x03
	#define BAUD        0x04
	#define AXOFFSET    0x05
	#define AYOFFSET    0x06
	#define AZOFFSET    0x07
	#define GXOFFSET    0x08
	#define GYOFFSET    0x09
	#define GZOFFSET    0x0a
	#define HXOFFSET    0x0b
	#define HYOFFSET    0x0c
	#define HZOFFSET    0x0d
	#define D0MODE      0x0e
	#define D1MODE      0x0f
	#define D2MODE      0x10
	#define D3MODE      0x11
	#define D0PWMH      0x12
	#define D1PWMH      0x13
	#define D2PWMH      0x14
	#define D3PWMH      0x15
	#define D0PWMT      0x16
	#define D1PWMT      0x17
	#define D2PWMT      0x18
	#define D3PWMT      0x19
	#define IICADDR     0x1a
	#define LEDOFF      0x1b
	#define GPSBAUD     0x1c
	
	#define YYMM        0x30
	#define DDHH        0x31
	#define MMSS        0x32
	#define MS          0x33
	#define AX          0x34
	#define AY          0x35
	#define AZ          0x36
	#define GX          0x37
	#define GY          0x38
	#define GZ          0x39
	#define HX          0x3a
	#define HY          0x3b
	#define HZ          0x3c
	#define Roll        0x3d
	#define Pitch       0x3e
	#define Yaw         0x3f
	#define TEMP        0x40
	#define D0Status    0x41
	#define D1Status    0x42
	#define D2Status    0x43
	#define D3Status    0x44
	#define PressureL   0x45
	#define PressureH   0x46
	#define HeightL     0x47
	#define HeightH     0x48
	#define LonL        0x49
	#define LonH        0x4a
	#define LatL        0x4b
	#define LatH        0x4c
	#define GPSHeight   0x4d
	#define GPSYAW      0x4e
	#define GPSVL       0x4f
	#define GPSVH       0x50
	
	#define DIO_MODE_AIN   0
	#define DIO_MODE_DIN   1
	#define DIO_MODE_DOH   2
	#define DIO_MODE_DOL   3
	#define DIO_MODE_DOPWM 4
	#define DIO_MODE_GPS   5

	struct STime {
		unsigned char  ucYear;
	    unsigned char  ucMonth;
	    unsigned char  ucDay;
	    unsigned char  ucHour;
	    unsigned char  ucMinute;
	    unsigned char  ucSecond;
	    unsigned short usMiliSecond;
	};
	struct SAcc {
		short a[3]; //加速度
		short T;    //温度
	};
	struct SGyro
	{
		short w[3];//角速度
		short T;   //温度
	};
	struct SAngle
	{
		short Angle[3];//角度
		short T;       //温度
	};
	struct SMag
	{
		short h[3]; // 磁场
		short T;    // 温度
	};
	struct SDStatus
	{
		short sDStatus[4]; // D0-D3的端口状态
	};
	struct SPress
	{
		long lPressure; // 气压 Pa
		long lAltitude; // 高度 cm /100=> m
	};
	struct SLonLat
	{
		long lLon; //经度 ddmm.mmmmm dd度mm.mmmmm分
		long lLat; //纬度 ddmm.mmmmm dd度mm.mmmmm分
	};
	struct SGPSV
	{
		short sGPSHeight; //海拔 m
		short sGPSYaw;   //航向 
		long lGPSVelocity; //地速 km/h
	};
	struct SQuaternions
	{
		short sR;
		short sI;
		short sJ;
		short sK;
	};
}

      


class CJY901 {
public:
	CJY901 () {}
	struct JY901::STime        stcTime;    //  时间
	struct JY901::SAcc         stcAcc;     //  3轴加速度 g
	struct JY901::SGyro        stcGyro;    //  3轴角速度 度/s
	struct JY901::SAngle       stcAngle;   //  3轴角度
	struct JY901::SMag         stcMag;      //  3轴磁场 mG
	struct JY901::SDStatus     stcDStatus;  // 4个数字IO口的值
	struct JY901::SPress       stcPress;   // 压力Pa
	struct JY901::SLonLat      stcLonLat;  // 经纬度
	struct JY901::SGPSV        stcGPSV;    // GPS导航数据, 海拔m，航向，地速km/h
	struct JY901::SQuaternions stcQuat;  // 四元数

	void CopeSerialData(char ucData[], unsigned short usLength) {
		static unsigned char chrTemp[1024];
		// static unsigned char ucRxCnt = 0 ;
		static unsigned short usRxLength = 0;
		memcpy(chrTemp,ucData,usLength);
		usRxLength += usLength;
		while (usRxLength >= 11) {
			if (chrTemp[0] != 0x55)
	        {
				usRxLength--;
				memcpy(&chrTemp[0],&chrTemp[1],usRxLength);                        
	            continue;
	        }
	        // 较验和检测 sum位
	        unsigned char i=0, summ=0;
        	for (i=0;i<10;i++) {
        		summ += chrTemp[i];
        		if (summ > 0xff) {
        			summ = ~summ;
        			summ += 1;
        		}
        	}
        	// summ = summ & 0xff;
        	if ( summ == chrTemp[10]) {

				switch(chrTemp[1])
				{
					case 0x50:	memcpy(&stcTime    , &chrTemp[2] , 8);break;
					case 0x51:	memcpy(&stcAcc     , &chrTemp[2] , 8);break;
					case 0x52:	memcpy(&stcGyro    , &chrTemp[2] , 8);break;
					case 0x53:	memcpy(&stcAngle   , &chrTemp[2] , 8);break;
					case 0x54:	memcpy(&stcMag     , &chrTemp[2] , 8);break;
					case 0x55:	memcpy(&stcDStatus , &chrTemp[2] , 8);break;
					case 0x56:	memcpy(&stcPress   , &chrTemp[2] , 8);break;
					case 0x57:	memcpy(&stcLonLat  , &chrTemp[2] , 8);break;
					case 0x58:	memcpy(&stcGPSV    , &chrTemp[2] , 8);break;
					case 0x59:	memcpy(&stcQuat    , &chrTemp[2] , 8);break;
				}
        	}
			usRxLength -= 11;
			memcpy(&chrTemp[0],&chrTemp[11],usRxLength);
		}
	}
};

class ofJY901: public CJY901 {
public:
	ofJY901(): connected(false), connectTime(0.0f) {}
	~ofJY901() { _port.close(); }

	bool connect(const std::string & device, int baud = 57600) {
		connectTime = ofGetElapsedTimef();
		_port.listDevices();
		connected = _port.setup(device.c_str(), baud);
		return connected;
	}

	void disconnect() {
		_port.close();
	}
	void update() {
		vector<unsigned char> bytesToProcess;
		int bytesToRead = _port.available();
		// cout << bytesToRead <<endl;
		if (bytesToRead >0) {
			bytesToProcess.resize(bytesToRead);
			_port.readBytes(&bytesToProcess[0], bytesToRead);
			for (int i=0; i<bytesToRead; i++) {
				// processData( (char)(bytesToProcess[i]));
				tempBuffer[i] =  (char)(bytesToProcess[i]) ;
			}
			CopeSerialData(&tempBuffer[0], bytesToRead);
		}
	}
	bool isReady() const {
		return connected;
	}

	// void printData() {
	// 	cout<< "Acc: "<<(float)stcAcc.a[0]/32768*16 << " " << (float)stcAcc.a[1]/32768*16 << " " << (float)stcAcc.a[2]/32768*16 <<endl;
	// 	cout<< "Gyro: "<<(float)stcGyro.w[0]/32768*2000 << " " << (float)stcGyro.w[1]/32768*2000 << " " << (float)stcGyro.w[2]/32768*2000<<endl;
	// 	cout<< "Angle: "<<(float)stcAngle.Angle[0]/32768*180 << " " << (float)stcAngle.Angle[1]/32768*180 << " " << (float)stcAngle.Angle[2]/32768*180 <<endl;
	// 	cout<< "Mag: "<<stcMag.h[0] << " " << stcMag.h[1] << " " << stcMag.h[2] <<endl;
	// 	cout<< "Pressure: "<< stcPress.lPressure << " Height: " << stcPress.lAltitude/100 <<endl;
	// 	cout<< "DStatus: "<< stcDStatus.sDStatus[0] << " " << stcDStatus.sDStatus[1]<< " " << stcDStatus.sDStatus[2] << " " << stcDStatus.sDStatus[3]<<endl;
	// 	cout<< "Longitude: "<< stcLonLat.lLon/10000000 <<"Deg "<< (double)(stcLonLat.lLon % 10000000)/1e5 << "m Lattitude:  " << stcLonLat.lLat/10000000 << " Deg " << (double)(stcLonLat.lLat % 10000000)/1e5<<" m" <<endl;
	// }
protected:
	ofSerial _port;
	mutable bool connected; 
	float connectTime; 

private:
	char tempBuffer[1024];
};