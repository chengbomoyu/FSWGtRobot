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

	STcpServerInfo SriSensorServerinfo;  //SRI����������������Ϣ
	STcpClientStatus SriGtRobotStatus;   //SRI�ͻ���״̬
	HANDLE GtRobotTcpClient;             //SRI�ͻ��˾��
	
	short SriServerStatus;  //SRI������״̬
	bool  AskStatus;        //SRI�Ƿ�����ѯ

	char*   RecvRawData;    //SRI���յ���ԭʼ����
	float*  SriDataZero;     //SRI�����������
	float*  SriDataNow;      //SRIת���������

	float*  SriDataHistory;   //���ڼ��SRI�������Ƿ����
	int     MeasuringDepthNow;//������


public:
	short   SriConnect();
	short   SriDisconnect();
	short   SetSriFzZero(float& FzData);
	short   GetSriFzData(float& FzZeroData);
	short   GetSriClientStatus(short& status);
	short   GetSriConnectStatus(short& status,float MeasureValue);

};

#endif // SRI_H