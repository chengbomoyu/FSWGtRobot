#ifndef CVT_SPINDLE_H
#define CVT_SPINDLE_H

#include "_Source_support/HEADER/COM/comm_struct_define.h"
#include "_Source_support/HEADER/COM/modbusrtu.h"
#include "_Source_support/HEADER/COM/plc_standard_class.h"
#include "_Source_support/HEADER/COM/robot_comm_interface.h"

#define NORMAL 1
#define REVERSE -1

class CvtSpindle{
public:
	CvtSpindle();
	~CvtSpindle();
public:
	short   SpindleType;          //��������,0�̸����� 1��������
	short   SpindleStatus;	      //�����ŷ�״̬,0���ŷ� 1���ŷ� 2���� 3�ر�
	short   SpindleComStatus;     //����ͨѶ״̬,0δ���� 1��������
	int     SpindleSpeedSet;      //�����趨�ٶ�
	double  SpindleSpeedReal;     //����ʵʱ�ٶ�
	double  SpindleAccaccelation; //������ٶ�
	double  SpindleDecelation;	  //������ٶ�
	short   SpindleDirection;     //���᷽��,-1��ʱ�� 0Ĭ�� 1˳ʱ��
public:
	ModbusRTU* CvtModebusRtu;     //���ڿ����������ڵ�����ModbusRTU��ʵ��

	SModbusRtuCmdEx CvtGetSpeedSModbusRtuCmdEx;//��ȡ����ת��
	bool CvtGetSpeedIsFinish;      //ָ�����
	bool CvtGetSpeedTimeout;       //ָ�ʱ
	unsigned short CvtGetSpeedData;//��ȡ��������

	SModbusRtuCmdEx CvtSetStatusSModbusRtuCmdEx;//��������״̬
	bool CvtSetStatusIsFinish;      //ָ�����
	bool CvtSetStatusTimeout;       //ָ�ʱ
	unsigned short CvtSetStatusData;//ָ������

	SModbusRtuCmdEx CvtSetSpeedSModbusRtuCmdEx;//�趨����ת��
	bool CvtSetSpeedIsFinish;      //ָ�����
	bool CvtSetSpeedTimeout;       //ָ�ʱ
	unsigned short CvtSetSpeedData;//ָ������

	SModbusRtuCmdEx CvtSetDirectionSModbusRtuCmdEx;//�趨���᷽��
	bool CvtSetDirectionIsFinish;     //ָ�����
	bool CvtSetDirectionTimeout;      //ָ�ʱ
	unsigned short CvtSetDirctionData;//ָ������

public:
	short SpindleConnect();
	short SpindleServorStatusSet(short mStatus);  //�����ŷ�����
	short SpindleGetRealSpeed(int& mRealSpeed);   //����ʵʱ�ٶȻ�ȡ
	short SpindleSetSpeed(int mSetSpeed);         //�����ٶȿ���
private:
	short SpindleSetDirection(short mDirection);  //����������ת����
};

#endif // CVT_SPINDLE_H