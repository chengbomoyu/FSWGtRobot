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
	//��ȡͨѶ״̬
	getTcpClientStatus(handle_,&client_sts);
	if (!client_sts.is_connected)		//��ͨѶ����״̬ʱ����ִ�����ں���
		return;

	if (cmdExEnb)	//��������Ҫ����ʱ
	{
		ton_timeout.Execute(true,Time_out);
		if (ton_timeout.GetQValue()) //��ʱ
		{
			cmdEx.is_timeout = (bool*)true;
			cmdEx.is_finish = (bool*)true;
			cmdExEnb = false;
			ton_timeout.Execute(false,Time_out);
			return;
		}
		//�ж��Ƿ���������Ӧ����
		if (client_sts.allow_read)
		{
			char read_data[256] = {0};
			int read_len = clientReadData(handle_,read_data);
			if (cmdEx.read_enb)
			{
				//�ж���Ӧ�����Ƿ�����
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
				//�ж���Ӧ�����Ƿ�����
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
	if (!client_sts.is_connected)		//��ͨѶ����״̬ʱ����ִ�����ں���
		return false;

	if (cmdExEnb == true)		//����ִ����,�������������ͨѶ����
	{
		return false;
	}
	if (cmd->read_enb)	//������ʱ��У�鳤��
	{
		if (cmd->data_len==0 || cmd->data_len>120)	//����У��
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

	//��������
	char send_data[256] = {0};
	int send_len = 0;
	if (cmdEx.read_enb)
		send_len = readDataGenerate(send_data);
	else
		send_len = writeDataGenerate(send_data);
	clientSendData(handle_,send_data,send_len);

	return true;
}

//�����ּĴ����������� ������03
int ModbusRTU::readDataGenerate( char *send_data )
{
	send_data[0] = station_id;					//��վ��ַ
	send_data[1] = 3;							//������
	send_data[2] = static_cast<char>(cmdEx.start_adress>>8);			//��ʼ��ַ��λ
	send_data[3] = static_cast<char>(cmdEx.start_adress & 0xff);		//��ʼ��ַ��λ
	send_data[4] = static_cast<char>(cmdEx.data_len>>8);				//���ݳ��ȸ�λ
	send_data[5] = static_cast<char>(cmdEx.data_len & 0xff);			//���ݳ��ȵ�λ

	unsigned int usCrc = Crc16((unsigned char *)send_data,6);	//CRCУ��
	send_data[6] = usCrc&0xFF;
	send_data[7] = (0xFF00 & usCrc)>>8;

	return 8;
}

//�������ݽ���
bool ModbusRTU::readReceiveData( int data_len,char *read_data )
{
	int len_ = cmdEx.data_len * 2 + 5;
	if (len_ != data_len)	//�����ܳ����ж�
		return false;

	if (cmdEx.data_len * 2 != read_data[2])	//�Ĵ��������ֽ����Ƚ�
		return false;

	if (read_data[0] != station_id)			//վ��ַУ��
		return false;

	if (read_data[1] != 3)					//������У��
		return false;

	//���ݽ���
	char * data_ = (char *)cmdEx.p_data;
	for (int i=0;i<cmdEx.data_len;i++)
	{
		*data_++ = read_data[4+2*i];
		*data_++ = read_data[3+2*i];
	}
	return true;
}

//д���ּĴ����������� ������06
int ModbusRTU::writeDataGenerate(char *send_data )
{
	send_data[0] = station_id;				//��վ��ַ
	send_data[1] = 6;						//������
	send_data[2] = static_cast<char>(cmdEx.start_adress>>8);			//��ʼ��ַ��λ
	send_data[3] = static_cast<char>(cmdEx.start_adress & 0xff);		//��ʼ��ַ��λ
	send_data[4] = *((char *)cmdEx.p_data + 1);				//���ݸ�λ
	send_data[5] = *((char *)cmdEx.p_data);					//���ݵ�λ

	unsigned int usCrc = Crc16((unsigned char *)send_data,6);	//CRCУ��
	send_data[6] = usCrc&0xFF;
	send_data[7] = (0xFF00 & usCrc)>>8;

	return 8;
}

//����д���ݷ��� ������������true,���򷵻�false
bool ModbusRTU::writeReceiveData( int data_len,char *read_data )
{
	if (8 != data_len)						//�����ܳ����ж�
		return false;

	if (read_data[0] != station_id)			//վ��ַУ��
		return false;

	if (read_data[1] != 6)					//������У��
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



