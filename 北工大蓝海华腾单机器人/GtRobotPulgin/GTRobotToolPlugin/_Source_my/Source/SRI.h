#ifndef SRI_H
#define SRI_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

#define MEASURINGDEPTH 5

#define DISCONNECT 0
#define NORMAL 1
#define ERROR 2
#define DISDAQ 3

class SRISensor{
public:
	SRISensor();
	~SRISensor();
public:

	STcpServerInfo SriSensorServerinfo;  //SRI����������������Ϣ
	STcpClientStatus SriGtRobotStatus;   //SRI�ͻ���״̬
	HANDLE GtRobotTcpClient;             //SRI�ͻ��˾��
	
	short SriServerStatus;  //SRI������״̬
	bool  AskStatus;        //SRI�Ƿ�����ѯ

	char*   RecvRawData;     //SRI���յ���ԭʼ����
	float*  SriDataZero;     //SRI�����������
	float*  SriDataNow;      //SRIת���������

	float*  SriDataHistory;   //���ڼ��SRI�������Ƿ����
	int     MeasuringDepthNow;//������

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