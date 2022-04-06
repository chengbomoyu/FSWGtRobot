#include "_Source_my/Source/FSW.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

FSW::FSW(){
	ForceControlStatus = false;
	PointLaserControlStatus = false;

	dValueSetFz = 0;
	dValuePlaserValtageSet = 0;
	
	tempdValuePlaserValtageNow = 0;

	FswOffsetMartix = new double *[11];
	for(int i = 0; i< 11; i++){
		FswOffsetMartix[i] = new double[7];
	}
	/***************************************************************************************************************/
	/*-------------------------------------------------------------------------------------------------------------*/
	/*|-----------ForeSri|[+100%,+008%)||[+008%,+005%)||(+005%,+000%)||(+000%,-005%]||(-005%,-008%]||(-008%,-100%]|*/
	/*|PointLaser--------|*************||*************||*************||*************||*************||*************|*/
	/*|(+  ∞,+0.5)-------|(+0.80,+0.00)||(+0.80,+0.00)||(+0.80,+0.00)||(+0.80,+0.00)||(+0.80,+0.00)||(+0.80,+0.00)|*/
	/*|(+0.5,+0.1)-------|(+0.20,-0.50)||(+0.20,-0.30)||(+0.20,+0.00)||(+0.20,+0.00)||(+0.20,+0.10)||(+0.20,+0.15)|*/
	/*|(+0.1,+0.0)-------|(+0.00,-0.50)||(+0.00,-0.30)||(+0.00,+0.00)||(+0.00,+0.00)||(+0.00,+0.15)||(+0.00,+0.20)|*/
	/*|(+0.0,-0.1)-------|(+0.00,-0.50)||(+0.00,-0.30)||(+0.00,+0.00)||(+0.00,+0.00)||(+0.00,+0.20)||(+0.00,+0.25)|*/
	/*|(-0.1,-  ∞)-------|(-1.00,+0.00)||(-1.00,+0.00)||(-1.00,+0.00)||(-1.00,+0.00)||(-1.00,+0.00)||(-1.00,+0.00)|*/
	/*-------------------------------------------------------------------------------------------------------------*/
    /*Note:--------------------------------------------------------------------------------------------------------*/
	/*FswOffsetMartix[(Laser,Force)]-------------------------------------------------------------------------------*/
	/*(+  ∞,+0.5)---------([1,1] [2,1])||([1,2] [2,2])||([1,3] [2,3])||([1,4] [2,4])||([1,5] [2,5])||([1,6] [2,6]|)*/
	/*-------------------------------------------------------------------------------------------------------------*/
	/***************************************************************************************************************/
	FswOffsetMartix[1][1] = 0.8;
	FswOffsetMartix[1][2] = 0.8;
	FswOffsetMartix[1][3] = 0.8;
	FswOffsetMartix[1][4] = 0.8;
	FswOffsetMartix[1][5] = 0.8;
	FswOffsetMartix[1][6] = 0.8;
	/********************************************/
	FswOffsetMartix[3][1] = 0.2;FswOffsetMartix[4][1] = -0.5;
	FswOffsetMartix[3][2] = 0.2;FswOffsetMartix[4][2] = -0.3;
	FswOffsetMartix[3][3] = 0.2;FswOffsetMartix[4][3] = 0;
	FswOffsetMartix[3][4] = 0.2;FswOffsetMartix[4][4] = 0;
	FswOffsetMartix[3][5] = 0.2;FswOffsetMartix[4][5] = 0.1;
	FswOffsetMartix[3][6] = 0.2;FswOffsetMartix[4][6] = 0.15;
	/********************************************/
	FswOffsetMartix[5][1] = 0;FswOffsetMartix[6][1] = -0.5;
	FswOffsetMartix[5][2] = 0;FswOffsetMartix[6][2] = -0.3;
	FswOffsetMartix[5][3] = 0;FswOffsetMartix[6][3] = 0;
	FswOffsetMartix[5][4] = 0;FswOffsetMartix[6][4] = 0;
	FswOffsetMartix[5][5] = 0;FswOffsetMartix[6][5] = 0.15;
	FswOffsetMartix[5][6] = 0;FswOffsetMartix[6][6] = 0.2;
	/********************************************/
	FswOffsetMartix[7][1] = 0;FswOffsetMartix[8][1] = -0.5;
	FswOffsetMartix[7][2] = 0;FswOffsetMartix[8][2] = -0.3;
	FswOffsetMartix[7][3] = 0;FswOffsetMartix[8][3] = 0;
	FswOffsetMartix[7][4] = 0;FswOffsetMartix[8][4] = 0;
	FswOffsetMartix[7][5] = 0;FswOffsetMartix[8][5] = 0.2;
	FswOffsetMartix[7][6] = 0;FswOffsetMartix[8][6] = 0.25;
	/********************************************/
	FswOffsetMartix[9][1] = -1;
	FswOffsetMartix[9][2] = -1;
	FswOffsetMartix[9][3] = -1;
	FswOffsetMartix[9][4] = -1;
	FswOffsetMartix[9][5] = -1;
	FswOffsetMartix[9][6] = -1;
	/********************************************/
}

FSW::~FSW(){
	for (int i = 0; i< 11; i++){
		delete []FswOffsetMartix[i];
	}
	delete []FswOffsetMartix;
}

short FSW::ForceControlStatusSet(bool status){
	ForceControlStatus = status;
	return 0;
}

short FSW::PointLaserControlStatusSet(bool status){
	PointLaserControlStatus = status;
	return 0;
}

short FSW::FswControlComputeOnlyForce(){
	/****************************************************************************************************/
	/*--------------------------------------------------------------------------------------------------*/
	/*|ForeSri|[+100%,+008%)||[+008%,+005%)||(+005%,+000%)||(+000%,-005%]||(-005%,-008%]||(-008%,-100%]|*/
	/*|-------|***(-0.50)***||***(-0.30)***||***(+0.00)***||***(+0.00)***||***(+0.10)***||***(+0.15)***|*/
	/*--------------------------------------------------------------------------------------------------*/
	/****************************************************************************************************/
	double SRIFZ;
	BGDReadSriFz(SRIFZ);
	if(ForceControlStatus == true){
		if(SRIFZ > dValueSetFz + (dValueSetFz * 0.08)) 
			ForceOffsetRela = -0.5 * ForceControlRatio;
		else if(SRIFZ <= dValueSetFz +(dValueSetFz * 0.08) && 
			    SRIFZ >  dValueSetFz +(dValueSetFz * 0.05)) 
			ForceOffsetRela = -0.3 * ForceControlRatio;
		else if(SRIFZ <= dValueSetFz +(dValueSetFz * 0.05) && 
			    SRIFZ >  dValueSetFz +(dValueSetFz * 0)) 
			ForceOffsetRela = 0 * ForceControlRatio;
		else if(SRIFZ <= dValueSetFz +(dValueSetFz * 0) && 
			    SRIFZ >  dValueSetFz -(dValueSetFz * 0.05)) 
			ForceOffsetRela = 0 * ForceControlRatio;
		else if(SRIFZ <= dValueSetFz -(dValueSetFz * 0.05) && 
			    SRIFZ >  dValueSetFz -(dValueSetFz * 0.08)) 
			ForceOffsetRela = 0.1 * ForceControlRatio;
		else if(SRIFZ <= dValueSetFz -(dValueSetFz * 0.08)) 
			ForceOffsetRela = 0.15 * ForceControlRatio;
		else 
			ForceOffsetRela = 0;
	}
	PointPlaserOffsetRela = 0;
	FswOffsetRelaData = ForceOffsetRela + PointPlaserOffsetRela;
	return 0;
}
short FSW::FswControlComputeOnlyLaser(){
	/****************************************************************************************/
	/*--------------------------------------------------------------------------------------*/
	/*|LaserPoint|[+   ∞,+0.50)||[+0.50,+0.10)||(+0.10,+0.00)||(+0.00,-0.10]||(-0.10,-   ∞]|*/
	/*|----------|***(+0.80)***||***(+0.20)***||***(+0.00)***||***(+0.00)***||***(-1.00)***|*/
	/*--------------------------------------------------------------------------------------*/
	/****************************************************************************************/
	if(PointLaserControlStatus == true){
		if(tempdValuePlaserValtageNow > dValuePlaserValtageSet + 0.5)
			PointPlaserOffsetRela = 0.8 * LaserPointControlRatio;             //偏移目标位置上方0.5mm以上
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet + 0.5 && //在目标位置上方[0.1,0.5]mm范围之间
			tempdValuePlaserValtageNow > dValuePlaserValtageSet + 0.1) 
			PointPlaserOffsetRela = 0.2 * LaserPointControlRatio;
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet + 0.1 && //在目标位置上方[0,0.1]mm范围之间
			tempdValuePlaserValtageNow > dValuePlaserValtageSet + 0) 
			PointPlaserOffsetRela = 0 * LaserPointControlRatio;  
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet + 0 &&   //在目标位置下方[-0.1,0]mm范围之间
			tempdValuePlaserValtageNow > dValuePlaserValtageSet - 0.1) 
			PointPlaserOffsetRela = 0 * LaserPointControlRatio;                         
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet - 0.1) 
			PointPlaserOffsetRela = -1 * LaserPointControlRatio;              //在目标位置下方-0.1,-∞]mm以下
		else 
			PointPlaserOffsetRela = 0;
	}
	ForceOffsetRela = 0;
	FswOffsetRelaData = ForceOffsetRela + PointPlaserOffsetRela;
	return 0;
}
short FSW::FswControlCompute(){
	double SRIFZ;
	BGDReadSriFz(SRIFZ);
	if (ForceControlStatus == true && PointLaserControlStatus == true){  //点激光和六维力全生效，力位混合
		int temp1 = 0;
		int temp2 = 0;
		/*****************判断行*******************/
		if(tempdValuePlaserValtageNow > dValuePlaserValtageSet + 0.5) 
			temp1 = 1;
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet + 0.5 && 
			    tempdValuePlaserValtageNow > dValuePlaserValtageSet + 0.1) 
			temp1 = 3;
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet + 0.1 && 
				tempdValuePlaserValtageNow > dValuePlaserValtageSet + 0) 
			temp1 = 5;
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet + 0 && 
				tempdValuePlaserValtageNow > dValuePlaserValtageSet - 0.1) 
			temp1 = 7;
		else if(tempdValuePlaserValtageNow <= dValuePlaserValtageSet - 0.1) 
			temp1 = 9;
		else 
			temp1 = 0;
		/*****************判断列*******************/
		if(SRIFZ > dValueSetFz + (dValueSetFz * 0.08)) 
			temp2 = 1;
		else if(SRIFZ <= dValueSetFz + (dValueSetFz * 0.08) && 
			    SRIFZ > dValueSetFz + (dValueSetFz * 0.05)) 
			temp2 = 2;
		else if(SRIFZ <= dValueSetFz + (dValueSetFz * 0.05) && 
			    SRIFZ > dValueSetFz + (dValueSetFz * 0)) 
			temp2 = 3;
		else if(SRIFZ <= dValueSetFz + (dValueSetFz * 0) && 
			    SRIFZ > dValueSetFz - (dValueSetFz * 0.05)) 
			temp2 = 4;
		else if(SRIFZ <= dValueSetFz - (dValueSetFz * 0.05) && 
			    SRIFZ > dValueSetFz - (dValueSetFz * 0.08)) 
			temp2 = 5;
		else if(SRIFZ <= dValueSetFz - (dValueSetFz * 0.08))
			temp2 = 6;
		else 
			temp2 = 0;
		/*******************************************/
		PointPlaserOffsetRela = FswOffsetMartix[temp1][temp2] * LaserPointControlRatio;
		ForceOffsetRela = FswOffsetMartix[temp1+1][temp2] * ForceControlRatio;
	}
	if (ForceControlStatus == false && PointLaserControlStatus == false){      
		ForceOffsetRela = 0;
		PointPlaserOffsetRela = 0;
	}
	FswOffsetRelaData = ForceOffsetRela + PointPlaserOffsetRela;
	return 0;
}
short FSW::FswControlResults(double &FswOffsetData){
	FswOffsetData = FswOffsetRelaData;
	return 0;
}
short FSW::FswTecParamaterRest(){
	return 0;
}
     	 			
