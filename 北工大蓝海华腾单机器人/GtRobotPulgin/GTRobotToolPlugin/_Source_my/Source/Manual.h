#ifndef MANUAL_H
#define MANUAL_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class ManualOffset{
public:
	ManualOffset(); //���캯��
	~ManualOffset();//��������
public:

	bool   ManOffsetStatus;     //��̬ƫ�ƿ���

	double  ManOffsetStep;      //�ֶ�����
	double* ManOffsetSumNow;    //�ֶ��������ܺ�[8]
	double* ManOffsetSumLast;   //�ֶ�ǰ�����ܺ�[8]
	double* ManOffsetRela;      //������ƫ�Ƶ���[8]

	short   ManualSetStatus(bool status);
	short   ManualSetStep(double step);
	short   ManSetOffsetY(short Dir);
	short   ManSetOffsetZ(short Dir);
	short   ManGetOffsetYSum(double& value);
	short   ManGetOffsetZSum(double& value);
	short   ManGetOffsetY(double& value);
	short   ManGetOffsetZ(double& value);

	short ManOffsetParameterReset();
};

#endif // MANUAL_H