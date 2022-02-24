#ifndef SRI_H
#define SRI_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class SRISensor{
public:
	SRISensor();
	~SRISensor();
public:

	STcpServerInfo SriSensorServerinfo;  //SRI传感器服务器端信息
	STcpClientStatus SriGtRobotStatus;   //SRI客户端状态
	HANDLE GtRobotTcpClient;             //SRI客户端句柄
	
	bool  bStatusSriConnect;             //SRI是否建立连接
	short rSriStatusConnect;             //SRI返回当前连接状态
	bool   bStatusSriAsk;                //SRI是否建立问询

	char  RecvRawData[32];        //SRI接收到的原始数据
	float  SriDataZero[8];        //SRI传感器的零点
	float  SriDataNow[8];         //SRI转换后的数据


public:
	void   RsiSriConnect();
	void   RsiReadSriConnectStatus();
	void   RsiSriSetZero();
	void   RsiReadSriData();
	void   RsiFswDoOffset();

};

#endif // SRI_H