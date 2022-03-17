#ifndef GTROBOT_BACKEND_INTERNAL_H
#define GTROBOT_BACKEND_INTERNAL_H

#include <QString>
#include <QMap>
#include <vector>
#include "gtrobot_backend_define.h"


#ifdef GTR_BACKEND_LIB
#define GTR_INTERNAL_EXPORT extern "C" __declspec(dllexport)
//#define GTR_INTERNAL_EXPORT __declspec(dllexport)
#else
#define GTR_INTERNAL_EXPORT extern "C" __declspec(dllimport)
//#define GTR_INTERNAL_EXPORT __declspec(dllimport)
#endif


namespace gtr_internal{

	//主菜单类型
	enum MENU_TYPE
	{
		PROGRAM = 0,
		VARIABLE,
		CRAFT,
		STATUS,
		LOG,
		SETTING,
		SYSTEM,
		APPLICATION
	};

	//用户权限
	enum USER_TYPE
	{
		OPERATOR = 0,
		MANAGER,
		FACTORY
	};

	//原枚举名称 Axis_Type 2021.05.16
	enum AXIS_TYPE{

		FIRST_ROBOT,			//机器人1
		SECOND_ROBOT,			//机器人2
		EXT_AXIS,				//外部轴
		NONE
	};


	//原枚举名称 Firmware_Type 2021.05.16
	enum FIRMWARE_TYPE{

		ARM = 1,			//ARM固件
		FPGA = 2			//FPGA固件
	};

	//主菜单管理
	struct MyMenuItem
	{
		QString class_name;
		QString menu_name;
		bool visiable;
	};


	//插件信息
	struct ApplicationInfo
	{
		QString name;
		QString dllName;
		bool menuVis;
		bool launch;
		QString icon_menu;
		QString icon_common;
		QString icon_craft;
	};

	//示教程序信息
	struct RobProgramInfo 
	{
		char directory[256];
		char name[256];
	};

	struct CraftPipeParam
	{
		short craft_id;			
		long  long_param[4];
		double double_param[4];
	};


	struct WatchInfo
	{
		short enable;						// WATCH使能 
		short run;							// WATCH状态
		unsigned long time;					// WATCH次数
		unsigned long head;					// WATCH头指针

		unsigned long threshold;			// 最多容纳采集次数
		short interval;						// 采集间隔
		short mode;							// 采集模式

		unsigned short count_before_event;	// 事件触发之前的采集数量
		unsigned short count_after_event;	// 事件触发以后的采集数量
		unsigned short var_count;			// 采集变量数目
		unsigned short event_count;			// 采集事件数量
	};


	//(PCS/TCS)笛卡尔坐标系变换参数
	struct CartesianTransPrm
	{
		double transX;		//X轴偏移量。单位：mm。
		double transY;		//Y轴偏移量。单位：mm。
		double transZ;		//Z轴偏移量。单位：mm。
		double rotAngle1;	//旋转角度1。单位：度。
		double rotAngle2;	//旋转角度2。单位：度。
		double rotAngle3;	//旋转角度3。单位：度。
	};


	typedef short (*CraftPipeCallBack)(const CraftPipeParam &param,void *,void *);

}



//获取库编译时间
GTR_INTERNAL_EXPORT short GTR_GetCompileDate(char time[256]);
//获取主版本信息
GTR_INTERNAL_EXPORT short GTR_GetVersion(char version[100]);

//获取固件版本信息
GTR_INTERNAL_EXPORT short GTR_GetFirmwareVersion(char version[20], gtr_internal::FIRMWARE_TYPE type);

/**
* @brief		指令调试信息使能开关
* @param[in]	none
* @note		当开启时，函数调用都会在控制台上打印出函数名称
*				默认关闭改功能
*/
GTR_INTERNAL_EXPORT short GTR_DebugInfoEnable(const bool enable);



//获取DSP规划周期 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetDspProfileTime(short core,unsigned long &time,unsigned long &timeMax);

//获取系统可用内存(单位: byte) 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetAvailablePhysicalMemory(unsigned long &mem);

//获取系统可用内存占用率 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetAvailablePhysicalMemoryRate(unsigned long &rate);

//获取CPU占用率 2021.06.25
GTR_INTERNAL_EXPORT short GTR_GetCpuUseRate(unsigned long &rate);

//获取NC线程的单次执行周期 2021.07.26
GTR_INTERNAL_EXPORT short GTR_GetNcPeriodTime(unsigned long &time);
//获取NC线程的循环周期 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetNcCycleTime(unsigned long &time);

//获取PLC线程的单次执行周期 2021.07.26
GTR_INTERNAL_EXPORT short GTR_GetPlcPeriodTime(unsigned long &time);
//获取PLC线程的循环周期 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetPlcCycleTime(unsigned long &time);


//获取掉电保护信号 2021.07.26
GTR_INTERNAL_EXPORT short GTR_GetPowerStatus(long &status);


//示教模式-前进检查运动到位状态 2021.06.26
GTR_INTERNAL_EXPORT short GTR_IsForwardCheckFinished(bool &status,short channel);


//开启轴仿真模式 2021.06.30
GTR_INTERNAL_EXPORT short GTR_SetAxisSimulation(bool status,short axis_id);
GTR_INTERNAL_EXPORT short GTR_IsAxisSimulation(bool &status,short axis_id);

//开启轴软限位 2021.06.30
GTR_INTERNAL_EXPORT short GTR_SetAxisSoftLimitEnable(bool enable,short axis_id);
GTR_INTERNAL_EXPORT short GTR_IsAxisSoftLimitEnable(bool &enable,short axis_id);


//工艺交互回调函数
GTR_INTERNAL_EXPORT short GTR_RegisterCraftPipeCallback(short craft_type, gtr_internal::CraftPipeCallBack func);
//多工艺交互函数调用
GTR_INTERNAL_EXPORT short GTR_CallCraftPipeFunc(short craft_type, const gtr_internal::CraftPipeParam &param, void *input, void *output);


//设置工艺状态
GTR_INTERNAL_EXPORT short GTR_SetCraftStatus(const short &status, short channel = GtrCurrentChannel);
GTR_INTERNAL_EXPORT short GTR_GetCraftStatus(short &status, short channel = GtrCurrentChannel);


//设置工艺速度---!!!加指令类型!!!
GTR_INTERNAL_EXPORT short GTR_SetCraftSpeed(const double &speed, short channel = GtrCurrentChannel);
GTR_INTERNAL_EXPORT short GTR_GetCraftSpeed(double &speed, short channel = GtrCurrentChannel);



//机器人+变位机联动开关 2021.07.03
GTR_INTERNAL_EXPORT short GTR_SetGroupDynamicCoordinateParameter(short channel,bool enable);


//设置轴滤波参数 2021.09.01
GTR_INTERNAL_EXPORT short GTR_SetAxisMotionSmooth(const double &time,const double &pk,const unsigned short &axis_index);
GTR_INTERNAL_EXPORT short GTR_GetAxisMotionSmooth(double &time, double &pk,const unsigned short &axis_index);



/************************************************************************/
/*						文件管理模块 2021.09.15                         */
/************************************************************************/

//机器人系统全局变量-布尔型变量配置文件保存 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarBFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarBToFile();

//机器人系统全局变量-整数型变量配置文件保存 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarIFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarIToFile();

//机器人系统全局变量-实数型变量配置文件保存 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarRFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarRToFile();

//机器人系统全局变量-字符型变量配置文件保存 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarSTRFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarSTRToFile();

//机器人系统全局变量-位置型变量配置文件保存 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarPFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarPToFile();



/************************************************************************/
/*						权限模块 2021.03.25                             */
/************************************************************************/

//【权限】-系统权限相关2021.03.25
GTR_INTERNAL_EXPORT short  GTR_SetSysPermission(const unsigned short &level);
GTR_INTERNAL_EXPORT short  GTR_GetSysPermission(unsigned short &level);

//【权限】-设置用户权限2021.04.14
GTR_INTERNAL_EXPORT short  GTR_SetUserType(const gtr_internal::USER_TYPE &user_type);
GTR_INTERNAL_EXPORT short  GTR_GetUserType(gtr_internal::USER_TYPE &user_type);

//【权限】-设置用户权限2021.04.14
GTR_INTERNAL_EXPORT short  GTR_GetUserTypeStr(QString &user_type_str);

//【权限】-设置用户权限2021.04.14
GTR_INTERNAL_EXPORT short  GTR_SetUserPwdStr(const QString &user_pwd_str,const gtr_internal::USER_TYPE &user_type);
GTR_INTERNAL_EXPORT short  GTR_GetUserPwdStr(QString &user_pwd_str,const gtr_internal::USER_TYPE &user_type);

//【权限】-设置用户权限2021.04.14
GTR_INTERNAL_EXPORT short GTR_GetMenuPermission(const gtr_internal::MENU_TYPE &menu_type, QList<gtr_internal::MyMenuItem>& permission);

//【权限】-读取插件信息2021.04.14
GTR_INTERNAL_EXPORT short GTR_ReadAppInfoList(const gtr_internal::USER_TYPE &user_type, QMap<short, gtr_internal::ApplicationInfo> &info_map);




/************************************************************************/
/*							通讯模块				                    */
/************************************************************************/

//【通讯】-外部启动,是否开启预约状态
GTR_INTERNAL_EXPORT short GTR_SetRemoteReserveStatus(bool status, short channel = GtrCurrentChannel);
//【通讯】-外部启动,获取预约状态
GTR_INTERNAL_EXPORT short GTR_GetRemoteReserveStatus(bool &status, short channel = GtrCurrentChannel);

//【通讯】-外部启动,是否开启重复预约
GTR_INTERNAL_EXPORT short GTR_SetRemoteRepeatReserveStatus(bool status, short channel = GtrCurrentChannel);
//【通讯】-外部启动,获取重复预约
GTR_INTERNAL_EXPORT short GTR_GetRemoteRepeatReserveStatus(bool &status, short channel = GtrCurrentChannel);

//【通讯】-外部启动,设置预约程序列表
GTR_INTERNAL_EXPORT short GTR_SetProgramConfigList(gtr_internal::RobProgramInfo *info, int len, short channel = GtrCurrentChannel);
//【通讯】-外部启动,获取预约程序列表
GTR_INTERNAL_EXPORT short GTR_GetProgramOrderList(std::vector<gtr_internal::RobProgramInfo> &info_vector, short channel = GtrCurrentChannel);
//【通讯】-外部启动,清除预约程序列表
GTR_INTERNAL_EXPORT short GTR_ClearProgramOrderList(short channel = GtrCurrentChannel);


//【通讯】-TCP指令配置
GTR_INTERNAL_EXPORT short GTR_SetTcpServerConfig(const Gtr::TcpServerConfig config);
GTR_INTERNAL_EXPORT short GTR_GetTcpServerConfig(Gtr::TcpServerConfig &config);
GTR_INTERNAL_EXPORT short GTR_GetTcpServerConnectListList(std::vector<Gtr::TcpConnectClientInfo> &list);
GTR_INTERNAL_EXPORT short GTR_GetModbusTcpClientConnectStatus(bool &status);

//【通讯】-Modbus服务端配置
GTR_INTERNAL_EXPORT short GTR_SetModbusServerConfig(const Gtr::ModbusServerConfig config);
GTR_INTERNAL_EXPORT short GTR_GetModbusServerConfig(Gtr::ModbusServerConfig &config);
GTR_INTERNAL_EXPORT short GTR_GetModbusTcpServerConnectList(std::vector<Gtr::TcpConnectClientInfo> &list);

//【通讯】-Modbus客户端配置
GTR_INTERNAL_EXPORT short GTR_SetModbusClientConfig(const Gtr::ModbusClientConfig config);
GTR_INTERNAL_EXPORT short GTR_GetModbusClientConfig(Gtr::ModbusClientConfig &config);





/************************************************************************/
/*						WATCH模块 2021.05.24                            */
/************************************************************************/
GTR_INTERNAL_EXPORT short GTR_GetcontrollerWatchInfo(short core,gtr_internal::WatchInfo &info);
GTR_INTERNAL_EXPORT short GTR_ControllerWatchOn(short core,char* path);
GTR_INTERNAL_EXPORT short GTR_ControllerWatchOffAndPrint(short core,char* path);



//PCS、TCS偏移接口 2021.06.01
GTR_INTERNAL_EXPORT short GTR_SetGroupCartesianTransform(short group, Gtr::TYPE_COORD coordSystem,gtr_internal::CartesianTransPrm para);
GTR_INTERNAL_EXPORT short GTR_GetGroupCartesianTransform(short group, Gtr::TYPE_COORD coordSystem,gtr_internal::CartesianTransPrm &para);




/************************************************************************/
/*						JOG控制模块 2021.06.12                          */
/************************************************************************/

//切换至下一组机器人JOG控制 2021.06.12
GTR_INTERNAL_EXPORT short GTR_NextRobotJogControlMap(short channel);
//切换至上一组机器人JOG控制 2021.06.12
GTR_INTERNAL_EXPORT short GTR_PreviousRobotJogControlMap(short channel);

//切换至下一组外部轴JOG控制 2021.06.12
GTR_INTERNAL_EXPORT short GTR_NextExtJointJogControlMap(short channel);
//切换至上一组外部轴JOG控制 2021.06.12
GTR_INTERNAL_EXPORT short GTR_PreviousExtJointJogControlMap(short channel);

//切换至机器人JOG控制 2021.06.12
GTR_INTERNAL_EXPORT short GTR_ChangeToRobotMode(short channel);
//切换至外部轴JOG控制 2021.06.12
GTR_INTERNAL_EXPORT short GTR_ChangeToExtJointMode(short channel);

//切换至机器人-双轴变位机JOG控制
GTR_INTERNAL_EXPORT short GTR_ChangeToRobotPositionerMode(short group,short channel);
//切换至机器人-双外部轴JOG控制
GTR_INTERNAL_EXPORT short GTR_ChangeToTwoExtJointControlMode(short channel);



/************************************************************************/
/*						日志模块(内部接口) 2021.07.26                   */
/************************************************************************/

//将日志缓存提交至数据库(写文件) 2021.07.26
GTR_INTERNAL_EXPORT short GTR_CommitToLogDataBase();




/************************************************************************/
/*						报警模块(内部接口) 2021.07.26                   */
/************************************************************************/

//将日志缓存提交至数据库(写文件) 2021.07.26
GTR_INTERNAL_EXPORT short GTR_CommitToAlarmDataBase();



/************************************************************************/
/*							通信模块									*/
/************************************************************************/

/**
* @brief		添加TCP客户端连接，返回客户端句柄。用户级函数接口
* @param[in] 	<STcpServerInfo *info_>远端IP地址和端口
* @param[out] 	<HANDLE &client_handle> 添加tcpclient后返回的句柄，添加失败则为null
* @note			后续通讯的所有操作都通过句柄完成。
* @return		
*/
GTR_INTERNAL_EXPORT short GTR_AddTcpClient(HANDLE &handle,Gtr::STcpServerInfo *info_=NULL);

/**
* @brief		移除TCP客户端。用户级函数接口
* @param[in] 	<HANDLE handle_>TCP客户端的句柄
* @param[out]	无
* @note			移除TCP客户端后不再通讯。
* @return		<0>:移除失败，输入的句柄错误
* @return		<1>:移除成功
*/
GTR_INTERNAL_EXPORT short GTR_RemoveTcpClient(HANDLE handle_=NULL);

/**
* @brief		获取TCP客户端当前状态。用户级函数接口
* @param[in] 	<HANDLE handle_>TCP客户端的句柄
* @param[out]	<STcpClientStatus *status_>TCP客户端的连接状态结构体指针
* @note			每次操作TCP通讯前调用，用于确定当前通讯连接的状态。
* @return		<0>:获取失败，输入的句柄错误
* @return		<1>:获取成功
*/
GTR_INTERNAL_EXPORT short GTR_GetTcpClientStatus(HANDLE handle_=NULL,Gtr::STcpClientStatus *status_=NULL);


/**
* @brief		连接服务端。用户级函数接口
* @param[in] 	<HANDLE handle_>TCP客户端的句柄
* @param[out]	无
* @note			异步操作，连接指令执行后，通过客户端当前状态判断是否连接成功。
* @return		<-1>:参数错误，句柄不存在
* @return		<0>:连接指令发送成功
*/
GTR_INTERNAL_EXPORT short GTR_ConnectToServer(HANDLE handle_=NULL);

/**
* @brief		断开连接。用户级函数接口
* @param[in] 	<HANDLE handle_>TCP客户端的句柄
* @param[out]	无
* @note			异步操作，断开连接指令执行后，通过客户端当前状态判断是否成功断开连接。
* @return		<-1>:参数错误，句柄不存在
* @return		<0>:断开连接指令发送成功
*/
GTR_INTERNAL_EXPORT short GTR_DisConnectToServer(HANDLE handle_=NULL);

/**
* @brief		客户端发送数据。用户级函数接口
* @param[in] 	<HANDLE handle_>TCP客户端的句柄
* @param[in] 	<char *data_>发送数据的指针
* @param[in] 	<int data_len>发送数据的字节数
* @param[out]	无
* @note			异步操作，通讯线程后台执行。
* @return		<-1>:参数错误，句柄不存在
* @return		<0>:发送成功
*/
GTR_INTERNAL_EXPORT short GTR_ClientSendData(HANDLE handle_=NULL,char *data_=NULL,int data_len=0);

/**
* @brief		客户端读取数据。用户级函数接口
* @param[in] 	<HANDLE handle_>TCP客户端的句柄
* @param[in] 	<char *data_>接收数据的指针
* @param[out]	无
* @note			通过客户端状态的allow_read变量，确定是否有数据可读。内部有数据池，一次可读取一条，当所有数据读取完成后，数据池清空，allow_read状态复位。
* @return		<-1>:参数错误，句柄不存在
* @return		<其他>:接收到的数据字节数
*/
GTR_INTERNAL_EXPORT short GTR_ClientReadData(HANDLE handle_=NULL,char *data_=NULL);





/************************************************************************/
/*							数据交互模块									*/
/************************************************************************/

// 执行机器人系统参变量动作函数
// @param [in/out] buf 输入/输出的参变量数据区，最大长度为GtrMaxBufSize
// @param [in/out] data_type 输入/输出的变量数据类型
// @param [in] action 输入操作类型
// @param [in] craft 输入工艺类型
// @param [in] id 输入参变量ID
// @param [in] id2 输入的二级索引，默认为1
// @param [in] id3 输入的三级索引，默认为1
GTR_INTERNAL_EXPORT short GTR_DoRobotValueAction(char buf[GtrMaxBufSize], 
												 Gtr::DataType & data_type,
												 const Gtr::ActionType & action, 
												 const Gtr::CraftType & craft,
												 const long id, 
												 const short id2=1, 
												 const short id3=1);

// 注册机器人系统参变量动作函数
// @param [in] craft 输入工艺类型
// @param [in] func 输入的函数指针
// @note: 如需禁用该接口，则需再次调用该接口，并将输入的函数指针设置为NULL
GTR_INTERNAL_EXPORT short GTR_RegisterRobotValueAction(Gtr::CraftType craft, Gtr::GTR_RobotValueAction func);


/*-------------参变量接口 - 数据类型转化函数-----------------------*/

// 将机器人系统二进制数据转换为可读字符串
// @param [out] out_str, 输出的可读字符串, 字符串的最大长度为GtrMaxBufSize
// @param [in] in_buf, 输入的二进制数据, 数据的最大长度为GtrMaxBufSize
// @param [in] data_type 二进制数据的数据类型
GTR_INTERNAL_EXPORT short GTR_BinToStr(char out_str[GtrMaxBufSize], char in_buf[GtrMaxBufSize], const Gtr::DataType & data_type);


// 将可读字符串转换为机器人系统二进制数据
// @param [out] out_buf, 输出的二进制数据, 数据的最大长度为GtrMaxBufSize
// @param [in] in_str, 输入的可读字符串, 字符串的最大长度为GtrMaxBufSize
// @param [in] data_type 二进制数据的数据类型
GTR_INTERNAL_EXPORT short GTR_StrToBin(char out_buf[GtrMaxBufSize], char in_str[GtrMaxBufSize], const Gtr::DataType & data_type);


// 将机器人系统“机器人组位置”变量转换为字符串
// @param [out] out_str, 输出字符串, 字符串的最大长度为GtrMaxBufSize
// @param [in] value, 输入机器人组位置
GTR_INTERNAL_EXPORT short GTR_GroupPointToStr(char out_str[GtrMaxBufSize], const Gtr::GroupPoint & value);


// 将字符串转换为机器人系统“机器人组位置”变量
// @param [out] value, 输出机器人组位置
// @param [in] in_str, 输入字符串, 字符串的最大长度为GtrMaxBufSize
GTR_INTERNAL_EXPORT short GTR_StrToGroupPoint(Gtr::GroupPoint & value, char in_str[GtrMaxBufSize]);


// 将机器人系统“位置型”变量转换为字符串
// @param [out] out_str, 输出字符串, 字符串的最大长度为GtrMaxBufSize
// @param [in] value, 输入位置型变量
GTR_INTERNAL_EXPORT short GTR_PointToStr(char out_str[GtrMaxBufSize], const Gtr::Point & value);


// 将字符串转换为机器人系统“位置型”变量
// @param [out] value, 输出位置型变量
// @param [in] in_str, 输入字符串, 字符串的最大长度为GtrMaxBufSize
GTR_INTERNAL_EXPORT short GTR_StrToPoint(Gtr::Point & value, char in_str[GtrMaxBufSize]);


// 将机器人系统“坐标系”变量转换为字符串
// @param [out] out_str, 输出字符串, 字符串的最大长度为GtrMaxBufSize
// @param [in] value, 输入坐标系变量
GTR_INTERNAL_EXPORT short GTR_CoordSystemToStr(char out_str[GtrMaxBufSize], const Gtr::CoordSystem & value);


// 将字符串转换为机器人系统“坐标系”变量
// @param [out] value, 输出坐标系变量
// @param [in] in_str, 输入字符串, 字符串的最大长度为GtrMaxBufSize
GTR_INTERNAL_EXPORT short GTR_StrToCoordSystem(Gtr::CoordSystem & value, char in_str[GtrMaxBufSize]);

//设置回放运行启动使能信号，默认为true，默认可以直接启动回放运行
// @param [out] 无
// @param [in] enable, 输入布尔型变量，默认为true可以直接启动回放运行，设为false时禁止示教器上启动使能
GTR_INTERNAL_EXPORT short GTR_SetReplayStartEnable(bool enable);

//@brief		设置回放模式强制启动行号
//@param[in]	<line> 启动行号
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_INTERNAL_EXPORT short GTR_SetForcedReplayStartLine(long line,short channel);

//@brief		获取回放模式强制启动行号
//@param[in]	<line> 启动行号
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_INTERNAL_EXPORT short GTR_GetForcedReplayStartLine(long &line,short channel);

//@brief		设置回放模式强制启动程序文件夹
//@param[in]	<line>回放启动程序文件夹
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_INTERNAL_EXPORT short GTR_SetForcedReplayStartPrgDir(char path[256],short channel);

//@brief		获取回放模式强制启动程序文件夹
//@param[in]	<line>回放启动程序文件夹
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_INTERNAL_EXPORT short GTR_GetForcedReplayStartPrgDir(char path[256],short channel);

//@brief		设置回放模式强制启动程序文件名
//@param[in]	<line>回放启动程序文件名
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_INTERNAL_EXPORT short GTR_SetForcedReplayStartPrgName(char path[256],short channel);

//@brief		获取回放模式强制启动程序文件名
//@param[in]	<line>回放启动程序文件名
//@param[in] 	<channel> 通道号
//@param[out]	无		
GTR_INTERNAL_EXPORT short GTR_GetForcedReplayStartPrgName(char path[256],short channel);



#endif