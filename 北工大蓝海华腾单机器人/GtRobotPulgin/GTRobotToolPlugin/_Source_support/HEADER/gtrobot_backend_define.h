#pragma once
#ifndef GTROBOT_BACKEND_DEFINE_H
#define GTROBOT_BACKEND_DEFINE_H

#include <string>
#include <Windows.h>

const short GtrCurrentGroup = -1;
const short GtrCurrentChannel = -1;

const short GtrMaxChannelNum =	2;	// 机器人系统支持的最大通道数
const short GtrMaxGroupNum =	3;	// 机器人系统支持的最大机器人组
const short GtrMaxAxisNum =		16;	// 机器人系统支持的最大轴数

const short GtrMaxCraftNum =	32;	// 机器人系统支持的最大工艺数量

const short GtrMaxBufSize =		256;// 机器人系统参变量数据区长度


namespace Gtr{


#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

	//Group坐标
	struct GroupPoint
	{
		short coordType;		//坐标系类型：
		//#define COORD_SYSTEM_PCS				(0)
		//#define COORD_SYSTEM_MCS				(1)
		//#define COORD_SYSTEM_ACS				(2)
		//#define COORD_SYSTEM_TCS				(3)
		//#define COORD_SYSTEM_VCS				(4)
		//short m_coord_idx;	//坐标系号：
		//short m_tool_idx;		/具号（TCS坐标系号）：
		short configNumber;		//构型选择（运动路径解选择，ACS设置为1）
		short posType;			//坐标类型（备用:0绝对 1增量, 默认为0）
		short orientationMode;	//指令位置的姿态描述模式(默认=GroupConfig::orientationMode)。
		//当指令位置的描述坐标系为笛卡尔坐标系时，需要指定姿态的描述模式。
		// #define ORI_MODE_NONE				    (0)：无姿态描述
		// #define ORI_MODE_EULER				    (1)：欧拉角姿态描述
		// #define ORI_MODE_QUAD				    (2)：四元数姿态描述
		// #define ORI_MODE_VECTOR				    (3)：刀轴矢量姿态描述
		// #define ORI_MODE_ROTATE_AXIS_POS			(4)：旋转轴位置姿态描述
		short groupIndex;		// Group索引[1,2]：Point::groupPoint[1]有效。
		short rev[3];
		double joint[8];		//坐标值：在关节坐标系下表示各个关节的值，在笛卡尔坐标系下表示位置和四元数(或欧拉角)表示的姿态（[0,2]为XYZ位置，[3,6]为姿态）
	};

	//机器人坐标
	struct Point
	{
		GroupPoint groupPoint[2];  
		double extJoint[8];
		unsigned char used;			//位置点是否有效（标定）：0无效；>0有效
		unsigned char dynSynch;		//动态跟踪：0无效； 1使能
		unsigned char rev[6];
		char comment[256];			//位置型变量注释信息
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

		// 100：由外部命令控制

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
		double absZeroRefPos;						// <立即生效> 参考点位置（默认0），单位：mm或度。绝对编码器零点(absEncoderZeroPos)对应的机床坐标。	
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

		double axisMoveVel;		//<立即生效>	加工时，单轴运动速度，		单位：mm/s或度/s。
		double axisMoveAcc;		//<立即生效>	加工时，单轴运动加速度，	单位：mm/s^2或度/s^2。
		double axisMoveDec;		//<立即生效>	加工时，单轴运动减速度，	单位：mm/s^2或度/s^2。

		double rev64[140];
	};



	//通道（Group）配置控制参数
	struct GroupConfig
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
		short cpGroupMoveType[6];	//[1,6]有效；1X方向，2Y方向，3Z方向，4绕X方向旋转，5绕Y方向旋转，6绕Z方向旋转
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
		double teachAcsMovVel;				// <立即>	运动到点：ACS关节坐标系下运动速度，取值范围：(0,...)，单位：mm/s。
		double teachAcsMovAcc;				// <立即>	运动到点：ACS关节坐标系下运动加速度，取值范围：(0,...)，单位：mm/s^2。
		
		//示教下运动到点：笛卡尔坐标系下运动参数
		double teachMcsMovVel;				// <立即>	运动到点：MCS关节坐标系下运动速度，取值范围：(0,...)，单位：mm/s。
		double teachMcsMovAcc;				// <立即>	运动到点：MCS关节坐标系下运动加速度,取值范围：(0,...)，单位：mm/s^2。
		
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

		double acsPosiLmtOffset[8];			//  <复位生效>	ACS下正向软限位偏移值
		double acsNegaLmtOffset[8];			//  <复位生效>	ACS下负向软限位偏移值
		double mcsPosiLmtOffset[3];			//  <复位生效>	MCS下正向软限位偏移值
		double mcsNegaLmtOffset[3];			//  <复位生效>	MCS下负向软限位偏移值
		double pcsPosiLmtOffset[3];			//  <复位生效>	PCS下正向软限位偏移值
		double pcsNegaLmtOffset[3];			//  <复位生效>	PCS下负向软限位偏移值

		double arcErr;							//  <复位生效>	圆弧最大误差

		//dec 减速度
		double movjDec;						// <立即>	MOVJ默认减速度，取值范围：(0,...)，单位：mm/s^2。
		double movlDec;						// <立即>	MOVL默认减速度，取值范围：(0,...)，单位：mm/s^2。
		double movcDec;						// <立即>	MOVC默认减速度，取值范围：(0,...)，单位：mm/s^2。
		double teachAcsMovDec;				// <立即>	运动到点：ACS关节坐标系下运动减速度。取值范围：(0,...)，单位：mm/s^2。
		double teachMcsMovDec;				// <立即>	运动到点：笛卡尔坐标系下运动减速度。取值范围：(0,...)，单位：mm/s^2。

		double rev64[211];
	};


	struct SysCtlParam
	{
		//8位参数（预留40）

		bool nWatchMode;			// <立即>		WATCH模式  0关闭WATCH模式，1开启WATCH模式。默认0.
		bool bGxnExtModule;			// <重启生效>	是否配置了GXN扩展模块（0表示无，1有）。默认0.
		bool bDisableAxisStopDI;	// <复位生效>	是否关闭轴停止信号（0开启 1关闭）。默认0。

		//16位参数（预留40）
		short nCardType;		// <重启生效>	控制卡（器）类型：GtRobotDef::CardType 
		short nSysAxisNum;		// <重启生效>	系统控制轴数
		short nSysChannelNum;	// <重启生效>	系统通道数：[1,2],默认1
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

		short nEstopMode;		//<立即> 急停模式 0急停立即下使能，1急停减速到0后下使能，默认0
		short nRuntoPointMode;	//<立即> 运动到点模式 0当前坐标系进行运动插补，1强制进行关节插补，2强制进行直角插补 默认0

		short nCoordinateMode;	//<立即> 坐标系模式 0可切换所有坐标系，1跳过TCS、PCS切换(部分四轴机器人无需TCS、PCS)，默认0
		short nSystemLanguage;	//<重启> 机器人系统当前语言类型，0中文，1英文
		short nSystemChannel;	//<重启> 机器人系统通道号
		short nSystemGroup;		//<立即> 机器人系统当前的Group，0-第一个Group，1-第二个Group，2-第三个Group
		short nbreakModeEnable;	//<立即> 是否开启断点重启，0-关闭，1-开启
		short nSpeedMode;		//<立即> 全局倍率切换模式 0：HMI进行倍率切换 1：PLC进行倍率切换
		short nPositionerJogMode;//<立即> 变位机JOG模式 0：切换至机器人2进行jog 1：使用扩展轴按键进行JOG
		short nRecordPosMode;		//<立即> 记录位置点模式 0：当前坐标系 1：强制记录ACS位置 2：强制记录MCS位置 

		short nGxnExtModuleNum;		//<重启> GXN扩展IO模块的个数
		short sSvalogToFile;		//<立即> 系统掉电日志保存 0:退出系统时保存日志 1:退出系统不时保存日志
	};

	//通道控制参数
	struct SysChannelCtrlParam
	{
		//8位参数（预留40）
		unsigned char bEnableDynamicCoordinate;   // <复位生效> 是否使能动态坐标系跟踪。0不使能 1使能，默认0

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
		
		long forcedReplayStartLine;			//<立即> 回放模式强制启动行号
		
		double jogStepLen;					// 示教模式下，手动步进模式的步长，单位mm或度。

		char forceReplayStartPrg[256];		//<立即> 回放模式强制启动程序目录
	};


	//耦合比参数
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
	struct HmiCoupleGroupPara
	{
		CouplePara couple_para[4];
	};

	//坐标系参数
	struct CoordSystem
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
	};

	struct TcpServerConfig
	{
		bool b_enable;					///<使能
		char ip[20];					///<IP地址
		unsigned short port;			///<端口
	};

	struct TcpConnectClientInfo
	{
		std::string ip;					///<IP地址
		unsigned short port;			///<端口
		unsigned long last_comm_time;	///<上一次数据交互时间(ms)
	};


	struct ModbusServerConfig
	{
		bool b_enable;					///<使能
		char ip[20];					///<IP地址
		unsigned short port;			///<端口
		unsigned short *p_di_data;		///<输入数据地址
		unsigned short *p_do_data;		///<输出数据地址
		unsigned short time_out;		///<超时时间
	};

	struct ModbusClientConfig
	{
		bool b_enable;					///<通讯启用使能
		bool b_read;					///<通讯周期读使能
		bool b_write;					///<通讯周期写使能
		char ip[20];					///<IP地址
		unsigned short port;			///<端口
		unsigned short station_id;		///<站地址
		unsigned short read_start_adress;///<读起始地址
		unsigned short read_data_len;	///<读数据长度
		unsigned short write_start_adress;///<写起始地址
		unsigned short write_data_len;	///<写数据长度
		unsigned short *p_di_data;		///<输入数据地址
		unsigned short *p_do_data;		///<输出数据地址
		unsigned short time_out;		///<超时时间,单位毫秒
	};


	//轴状态
	struct AxisStatus
	{
		bool is_servo_alarm;		//伺服报警状态
		bool is_pos_error;			//跟随误差超限
		bool is_positive_limit;		//正限位报警
		bool is_negative_limit;		//负限位报警
		bool is_stop_io;			//轴停止信号
		bool is_estop_io;			//急停IO
		bool is_axis_on;			//伺服状态
		bool is_profile_running;	//运动规划中
		bool is_inpos;				//运动到位
	};


	//驱动器状态
	struct DriverStatus
	{
		bool is_over_current;			//过流
		bool is_over_voltage;			//过压
		bool is_under_voltage;			//欠电压
		bool is_input_outphase;			//输入缺相
		bool is_encoder_error;			//编码器故障
		bool is_over_load;				//过载
		bool is_over_temperature;		//过温
		bool is_io_error;				//IO故障
		bool is_register_protection;	//寄存器保护
		bool is_power_error;			//功率模块错误
		bool is_over_speed;				//过速度
		bool is_over_pressure;			//过压
		bool is_direction_protection;	//方向保护
		bool is_instant_over_current;	//瞬间过流
		bool is_output_offline;			//输出断线
	};

#pragma pack(pop)

	// 描述摆弧类型及参数
	struct GroupWeavePrm
	{
		short type;				// 摆弧类型: (0)正弦形摆弧，摆弧叠加到叠加坐标系的Y轴方向; (100)正弦形摆弧，摆弧叠加到叠加坐标系的X轴方向;

		short weaveMode;		// 摆弧模式
		// 0：摆弧，表示该结构体参数设置的是摆弧参数
		// 1：预摆弧，表示该结构体参数设置的是预摆弧参数

		short frequencyMode;	// 频率模式
		// 0：正负摆弧为同一频率
		// 1：正负摆弧通过weavePrm[0]和weavePrm[1]设置频率比例

		double amplitude;		// 摆弧振幅，范围：(0,10]，单位：mm 

		double frequency;		// 摆弧频率，范围：(0,100]，单位：Hz

		double weavePrm [10];	// 摆弧几何参数，大小为10的数组。
		// 当摆弧类型为正弦型摆弧时，通过weavePrm[0]和weavePrm[1]参数分别描述正向和负向的幅值比例，取值范围为[0,1]。
		// 当摆弧类型为锯齿形摆弧时，通过weavePrm[0]参数描述锯齿形摆弧的几何参数k，取值范围为[-1.5,1.5]。

		short startPosition;	// 摆弧开始位置。
		// 0：从中间开始摆弧
		// 1：从左侧开始摆弧，从叠加值为最大正振幅开始摆动
		// 2：从右侧开始摆弧，从叠加值为最大负振幅开始摆动

		short dweelFullStop;	// 完全停止使能
		// 0：不使能。当摆弧停留时间不为0时，运动规划不停止，只是不进行摆弧运动。
		// 1：使能。当摆弧停留时间不为0时，规划停止。当摆弧停留时间为0时，dweelFullStop使能或不使能，规划都不停止。

		double dweelLeft;		// 摆弧左停留时间，在叠加值为最大正振幅时的停留时间，单位：ms

		double dwellMid;		// 摆弧中停留时间，在叠加值为0时的停留时间，单位：ms

		double dwellRight;		// 摆弧右停留时间，在叠加值为最大负振幅时的停留时间，单位：ms

		short oriControlMode;	// 摆弧姿态控制模式
		// 0：摆动过程中不改变原有姿态。
		// 1：摆动过程中启动姿态控制，原规划姿态不生效。（暂不支持）

		double rotateAngleX;	// 绕运动坐标系的X轴的旋转角，用于控制内外倾旋转角，
		// 即旋转角大于0，为外倾，旋转角小于0，为内倾，范围：[-90,90]，单位：度

		double rotateAngleY;	// 绕运动坐标系的Y轴的旋转角，用于控制前后倾旋转角，
		// 旋转角大于0，为前倾，旋转角小于0，为后倾，范围：[-90,90]，单位：度

		double rotateAngleZ;	// 绕运动坐标系的Z轴的旋转角，范围：[-90,90]，单位：度

	};


	// 设置直接叠加值
	struct GroupSuperpositionValueDirect
	{
		double value[8];                         // 叠加值
		double reserve[24];
	};

	struct GroupSuperpositionWeaveEx
	{
		short mode;                              // 摆弧叠加子模式 0：摆弧叠加模式 1：预摆弧模式
		short pad[3];                            // 对齐
		double time;                             // 预摆弧模式的持续时间
		double velocity;                         // 预摆弧模式的速度
		double reserve[29];
	};

	union GroupSuperpositionUnion
	{
		GroupSuperpositionValueDirect direct;   // 直接叠加值
		GroupSuperpositionWeaveEx weaveEx;      // 摆弧叠加扩展模式
		double data[32];
	};

	//group的运动叠加功能参数
	struct GroupSuperpositionPrm{
		
		short enable;         // 叠加是否使能
		short mode;           // 叠加模式 0：直接叠加 1：根据时间进行摆弧叠加 2：摆弧叠加扩展模式
		short pad[2];
		double smoothTime;    // 平滑时间
		GroupSuperpositionUnion data;
	};


	struct UserComParam
	{
		short channel_index;
		short user_id;			//对应USER指令参数：ID
		long  long_param[4];	//对应USER指令参数：L1、L2、L3、L4
		double double_param[4]; //对应USER指令参数：D1、D2、D3、D4
	};

	//日志
	struct LogItem
	{
		short log_type;
		short user_type;
		char log_id[256];
		char text[256];
		char datetime[256];

		LogItem(){

			log_type = -1;
			user_type = -1;
			memset(log_id,0,256);
			memset(text,0,256);
			memset(datetime,0,256);
		}
	};

	//日志-兼容旧版本
	struct GT_LogItem
	{
		char username[256];
		char text[256];
		char datetime[256];

		GT_LogItem(){

			memset(username,0,256);
			memset(text,0,256);
			memset(datetime,0,256);
		}
	};

	//TCP通信
	struct STcpServerInfo
	{
		char ip[20];					///<IP地址
		unsigned short port;			///<端口
	};

	struct STcpClientStatus
	{
		bool is_connecting;				///<正在连接状态
		bool is_connected;				///<已经连接上
		bool allow_read;				///<允许读取
	};

	typedef short (*GtrUserCom)(const UserComParam &param,bool first);
	typedef short (*GtrUserRun)();
	typedef void (*GtrPlcLoop)();


	//坐标系
	enum TYPE_COORD
	{
		PCS = 0,		//COORD_SYSTEM_PCS,
		MCS = 1,		//COORD_SYSTEM_MCS,
		ACS = 2,		//COORD_SYSTEM_ACS,
		TCS = 3,		//COORD_SYSTEM_TCS,
		VCS	= 4,		//COORD_SYSTEM_VCS,
		FCS = 5,		//COORD_SYSTEM_FCS,
		CURRENT = 6,	//当前坐标系
		MVCS = 10,		//COORD_SYSTEM_MVCS
		PCS2 = 40		//COORD_SYSTEM_PCS2
	};

	enum Key
	{
		Key_EStop =			0,	// 急停按钮
		Key_Start,				// 启动
		Key_Stop,				// 停止/暂停
		Key_ThreeStateSwitch,	// 三段开关

		Key_ServoOn =		10,	// 伺服准备开
		Key_Reset,				// 复位/清除报警
		Key_SpeedUp,			// 加速
		Key_SpeedDown,			// 减速
		Key_MoveForward,		// 前进（前进检查，或运动到点）
		Key_MoveBackward,		// 后退（后腿检查，或运动到点）
		Key_OverrideLimit,		// 取消限制

		Key_SwitchExtAxis =	20,	// 切换外部轴
		Key_SwitchRobotGroup,	// 切换机器人组
		Key_SwitchCoord,		// 切换坐标系
		Key_SwitchCmdType,		// 切换指令类型（切换“插补”类型）

		Key_CmdList =		30,	// 命令一览
		Key_Insert,				// 插入
		Key_Delete,				// 删除
		Key_Edit,				// 修改
		Key_Confirm,			// 确认

		Key_Shift =			40,	// 上档
		Key_Ctrl,				// 连锁
		Key_PageDown,			// 翻页
		Key_Up,					// 方向键向上
		Key_Down,				// 方向键向下
		Key_Left,				// 方向键向左
		Key_Right,				// 方向键向右

		Key_0 =				50,	// 数字0
		Key_1,					// 数字0
		Key_2,					// 数字0
		Key_3,					// 数字0
		Key_4,					// 数字0
		Key_5,					// 数字0
		Key_6,					// 数字0
		Key_7,					// 数字0
		Key_8,					// 数字0
		Key_9,					// 数字0

		Key_Dot =			60,	// 英文句号(点".")
		Key_Minus,				// 减号（横杠"-"）

		Key_X_Negative  =	70,	//手持盒按键X-
		Key_X_Positive,			//手持盒按键X+
		Key_Y_Negative,			//手持盒按键Y-
		Key_Y_Positive,			//手持盒按键Y+
		Key_Z_Negative,			//手持盒按键Z-
		Key_Z_Positive,			//手持盒按键Z+
		Key_RX_Negative,		//手持盒按键RX-
		Key_RX_Positive,		//手持盒按键RX+
		Key_RY_Negative,		//手持盒按键RY-
		Key_RY_Positive,		//手持盒按键RY+
		Key_RZ_Negative,		//手持盒按键RZ-
		Key_RZ_Positive,		//手持盒按键RZ+
		Key_E1_Negative,		//手持盒按键E1-
		Key_E1_Positive,		//手持盒按键E1+
		Key_E2_Negative,		//手持盒按键E2-
		Key_E2_Positive,		//手持盒按键E2+
	};

	//原枚举名称 Running_Mode 2021.05.16
	enum RUNNING_MODE{

		MODE_TEACH = 1,		//示教模式
		MODE_REPLAY,		//回放模式
		MODE_REMOTE			//远程模式
	};

	//原枚举名称 Running_Status 2021.05.16
	enum RUNNING_STATUS{

		IDLE = 1,			//空闲状态
		PAUSE ,				//暂停状态
		RUNNING				//运行状态
	};

	enum TEACH_STATUS{

		TEACH_IDLE = 1,				//示教模式-空闲状态
		TEACH_FORWARD_STATUS,		//示教模式-前进检查状态
		TEACH_BACKWARD_STATUS,		//示教模式-后退检查状态
		TEACH_MOVE_TO_POINT_STATUS,	//示教模式-运动到点状态
		TEACH_JOG_STATUS			//示教模式-JOG运动状态
	};

	//原枚举名称 Compare_Option 2021.05.16
	enum COMPARE_OPTION{
	
		 CP_LT = 1,			//小于<
		 CP_LE,				//小于等于<=
		 CP_GT,				//大于>
		 CP_GE,				//大于>=
		 CP_EQ,				//等于=
		 CP_NEQ				//不等于!=
	};

	//原枚举名称 LogType 2021.05.16
	//日志类型
	enum LOG_TYPE{

		TYPE_DEBUG,
		TYPE_INFO,
		TYPE_WARNING,
		TYPE_ALARM,
		TYPE_CRITICAL
	};

	// 机器人系统参变量数据类型
	enum DataType
	{
		TYPE_FLOAT = 0,			// 单精度型
		TYPE_DOUBLE = 1,		// 双精度（实数型变量）
		TYPE_BOOL = 2,			// 布尔型（布尔型变量）
		TYPE_SHORT = 3,			// 短整型
		TYPE_UNSIGNED_SHORT = 4,// 无符号短整型（寄存器变量）
		TYPE_LONG = 5,			// 长整型（整数型变量）
		TYPE_UNSIGNED_LONG = 6,	// 无符号短整型
		TYPE_UNSIGNED_CHAR = 7, // 无符号字符型
		TYPE_POINT = 10,		// 通道位置（位置型变量）
		TYPE_GROUP_POINT = 11,	// 机器人组位置
		TYPE_COORD_SYSTEM = 12,	// 坐标系
		TYPE_STR = 20,			// 字符串（字符型变量）
	};

	// 机器人系统参变量操作类型
	enum ActionType
	{
		GET_FROM_ROBOT = 0,	// 从机器人数据区获取二进制数据
		SET_TO_ROBOT = 1	// 将二进制数据写入机器人数据区
	};

	// 机器人工艺类型
	enum CraftType
	{
		CRAFT_SYSTEM =		0,	// 机器人系统

		CRAFT_USER =		10,	// 用户自定义工艺
		CRAFT_PALLETIZE =	11,	// 码垛
		CRAFT_PUNCH =		12,	// 冲压
		CRAFT_SCREW =		13,	// 拧紧
		CRAFT_SORT =		14,	// 分拣
		CRAFT_BEND =		15,	// 折弯
		CRAFT_GRIND =		16,	// 打磨
		CRAFT_ARCWELD =		17,	// 弧焊
		CRAFT_SPRAY =		18,	// 喷涂
		CRAFT_OTHER =		19,	// 其它工艺
	};

	// 参变量操作函数：函数原型
	// @param [in/out] const char * 输入/输出的参变量数据区，最大长度为GtrMaxBufSize
	// @param [in/out] Gtr::DataType & 输入/输出的变量数据类型
	// @param [in] const Gtr::ActionType & 输入操作类型
	// @param [in] const long & 输入的变量索引
	// @param [in] const short & 输入的二级索引
	// @param [in] const short & 输入的三级索引
	typedef short(*GTR_RobotValueAction)(char buf[GtrMaxBufSize],  
		Gtr::DataType &,
		const Gtr::ActionType &, 
		const long &, 
		const short &, 
		const short &);
}

#endif