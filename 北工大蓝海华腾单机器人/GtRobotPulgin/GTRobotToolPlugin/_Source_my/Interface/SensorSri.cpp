#include "_Source_my/Interface/OffsetInterfaceEx.h"
#include "_Source_my/Source/OffsetEx.h"
#include "_Source_my/Source/Manual.h"
#include "_Source_my/Source/SRI.h"
#include "_Source_my/Interface/SensorSri.h"

SRISensor *mSRISensor = NULL;

short BGDSRIInit(){
	if(mSRISensor == NULL) mSRISensor = new SRISensor();
	return 0;
}
short BGDSRIDeinit(){
	delete mSRISensor;
	return 0;
}
short BGDSRIVarRest(){
	mSRISensor->SriParameterReset();
	return 0;
}

short BGDSriConnectSet(bool status){
	if(status==true) mSRISensor->SriConnect();
	else             mSRISensor->SriDisconnect();
	return 0;
}

short BGDSriReadConnectStatus(short& status){
	mSRISensor->GetSriConnectStatus(status);
	return 0;
}

short BGDSriSetAskStatus(bool status){
	mSRISensor->SetSriAskStatus(status);
	return 0;
}

short BGDSriSetZero(){
	mSRISensor->SetSriFzZero();
	return 0;
}

void BGDGetSriDataLoopRun(){
	mSRISensor->GetSriFzDataLoopRun();
}

short BGDReadSriFz(double& value){
	mSRISensor->GetSriFzData(value);
	return 0;
}