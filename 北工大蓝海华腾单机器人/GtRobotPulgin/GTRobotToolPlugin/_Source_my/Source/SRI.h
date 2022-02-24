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

	STcpServerInfo SriSensorServerinfo;  //SRI����������������Ϣ
	STcpClientStatus SriGtRobotStatus;   //SRI�ͻ���״̬
	HANDLE GtRobotTcpClient;             //SRI�ͻ��˾��
	
	bool  bStatusSriConnect;             //SRI�Ƿ�������
	short rSriStatusConnect;             //SRI���ص�ǰ����״̬
	bool   bStatusSriAsk;                //SRI�Ƿ�����ѯ

	char  RecvRawData[32];        //SRI���յ���ԭʼ����
	float  SriDataZero[8];        //SRI�����������
	float  SriDataNow[8];         //SRIת���������


public:
	void   RsiSriConnect();
	void   RsiReadSriConnectStatus();
	void   RsiSriSetZero();
	void   RsiReadSriData();
	void   RsiFswDoOffset();

};

#endif // SRI_H