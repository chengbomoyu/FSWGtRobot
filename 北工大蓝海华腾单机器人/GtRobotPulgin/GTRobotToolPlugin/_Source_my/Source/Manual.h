#ifndef MANUAL_H
#define MANUAL_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class ManualOffset{
public:
	ManualOffset(); //构造函数
	~ManualOffset();//析构函数
public:

	bool   ManOffsetStatus;     //动态偏移开关

	double  ManOffsetStep;      //手动步距
	double* ManOffsetSumNow;    //手动本周期总和[8]
	double* ManOffsetSumLast;   //手动前周期总和[8]
	double* ManOffsetRela;      //本周期偏移的量[8]

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