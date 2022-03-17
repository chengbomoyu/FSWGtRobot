#include "_Source_my/Interface/OffsetInterfaceEx.h"
#include "_Source_my/Source/OffsetEx.h"
#include "_Source_my/Source/SRI.h"


OffsetEx *mOffsetEx = NULL;

short BGDOffsetInit(){
	if(mOffsetEx == NULL) mOffsetEx = new OffsetEx();
	return 0;
}
short BGDOffsetDeinit(){
	delete mOffsetEx;
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

short BGDManualOffsetStepSet(double step){
	mOffsetEx->mManualOffset->ManualSetStep(step);
	return 0;
}

short BGDDoManOffsetY(short Dir){
	mOffsetEx->mManualOffset->ManSetOffsetY(Dir);
	return 0;
}

short BGDDoManOffsetZ(short Dir){
	mOffsetEx->mManualOffset->ManSetOffsetZ(Dir);
	return 0;
}

short BGDGetManOffsetSumY(double& value){
	mOffsetEx->mManualOffset->ManGetOffsetYSum(value);
	return 0;
}

short BGDGetManOffsetSumZ(double& value){
	mOffsetEx->mManualOffset->ManGetOffsetZSum(value);
	return 0;
}

void BGDDoOffsetLoopRun(){
	mOffsetEx->OffsetDoOffset();
}
