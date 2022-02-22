#ifndef SPINDLE_H
#define SPINDLE_H

#include "_Source_support/HEADER/COM/comm_struct_define.h"
#include "_Source_support/HEADER/COM/modbusrtu.h"
#include "_Source_support/HEADER/COM/plc_standard_class.h"
#include "_Source_support/HEADER/COM/robot_comm_interface.h"

class AbsSpindle{
public:
	AbsSpindle(){} //默认构造函数
	~AbsSpindle(){}//默认析构函数
public:
	/***********************************************************/
	short   SpindleType;          //主轴类型,0固高主轴 1其他主轴
	short   SpindleStatus;	      //主轴伺服状态,0下伺服 1上伺服 2开启 3关闭
	short   SpindleComStatus;     //主轴通讯状态,0未连接 1建立连接
	int     SpindleSpeedSet;      //主轴设定速度
	double  SpindleSpeedReal;     //主轴实时速度
	double  SpindleAccaccelation; //主轴加速度
	double  SpindleDecelation;	  //主轴减速度
	short   SpindleDirection;     //主轴方向,-1逆时针 0默认  1顺时针
	/***********************************************************/
	virtual short SpindleServorStatusSet(short mStatus)=0;  //主轴伺服控制
	virtual short SpindleGetRealSpeed(int& mRealSpeed)=0;   //主轴实时速度获取
	virtual short SpindleSetSpeed(int mSetSpeed)=0;      //主轴速度控制
	virtual short SpindleSetDirection(short mDirection)=0;  //设置主轴旋转方向
};

class CvtSpindle : public AbsSpindle{
public:
	CvtSpindle();
	~CvtSpindle();
public:
	unsigned short CvtSpindleModebusRtuSpeedReal;
	ModbusRTU CvtModebusRtu; //用于控制蓝海华腾电主轴ModbusRTU的实例

	SModbusRtuCmdEx CvtGetSpeedSModbusRtuCmdEx; //获取主轴转速
	bool CvtGetSpeedIsFinish; //指令完成
	bool CvtGetSpeedTimeout; //指令超时
	unsigned short CvtGetSpeedData;// 获取到的数据

	SModbusRtuCmdEx CvtSetStatusSModbusRtuCmdEx; //设置主轴状态
	bool CvtSetStatusIsFinish; //指令完成
	bool CvtSetStatusTimeout; //指令超时
	unsigned short CvtSetStatusData;// 指令数据

	SModbusRtuCmdEx CvtSetSpeedSModbusRtuCmdEx;// 设定主轴转速
	bool CvtSetSpeedIsFinish; // 指令完成
	bool CvtGetSpeedTimeout; // 指令超时
	unsigned short CvtSetSpeedData; //指令数据

	SModbusRtuCmdEx CvtSetDirectionSModbusRtuCmdEx; // 设定主轴方向
	bool CvtSetDirectionIsFinish; // 指令完成
	bool CvtGetDirectionTimeout; // 指令超时
	unsigned short CvtSetDirctionData; // 指令数据

public:
	short SpindleServorStatusSet(short mStatus);  //主轴伺服控制
	short SpindleGetRealSpeed(int& mRealSpeed);   //主轴实时速度获取
	short SpindleSetSpeed(int mSetSpeed);         //主轴速度控制
	short SpindleSetDirection(short mDirection);  //设置主轴旋转方向
public:
	short SpindleConnect();
};

#endif // SPINDLE_H