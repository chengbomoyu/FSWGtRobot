#ifndef FSW_H
#define FSW_H

#include "_Source_my/Interface/SensorSri.h"
#include "_Source_my/Interface/SpindleInterface.h"

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

#define  ForceControlRatio 0.01
#define  LaserPointControlRatio 0.01

class FSW{
public:
	FSW();
	~FSW();
public:
	bool    ForceControlStatus;     //力控偏移开关
	bool    PointLaserControlStatus;//点激光偏移开关
	double**  FswOffsetMartix;       //力位控制混合矩阵
	double  dValueSetFz;             //力控设定值大小
	double  dValuePlaserValtageSet;  //光控设定值大小
	double tempdValuePlaserValtageNow;
	double PointPlaserOffsetRela;
	double ForceOffsetRela;
	double FswOffsetRelaData;
public:
	short   ForceControlStatusSet(bool status);
	short   PointLaserControlStatusSet(bool status);
	short   FswControlCompute();
	short   FswControlComputeOnlyForce();
	short   FswControlComputeOnlyLaser();
	short   FswControlResults(double &FswOffsetData);
	short   FswTecParamaterRest();
};

#endif // FSW_H