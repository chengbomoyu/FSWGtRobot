#ifndef OFFSET_INTERFACE_H
#define OFFSET_INTERFACE_H
#include "qstring.h"
#define NULL 0

short BGDOffsetInit(); //RSI接口初始化
short BGDOffsetDeinit();//RSI接口释放
short BGDOffsetVarRest();//RSI部分接口变量重置

short BGDOffsetStatusSet(bool status);        //RSI接口状态设定
short BGDRreadOffsetSumY(double& value);       //读取RSI Y总偏差
short BGDRreadOffsetSumZ(double& value);       //读取RSI Z总偏差

short BGDManualOffsetStatusSet(bool status);//设定手动偏移开关
short BGDManualOffsetStepSet(double step);//设定手动修正步距
short BGDDoManOffsetY(short Dir);         //手动修正Y，0上，1下；
short BGDDoManOffsetZ(short Dir);         //手动修正Z，0上，1下；
short BGDGetManOffsetSumY(double& value);    //读取手动偏移Y值总和
short BGDGetManOffsetSumZ(double& value);    //读取手动偏移Z值总和

short BGDSriConnectSet(bool status); //SRI建立连接
short BGDSriReadConnectStatus(short& status);  //问询建立状态
short BGDSriSetStatus(bool status);//设定力控偏移状态
short BGDSriSetAskStatus(bool status);//开启问询
short BGDSriSetZero();//设定零点
short BGDSriSetFz(double value);//
short BGDReadSriFz(double& value);//问询Z值
short BGDRreadSriOffsetZ(double& value); //问询偏移Z

short BGDFswMartixUpdate(double Martix[][7]);

void BGDGetSriDataLoopRun();  //问询SRI数据
void BGDGetManOffDataLoopRun();//问询人在回路数据
void BGDDoOffsetLoopRun();    //进行动态偏移

#endif // OFFSET_INTERFACE_H