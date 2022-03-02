#include "_Source_my/Source/OffsetEx.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

OffsetEx::OffsetEx(){
	OffsetStatus= false;
	OffsetForceControlStatus = false;
	OffsetPointLaserControlStatus = false;

	OffsetSumValue = new double[8];
	SriOffsetRela = new double[8];
}

OffsetEx::~OffsetEx(){
	delete []OffsetSumValue;
	delete []SriOffsetRela;
}

short OffsetEx::OffsetStatusSet(bool status){
	OffsetStatus = status;
	if(OffsetStatus == true)
		GTR_SetOffsetOn(100,10,0);
	else
		GTR_SetOffsetOff(0);
	return 0;
}

short OffsetEx::OffsetForceControlStatusSet(bool status){
	OffsetForceControlStatus = status;
	return 0;
}

short OffsetEx::OffsetPointLaserControlStatusSet(bool status){
	OffsetPointLaserControlStatus = status;
	return 0;
}

short OffsetEx::OffsetDoOffset(){
	double* RSI_offset_rela = new double[8]();
	if(OffsetStatus == true){
		if (OffsetForceControlStatus == true && OffsetPointLaserControlStatus == true){  //�㼤�����ά��ȫ��Ч����λ���
			int temp1 = 0;
			int temp2 = 0;
			/*****************�ж���*******************/
			if(dValuePlaserValtageNow > dValuePlaserValtageSet + 0.5) temp1 = 1;
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.5 && 
				dValuePlaserValtageNow > dValuePlaserValtageSet + 0.1) temp1 = 3;
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.1 && 
				dValuePlaserValtageNow > dValuePlaserValtageSet + 0) temp1 = 5;
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0 && 
				dValuePlaserValtageNow > dValuePlaserValtageSet - 0.1) temp1 = 7;
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet - 0.1) temp1 = 9;
			else temp1 = 0;
			/*****************�ж���*******************/
			if(mSRISensor->SriDataNow[2] > dValueSetFz + (dValueSetFz * 0.08)) temp2 = 1;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz + (dValueSetFz * 0.08) && 
				mSRISensor->SriDataNow[2] > dValueSetFz + (dValueSetFz * 0.05)) temp2 = 2;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz + (dValueSetFz * 0.05) && 
				mSRISensor->SriDataNow[2] > dValueSetFz + (dValueSetFz * 0)) temp2 = 3;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz + (dValueSetFz * 0) && 
				mSRISensor->SriDataNow[2] > dValueSetFz - (dValueSetFz * 0.05)) temp2 = 4;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz - (dValueSetFz * 0.05) && 
				mSRISensor->SriDataNow[2] > dValueSetFz - (dValueSetFz * 0.08)) temp2 = 5;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz - (dValueSetFz * 0.08)) temp2 = 6;
			else temp2 = 0;
			/*******************************************/
			PointPlaserOffsetRela = FswOffsetMartix[temp1][temp2] * 0.01;
			SriOffsetRela[2] = FswOffsetMartix[temp1+1][temp2] * 0.01;
		}
		if(OffsetPointLaserControlStatus == true && OffsetForceControlStatus == false){   //�㼤����Ч����ά������Ч��λ��
			int temp1 = 0;
			if(dValuePlaserValtageNow > dValuePlaserValtageSet + 0.5 && dValuePlaserValtageNow < 4.9)  temp1 = 1;//ƫ��Ŀ��λ���Ϸ�0.5mm����
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.5 &&                                    //��Ŀ��λ���Ϸ�[0.1,0.5]mm��Χ֮��
				dValuePlaserValtageNow > dValuePlaserValtageSet + 0.1) temp1 = 3;
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0.1 &&                                    //��Ŀ��λ���Ϸ�[0,0.1]mm��Χ֮��
				dValuePlaserValtageNow > dValuePlaserValtageSet + 0) temp1 = 5;  
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet + 0 &&                                      //��Ŀ��λ���·�[-0.1,0]mm��Χ֮��
				dValuePlaserValtageNow > dValuePlaserValtageSet - 0.1) temp1 = 7;                         
			else if(dValuePlaserValtageNow <= dValuePlaserValtageSet - 0.1) temp1 = 9;                            //��Ŀ��λ���·�-0.1,-5]mm����
			else temp1 = 10;
			/*******************************************/
			PointPlaserOffsetRela = FswOffsetMartix[temp1][1] * 0.01;
			SriOffsetRela[2] = 0;
		}
		if(OffsetPointLaserControlStatus == false && OffsetForceControlStatus == true){ //�㼤�ⲻ��Ч����ά����Ч������
			int temp2=0;
			if(mSRISensor->SriDataNow[2] > dValueSetFz + (dValueSetFz * 0.08)) temp2 = 1;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz +(dValueSetFz * 0.08) && 
				mSRISensor->SriDataNow[2] > dValueSetFz +(dValueSetFz * 0.05)) temp2 = 2;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz +(dValueSetFz * 0.05) && 
				mSRISensor->SriDataNow[2] > dValueSetFz +(dValueSetFz * 0)) temp2 = 3;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz +(dValueSetFz * 0) && 
				mSRISensor->SriDataNow[2] > dValueSetFz -(dValueSetFz * 0.05)) temp2 = 4;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz -(dValueSetFz * 0.05) && 
				mSRISensor->SriDataNow[2] > dValueSetFz -(dValueSetFz * 0.08)) temp2 = 5;
			else if(mSRISensor->SriDataNow[2] <= dValueSetFz -(dValueSetFz * 0.08)) temp2 = 6;
			else temp2 = 0;
			/*******************************************/
			SriOffsetRela[2] = FswOffsetMartix[4][temp2] * 0.01; 
			PointPlaserOffsetRela = 0;
		}
		if (OffsetPointLaserControlStatus == false && OffsetForceControlStatus == false){      
			SriOffsetRela[2] = 0;
			PointPlaserOffsetRela = 0;
		}

		RSI_offset_rela[1] = mManualOffset->ManOffsetRela[1];
		RSI_offset_rela[2] = mManualOffset->ManOffsetRela[2] + SriOffsetRela[2];
		GTR_SetOffsetRelativeValue(RSI_offset_rela, 0);
	}
	delete []RSI_offset_rela;
	return 0;
}

short OffsetEx::OffsetParamaterRest(){
	for (int i=0;i<8;i++){
		OffsetSumValue[i] = 0;
	}
	mSRISensor->SriParameterReset();
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

     	 			
