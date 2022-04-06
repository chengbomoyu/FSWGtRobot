#ifndef FSW_INTERFACE_H
#define FSW_INTERFACE_H
#include "qstring.h"
#define NULL 0

short BGDFswInit();   //FSW接口初始化
short BGDFswDeinit(); //FSW接口释放
short BGDFswVarRest();//FSW部分接口变量重置

short BGDForceControlSetStatus(bool status);        //设定力控偏移状态
short BGDPointLaserControlSetStatus(bool status);   //设定力控偏移状态
short BGDForceControlSetFz(double value);           //设定压力
short BGDPointLaserSetVoltage(double value);             
short BGDFswOffsetDataGet(double& data);
short BGDRreadFswOffsetZ(double& value);

#endif // FSW_INTERFACE_H