#ifndef CFSW_H
#define CFSW_H

#include "qstring.h"

#include "robot_comm_interface.h"
#include "comm_struct_define.h"
#include "plc_standard_class.h"

class CFSW{
public:
	bool bStatusOnOff;
	bool bStatusAllow;
	int dValueRsiSetCdefficient;
	double dValueOffsetSum[8];

	bool bStatusManSet;
	double dValueManOffsetStep;
	double RsiManOffsetAbsNow[8];
	double RsiManOffsetAbsHistory[8];
	double RsiManOffsetRela[8];      //每次偏移的量

	STcpServerInfo SriServerinfo;
	STcpClientStatus SriTcpConnectStatus;
	HANDLE SriTcpClient;
	char SriRecvData[32];
	bool bStatusSriConnect;
	short rSriStatusConnect;

	UINT temDataInt;
	float temValueFz;
	double temRsiSriData;

	bool bStatusSriSet;
	bool bStatusSriAsk;
	double dValueSetFz;            //力控设定值大小

	double dValuePlaserValtageSet; //点激光设定电压
	bool bStatusPlaserdaq;         //点激光采集状态
	bool bStatusPlaesrOffset;      //点激光调整状态
	double dValuePlaserValtageNow; //点激光读取电压
	double RsiPlaserOffsetRela[8]; //点激光偏移距离
	double RsiPlaserOffsetAbs[8];
	double dValuePlaserThickness;
	
	double RsiSriDataNow[8];
	double RsiSriDataNowFliter[8];
	double RsiSriDataFliter[12];
	int    RsiSriDataFliterN;
	double RsiSriDataFliterSum;

	double RsiSriDataNowFliterA;

	double RsiSriDataOfsset[8];
	float  RsiSriDataZero[8];
	double RsiSriOffsetAbs[8];
	double RsiSriOffsetRela[8];      //每次偏移的量

	double RsiFswMartix[11][7];
/***********************************************************/
	bool   bj_spindle_status;	              //主轴伺服状态
	bool   bj_spindle_power;	              //主轴开关	

	short  bj_spindle_speed_set;	          //主轴设定速度
	double bj_spindle_accaccelation;          //主轴加速度
	double bj_spindle_decelation;	          //主轴减速度
	int    bj_spindle_direction;              //主轴方向 -1表示逆时针 0 默认  1顺时针
	short  bj_spindle_num; 	                  //主轴轴号   默认是8
	double  bj_spindle_speed_real; 	          //主轴实时速度
/***********************************************************/
public:
	CFSW();
	~CFSW();

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

	void   RsiReadPlaserData();
	void   RsiFswDoOffset();

	void bj_spindle_servor_status(bool servor_status);    //主轴伺服控制
	void bj_spindle_power_control(bool power);            //主轴开关控制
	void bj_spindle_speed_real_get();                     //主轴实时速度获取
	void bj_spindle_speed_control(int speed_addnum);      //主轴速度控制
	void bj_spindle_speed_quickset(int speed);
};

#endif // CRSI_H