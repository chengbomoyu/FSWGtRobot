#ifndef SENSOR_SRI_H
#define SENSOR_SRI_H
#include "qstring.h"
#define NULL 0

short BGDSRIInit();   //RSI接口初始化
short BGDSRIDeinit(); //RSI接口释放
short BGDSRIVarRest();//RSI部分接口变量重置

short BGDSriConnectSet(bool status); //SRI建立连接
short BGDSriReadConnectStatus(short& status);  //问询建立状态

short BGDSriSetAskStatus(bool status);//开启问询
short BGDSriSetZero();            //设定零点
short BGDReadSriFz(double& value);//问询Z值
void  BGDGetSriDataLoopRun();      //问询SRI数据

#endif // SENSOR_SRI_H