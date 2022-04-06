#ifndef SRI_H
#define SRI_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

#define MEASURINGDEPTH 5 //������
#define DISDAQ 0 //�趨���ɼ�
#define DAQING 1 //�趨�ɼ�

#define CONNECTING 1 //�趨����
#define DISCONNECT 2 //�趨�Ͽ�

#define CLIENT_DISCONNECT 3//ϵͳ�ж��ͻ���δ����
#define CLIENT_CONNECTED 1 //ϵͳ�ж��ͻ����Ѿ�����
#define CLIENT_CONNECTING 2//ϵͳ�ж��ͻ�����������

#define MEA_DISCONNECT 4 //��⻹δ�������� 
#define MEA_CLIENT_DISCONNECT 1 //���ͻ��˵���
#define MEA_NORMAL 2     //��ⷴ������
#define MEA_SRIERROR 3   //��ⷴ������

class SRISensor{
public:
	SRISensor();
	~SRISensor();
public:

	STcpServerInfo SriSensorServerinfo;  //SRI����������������Ϣ
	HANDLE GtRobotTcpClient;             //SRI�ͻ��˾��

	bool  SetConnect;       //SRI�Ƿ�������
	STcpClientStatus SriGtRobotStatus;   //SRI�ͻ���״̬
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