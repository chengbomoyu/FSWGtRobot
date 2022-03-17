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
	mManualOffset->ManualSetStatus(status);
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
	return 0;
}


short BGDSriSetStatus(bool status){
	mOffsetEx->OffsetForceControlStatusSet(status);
	return 0;
}


short BGDSriSetFz(double value){
	mOffsetEx->dValueSetFz = value;
	return 0;
}



short BGDRreadSriOffsetZ(double& value){
	value = 0;
	return 0;
}

short BGDFswMartixUpdate(double Martix[][7]){
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 7; j++){
			mOffsetEx->FswOffsetMartix[i][j] = Martix[i][j];
		}
	}
	return 0;
}

void BGDDoOffsetLoopRun(){
	mOffsetEx->OffsetDoOffset();
}
