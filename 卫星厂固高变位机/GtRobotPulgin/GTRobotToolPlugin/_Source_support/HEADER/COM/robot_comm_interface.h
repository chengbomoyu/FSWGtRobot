/*! 
*@file robot_comm_interface.h
*@brief 机器人系统通讯库
*@author 张 zhang.zb@googoltech.com
*@version v1.0.0
*@date 2020-10-12
*/
#ifndef ROBOT_COMM_INTERFACE_H
#define ROBOT_COMM_INTERFACE_H
#include "comm_struct_define.h"
#include <vector>
#include <string>

#ifdef ROBOTCOMM_LIB
#define RobotCommApi extern "C" __declspec(dllexport) //Q_DECL_EXPORT
#define RobotCommCpp __declspec(dllexport)
#else
#define RobotCommApi extern "C" __declspec(dllimport)	//Q_DECL_IMPORT
#define RobotCommCpp __declspec(dllimport)
#endif

using namespace std;
namespace CRobotComm
{

	/**
	 * @brief		删除整个通讯模块类。系统级函数接口
	 * @param[in]	无 
	 * @param[out]	无 
	 * @note		需系统软件退出前调用,用于释放通讯库相关资源	
	 */
	RobotCommApi void deleteInstance();

	/**
	 * @brief		设置ModbusTCP客户端通讯配置参数。系统级函数接口
	 * @param[in] 	<SModbusTcpClientInfo *info>ModbusTcp客户端连接配置参数指针
	 * @param[out]	无
	 * @note		设置通讯相关参数、开启关闭通讯都通过这个接口实现
	 */
	RobotCommApi void setModbusTcpClientInfo(SModbusTcpClientInfo *info);

	/**
	 * @brief		读取ModbusTCP客户端通讯配置参数。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无
	 * @return		返回当前使用的ModbusTcp客户端连接配置参数指针
	 */
	RobotCommApi SModbusTcpClientInfo * getModbusTcpClientInfo();

	/**
	 * @brief		ModbusTCP客户端通讯任务循环实现接口。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		需要被PLC线程周期调用。如果PLC线程没有正常运行，无法通讯。
	 */
	RobotCommApi void loopModbusTcpClient();

	/**
	 * @brief		获取ModbusTCP客户端通讯连接状态。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无 	
	 * @return		<false>:非连接状态
	 * @return		<true>:连接状态
	 */
	RobotCommApi bool getModbusTcpClientConnectStatus();

	/**
	 * @brief		设置ModbusTCP服务端通讯配置参数。系统级函数接口
	 * @param[in] 	<SModbusTcpServerInfo *info>ModbusTcp服务端连接配置参数指针
	 * @param[out]	无
	 * @note		设置通讯相关参数、开启关闭通讯都通过这个接口实现
	 */
	RobotCommApi void setModbusTcpServerInfo(SModbusTcpServerInfo *info);

	/**
	 * @brief		获取ModbusTCP服务端通讯配置参数。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无
	 * @return		返回当前使用的ModbusTcp服务端连接配置参数指针
	 */
	RobotCommApi SModbusTcpServerInfo * getModbusTcpServerInfo();

	/**
	 * @brief		ModbusTCP服务端通讯任务循环实现接口。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		需要被PLC线程周期调用。如果PLC线程没有正常运行，无法通讯。
	 */
	RobotCommApi void loopModbusTcpServer();

	/**
	 * @brief		获取ModbusTCP服务端远端连接列表。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无
	 * @return		返回所有连接的客户端列表信息，包含IP和端口
	 */
	RobotCommCpp vector<STcpConnectClientInfo> getModbusTcpServerConnectList();


	/**
	 * @brief		设置远程TCP服务端通讯配置参数。系统级函数接口
	 * @param[in] 	<SUserTcpServerInfo *info>包含本地IP地址、端口等信息
	 * @param[out]	无
	 * @note		远程TCP协议，机器人系统作为TCP服务端，需要设置本地的IP地址和端口。启停也通过此接口实现。
	 */
	RobotCommApi void setUserTcpServerInfo(SUserTcpServerInfo *info);

	/**
	 * @brief		获取远程TCP协议服务端通讯配置参数。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无
	 * @return		返回当前使用的自定义TCP服务端连接配置参数指针
	 */
	RobotCommApi SUserTcpServerInfo * getUserTcpServerInfo();

	/**
	 * @brief		远程TCP协议,机器人服务端通讯循环实现接口。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		需要被PLC线程周期调用。如果PLC线程没有正常运行，无法通讯。
	 */
	RobotCommApi void loopUserTcpServer();


	/**
	 * @brief		获取远程TCP服务端远端连接列表。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无
	 * @return		返回所有连接的客户端列表信息，包含IP和端口
	 */
	RobotCommCpp vector<STcpConnectClientInfo> getUserTcpServerConnectList();


	/**
	 * @brief		设置远程TCP数据应答函数指针。系统级函数接口
	 * @param[in] 	应答函数指针
	 * @param[out]	无
	 * @note		无 	
	 * @return		<false>:设置失败
	 * @return		<true>:设置成功
	 */
	RobotCommApi bool setRemoteTcpResponseCallback(RemoteTcpResponseCallback pFunc=NULL);

	/**
	 * @brief		获取远程TCP数据应答函数指针。系统级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无 	
	 * @return		应答函数指针
	 */
	RobotCommApi RemoteTcpResponseCallback getRemoteTcpResponseCallback();					

	/**
	 * @brief		设置Gibbon触发使能变量指针和通讯数据生成函数指针。系统级函数接口
	 * @param[in] 	使能触发变量指针
	 * @param[in] 	输出生成函数指针
	 * @param[out]	无
	 * @note		无 	
	 * @return		<false>:设置失败
	 * @return		<true>:设置成功
	 */
	RobotCommApi bool setGibbonTrig(bool * enb = NULL,GibbonResponseCallback pFunc=NULL);

	/**
	 * @brief		设设置ModbusTCP视觉客户端通讯配置参数。用户级函数接口
	 * @param[in] 	<SModbusTcpClientInfo *info>ModbusTcp客户端连接配置参数指针
	 * @param[out]	无
	 * @note		设置通讯相关参数、开启关闭通讯都通过这个接口实现
	 */
	RobotCommApi void setModbusTcpClientVisionInfo(SModbusTcpClientInfo *info);

	/**
	 * @brief		读取ModbusTCP视觉客户端通讯配置参数。用户级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无
	 * @return		返回当前使用的ModbusTcp客户端连接配置参数指针
	 */
	RobotCommApi SModbusTcpClientInfo * getModbusTcpClientVisionInfo();

	/**
	 * @brief		获取ModbusTCP视觉客户端通讯连接状态。用户级函数接口
	 * @param[in] 	无
	 * @param[out]	无
	 * @note		无 	
	 * @return		<false>:非连接状态
	 * @return		<true>:连接状态
	 */
	RobotCommApi bool getModbusTcpClientVisionConnectStatus();

	/**
	 * @brief		设置ModbusTCP视觉客户端辅助通讯命令。用户级函数接口
	 * @param[in] 	<SModbusTcpClientCmdEx *cmd>通讯命令数据的指针
	 * @param[out]	无
	 * @note		添加额外的通讯请求一次，通过传入的结构体内部数据返回值，判断辅助通讯命令是否执行完成。当执行完成后才可以进行下一次辅助通讯。
	 * @return		<false>:添加失败
	 * @return		<true>:添加成功
	 */
	RobotCommApi bool addModbusTcpClientCmdEx(SModbusTcpClientCmdEx *cmd);


	/**
	 * @brief		添加TCP客户端连接，返回客户端句柄。用户级函数接口
	 * @param[in] 	<STcpServerInfo *info_>远端IP地址和端口
	 * @param[out]	无
	 * @note		通讯的所有操作都通过句柄完成。
	 * @return		<NULL>:添加失败
	 * @return		<其他>:句柄值
	 */
	RobotCommApi HANDLE addTcpClient(STcpServerInfo *info_=NULL);

	/**
	 * @brief		移除TCP客户端。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP客户端的句柄
	 * @param[out]	无
	 * @note		移除TCP客户端后不再通讯。
	 * @return		<false>:移除失败，输入的句柄错误
	 * @return		<true>:移除成功
	 */
	RobotCommApi bool removeTcpClient(HANDLE handle_=NULL);

	/**
	 * @brief		获取TCP客户端当前状态。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP客户端的句柄
	 * @param[out]	<STcpClientStatus *status_>TCP客户端的连接状态结构体指针
	 * @note		每次操作TCP通讯前调用，用于确定当前通讯连接的状态。
	 * @return		<false>:获取失败，输入的句柄错误
	 * @return		<true>:获取成功
	 */
	RobotCommApi bool getTcpClientStatus(HANDLE handle_=NULL,STcpClientStatus *status_=NULL);

	/**
	 * @brief		连接服务端。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP客户端的句柄
	 * @param[out]	无
	 * @note		异步操作，连接指令执行后，通过客户端当前状态判断是否连接成功。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:连接指令发送成功
	 */
	RobotCommApi int connectToServer(HANDLE handle_=NULL);

	/**
	 * @brief		断开连接。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP客户端的句柄
	 * @param[out]	无
	 * @note		异步操作，断开连接指令执行后，通过客户端当前状态判断是否成功断开连接。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:断开连接指令发送成功
	 */
	RobotCommApi int disConnectToServer(HANDLE handle_=NULL);

	/**
	 * @brief		客户端发送数据。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP客户端的句柄
	 * @param[in] 	<char *data_>发送数据的指针
	 * @param[in] 	<int data_len>发送数据的字节数
	 * @param[out]	无
	 * @note		异步操作，通讯线程后台执行。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:发送成功
	 */
	RobotCommApi int clientSendData(HANDLE handle_=NULL,char *data_=NULL,int data_len=0);

	/**
	 * @brief		客户端读取数据。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP客户端的句柄
	 * @param[in] 	<char *data_>接收数据的指针
	 * @param[out]	无
	 * @note		通过客户端状态的allow_read变量，确定是否有数据可读。内部有数据池，一次可读取一条，当所有数据读取完成后，数据池清空，allow_read状态复位。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<其他>:接收到的数据字节数
	 */
	RobotCommApi int clientReadData(HANDLE handle_=NULL,char *data_=NULL);

	/**
	 * @brief		添加TCP服务端，返回服务端句柄。用户级函数接口
	 * @param[in] 	<STcpServerInfo *info_>本地IP地址和端口
	 * @param[out]	无
	 * @note		通讯的所有操作都通过句柄完成。
	 * @return		<NULL>:添加失败
	 * @return		<其他>:句柄值
	 */
	RobotCommApi HANDLE addTcpServer(STcpServerInfo *info_=NULL);

	/**
	 * @brief		移除TCP服务端。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[out]	无
	 * @note		移除TCP服务端后不再通讯。
	 * @return		<false>:移除失败，输入的句柄错误
	 * @return		<true>:移除成功
	 */
	RobotCommApi bool removeTcpServer(HANDLE handle_=NULL);

	/**
	 * @brief		获取TCP服务端连接列表。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[out]	<vector<STcpConnectClientInfo> *>当前TCP服务端的客户端连接列表指针
	 * @note		理论上，一个服务端的连接个数没有上限。
	 * @return		<false>:获取失败，输入的句柄错误
	 * @return		<true>:获取成功
	 */
	RobotCommCpp bool getTcpServerConnectList(HANDLE handle_=NULL,vector<STcpConnectClientInfo> *list=NULL);

	/**
	 * @brief		开启服务端监听。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[out]	无
	 * @note		开启服务端监听后，通过获取连接列表实现通讯
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:开启成功
	 */
	RobotCommApi int startTcpServer(HANDLE handle_=NULL);

	/**
	 * @brief		断开连接。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[in] 	<HANDLE connect_>TCP客户端的句柄
	 * @param[out]	无
	 * @note		异步操作，断开连接指令执行后，通过服务端连接列表判断是否成功断开连接。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:断开连接指令发送成功
	 */
	RobotCommApi int disConnectToOneClient(HANDLE handle_=NULL,HANDLE connect_=NULL);

	/**
	 * @brief		服务端发送数据。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[in] 	<HANDLE connect_>连接到此服务端下客户端的句柄
	 * @param[in] 	<char *data_>发送数据的指针
	 * @param[in] 	<int data_len>发送数据的字节数
	 * @param[out]	无
	 * @note		异步操作，通讯线程后台执行。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:发送成功
	 */
	RobotCommApi int serverSendData(HANDLE handle_=NULL,HANDLE connect_=NULL,char *data_=NULL,int data_len=0);

	/**
	 * @brief		服务端读取数据。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[in] 	<HANDLE connect_>连接到此服务端下客户端的句柄
	 * @param[out] 	<char *data_>接收数据的指针
	 * @note		需要周期轮询，有数据则读取数据。
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:没有可读取的数据
	 * @return		<其他>:接收到的数据字节数
	 */
	RobotCommApi int serverReadData(HANDLE handle_=NULL,HANDLE connect_=NULL,char *data_=NULL);

	/**
	 * @brief		添加ModbusTCP服务端，返回服务端句柄。用户级函数接口
	 * @param[in] 	<STcpServerInfo *info_>本地IP地址和端口
	 * @param[out]	无
	 * @note		通讯的所有操作都通过句柄完成。
	 * @return		<NULL>:添加失败
	 * @return		<其他>:句柄值
	 */
	RobotCommApi HANDLE addNormalModbusTcpServer(SModbusTcpServerNormalInfo *info_=NULL);

	/**
	 * @brief		移除ModbusTCP服务端。用户级函数接口
	 * @param[in] 	<HANDLE handle_>TCP服务端的句柄
	 * @param[out]	无
	 * @note		移除TCP服务端后不再通讯。
	 * @return		<false>:移除失败，输入的句柄错误
	 * @return		<true>:移除成功
	 */
	RobotCommApi bool removeNormalModbusTcpServer(HANDLE handle_=NULL);

	/**
	 * @brief		获取ModbusTCP服务端连接列表。用户级函数接口
	 * @param[in] 	<HANDLE handle_>ModbusTCP服务端的句柄
	 * @param[out]	<vector<STcpConnectClientInfo> *>当前TCP服务端的客户端连接列表指针
	 * @note		理论上，一个服务端的连接个数没有上限。
	 * @return		<false>:获取失败，输入的句柄错误
	 * @return		<true>:获取成功
	 */
	RobotCommCpp bool getNormalModbusTcpServerConnectList(HANDLE handle_=NULL,vector<STcpConnectClientInfo> *list=NULL);

	/**
	 * @brief		开启服务端监听。用户级函数接口
	 * @param[in] 	<HANDLE handle_>ModbusTCP服务端的句柄
	 * @param[out]	无
	 * @note		开启服务端监听后，通过获取连接列表实现通讯
	 * @return		<-1>:参数错误，句柄不存在
	 * @return		<0>:开启成功
	 */
	RobotCommApi int startNormalModbusTcpServer(HANDLE handle_=NULL);

}

#endif // ROBOT_COMM_INTERFACE_H
