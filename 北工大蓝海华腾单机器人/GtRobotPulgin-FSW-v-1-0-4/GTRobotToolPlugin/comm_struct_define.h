/*! 
*@file comm_struct_define.h
*@brief ͨѶ��ؽṹ�嶨��
*@author �� zhang.zb@googoltech.com
*@version v1.0.0
*@date 2020-10-12
*/
#ifndef COMM_STRUCT_DEFINE_H
#define COMM_STRUCT_DEFINE_H
#include <windows.h>
#include <string>

/**
 * @brief		GibbonͨѶ�������ɻص����ص�����ָ��ԭ��
 * @param[out]	������ݵ�ָ��
 * @note		��
 * @return		����������ݵĳ���
 */
typedef int(*GibbonResponseCallback)(char *);

/**
 * @brief		Զ��TCP����Ӧ����ָ�����͡��ص�����ָ��ԭ��
 * @param[in] 	�������ݵĳ���
 * @param[in] 	�������ݵ�ָ��
 * @param[out]	������ݵ�ָ��
 * @note		��
 * @return		����������ݵĳ���
 */
typedef int(*RemoteTcpResponseCallback)(int,char *,char *);

/** 
* @brief ModbusTCP�ͻ������ò��� 
*/
typedef struct
{
	bool b_enable;					///<ͨѶ����ʹ��
	bool b_read;					///<ͨѶ���ڶ�ʹ��
	bool b_write;					///<ͨѶ����дʹ��
	char ip[20];					///<IP��ַ
	unsigned short port;			///<�˿�
	unsigned short station_id;		///<վ��ַ
	unsigned short read_start_adress;///<����ʼ��ַ
	unsigned short read_data_len;	///<�����ݳ���
	unsigned short write_start_adress;///<д��ʼ��ַ
	unsigned short write_data_len;	///<д���ݳ���
	unsigned short *p_di_data;		///<�������ݵ�ַ
	unsigned short *p_do_data;		///<������ݵ�ַ
	unsigned short time_out;		///<��ʱʱ��,��λ����
}SModbusTcpClientInfo;

/** 
* @brief ͨ��ModbusTCP�ͻ������ò��� 
*/
typedef struct
{
	bool b_enable;					///<ͨѶ����ʹ��

	char ip[20];					///<IP��ַ
	unsigned short port;			///<�˿�
	unsigned short station_id;		///<վ��ַ

	bool b_read_coils;				///<���ڲ���Ȧʹ��
	bool b_read_input_coils;		///<��������Ȧʹ��
	bool b_read_hold_regs;			///<�����ּĴ���ʹ��
	bool b_read_input_regs;			///<������Ĵ���ʹ��

	bool b_write_coils;				///<д�ڲ���Ȧʹ��
	bool b_write_hold_regs;			///<д���ּĴ���ʹ��


	unsigned short read_coils_start_adress;			///<���ڲ���Ȧ��ʼ��ַ
	unsigned short read_coils_data_len;				///<���ڲ���Ȧ���ݳ���

	unsigned short read_input_coils_start_adress;	///<��������Ȧ��ʼ��ַ
	unsigned short read_input_coils_data_len;		///<��������Ȧ���ݳ���

	unsigned short read_hold_regs_start_adress;		///<�����ּĴ�����ʼ��ַ
	unsigned short read_hold_regs_data_len;			///<�����ּĴ������ݳ���

	unsigned short read_input_regs_start_adress;	///<������Ĵ�����ʼ��ַ
	unsigned short read_input_regs_data_len;		///<������Ĵ������ݳ���

	unsigned short write_coils_start_adress;		///<д�ڲ���Ȧ��ʼ��ַ
	unsigned short write_coils_data_len;			///<д�ڲ���Ȧ���ݳ���

	unsigned short write_hold_regs_start_adress;	///<д���ּĴ�����ʼ��ַ
	unsigned short write_hold_regs_data_len;		///<д���ּĴ������ݳ���

	unsigned char *p_coils;							///<�ڲ���Ȧ���ݵ�ַ
	unsigned char *p_input_coils;					///<������Ȧ���ݵ�ַ
	unsigned short *p_hold_regs;					///<���ּĴ������ݵ�ַ
	unsigned short *p_input_regs;					///<����Ĵ������ݵ�ַ

	unsigned short time_out;						///<��ʱʱ��,��λ���루0����鳬ʱ��

}SModbusTcpClientNormalInfo;

/** 
* @brief ModbusTCP�Ӿ��ͻ��˶���ͨѶ���� 
*/
typedef struct
{
	bool read_enb;					///<trueΪ����falseΪд
	unsigned short start_adress;	///<��/д ��ʼ��ַ
	unsigned short data_len;		///<��/д ���ݳ���
	unsigned short *p_data;			///<����ָ��
	bool *is_finish;				///<ͨѶ���״̬
}SModbusTcpClientCmdEx;



/** 
* @brief ModbusTCP��������ò���
*/
typedef struct
{
	bool b_enable;					///<ʹ��
	char ip[20];					///<IP��ַ
	unsigned short port;			///<�˿�
	unsigned short *p_di_data;		///<�������ݵ�ַ
	unsigned short *p_do_data;		///<������ݵ�ַ
	unsigned short time_out;		///<��ʱʱ��
}SModbusTcpServerInfo;


/** 
* @brief ModbusTCPͨ�÷�����ڲ�����
*/
typedef struct 
{
	bool coil[10000];						//��ɢ��Ȧ���ɶ�д��
	bool input_coil[10000];					//������Ȧ���ɶ���
	unsigned short reg[10000];				//���ּĴ������ɶ�д��
	unsigned short input_reg[10000];		//����Ĵ������ɶ���
}SModbusBuffer;

/** 
* @brief ModbusTCPͨ�÷�������ò���
*/
typedef struct
{
	char ip[20];					///<IP��ַ
	unsigned short port;			///<�˿�
	SModbusBuffer *p_data;			///<���ݵ�ַ
}SModbusTcpServerNormalInfo;

/** 
* @brief TCP��������ò���
*/
typedef struct
{
	bool b_enable;					///<ʹ��
	char ip[20];					///<IP��ַ
	unsigned short port;			///<�˿�
}SUserTcpServerInfo;

/** 
* @brief TCP����������б�
*/
typedef struct
{
	std::string ip;					///<IP��ַ
	unsigned short port;			///<�˿�
 	unsigned long last_comm_time;	///<��һ�����ݽ���ʱ��(ms)
	HANDLE connect_;				///<����ָ��
}STcpConnectClientInfo;


/** 
* @brief TCP����˲�����Ϣ
*/
typedef struct
{
	char ip[20];					///<IP��ַ
	unsigned short port;			///<�˿�
}STcpServerInfo;

/** 
* @brief TCP�ͻ���״̬��Ϣ
*/
typedef struct
{
	bool is_connecting;				///<��������״̬
	bool is_connected;				///<�Ѿ�������
	bool allow_read;				///<�����ȡ
}STcpClientStatus;


#endif