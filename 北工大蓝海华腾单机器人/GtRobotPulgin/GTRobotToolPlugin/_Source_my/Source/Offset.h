#ifndef OFFSET_H
#define OFFSET_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class Offset{
public:
	bool bStatusOnOff;          //��̬ƫ�ƿ���
	double dValueOffsetSum[8];  //��������ֵ

	double dValueManOffsetStep;      //�ֶ�����
	double RsiManOffsetAbsNow[8];    //�ֶ���ǰ�ܺ�
	double RsiManOffsetAbsHistory[8];//�ֶ�ǰ�����ܺ�
	double RsiManOffsetRela[8];      //ÿ��ƫ�Ƶ���

	STcpServerInfo SriServerinfo;        //SRI����������������Ϣ
	STcpClientStatus SriTcpConnectStatus;//SRI�ͻ���״̬
	HANDLE SriTcpClient;                 //SRI�ͻ��˾��
	char SriRecvData[32];                //SRI���յ���ԭʼ����
	bool  bStatusSriConnect;             //SRI�Ƿ�������
	short rSriStatusConnect;             //SRI���ص�ǰ����״̬

	bool   bStatusSriAsk;                //SRI�Ƿ�����ѯ
	float  RsiSriDataZero[8];            //SRI�����������
	double RsiSriDataNow[8];             //SRIת���������

	double dValuePlaserValtageNow;    //�㼤�⵱ǰֵ
	double dValuePlaserValtageSet;	  //�㼤���趨ֵ

	bool bStatusSriSet;            //�Ƿ�������
	bool bStatusPlaesrOffset;      //�Ƿ����㼤�����
	
	double dValueSetFz;            //�����趨ֵ��С
	double RsiSriOffsetAbs[8];     //����ƫ����ֵ
	double RsiSriOffsetRela[8];    //����ÿ��ƫ�Ƶ���

	double RsiPlaserOffsetRela[8]; //�㼤�����ƫ����

	double RsiFswMartix[11][7];    //��λ���ƻ�Ͼ���

public:
	Offset();
	~Offset();

	void   RsiStatusSet();

	double RsiRreadOffsetY(); //��ȡRSI Y��ƫ��
	double RsiRreadOffsetZ(); //��ȡRSI Z��ƫ��
	void   RsiManOffsetY(short Dir);
	void   RsiManOffsetZ(short Dir);

	void   RsiSriConnect();
	void   RsiReadSriConnectStatus();
	void   RsiSriSetZero();

	void   RsiDoOffset();    //���ж�̬ƫ��
	void   RsiAskManOffset();//��ѯ�ֶ�ƫ��
	void   RsiReadSriData();

	void   RsiFswDoOffset();

};

#endif // OFFSET_H