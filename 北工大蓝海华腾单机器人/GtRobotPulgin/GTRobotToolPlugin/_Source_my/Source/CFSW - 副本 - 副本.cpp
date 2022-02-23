#include "CFSW.h"
#include <QDebug>
#include <QDateTime>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

CFSW::CFSW(){
	bStatusOnOff = false;
	bStatusAllow = false;

	bStatusManSet = false;
	dValueManOffsetStep = 0.1;

	bStatusSriConnect = false;
	rSriStatusConnect = 0;
	bStatusSriSet = false;
	bStatusSriAsk = false;

	dValueRsiSetCdefficient = 200;
	dValueSetFz = 4500;

	bStatusPlaserdaq = true;    //点激光采集状态
	bStatusPlaesrOffset = false; //点激光调整状态
	dValuePlaserValtageNow = 0;  //点激光读取电压
	dValuePlaserValtageSet = 1.2;//点激光设定电压1.2V
	dValuePlaserThickness = 0;

	RsiSriDataNowFliterA = 0.65;

	RsiSriDataFliterN = 0;
	RsiSriDataFliterSum = 0;
	temDataInt = 0;
	temValueFz = 0;
	temRsiSriData = 0;

	for(int i = 0; i < 8; i++){
		dValueOffsetSum[i] = 0;
		RsiManOffsetAbsNow[i] = 0;
		RsiManOffsetAbsHistory[i] = 0;
		RsiManOffsetRela[i]= 0;
		RsiSriDataNow[i] = 0;
		RsiSriOffsetRela[i] = 0;
		RsiSriOffsetAbs[i] = 0;
		RsiPlaserOffsetRela[i] = 0;
		RsiPlaserOffsetAbs[i] = 0;
		RsiSriDataNowFliter[i] = 0;
	}

	bj_spindle_status=false;	           
	bj_spindle_power=false;	           
	bj_spindle_speed_set=0;             //换算单位：6°/s = r/min(默认单位°/s)	
	bj_spindle_speed_real=0;
	bj_spindle_accaccelation=600;	    //换算单位：1°/s2 = 10r/min2 (默认单位°/s2)  
	bj_spindle_decelation=600;	   
	bj_spindle_direction=1; 	   
	bj_spindle_num=8; 	
}

CFSW::~CFSW(){

}

void CFSW::RsiStatusSet(){
	if(bStatusOnOff == true)
		GTR_SetOffsetOn(dValueRsiSetCdefficient,10,0);
	else
		GTR_SetOffsetOff(0);
}

double CFSW::RsiRreadOffsetY(){
	return dValueOffsetSum[1];
}

double CFSW::RsiRreadOffsetZ(){
	return dValueOffsetSum[2];
}

void CFSW::RsiAskManOffset(){
	if(bStatusManSet == true){
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

void CFSW::RsiDoOffset(){
	double RSI_offset_rela[8] = {0};
	if(bStatusAllow == true){
		/*Y偏差*/
		RSI_offset_rela[1] = RsiManOffsetRela[1];
		/*Z偏差*/
		RSI_offset_rela[2] = RsiManOffsetRela[2]+
						     RsiSriOffsetRela[2]+
							 RsiPlaserOffsetRela[2];
		GTR_SetOffsetRelativeValue(RSI_offset_rela, 0);
		
		dValueOffsetSum[1] = RsiManOffsetAbsNow[1];
		dValueOffsetSum[2] = RsiManOffsetAbsNow[2]+
							 RsiSriOffsetAbs[2]+ 
							 RsiPlaserOffsetAbs[2];

		RsiPlaserOffsetAbs[2] = RsiPlaserOffsetAbs[2]+RsiPlaserOffsetRela[2];
		RsiSriOffsetAbs[2]    = RsiSriOffsetAbs[2]   + RsiSriOffsetRela[2]  ;
	}
}

void CFSW::RsiManOffsetY(short Dir){
	if(bStatusManSet == true){
		if(Dir == 0){
			RsiManOffsetAbsNow[1] = RsiManOffsetAbsNow[1]+
								    dValueManOffsetStep;
		}
		else if(Dir ==1){
			RsiManOffsetAbsNow[1] = RsiManOffsetAbsNow[1]- 
							        dValueManOffsetStep;
		}
	}
	else{
	   RsiManOffsetAbsNow[1]=0;
	}
}

void CFSW::RsiManOffsetZ(short Dir){
	if(bStatusManSet == true){
		if(Dir == 0){
			RsiManOffsetAbsNow[2] = RsiManOffsetAbsNow[2]+ 
									dValueManOffsetStep;
		}
		else if(Dir ==1){
			RsiManOffsetAbsNow[2] = RsiManOffsetAbsNow[2]- 
									dValueManOffsetStep;
		}
	}
	else{
	   RsiManOffsetAbsNow[2]=0;
	}
}

void CFSW::RsiSriConnect(){
	if(bStatusSriConnect == true){
		char *ip = "192.168.0.108";
		SriServerinfo.port = 4008;
		strcpy(SriServerinfo.ip,ip);
		SriTcpClient = CRobotComm::addTcpClient(&SriServerinfo);	//添加TCP连接
		CRobotComm::connectToServer(SriTcpClient);
	}
	else{
		CRobotComm::disConnectToServer(SriTcpClient);
		CRobotComm::removeTcpClient(SriTcpClient);
	}
}

void CFSW::RsiReadSriConnectStatus(){
		CRobotComm::getTcpClientStatus(SriTcpClient,&SriTcpConnectStatus);
		if(SriTcpConnectStatus.is_connected == true){
			rSriStatusConnect = 1;
		}
		else if(SriTcpConnectStatus.is_connecting == true){
			rSriStatusConnect =  2;
		}
		else
			rSriStatusConnect =  0;
}

void CFSW::RsiReadSriData(){              //操作步骤先按零点标定再进行问询
	if(bStatusSriConnect == true && bStatusSriAsk == true){
		char SriOffsetAskCom[8] = { 0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A };
		CRobotComm::getTcpClientStatus(SriTcpClient,&SriTcpConnectStatus);
		if (SriTcpConnectStatus.is_connected){ //TODO  客户端已经连接上，允许写数据
			CRobotComm::clientSendData(SriTcpClient,SriOffsetAskCom,8);
		}
		if (SriTcpConnectStatus.allow_read){//TODO  接收到服务端发送来的数据，允许读
			CRobotComm::clientReadData(SriTcpClient,SriRecvData);
			temDataInt =0;
			temDataInt = (UCHAR)SriRecvData[17]<<24 | temDataInt;
			temDataInt = (UCHAR)SriRecvData[16]<<16 | temDataInt;
			temDataInt = (UCHAR)SriRecvData[15]<<8  | temDataInt;
			temDataInt = (UCHAR)SriRecvData[14]     | temDataInt;

			temValueFz =  *((float*)(&temDataInt));
			temValueFz = temValueFz - RsiSriDataZero[2];
			
			temRsiSriData = 0;
			temRsiSriData = fabs(temValueFz);
			temRsiSriData = RsiSriDataNowFliterA * temRsiSriData + (1-RsiSriDataNowFliterA) * RsiSriDataNowFliter[2];
			RsiSriDataNowFliter[2] = temRsiSriData;

			RsiSriDataFliterSum = RsiSriDataFliterSum + RsiSriDataNowFliter[2];
			
			RsiSriDataFliterN = RsiSriDataFliterN + 1;
			if(RsiSriDataFliterN==8){
				RsiSriDataNow[2] = (RsiSriDataFliterSum / RsiSriDataFliterN) - 3;
				RsiSriDataFliterSum = 0;
				RsiSriDataFliterN = 0;
			}
		}
	}
}

void CFSW::RsiSriSetZero(){
	if(bStatusSriConnect == true){
		char SriOffsetAskCom[8] = { 0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A };
		CRobotComm::getTcpClientStatus(SriTcpClient,&SriTcpConnectStatus);
		if (SriTcpConnectStatus.is_connected){ //TODO  客户端已经连接上，允许写数据
			CRobotComm::clientSendData(SriTcpClient,SriOffsetAskCom,8);
		}
		if (SriTcpConnectStatus.allow_read){//TODO  接收到服务端发送来的数据，允许读
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

void CFSW::RsiReadPlaserData(){
	if(bStatusPlaserdaq == true){
		GTR_GetAiValue(dValuePlaserValtageNow,0,1);
	}
}

void CFSW::RsiFswDoOffset(){
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
		RsiSriOffsetRela[2] = RsiFswMartix[4][temp2] * 0.01; //可能会有缺陷
		RsiPlaserOffsetRela[2] = 0;
	}
	if (bStatusSriSet == false && bStatusPlaesrOffset == false){      
	   RsiSriOffsetRela[2] = 0;
	   RsiPlaserOffsetRela[2] = 0;
	}
}

void CFSW::bj_spindle_servor_status(bool servor_status){
	if(servor_status==true){          //主轴伺服开启
		bj_spindle_status=true;
		GTR_HmiAxisServoOn(bj_spindle_num);
	}
	if(servor_status==false){         //主轴伺服关闭
		bj_spindle_status=false;
		bj_spindle_speed_set=0;
		bj_spindle_direction=1;
		GTR_HmiAxisServoOff(bj_spindle_num);
	}

}  	 			 
void CFSW::bj_spindle_power_control(bool power){
	if(power==true){  
		bj_spindle_power=true;                       //主轴开启
		if(bj_spindle_status==true){
			GTR_SetHmiAxisVelocity(bj_spindle_num,6*bj_spindle_speed_set*bj_spindle_direction);
			GTR_SetHmiAxisAcceleration(bj_spindle_num,bj_spindle_accaccelation);
			GTR_HmiAxisStart(bj_spindle_num);
		}
	}
	else if(power==false){                           //主轴关闭
		bj_spindle_power=false;
		GTR_SetHmiAxisVelocity(bj_spindle_num,0);
		GTR_SetHmiAxisDeceleration(bj_spindle_num,bj_spindle_decelation);
		GTR_HmiAxisStop(bj_spindle_num);
	}

}          	 			
void CFSW::bj_spindle_speed_real_get(){
	GTR_GetHmiAxisVelocity(bj_spindle_num,bj_spindle_speed_real);
}                                    
void CFSW::bj_spindle_speed_control(int speed_addnum){
	bj_spindle_speed_set= bj_spindle_speed_set+speed_addnum;
	if(bj_spindle_speed_set<=0){
		if(bj_spindle_speed_set<=-5500)  bj_spindle_speed_set=-5500;
	}  
	if(bj_spindle_speed_set>=0){
		if(bj_spindle_speed_set>=5500)  bj_spindle_speed_set=5500;
	}
	if(bj_spindle_status==true&&bj_spindle_power==true){
		GTR_SetHmiAxisAcceleration(bj_spindle_num,bj_spindle_accaccelation);
		GTR_SetHmiAxisVelocity(bj_spindle_num,bj_spindle_speed_set*bj_spindle_direction*6);
		GTR_HmiAxisStart(bj_spindle_num);
	}

}

void CFSW::bj_spindle_speed_quickset(int speed){
	bj_spindle_speed_set = speed;
	if(bj_spindle_speed_set<=0){
		if(bj_spindle_speed_set<=-5500)  bj_spindle_speed_set=-5500;
	}  
	if(bj_spindle_speed_set>=0){
		if(bj_spindle_speed_set>=5500)  bj_spindle_speed_set=5500;
	}
	if(bj_spindle_status==true&&bj_spindle_power==true){
		GTR_SetHmiAxisAcceleration(bj_spindle_num,bj_spindle_accaccelation);
		GTR_SetHmiAxisVelocity(bj_spindle_num,bj_spindle_speed_set*bj_spindle_direction*6);
		GTR_HmiAxisStart(bj_spindle_num);
	}

}