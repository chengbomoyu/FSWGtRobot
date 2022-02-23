#ifndef OFFSET_INTERFACE_H
#define OFFSET_INTERFACE_H
#include "qstring.h"
#define NULL 0

void BR_RsiInit(); //RSI接口初始化
void BR_RsiDeinit();//RSI接口释放
void BR_RsiZeroRest();
void BR_RsiSetStatus(bool status); //RSI接口状态设定
void BR_RsiSetAllow(bool status);  //RSI是否允许修正
double BR_RsiRreadOffsetY(); //读取RSI Y总偏差
double BR_RsiRreadOffsetZ(); //读取RSI Z总偏差
void   BR_RsiSetCodefficient(int value); //设定平滑系数

void BR_RsiManSetStatus(bool status); //RSI是否允许手动修正
void BR_RsiSetOffsetStep(double step);//RSI设定手动修正步距
void BR_RsiManOffsetY(short Dir); //手动修正Y，0上，1下；
void BR_RsiManOffsetZ(short Dir); //手动修正Z，0上，1下；
double BR_RsiReadManOffsetY();//读取手动偏移Y值
double BR_RsiReadManOffsetZ();//读取手动偏移Z值

void  BR_RsiSriConnect(bool status); //SRI建立连接
short BR_RsiSriReadConnectStatus();  //问询建立状态
void BR_RsiSriSetStatus(bool status);//设定偏移状态
void BR_RsiSriSetAskStatus(bool status);//开启问询
void BR_RsiSriSetZero();//设定零点
void BR_RsiSriSetFz(double value);//设定零点
double BR_RsiReadSriFz();//问询Z值
double BR_RsiReadSriFx();//
double BR_RsiReadSriFy();//
double BR_RsiReadSriMx();//
double BR_RsiReadSriMy();//
double BR_RsiReadSriMz();//
double BR_RsiRreadSriOffsetZ(); //问询偏移Z

void   BR_RsiPlaserConnect(bool status); //开始点激光采集
void   BR_RsiPlaserSetStatus(bool status);//开始点激光偏移
void   BR_RsiPlaerSetZero(double value);//设定点激光标准值
void   BR_RsiPlaerSetThickness(double value);//设定板厚
double BR_RsiReadPlaser();//读取点激光
double BR_RsiRreadPlaerOffsetZ(); //读取点激光偏移值

void BR_RsiFswMartixUpdate(double Martix[][7]);

void BR_PlcLoopRun_AskSriData();//问询SRI数据
void BR_PlcLoopRun_AskPlaserDate();//问询点激光数据
void BR_PlcLoopRun_AskManOffset();//问询人在回路偏移
void BR_PlcLoopRun_AskFswOffset();//问询力位混合偏移
void BR_PlcLoopRun_DoOffset();//进行动态偏移

void BR_RsiZeroRest();


//主轴停止
bool BR_SynOffsetOnOff();//偏移开启
//偏移关闭
bool BR_SynForceOnOff();//力控开启
//力控关闭
int BR_SynSpindleRMP();//同步设定速度
int BR_SynForce();//同步设定压力

#endif // OFFSET_INTERFACE_H