/*! 
*@file comm_struct_define.h
*@brief 通讯相关结构体定义
*@author 张 zhang.zb@googoltech.com
*@version v1.0.0
*@date 2020-10-12
*/
#ifndef COMM_STRUCT_DEFINE_H
#define COMM_STRUCT_DEFINE_H
#include <windows.h>
#include <string>

/**
 * @brief		Gibbon通讯数据生成回调。回调函数指针原型
 * @param[out]	输出数据的指针
 * @note		无
 * @return		返回输出数据的长度
 */
typedef int(*GibbonResponseCallback)(char *);

/**
 * @brief		远程TCP数据应答函数指针类型。回调函数指针原型
 * @param[in] 	输入数据的长度
 * @param[in] 	输入数据的指针
 * @param[out]	输出数据的指针
 * @note		无
 * @return		返回输出数据的长度
 */
typedef int(*RemoteTcpResponseCallback)(int,char *,char *);

/** 
* @brief ModbusTCP客户端配置参数 
*/
typedef struct
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
}SModbusTcpClientInfo;

/** 
* @brief 通用ModbusTCP客户端配置参数 
*/
typedef struct
{
	bool b_enable;					///<通讯启用使能

	char ip[20];					///<IP地址
	unsigned short port;			///<端口
	unsigned short station_id;		///<站地址

	bool b_read_coils;				///<读内部线圈使能
	bool b_read_input_coils;		///<读输入线圈使能
	bool b_read_hold_regs;			///<读保持寄存器使能
	bool b_read_input_regs;			///<读输入寄存器使能

	bool b_write_coils;				///<写内部线圈使能
	bool b_write_hold_regs;			///<写保持寄存器使能


	unsigned short read_coils_start_adress;			///<读内部线圈起始地址
	unsigned short read_coils_data_len;				///<读内部线圈数据长度

	unsigned short read_input_coils_start_adress;	///<读输入线圈起始地址
	unsigned short read_input_coils_data_len;		///<读输入线圈数据长度

	unsigned short read_hold_regs_start_adress;		///<读保持寄存器起始地址
	unsigned short read_hold_regs_data_len;			///<读保持寄存器数据长度

	unsigned short read_input_regs_start_adress;	///<读输入寄存器起始地址
	unsigned short read_input_regs_data_len;		///<读输入寄存器数据长度

	unsigned short write_coils_start_adress;		///<写内部线圈起始地址
	unsigned short write_coils_data_len;			///<写内部线圈数据长度

	unsigned short write_hold_regs_start_adress;	///<写保持寄存器起始地址
	unsigned short write_hold_regs_data_len;		///<写保持寄存器数据长度

	unsigned char *p_coils;							///<内部线圈数据地址
	unsigned char *p_input_coils;					///<输入线圈数据地址
	unsigned short *p_hold_regs;					///<保持寄存器数据地址
	unsigned short *p_input_regs;					///<输入寄存器数据地址

	unsigned short time_out;						///<超时时间,单位毫秒（0不检查超时）

}SModbusTcpClientNormalInfo;

/** 
* @brief ModbusTCP视觉客户端额外通讯命令 
*/
typedef struct
{
	bool read_enb;					///<true为读，false为写
	unsigned short start_adress;	///<读/写 起始地址
	unsigned short data_len;		///<读/写 数据长度
	unsigned short *p_data;			///<数据指针
	bool *is_finish;				///<通讯完成状态
}SModbusTcpClientCmdEx;



/** 
* @brief ModbusTCP服务端配置参数
*/
typedef struct
{
	bool b_enable;					///<使能
	char ip[20];					///<IP地址
	unsigned short port;			///<端口
	unsigned short *p_di_data;		///<输入数据地址
	unsigned short *p_do_data;		///<输出数据地址
	unsigned short time_out;		///<超时时间
}SModbusTcpServerInfo;


/** 
* @brief ModbusTCP通用服务端内部数据
*/
typedef struct 
{
	bool coil[10000];						//离散线圈（可读写）
	bool input_coil[10000];					//输入线圈（可读）
	unsigned short reg[10000];				//保持寄存器（可读写）
	unsigned short input_reg[10000];		//输入寄存器（可读）
}SModbusBuffer;

/** 
* @brief ModbusTCP通用服务端配置参数
*/
typedef struct
{
	char ip[20];					///<IP地址
	unsigned short port;			///<端口
	SModbusBuffer *p_data;			///<数据地址
}SModbusTcpServerNormalInfo;

/** 
* @brief TCP服务端配置参数
*/
typedef struct
{
	bool b_enable;					///<使能
	char ip[20];					///<IP地址
	unsigned short port;			///<端口
}SUserTcpServerInfo;

/** 
* @brief TCP服务端连接列表
*/
typedef struct
{
	std::string ip;					///<IP地址
	unsigned short port;			///<端口
 	unsigned long last_comm_time;	///<上一次数据交互时间(ms)
	HANDLE connect_;				///<连接指针
}STcpConnectClientInfo;


/** 
* @brief TCP服务端参数信息
*/
typedef struct
{
	char ip[20];					///<IP地址
	unsigned short port;			///<端口
}STcpServerInfo;

/** 
* @brief TCP客户端状态信息
*/
typedef struct
{
	bool is_connecting;				///<正在连接状态
	bool is_connected;				///<已经连接上
	bool allow_read;				///<允许读取
}STcpClientStatus;


#endif