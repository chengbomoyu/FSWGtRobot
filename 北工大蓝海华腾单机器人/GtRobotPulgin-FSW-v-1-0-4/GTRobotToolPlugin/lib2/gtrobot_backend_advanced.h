#pragma once

#ifndef GTROBOT_BACKEND_ADVANCED_H
#define GTROBOT_BACKEND_ADVANCED_H

#include "gtrobot_backend_define.h"

#ifdef GTR_BACKEND_LIB
# define GTR_ADVANCED_EXPORT extern "C" __declspec(dllexport)
#else
# define GTR_ADVANCED_EXPORT extern "C" __declspec(dllimport)
#endif



namespace Gtr_Advanced{

#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

	struct Cmd_Movj{

		Gtr::Point des_point;	//目标位置点
		double speed;			//速度范围0~100(百分比)，单位:无
		double blending;			//BL范围0~∞，单位:mm
		double vblending;		//VBL范围0~100(百分比)，单位:无
	};
	struct Cmd_Movl{

		Gtr::Point des_point;	//目标位置点
		double speed;			//速度范围0~∞，单位:mm/s
		double blending;			//BL范围0~∞，单位:mm
		double vblending;		//VBL范围0~100(百分比)，单位:无
	};
	struct Cmd_Movc{

		Gtr::Point mid_point;	//中间位置点
		Gtr::Point des_point;	//目标位置点
		double speed;			//速度范围0~∞，单位mm/s
		double blending;			//BL范围0~∞，单位mm
		double vblending;		//VBL范围0~100(百分比),单位:无
	};
	struct Cmd_User{

		short type;				//模块号
		short id;				//端口号
		long long_data[4];		//long型参数
		double double_data[4];	//double型参数
	};
	struct Cmd_GetPos{

		short coord_type;		//坐标系类型,PCS:0,MCS:1,ACS:2,TCS:3,VCS:4,
		Gtr::Point output_point;//输出至位置点
	};
	struct Cmd_CoordNum{

		short coord_type;		//坐标系类型,PCS:0,MCS:1,ACS:2,TCS:3,VCS:4,
		short id;				//坐标系索引,从0开始
	};
	struct Cmd_GetCapturePos{

		short coord_type;		//坐标系类型,PCS:0,MCS:1,ACS:2,TCS:3,VCS:4,
		Gtr::Point output_point;//输出至位置点
	};
	struct Cmd_Modal{

		short id;
		bool value;
	};
	struct Cmd_ExtJoint{
		bool sync;				//是否打开外部轴模态
	};
	struct Cmd_Speed{

		double speed;			//速度倍率范围0~100(百分比)，单位:无
	};
	struct Cmd_Dyn{

		double acceleration;	//加速度倍率范围0~100(百分比)，单位:无
		double deceleration;	//减速度倍率范围0~100(百分比)，单位:无
		double jerk;			//加加速度范围0~120，单位:ms
	};
	struct Cmd_Set{

		short var_type;			//需要set的变量类型,0-布尔型B，1-整数型I，2-实数型R
		short var_index;		//变量值索引
		union
		{
			bool b_value;		//布尔型变量值
			long i_value;		//整数型变量值
			double r_value;		//实数型变量值
		}value;
	};
	struct Cmd_Until{

		short wait_type;				//等待类型 0-DI，2-布尔型变量B，3-整数型变量I，4-实数型变量
		short wait_para1;				//若等待DI，则代表DI模块号，其他类型为变量下标
		short wait_para2;				//若等待DI，则代表DI端口号，其他类型该参数无效
		Gtr::COMPARE_OPTION wait_operator;	//等待条件，0-大于>，1-等于=，2-不等于!=，3-大于等于》=，4-小于等于<=，5小于<
		double wait_value;				//等待结果
		long continue_time;				//持续时间
		long over_time;					//超时时间
		short output_var_type;			//输出变量类型 0-不输出，2-布尔型变量B，3-整数型变量I，4-实数型变量
		short var_index;				//输出变量索引
	};
	struct Cmd_Wait{

		short wait_type;				//等待类型 0-DI，2-布尔型变量B，3-整数型变量I，4-实数型变量
		short wait_para1;				//若等待DI，则代表DI模块号，其他类型为变量下标
		short wait_para2;				//若等待DI，则代表DI端口号，其他类型该参数无效
		Gtr::COMPARE_OPTION wait_operator;	//等待条件，0-大于>，1-等于=，2-不等于!=，3-大于等于》=，4-小于等于<=，5小于<
		double wait_value;				//等待结果
		long continue_time;				//持续时间
		long over_time;					//超时时间
		short output_var_type;			//输出变量类型 0-不输出，2-布尔型变量B，3-整数型变量I，4-实数型变量
		short var_index;				//输出变量索引
		short overtime_option;			//超时现象，0-暂停运动，1-停止运动且报警，2-继续运动
		bool is_modal;					//是否为模态指令 
	};
	struct Cmd_Timer{

		double time;			//延时范围0~∞，单位：ms
	};
	struct Cmd_ExtjSpeed{

		short axis_id;			//轴号
		double speed;			//速度倍率范围0~100(百分比)，单位:无
		double acceleration;	//加速度倍率范围0~100(百分比)，单位:无
		double deceleration;	//减速度倍率范围0~100(百分比)，单位:无
	};
	struct Cmd_Dout{

		short module;			//DO模块号，1-本地IO，2-扩展IO
		short port;				//端口号，-1代表整个DO模块,最多支持32位DO
		long value;	//设定值
	};
	struct Cmd_Din{

		short module;			//DO模块号，1-本地IO，2-扩展IO
		short port;				//端口号，-1代表整个DO模块,最多支持32位DO
		short output_var_type;	//输出变量的类型,0-布尔型变量B，1-整数型变量I
		short output_var_index;	//输出变量的索引
	};
	struct Cmd_PauseDecoder{

		short pause_decoder;
	};

#pragma pack(pop)



/*-------------后端接口-动态指令-----------------------*/


/**
 * @brief		使机器人系统进入动态指令流模式
 * @param[in]	<int group> 系统机器人组号
 * @note		机器人系统切换至回放-动态指令模式后，需要在启动前(手持盒绿灯亮起前)调用，
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:进入指令插入状态成功
 * @return		<other value>: 进入指令插入状态失败
 */
GTR_ADVANCED_EXPORT short GTR_EnterStreamMode(short channel = GtrCurrentChannel);


/**
 * @brief		重置机器人系统动态指令状态
 * @param[in]	<int group> 系统机器人组号
 *				将清空所有指令池中的指令
 * @return		<0>:重置状态成功
 * @return		<other value>: 重置状态成功失败
 */
GTR_ADVANCED_EXPORT short GTR_CancelMotion(bool clear_alarm,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令MOVJ
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddMovj(Gtr_Advanced::Cmd_Movj *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令MOVL
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddMovl(Gtr_Advanced::Cmd_Movl *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令MOVC
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddMovc(Gtr_Advanced::Cmd_Movc *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令USER
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddUser(Gtr_Advanced::Cmd_User *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令GETPOS
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddGetpos(Gtr_Advanced::Cmd_GetPos *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令COORD_NUM
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于可动态插入指令的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddCoordNum(Gtr_Advanced::Cmd_CoordNum *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令GETCAPTUREPOS
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddGetCapturePos(Gtr_Advanced::Cmd_GetCapturePos *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入空指令
 * @param[in]	<none>
 * @note		插入该指令后可立即启动运行指令池的指令
 *				调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddBlank(short channel = GtrCurrentChannel);


/**
 * @brief		插入指令MODAL
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddModal(Gtr_Advanced::Cmd_Modal *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令EXTJOINT
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddExtJoint(Gtr_Advanced::Cmd_ExtJoint *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令SPEED
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddSpeed(Gtr_Advanced::Cmd_Speed *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令DYN
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddDyn(Gtr_Advanced::Cmd_Dyn *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令SET
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddSet(Gtr_Advanced::Cmd_Set *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令UNTIL
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddUntil(Gtr_Advanced::Cmd_Until *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令WAIT
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddWait(Gtr_Advanced::Cmd_Wait *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令TIMER
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddTimer(Gtr_Advanced::Cmd_Timer *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令EXTJSPEED
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddExtjSpeed(Gtr_Advanced::Cmd_ExtjSpeed *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令DIN
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddDin(Gtr_Advanced::Cmd_Din *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令DOUT
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddDout(Gtr_Advanced::Cmd_Dout *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		插入指令PAUSE_DECODER
 * @param[in]	<none>
 * @note		调用前确定机器人系统处于指令插入的状态(调用short GTR_DYN_Start())
 *				否则机器人系统可能无法动态插入指令
 * @return		<0>:指令插入成功
 * @return		<other value>: 指令插入失败
 */
GTR_ADVANCED_EXPORT short GTR_AddPauseDecoder(short channel = GtrCurrentChannel);


/**
 * @brief		使机器人系统结束指令插入的状态，并执行指令
 * @param[in]	<int group> 系统机器人组号
 * @note		调用该接口后，若所有指令已执行完毕，则机器人系统将
 *				进入空闲状态（手持盒绿灯熄灭）并自动重新进入指令插入的状态
 * @return		<0>:结束指令插入状态成功
 * @return		<other value>: 结束指令插入状态失败
 */
GTR_ADVANCED_EXPORT short GTR_StartCmdMotion(short channel = GtrCurrentChannel);


/**
 * @brief		获取当前指令池中指令数量
 * @param[in]	<int group> 系统机器人组号
 * @note		指令池容量为4096条指令
 * @return		指令池当前指令指令数量
 */
GTR_ADVANCED_EXPORT short GTR_GetCmdCount(long &count,short channel = GtrCurrentChannel);


/**
 * @brief		清空当前指令池中所有指令
 * @param[in]	<int group> 系统机器人组号
 * @return		<0>:清空指令池成功
 * @return		<other value>: 清空指令池失败
 */
GTR_ADVANCED_EXPORT short GTR_ClearCmdPool(short channel = GtrCurrentChannel);


/**
 * @brief		判断当前指令池是否为空
 * @param[in]	<int group> 系统机器人组号
 *				将清空所有指令池中的指令
 * @return		<false>:指令池未空
 * @return		<true>: 指令池已空
 */
GTR_ADVANCED_EXPORT short GTR_IsCmdEmpty(bool &result,short channel = GtrCurrentChannel);


/**
 * @brief		判断当前指令池是否已满
 * @param[in]	<int group> 系统机器人组号
 *				将清空所有指令池中的指令
 * @return		<false>:指令池未满
 * @return		<true>: 指令池已满
 */
GTR_ADVANCED_EXPORT short GTR_IsCmdFull(bool &result,short channel = GtrCurrentChannel);

}

#endif