#ifndef OFFSETEX_H
#define OFFSETEX_H

#include "_Source_my/Source/Manual.h"
#include "_Source_my/Source/SRI.h"

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class OffsetEx{
public:
	OffsetEx();
	~OffsetEx();
public:
	bool    OffsetStatus;                 //��̬ƫ�ƿ���
	bool    OffsetForceControlStatus;     //����ƫ�ƿ���
	bool    OffsetPointLaserControlStatus;//�㼤��ƫ�ƿ���

	double* OffsetSumValue;     //��������[8]
	double* SriOffsetRela;
	double  FswOffsetMartix[11][7]; //��λ���ƻ�Ͼ���

	double dValueSetFz;            //�����趨ֵ��С
	double dValuePlaserValtageSet;
	double dValuePlaserValtageNow;

	double PointPlaserOffsetRela;
public:
	SRISensor* mSRISensor;
	ManualOffset* mManualOffset;
public:
	short   OffsetStatusSet(bool status);
	short   OffsetForceControlStatusSet(bool status);
	short   OffsetPointLaserControlStatusSet(bool status);
	short   OffsetDoOffset();

	short   GetOffsetSumY(double& value);
	short   GetOffsetSumZ(double& value);

	short   OffsetParamaterRest();
};

#endif // OFFSETEX_H