#include "fsw_interface.h"
#include "CFSW.h"

static CFSW *mFSW = NULL;

void BR_RsiInit(){
	if(mFSW == NULL) mFSW = new CFSW();
}
void BR_RsiDeinit(){
	delete mFSW;
}
void BR_RsiZeroRest(){
	for(int i = 0; i < 8; i++){
		mFSW->dValueOffsetSum[i] = 0;
		mFSW->RsiManOffsetAbsNow[i] = 0;
		mFSW->RsiSriOffsetAbs[i] = 0;
	}
}
void BR_RsiSetStatus(bool status){
	mFSW->bStatusOnOff = status;
	mFSW->RsiStatusSet();
}
void BR_RsiSetAllow(bool status){
	mFSW->bStatusAllow = status;
}
double BR_RsiRreadOffsetY(){
	return mFSW->RsiRreadOffsetY();
}
double BR_RsiRreadOffsetZ(){
	return mFSW->RsiRreadOffsetZ();
}
void   BR_RsiSetCodefficient(int value){
	mFSW->dValueRsiSetCdefficient = value;
}
void BR_PlcLoopRun_DoOffset(){
	mFSW->RsiDoOffset();
}
void BR_RsiManSetStatus(bool status){
	mFSW->bStatusManSet = status;
}
void BR_RsiSetOffsetStep(double step){
	mFSW->dValueManOffsetStep = step;
}
void BR_RsiManOffsetY(short Dir){
	mFSW->RsiManOffsetY(Dir);
}
void BR_RsiManOffsetZ(short Dir){
	mFSW->RsiManOffsetZ(Dir);
}
double BR_RsiReadManOffsetY(){
	return mFSW->RsiManOffsetAbsNow[1];
}
double BR_RsiReadManOffsetZ(){
	return mFSW->RsiManOffsetAbsNow[2];
}
void BR_PlcLoopRun_AskManOffset(){
	mFSW->RsiAskManOffset();
}
void  BR_RsiSriConnect(bool status){
	mFSW->bStatusSriConnect = status;
	mFSW->RsiSriConnect();
} 
short BR_RsiSriReadConnectStatus(){
	mFSW->RsiReadSriConnectStatus();
	return mFSW->rSriStatusConnect;
}  
void BR_RsiSriSetStatus(bool status){
	mFSW->bStatusSriSet = status;
}
void BR_RsiSriSetAskStatus(bool status){
	mFSW->bStatusSriAsk = status;
}
void BR_RsiSriSetZero(){
	mFSW->RsiSriSetZero();
}
void BR_RsiSriSetFz(double value){
	mFSW->dValueSetFz = value;
}
double BR_RsiReadSriFx(){
	return mFSW->RsiSriDataNow[0];
}
double BR_RsiReadSriFy(){
	return mFSW->RsiSriDataNow[1];
}
double BR_RsiReadSriFz(){
	return mFSW->RsiSriDataNow[2];
}
double BR_RsiReadSriMx(){
	return mFSW->RsiSriDataNow[3];
}
double BR_RsiReadSriMy(){
	return mFSW->RsiSriDataNow[4];
}
double BR_RsiReadSriMz(){
	return mFSW->RsiSriDataNow[5];
}
double BR_RsiRreadSriOffsetZ(){
	return mFSW->RsiSriOffsetAbs[2];
} 
void BR_PlcLoopRun_AskSriData(){
	mFSW->RsiReadSriData();
}
void   BR_RsiPlaserConnect(bool status){
	mFSW->bStatusPlaserdaq = status;
}
void   BR_RsiPlaserSetStatus(bool status){
	mFSW->bStatusPlaesrOffset = status;
}
void   BR_RsiPlaerSetZero(double value){
	mFSW->dValuePlaserValtageSet = value;
}
void   BR_RsiPlaerSetThickness(double value){
	mFSW->dValuePlaserThickness = value;
}
double BR_RsiReadPlaser(){
	return mFSW->dValuePlaserValtageNow;
}
double BR_RsiRreadPlaerOffsetZ(){
	return mFSW->RsiPlaserOffsetAbs[2];
} 
void BR_PlcLoopRun_AskPlaserDate(){
	mFSW->RsiReadPlaserData();
}

void BR_PlcLoopRun_AskFswOffset(){
	mFSW->RsiFswDoOffset();
}
void BR_RsiFswMartixUpdate(double Martix[][7]){
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 7; j++){
			mFSW->RsiFswMartix[i][j] = Martix[i][j];
		}
	}
}
void bci_go_spindle_status_on(){
	mFSW->bj_spindle_servor_status(true);
}            	   
void bci_go_spindle_status_off(){
	mFSW->bj_spindle_servor_status(false);
}            	  
void bci_go_spindle_on(){
	mFSW->bj_spindle_power_control(true);
}                  	 
void bci_go_spindle_off(){
	mFSW->bj_spindle_power_control(false);
}                   	   
double bci_go_spindle_speed_real_get(){
	mFSW->bj_spindle_speed_real_get();
	return mFSW->bj_spindle_speed_real;
}     	  
void bci_go_spindle_speed_up100(){
	mFSW->bj_spindle_speed_control(100);
}          	   
void bci_go_spindle_speed_down100(){
	mFSW->bj_spindle_speed_control(-100);
}
void bci_go_spindle_speed_set(int speed){
	mFSW->bj_spindle_speed_quickset(speed);
}

bool BR_SynSpindleServo(){
	return mFSW->bj_spindle_status;
}
bool BR_SynSpindleOnOff(){
	return mFSW->bj_spindle_power;
}
bool BR_SynOffsetOnOff(){
	return mFSW->bStatusOnOff;
}
bool BR_SynForceOnOff(){
	return mFSW->bStatusSriSet;
}
int BR_SynSpindleRMP(){
	return mFSW->bj_spindle_speed_set;
}
int BR_SynForce(){
	return mFSW->dValueSetFz;
}