#include "_Source_my/Source/Manual.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

ManualOffset::ManualOffset(){
	ManOffsetStatus = false;
	ManOffsetSumNow = new double[8];    //手动本周期总和[8]
	ManOffsetSumLast = new double[8];   //手动前周期总和[8]
	ManOffsetRela = new double[8];      //本周期偏移的量[8]
	ManOffsetStep = 0.1;
}

ManualOffset::~ManualOffset(){
	delete []ManOffsetSumNow;
	delete []ManOffsetSumLast;
	delete []ManOffsetRela;
}

short ManualOffset::ManualSetStatus(bool status){
	ManOffsetStatus = status;
	return 0;
}


short ManualOffset::ManSetOffsetY(short Dir){
	if(ManOffsetStatus == true){
		if     (Dir == 0){ManOffsetSumNow[1] = ManOffsetSumNow[1] + ManOffsetStep;}
		else if(Dir == 1){ManOffsetSumNow[1] = ManOffsetSumNow[1] - ManOffsetStep;}
		ManOffsetRela[1] = ManOffsetSumNow[1] - ManOffsetSumLast[1];
		ManOffsetSumLast[1] = ManOffsetSumNow[1];
	}
	else{
	   ManOffsetSumNow[1] = 0;
	   ManOffsetRela[1] = 0;
	}
	return 0;
}

short ManualOffset::ManSetOffsetZ(short Dir){
	if(ManOffsetStatus == true){
		if     (Dir == 0){ManOffsetSumNow[2] = ManOffsetSumNow[2] + ManOffsetStep;}
		else if(Dir == 1){ManOffsetSumNow[2] = ManOffsetSumNow[2] - ManOffsetStep;}
		ManOffsetRela[2] = ManOffsetSumNow[2] - ManOffsetSumLast[2];
		ManOffsetSumLast[2] = ManOffsetSumNow[2];
	}
	else{
		ManOffsetSumNow[2] = 0;
		ManOffsetRela[2] = 0;
	}
	return 0;
}
short  ManualOffset::ManOffsetTransmitDone(){
	ManOffsetRela[1] = 0;
	ManOffsetRela[2] = 0;
	return 0;
}
short  ManualOffset::ManGetOffsetYSum(double& value){
	value = ManOffsetSumNow[1];
	return 0;
}

short  ManualOffset::ManGetOffsetZSum(double& value){
	value = ManOffsetSumNow[2];
	return 0;
}

short ManualOffset::ManOffsetParameterReset(){
	for (int i=0;i<8;i++){
		ManOffsetSumNow[i] = 0;
		ManOffsetSumLast[i] = 0;
		ManOffsetRela[i] = 0;
	}
	return 0;
}

short   ManualOffset::ManualSetStep(double step){
	ManOffsetStep = step;
	return 0;
}	
