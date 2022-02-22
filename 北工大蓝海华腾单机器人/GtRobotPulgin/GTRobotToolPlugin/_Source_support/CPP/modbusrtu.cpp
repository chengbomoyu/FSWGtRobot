#include "modbusrtu.h"

ModbusRTU::ModbusRTU(){

}

ModbusRTU::~ModbusRTU()
{
	if (handle_ != NULL)
	{
		disConnectToServer(handle_);
		removeTcpClient(handle_);
	}
}

void ModbusRTU::resinfo(STcpServerInfo *info,unsigned char station){
	memset(&client_sts,0,sizeof(STcpClientStatus));
	cmdExEnb = false;
	station_id = station;
	handle_ = addTcpClient(info);
	if (handle_ != NULL)
	{
		connectToServer(handle_);
	}
}

void ModbusRTU::loopRun()
{
	if (handle_ == NULL)
		return;
	//获取通讯状态
	getTcpClientStatus(handle_,&client_sts);
	if (!client_sts.is_connected)		//非通讯连接状态时，不执行周期函数
		return;

	if (cmdExEnb)	//有数据需要处理时
	{
		ton_timeout.Execute(true,Time_out);
		if (ton_timeout.GetQValue()) //超时
		{
			cmdEx.is_timeout = (bool*)true;
			cmdEx.is_finish = (bool*)true;
			cmdExEnb = false;
			ton_timeout.Execute(false,Time_out);
			return;
		}
		//判断是否有数据相应返回
		if (client_sts.allow_read)
		{
			char read_data[256] = {0};
			int read_len = clientReadData(handle_,read_data);
			if (cmdEx.read_enb)
			{
				//判断相应数据是否正常
				if (readReceiveData(read_len,read_data))
				{
					cmdEx.is_timeout = (bool*)false;
					cmdEx.is_finish = (bool*)true;
					cmdExEnb = false;
					ton_timeout.Execute(false,Time_out);
					return;
				}
			} 
			else
			{
				//判断相应数据是否正常
				if (writeReceiveData(read_len,read_data))
				{
					cmdEx.is_timeout = (bool*)false;
					cmdEx.is_finish = (bool*)true;
					cmdExEnb = false;
					ton_timeout.Execute(false,Time_out);
					return;
				}
			}

		}
	} 
	else
		ton_timeout.Execute(false,Time_out);

}

bool ModbusRTU::commIsOk()
{
	if (handle_ == NULL)
		return false;
	else
		return true;
}

bool ModbusRTU::getConnectStatus()
{
	return client_sts.is_connected;
}

bool ModbusRTU::addCmdEx( SModbusRtuCmdEx *cmd )
{
	if (handle_ == NULL)
		return false;

	getTcpClientStatus(handle_,&client_sts);
	if (!client_sts.is_connected)		//非通讯连接状态时，不执行周期函数
		return false;

	if (cmdExEnb == true)		//正在执行中,不允许接收其他通讯命令
	{
		return false;
	}
	if (cmd->read_enb)	//读数据时，校验长度
	{
		if (cmd->data_len==0 || cmd->data_len>120)	//参数校验
		{
			return false;
		}
	}

	if (cmd->start_adress<1)
	{
		return false;
	}
	if (cmd->p_data == NULL)
	{
		return false;
	}
	cmd->is_finish = false;
	cmd->is_timeout = false;

	cmdExEnb = true;
	memcpy(&cmdEx,cmd,sizeof(cmdEx));
/*	cmdEx = cmd;*/

	//发送数据
	char send_data[256] = {0};
	int send_len = 0;
	if (cmdEx.read_enb)
		send_len = readDataGenerate(send_data);
	else
		send_len = writeDataGenerate(send_data);
	clientSendData(handle_,send_data,send_len);

	return true;
}

//读保持寄存器数据生成 功能码03
int ModbusRTU::readDataGenerate( char *send_data )
{
	send_data[0] = station_id;					//从站地址
	send_data[1] = 3;							//功能码
	send_data[2] = static_cast<char>(cmdEx.start_adress>>8);			//起始地址高位
	send_data[3] = static_cast<char>(cmdEx.start_adress & 0xff);		//起始地址低位
	send_data[4] = static_cast<char>(cmdEx.data_len>>8);				//数据长度高位
	send_data[5] = static_cast<char>(cmdEx.data_len & 0xff);			//数据长度低位

	unsigned int usCrc = Crc16((unsigned char *)send_data,6);	//CRC校验
	send_data[6] = usCrc&0xFF;
	send_data[7] = (0xFF00 & usCrc)>>8;

	return 8;
}

//接收数据解析
bool ModbusRTU::readReceiveData( int data_len,char *read_data )
{
	int len_ = cmdEx.data_len * 2 + 5;
	if (len_ != data_len)	//数据总长度判断
		return false;

	if (cmdEx.data_len * 2 != read_data[2])	//寄存器返回字节数比较
		return false;

	if (read_data[0] != station_id)			//站地址校对
		return false;

	if (read_data[1] != 3)					//功能码校对
		return false;

	//数据解析
	char * data_ = (char *)cmdEx.p_data;
	for (int i=0;i<cmdEx.data_len;i++)
	{
		*data_++ = read_data[4+2*i];
		*data_++ = read_data[3+2*i];
	}
	return true;
}

//写保持寄存器数据生成 功能码06
int ModbusRTU::writeDataGenerate(char *send_data )
{
	send_data[0] = station_id;				//从站地址
	send_data[1] = 6;						//功能码
	send_data[2] = static_cast<char>(cmdEx.start_adress>>8);			//起始地址高位
	send_data[3] = static_cast<char>(cmdEx.start_adress & 0xff);		//起始地址低位
	send_data[4] = *((char *)cmdEx.p_data + 1);				//数据高位
	send_data[5] = *((char *)cmdEx.p_data);					//数据低位

	unsigned int usCrc = Crc16((unsigned char *)send_data,6);	//CRC校验
	send_data[6] = usCrc&0xFF;
	send_data[7] = (0xFF00 & usCrc)>>8;

	return 8;
}

//接收写数据返回 数据正常返回true,否则返回false
bool ModbusRTU::writeReceiveData( int data_len,char *read_data )
{
	if (8 != data_len)						//数据总长度判断
		return false;

	if (read_data[0] != station_id)			//站地址校对
		return false;

	if (read_data[1] != 6)					//功能码校对
		return false;

	return true;
}


unsigned int ModbusRTU::Crc16(unsigned char* data , unsigned char length)
{          
	unsigned char i = 0;            
	unsigned int crc = 0xffff;
	while(length--)
	{
		crc ^= *data++;
		for(i = 0; i < 8; i++)
		{
			if(crc & 0x01)  
			{
				crc = (crc >> 1) ^ 0xa001; 	// Polynomial: x^16 + x^15 + x^2 + 1 (0xa001)
			}
			else
			{
				crc = crc >> 1;
			}
		}
	}
	return crc;
}



