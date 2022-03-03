#include "_Source_my/Source/SRI.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

SRISensor::SRISensor(){
	MeasuringDepthNow = 0;
	RecvRawData = new char[32];   //SRI接收到的原始数据
	SriDataZero = new float[6];   //SRI传感器的零点
	SriDataNow = new float[6];    //SRI转换后的数据
	SriDataHistory = new float[MEASURINGDEPTH];
}

SRISensor::~SRISensor(){
	delete []RecvRawData;
	delete []SriDataNow;
	delete []SriDataZero;
	delete []SriDataHistory;
}

short SRISensor::SriConnect(){
	char *ip = "192.168.0.108";
	SriSensorServerinfo.port = 4008;
	strcpy(SriSensorServerinfo.ip,ip);
	GtRobotTcpClient = CRobotComm::addTcpClient(&SriSensorServerinfo);	
	CRobotComm::connectToServer(GtRobotTcpClient);
	return 0;
}

short SRISensor::SriDisconnect(){
	CRobotComm::disConnectToServer(GtRobotTcpClient);
	CRobotComm::removeTcpClient(GtRobotTcpClient);
	return 0;
}

short SRISensor::GetSriClientStatus(short& status){
	CRobotComm::getTcpClientStatus(GtRobotTcpClient,&SriGtRobotStatus);
	if(SriGtRobotStatus.is_connected == true)       status = 1;
	else if(SriGtRobotStatus.is_connecting == true) status = 2;
	else                                    		status = 0;
	return 0;
}

short  SRISensor::GetSriConnectStatus(short& status){
	if(SriGtRobotStatus.is_connected == true){
		if(AskStatus == true){
			SriDataHistory[MeasuringDepthNow] = SriDataNow[2];
			if(MeasuringDepthNow >= (MEASURINGDEPTH-1)){
				int tempcount = 0;
				for(int i = 0;i < MEASURINGDEPTH;i++){
					if(SriDataHistory[0] == SriDataHistory[i+1]) tempcount++;
				}
				if(tempcount == (MEASURINGDEPTH-1)) SriServerStatus = ERROR;
				else           SriServerStatus = 1;
				MeasuringDepthNow = 0;
			}
			else{
				MeasuringDepthNow = MeasuringDepthNow + 1;
				SriServerStatus = NORMAL;
			}
		}
		else{SriServerStatus = DISDAQ;}
	}
	else{ SriServerStatus = DISCONNECT; }
	status = SriServerStatus;
	return 0;
}

short SRISensor::SetSriFzZero(){
	char SriOffsetAskCom[8] = {0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A};
	if (SriGtRobotStatus.is_connected){ 
		CRobotComm::clientSendData(GtRobotTcpClient,SriOffsetAskCom,8);
	}
	if (SriGtRobotStatus.allow_read){
		CRobotComm::clientReadData(GtRobotTcpClient,RecvRawData);
		UINT dataint =0;
		dataint = (UCHAR)RecvRawData[17]<<24 | dataint;
		dataint = (UCHAR)RecvRawData[16]<<16 | dataint;
		dataint = (UCHAR)RecvRawData[15]<<8  | dataint;
		dataint = (UCHAR)RecvRawData[14]     | dataint;
		SriDataZero[2] =  *((float*)(&dataint));
	}
	return 0;
}

short SRISensor::GetSriFzData(double& value){   
	value = SriDataNow[2];
	return 0;
}

short SRISensor::GetSriFzDataLoopRun(){
	char SriOffsetAskCom[8] ={ 0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A };
	if(AskStatus == true){
		if (SriGtRobotStatus.is_connected){ 
			CRobotComm::clientSendData(GtRobotTcpClient,SriOffsetAskCom,8);
		}
		if (SriGtRobotStatus.allow_read){
			CRobotComm::clientReadData(GtRobotTcpClient,RecvRawData);
			UINT dataint =0;
			dataint = (UCHAR)RecvRawData[17]<<24 | dataint;
			dataint = (UCHAR)RecvRawData[16]<<16 | dataint;
			dataint = (UCHAR)RecvRawData[15]<<8  | dataint;
			dataint = (UCHAR)RecvRawData[14]     | dataint;

			SriDataNow[2] =  *((float*)(&dataint));
			SriDataNow[2] = SriDataNow[2] - SriDataZero[2];
			SriDataNow[2] = fabs(SriDataNow[2]);
		}
	}
	return 0;
}

short SRISensor::SriParameterReset(){
	for (int i=0;i<8;i++){
		SriDataZero[i] = 0;
		SriDataNow[i] = 0;
	}
	for(int i=0;i<32;i++){
		RecvRawData[i] = 0;
	}
	for(int i=0;i<MEASURINGDEPTH;i++){
		SriDataHistory[i] = 0;
	}
	return 0;
}

short SRISensor::SetSriAskStatus(bool status){
	AskStatus = status;
	return 0;
}