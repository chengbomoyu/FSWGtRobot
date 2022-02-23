#ifndef OFFSET_H
#define OFFSET_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class Offset{
public:
	bool bStatusOnOff;          //动态偏移开关
	double dValueOffsetSum[8];  //修正量总值

	double dValueManOffsetStep;      //手动步距
	double RsiManOffsetAbsNow[8];    //手动当前总和
	double RsiManOffsetAbsHistory[8];//手动前周期总和
	double RsiManOffsetRela[8];      //每次偏移的量

	STcpServerInfo SriServerinfo;        //SRI传感器服务器端信息
	STcpClientStatus SriTcpConnectStatus;//SRI客户端状态
	HANDLE SriTcpClient;                 //SRI客户端句柄
	char SriRecvData[32];                //SRI接收到的原始数据
	bool  bStatusSriConnect;             //SRI是否建立连接
	short rSriStatusConnect;             //SRI返回当前连接状态

	bool   bStatusSriAsk;                //SRI是否建立问询
	float  RsiSriDataZero[8];            //SRI传感器的零点
	double RsiSriDataNow[8];             //SRI转换后的数据

	double dValuePlaserValtageNow;    //点激光当前值
	double dValuePlaserValtageSet;	  //点激光设定值

	bool bStatusSriSet;            //是否开启力控
	bool bStatusPlaesrOffset;      //是否开启点激光控制
	
	double dValueSetFz;            //力控设定值大小
	double RsiSriOffsetAbs[8];     //力控偏移总值
	double RsiSriOffsetRela[8];    //力控每次偏移的量

	double RsiPlaserOffsetRela[8]; //点激光相对偏移量

	double RsiFswMartix[11][7];    //力位控制混合矩阵

public:
	Offset();
	~Offset();

	void   RsiStatusSet();

	double RsiRreadOffsetY(); //读取RSI Y总偏差
	double RsiRreadOffsetZ(); //读取RSI Z总偏差
	void   RsiManOffsetY(short Dir);
	void   RsiManOffsetZ(short Dir);

	void   RsiSriConnect();
	void   RsiReadSriConnectStatus();
	void   RsiSriSetZero();

	void   RsiDoOffset();    //进行动态偏移
	void   RsiAskManOffset();//问询手动偏移
	void   RsiReadSriData();

	void   RsiFswDoOffset();

};

#endif // OFFSET_H