#ifndef SRI_H
#define SRI_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

#define MEASURINGDEPTH 5 //检测深度
#define DISDAQ 0 //设定不采集
#define DAQING 1 //设定采集

#define CONNECTING 1 //设定连接
#define DISCONNECT 2 //设定断开

#define CLIENT_DISCONNECT 3//系统判定客户端未连接
#define CLIENT_CONNECTED 1 //系统判定客户端已经连接
#define CLIENT_CONNECTING 2//系统判定客户端正在连接

#define MEA_DISCONNECT 4 //检测还未建立连接 
#define MEA_CLIENT_DISCONNECT 1 //检测客户端掉线
#define MEA_NORMAL 2     //检测反馈正常
#define MEA_SRIERROR 3   //检测反馈错误

class SRISensor{
public:
	SRISensor();
	~SRISensor();
public:

	STcpServerInfo SriSensorServerinfo;  //SRI传感器服务器端信息
	HANDLE GtRobotTcpClient;             //SRI客户端句柄

	bool  SetConnect;       //SRI是否建立连接
	STcpClientStatus SriGtRobotStatus;   //SRI客户端状态
	short SriServerStatus;  //SRI服务器状态
	bool  AskStatus;        //SRI是否建立问询

	char*   RecvRawData;     //SRI接收到的原始数据
	float*  SriDataZero;     //SRI传感器的零点
	float*  SriDataNow;      //SRI转换后的数据

	float*  SriDataHistory;   //用于检测SRI传感器是否掉线
	int     MeasuringDepthNow;//检测深度

public:
	short   GetSriFzDataLoopRun();

	short   SriConnect();
	short   SriDisconnect();
	short   SetSriFzZero();
	short   SetSriAskStatus(bool status);
	short   GetSriFzData(double& value);
	short   GetSriClientStatus(short& status);
	short   GetSriConnectStatus(short& status);
	short   SriParameterReset();
};

#endif // SRI_H