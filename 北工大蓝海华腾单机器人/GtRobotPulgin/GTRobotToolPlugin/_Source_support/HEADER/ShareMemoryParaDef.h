#pragma once

#ifndef SHAREMEMORYPARADEF_H
#define SHAREMEMORYPARADEF_H

#include <Windows.h>
#include "GtRobotDefine.h"
                                                                                                       

#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

namespace ShareMemory
{	
	typedef GtRobotDef::Point Point;
	//系统控制参数
	typedef struct 
	{
		//8位参数（预留40）

		bool nWatchMode;			// <立即>		WATCH模式  0关闭WATCH模式，1开启WATCH模式。默认0.
		bool bGxnExtModule;			// <重启生效>	是否配置了GXN扩展模块（0表示无，1有）。默认0.
		bool bDisableAxisStopDI;	// <复位生效>	是否关闭轴停止信号（0开启 1关闭）。默认0。

		bool rev8[37];

		//16位参数（预留40）
		short nCardType;		// <重启生效>	控制卡（器）类型：GtRobotDef::CardType 
		short nSysAxisNum;		// <重启生效>	系统控制轴数
		short nSysChannelNum;	// <重启生效>	系统控制通道数：[1,2],默认1
		short nSysGroupNum;		// <重启生效>	系统控制Group数：[1,2],默认1
		short eHmiType;			// <重启生效>	eHMI面板类型（0表示无面板）
		short eHmiDiNum;		// <重启生效>	eHMI面板Di数量
		short eHmiDoNum;		// <重启生效>	eHMI面板Do数量

		short iDebugMsgLevel;	// <立即>		调试信息输出等级，默认0（系统内部依据不同的等级，输出不同调试信息；用于系统诊断排查问题）

		short nCardOpenChannel;	// <重启生效>	默认5.	GTN_Open(short channel=5,short param=1) 
		short nCardOpenParam;	// <重启生效>	默认1.	GTN_Open(short channel=5,short param=1)

		short nBoolVarNum;		// <立即>		支持的BOOL型内部变量个数：[0,20],默认0
		short nLongVarNum;		// <立即>		支持的Long型内部变量个数：[0,20],默认0
		short nDoubleVarNum;	// <立即>		支持的Double型内部变量个数：[0,20],默认0

		short nRemoteMode;		//<立即> 远程模式选择	0不启用,1远程IO模式,2远程TCP模式
		
		short nReplayIoEnable;	//<立即> 回放模式下IO控制生效使能，0不使能IO，1使能IO
		short nReplayBtnDisable;//<立即> 回放模式下手持盒绿灯与白灯屏蔽使能，0屏蔽不使能，1屏蔽使能

		short nSwitchTon;		//<立即> 三段开关接通延时,单位ms
		short nSwitchTof;		//<立即> 三段开关断开延时,单位ms

		unsigned short nSynPosCycleTime;	// <立即>	系统空闲时，位置同步周期。单位ms，默认1000ms，<1时不同步
		short nCapturePosType;				// <立即>	信号触发捕获位置的类型	
											//			0 规划位置（无编码器时，测试用）。
											//			1 编码器位置(实际使用)
											//			默认1
		
		short nEstopMode;			//<立即> 急停模式 0急停立即下使能，1急停减速到0后下使能，默认0
		short nRuntoPointMode;		//<立即> 运动到点模式 0当前坐标系进行运动插补，1强制进行关节插补，2强制进行直角插补 默认0

		short nCoordinateMode;		//<立即> 坐标系模式 0可切换所有坐标系，1跳过TCS、PCS切换(部分四轴机器人无需TCS、PCS)，默认0
		short nSystemLanguage;		//<重启> 机器人系统当前语言类型，0中文，1英文
		short nSystemChannel;		//<立即> 机器人系统当前通道号，0-通道1，1-通道2
		short nSystemGroup;			//<立即> 机器人系统当前的Group，0-主Group，1-辅助Group
		short nbreakModeEnable;		//<立即> 是否开启断点重启，0-关闭，1-开启
		short nSpeedMode;			//<立即> 全局倍率切换模式 0：HMI进行倍率切换 1：PLC进行倍率切换
		short nPositionerJogMode;	//<立即> 变位机JOG模式 0：切换至机器人2进行jog 1：使用扩展轴按键进行JOG
		short nRecordPosMode;		//<立即> 记录位置点模式 0：当前坐标系 1：强制记录ACS位置 2：强制记录MCS位置 

		short nGxnExtModuleNum;		//<重启> GXN扩展IO模块模块的个数
		short sSavelogToFile;		//<立即> 系统掉电日志保存 0:退出系统时保存日志 1:退出系统不时保存日志
		short rev16[8];	

		//32位参数（预留40）
		long rev32[40];
		//64位参数（预留100）
		double rev64[100];
	}SysCtlParam;

	//通道控制参数
	typedef struct 
	{
		//8位参数（预留40）
		//bool bEnableDynamicCoordinate;   // <重启生效> 是否使能动态坐标系跟踪。0不使能 1使能，默认0
		unsigned char bEnableDynamicCoordinate;   // <重启生效> 动态坐标系跟踪功能。0不使能 1地轨(轴)跟踪 2变位机(Group)跟踪 3桁架机器人(Group)跟踪
		bool rev8[39];

		//16位参数（预留40）
				//通道控制总轴数=主Group轴数+辅助Group轴数+外部轴数+龙门从轴
				//通道控制轴顺序：主Group、辅助Group、外部轴、龙门从轴

		unsigned short nGroupNo[GRT_MAX_GROUP_NUM];		// <重启生效>	通道控制的Group号，[0,GRT_MAX_GROUP_NUM].
																						// nGroupNo[0]：（机器人）主Group，默认1 ；
																						// nGroupNo[1]、nGroupNo[2]：（变位机）辅助Group，默认0。
																						//	0表示无该Group
																						//	1对应第一个Group（GroupConfig[0]）
																						//	2对应第二个Group（GroupConfig[1]）

		unsigned short nExtAxisNum;			// <重启生效>	通道控制的外部轴数，≥0，默认0

		unsigned short nGantryAxisNum;		// <重启生效>	通道控制的龙门从轴数，≥0，默认0

		unsigned short auGroupDynType;		// <复位生效,备用>	辅助Group在动态跟踪中的类型：0 master； 1 slave 
		unsigned short auGroupSynType;		// <复位生效,备用>	辅助Group在同步运动中的类型：0 master； 1 slave

		short nReplayOverrideSelect;		// <立即>	回放模式速度倍率选择，范围：[0,16]，0表示不受倍率影响，默认1
		short nTeachOverrideSelect;			// <立即>	示教模式速度倍率选择，范围：[0,16]，0表示不受倍率影响，默认1
		short dynTransMode;           // <立即,备用> 动态坐标系模式选择，默认0
		short dynTransPrm;           // <立即,备用> 动态坐标系参数，默认0

		short rev16[29];

		//32位参数（预留40）
		long rev32[40];

		//64位参数（预留64）
		double dynTransMasterOrigin[GRT_MAX_GROUP_NUM][6];		//  <复位生效>  动态跟踪：master的MCS相对当前group的MCS的坐标系变换关系
		double dynTransPcsToMasterTcs[GRT_MAX_GROUP_NUM][6];	//  <复位生效>  动态跟踪：PCS相对master的TCS的坐标系变换关系

		double rev64[64];
	}SysChannelCtrlParam;

	//DIO配置(如Di配置：type=0，num=40，di信号为DI0.0~DI0.39)
	typedef struct 
	{
		short	enable;		//是否有效(0无效 1有效)
		short	type;		//类型(0GPIO 1EHmi)
		short	num;		//个数 (单个类型最大允许64个信号）
		short	sense;		//有效电平(LEVEL_SENSE::)
		short	iGrpIndex;	//内部索引（系统内部赋值使用，界面不处理）
		short	rev[3];
	}TTDioConfig;

	//X变量配置（如：(逻辑变量)PLC的X变量与（物理信号）DI信号的映射关系等）
	typedef struct 
	{
		//X信号
		short valueType;	//X变量值类型，0普通变量, 1常量0, 2常量1；默认为0。
		short xIndex;		//X变量索引,[0,39] 或 [100,199]
		short xBit;			//X变量位，[0,15]

		//关联DI信号	（仅允许X0.0~X39.15关联Di信号）
		unsigned short diEnable;		//是否关联数字量输入信号（0不关联，1关联）
		short diType;		//类型（GPI、EHMI_DI...）
		short diIndex;		//di端口索引，[0,n), n为对应类型的信号个数
		short diSense;		//有效电平(LEVEL_SENSE::)
		short iCfgIndex;	//对应的（TTDioConfig）DIO配置的组索引（系统内部赋值使用，界面不处理）
		short rev[8];
	}TTPlcXConfig;

	//Y变量配置（如：(逻辑变量)PLC的Y变量与（物理信号）Do信号的映射关系等）
	typedef struct
	{
		//Y信号
		short valueType;	//Y变量值类型，0普通变量,1强制为0, 2强制为1；默认为0
		short yIndex;		//Y变量索引,[0,39], 或 [100,199]
		short yBit;			//Y变量位，[0,15]

		//关联Do信号（仅允许Y0.0~Y39.15关联Do信号）
		unsigned short doEnable;		//是否关联数字量输出信号（0不关联，1关联）
		short doType;		//类型（GPO、EHMI_DO...）
		short doIndex;		//do端口索引，[0,n), n为对应类型的信号个数
		short doSense;		//有效电平(LEVEL_SENSE::)
		short iCfgIndex;	//对应的（TTDioConfig）DIO配置的组索引（系统内部赋值使用，界面不处理）
		short rev[8];
	}TTPlcYConfig;

	//Adc配置
	typedef struct
	{
		unsigned short enable;		//是否有效 (0无效 1有效)
		short adcType;				//Adc类型：	0本地AI；1辅助AI
		short adcNo;				//Adc通道号：≥1
		short reverse;				//备用
		short filterMode;			//备用
		short enableUpdate;			//是否实时读取输入值 (0否 1是)
		short null[2];				//保留
	}TTAdcConfig;

	//Dac配置
	typedef struct
	{
		unsigned short enable;		//是否有效 (0无效 1有效)
		short dacType;				//dac类型：0本地AI；1辅助AI
		short dacNo;				//dac通道号：≥1
		short reverse;				//备用
		short bias;					//备用
		short limit;				//备用
		short null[2];	
	}TTDacConfig;

	//刚体运动
	typedef struct  
	{
		double mass; 
		double inertia[6]; 
		double pos[3]; 
		double ori[4];
		char reserve[20];
	}RigidBodyDynParam;

	//连续轨迹运动参数（笛卡尔空间末端合成速度、加速度）
	typedef struct  
	{
		double max_lin_vel;
		double max_lin_acc;
		double max_lin_dec;
		double max_rot_vel;
		double max_rot_acc;
		double max_rot_dec;
		int jerk_time;
		char reserve[20];
	}CpMotionParam; 

	//坐标系参数
	typedef struct  
	{
		short type;				// 备用
		short orientationMode;	// 姿态描述模式(默认=GroupConfig::orientationMode)。
								// 坐标系为笛卡尔坐标系时，需要指定姿态的描述模式。
								// 0 ORI_MODE_NONE：无姿态描述。
								// 1 ORI_MODE_EULER：欧拉角姿态描述。
								// 2 ORI_MODE_QUAD：四元数姿态描述。
								// 3 ORI_MODE_VECTOR：刀轴矢量姿态描述。
								// 4 ORI_MODE_ROTATE_AXIS_POS：旋转轴位置姿态描述
		short rev16[2];

		//机器人
		double pos[3];
		double ori[4];
	}CoordSystem;

	//串行通信参数
	typedef struct  
	{
		short port;
		short baud_rate;
		short timeout;
		short data_bit;
		short parity_bit;  // parity bit
		short parity_type; // none, odd, even, space, mark
		short stop_bit;
		short reserve[3];
	}SerialComParam;

	//TCPIP通信参数
	typedef struct
	{
		short server_port; 
		short ip_version; // ipv4 / ipv6
		short ip_address[8];
		short client_port; 
		short client_heartbeat_interval; // unit: ms
		short connect_type;  // as server / as client
		short reserve[7];
	}TcpIpParam;

	//机器人模型参数
	typedef struct  
	{
		short type; // convert to int 16
		short joint_number; 
		double joint_bias[8];
		double kin_param[50]; // 50 for most cases 
		char reserve[20];
	}ModelParam;

	//电机参数
	typedef struct  
	{
		short type;
		double max_speed;		// unit: rpm
		double rated_current;	// unit: A
		double rated_torque;	// unit: N.m
		double trq_coeff;		//unit: N.m / A
		char reserve[20];
	}MotorParam;

	//运动平滑参数
	typedef struct 
	{
		bool enable;
		double smooth_time;
		double shaping_const;
		char reserve[20];
	}SmoothParam;

///共享内存参数 ////

	// 轴配置控制参数
	typedef struct
	{
		//8位参数(预留40)////////////////////////////////////////////////////
		bool bEnAlarm;				// <复位生效>	使能伺服报警
		bool bEnLmtPosi;			// <复位生效>	使能正限位
		bool bEnLmtNega;			// <复位生效>	使能负限位
		bool bEnLmtSoft;			// <复位生效>	使能软限位
		bool bPosiLmtSns;			// <复位生效>	正限位极性：	false常闭，true常开
		bool bNegaLmtSns;			// <复位生效>	负限位极性：	false常闭，true常开
		bool bHomeSns;				// <备用>		Home信号极性：	false常闭，true常开
		bool bEncoderSns;			// <重启生效>	编码器极性：	false正常，true取反
		bool bSimuMode;				// <重启生效>	仿真模式：		false常规模式，true仿真模式，默认false
		bool bEnPathShaping;		// <复位生效>	使能PathShaping功能：false关闭，true开启，默认false
		bool rev8[30];				

		//16位参数(预留40)////////////////////////////////////////////////////
		short	axisID;				// <重启生效>	轴ID：[1,GRT_MAX_AXIS_NUM]
		short	axisType;			// <备用>		轴类型： 0: linear  1: rotary 
		short	ctrlMode;			// <重启生效>	控制模式：0脉冲+方向；1模拟量；2正负脉冲
		short   cmdDir;				// <重启生效>	指令方向(0正常 1取反；使用该参数保证轴运动方向和模型方向保持一致)

		short	profileID;			// <重启生效>	轴规划输出通道：1-n，默认为轴ID
		short	encoderID;			// <重启生效>	轴编码器反馈通道：1-n，默认轴ID
		short	stepID;				// <重启生效>	轴规划脉冲输出通道：取值1-n，默认为轴ID

		short	encoderType;		// <重启生效>	编码器类型 0绝对式 1增量式 2脉冲计数器，默认0.
		short	absEncoderType;		// <重启生效>	绝对编码器类型（0glink 1串口通信），默认0.
		short	absEncoderDir;		// <立即生效>	绝对编码器方向（0正 1负），默认0.
		short	absEncoderBits;		// <备用>		绝对编码器位数（绝对编码器分辨率=pow(2.0, absEncoderBits * 1.0))
		
		short	motorType;			// <备用>		电机类型,范围[0,n]。0电机参数无效，>0需设置电机参数
		short	stationID;			// <备用>		站号

		short	backlashCompDir;	// <复位生效>	反向间隙补偿方向，0或1，默认1

		//触发停止运动的输入信号
		short  stopDiType;			// <复位生效>	触发停止运动的输入信号类型，默认0
									//#define MC_LIMIT_POSITIVE               (0)
									//#define MC_LIMIT_NEGATIVE               (1)
									//#define MC_ALARM                        (2)
									//#define MC_HOME                         (3)
									//#define MC_GPI                          (4)
		short  stopDiIndex;			// <复位生效>	触发停止运动的输入信号索引，默认-1(无效)
		short  stopType;			// <复位生效>	停止类型，0急停  1平滑停止  2关闭伺服。默认0
		short  stopDiSns;			// <复位生效>	停止信号极性：	0常闭，1常开, 默认0

		//轴运动约束参数（最大值）：TAxisMotionConstraint
		short  reverseLimitMode;	// <复位生效>	运动反向速度约束模式，在前瞻使能时生效。默认0
									// 0：当轴反向时，终点速度根据dvMax进行约束
									// 1：当轴反向时，终点速度减速到0。
		unsigned short extAxisPrgCtrlType;	// <复位生效>	外部轴在程序运行中的默认控制类型（参见TYPE_AXIS_MOVE_MODE）
											// 0：绝对模式（默认0）
											// 1：相对模式
											// 2：Jog模式
											// 3：跟随其他轴规划同步运动 
											// 4：跟随group合成规划位置同步运动 

											// 100：由外部命令控制

		short velFilterNum;			// <复位生效>	速度规划滤波值,范围[0,4096]
		short rev16[19];		

		//32位参数(预留40)////////////////////////////////////////////////////
		long absEncoderZeroPos;		// <立即生效>	绝对编码器零点	

		//绝对编码器串口通信（备用）
		unsigned long motorBrand;	// <立即生效>		电机品牌, 配合绝对值编码器absEncoderType使用
		unsigned long absoluteEncID;// <立即生效>		电机处于串口通讯上的链路ID
		unsigned long port;			// <立即生效>		串口号
		unsigned long baud;			// <立即生效>			
		unsigned long dataBit;		// <立即生效>		
		unsigned long parity;		// <立即生效>		
		unsigned long stopbit;		// <立即生效>	
		unsigned long absEncMultiLines;		// <重启生效>	(absEncoderType=0时)绝对值编码器线数(默认65536)  
											//              (absEncoderType=1时)绝对编码器单圈脉冲数
		long rev32[31];		

		//64位参数(预留200)///////////////////////////////////////////////////

		//脉冲当量
		double pulse;								// <重启生效>	电机一圈脉冲数，单位：pulse
		double pinch;								// <重启生效>	电机一圈运动距离，单位：mm或度
		double gearRatio;							// <重启生效>	减速比.机器人末端:（实际减速比=gearRatio/gearRatioMotor） 
		double scale;								// <重启生效>	脉冲当量（非输入参数，由NC初始化时计算：pulse*gearRatio/pinch/gearRatioMotor）, 单位：pulse/mm 或 pulse/度。
		double gearRatioMotor;						// <重启生效>	减速比.电机端: 

		double absZeroRefPos;				// <立即生效> 参考点位置（默认0），单位：mm或度。绝对编码器零点(absEncoderZeroPos)对应的机床坐标。	
		double revd64[14];
		//double couple_ratio[GRT_MAX_AXIS_NUM];	// <重启生效>	和其他所有轴的耦合比(20200825 弃用，移到GROUP参数)
		//行程（软限位）
		double minPos;								// <复位生效>	最小行程，		单位：mm或度。
		double maxPos;								// <复位生效>	最大行程，		单位：mm或度。
		double minPosOffset;						// <复位生效>	最小行程，		单位：mm或度。
		double maxPosOffset;						// <复位生效>	最大行程，		单位：mm或度。

		//模拟量控制
		double kp;									// <复位生效>	伺服比例增益
		double ki;									// <复位生效>	伺服积分增益
		double kd;									// <复位生效>	伺服微分增益
		double kvff;								// <复位生效>	伺服速度前馈增益
		double kaff;								// <复位生效>	伺服加速度前馈增益
		double mtrBias;								// <复位生效>	电机静差（零漂补偿），单位：pulse
		double mtrLmt;								// <复位生效>	输出指令限制(电压饱和极限)，单位：V
		double posErrLmt;							// <复位生效>	跟随误差，单位：mm或度。

		//轴运动约束参数（最大值）：TAxisMotionConstraint
		double velMax;			// <复位生效>	最大速度，			单位：mm/s或度/s。
		double accMax;			// <复位生效>	最大加速度，		单位：mm/s^2或度/s^2。
		double decMax;			// <复位生效>	最大减速度，		单位：mm/s^2或度/s^2。
		double jerkMax;			// <复位生效>	最大加加速度，		单位：mm/s^3或度/s^3。
		double dvMax;			// <复位生效>	最大速度跳变量，	单位：mm/s或度/s。

		//停止
		double stopDec;			// <复位生效>	停止减速度，		单位：mm/s^2或度/s^2。
		double estopDec;		// <复位生效>	急停减速度，		单位：mm/s^2或度/s^2。
		
		//平滑
		double smoothTime;		// <复位生效>	轴平滑时间。取值范围：[0,60]，单位：ms 
		double smoothK;			// <复位生效>	平滑系数。取值范围：[0,1000]
		
		//关节坐标系下：手动JOG运动参数	
		double acsJogVel;		// <立即生效>	手动关节JOG运动速度，		单位：mm/s或度/s。
		double acsJogAcc;		// <立即生效>	手动关节JOG运动加速度，		单位：mm/s^2或度/s^2。

		//笛卡尔坐标系下：手动JOG运动参数
		double cpJogVel;		// <立即生效>	手动笛卡尔JOG运动速度，		单位：mm/s或度/s。
		double cpJogAcc;		// <立即生效>	手动笛卡尔JOG运动加速度，	单位：mm/s^2或度/s^2。

		//关节坐标系下：手动Step运动参数
		double acsStepVel;		//<立即生效>	手动关节Step运动速度，		单位：mm/s或度/s。
		double acsStepAcc;		//<立即生效>	手动关节Step运动加速度，	单位：mm/s^2或度/s^2。

		//笛卡尔坐标系下：手动Step运动参数
		double cpStepVel;		// <立即生效>	手动笛卡尔Step运动速度，	单位：mm/s或度/s。
		double cpStepAcc;		// <立即生效>	手动笛卡尔Step运动加速度，	单位：mm/s^2或度/s^2。

		//电机参数
		double motorMaxSpeed;				// <备用>	最大转速，		单位: rpm 
		double motorRateCurrent;			// <备用>	额定电流，		单位: A
		double motorRateTorque;				// <备用>	额定扭矩，		单位: N.m
		double motortorqueToCurrentCoef;	// <备用>	力矩电流比，	单位: N.m / A

		//PathShaping功能
		double pathShapingT1;				// <复位生效>	系统响应时间，通过速度和跟随误差确定该参数，t1=err/vel，单位：s。
		double pathShapingT2;				// <复位生效>	目标响应时间，通过设置小于t1的时间提高系统响应速度。单位：s。

		//反向间隙补偿
		double backlashCompValue;			// <复位生效>	反向间隙补偿值，≥0，0时无补偿，单位：mm或度
		double backlashCompTime;			// <复位生效>	反向间隙补偿时间，≥0，为n的话，表示2^n次方个周期。

		//程序运行：单轴（外部轴）运动参数	
		double axisMoveVel;		//<立即生效>	加工时，单轴运动速度，		单位：mm/s或度/s。
		double axisMoveAcc;		//<立即生效>	加工时，单轴运动加速度，	单位：mm/s^2或度/s^2。
		double axisMoveDec;		//<立即生效>	加工时，单轴运动减速度，	单位：mm/s^2或度/s^2。

		double rev64[140];	

	}AxisConfig;

	//系统配置参数
	typedef struct 
	{
		//系统控制参数
		SysCtlParam		sysParam;

		//通道控制参数
		SysChannelCtrlParam channelParam[GRT_MAX_CHANNEL_NUM];

		//Adc配置
		TTAdcConfig		adcConfig[GRT_MAX_ADC_NUM];			// <立即>		预留20个Adc

		//Dac配置
		TTDacConfig		dacConfig[GRT_MAX_DAC_NUM];			// <立即>		预留20个Dac

		//DI配置
		TTDioConfig		diConfig[GRT_MAX_DIO_GROUP_NUM];	// <重启生效>		预留8组Di
		//DO配置
		TTDioConfig		doConfig[GRT_MAX_DIO_GROUP_NUM];	// <重启生效>		预留8组Do

		//X变量配置（如：(逻辑变量)PLC的X变量与（物理信号）DI信号的映射关系等）
		TTPlcXConfig	xConfig[GRT_MAX_XY_SIGNAL_NUM];		// <重启生效>	预留配置200个X变量，其他未配置的X变量默认为普通变量

		//Y变量配置（如：(逻辑变量)PLC的Y变量与（物理信号）Do信号的映射关系等）
		TTPlcYConfig	yConfig[GRT_MAX_XY_SIGNAL_NUM];		// <重启生效>	预留配置200个Y变量，其他未配置的Y变量默认为普通变量

		//串口通讯配置
		SerialComParam serial_com_param;

		// tcp ip 通讯
		TcpIpParam tcp_ip_param;
		// modbus param
		// modbus TCP param
		// can param
	}SystemConfig;

	//单步运动参数
	typedef struct 
	{
		double step_size_joint; // 本体轴jog寸动，unit: deg/mm
		double step_size_xyz;	// 笛卡尔直线轴jog寸动, unit: mm
		double step_size_rot;	// 笛卡尔旋转轴jog寸动, unit: deg
		char reserve[20];
	}StepMoveParam;

	//前瞻预处理参数
	typedef struct
	{
		bool enable;
		double curvature_ratio; 
		int seg_num; //前瞻段数
		double max_dv;
	}LookAheadParam;

	//DYN参数
	typedef struct 
	{
		bool enable;
		short enable_compensate;
		short enable_friction;
		int count;
		double dyn_param[100];
	}DynParam;

	//通道（Group）配置控制参数
	typedef struct 
	{
		//8位参数（预留100）/////////
		bool bEnBlending;				//  <复位生效>	开启轨迹blending
		bool bEnableDynPara;			//  <复位生效>	开启动力学补偿
		bool bEnableLookAhead;			//  <复位生效>	开启前瞻

		bool bEnAcsPosiLmt[8];			//  <复位生效>	ACS下开启正向软限位
		bool bEnAcsNegaLmt[8];			//  <复位生效>	ACS下开启负向软限位
		bool bEnMcsPosiLmt[3];			//  <复位生效>	MCS下开启正向软限位
		bool bEnMcsNegaLmt[3];			//  <复位生效>	MCS下开启负向软限位
		bool bEnPcsPosiLmt[3];			//  <复位生效>	PCS下开启正向软限位
		bool bEnPcsNegaLmt[3];			//  <复位生效>	PCS下开启负向软限位

		bool bEnAxisJointOffset;			// <复位生效>	关节偏移(JointOffset)是否叠加轴零点(absZeroRefPos)偏移：false不叠加、true叠加；默认false。

		bool rev8[68];
	
		//16位参数（预留200）///////////////////////////////////////////////////
		short groupID;				// <备用>		组ID，范围[1,2]
		short nGroupAxisNum;		// <重启生效>	组控制轴数
		
		short profileMode;			// <复位生效>	速度规划模式：0平滑模式 1高阶平滑模式 2Jerk模式(备用)，默认为0

		short nKinType;				// <重启生效>	结构类型(默认为KIN_TYPE_ROBOT)：	
									//				0 KIN_TYPE_ORTHOGONAL：标准正交三轴结构。
									//				1 KIN_TYPE_NON_ORTHOGONAL：非正交结构。
									//				2 KIN_TYPE_ROBOT：机器人结构。
									//				3 KIN_TYPE_FIVE_AXIS：五轴结构。
									//				4 KIN_TYPE_MULTI_AXIS：多轴结构。

		short orientationMode;		// <重启生效>	指令位置的姿态描述模式(1或2；默认为2 ORI_MODE_QUAD)。
									// 当指令位置的描述坐标系为笛卡尔坐标系时，需要指定姿态的描述模式。
									// 0 ORI_MODE_NONE：无姿态描述。
									// 1 ORI_MODE_EULER：欧拉角姿态描述。
									// 2 ORI_MODE_QUAD：四元数姿态描述。
									// 3 ORI_MODE_VECTOR：刀轴矢量姿态描述。
									// 4 ORI_MODE_ROTATE_AXIS_POS：旋转轴位置姿态描述。
									// 5 ORI_MODE_SPACE_ROTATE

		short nRobotKinType;		// <重启生效>	机器人结构类型:	0 ROBOT_TYPE_SCARA：SCARA机械臂。
									//					1 ROBOT_TYPE_SIX_REVOLUTE：6自由度串联机械臂。
									//					3 Delta（备用）
									//					默认1

		short dynamicsParaNum;				// <备用>	动力学模型参数个数, 取值范围：[1,128]

		short dynCompensateSource;			// <备用>	动力学补偿的参考输入源。
											//			0 MC_PROFILE: 轴规划位置。
											//			1 MC_ENCODER：轴编码器位置。
											//			2 MC_GROUP_PROFILE：group的ACS规划位置。
											//			默认0
		short dynCompensateEnFriction;		// <备用>	动力学补偿：设置是否使能摩擦力补偿。0：不使能，1：使能。
		short dynCompensateEnable;			// <备用>	动力学补偿：设置是否输出动力学补偿值，0：不输出，1：输出。


		short LaSegNum;				// <重启生效>		前瞻段数，范围[150,1000],默认200。

		short blendType;			// <重启生效>		轨迹blending类型:	
									//					0 BLEND_MODE_NONE：不处理
									//					1 BLEND_MODE_ARC： 圆弧blending
									//					2 BLEND_MODE_BIARC：双圆弧blending
									//					默认2
		short blendPrmType;			// <重启生效>		轨迹blending约束参数类型:
									//					0 BLEND_PARA_TYPE_ERROR：误差，只对BLEND_MODE_ARC生效
									//					1 BLEND_PARA_TYPE_RADIUS：过渡圆弧半径，只对BLEND_MODE_ARC生效
									//					2 BLEND_PARA_TYPE_DISTANCE：距离
									//					默认2
		short nRobotKinSubType;			// <重启生效>	机器人结构子类型，[0,3]，SCARA有效。	默认0			//20200428
		short nJointDir[8];				// <重启生效>	关节方向，0:与定义方向同向，1：与定义方向反向。	默认0	//20200428

		//耦合轴 (coupleAxisMaster[i]>0&&coupleAxisSlave[i]>0对应组耦合参数有效)
		short coupleAxisMaster[4];		//<重启生效>	耦合.主轴ID
		short coupleAxisSlave[4];		//<重启生效>	耦合.从轴ID

		//笛卡尔坐标系下示教（手动）轴运动控制对象配置
		short cpGroupMoveType[6];	//<立即>	[1,6]有效；1X方向，2Y方向，3Z方向，4绕X方向旋转，5绕Y方向旋转，6绕Z方向旋转
									//默认为{1,2,3,4,5,6}。
									//主要用于笛卡尔下，GROUP轴数小于6且控制对像不连续的情况）
									//如：4轴SCARA,MoveJog没有没有绕X/Y轴旋转，只有绕Z轴旋转,应配置为{1,2,3,6,0,0}；
									//这样笛卡尔坐标系下，NC收到轴4运动命令（G6.3）后，自动执行绕Z轴旋转运动


		short acsVelMode;  //<立即>	ACS轴坐标系下运动的指令速度和加速度的类型。
									//0：默认模式，单位：mm/s或度/s
									//1：百分比模式
		
		short rev16[163];

		//32位参数（预留100）///////////////////////////////////////
		long rev32[100];

		//64位参数（预留500）///////////////////////////////////////
		//轨迹blending
		double blendMinAngle;		//  <重启或使能>	进行blending处理的最小角度，当轨迹矢量角度变化小于该角度时不进行处理。
		double blendMaxAngle;		//  <重启或使能>	进行blending处理的最大角度，当轨迹矢量角度变化大于该角度时不进行处理。
		double blendPara;			//  <重启或使能>	进行blending处理的过渡段参数（误差，圆弧半径，距离），单位mm。

		//前瞻
		double LaTime;				//  <重启或使能>	前瞻转角系数：转角系数越低，转角速度越低，转角处的轮廓精度越高；
									//					反之，转角系数越高，转角速度越高，转角处的轮廓精度越低。
									//					默认0.1
		double LaRadiusRatio;		//  <重启或使能>	前瞻圆弧系数，系数越大，目标速度越高；反之，系数越小，目标速度越小。
									//					默认1

		//速度规划模式：平滑模式
		double smoothTime;			//  <复位生效>	 平滑（加速度变化）时间。
									// profileMode=0时，取值范围：[0,511]，单位：ms。当accTime为0时，速度规划曲线为T型曲线。
									// profileMode=1时，取值范围：[0,255]，单位：ms。当accTime为0时，速度规划曲线为T型曲线。

		double smoothK;				//  <复位生效>	 平滑形态系数，取值范围：[0,1000]。

		//速度规划模式：Jerk模式(备用)
		double jerkValue;			// 加加速度，取值范围：(0,...)，单位：mm/s^3或度/s^3。
		double jerkBeginPercent;	// 起始加速度百分比，取值范围：[0,100]。
		double jerkEndPercent;		// 终止加速度百分比，取值范围：[0,100]。

		//笛卡尔坐标系下运动限制参数
		double cpVelMax;			//  <复位生效>	 笛卡尔坐标系下的最大速度，取值范围：(0,...)，单位：mm/s。
		double cpAccMax;			//  <复位生效>	 笛卡尔坐标系下的最大加速度，取值范围：(0,...)，单位：mm/s^2。
		double cpDecMax;			//  <复位生效>	 笛卡尔坐标系下的最大减速度，取值范围：(0,...)，单位：mm/s^2。
		double cpJerkMax;			//  <复位生效>	 笛卡尔坐标系下的最大加加速度，取值范围：(0,...)，单位：mm/s^3。

		//MOVJ默认运动参数
		double movjVel;				// <立即>	MOVJ默认速度，取值范围：(0,...)，单位：mm/s。
		double movjAcc;				// <立即>	MOVJ默认加速度，取值范围：(0,...)，单位：mm/s^2。

		//MOVL默认运动参数
		double movlVel;				// <立即>	MOVL默认速度，取值范围：(0,...)，单位：mm/s。
		double movlAcc;				// <立即>	MOVL默认加速度，取值范围：(0,...)，单位：mm/s^2。

		//MOVC默认运动参数
		double movcVel;				// <立即>	MOVC默认速度，取值范围：(0,...)，单位：mm/s。
		double movcAcc;				// <立即>	MOVC默认加速度，取值范围：(0,...)，单位：mm/s^2。
		
		//停止
		double stopDec;				// <复位生效>	 停止加速度，		单位：mm/s^2。
		double stopJerk;			// <复位生效>	 停止加加速度，	单位：mm/s^3。
		//急停（急停、伺服报警、限位）
		double EStopDec;			// <复位生效>	 急停加速度，		单位：mm/s^2。
		double EStopJerk;			// <复位生效>	 急停加加速度，	单位：mm/s^3

		double maxOverride;			// <复位生效>	 最大倍率，[10,150]，默认100。

	
		double kinTransLinkLength[50];	// <复位生效>	 运动学变换参数: 杆长参数，单位：mm。	
		double dynamicsParamter[128];	// <复位生效>	 动力学模型参数值

		double jointOffset[8];			// <复位生效>	关节偏移，实际初始姿态与定义的初始姿态的偏移(默认0，实际初始姿态在定义坐标系下的位置)//20200428
		
		//姿态限制参数
		double oriVelMax;				//  <复位生效>
		double oriAccMax;				//  <复位生效>
		double oriDecMax;				//  <复位生效>
		double oriJerkMax;				//  <复位生效>

		//示教下运动到点：ACS关节坐标系下运动参数
		double teachAcsMovVel;				// <立即>	速度，取值范围：(0,...)，单位：mm/s。
		double teachAcsMovAcc;				// <立即>	加速度，取值范围：(0,...)，单位：mm/s^2。

		//示教下运动到点：笛卡尔坐标系下运动参数
		double teachMcsMovVel;				// <立即>	速度，取值范围：(0,...)，单位：mm/s。
		double teachMcsMovAcc;				// <立即>	取值范围：(0,...)，单位：mm/s^2。

		//耦合比
		double coupleRatioMaster[4];		//<重启生效>	耦合比值.主轴
		double coupleRatioSlave[4];			//<重启生效>	耦合比值.从轴

		//软限位
		double acsPosiLmtValue[8];			//  <复位生效>	ACS下正向软限位值
		double acsNegaLmtValue[8];			//  <复位生效>	ACS下负向软限位值
		double mcsPosiLmtValue[3];			//  <复位生效>	MCS下正向软限位值
		double mcsNegaLmtValue[3];			//  <复位生效>	MCS下负向软限位值
		double pcsPosiLmtValue[3];			//  <复位生效>	PCS下正向软限位值
		double pcsNegaLmtValue[3];			//  <复位生效>	PCS下负向软限位值
		
		double acsPosiLmtOffset[8];			//  <复位生效>	ACS下正向软限位偏移值//liu.zl-2021-6-26
		double acsNegaLmtOffset[8];			//  <复位生效>	ACS下负向软限位偏移值
		double mcsPosiLmtOffset[3];			//  <复位生效>	MCS下正向软限位偏移值
		double mcsNegaLmtOffset[3];			//  <复位生效>	MCS下负向软限位偏移值
		double pcsPosiLmtOffset[3];			//  <复位生效>	PCS下正向软限位偏移值
		double pcsNegaLmtOffset[3];			//  <复位生效>	PCS下负向软限位偏移值

		double arcErr;							//  <复位生效>	圆弧最大误差

		//dec 减速度
		double movjDec;						// <立即>	MOVJ默认减速度，取值范围：(0,...)，单位：mm/s^2。
		double movlDec;						// <立即>	MOVL默认减速度，取值范围：(0,...)，单位：mm/s^2。
		double movcDec;					// <立即>	MOVC默认减速度，取值范围：(0,...)，单位：mm/s^2。
		double teachAcsMovDec;			// <立即>	运动到点：ACS关节坐标系下运动减速度。取值范围：(0,...)，单位：mm/s^2。
		double teachMcsMovDec;			// <立即>	运动到点：笛卡尔坐标系下运动减速度。取值范围：(0,...)，单位：mm/s^2。

		double rev64[211];
	}GroupConfig;

	//NC输出：轴信息
	typedef struct  
	{
		//8位参数（预留40）/////////
		bool bCmdReadAbsPos;	//获取绝对编码器值命令：由界面置位、NC响应(读取的绝对编码器值放在abs_pos)后复位
		bool bReadAbsEnc;		//是否成功读取绝对编码器值(true 成功)：
								//界面在bCmdReadAbsPos复位后，通过此变量判断是否读取成功

		bool bCmdSetAbsPos;		//设置绝对编码器值零点：由界面置位、NC响应后复位
		bool bSetAbs;			//是否成功设置绝对编码器值零点(true 成功)：

		bool bCmdReadDriverInfo; //读取驱动器信息命令：由界面置位、NC响应后复位 20200612
		bool bReadDriverOK;		 //是否成功读取驱动器信息(true 成功)：

		bool bCmdReadAtlTorque;		//读取驱动器实际电流命令：由界面置位、NC响应后复位 20200612
		bool bReadAtlTorqueOK;		//是否成功读取驱动器电流(true 成功)：

		bool bCmdWriteDriverInfo;  //写驱动器信息命令：由界面置位、NC响应后复位 20201127
		bool bWriteDriverOK;		//是否成功写入驱动器信息(true 成功)：

		//单轴运动控制（目前仅支持外部轴类型AxisConfig::extAxisPrgCtrlType=100）
		bool bCmdAxisMove;			//（界面设置）单轴运动启停命令：1启动运动，0停止运动

		bool rev8[29];

		//16位参数（预留40）/////////
		unsigned short iAxisMoveType;		//（界面设置）单轴运动模式：目前仅支持2Jog模式。
											// 0：绝对模式（默认0）
											// 1：相对模式
											// 2：Jog模式
		unsigned short iAxisMoveSts;		//（NC输出）单轴运动状态：0空闲，1运动中
		short rev16[38];

		//32位参数（预留40）/////////
		long axis_status;		//轴状态字
		unsigned long driverInfoSize;	//实际读取驱动器信息的字节数
		unsigned long driverInfoCode;	//读取驱动器信息的网络通信错误码，0表示正常

		long rev32[37];

		//64位参数（预留40）/////////
		double prf_pos;			//规划位置
		double prf_vel;			//规划速度
		double prf_acc;			//规划加速度(HmiParam::bEnUpdatePrfAcc=1时更新)
		double prf_break_pos;	//(回放模式)断点坐标；暂停时自动更新

		double err_pos;			//跟随误差 (HmiParam::bEnUpdateEncInfo=1时更新)
		double enc_pos;			//编码器位置 (HmiParam::bEnUpdateEncInfo=1时更新)
		double enc_vel;			//编码器速度 (HmiParam::bEnUpdateEncInfo=1时更新)
		double motor_vel;		//电机实际转速，单位：r/min //liu.zl-2021-6-26

		double abs_pos;			//绝对编码器值
		
		double abs_pos_multi;		// 绝对编码器零点多圈值
		double abs_pos_single;		// 绝对编码器零点单圈值

		union
		{
			double			dValue;
			unsigned long	ulValue[2];
			long			lValue[2];
			unsigned short	uiValue[4];
			short			iValue[4];
			unsigned char	info[8];
		}driverInfoValue;	//读取的驱动器信息（暂时最大读取8字节）

		double atlTorque;	//驱动器实际电流值

		double axisMoveVel;		//（界面设置）单轴运动速度，单位：mm/s。
		double axisMoveAcc;		//（界面设置）单轴运动加速度，单位：mm/s^2。
		double axisMoveDec;		//（界面设置）单轴运动减速度，单位：mm/s^2。

		double rev64[24];		
	}AxisInfo;


	//NC输出：通道信息
	typedef struct  
	{
		char main_program_name[GRT_FILEPATH_STRING_LEN];		//主程序名
		char current_program_name[GRT_FILEPATH_STRING_LEN];		//当前程序名

		//8位参数（预留40）
		bool bBreakInfoOK;				// 回放暂停时，译码是否已保存断点信息（true是，表示NC调用译码saveContext结束）
		bool bPauseInfoOK;				// 回放暂停时，NC是否已输出相关断点信息（true是，表示进入回放暂停时，已输出相关信息）
		char rev8[38];
		//16位参数（预留40）
		short stopInfo;			// 指令流停止信息
			//0：无停止信息
			//1：调用指令GTN_StopCommandList停止
			//2：调用指令GTN_Stop停止
			//3：调用指令GTN_GroupStop停止
			//4：调用指令GTN_ConditionStopCommandList，条件触发停止
			//10：指令流跑空停止
			//11：等待条件超时停止
			//20：限位触发停止
			//21：报警触发停止
			//22：跟随误差超限停止
			//23：龙门跟随误差超限停止
			//24：指令GTN_SetStopIo设置的IO触发导致停止
			//30：Group计算错误停止
			//40：group处于同步模式时，由于从轴异常导致的停止
			//60：group的PCS软限位触发停止
			//61：group的MCS软限位触发停止
			//62：group的ACS软限位触发停止

		short waitCmdDone; //Wait指令执行状态：0等待条件未完成，1等待条件已完成。bPauseInfoOK=true时有效。
		short rev16[38];

		//32位参数（预留40）
		unsigned long cycle_time;				// 循环时间
		unsigned long work_time;				// 本次总加工时间
		unsigned long main_exeute_line;			// 主程序行号
		unsigned long current_execute_line;		// 当前程序行号
		unsigned long cmd_uuid;					// 当前指令ID
		long cmd_progType;						// 当前指令对应程序类型，参考 via::ProgType

		long exeuteProgLayer;			 		// 当前嵌套执行层:[0,4]
		long exeuteProgLines[5];				// 当前每个嵌套层的执行行号

		long waitCmdLine;								//Wait指令行号：waitCmdDone=0时有效。
		long rev32[27];

		//64位参数（预留100）
		double rev64[100];

		//-----非标准类型，大小可能变化的参数放在最后，避免影响前面大小确定的参数------
		Point cmdStartPoint;									//当前正在执行指令的运动起点
	}ChannelInfo;

	//NC输出：Group信息
	typedef struct  
	{
		//8位参数（预留40）
		char rev8[40];

		//16位参数（预留40）
		short tcs_id;			// 当前生效的tcs的编号
		short pcs_id;			// 当前生效的pcs的编号
		short oriMode;			// MCS/PCS输出位置姿态模式
		short iTeachCoordsys;	// 当前示教生效的坐标系
		short iConfigIndex;		// 当前GROUP构型解 20200603
		short stopInfo;			// Group停止信息
								//0：无停止信息
								//1：调用指令GTN_Stop平滑停止
								//2：调用指令GTN_Stop异常停止
								//5：限位停止
								//8：报警停止
								//9：跟随误差超限停止
								//10：龙门跟随误差超限停止
								//11：指令GTN_SetStopIo设置的IO触发导致停止
								//100：碰奇异点停止
		short rev16[34];

		//32位参数（预留40）
		long rev32[40];

		//64位参数（预留300）
		//ACS 自动更新
		double acs_syn_vel;			//ACS 合成速度
		double acs_prf_pos[8];		//ACS 各轴规划位置
		double acs_prf_vel[8];		//ACS 各轴规划速度

		//MCS (HmiParam::bEnUpdateMcsInfo=1时更新)
		double mcs_syn_vel;			//MCS 合成速度
		double mcs_prf_pos[8];		//MCS 各轴规划位置：（[0,2]为XYZ位置，[3,6]为姿态）
		double mcs_prf_vel[8];		//MCS 各轴规划速度

		//PCS (HmiParam::bEnUpdatePcsInfo=1时更新)
		double pcs_syn_vel;			//PCS 合成速度
		double pcs_prf_pos[8];		//PCS 各轴规划位置：（[0,2]为XYZ位置，[3,6]为姿态）
		double pcs_prf_vel[8];		//PCS 各轴规划速度

		//TCS (备用：HmiParam::bEnUpdateTcsInfo=1时更新)
		double tcs_syn_vel;			//TCS 合成速度
		double tcs_prf_pos[8];		//TCS 各轴规划位置：（[0,2]为XYZ位置，[3,6]为姿态）
		double tcs_prf_vel[8];		//TCS 各轴规划速度

		// (回放模式)断点坐标；指令流暂停时自动更新
		double acs_break_pos[8];	//ACS 断点坐标
		double mcs_break_pos[8];	//MCS 断点坐标：（[0,2]为XYZ位置，[3,6]为姿态）
		double pcs_break_pos[8];	//PCS 断点坐标：（[0,2]为XYZ位置，[3,6]为姿态）
		double tcs_break_pos[8];	//TCS 断点坐标(备用)：（[0,2]为XYZ位置，[3,6]为姿态）

		//FCS (HmiParam::bEnUpdateFcsInfo=1时更新)
		double fcs_prf_pos[8];		//FCS 各轴规划位置：（[0,2]为XYZ位置，[3,6]为姿态）
		double fcs_prf_vel[8];		//FCS 各轴规划速度

		double rev64[184];			
	}GroupInfo;

	//NC输出信息
	typedef struct 
	{
		//16位参数（预留40）
		short rev16[40];

		//32位参数（预留40）
		unsigned long cycleCnt;		//NC计数器(NC每执行一次，计数加1)
		unsigned long plcCycleCnt;	//PLC计数器(PLC每执行一次，计数加1)
		long nPowerSts;				//控制器断电状态(从站模块的电源状态: GTN_GetPowerSts)
		//按位指示从站电源状态。当bit位为0：正常；1：掉电
		unsigned long plcCycleTime;	//plc循环时间，单位:us
		unsigned long plcRunTime;		//plc执行时间，单位:us
		unsigned long ncCycleTime;		//nc循环时间，单位:us
		unsigned long ncRunTime;		//nc执行时间，单位:us
		long rev32[33];

		//64位参数（预留80）
		double auEncoderPos[2];			//辅编位置
		double auEncoderVel[2];			//辅编速度
		double rev64[76];


	//-----非标准类型，大小可能变化的参数放在最后，避免影响前面大小确定的参数------
		//NC输出：轴信息
		AxisInfo	axis_info[GRT_MAX_AXIS_NUM];
		//NC输出：Group信息
		GroupInfo	group_info[GRT_MAX_GROUP_NUM];
		//NC输出：通道信息
		ChannelInfo channel_info[GRT_MAX_CHANNEL_NUM];
	}MotionOutput;

	//PLC接口数据
	typedef struct 
	{
		// mx : hmi to plc
		unsigned short m_x_data[GRT_PLC_DATA16_NUM];
		// my : plc to hmi
		unsigned short m_y_data[GRT_PLC_DATA16_NUM];
		// mf : nc to plc
		unsigned short m_f_data[GRT_PLC_DATA16_NUM];
		// mg : plc to nc
		unsigned short m_g_data[GRT_PLC_DATA16_NUM];
		// mm : plc internal
		unsigned short m_m_data[GRT_PLC_DATA16_NUM];

		//D变量(程序中通过符号'$'访问)	
		//	$0~$999, $3000~$3999		hmi写，其他只读
		//	$1000~$1999, $4000~$4999	nc写，其他只读
		//	$2000~$2999, $5000~$5999	PLC写，其他只读
		long	m_Data32[GRT_PLC_DATA32_NUM];	//$0~$2999
		double	m_Data64[GRT_PLC_DATA64_NUM];	//$3000~$5999
	}PlcInterface;

	//用户变量
	typedef struct
	{
		char var_string[GRT_PUBLIC_STRING_NUM][GRT_PUBLIC_STRING_LEN];	//STR0~STR999
		unsigned char var_string_used[GRT_PUBLIC_STRING_NUM];

		bool var_B[GRT_PUBLIC_BOOL_NUM];         //B0~B9999
		unsigned char var_B_used[GRT_PUBLIC_BOOL_NUM];

		long var_I[GRT_PUBLIC_INT_NUM];         //I0~I9999
		unsigned char var_I_used[GRT_PUBLIC_INT_NUM]; 

		double var_double[GRT_PUBLIC_DOUBLE_NUM];       //R0~R9999
		unsigned char var_double_used[GRT_PUBLIC_DOUBLE_NUM];

		Point var_IncP[GRT_PUBLIC_POINT_NUM];        //IncP0~IncP9999
		unsigned char var_IncP_used[GRT_PUBLIC_POINT_NUM];

		Point var_point[GRT_PUBLIC_POINT_NUM];       //P0~P9999 
		unsigned char var_point_used[GRT_PUBLIC_POINT_NUM];
	}PublicVariable;

	//Watch配置
	typedef struct  // to be completed
	{
		bool enable; 
		char config_path[GRT_FILEPATH_STRING_LEN];
		char save_path[GRT_FILEPATH_STRING_LEN];
	}WatchConfig;

	//示教程序信息
	typedef struct  
	{
		char directory[GRT_FILEPATH_STRING_LEN];
		char name[GRT_FILEPATH_STRING_LEN];
	}RobProgramInfo;


	//HMI:通道参数
	typedef struct
	{
		//8位参数（预留40）
		bool bEnableBreakStart;					// 断点启动的运动起点是否有效
												// true有效：启动行圆弧运动将以breakCmdStartPoint为运动起点进行计算
												// false无效：启动行圆弧运动将以当前位置为运动起点进行计算
		bool rev8[39];

		//16位参数（预留40）
		short cmd_moveToPointId;	// 运动到点：位置id，[0,GRT_PUBLIC_POINT_NUM-1];
		short craft_status;			// 工艺状态： 0工艺关(灰色),1工艺开(绿色),2工艺警告(黄色),3工艺异常(红色)
		short rev16[38];

		//32位参数（预留40）
		long replayStartLine;		// 回放（跳段）启动行号
		long teachStartLine;		// 示教（前进/后退）启动（执行）行号
		long current_prg_rows;		// 当前打开的示教程序总行数
		long teachStartLineBefore;	//上一次的示教启动行号
		long replayStartLineBefore; //上一次的回放启动行号
		long rev32[35];

		//64位参数（预留40）
		double replaySpeed;			// 回放模式下速度倍率，默认100（100%） 
		double teachSpeed;			// 示教模式下：Jog运动的速度倍率，默认100（100%）  
		double moveToSpeed;			// 示教模式下：运动到点\前进\后退的速度倍率，默认100（100%）//liu.zl-2021-6-26
		double jogStepLen;			// 示教模式下，手动步进模式的步长，单位mm或度。
		double userVel;				// 指令速度为0时，使用的用户速度
		double rev64[35];

		//-----非标准类型，大小可能变化的参数放在最后，避免影响前面大小确定的参数------
		RobProgramInfo	prgInfo;					// 程序信息
		Point			refPoint;							// 参考点
		Point			breakCmdStartPoint;		// 断点启动，指令运动起点（起点行，为圆弧运动时有意义）。
															//	记录ChannelInfo::cmdStartPoint的值;								
	}HmiChannelParam;

	//HMI:GROUP参数
	typedef struct
	{
		//8位参数（预留40）
		/// NC信息更新开关；不需要时关闭(减少NC循环执行时间)；参见MotionOutput
		/// <false>Nc不更新输出对应坐标系的轴信息（位置、速度）； <true>Nc更新输出对应坐标系当前轴信息
		bool bEnUpdateMcsInfo;			// MCS
		bool bEnUpdatePcsInfo;			// PCS
		bool bEnUpdateTcsInfo;			// TCS（备用）
		bool bEnUpdateFcsInfo;			// FCS（法兰坐标系）
		bool bEnUpdateGroupConfigIndex; // 更新获取当前构型解(默认true) 
		bool bPositionerActivate;		//变位机系统是否激活（标定）

		bool bEnUpdatePrfVel;			//对应坐标系更新信息开启后，是否更新输出规划速度：acs_prf_vel、mcs_prf_vel、pcs_prf_vel、fcs_prf_vel
		bool bEnUpdateSynVel;		//对应坐标系更新信息开启后，是否更新输出合成速度：acs_syn_vel、mcs_syn_vel、pcs_syn_vel
		bool rev8[32];

		//16位参数（预留40）
		short cmd_coordsys;				// 切换坐标系: 目标坐标系（PCS = 0, MCS = 1,ACS = 2,TCS = 3）
		short cmd_tcs_id;				// 切换坐标系: 目标TCS选择：[0,GRT_MAX_COORDINATE_NUM-1]
		short cmd_pcs_id;				// 切换坐标系: 目标PCS选择：[0,GRT_MAX_COORDINATE_NUM-1]

		short cmd_teachOrientationMode;	//示教模式下手动运动：空间位置姿态描述模式(1或5；默认为1 ORI_MODE_EULER)。
										// 笛卡尔坐标系运动时，需要指定姿态的描述模式。
										// 0 ORI_MODE_NONE：无姿态描述。
										// 1 ORI_MODE_EULER：欧拉角姿态描述。
										// 2 ORI_MODE_QUAD：四元数姿态描述。
										// 3 ORI_MODE_VECTOR：刀轴矢量姿态描述。
										// 4 ORI_MODE_ROTATE_AXIS_POS：旋转轴位置姿态描述。
										// 5 ORI_MODE_SPACE_ROTATE  
		short	rev16[36];

		//32位参数（预留40）
		long	rev32[40];

		//64位参数（预留40）
// 		double acs_break_pos[8];	//ACS 断点启动坐标
// 		double mcs_break_pos[8];	//MCS 断点启动坐标
// 		double pcs_break_pos[8];	//PCS 断点启动坐标
		double	rev64[40];

		//-----非标准类型，大小可能变化的参数放在最后，避免影响前面大小确定的参数------
		//机器人法兰坐标系，tcs[0] 不允许修改(机器人本体机构确定后，通过结构参数自动计算生成)
		CoordSystem TCS[GRT_MAX_COORDINATE_NUM];
		//机器人坐标系，pcs[0] 不允许修改
		CoordSystem PCS[GRT_MAX_COORDINATE_NUM];
	}HmiGroupParam;
	
	////HMI参数
	typedef struct
	{
		//8位参数（预留40）
		/// NC信息更新开关；不需要时关闭(减少NC循环执行时间)；参见MotionOutput
		/// <false>Nc不更新输出对应坐标系的轴信息（位置、速度）； <true>Nc更新输出对应坐标系当前轴信息
		bool bEnUpdateEncInfo;		// 更新编码器信息
		bool bEnUpdatePrfAcc;		// 更新规划加速度: prf_acc
		bool bEnUpdatePowerSts;		// 读取控制器断电状态/从站模块的电源状态(默认false) 20200612
		bool bSystemInitSuccess;	// 机器人系统初始化状态， 0初始化失败，1初始化成功
		bool flag_insert_movc;					//快捷插入movc时的标志位，值为true时程序界面插入movc，插入后修改为false

		bool bEnUpdatePrfVel;			// 更新读取规划速度: prf_vel
		bool bEnUpdateErrPos;		// 更新读取跟随误差: err_pos
		bool bEnUpdateEncVel;		// 更新读取编码器速度: enc_vel；motor_vel
		bool rev8[32];				

		//16位参数（预留40）
		unsigned short hmi_permission;			// hmi用户权限信息，0操作工，1管理员，2出厂设置
		unsigned short driverInfoIndex;			// 读取驱动器相关的信息的指令索引。默认为0x603F(驱动器的报警代码)
		unsigned short driverInfoSubIndex;		// 读取驱动器相关的信息的指令子索引。默认为0.
		short hmi_interpolator;					// hmi指令插补类型,1-MOVJ,2-MOVL,3-MOVC

		unsigned short writeDriverInfoIndex;	// 写驱动器相关的信息的指令索引。如：0x8000(清除编码器报警)
		unsigned short writeDriverInfoSubIndex;	// 写驱动器相关的信息的指令子索引。如：39(清除编码器报警)

		union
		{
			double			dValue;
			unsigned long	ulValue[2];
			long			lValue[2];
			unsigned short	uiValue[4];
			short			iValue[4];
			unsigned char	info[8];		//写入的驱动器信息
		}writeDriverData;	

		short auEncoderId[2];			//2个辅助编码器ID：≥0.
												// 0表示无效
												// ＞0，有效，NC会读取该ID对应的辅助编码器值到MotionOutput::auEncoderPos,auEncoderVel
		short hmi_dynsynch_group;		//界面快捷插入指令时，选择需要联动的group,用于设置位置型变量的dynSynch变量
		short rev16[27];

		//32位参数（预留40）
		long mainPlcLogicCnt;	//系统主PLC计数器

		unsigned long writeDriverDataSize;	//写入的驱动器信息大小（字节数），[1,8]
		unsigned long writeDriverAbortCode; //写入的驱动器时，得到的AbortCode（参见相关手册）。
		long rev32[37];

		//64位参数（预留40）
		double rev64[40];

		///非标准类型放在最后，避免影响前面的标准类型参数/////////////////
		HmiChannelParam channelParam[GRT_MAX_CHANNEL_NUM];
		HmiGroupParam groupParam[GRT_MAX_GROUP_NUM];

	}HmiParam;

	//用户自定义参数（工艺参数）
	typedef struct
	{
		double para[20000];
	}UserParam;
}

#pragma pack(pop)

#endif // SHAREMEMORYPARADEF_H
