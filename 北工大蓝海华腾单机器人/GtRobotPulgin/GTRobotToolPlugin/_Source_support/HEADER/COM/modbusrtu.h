#ifndef MODBUSRTU_H
#define MODBUSRTU_H

//ͨѶ��ʱʱ�䣬����Ϊ500����
#define Time_out 500

#include "comm_struct_define.h"
#include "robot_comm_interface.h"
#include "plc_standard_class.h"

typedef struct
{
	bool read_enb;					///<trueΪ��03�����룬falseΪд06������
	unsigned short start_adress;	///<��/д ��ʼ��ַ
	unsigned short data_len;		///<��/д ���ݳ��ȣ�Ĭ��д���Ⱥ�Ϊ1���˴�������Ч��
	unsigned short *p_data;			///<����ָ��
	bool *is_finish;				///<ͨѶ���״̬
	bool *is_timeout;				///<ͨѶ��ʱ״̬				
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

	//ע���ַ
	void resinfo(STcpServerInfo *info,unsigned char station=1);
	//��ȡTCP�ͻ����Ƿ������������������TCP����
	bool commIsOk();
	//��ȡͨѶ����״̬
	bool getConnectStatus();
	//���ڴ������������ص�PLC�߳�
	void loopRun();
	//���ͨѶ���� ����TRUE��ӳɹ�
	bool addCmdEx(SModbusRtuCmdEx *cmd);

private:
	//�����ּĴ����������� ������03
	int readDataGenerate(char *send_data);
	//�������ݽ��� ������������true,���򷵻�false
	bool readReceiveData(int data_len,char *read_data);	
	//д���ּĴ����������� ������06
	int writeDataGenerate(char *send_data);	
	//����д���ݷ��� ������������true,���򷵻�false
	bool writeReceiveData(int data_len,char *read_data);	
	unsigned int Crc16(unsigned char* data , unsigned char length);

private:
	HANDLE handle_;			//ͨѶ���Ӿ��
	unsigned char station_id;
	SModbusRtuCmdEx cmdEx;
	bool cmdExEnb;							//����ͨѶ����ʹ��
	STcpClientStatus client_sts;
	TON ton_timeout;
};

#endif // MODBUSRTU_H
