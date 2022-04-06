#include "_Source_my/Source/FSW.h"

static FSW *mFSW = NULL;

short BGDFswInit(){
	if(mFSW == NULL) mFSW = new FSW();
	return 0;
}
short BGDFswDeinit(){
	delete mFSW;
	return 0;
}
short BGDFswVarRest(){
	mFSW->FswTecParamaterRest();
	return 0;
}

short BGDForceControlSetStatus(bool status){
	mFSW->ForceControlStatusSet(status);
	return 0;
}

short BGDPointLaserControlSetStatus(bool status){
	mFSW->PointLaserControlStatusSet(status);
	return 0;
}
short BGDForceControlSetFz(double value){
	mFSW->dValueSetFz = value;
	return 0;
}
short BGDPointLaserSetVoltage(double value){
	mFSW->dValuePlaserValtageSet = value;
	return 0;
}
short BGDFswOffsetDataGet(double& data){
	mFSW->FswControlCompute();
	mFSW->FswControlResults(data);
	return 0;
}
short BGDRreadFswOffsetZ(double& value){
	mFSW->FswControlResults(value);
	return 0;
}