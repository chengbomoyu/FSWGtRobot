#ifndef GTR_USER_INTERFACE_H
#define GTR_USER_INTERFACE_H
#include <QWidget>
#include <QString>
#include <QMultiMap>

#include "gtrobot_frontend_define.h"

///////////////////////////////////////////////////////////////////////// 
/// GTRobot	固高科技 开放式可重组工业机器人控制系统开发平台
/// Copyright (C) 2020 Googol Technology Ltd. All Rights Reserved.  
///   
/// @file		gtr_user_interface.h    
/// @brief		GTR工艺机器人控制系统-顶层接口-数据接口定义  
/// @version 	v2.0.7.0         
//////////////////////////////////////////////////////////////////////////


class FrameInterface: public QWidget	//FrontEndInterface
{

public:
	virtual ~FrameInterface(){}
	
/**
 * @brief		初始化机器人系统
 * @param[in]	无
 * @param[out]	无
 * @note		该函数包含机器人系统基本模块的初始化，如PLC、NC、译码模块等
 * @return		<0>: 初始化成功
 * @return		<1>: 初始化失败
 */	
	virtual short InitRobotSystem() = 0;
	
/**
 * @brief		读取机器人系统用户权限等级
 * @param[in]	无
 * @param[out]	<PermissionLevel &level>: 用户权限等级
 * @note		PermissionLevel::OPERATOR 操作工
 *				PermissionLevel::MANAGER  管理员
 *				PermissionLevel::FACTORY  出厂设置
 * @code		
 *				PermissionLevel level;
 *				FrameInterface *robot_interface = GetSysInstance(0);	//获取机器人系统对象
 * 				robot_interface->GetPermissionLevel(level);				//读取机器人当前用户权限
 * @endcode	
 * @return		<0>: 读取成功
 * @return		<1>: 读取失败
 */
	virtual short GetPermissionLevel(front_gtr::PermissionLevel &level) = 0;
	
/**
 * @brief		设置机器人系统用户权限等级
 * @param[in]	<PermissionLevel level>: 用户权限等级
 * @note		PermissionLevel::OPERATOR 操作工
 *				PermissionLevel::MANAGER  管理员
 *				PermissionLevel::FACTORY  出厂设置
 * @code		
 *				PermissionLevel level = PermissionLevel::FACTORY;
 *				FrameInterface *robot_interface = GetSysInstance(0);	//获取机器人系统对象
 * 				robot_interface->SetPermissionLevel(level);				//设置机器人当前用户权限为"出厂设置"
 * @endcode	
 * @return		<0>: 设置成功
 * @return		<1>: 设置失败
 */
	virtual short SetPermissionLevel(front_gtr::PermissionLevel level) = 0;

/**
 * @brief		读取机器人系统版本信息
 * @param[in]	无
 * @param[out]	<QString &version>: 版本信息
 * @note		版本格式：x.x.x.x 如2.0.1.2
 * @code		
 *				QString version;
 *				FrameInterface *robot_interface = GetSysInstance(0);	//获取机器人系统对象
 * 				robot_interface->GetRobotVersion(version);				//设置机器人系统版本信息
 * @endcode	
 * @return		<0>: 读取成功
 * @return		<1>: 读取失败
 */	
	virtual short GetRobotVersion(QString &version) = 0;

	/**
 * @brief		获取各模块版本信息
 * @param[in]	<ModuleType type>: 模块名称
 * @param[out]	<QString &version>: 版本信息
 */
	virtual void GetModuleVersion(front_gtr::ModuleType type,QString &version) = 0;
	
/**
 * @brief		添加指定变量序列至文件(布尔、整数、实数型、字符型变量)
 * @param[in]	<NumericVarType type>:变量类型
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:变量序列
 * @param[out]	<double &progress>:存储进度条
 * @note		变量在文件中不存在时自动创建新xml节点，变量存在时更新xml节点值,不包含共享内存读写
 *				函数内部将初始化progress为0，完成读写操作时process = 100;
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
/*	virtual short SaveVarNumberToFile(front_gtr::NumericVarType type,QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;*/

/**
 * @brief		添加布尔型变量序列至文件
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:变量序列
 * @param[out]	<double &progress>:存储进度条
 * @note		变量在文件中不存在时自动创建新xml节点，变量存在时更新xml节点值,不包含共享内存读写
 *				函数内部将初始化progress为0，完成读写操作时process = 100;
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveVarBToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;

/**
 * @brief		添加整数型变量序列至文件
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:变量序列
 * @param[out]	<double &progress>:存储进度条
 * @note		变量在文件中不存在时自动创建新xml节点，变量存在时更新xml节点值,不包含共享内存读写
 *				函数内部将初始化progress为0，完成读写操作时process = 100;
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveVarIToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;

	/**
 * @brief		添加实数型变量序列至文件
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:变量序列
 * @param[out]	<double &progress>:存储进度条
 * @note		变量在文件中不存在时自动创建新xml节点，变量存在时更新xml节点值,不包含共享内存读写
 *				函数内部将初始化progress为0，完成读写操作时process = 100;
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveVarRToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;

/**
 * @brief		添加字符型变量序列至文件
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:变量序列
 * @param[out]	<double &progress>:存储进度条
 * @note		变量在文件中不存在时自动创建新xml节点，变量存在时更新xml节点值,不包含共享内存读写
 *				函数内部将初始化progress为0，完成读写操作时process = 100;
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveVarStrToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;
/**
 * @brief		添加指定id变量至文件(位置、增量位置型变量)
 * @param[in]	<PositionVarType type>: 变量类型
 * @param[in]	<int id>: 变量id
 * @param[out]	<VarPosition var>: 需要存储的位置型变量
 * @note		在文件尾部追加新变量节点,不包含共享内存读写
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveVarPToFile(front_gtr::PositionVarType type,int id,front_gtr::VarPosition var) = 0;
	
/**
 * @brief		批量写入变量至文件(位置、增量位置型变量)
 * @param[in]	<PositionVarType type>: 变量类型
 * @param[in]	<QMap<int,VarPosition> var_map>: 变量序列
 * @param[out]	<double &progress>: 存储进度条
 * @note		变量在文件中不存在时自动创建新xml节点，变量存在时更新xml节点值,不包含共享内存读写
 *				函数内部将初始化progress为0，完成读写操作时process = 100;
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveVarsPToFile(front_gtr::PositionVarType type,QMap<int,front_gtr::VarPosition> var_map,double &progress) = 0;

/**
 * @brief		保存当前正在使用的控制器参数至文件
 * @param[in]	<front_gtr::SysCtlParam para>: 控制器参数结构体
 * @param[out]	无
 * @note		只包含参数文件的写出,不包含共享内存读写
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 */
	virtual short SaveControllerConfigToFile(front_gtr::SystemParam para) = 0;

/**
 * @brief		保存当前正在使用的通道参数至文件
 * @param[in]	<int id>: 需要保存的通道ID号
 * @param[out]	无
 * @note		只包含参数文件的写出,不包含共享内存读写
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 */
	virtual short SaveChannelConfigToFile(short id) = 0;

/**
 * @brief		保存轴关节参数至文件
 * @param[in]	<AxisConfig para>: 轴关节参数结构体
 * @param[in]	<int id>: 需要保存的轴ID号
 * @param[out]	无
 * @note		只包含参数文件的读写(不读写耦合比参数),不包含共享内存读写,id下标从0开始，即0为1轴关节参数
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveAxisConfigToFile(short id) = 0;

/**
 * @brief		保存组配置参数至文件
 * @param[in]	<GroupConfig para>: 组配置参数结构体
 * @param[in]	<int id>: 需要保存的组ID号
 * @param[out]	无
 * @note		只包含参数文件的读写(不读写动力学模型参数),不包含共享内存读写,id下标从0开始，即0为group1参数
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */
	virtual short SaveGroupConfigToFile(short id) = 0;

/**
 * @brief		保存DH参数至文件
 * @param[in]	<DhCouplePara para>: 连杆及耦合比配置参数
 * @param[out]	无
 * @note		只包含参数文件的读写,不包含共享内存读写
 * @return		<0>: 添加成功
 * @return		<1>: 打开文件失败
 * @return		<2>: 添加失败，节点已存在
 * @return		<3>: 添加失败，其他异常
 */	
	virtual short SaveMechModelConfigToFile(front_gtr::DhPara para,short group) = 0;

/**
 * @brief		获取报警列表的首条报警信息
 * @param[in]	<long &id>: 报警id
 * @param[in]	<QString &msg>: 报警信息
 * @param[out]	无
 * @return		<0>: 获取报警信息成功
 * @return		<-1>: 返回失败，报警信息为空
 * @note		清除系统报警状态，报警列表一并清除，返回值为-1
 */
	virtual short GetCurrentAlarm(QString &id,QString &msg) = 0;

/**
 * @brief		从数据库批量读入报警历史
 * @param[in]	<QMultiMap<int,QString> &alarm_map>: 报警历史信息。int->报警id,QString->报警内容
 * @param[out]	无
 * @note		只包含参数文件的读写,不包含共享内存读写
 * @return		<0>: 读取成功
 * @return		<1>: 读取失败
 */	
	virtual short LoadAlarmFromFile(QMultiMap<QString,QString> &alarm_map) = 0;

/**
 * @brief		批量写入报警历史至文件
 * @param[in]	<QMap<int,QString> &alarm_map>: 报警历史信息，int:报警历史id,QString:报警内容
 * @param[out]	无
 * @note		读取最近100条报警历史记录
 * @return		<0>: 写入成功
 * @return		<n>: 写入失败，n 为写入失败的条目数
 */	
	virtual short SaveAlarmToFile(QMultiMap<QString,QString> &alarm_map) = 0;

/**
 * @brief		从数据库批量读入操作日志
 * @param[in]	无
 * @param[out]	<QList<LogItem> &log_list>: 操作日志信息
 * @note		读取最近100条操作日志记录
 * @return		<0>: 读取成功
 * @return		<1>: 读取失败
 */	
	virtual short LoadLogFromFile(QList<front_gtr::LogItem> &log_list) = 0;

/**
 * @brief		批量写入操作日志至文件
 * @param[in]	<QString log>: 操作日志信息
 * @param[out]	无
 * @note		只包含参数文件的读写,不包含共享内存读写
 * @return		<0>: 写入成功
 * @return		<1>: 写入失败
 */	
	virtual short SaveLogToFile(QString log) = 0;

	/**
 * @brief		显示机器人系统HMI
 * @param[in]	无
 * @param[out]	无
 * @return		<0>: 设置成功
 * @return		<1>: 设置失败
 */		
	virtual short ShowHMI() = 0;
	
/**
 * @brief		隐藏机器人系统HMI
 * @param[in]	无
 * @param[out]	无
 * @return		<0>: 设置成功
 * @return		<1>: 设置失败
 */	
	virtual short HideHMI() = 0;


/**
 * @brief		设定组合键“联锁”+“上档”+“清除”是否退出专业界面
 * @param[in]	<bool flag>: true按键有效，false按键无效
 * @param[out]	无
 */
	virtual void EnableQuitKey(bool flag) = 0;

/**
 * @brief		是否创建专业界面键盘对象
 * @param[in]	<bool flag>: true创建键盘对象，false不创建键盘对象
 * @param[out]	无
 */
	virtual void CreateKeyBoard(bool flag) = 0;


/**
 * @brief		设置键盘弹出模式
 * @param[in]	<bool mode>: false不弹出专业界面的键盘,true弹出专业界面的键盘
 * @param[out]	无
 */
	virtual void SetKeyBoardMode(bool mode) = 0;
	
/**
 * @brief		获取键盘弹出模式
 * @param[in]	无
 * @param[out]	无
 * @return		<false>: 不弹出专业界面的键盘
 * @return		<true>: 弹出专业界面的键盘
 */
	virtual bool GetKeyBoardMode() = 0;

/**
* @brief		显示左下角“主菜单”按钮
* @param[out]	无
* @return		<0>: 设置成功
* @return		<1>: 设置失败
*/	
	virtual short ShowMainButton() = 0;

/**
 * @brief		隐藏左下角“主菜单”按钮
 * @param[out]	无
 * @return		<0>: 设置成功
 * @return		<1>: 设置失败
 */	
	virtual short HideMainButton() = 0;

signals:
	void SignalMStackWidget(int iPageNum);

}; 


#endif