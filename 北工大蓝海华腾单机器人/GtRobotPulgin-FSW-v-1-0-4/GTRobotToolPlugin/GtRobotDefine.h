#pragma once

#ifndef GTROBOTDEFINE_H
#define GTROBOTDEFINE_H

#include "windef.h"  

//#define HOOK_MC_CMD         

#define GRT_MAX_AXIS_NUM			(16)		//机器人系统最大控制轴数
#define GRT_MAX_CHANNEL_NUM			(2)			//机器人系统最大通道数
#define GRT_MAX_GROUP_NUM				(3)			//机器人系统最大Group数
#define GRT_MAX_GROUP_AXIS_NUM		(8)			//Group最大轴数
#define GRT_MAX_COORDINATE_NUM		(64)		//（PCS/TCS）坐标系最大个数

#define R688_MAX_AXES               (24)	    //R688最大轴数

#define GRT_MIN_LIST_SPACE          (300)	    // List最小剩余空间
#define GRT_MAX_LIST_SPACE          (4096)     // List最大空间

#define GRT_PUBLIC_BOOL_NUM			(10000)		//bool型公共变量个数：B0~B9999
#define GRT_PUBLIC_INT_NUM			(10000)		//int型公共变量个数： I0~I9999
#define GRT_PUBLIC_DOUBLE_NUM		(10000)		//double型公共变量个数：R0~R9999
#define GRT_PUBLIC_POINT_NUM		(10000)		//位置型公共变量个数：P0~P9999
#define GRT_PUBLIC_STRING_NUM		(1000)		//字符串型公共变量个数：STR0~STR999
#define GRT_PUBLIC_STRING_LEN		(256)		//单个字符串型公共变量长度

#define GRT_FILEPATH_STRING_LEN		(256)		//文件路径、名称字符串长度

#define GRT_PLC_DATA16_NUM			(1000)		//PLC：16位X/Y/F/G/M变量个数：如，X0.0~X199.15

#define GRT_PLC_DATA32_NUM			(3000)		//PLC：32位D变量个数（程序中访问$0~$2999）
#define GRT_PLC_DATA64_NUM			(3000)		//PLC：32位D变量个数（程序中访问$3000~$5999）


#define GRT_MAX_DIO_GROUP_NUM			(8)			//DIO输入输出信号组数
#define GRT_MAX_DIO_GROUP_PORT_NUM		(64)		//单组DIO支持的信号个数（原来为32）


#define GRT_MAX_DAC_NUM				(20)		//Dac输出通道数
#define GRT_MAX_ADC_NUM				(20)		//Adc输入通道数

#define GRT_MAX_XY_SIGNAL_NUM		(400)		//可配置的XY信号个数

#define GRT_SLEEP_NC        		(10)//(10)		//(1)
#define GRT_SLEEP_PLC        		(10)//(2)			//(18)
#define GRT_SLEEP_PAUSE       		(100)

#define GRT_ERROR_OPEN              (-6)
#define GRT_NONE                    (-1)
#define GRT_SUCCESS       		    (0)
#define GRT_ERROR_EXECUTE           (1)
#define GRT_ERROR_PARAMETER         (7)
#define GRT_ERROR_UNKNOWN           (8)
#define GRT_ERROR_LOADFILE          (-1)

#define GRT_LIST_FULL       		 (10700) //指令流满，下次重新压指令 20200720

#define GRT_DEBUG_MSG_LEN           (512)

#define GRT_MIN_FILE_LEN            (2)
#define GRT_MAX_FILE_LEN            (256)

#define GRT_MIN_OVERRIDE            (0.00001)
#define GRT_MAX_OVERRIDE            (100.00001)

#define GRT_SCALE_PERCENT           (0.01)
#define GRT_SCALE_MILLI             (0.001)
#define GRT_SCALE_PPM               (0.000001)

#define GRT_ZERO_FLOAT              (0.001)

#define GRT_STEP_LENGTH             (50)



#define GRT_NO_INIT                 (-1)

#define GRT_OVERRIDE_DEFAULT        (1.0)

#define GRT_SYS_STATUS_UNLOCK   	(0)
#define GRT_SYS_STATUS_LOCK		    (1)
#define GRT_SYS_STATUS_NOALARM   	(0)
#define GRT_SYS_STATUS_ALARM	    (1)

#define GRT_LOOKAHEAD_NUM_DEFAULT   (2) //(100)

#define GRT_DECODER_REPEAT_ONCE   	(1)
#define GRT_DECODER_REPEAT_LOOP     (-1)

#define GRT_GROUP_AXIS_NUM_MCS      (6)

#define GRT_GROUP_DIFFERENT_POS_THRESHOLD     (10.0)

namespace GtRobotDef
{
	//坐标系
	enum TYPE_COORD
	{
		PCS = 0,	//COORD_SYSTEM_PCS,
		MCS = 1,	//COORD_SYSTEM_MCS,
		ACS = 2,	//COORD_SYSTEM_ACS,
		TCS = 3,	//COORD_SYSTEM_TCS,
		VCS	= 4,	//COORD_SYSTEM_VCS,
		FCS = 5,	//COORD_SYSTEM_FCS
		MVCS = 10,	//COORD_SYSTEM_MVCS
		PCS2 = 40,		//COORD_SYSTEM_PCS2 
		PCS3 = 41		//COORD_SYSTEM_PCS3
	};

	//控制器类型
	enum TYPE_CONTROLER
	{
		MARVIE4 = 0, //拿云4
		MARVIE6,
		R688C,
		R688S
	};

	//结构类型
	enum TYPE_KIN
	{
		KIN_ORTHOGONAL = 0,			//标准正交三轴结构。
		KIN_NON_ORTHOGONAL,			//非正交结构。
		KIN_ROBOT,					//机器人结构。
		KIN_FIVE_AXIS,				//五轴结构。
		KIN_MULTI_AXIS				//多轴结构。
	};

	//机器人类型
	enum TYPE_ROBOT
	{
		SCARA = 0,
		SIX_R_S_WRIST,
		DELTA
	};

	//轴反馈编码器类型
	enum TYPE_ENCODER
	{
		ENCODER_ABS=0,		//绝对编码器
		ENCODER_INC,		//增量编码器
		ENCODER_PULSE		//脉冲计数器（无编码器）
	};

	//轴控制模式
	enum TYPE_AXIS_CTRL_MODE
	{
		CTRL_MODE_PULSEDIR = 0,		//脉冲+方向
		CTRL_MODE_DAC,				//模拟量
		CTRL_MODE_NPPULSE			//正负脉冲
	};


	//轴类型
	enum TYPE_AXIS
	{
		LINEAR = 0,
		ROTARY,
		HELIX
	};

	//DIO有效电平
	enum SENCES_LEVEL
	{
		LEVEL_LOW = 0,	//低电平触发：常闭
		LEVEL_HIGH		//高电平触发：常开
	};

	//DI类型
	enum TYPE_DI
	{
		GPI = 0,		//本地
		EHMI_DI,		//eHmi面板
		GXN_EXTDI		//GXN扩展模块
	};

	//DO类型
	enum TYPE_DO
	{
		GPO = 0,		//本地
		EHMI_DO,		//eHmi面板
		GXN_EXTDO		//GXN扩展模块
	};

	//Adc类型
	enum TYPE_ADC
	{
		ADC = 0,		//本地
		AU_ADC,			//辅助
		GXN_EXTAI		//GXN扩展模块
	};

	//Dac类型
	enum TYPE_DAC
	{
		DAC = 0,		//本地
		AU_DAC,			//辅助
		GXN_EXTAO		//GXN扩展模块
	};

	//PLC的XY变量类型
	enum TYPE_PLC
	{
		VAR = 0,	//普通变量，其值由程序决定
		CONST_0,		//常量0(强制0)
		CONST_1		//常量1(强制1)
	};

	//Group坐标
	typedef struct 
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
	}GroupPoint;

	//机器人坐标
	typedef struct 
	{
		GroupPoint groupPoint[2];  
		double extJoint[8];
		unsigned char used;			//位置点是否有效（标定）：0无效；>0有效
		unsigned char dynSynch;		//动态跟踪：0无效； 1使能
		unsigned char rev[6];
	}Point;


	//轴状态(32位)
	typedef struct 
	{
		unsigned long bit0: 1;
		unsigned long servoAlm: 1;
		unsigned long bit2: 1;
		unsigned long bit3: 1;
		unsigned long posErr: 1;	//4
		unsigned long posiLmt: 1;	//5
		unsigned long negaLmt: 1;	//6
		unsigned long stopIO: 1;	//7
		unsigned long eStopIO: 1;	//8
		unsigned long axisOn: 1;	//9
		unsigned long prfRun: 1;	//10
		unsigned long inpos: 1;		//11
		unsigned long bit12: 20;
	}TRAxisStatus;

	//指令流状态
	typedef struct 
	{
		short execute;			//指令流执行状态，0：未执行，1：正在执行。
		short empty;			//指令流跑空状态，0：未跑空过，1：跑空过。跑空状态在再次调用启动指令流指令或者清空指令流数据时会清除。也可以调用清除指令流状态的指令进行清除。
		short stopInfo;			//指令流停止信息, 0：无停止信息
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
		short commandType;		//正在执行的指令类型
								//COMMAND_LIST_TYPE_NONE(-1)：未知类型
								//COMMAND_LIST_TYPE_MOTION_COMMAND(1)：运动操作指令
								//COMMAND_LIST_TYPE_DELAY_COMMAND(2)：延时操作指令
								//COMMAND_LIST_TYPE_IO_COMMAND(3)：IO操作指令
								//COMMAND_LIST_TYPE_WAIT_COMMAND(4)：等待操作指令
								//COMMAND_LIST_TYPE_OTHER_COMMAND(5)：其他操作指令
		short	cmmand;		//正在执行的指令

		short remainderSegCount; //20200707 DSP空间的剩余未执行段数，用于启动指令流时的判断依据。

		short rev16[2];			

		long executeSegNum;		//指令流当前执行段段号。
		long space;				//指令流DSP剩余空间。 20200707 改为DSP空间减去前瞻段数
		long userTag;
	}TRListStatus;


	//指令流设置
	typedef struct 
	{
		short list;				// 指令流号，取值范围：[0,4]。0时，指令为立即指令,>0时，指令为指令流指令
		short modal;			// 0非阻塞模式；1阻塞模式，等待当前指令运动完成。
		long segNum;			// 指令段号，取值范围：[-2147483648,2147483647]。
		long line;				// 指令行号（用于报警显示）
	}TRListInfo;


	//单轴点位运动参数(绝对运动)
	typedef struct
	{
		double pos;					// 目标位置，单位mm。
		double vel;					// 目标速度，单位mm/s。
		double velEnd;				// 终点速度，单位mm/s。
		double acc;					// 加速度,单位mm/s2
		double dec;					// 减速度,单位mm/s2
		short direction;			// 运动方向，旋转轴模式下有效。
		short overrideSelect;		// 倍率选择，范围：[0,16]，0表示不受倍率影响
		short reserve[2];
	} TRAxisAbsoluteMovePrm;

	//单轴点位运动参数(相对对运动)
	typedef struct  
	{
		double distance;
		double vel;
		double velEnd;
		double acc;
		double dec;
		short overrideSelect;
		short reserve[3];
	} TRAxisRelativeMovePrm;


	//单轴运动模式
	enum TYPE_AXIS_MOVE_MODE
	{
		AXIS_MOVE_ABS = 0,			//绝对模式
		AXIS_MOVE_REL,				//相对模式
		AXIS_MOVE_JOG,				//Jog模式
		AXIS_MOVE_PROFILE_GEAR,		//跟随其他轴规划同步运动 
		AXIS_MOVE_GROUP_GEAR,		//跟随group合成规划同步运动 

		AXIS_MOVE_HMI_CMD=100		//由外部命令/模式控制
	};
	//单轴运动参数
	typedef struct
	{
		short mode;					// 运动模式（TYPE_AXIS_MOVE_MODE）
		short direction;			// 运动方向：绝对模式，旋转轴模式下有效，
		short overrideSelect;		// 倍率选择，范围：[0,16]，0表示不受倍率影响
		short reserve[1];

		double pos;					// 目标位置(绝对模式)，单位mm。
		double distance;			// 一定距离(相对模式)，单位mm。
		double vel;					// 目标速度，单位mm/s。 （JOG模式下，速度正负值决定运动方向）
		double velEnd;				// 终点速度，单位mm/s。
		double acc;					// 加速度,单位mm/s2
		double dec;					// 减速度,单位mm/s2	
	} TRAxisMovePrm;



	//直线插补运动参数
	typedef struct  
	{
		double pos[GRT_MAX_GROUP_AXIS_NUM];	// 目标位置，单位mm。
		short  dir[GRT_MAX_GROUP_AXIS_NUM];	// 运动方向，旋转轴模式下有效。
		double vel;							// 合成速度，单位mm/s（实际规划速度=合成速度*速度倍率）
		double acc;							// 加速度,单位mm/s2	
		double dec;									// 减速度,单位mm/s2
		double blendLen;					// blend长度，单位mm。
		short  overrideSelect;				// 倍率选择
		short  endVelocityMode;			//终点速度模式，0：前瞻使能时，终点速度由前瞻模块决定，1：终点速度为0。
		short  orientationDir;				// 姿态变化方向，0：短路径方向，1：长路径方向
		short  reserve2[1];
	} TRGroupLineMovePrm;


	//圆弧插补运动参数
	typedef struct
	{
		short arcMode;								//圆弧描述模式，CIRCULAR_MODE_SPACE_BORDER等
		short arcPlane;								//圆弧插补平面，XY,YZ,ZX
		short endPointMode;						//圆弧终点指定模式，0：终点为输入的终点位置，1：终点由圆心角决定
		short arcPathChoice;						//圆弧插补方向，平面圆弧时为方向(1：逆时针，-1：顺时针)，空间圆弧为优劣弧(1：劣弧，-1：优弧)
		
		short auxPointCommandCoord;         //中间点位置描述坐标系
		short auxPointOrientationMode;		//中间点位置描述姿态
		short auxPointConfigIndex;				 //中间点构型解
		short auxStartPointCommandCoord;    //辅助起点位置描述坐标系

		short auxStartPointOrientationMode;	//辅助起点位置描述姿态
		short auxStartPointConfigIndex;		//辅助起点构型解

		short overrideSelect;						// 倍率选择
		short endVelocityMode;					//终点速度模式，0：前瞻使能时，终点速度由前瞻模块决定，1：终点速度为0。
		short  orientationDir;						// 姿态变化方向，0：短路径方向，1：长路径方向
		short  rev[3];	

		double arcRadius;							//圆弧半径，单位：mm。
		double centralAngle;						//圆心角，单位：度。
		double auxPoint[GRT_MAX_GROUP_AXIS_NUM];	//圆弧的辅助点位置（圆心或中间点）。单位：mm。
		double auStartPoint[GRT_MAX_GROUP_AXIS_NUM];//辅助起点位置（4点圆弧），单位mm。

		double pos[GRT_MAX_GROUP_AXIS_NUM];			// 终点位置，单位mm。
		double vel;									// 合成速度，单位mm/s（实际规划速度=合成速度*速度倍率）
		double acc;									// 加速度,单位mm/s2
		double dec;									// 减速度,单位mm/s2
		double blendLen;							// blend长度，单位mm。

	}TRGroupCircularMovePrm;

	//(PCS/TCS)笛卡尔坐标系变换参数
	typedef struct
	{
		double transX;		//X轴偏移量。单位：mm。
		double transY;		//Y轴偏移量。单位：mm。
		double transZ;		//Z轴偏移量。单位：mm。
		double rotAngle1;	//旋转角度1。单位：度。
		double rotAngle2;	//旋转角度2。单位：度。
		double rotAngle3;	//旋转角度3。单位：度。
	}TRCartesianTransPrm;

	typedef struct
	{
		double vel;				        // 位置速度，单位mm/s
		double oriVel;                  // 姿态速度，单位度/s
		double reserve[18];
	}TRCartesianTransformVelConstraint;

	typedef union
	{
		TRCartesianTransformVelConstraint velConstraint;
		double value[20];
	}TRCartesianTransformConstraintUnion;

	typedef struct 
	{
		short mode;			// 模式
		short reserve[3];	
		TRCartesianTransformConstraintUnion data;
	}TRCartesianTransformConstraint;

	//设置轨迹blending参数（前瞻开启有效）
	typedef struct 
	{
		short blendType;	// 轨迹blending类型:	0 BLEND_MODE_NONE：不处理
							//						1 BLEND_MODE_ARC： 圆弧blending
							//						2 BLEND_MODE_BIARC：双圆弧blending
		short prmType;		// 轨迹blending过渡段参数类型:
							// 0 BLEND_PARA_TYPE_ERROR：误差，只对BLEND_MODE_ARC生效
							// 1 BLEND_PARA_TYPE_RADIUS：过渡圆弧半径，只对BLEND_MODE_ARC生效
							// 2 BLEND_PARA_TYPE_DISTANCE：距离
		double prm;			// blending过渡段参数（误差，圆弧半径，距离），单位mm。
		double minAngle;	// blending处理的最小角度，当轨迹矢量角度变化小于该角度时不进行处理。
		double maxAngle;	// blending处理的最大角度，当轨迹矢量角度变化大于该角度时不进行处理。	
	}TRPathBlendingPrm;



	//等待DI输入信号
	typedef struct
	{
		//MC_LIMIT_POSITIVE：正限位。[1,24]
		//MC_LIMIT_NEGATIVE：负限位。[1,24]
		//MC_ALARM：驱动报警。[1,24]
		//MC_HOME：原点开关。[1,24]
		//MC_GPI：通用输入。[1,100]
		//MC_ARRIVE：电机到位信号。[1,24]
		//MC_MPG：手轮MPG轴选和倍率信号（5V电平输入）。[1,28]

		short diType;
		short diIndex;
		short diCount;
		short rev1[1];
		short diValue[8];
		long  diOverTime;  // 等待超时时间，≥0, 0为无线等待
		long  rev2[1];
	}TRWaitDIPrm;

	//设置DO输出状态。
	typedef struct
	{
		//doType=MC_ENABLE时，doIndex取值范围为：[1,24]。
		//doType=MC_CLEAR时，doIndex取值范围为：[1,24]。
		//doType=MC_GPO时，doIndex取值范围为：[1,40]。
		//doType=MC_EHMI_DO时，doIndex取值范围：[1,n]，n为初始化EHMI接口时所设置的数量

		//mode：do输出模式
		//	0：立即输出。输出电平或脉冲
		//	1：在距离目标点还有指定距离时，延时一段时间后输出
		//	2：等距离输出。
		//	3：等时间输出。

		// 101: ANTOUT DELAY
		// 102: ANTOUT DIS
		// 103: ANTOUT T

		short mode;              //Do输出模式
		short doType;
		short doIndex;
		short doCount;			  //[1,8]
		short doValue[8];

		double distance;	//mode1：指定距离,		mode2：距离	, 单位mm
		double time;		//mode1：延时时间,		mode3：时间	, 单位ms
	}TRWriteDOPrm;


	//设置模拟量输出电压
	typedef struct
	{
		//aoType=MC_DAC时，		aoIndex取值范围：[1,8]。	aoValue取值范围：[-10,10]，输出精度为0.0003V。
		//aoType=MC_AU_DAC时，	aoIndex取值范围：[1,4]。	aoValue取值范围：[0,10]，输出精度为0.0024V。
		short aoType;
		short aoIndex;
		short count;
		short rev1;
		double aoValue[8];
	}TRWriteAOPrm;


	//设置group的速度规划参数
	typedef struct 
	{
		short mode;					// 40： ROFILE_MODE_SMOOTH：平滑模式;  46： PROFILE_MODE_JERK：Jerk模式
		short jerkBeginPercent;		// Jerk模式：起始加速度百分比，取值范围：[0,100]。
		short jerkEndPercent;		// Jerk模式：终止加速度百分比，取值范围：[0,100]。
		short rev16[5];	

		double jerkValue;			// Jerk模式：加加速度,取值范围：(0,...)，单位：mm/s^3

		double smoothAccTime;		// 平滑模式：加速度变化时间
		double smoothK;				// 平滑模式：形态系数，取值范围：[0,1000]。

	} TRVelProfilePrm;


	//等待条件指令参数
	typedef struct
	{
		short enable;				// 使能
		short iCmdType;				// 指令类型：ListWait 或 AstWait 
		short iResult;				// 等待结果

		short iWaitType;			// P1 等待类型：DI、AI、VAR、DIS、T
		short iConditionParaType;	// P2 比较DI、AI的类型；VAR\B\I\R的索引
		short iConditionParaIndex;	// P3 比较DI、AI端口号；
		short iConditionOption;		// P4 比较选择：大于、小于.....

		short iOutVarType;			// P8 输出变量类型：VAR\B\I\R
		short iOutVarIndex;			// P9 输出变量索引：
		short iOverTimeOption;		// P10 超时处理选择：暂停、停止（报警）、继续
		short iMode;				// P11 是否模态，1模态 0非模态
		short rev16[5];	
		
		long lContiTime;		// P6 持续时间
		long lOverTime;			// P7 等待超时时间，≥0, 0为无线等待
		long lValue;			// P5 整型比较值：DI
		long segnum;			// 段号

		double	dValue;			// P5 double型比较值：AI、VAR、DIS、T	
	}TRWaitConditionPrm;

	//等待条件指令执行状态
	typedef struct
	{
		short conditionDone;	//状态：0等待条件未完成，1等待条件已完成
		short modal;				//模态：
		long segNum;				//段号
		long userTag;				//行号
	}TRWaitConditionInfo;


	//同步指令
	typedef struct
	{
		short enable;				//0：不使能，1：使能
		short masterType;			// 类型
		short masterIndex;			// 索引
		short masterSubIndex;		// 二级索引
	
		short slaveType;			// 类型
		short slaveIndex;			// 索引
		short slaveSubIndex;		// 二级索引
	
		double masterEven;			// 传动比系数：主轴位移
		double slaveEven;			// 传动比系数：从轴位移	

		double slavePos;			// 从轴目标位置
	}TRMoveSynPrm;

	//动态跟踪
	typedef struct
	{
		short groupID;
		short enable;    //0：不使能，1：使能
		short masterType;
		short masterIndex;
		short masterMoveType;
		short trackMode;
		double originPrfPos;
		double masterOrigin[6];
		double pcsToMasterTcs[6];
	}TRDynTransPrm;


	// 描述摆弧类型及参数
	typedef struct  
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

	}TRGroupWeavePrm;


	

	// 设置直接叠加值
	typedef struct  
	{
		double value[8];                         // 叠加值
		double reserve[24];
	}TRGroupSuperpositionValueDirect;

	typedef struct
	{
		short mode;                              // 摆弧叠加子模式 0：摆弧叠加模式 1：预摆弧模式
		short pad[3];                            // 对齐
		double time;                             // 预摆弧模式的持续时间
		double velocity;                         // 预摆弧模式的速度
		double reserve[29];
	}TRGroupSuperpositionWeaveEx;

	typedef union  
	{
		TRGroupSuperpositionValueDirect direct;   // 直接叠加值
		TRGroupSuperpositionWeaveEx weaveEx;      // 摆弧叠加扩展模式
		double data[32];
	}TRGroupSuperpositionUnion;

	//group的运动叠加功能参数
	typedef struct  
	{
		short enable;         // 叠加是否使能
		short mode;           // 叠加模式 0：直接叠加 1：根据时间进行摆弧叠加 2：摆弧叠加扩展模式
		short pad[2];
		double smoothTime;    // 平滑时间
		TRGroupSuperpositionUnion data;
	}TRGroupSuperpositionPrm;

	typedef struct  
	{
		short coordSystem;
		short oriMode;
		short configIndex;
		short targetOriMode;
		short reserve1[8];
		double inputPos[8];
		double preAcsPos[8];
		double reserve2[24];
	}TRGroupPosTransformInput;

	typedef struct  
	{
		short configIndex;
		short singularity;
		short reserve1[10];
		double pcsPos[8];
		double mcsPos[8];
		double acsPos[8];
		double reserve2[16];
	}TRGroupPosTransformOutput;
}
#endif