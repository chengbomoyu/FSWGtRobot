#ifndef CVT_SPINDLE_H
#define CVT_SPINDLE_H

#include "_Source_support/HEADER/COM/comm_struct_define.h"
#include "_Source_support/HEADER/COM/modbusrtu.h"
#include "_Source_support/HEADER/COM/plc_standard_class.h"
#include "_Source_support/HEADER/COM/robot_comm_interface.h"

#define NORMAL 1
#define REVERSE -1

class CvtSpindle{
public:
	CvtSpindle();
	~CvtSpindle();
public:
	short   SpindleType;          //主轴类型,0固高主轴 1其他主轴
	short   SpindleStatus;	      //主轴伺服状态,0下伺服 1上伺服 2开启 3关闭
	short   SpindleComStatus;     //主轴通讯状态,0未连接 1建立连接
	int     SpindleSpeedSet;      //主轴设定速度
	double  SpindleSpeedReal;     //主轴实时速度
	double  SpindleAccaccelation; //主轴加速度
	double  SpindleDecelation;	  //主轴减速度
	short   SpindleDirection;     //主轴方向,-1逆时针 0默认 1顺时针
public:
	ModbusRTU* CvtModebusRtu;     //用于控制蓝海华腾电主轴ModbusRTU的实例

	SModbusRtuCmdEx CvtGetSpeedSModbusRtuCmdEx;//获取主轴转速
	bool CvtGetSpeedIsFinish;      //指令完成
	bool CvtGetSpeedTimeout;       //指令超时
	unsigned short CvtGetSpeedData;//获取到的数据

	SModbusRtuCmdEx CvtSetStatusSModbusRtuCmdEx;//设置主轴状态
	bool CvtSetStatusIsFinish;      //指令完成
	bool CvtSetStatusTimeout;       //指令超时
	unsigned short CvtSetStatusData;//指令数据

	SModbusRtuCmdEx CvtSetSpeedSModbusRtuCmdEx;//设定主轴转速
	bool CvtSetSpeedIsFinish;      //指令完成
	bool CvtSetSpeedTimeout;       //指令超时
	unsigned short CvtSetSpeedData;//指令数据

	SModbusRtuCmdEx CvtSetDirectionSModbusRtuCmdEx;//设定主轴方向
	bool CvtSetDirectionIsFinish;     //指令完成
	bool CvtSetDirectionTimeout;      //指令超时
	unsigned short CvtSetDirctionData;//指令数据

public:
	short SpindleConnect();
	short SpindleServorStatusSet(short mStatus);  //主轴伺服控制
	short SpindleGetRealSpeed(int& mRealSpeed);   //主轴实时速度获取
	short SpindleSetSpeed(int mSetSpeed);         //主轴速度控制
private:
	short SpindleSetDirection(short mDirection);  //设置主轴旋转方向
};

#endif // CVT_SPINDLE_H