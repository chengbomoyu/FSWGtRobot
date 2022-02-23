#include "_Source_my/Interface/OffsetInterface.h"
#include "_Source_my/Source/Offset.h"

static Offset *mOffset = NULL;

void BR_RsiInit(){
	if(mOffset == NULL) mOffset = new Offset();
}
void BR_RsiDeinit(){
	delete mOffset;
}
void BR_RsiVarRest(){
	for(int i = 0; i < 8; i++){
		mOffset->dValueOffsetSum[i] = 0;
		mOffset->RsiManOffsetAbsNow[i] = 0;
		mOffset->RsiSriOffsetAbs[i] = 0;
	}
}
void BR_RsiSetStatus(bool status){
	mOffset->bStatusOnOff = status;
	mOffset->RsiStatusSet();
}
double BR_RsiRreadOffsetY(){
	return mOffset->RsiRreadOffsetY();
}
double BR_RsiRreadOffsetZ(){
	return mOffset->RsiRreadOffsetZ();
}

void BR_RsiSetOffsetStep(double step){
	mOffset->dValueManOffsetStep = step;
}
void BR_RsiManOffsetY(short Dir){
	mOffset->RsiManOffsetY(Dir);
}
void BR_RsiManOffsetZ(short Dir){
	mOffset->RsiManOffsetZ(Dir);
}
double BR_RsiReadManOffsetY(){
	return mOffset->RsiManOffsetAbsNow[1];
}
double BR_RsiReadManOffsetZ(){
	return mOffset->RsiManOffsetAbsNow[2];
}

void  BR_RsiSriConnect(bool status){
	mOffset->bStatusSriConnect = status;
	mOffset->RsiSriConnect();
} 

short BR_RsiSriReadConnectStatus(){
	mOffset->RsiReadSriConnectStatus();
	return mOffset->rSriStatusConnect;
}

void BR_RsiSriSetStatus(bool status){
	mOffset->bStatusSriSet = status;
}
void BR_RsiSriSetAskStatus(bool status){
	mOffset->bStatusSriAsk = status;
}
void BR_RsiSriSetZero(){
	mOffset->RsiSriSetZero();
}
void BR_RsiSriSetFz(double value){
	mOffset->dValueSetFz = value;
}

double BR_RsiReadSriFz(){
	return mOffset->RsiSriDataNow[2];
}
double BR_RsiRreadSriOffsetZ(){
	return mOffset->RsiSriOffsetAbs[2];
} 

void BR_RsiFswMartixUpdate(double Martix[][7]){
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 7; j++){
			mOffset->RsiFswMartix[i][j] = Martix[i][j];
		}
	}
}

void BR_PlcLoopRun_AskSriData(){
	mOffset->RsiReadSriData();
}

void BR_PlcLoopRun_AskFswOffset(){
	mOffset->RsiFswDoOffset();
}
void BR_PlcLoopRun_DoOffset(){
	mOffset->RsiDoOffset();
}
void BR_PlcLoopRun_AskManOffset(){
	mOffset->RsiAskManOffset();
}
