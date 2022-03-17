#ifndef GTROBOT_BACKEND_INTERFACE_H
#define GTROBOT_BACKEND_INTERFACE_H

#include <vector>
#include "gtrobot_backend_define.h"

#ifdef GTR_BACKEND_LIB
# define GTR_EXPORT __declspec(dllexport)
#else
# define GTR_EXPORT __declspec(dllimport)
#endif




/*-------------后端接口-系统初始化-----------------------*/


//机器人系统初始化状态
GTR_EXPORT short GTR_IsSystemInit(bool &result);

//初始化机器人系统
GTR_EXPORT short GTR_InitRobotSystem();

//退出机器人系统
GTR_EXPORT short GTR_ExitRobotSystem();



/*-------------后端接口-系统线程-----------------------*/


//NC线程Sleep时间
GTR_EXPORT short GTR_GetNcSleepTime(unsigned short &time);
GTR_EXPORT short GTR_SetNcSleepTime(const unsigned short &time);
//NC线程暂停与继续
GTR_EXPORT short GTR_PauseNcThread();
GTR_EXPORT short GTR_ContinueNcThread();


//PLC线程Sleep时间
GTR_EXPORT short GTR_GetPlcSleepTime(unsigned short &time);
GTR_EXPORT short GTR_SetPlcSleepTime(const unsigned short &time);
//PLC线程暂停与继续
GTR_EXPORT short GTR_PausePlcThread();
GTR_EXPORT short GTR_ContinuePlcThread();


//注册NC线程User指令回调函数
GTR_EXPORT short GTR_RegisterUserCom(const short &craft_type,Gtr::GtrUserCom func);
//注册NC线程LoopRun函数
GTR_EXPORT short GTR_RegisterUserRun(const short &index,Gtr::GtrUserRun func);
//注册PLC线程的周期回调函数（周期约8ms）
GTR_EXPORT short GTR_RegisterPlcLoop(const int &index,Gtr::GtrPlcLoop func);









/*-------------后端接口-系统状态-----------------------*/
//设置全局报警
GTR_EXPORT short GTR_IsSystemAlarm(bool &result);
//是否处于急停状态
GTR_EXPORT short GTR_IsSystemEstopAlarm(bool &result);
//系统是否处于警告状态
GTR_EXPORT short GTR_IsSystemWarning(bool &result);
//清除报警
GTR_EXPORT short GTR_ClearSystemAlarm();


//获取机器人驱动器报警信息
GTR_EXPORT short GTR_GetAbsEncoderAlarm(Gtr::DriverStatus &driver_status,const short &axis_id);
//清除驱动器报警-!!!将会使绝对编码器值为0
GTR_EXPORT short GTR_ClearAbsEncoderAlarm(const short &axis_id);
//松刹车
GTR_EXPORT short GTR_ClearAbsEncoderBrake(const short &axis_id);


//获取系统运行状态-不区分示教与回放模式
//0-空闲状态
//1-运行状态
//2-暂停状态
//原接口名称GTR_GetRobotRunningStatus 2021.05.16
GTR_EXPORT short GTR_GetSystemRunningStatus(Gtr::RUNNING_STATUS &status);


//获取系统运行模式(示教模式、回放模式、远程模式)
//原接口名称GTR_GetRobotRunningMode 2021.05.16
GTR_EXPORT short GTR_GetSystemRunningMode(Gtr::RUNNING_MODE &mode,short channel = GtrCurrentChannel);


//获取示教模式运行状态
GTR_EXPORT short GTR_GetTeachRunningStatus(Gtr::TEACH_STATUS &status,short channel = GtrCurrentChannel);


//获取回放模式运行状态
GTR_EXPORT short GTR_GetReplayRunningStatus(Gtr::RUNNING_STATUS &status,short channel = GtrCurrentChannel);


//获取远程模式运行状态
GTR_EXPORT short GTR_GetRemoteRunningStatus(Gtr::RUNNING_STATUS &status,short channel = GtrCurrentChannel);


//是否为恢复运行状态（回放模式从暂停中恢复运行）
GTR_EXPORT short GTR_IsReplayResumeStatus(bool &status,short channel = GtrCurrentChannel);


//读写驱动器电流
GTR_EXPORT short GTR_SetPrfTorque(short axis_index,short prfTorque);
GTR_EXPORT short GTR_GetAtlTorque(short axis_index,short &atlTorque);

//设置GSHD驱动器力矩限制率（千分率）的接口 2021.12.14
GTR_EXPORT short GTR_SetTorqueLimit(short axis_index, unsigned short torqueMax, unsigned short torquePostive, unsigned short torqueNegitive);
GTR_EXPORT short GTR_GetTorqueLimit(short axis_index, unsigned short &torqueMax, unsigned short &torquePostive, unsigned short &torqueNegitive);

//增加设置跟随误差的接口（posErrLmt单位：mm或°）2021.12.14
GTR_EXPORT short GTR_SetAxisPosErrLimit(short axis_index, double posErrLmt);
GTR_EXPORT short GTR_GetAxisPosErrLimit(short axis_index, double &posErrLmt);

//驱动器工作模式接口 2021.12.15
GTR_EXPORT short GTR_SetMotionMode(short axis_index,short motionMode);
GTR_EXPORT short GTR_GetMotionMode(short axis_index,short &motionMode);

//读写驱动器命令 2021-12-15
GTR_EXPORT short GTR_WriteDriverCmd(short axis_index,unsigned short cmd_index,unsigned short cmd_sub_index,double value);
GTR_EXPORT short GTR_ReadDriverCmd(unsigned short &cmd_index,unsigned short &cmd_sub_index);

//读取驱动器力矩系数 2021-12-15
GTR_EXPORT short GTR_ReadDriverTorqueConstant(short axis_index,double &value);
//读取驱动器额定电流 2021-12-16
GTR_EXPORT short GTR_ReadDriverRatedCurrent(short axis_index,double &value);
//读取驱动器峰值电流 2021-12-16
GTR_EXPORT short GTR_ReadDriverPeakCurrent(short axis_index,double &value);


/*-------------后端接口-IO及设备操作-----------------------*/


//屏蔽IO停止信号
GTR_EXPORT short GTR_IsDisableStopIo(bool &disable);
GTR_EXPORT short GTR_DisableStopIo(const bool &disable);
GTR_EXPORT short GTR_GetStopIoStatus(bool &status,const short &axis_id);


//获取DI状态
//type = 0,EHMI-DI（0~15位）
//type = 1,本地DI-1（0~15位）
//type = 2,本地DI-2（16~31位）
//type = 3,本地DI-3（32~47位）
//type = 4,扩展DI（0~15位）
GTR_EXPORT short GTR_GetDiValue(unsigned short &value,const short type);
GTR_EXPORT short GTR_GetDiBitValue(bool &value,const short type,const short bit);


//设置DO状态(按位写入)
//type = 0,EHMI-DO（0~15位）
//type = 1,本地DO-1（0~15位）
//type = 2,本地DO-2（16~31位）
//type = 3,本地DO-3（32~47位）
//type = 4,扩展DO（0~15位）
GTR_EXPORT short GTR_SetDoValue(const unsigned short value,const short type);
GTR_EXPORT short GTR_SetDoBitValue(const bool value,const short type,const short bit);


//设置DO状态
//type = 0,EHMI-DO（0~15位）
//type = 1,本地DO-1（0~15位）
//type = 2,本地DO-2（16~31位）
//type = 3,本地DO-3（32~47位）
//type = 4,扩展DO（0~15位）
GTR_EXPORT short GTR_GetDoValue(unsigned short &value,const short type);
GTR_EXPORT short GTR_GetDoBitValue(bool &value,const short type,const short bit);


//获取AI状态
//type = 0,本地AIO
//type = 1,扩展AIO
GTR_EXPORT short GTR_GetAiValue(double &value,const short index,short type = 0);
//获取AO状态
GTR_EXPORT short GTR_GetAoValue(double &value,const short index,short type = 0);
//设置AO状态
GTR_EXPORT short GTR_SetAoValue(const double value,const short index,short type = 0);


//手持盒按键（动作）：按下或松开
GTR_EXPORT short GTR_PressKey(const Gtr::Key &key); 
GTR_EXPORT short GTR_ReleaseKey(const Gtr::Key &key);


//手持盒按键（状态）：获取按下与松开状态
GTR_EXPORT short GTR_IsKeyPressed(bool &result,const Gtr::Key &key);
GTR_EXPORT short GTR_IsKeyReleased(bool &result,const Gtr::Key &key);


//急停按钮信号锁存(红色急停按钮)
GTR_EXPORT short GTR_LockEstopSignal(const bool &enable);

//设置无示教器模式使能状态
GTR_EXPORT short GTR_SetNoneTeachPendantMode(const bool &enable);
GTR_EXPORT short GTR_GetNoneTeachPendantMode(bool &enable);

//逻辑模式按钮(钥匙模式切换)
GTR_EXPORT short GTR_SetSystemMode(const Gtr::RUNNING_MODE &mode);








/*-------------后端接口-示教程序-----------------------*/

//设置示教模式示教程序启动行号，用于前进检查
GTR_EXPORT short GTR_SetTeachStartLine(const long &start_line,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetTeachStartLine(long &start_line,short channel = GtrCurrentChannel);


//设置示教模式下的启动程序，用于前进检查
GTR_EXPORT short GTR_SetTeachStartPrgFile(char *file_path,short start_line = 1,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetTeachStartPrgFile(char *file_path,short channel = GtrCurrentChannel);


//设置回放模式示教程序启动行号，用于回放运行
GTR_EXPORT short GTR_SetReplayStartLine(const long &start_line,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplayStartLine(long &start_line,short channel = GtrCurrentChannel);


//设置回放模式启动程序，用于回放运行
GTR_EXPORT short GTR_SetReplayStartPrgFile(char *file_path,short start_line = 1,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplayStartPrgFile(char *file_path,short channel = GtrCurrentChannel);


//获取回放模式下当前执行的示教程序类型 （0=主程序，1=子程序，2=注册指令）
GTR_EXPORT short GTR_GetReplayCurrentPrgType(short &prg_type,short channel = GtrCurrentChannel);


//获取回放模式下当前执行的示教文件（主程序）名称
GTR_EXPORT short GTR_GetReplayCurrentMainPrgName(char *prg_name,short channel = GtrCurrentChannel);


//获取回放模式下当前执行的示教文件名称
GTR_EXPORT short GTR_GetReplayCurrentPrgName(char *sub_prg_name,short channel = GtrCurrentChannel);


//获取回放模式下当前执行的示教文件(主程序)行号
GTR_EXPORT short GTR_GetReplayCurrentMainPrgLineNum(unsigned long &line_num,short channel = GtrCurrentChannel);


//获取回放模式下当前执行的示教文件行号
GTR_EXPORT short GTR_GetReplayCurrentPrgLineNum(unsigned long &line_num,short channel = GtrCurrentChannel);

//@brief		设置JOG模式是否为步进模式
//@param[in]	<line>步进模式：true，非步进模式：false
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_EXPORT short GTR_SetTeachJogMode(bool is_step,short channel);

//@brief		获取JOG模式是否为步进模式
//@param[out]	<line>步进模式：true，非步进模式：false
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_EXPORT short GTR_GetTeachJogMode(bool &is_step,short channel);





/*-------------后端接口-参数读写-----------------------*/


//获取group控制的轴数
GTR_EXPORT short GTR_GetChannelCtrlAxisNum(short &result,short channel = GtrCurrentChannel);


//获取指定group中控制的轴数
GTR_EXPORT short GTR_GetChannelRobotAxisNum(short &result,const short &index,short channel = GtrCurrentChannel);
 //获取指定group中控制的group下标
GTR_EXPORT short GTR_GetChannelRobotId(short &result,const short &index,short channel = GtrCurrentChannel);

//获取第一个group中控制的轴数
GTR_EXPORT short GTR_GetChannelFirstRobotAxisNum(short &result,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetChannelFirstRobotId(short &result,short channel = GtrCurrentChannel);


//获取第二个group中控制的轴数
GTR_EXPORT short GTR_GetChannelSecondRobotAxisNum(short &result,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetChannelSecondRobotId(short &result,short channel = GtrCurrentChannel);


//获取指定通道中外部轴的轴数
GTR_EXPORT short GTR_GetChannelExtAxisNum(short &result,short channel = GtrCurrentChannel);
//获取指定通道中龙门从轴的轴数
GTR_EXPORT short GTR_GetChannelGantryAxisNum(short &result,short channel = GtrCurrentChannel);


//轴配置参数
GTR_EXPORT short GTR_SetAxisConfig(const Gtr::AxisConfig &config,const short &axis_id);
GTR_EXPORT short GTR_GetAxisConfig(Gtr::AxisConfig &config,const short &axis_id);


//组配置参数-从1开始
GTR_EXPORT short GTR_SetGroupConfig(const Gtr::GroupConfig &config,const short &group_id);
GTR_EXPORT short GTR_GetGroupConfig(Gtr::GroupConfig &config,const short &group_id);


//控制器参数
GTR_EXPORT short GTR_SetControllerConfig(const Gtr::SysCtlParam &config);
GTR_EXPORT short GTR_GetControllerConfig(Gtr::SysCtlParam &config);


//通道控制参数
GTR_EXPORT short GTR_SetChannelConfig(const Gtr::SysChannelCtrlParam &config,short channel);
GTR_EXPORT short GTR_GetChannelConfig(Gtr::SysChannelCtrlParam &config,short channel);


//零位标定参数
GTR_EXPORT short GTR_SetZeroCaliPosition(const long &abs_pos,const short &axis_id);
GTR_EXPORT short GTR_GetZeroCaliPosition(long &abs_pos,const short &axis_id);


//快捷回零点
GTR_EXPORT short GTR_SetZeroPosConfig(const Gtr::Point &value,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetZeroPosConfig(Gtr::Point &value,short channel = GtrCurrentChannel);


//坐标系管理参数
GTR_EXPORT short GTR_SetCoordinateConfig(const Gtr::CoordSystem &config,const Gtr::TYPE_COORD &type,const short &index,short group = GtrCurrentGroup);
GTR_EXPORT short GTR_GetCoordinateConfig(Gtr::CoordSystem &config,const Gtr::TYPE_COORD &type,const short &index,short group = GtrCurrentGroup);


//【通讯】-TCP指令配置
GTR_EXPORT short GTR_SetTcpServerInfo(const Gtr::TcpServerConfig &config);
GTR_EXPORT short GTR_GetTcpServerInfo(Gtr::TcpServerConfig &config);

//【通讯】-Modbus服务端配置
GTR_EXPORT short GTR_SetModbusServerInfo(const Gtr::ModbusServerConfig &config);
GTR_EXPORT short GTR_GetModbusServerInfo(Gtr::ModbusServerConfig &config);

//【通讯】-Modbus客户端配置
GTR_EXPORT short GTR_SetModbusClientInfo(const Gtr::ModbusClientConfig &config);
GTR_EXPORT short GTR_GetModbusClientInfo(Gtr::ModbusClientConfig &config);


//变位机标定参数
//TYPE = 0: ECS1标定参数
//TYPE = 1：ECS2标定参数
//TYPE = 2：ECS3标定参数
GTR_EXPORT short GTR_SetPositionerConfig(double param[6],const short &type,bool reset_sys,short group,short channel = 0);
GTR_EXPORT short GTR_GetPositionerConfig(double param[6],const short &type,short group,short channel = 0);


//地轨标定参数
//TYPE = 0: GCS1标定参数
//TYPE = 1：GCS2标定参数
GTR_EXPORT short GTR_SetGroundRailConfig(double param[6],const short &type,bool reset_sys,short group,short channel = 0);
GTR_EXPORT short GTR_GetGroundRailConfig(double param[6],const short &type,short group,short channel = 0);





/*-------------后端接口-全局变量读写-----------------------*/


//全局变量-布尔型变量
GTR_EXPORT short GTR_SetVarB(const bool &value,const short &index);
GTR_EXPORT short GTR_GetVarB(bool &value,const short &index);
GTR_EXPORT short GTR_SetVarBUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarB(bool &result,const short &index);


//全局变量-整数型变量
GTR_EXPORT short GTR_SetVarI(const long &result,const short &index);
GTR_EXPORT short GTR_GetVarI(long &value,const short &index);
GTR_EXPORT short GTR_SetVarIUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarI(bool &result,const short &index);


//全局变量-实数型变量
GTR_EXPORT short GTR_SetVarR(const double &result,const short &index);
GTR_EXPORT short GTR_GetVarR(double &value,const short &index);
GTR_EXPORT short GTR_SetVarRUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarR(bool &result,const short &index);


//全局变量-字符型变量
GTR_EXPORT short GTR_SetVarSTR(char *result,const short &index);
GTR_EXPORT short GTR_GetVarSTR(char *result,const short &index);
GTR_EXPORT short GTR_SetVarSTRUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarSTR(bool &result,const short &index);


//全局变量-位置型变量
GTR_EXPORT short GTR_SetVarP(const Gtr::Point &result,const short &index);
GTR_EXPORT short GTR_GetVarP(Gtr::Point &value,const short &index);
GTR_EXPORT short GTR_SetVarPUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarP(bool &result,const short &index);


//系统内部变量
// index 范围： 9000~9019
GTR_EXPORT short GTR_SetInternalVarB(const bool &value,const short &index); 
// index 范围： 9000~9019
GTR_EXPORT short GTR_SetInternalVarI(const long &value,const short &index); 
// index 范围： 9000~9019
GTR_EXPORT short GTR_SetInternalVarR(const double &value,const short &index); 

//系统内部变量批量读取，从第1个内部变量开始读取
GTR_EXPORT short GTR_SetInternalVarBEx(bool *value,const short &count); 
GTR_EXPORT short GTR_SetInternalVarIEx(long *value,const short &count); 
GTR_EXPORT short GTR_SetInternalVarREx(double *value,const short &count); 

// index 范围： 9000~9019
GTR_EXPORT short GTR_GetInternalVarBEx(bool *value,const short &count); 
// index 范围： 9000~9019
GTR_EXPORT short GTR_GetInternalVarIEx(long *value,const short &count); 
// index 范围： 9000~9019
GTR_EXPORT short GTR_GetInternalVarREx(double *value,const short &count);



/*-------------后端接口-机器人运动-----------------------*/


//设置系统当前通道类型
GTR_EXPORT short GTR_GetCurrentChannel(short &channel);
GTR_EXPORT short GTR_SetCurrentChannel(const short &channel);


//设置系统当前Group类型
GTR_EXPORT short GTR_GetCurrentGroup(short &group);
GTR_EXPORT short GTR_SetCurrentGroup(const short &group,short channel = GtrCurrentChannel);


//各机器人组伺服状态
GTR_EXPORT short GTR_IsChannelServoOn(bool &status,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_IsChannelServoOff(bool &status,short channel = GtrCurrentChannel);


//停止机器人所有运动,如示教模式下的前进检查，回放运行示教程序等
GTR_EXPORT short GTR_StopMotion(short channel = GtrCurrentChannel);


//机器人上下伺服
GTR_EXPORT short GTR_RobotTeachServoOn(short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_RobotTeachServoOff(short channel = GtrCurrentChannel);


//切换坐标系类型
GTR_EXPORT short GTR_SetTeachCoordType(const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup);
GTR_EXPORT short GTR_GetTeachCoordType(Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup);


//切换坐标系ID号，只支持TCS、PCS(工具坐标系、工件坐标系)
GTR_EXPORT short GTR_SetTeachCoordId(const Gtr::TYPE_COORD &coord_type,const short &coord_id,short group = GtrCurrentGroup);
GTR_EXPORT short GTR_GetTeachCoordId(short &coord_id,const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup);


//轴Jog运动
// axis_type = 0-手持盒X方向
// axis_type = 1-手持盒Y方向
// axis_type = 2-手持盒Z方向
// axis_type = 3-手持盒RX方向
// axis_type = 4-手持盒RY方向
// axis_type = 5-手持盒RZ方向
// axis_type = 6-手持盒E1方向
// axis_type = 7-手持盒E2方向
//dir=true正方向运动，dir=false负方向运动
GTR_EXPORT short GTR_StartTeachMoveJog(const Gtr::Key &key_type,bool refresh_abs = false);
GTR_EXPORT short GTR_StopTeachMoveJog(const Gtr::Key &key_type);


//运动到点
GTR_EXPORT short GTR_StartTeachMoveToPoint(const short &point_id,short channel = GtrCurrentChannel,const bool is_need_forward_check = true);
GTR_EXPORT short GTR_StopTeachMoveToPoint();
GTR_EXPORT short GTR_GetTeachMoveToPointStatus(bool &status);


//全局速度倍率-示教模式
GTR_EXPORT short GTR_SetTeachSpeedOverride(const double &speedOverride,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetTeachSpeedOverride(double &speedOverride,short channel = GtrCurrentChannel);

//全局速度倍率-运动到点、前进检查、快捷回零点 2021.06.26
GTR_EXPORT short GTR_SetMoveToSpeedOverride(const double &speedOverride,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetMoveToSpeedOverride(double &speedOverride,short channel = GtrCurrentChannel);


//回放模式机器人上伺服
GTR_EXPORT short GTR_RobotReplayServoOn(short channel = GtrCurrentChannel);
//回放模式机器人下伺服
GTR_EXPORT short GTR_RobotReplayServoOff(short channel = GtrCurrentChannel);


//设置当前回放模式下的运行模式
//-1 不处于回放模式
//0-单次循环 
//1-无限循环 
//2-单步运行 
//3-动态指令
GTR_EXPORT short GTR_SetReplayRunningMode(const short &mode,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplayRunningMode(short &mode,short channel = GtrCurrentChannel);


//全局速度倍率-回放模式
GTR_EXPORT short GTR_SetReplaySpeedOverride(const double &speedOverride,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplaySpeedOverride(double &speedOverride,short channel = GtrCurrentChannel);


//开始运行示教程序
GTR_EXPORT short GTR_StartReplayRun(short channel = GtrCurrentChannel);
//暂停运行示教程序
GTR_EXPORT short GTR_PauseReplayRun(short channel = GtrCurrentChannel);




//HMIAXIS独立上伺服
GTR_EXPORT short GTR_HmiAxisServoOn(const short &axis_id);
//HMIAXIS独立下伺服
GTR_EXPORT short GTR_HmiAxisServoOff(const short &axis_id);


//读写HMIAXIS速度
GTR_EXPORT short GTR_SetHmiAxisVelocity(const short &axis_id,const double &vel);
GTR_EXPORT short GTR_GetHmiAxisVelocity(const short &axis_id,double &vel);

//读写HMIAXIS加速度
GTR_EXPORT short GTR_SetHmiAxisAcceleration(const short &axis_id,const double &acc);
GTR_EXPORT short GTR_GetHmiAxisAcceleration(const short &axis_id,double &acc);

//读写HMIAXIS减速度
GTR_EXPORT short GTR_SetHmiAxisDeceleration(const short &axis_id,const double &dec);
GTR_EXPORT short GTR_GetHmiAxisDeceleration(const short &axis_id,double &dec);

//HMIAXIS开始运动
GTR_EXPORT short GTR_HmiAxisStart(const short &axis_id);

//HMIAXIS停止运动
GTR_EXPORT short GTR_HmiAxisStop(const short &axis_id);


//机器人各坐标系下合成速度 
GTR_EXPORT short GTR_GetProfileSyntheticVelocity(double &vel,const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);
//机器人各坐标系下合成速度(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetProfileSyntheticVelocity(double &vel,const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);


//机器人各坐标系下规划速度
GTR_EXPORT short GTR_GetProfileVelocity(double vel_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);
//机器人各坐标系下规划速度(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetProfileVelocity(double vel_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);


//机器人各坐标系下规划位置
GTR_EXPORT short GTR_GetProfilePosition(double pos_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);
//机器人各坐标系下规划位置(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetProfilePosition(double pos_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);


//机器人各轴的规划速度
GTR_EXPORT short GTR_GetAxisProfileVelocity(double &vel,const short &axis_id);
//机器人各轴的规划速度(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetAxisProfileVelocity(double &vel,const short &axis_id);


//机器人各轴的规划位置
GTR_EXPORT short GTR_GetAxisProfilePosition(double &pos,const short &axis_id);
//机器人各轴的规划位置(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetAxisProfilePosition(double &pos,const short &axis_id);


//机器人各轴的规划加速度
GTR_EXPORT short GTR_GetAxisProfileAcceleration(double &acc,const short &axis_id);
//机器人各轴的规划加速度(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetAxisProfileAcceleration(double &acc,const short &axis_id);


//机器人编码器速度
GTR_EXPORT short GTR_GetEncoderVelocity(double &vel,const short &axis_id);
//机器人编码器速度(高速接口)
GTR_EXPORT short GTR_RT_GetEncoderVelocity(double &vel,const short &axis_id);

//机器人编码器位置
GTR_EXPORT short GTR_GetEncoderPosition(double &pos,const short &axis_id);
//机器人编码器位置(高速接口)
GTR_EXPORT short GTR_RT_GetEncoderPosition(double &pos,const short &axis_id);

//机器人编码器跟随误差
GTR_EXPORT short GTR_GetEncoderFollowError(double &err,const short &axis_id);


//辅助编码器速度,index>=1
GTR_EXPORT short GTR_GetAuEncoderVelocity(double &vel, const short &index);
//辅助编码器速度(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetAuEncoderVelocity(double &vel, const short &index);
//辅助编码器位置,index>=1
GTR_EXPORT short GTR_GetAuEncoderPosition(double &pos, const short &index);
//辅助编码器位置(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetAuEncoderPosition(double &pos, const short &index);


//机器人轴状态信息
GTR_EXPORT short GTR_GetAxisStatus(Gtr::AxisStatus &status,const short &axis_id);


//机器人各坐标系下规划位置读取至位置型变量
GTR_EXPORT short GTR_GetCurrentVarP(Gtr::Point &value,const Gtr::TYPE_COORD coord_type[2],short channel = GtrCurrentChannel);
//机器人各坐标系下规划位置至位置型变量(高速接口Real-time）
GTR_EXPORT short GTR_RT_GetCurrentVarP(Gtr::Point &value,const Gtr::TYPE_COORD coord_type[2],short channel = GtrCurrentChannel);


//焊接摆弧相关接口	2021.06.06
GTR_EXPORT short GTR_SetGroupWeaveParameter(const Gtr::GroupWeavePrm &para,short group);
GTR_EXPORT short GTR_GetGroupWeaveParameter(Gtr::GroupWeavePrm &para,short group);
//焊接运动叠加相关接口  20210606
GTR_EXPORT short GTR_SetGroupSuperposition(const Gtr::GroupSuperpositionPrm &para,const short &coordSystem,const short &index,short group);
GTR_EXPORT short GTR_GetGroupSuperposition(Gtr::GroupSuperpositionPrm &para,const short &coordSystem,const short &index,short group);


//获取Group的叠加功能参数 2021.06.29
GTR_EXPORT short GTR_GetGroupSuperpositionValue(const short &group,const short &coordSystem,const short &index,double value[8]);




//相对偏移接口，不可与叠加指令混用，（20211021定义）
//支持的坐标系有：
//10:	MVCS 运动坐标系

/**
* @brief		开启偏移
* @param[in]	<const & double> smooth_time 平滑时间 0~255
* @param[in]	<const short &>coordSystem 偏移的坐标系类型,现仅支持10（运动坐标系）
* @param[in]	<short>group 机器人组号，0~2
* @param[out]	无 
* @note			仅支持同时开启1个坐标系类型的偏移	
*	支持的坐标系类型:10:	MVCS 运动坐标系
*/
GTR_EXPORT short GTR_SetOffsetOn(const double & smooth_time,const short &coordSystem,short group = GtrCurrentGroup);

/**
* @brief		关闭偏移
* @param[in]	<short>group 机器人组号，0~2
* @param[out]	无 
* @note			仅在机器人组无运动时可调用
*/
GTR_EXPORT short GTR_SetOffsetOff(short group = GtrCurrentGroup);

/**
* @brief		设置相对偏移量
* @param[in]	<short>group 机器人组号，0~2
* @param[out]	无 
* @note			仅在机器人组运动时可调用
*/
GTR_EXPORT short GTR_SetOffsetRelativeValue(double relativeValue[8],short group = GtrCurrentGroup);

/**
* @brief		获取偏移状态
* @param[in]	<short>group 机器人组号，0~2
* @param[out]	<bool &>is_on 偏移功能是否打开
* @param[out]	<double &>smooth_time 当前生效的平滑时间，若未打开则输出无效
* @param[out]	<double &>coordSystem 当前生效的坐标系，若未打开则输出无效
* @note			
*/
GTR_EXPORT short GTR_GetOffsetStatus(bool & is_on, double & smooth_time,short &coordSystem,short group = GtrCurrentGroup);

/**
* @brief		 获取偏移值（待优化）
* @param[in]	<short>group  机器人组号，0~2
* @param[in]	<coord>coordSystem 读取目标坐标系的偏移值  
* @param[out]	<double offset_value[8]当前偏移值
* @note			
*/
GTR_EXPORT short GTR_GetOffsetValue(double offset_value[8],short &coordSystem,short group = GtrCurrentGroup);



/************************************************************************/
/*							报警模块 									*/
/************************************************************************/

//【报警】-添加报警信息
GTR_EXPORT short GTR_PushAlarmInfo(const long &id, long param1 = 0, long param2 = 0, long param3 = 0);
//【报警】-添加自定义内容报警信息 
GTR_EXPORT short GTR_PushAlarmUserInfo(char *info,const long &id);
//【报警】-获取报警信息，并从列表中移除报警信息
GTR_EXPORT short GTR_PopAlarmInfo(char *info, long &info_size, long &id);
//【报警】-获取报警信息
GTR_EXPORT short GTR_GetAlarmInfo(char *info, long &info_size,long &id,const long &index);
//【报警】-获取报警信息数量
GTR_EXPORT short GTR_GetAlarmInfoCount(long &count);
//【报警】-清除指定报警信息 
GTR_EXPORT short GTR_ClearAlarmInfo(const long &id);
//【报警】-清除所有报警信息
GTR_EXPORT short GTR_ClearAllAlarmInfo();


//【报警】-读取报警数据库记录
GTR_EXPORT short GTR_ReadAlarmInfoItem(Gtr::LogItem &item,const long &index);
//【报警】-批量读取报警数据库记录
GTR_EXPORT short GTR_ReadAlarmInfoItems(std::vector<Gtr::LogItem> &items,const long &start_index,const long &end_index);

//【报警】-添加数据库记录至数据库缓存
GTR_EXPORT short GTR_AddAlarmInfoItem(char *id, char *info,const Gtr::LOG_TYPE &type, bool repeatable = true, bool auto_commit = false);

//【报警】-获取报警数据库记录数
GTR_EXPORT short GTR_GetAlarmInfoItemsCount(long &count);

//【报警】-删除指定下标报警数据库记录 
GTR_EXPORT short GTR_DeleteAlarmInfoItem(const long &index);
//【报警】-删除所有报警数据库记录 
GTR_EXPORT short GTR_DeleteAllAlarmInfoItems();







/************************************************************************/
/*							日志模块									*/
/************************************************************************/

//【日志】-日志等级，小于设置的日志等级则不加入日志缓存 
GTR_EXPORT short GTR_GetLogLevel(Gtr::LOG_TYPE &level);
GTR_EXPORT short GTR_SetLogLevel(const Gtr::LOG_TYPE &level);

//【日志】-自动提交至数据库的缓存记录数，缓存记录数量大于自动提交的数量则自动提交至数据库 
GTR_EXPORT short GTR_GetAutoCommitLogCount(long &count);
GTR_EXPORT short GTR_SetAutoCommitLogCount(const long &count);

//【日志】-批量读取数据库记录（兼容早期版本）
GTR_EXPORT short GTR_ReadLogItems(std::vector<Gtr::GT_LogItem> &list, int count = 0);			//兼容早期版本
GTR_EXPORT short GTR_ReadLogItems(std::vector<Gtr::GT_LogItem> &list,const int &start_index,const int &lenth);	//兼容早期版本

//【日志】-读取数据库记录 
GTR_EXPORT short GTR_ReadLogItem(Gtr::LogItem &item,const long &index);
//【日志】-批量读取数据库记录 
GTR_EXPORT short GTR_ReadLogItems(std::vector<Gtr::LogItem> &items,const long &start_index,const long &end_index);

//【日志】-添加数据库记录至数据库缓存 
GTR_EXPORT short GTR_AddLogItem(char *info,const Gtr::LOG_TYPE &type, bool repeatable = true, bool auto_commit = false);

//【日志】-获取数据库记录数
GTR_EXPORT short GTR_GetLogItemsCount(long &count);

//【日志】-删除指定下标数据库记录 
GTR_EXPORT short GTR_DeleteLogItem(const long &index);
//【日志】-删除所有数据库记录
GTR_EXPORT short GTR_DeleteAllLogItems();


#endif