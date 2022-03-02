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
	bool    OffsetStatus;                 //动态偏移开关
	bool    OffsetForceControlStatus;     //力控偏移开关
	bool    OffsetPointLaserControlStatus;//点激光偏移开关

	double* OffsetSumValue;     //修正总量[8]
	double* SriOffsetRela;
	double  FswOffsetMartix[11][7]; //力位控制混合矩阵

	double dValueSetFz;            //力控设定值大小
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