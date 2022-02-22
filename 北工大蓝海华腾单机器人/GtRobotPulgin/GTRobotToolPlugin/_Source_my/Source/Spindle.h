#ifndef SPINDLE_H
#define SPINDLE_H

#include "_Source_support/HEADER/COM/comm_struct_define.h"
#include "_Source_support/HEADER/COM/modbusrtu.h"
#include "_Source_support/HEADER/COM/plc_standard_class.h"
#include "_Source_support/HEADER/COM/robot_comm_interface.h"

class AbsSpindle{
public:
	AbsSpindle(){} //Ĭ�Ϲ��캯��
	~AbsSpindle(){}//Ĭ����������
public:
	/***********************************************************/
	short   SpindleType;          //��������,0�̸����� 1��������
	short   SpindleStatus;	      //�����ŷ�״̬,0���ŷ� 1���ŷ� 2���� 3�ر�
	short   SpindleComStatus;     //����ͨѶ״̬,0δ���� 1��������
	int     SpindleSpeedSet;      //�����趨�ٶ�
	double  SpindleSpeedReal;     //����ʵʱ�ٶ�
	double  SpindleAccaccelation; //������ٶ�
	double  SpindleDecelation;	  //������ٶ�
	short   SpindleDirection;     //���᷽��,-1��ʱ�� 0Ĭ��  1˳ʱ��
	/***********************************************************/
	virtual short SpindleServorStatusSet(short mStatus)=0;  //�����ŷ�����
	virtual short SpindleGetRealSpeed(int& mRealSpeed)=0;   //����ʵʱ�ٶȻ�ȡ
	virtual short SpindleSetSpeed(int mSetSpeed)=0;      //�����ٶȿ���
	virtual short SpindleSetDirection(short mDirection)=0;  //����������ת����
};

class CvtSpindle : public AbsSpindle{
public:
	CvtSpindle();
	~CvtSpindle();
public:
	unsigned short CvtSpindleModebusRtuSpeedReal;
	ModbusRTU CvtModebusRtu; //���ڿ����������ڵ�����ModbusRTU��ʵ��

	SModbusRtuCmdEx CvtGetSpeedSModbusRtuCmdEx; //��ȡ����ת��
	bool CvtGetSpeedIsFinish; //ָ�����
	bool CvtGetSpeedTimeout; //ָ�ʱ
	unsigned short CvtGetSpeedData;// ��ȡ��������

	SModbusRtuCmdEx CvtSetStatusSModbusRtuCmdEx; //��������״̬
	bool CvtSetStatusIsFinish; //ָ�����
	bool CvtSetStatusTimeout; //ָ�ʱ
	unsigned short CvtSetStatusData;// ָ������

	SModbusRtuCmdEx CvtSetSpeedSModbusRtuCmdEx;// �趨����ת��
	bool CvtSetSpeedIsFinish; // ָ�����
	bool CvtGetSpeedTimeout; // ָ�ʱ
	unsigned short CvtSetSpeedData; //ָ������

	SModbusRtuCmdEx CvtSetDirectionSModbusRtuCmdEx; // �趨���᷽��
	bool CvtSetDirectionIsFinish; // ָ�����
	bool CvtGetDirectionTimeout; // ָ�ʱ
	unsigned short CvtSetDirctionData; // ָ������

public:
	short SpindleServorStatusSet(short mStatus);  //�����ŷ�����
	short SpindleGetRealSpeed(int& mRealSpeed);   //����ʵʱ�ٶȻ�ȡ
	short SpindleSetSpeed(int mSetSpeed);         //�����ٶȿ���
	short SpindleSetDirection(short mDirection);  //����������ת����
public:
	short SpindleConnect();
};

#endif // SPINDLE_H