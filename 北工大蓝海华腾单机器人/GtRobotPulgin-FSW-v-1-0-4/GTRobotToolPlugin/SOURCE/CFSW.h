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

};

#endif // CRSI_H