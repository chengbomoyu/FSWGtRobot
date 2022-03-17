#ifndef OFFSET_INTERFACE_EX_H
#define OFFSET_INTERFACE_EX_H
#include "qstring.h"
#define NULL 0

short BGDOffsetInit();   //RSI接口初始化
short BGDOffsetDeinit(); //RSI接口释放
short BGDOffsetVarRest();//RSI部分接口变量重置

short BGDOffsetStatusSet(bool status);      //RSI接口状态设定
short BGDSriSetStatus(bool status);         //设定力控偏移状态
short BGDManualOffsetStatusSet(bool status);//设定手动偏移开关
short BGDRreadOffsetSumY(double& value);    //读取RSI Y总偏差
short BGDRreadOffsetSumZ(double& value);    //读取RSI Z总偏差
short BGDGetManOffsetSumY(double& value);   //读取手动偏移Y值总和
short BGDGetManOffsetSumZ(double& value);   //读取手动偏移Z值总和
short BGDRreadSriOffsetZ(double& value);    //问询偏移Z
short BGDSriSetFz(double value);            //设定压力

short BGDManualOffsetStepSet(double step);  //设定手动修正步距
short BGDDoManOffsetY(short Dir);           //手动修正Y，0上，1下；
short BGDDoManOffsetZ(short Dir);           //手动修正Z，0上，1下；

short BGDFswMartixUpdate(double Martix[][7]); //更新系数矩阵

void BGDGetManOffsetDataLoopRun();//问询人在回路数据
void BGDDoOffsetLoopRun();        //进行动态偏移

#endif // OFFSET_INTERFACE_EX_H