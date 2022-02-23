#ifndef CFSW_H
#define CFSW_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class CFSW{
public:
	bool bStatusOnOff;
	bool bStatusAllow;
	int dValueRsiSetCdefficient;
	double dValueOffsetSum[8];

	bool bStatusManSet;
	double dValueManOffsetStep;
	double RsiManOffsetAbsNow[8];
	double RsiManOffsetAbsHistory[8];
	double RsiManOffsetRela[8];      //ÿ��ƫ�Ƶ���

	STcpServerInfo SriServerinfo;
	STcpClientStatus SriTcpConnectStatus;
	HANDLE SriTcpClient;
	char SriRecvData[32];
	bool bStatusSriConnect;
	short rSriStatusConnect;

	UINT temDataInt;
	float temValueFz;
	double temRsiSriData;

	bool bStatusSriSet;
	bool bStatusSriAsk;
	double dValueSetFz;            //�����趨ֵ��С

	double dValuePlaserValtageSet; //�㼤���趨��ѹ
	bool bStatusPlaserdaq;         //�㼤��ɼ�״̬
	bool bStatusPlaesrOffset;      //�㼤�����״̬
	double dValuePlaserValtageNow; //�㼤���ȡ��ѹ
	double RsiPlaserOffsetRela[8]; //�㼤��ƫ�ƾ���
	double RsiPlaserOffsetAbs[8];
	double dValuePlaserThickness;
	
	double RsiSriDataNow[8];
	double RsiSriDataNowFliter[8];
	double RsiSriDataFliter[12];
	int    RsiSriDataFliterN;
	double RsiSriDataFliterSum;

	double RsiSriDataNowFliterA;

	double RsiSriDataOfsset[8];
	float  RsiSriDataZero[8];
	double RsiSriOffsetAbs[8];
	double RsiSriOffsetRela[8];      //ÿ��ƫ�Ƶ���

	double RsiFswMartix[11][7];
/***********************************************************/
	bool   bj_spindle_status;	              //�����ŷ�״̬
	bool   bj_spindle_power;	              //���Ὺ��	

	short  bj_spindle_speed_set;	          //�����趨�ٶ�
	double bj_spindle_accaccelation;          //������ٶ�
	double bj_spindle_decelation;	          //������ٶ�
	int    bj_spindle_direction;              //���᷽�� -1��ʾ��ʱ�� 0 Ĭ��  1˳ʱ��
	short  bj_spindle_num; 	                  //�������   Ĭ����8
	double  bj_spindle_speed_real; 	          //����ʵʱ�ٶ�
/***********************************************************/
public:
	CFSW();
	~CFSW();

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

	void   RsiReadPlaserData();
	void   RsiFswDoOffset();

	void bj_spindle_servor_status(bool servor_status);    //�����ŷ�����
	void bj_spindle_power_control(bool power);            //���Ὺ�ؿ���
	void bj_spindle_speed_real_get();                     //����ʵʱ�ٶȻ�ȡ
	void bj_spindle_speed_control(int speed_addnum);      //�����ٶȿ���
	void bj_spindle_speed_quickset(int speed);
};

#endif // CRSI_H