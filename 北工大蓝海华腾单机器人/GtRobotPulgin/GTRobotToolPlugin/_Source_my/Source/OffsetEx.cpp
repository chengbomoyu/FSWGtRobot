#include "_Source_my/Source/OffsetEx.h"
#include "_Source_my/Source/Manual.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

OffsetEx::OffsetEx(){
	OffsetStatus= false;
	OffsetSumValue = new double[8];
	mManualOffset = new ManualOffset();
}

OffsetEx::~OffsetEx(){
	delete []OffsetSumValue;
	delete mManualOffset;
}

short OffsetEx::OffsetStatusSet(bool status){
	OffsetStatus = status;
	mManualOffset->ManualSetStatus(status);
	if(OffsetStatus == true)
		GTR_SetOffsetOn(100,10);
	else
		GTR_SetOffsetOff(0);
	return 0;
}

short OffsetEx::OffsetDoOffset(){
	double OffsetRela[8] = {0};
	if(OffsetStatus == true){
		OffsetRela[1] = mManualOffset->ManOffsetRela[1];
		OffsetRela[2] = mManualOffset->ManOffsetRela[2];
		GTR_SetOffsetRelativeValue(OffsetRela);
		OffsetSumValue[1] = mManualOffset->ManOffsetSumNow[1];
		OffsetSumValue[2] = mManualOffset->ManOffsetSumNow[2];
		mManualOffset->ManOffsetRela[1] = 0;
		mManualOffset->ManOffsetRela[2] = 0;
	}
	return 0;
}

short OffsetEx::OffsetParamaterRest(){
	for (int i=0;i<8;i++){
		OffsetSumValue[i] = 0;
	}
	mManualOffset->ManOffsetParameterReset();
	return 0;
}

short OffsetEx::GetOffsetSumY(double& value){
	value = OffsetSumValue[1];
	return 0;
}

short OffsetEx::GetOffsetSumZ(double& value){
	value = OffsetSumValue[2];
	return 0;
}

     	 			
