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
	double* OffsetSumValue;               //��������[8]
public:
	ManualOffset* mManualOffset;          //�ֶ�ƫ��
public:
	short   OffsetStatusSet(bool status);
	short   OffsetParamaterRest();
	short   OffsetDoOffset();
	short   GetOffsetSumY(double& value);
	short   GetOffsetSumZ(double& value);

};

#endif // OFFSETEX_H