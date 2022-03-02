#ifndef SRI_H
#define SRI_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

#define MEASURINGDEPTH 5

typedef struct{
	char*  ForceRawData;
	float* ForceDataNowValue;
	float* ForceZeroValue;
	float* ForceMeasureingValue;
}STSRISensorData;

class SRISensor{
public:
	SRISensor();
	~SRISensor();
public:

	STcpServerInfo SriSensorServerinfo;  //SRI传感器服务器端信息
	STcpClientStatus SriGtRobotStatus;   //SRI客户端状态
	HANDLE GtRobotTcpClient;             //SRI客户端句柄
	
	short SriServerStatus;  //SRI服务器状态//0未连接1正常2异常3未采集
	bool  AskStatus;        //SRI是否建立问询

	char*   RecvRawData;    //SRI接收到的原始数据
	float*  SriDataZero;     //SRI传感器的零点
	float*  SriDataNow;      //SRI转换后的数据

	float*  SriDataHistory;   //用于检测SRI传感器是否掉线
	int     MeasuringDepthNow;//检测深度


public:
	short   SriConnect();
	short   SriDisconnect();
	short   SetSriFzZero();
	short   SetSriAskStatus(bool status);
	short   GetSriFzData(double& value);
	short   GetSriFzDataLoopRun();
	short   GetSriClientStatus(short& status);
	short   GetSriConnectStatus(short& status);

	short   SriParameterReset();

};

#endif // SRI_H