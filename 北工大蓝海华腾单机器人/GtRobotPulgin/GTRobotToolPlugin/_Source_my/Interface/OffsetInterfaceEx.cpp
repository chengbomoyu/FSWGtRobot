#include "_Source_my/Interface/OffsetInterfaceEx.h"
#include "_Source_my/Source/OffsetEx.h"
#include "_Source_my/Source/Manual.h"
#include "_Source_my/Source/SRI.h"


static OffsetEx *mOffsetEx = NULL;
static ManualOffset *mManualOffset = NULL;
static SRISensor *mSRISensor = NULL;

short BGDOffsetInit(){
	if(mOffsetEx == NULL) mOffsetEx = new OffsetEx();
	if(mManualOffset == NULL) mManualOffset = new ManualOffset();
	if(mSRISensor == NULL) mSRISensor = new SRISensor();
	mOffsetEx->mManualOffset = mManualOffset;
	mOffsetEx->mSRISensor = mSRISensor;
	return 0;
}
short BGDOffsetDeinit(){
	delete mOffsetEx;
	delete mManualOffset;
	delete mSRISensor;
	return 0;
}
short BGDOffsetVarRest(){
	mOffsetEx->OffsetParamaterRest();
	return 0;
}

short BGDOffsetStatusSet(bool status){
	mOffsetEx->OffsetStatusSet(status);
	return 0;
}

short BGDRreadOffsetSumY(double& value){
	mOffsetEx->GetOffsetSumY(value);
	return 0;
}

short BGDRreadOffsetSumZ(double& value){
	mOffsetEx->GetOffsetSumZ(value);
	return 0;
}

short BGDManualOffsetStatusSet(bool status){
	mManualOffset->ManOffsetStatus(status);
	return 0;
}

short BGDManualOffsetStepSet(double step){
	mManualOffset->ManualSetStep(step);
	return 0;
}

short BGDDoManOffsetY(short Dir){
	mManualOffset->ManSetOffsetY(Dir);
	return 0;
}

short BGDDoManOffsetZ(short Dir){
	mManualOffset->ManSetOffsetZ(Dir);
	return 0;
}

short BGDGetManOffsetSumY(double& value){
	mManualOffset->ManGetOffsetYSum(value);
	return 0;
}

short BGDGetManOffsetSumZ(double& value){
	mManualOffset->ManGetOffsetZSum(value);
}


short BGDSriConnectSet(bool status){
	if(status==true) mSRISensor->SriConnect();
	else             mSRISensor->SriDisconnect();
}

short BGDSriReadConnectStatus(short& status){
	mSRISensor->GetSriConnectStatus(status);
}

short BGDSriSetStatus(bool status){
}

short BGDSriSetAskStatus(bool status){
	mSRISensor->SetSriAskStatus(status);
}

short BGDSriSetZero(){
	mSRISensor->SetSriFzZero();
}

short BGDSriSetFz(double value){

}

short BGDReadSriFz(double& value){
}

short BGDRreadSriOffsetZ(double& value){
}


short BGDFswMartixUpdate(double Martix[][7]){
}


void BGDGetSriDataLoopRun(){
}

void BGDGetManOffDataLoopRun(){
}

void BGDDoOffsetLoopRun(){
}
