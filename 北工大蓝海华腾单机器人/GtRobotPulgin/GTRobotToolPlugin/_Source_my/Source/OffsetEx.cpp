#include "_Source_my/Source/OffsetEx.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

OffsetEx::OffsetEx(){
	OffsetSumValue = new double[8];

	mSRISensor = new SRISensor();
	mManualOffset = new ManualOffset();
}

OffsetEx::~OffsetEx(){
	delete []OffsetSumValue;
	delete mSRISensor;
	delete mManualOffset;
}

short OffsetEx::OffsetStatusSet(bool status){
	OffsetStatus = status;
	if(OffsetStatus == true)
		GTR_SetOffsetOn(100,10,0);
	else
		GTR_SetOffsetOff(0);
	return 0;
}

short OffsetEx::OffsetDoOffset(){
	double* RSI_offset_rela = new double[8]();
	if(OffsetStatus == true){
		GTR_SetOffsetRelativeValue(RSI_offset_rela, 0);
	}
	delete RSI_offset_rela;
	return 0;
}



     	 			
