#include "Offset.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

Offset::Offset(){
	bStatusOnOff = false;
	dValueManOffsetStep = 0.1;

	bStatusSriConnect = false;
	rSriStatusConnect = 0;
	bStatusSriSet = false;
	bStatusPlaesrOffset = false;
	bStatusSriAsk = false;

	dValuePlaserValtageNow = 0; //点激光当前值
	dValuePlaserValtageSet = 0;	//点激光设定值

	dValueSetFz = 4500;

	for(int i = 0; i < 8; i++){
		dValueOffsetSum[i] = 0;
		RsiManOffsetAbsNow[i] = 0;
		RsiManOffsetAbsHistory[i] = 0;
		RsiManOffsetRela[i]= 0;
		RsiSriDataNow[i] = 0;
		RsiSriOffsetRela[i] = 0;
		RsiSriOffsetAbs[i] = 0;
		RsiPlaserOffsetRela[i];
	}
}

Offset::~Offset(){

}

void Offset::RsiStatusSet(){
	if(bStatusOnOff == true)
		GTR_SetOffsetOn(100,10,0);
	else
		GTR_SetOffsetOff(0);
}

double Offset::RsiRreadOffsetY(){
	return dValueOffsetSum[1];
}

double Offset::RsiRreadOffsetZ(){
	return dValueOffsetSum[2];
}

void Offset::RsiAskManOffset(){
	if(bStatusOnOff == true){
		RsiManOffsetRela[1] = RsiManOffsetAbsNow[1] - RsiManOffsetAbsHistory[1];
		RsiManOffsetRela[2] = RsiManOffsetAbsNow[2] - RsiManOffsetAbsHistory[2];
		RsiManOffsetAbsHistory[1] = RsiManOffsetAbsNow[1];
		RsiManOffsetAbsHistory[2] = RsiManOffsetAbsNow[2];
	}
	else{
		RsiManOffsetRela[1] = 0;
		RsiManOffsetRela[2] = 0;
	}
}

void Offset::RsiDoOffset(){
	double RSI_offset_rela[8] = {0};
	if(bStatusOnOff == true){
		RSI_offset_rela[1] = RsiManOffsetRela[1];
		RSI_offset_rela[2] = RsiManOffsetRela[2]+
						     RsiSriOffsetRela[2];
		GTR_SetOffsetRelativeValue(RSI_offset_rela, 0);
		dValueOffsetSum[1] = RsiManOffsetAbsNow[1];
		dValueOffsetSum[2] = RsiManOffsetAbsNow[2]+
							 RsiSriOffsetAbs[2]; 
		RsiSriOffsetAbs[2] = RsiSriOffsetAbs[2]+ 
			                 RsiSriOffsetRela[2];
	}
}

void Offset::RsiManOffsetY(short Dir){
	if(bStatusOnOff == true){
		if     (Dir == 0){RsiManOffsetAbsNow[1] = RsiManOffsetAbsNow[1] + dValueManOffsetStep;}
		else if(Dir == 1){RsiManOffsetAbsNow[1] = RsiManOffsetAbsNow[1] - dValueManOffsetStep;}
	}
	else{
	   RsiManOffsetAbsNow[1] = 0;
	}
}

void Offset::RsiManOffsetZ(short Dir){
	if(bStatusOnOff == true){
		if     (Dir == 0){RsiManOffsetAbsNow[2] = RsiManOffsetAbsNow[2] + dValueManOffsetStep;}
		else if(Dir == 1){RsiManOffsetAbsNow[2] = RsiManOffsetAbsNow[2] - dValueManOffsetStep;}
	}
	else{
	   RsiManOffsetAbsNow[2] = 0;
	}
}

void Offset::RsiSriConnect(){
	if(bStatusSriConnect == true){
		char *ip = "192.168.0.108";
		SriServerinfo.port = 4008;
		strcpy(SriServerinfo.ip,ip);
		SriTcpClient = CRobotComm::addTcpClient(&SriServerinfo);	
		CRobotComm::connectToServer(SriTcpClient);
	}
	else{
		CRobotComm::disConnectToServer(SriTcpClient);
		CRobotComm::removeTcpClient(SriTcpClient);
	}
}

void Offset::RsiReadSriConnectStatus(){
	CRobotComm::getTcpClientStatus(SriTcpClient,&SriTcpConnectStatus);
	if(SriTcpConnectStatus.is_connected == true)       rSriStatusConnect = 1;
	else if(SriTcpConnectStatus.is_connecting == true) rSriStatusConnect = 2;
	else                                    		   rSriStatusConnect = 0;
}

void Offset::RsiReadSriData(){              
	if(bStatusSriConnect == true && bStatusSriAsk == true){
		char SriOffsetAskCom[8] = { 0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A };
		CRobotComm::getTcpClientStatus(SriTcpClient,&SriTcpConnectStatus);
		if (SriTcpConnectStatus.is_connected){ 
			CRobotComm::clientSendData(SriTcpClient,SriOffsetAskCom,8);
		}
		if (SriTcpConnectStatus.allow_read){
			CRobotComm::clientReadData(SriTcpClient,SriRecvData);
			UINT dataint =0;
			dataint = (UCHAR)SriRecvData[17]<<24 | dataint;
			dataint = (UCHAR)SriRecvData[16]<<16 | dataint;
			dataint = (UCHAR)SriRecvData[15]<<8  | dataint;
			dataint = (UCHAR)SriRecvData[14]     | dataint;

			RsiSriDataNow[2] =  *((float*)(&dataint));
			RsiSriDataNow[2] = RsiSriDataNow[2] - RsiSriDataZero[2];
			RsiSriDataNow[2] = fabs(RsiSriDataNow[2]);
		}
	}
}

void Offset::RsiSriSetZero(){
	if(bStatusSriConnect == true){
		char SriOffsetAskCom[8] = { 0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A };
		CRobotComm::getTcpClientStatus(SriTcpClient,&SriTcpConnectStatus);
		if (SriTcpConnectStatus.is_connected){ 
			CRobotComm::clientSendData(SriTcpClient,SriOffsetAskCom,8);
		}
		if (SriTcpConnectStatus.allow_read){
			CRobotComm::clientReadData(SriTcpClient,SriRecvData);
			UINT dataint =0;
			dataint = (UCHAR)SriRecvData[17]<<24 | dataint;
			dataint = (UCHAR)SriRecvData[16]<<16 | dataint;
			dataint = (UCHAR)SriRecvData[15]<<8  | dataint;
			dataint = (UCHAR)SriRecvData[14]     | dataint;
			RsiSriDataZero[2] =  *((float*)(&dataint));
		}
	}
}


void Offset::RsiFswDoOffset(){
	if (bStatusSriSet == true && bStatusPlaesrOffset == true){  //点激光和六维力全生效，力位混合
		int temp1 = 0;
		int temp2 = 0;
		/*****************判断行*******************/
		if(dValuePlaserValtageNow > dValuePlaserValtageSet + 0.5) temp1 = 1;
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.5 && 
			    dValuePlaserValtageNow > dValuePlaserValtageSet + 0.1) temp1 = 3;
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.1 && 
			    dValuePlaserValtageNow > dValuePlaserValtageSet + 0) temp1 = 5;
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0 && 
			    dValuePlaserValtageNow > dValuePlaserValtageSet - 0.1) temp1 = 7;
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet - 0.1) temp1 = 9;
		else temp1 = 0;
		/*****************判断列*******************/
		if(RsiSriDataNow[2] > dValueSetFz + (dValueSetFz * 0.08)) temp2 = 1;
		else if(RsiSriDataNow[2] <= dValueSetFz + (dValueSetFz * 0.08) && 
		        RsiSriDataNow[2] > dValueSetFz + (dValueSetFz * 0.05)) temp2 = 2;
		else if(RsiSriDataNow[2] <= dValueSetFz + (dValueSetFz * 0.05) && 
			    RsiSriDataNow[2] > dValueSetFz + (dValueSetFz * 0)) temp2 = 3;
		else if(RsiSriDataNow[2] <= dValueSetFz + (dValueSetFz * 0) && 
			    RsiSriDataNow[2] > dValueSetFz - (dValueSetFz * 0.05)) temp2 = 4;
		else if(RsiSriDataNow[2] <= dValueSetFz - (dValueSetFz * 0.05) && 
			    RsiSriDataNow[2] > dValueSetFz - (dValueSetFz * 0.08)) temp2 = 5;
		else if(RsiSriDataNow[2] <= dValueSetFz - (dValueSetFz * 0.08)) temp2 = 6;
		else temp2 = 0;
		/*******************************************/
		RsiPlaserOffsetRela[2] = RsiFswMartix[temp1][temp2] * 0.01;
		RsiSriOffsetRela[2] = RsiFswMartix[temp1+1][temp2] * 0.01;
	}
	if(bStatusPlaesrOffset == true && bStatusSriSet == false){   //点激光生效，六维力不生效，位控
		int temp1 = 0;
		if(dValuePlaserValtageNow > dValuePlaserValtageSet + 0.5 && dValuePlaserValtageNow < 4.9)  temp1 = 1;//偏移目标位置上方0.5mm以上
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.5 &&                                    //在目标位置上方[0.1,0.5]mm范围之间
			    dValuePlaserValtageNow > dValuePlaserValtageSet + 0.1) temp1 = 3;
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.1 &&                                    //在目标位置上方[0,0.1]mm范围之间
			    dValuePlaserValtageNow > dValuePlaserValtageSet + 0) temp1 = 5;  
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0 &&                                      //在目标位置下方[-0.1,0]mm范围之间
			    dValuePlaserValtageNow > dValuePlaserValtageSet - 0.1) temp1 = 7;                         
		else if(dValuePlaserValtageNow <= dValuePlaserValtageSet - 0.1) temp1 = 9;                            //在目标位置下方-0.1,-5]mm以下
		else temp1 = 10;
		/*******************************************/
		RsiPlaserOffsetRela[2] = RsiFswMartix[temp1][1] * 0.01;
		RsiSriOffsetRela[2] = 0;
	}
	if(bStatusPlaesrOffset == false && bStatusSriSet == true){ //点激光不生效，六维力生效，力控
		int temp2=0;
		if(RsiSriDataNow[2] > dValueSetFz + (dValueSetFz * 0.08)) temp2 = 1;
		else if(RsiSriDataNow[2] <= dValueSetFz +(dValueSetFz * 0.08) && 
			RsiSriDataNow[2] > dValueSetFz +(dValueSetFz * 0.05)) temp2 = 2;
		else if(RsiSriDataNow[2] <= dValueSetFz +(dValueSetFz * 0.05) && 
			RsiSriDataNow[2] > dValueSetFz +(dValueSetFz * 0)) temp2 = 3;
		else if(RsiSriDataNow[2] <= dValueSetFz +(dValueSetFz * 0) && 
			RsiSriDataNow[2] > dValueSetFz -(dValueSetFz * 0.05)) temp2 = 4;
		else if(RsiSriDataNow[2] <= dValueSetFz -(dValueSetFz * 0.05) && 
			RsiSriDataNow[2] > dValueSetFz -(dValueSetFz * 0.08)) temp2 = 5;
		else if(RsiSriDataNow[2] <= dValueSetFz -(dValueSetFz * 0.08)) temp2 = 6;
		else temp2 = 0;
		/*******************************************/
		RsiSriOffsetRela[2] = RsiFswMartix[4][temp2] * 0.01; 
		RsiPlaserOffsetRela[2] = 0;
	}
	if (bStatusSriSet == false && bStatusPlaesrOffset == false){      
	   RsiSriOffsetRela[2] = 0;
	   RsiPlaserOffsetRela[2] = 0;
	}
}

     	 			
