#ifndef MODBUSRTU_H
#define MODBUSRTU_H

//通讯超时时间，设置为500毫秒
#define Time_out 500

#include "comm_struct_define.h"
#include "robot_comm_interface.h"
#include "plc_standard_class.h"

typedef struct
{
	bool read_enb;					///<true为读03功能码，false为写06功能码
	unsigned short start_adress;	///<读/写 起始地址
	unsigned short data_len;		///<读/写 数据长度（默认写长度恒为1，此处参数无效）
	unsigned short *p_data;			///<数据指针
	bool *is_finish;				///<通讯完成状态
	bool *is_timeout;				///<通讯超时状态				
}SModbusRtuCmdEx;


#pragma comment(lib,"RobotComm.lib")

using namespace CRobotComm;
using namespace plc;

class ModbusRTU
{
public:
	ModbusRTU();
	//ModbusRTU();
	~ModbusRTU();

	//注册地址
	void resinfo(STcpServerInfo *info,unsigned char station=1);
	//获取TCP客户端是否开启正常，不正常检查TCP参数
	bool commIsOk();
	//获取通讯连接状态
	bool getConnectStatus();
	//周期触发函数，加载到PLC线程
	void loopRun();
	//添加通讯命令 返回TRUE添加成功
	bool addCmdEx(SModbusRtuCmdEx *cmd);

private:
	//读保持寄存器数据生成 功能码03
	int readDataGenerate(char *send_data);
	//接收数据解析 数据正常返回true,否则返回false
	bool readReceiveData(int data_len,char *read_data);	
	//写保持寄存器数据生成 功能码06
	int writeDataGenerate(char *send_data);	
	//接收写数据返回 数据正常返回true,否则返回false
	bool writeReceiveData(int data_len,char *read_data);	
	unsigned int Crc16(unsigned char* data , unsigned char length);

private:
	HANDLE handle_;			//通讯连接句柄
	unsigned char station_id;
	SModbusRtuCmdEx cmdEx;
	bool cmdExEnb;							//额外通讯命令使能
	STcpClientStatus client_sts;
	TON ton_timeout;
};

#endif // MODBUSRTU_H
