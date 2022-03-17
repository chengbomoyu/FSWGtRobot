#ifndef GTR_USER_DEFINE_H
#define GTR_USER_DEFINE_H

///////////////////////////////////////////////////////////////////////// 
/// GTRobot	固高科技 开放式可重组工业机器人控制系统开发平台
/// Copyright (C) 2020 Googol Technology Ltd. All Rights Reserved.  
///   
/// @file		gtr_user_define.h    
/// @brief    	GTR工艺机器人控制系统-顶层接口-数据接口定义  
/// @version 	v2.0.7.0          
//////////////////////////////////////////////////////////////////////////

#include<QString>

//界面宏定义约束值
#define SHOWNUMVARCOUNT				8		//数值型变量
#define SHOWBOOLVARCOUNT			8		//布尔型变量
#define SHOWINTVARCOUNT				8		//整数型变量
#define SHOWREALVARCOUNT			8		//实数型变量
#define SHOWSTRVARCOUNT				8		//字符型变量
#define SHOWAXISCOUNT				8		//位置型变量
#define MAXPOINTCOUNT				999
#define SHOWINCPVARCOUNT			8		//增量位置型变量
#define MAXIOROW					4		//IO状态
#define MAXIOCOLUMN					16
#define MAXCOMMONAXISROW			9		//通用轴状态
#define MAXCOMMONAXISCOL			8
#define CURRENTAXISCOUNT			8		//当前位置
#define MAXSHOWAXISCOUNT			8		//示波器
#define MAXAXISCONFIGCOUNT			16		//轴配置参数
#define MAXCONFIGGROUPCOUNT			2		//组配置参数
#define DHMAXCOUNT					15		//DH参数
#define COUPLECOUNT					4		//耦合比组数
#define JOINTDIRANDOFFSETCOUNT		8		//关节方向与偏移组数
#define REMOTEXCONFIGSIZE			40		//远程通讯参数
#define REMOTEYCONFIGSIZE			40
#define REMOTEMAXROW				8
#define REMOTESINGLEPAGE			1
#define REMOTEBINARYPAGE			30
#define MAXSHOWROW					32		//坐标系管理配置
#define MAXENCODERCOUNT				8		//零位标定参数
#define MAXSHOWALARMCOUNT			8		//报警历史
#define MAXSHOWLOGCOUNT				9		//操作日志


namespace front_gtr{

enum ModuleType
{
	MODULE_HMI = 0,				//HMI模块
	MODULE_TASK,				//TASK模块
	MODULE_WARNING,				//报警模块
	MODULE_SHAREMEMORY,			//共享内存模块
	MODULE_PLC,					//PLC模块
	MODULE_NC,					//NC模块
	MODULE_ROBOTAPI,			//机器人库模块
	MODULE_MAINPLCLOGIC,		//主PLC逻辑模块
	MODULE_CRAFTLOGIC,			//工艺逻辑模块
	MODULE_WATCH				//watch模块
};

enum NumericVarType
{
	VAR_B,						//布尔型变量
	VAR_I,						//整数型变量
	VAR_R,						//实数型变量
	VAR_STR						//字符型变量
};

enum PositionVarType
{
	VAR_P,						//位置型变量
	VAR_INCP					//增量位置型变量
};

//用户权限
enum PermissionLevel
{
	OPERATOR = 0,				//操作工
	MANAGER,					//管理员
	FACTORY						//出厂设置
};


//JOG运动轴类型
enum JogAxisType
{
	JOG_NEGATIVE_X = 0,			//X轴负方向
	JOG_POSITIVE_X,				//X轴正方向
	JOG_NEGATIVE_Y,				//Y轴负方向
	JOG_POSITIVE_Y,				//Y轴正方向
	JOG_NEGATIVE_Z,				//Z轴负方向
	JOG_POSITIVE_Z,				//Z轴正方向
	JOG_NEGATIVE_RX,			//RX轴负方向
	JOG_POSITIVE_RX,			//RX轴正方向
	JOG_NEGATIVE_RY,			//RY轴负方向
	JOG_POSITIVE_RY,			//RY轴正方向
	JOG_NEGATIVE_RZ,			//RZ轴负方向
	JOG_POSITIVE_RZ,			//RZ轴正方向
};

struct VarNumber
{
	QString value;
	QString comment;

	VarNumber()
	{
		this->value = "0";
		this->comment = "无";
	}
	VarNumber& operator=(const VarNumber&input)
	{
		this->value = input.value;
		this->comment = input.comment;
		return *this;
	}
	bool operator!=(const VarNumber& input)const
	{
		return (this->value != input.value);
	}
};

struct GroupPoint
{
	QString coordType;			//坐标系类型：
	//#define COORD_SYSTEM_PCS				(0)
	//#define COORD_SYSTEM_MCS				(1)
	//#define COORD_SYSTEM_ACS				(2)
	//#define COORD_SYSTEM_TCS				(3)
	//#define COORD_SYSTEM_VCS				(4)
	//short m_coord_idx;	//坐标系号：
	//short m_tool_idx;		/具号（TCS坐标系号）：
	QString configNumber;		//构型选择（运动路径解选择，ACS设置为1）
	QString posType;			//坐标类型（备用:0绝对 1增量, 默认为0）
	QString orientationMode;	//指令位置的姿态描述模式(默认=GroupConfig::orientationMode)。
	//当指令位置的描述坐标系为笛卡尔坐标系时，需要指定姿态的描述模式。
	// #define ORI_MODE_NONE				    (0)：无姿态描述
	// #define ORI_MODE_EULER				    (1)：欧拉角姿态描述
	// #define ORI_MODE_QUAD				    (2)：四元数姿态描述
	// #define ORI_MODE_VECTOR				    (3)：刀轴矢量姿态描述
	// #define ORI_MODE_ROTATE_AXIS_POS			(4)：旋转轴位置姿态描述
	
	QString groupIndex;			// Group索引[1,2]：Point::groupPoint[1]有效。
	QString dynSynch;
	QString joint[8];			//坐标值：在关节坐标系下表示各个关节的值，在笛卡尔坐标系下表示位置和四元数(或欧拉角)表示的姿态（[0,2]为XYZ位置，[3,6]为姿态）

	GroupPoint()
	{
		this->coordType = "2";
		this->configNumber = "0";
		this->posType = "0";
		this->orientationMode = "1";
		this->groupIndex = "0";
		this->dynSynch = "0";
		for(int i = 0;i<8;i++){
			this->joint[i] = "0";
		}
	}
};

struct VarPosition
{
	GroupPoint groupPoint[2];
	QString extJoint[8];
	QString comment;
	QString used;
	QString dynSynch;
	QString rev[6];

	VarPosition()
	{
		for(int i = 0;i<8;i++){
			this->extJoint[i] = "0";
		}
		this->comment = "无";
		this->used = "0";
		this->dynSynch = "0";
		
		for(int i = 0;i<6;i++){
			this->rev[i] = "0";
		}
	}
};


struct LogItem
{	
	QString username;
	QString text;
	QString datetime;
	
	LogItem()
	{
		this->username = "";
		this->text = "";
		this->datetime = "";
	}
};

struct RobotStatus
{
	QString pendant_mode;		
	QString run_status;
	QString servo_status;
	QString welding_status;
	QString tcs_id;
	QString coord_system;
	QString teach_speed;
	QString estop_status;
	QString switch_three_stage;
	QString prg_current_line;
	
	RobotStatus()
	{
		this->pendant_mode = "";
		this->run_status = "";
		this->servo_status = "";
		this->welding_status = "";
		this->tcs_id = "";
		this->coord_system = "";
		this->teach_speed = "";
		this->estop_status = "";
		this->switch_three_stage = "";
		this->prg_current_line = "";
	}
};

struct SystemParam
{
	QString nWatchMode;			//Watch模式，0关闭，1开启
	QString bGxnExtModule;		// <重启生效>	是否配置了GXN扩展模块（0表示无，1有）。默认0.
	QString bDisableAxisStopDI;	// <复位生效>	是否关闭轴停止信号（0开启 1关闭）。默认0。

	QString gxnExtDiNum;		// <重启生效>	GXN扩展DI数量
	QString gxnExtDoNum;		// <重启生效>	GXN扩展DO数量

	QString nCardType;			//控制卡（器）类型：GtRobotDef::CardType 
	QString nSysAxisNum;		// <重启生效>	系统控制轴数
	QString nSysChannelNum;		// <重启生效>	系统控制通道数：[1,2],默认1
	QString nSysGroupNum;		// <重启生效>	系统控制Group数：[1,2],默认1
	QString eHmiType;			//eHMI面板类型（0表示无面板）
	QString eHmiDiNum;			//eHMI面板Di数量
	QString eHmiDoNum;			//eHMI面板Do数量

	QString nCardOpenChannel;	//默认5.	GTN_Open(short channel=5,short param=1) 
	QString nCardOpenParam;		//默认1.	GTN_Open(short channel=5,short param=1)

	QString nBoolVarNum;		//支持的BOOL型内部变量个数：[0,20],默认0
	QString nLongVarNum;		//支持的Long型内部变量个数：[0,20],默认0
	QString nDoubleVarNum;		//支持的Double型内部变量个数：[0,20],默认0

	QString nRemoteMode;		//远程模式选择	0不启用,1远程IO模式,2远程TCP模式

	QString nReplayIoEnable;	//回放模式下IO控制生效使能，0不使能IO，1使能IO
	QString nReplayBtnDisable;	//回放模式下手持盒绿灯与白灯屏蔽使能，0屏蔽不使能，1屏蔽使能

	QString nSwitchTon;			//三段开关接通延时,单位ms
	QString nSwitchTof;			//三段开关断开延时,单位ms

	QString nSynPosCycleTime;   //系统空闲时，位置同步周期。单位ms，默认1000ms，<1时不同步
	QString nCapturePosType;	// <立即>	信号触发捕获位置的类型	
	//			0 规划位置（无编码器时，测试用）。
	//			1 编码器位置(实际使用)
	//			默认1

	QString localDiNum;			//本地DI数量
	QString localDoNum;			//本地DO数量

	QString nEstopMode;			//<立即> 急停模式 0急停立即下使能，1急停减速到0后下使能
	QString nRuntoPointMode;	//<立即> 运动到点模式 0当前坐标系进行运动插补，1强制进行关节插补

	QString nCoordinateMode;	//<立即> 坐标系切换模式 0可切换所有坐标系，1跳过TCS、PCS切换(部分四轴机器人无需TCS、PCS)，默认0
	QString nSystemLanguage;	//<重启> 机器人系统当前语言类型，0中文，1英文
	QString nSystemChannel;		//<重启> 机器人系统当前通道号
	QString nSystemGroup;		//<立即> 机器人系统当前的Group，0-第一个Group，1-第二个Group，2-第三个Group
	QString nbreakModeEnable;	//<立即> 是否开启断点重启，0-关闭，1-开启
	QString nSpeedMode;			//<立即> 全局倍率切换模式 0：HMI进行倍率切换 1：PLC进行倍率切换
	QString nPositionerJogMode; //<立即> 变位机JOG模式 0：切换至机器人2进行jog 1：使用扩展轴按键进行JOG
};

#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

//通道控制参数
struct ChannelParam
{
	//8位参数（预留40）
	unsigned char bEnableDynamicCoordinate;   // <复位生效> 是否使能动态坐标系跟踪。0不使能 1使能，默认0
	bool rev8[39];

	//16位参数（预留40）
	//通道控制总轴数 = Group轴数 +外部轴数+龙门从轴
	//通道控制轴顺序：Group轴、外部轴、龙门从轴

	unsigned short nGroupNo[3];		// <重启生效>	通道控制的Group号，[0,GRT_MAX_GROUP_NUM].
	// nGroupNo[0]：第一个Group，默认1 ；
	// nGroupNo[1]：第二个Group，默认0 ；
	// nGroupNo[2]：第三个Group，默认0 ；
	// 0表示无该Group
	// 1对应第一个Group（GroupConfig[0]）
	// 2对应第二个Group（GroupConfig[1]）
	// 3对应第二个Group（GroupConfig[2]）


	unsigned short nExtAxisNum;			// <重启生效>	通道控制的外部轴数，≥0，默认0

	unsigned short nGantryAxisNum;		// <重启生效>	通道控制的龙门从轴数，≥0，默认0

	unsigned short auGroupDynType;		// <复位生效>	辅助Group在动态跟踪中的类型：0 master； 1 slave 
	unsigned short auGroupSynType;		// <复位生效>	辅助Group在同步运动中的类型：0 master； 1 slave

	short nReplayOverrideSelect;		// <立即>	回放模式速度倍率选择，范围：[0,16]，0表示不受倍率影响，默认1
	short nTeachOverrideSelect;			// <立即>	示教模式速度倍率选择，范围：[0,16]，0表示不受倍率影响，默认1

	short dynTransMode;					// <立即> 动态坐标系模式选择，默认0
	short dynTransPrm;					// <立即> 动态坐标系参数，默认0

	short rev16[29];	

	//32位参数（预留40）
	long rev32[40];

	//64位参数（预留100）
	double dynTransMasterOrigin[3][6];		//  <复位生效>  动态跟踪：master的MCS相对当前group的MCS的坐标系变换关系
	double dynTransPcsToMasterTcs[3][6];	//  <复位生效>  动态跟踪：PCS相对master的TCS的坐标系变换关系

	double rev64[64];
};


// 轴配置控制参数
struct AxisConfig
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
	unsigned short extAxisPrgCtrlType;	// <空闲时，立即生效>	外部轴在程序运行中的默认控制类型（参见TYPE_AXIS_MOVE_MODE）
	// 0：绝对模式（默认0）
	// 1：相对模式
	// 2：Jog模式
	// 3：跟随其他轴规划同步运动 
	// 4：跟随group合成规划位置同步运动 
	short velFilterNum;			// <复位生效>	速度规划滤波值,范围[0,4096]
	short	rev16[19];		

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
	double revd64[15];
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
	double rev64[143];	

};


//通道（Group）配置控制参数
struct GroupConfig
{
	//8位参数（预留40）/////////
	bool bEnBlending;			//  <复位生效>	开启轨迹blending
	bool bEnableDynPara;		//  <复位生效>	开启动力学补偿
	bool bEnableLookAhead;		//  <复位生效>	开启前瞻
	
	bool bEnAcsPosiLmt[8];			//  <复位生效>	ACS下开启正向软限位
	bool bEnAcsNegaLmt[8];			//  <复位生效>	ACS下开启负向软限位
	bool bEnMcsPosiLmt[3];			//  <复位生效>	MCS下开启正向软限位
	bool bEnMcsNegaLmt[3];			//  <复位生效>	MCS下开启负向软限位
	bool bEnPcsPosiLmt[3];			//  <复位生效>	PCS下开启正向软限位
	bool bEnPcsNegaLmt[3];			//  <复位生效>	PCS下开启负向软限位
	
	bool rev8[69];

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
	short cpGroupMoveType[6];	//[1,6]有效；1X方向，2Y方向，3Z方向，4绕X方向旋转，5绕Y方向旋转，6绕Z方向旋转
	//默认为{1,2,3,4,5,6}。
	//主要用于笛卡尔下，GROUP轴数小于6且控制对像不连续的情况）
	//如：4轴SCARA,MoveJog没有没有绕X/Y轴旋转，只有绕Z轴旋转,应配置为{1,2,3,6,0,0}；
	//这样笛卡尔坐标系下，NC收到轴4运动命令（G6.3）后，自动执行绕Z轴旋转运动

	short acsVelMode;	//<立即>	ACS轴坐标系下运动的指令速度和加速度的类型。
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
};


//DH参数
struct CouplePara
{
	short master_id;
	double master_value;
	short slave_id;
	double slave_value;
	bool used;
	CouplePara()
	{
		master_id = 0;
		master_value = 0;
		slave_id = 0;
		slave_value = 0;
		used = 0;
	}
};
struct CoupleGroupPara
{
	CouplePara couple_para[COUPLECOUNT];
};
struct DhPara
{
	double kinTransLinkLength[DHMAXCOUNT];
	DhPara()
	{
		memset(this->kinTransLinkLength,0,sizeof(kinTransLinkLength));
	}
};
struct HmiJointDirAndOffset
{
	bool dir[JOINTDIRANDOFFSETCOUNT];
	double offset[JOINTDIRANDOFFSETCOUNT];
	HmiJointDirAndOffset()
	{
		memset(this->dir,0,sizeof(dir));
		memset(this->offset,0,sizeof(offset));
	}
};
struct DhCouplePara
{
	double kinTransLinkLength[DHMAXCOUNT];
	CouplePara couple_para[COUPLECOUNT];
	DhCouplePara()
	{
		memset(this->kinTransLinkLength,0,sizeof(kinTransLinkLength));
	}
};

#pragma pack(pop)

}

#endif
