#include "_Source_my/Source/Spindle.h"
#include <QDebug>

#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "gtrobot_frontend_define.h"
#include "gtrobot_frontend_interface.h"

#pragma comment(lib,"GTRobotBackEndDll")
#pragma comment(lib,"GTRobotDll")

CvtSpindle::CvtSpindle(){
	SpindleType = 1;           //��������,0�̸����� 1��������
	SpindleStatus = 0;	       //�����ŷ�״̬,0���ŷ� 1���ŷ� 2���� 3�ر�
	SpindleComStatus = 0;      //����ͨѶ״̬,0δ���� 1��������
	SpindleSpeedSet = 0;       //�����趨�ٶ�
	SpindleSpeedReal = 0;      //����ʵʱ�ٶ�
	SpindleAccaccelation = -1; //������ٶ�
	SpindleDecelation = -1;	   //������ٶ�
	SpindleDirection = -1;       //���᷽��,-1��ʱ�� 0Ĭ��  1˳ʱ��

	CvtGetSpeedSModbusRtuCmdEx.is_finish = &CvtGetSpeedIsFinish;
	CvtGetSpeedSModbusRtuCmdEx.is_timeout = &CvtGetSpeedTimeout;
	CvtGetSpeedSModbusRtuCmdEx.read_enb = true;
	CvtGetSpeedSModbusRtuCmdEx.start_adress = 0x6006;
	CvtGetSpeedSModbusRtuCmdEx.data_len = 1;

	CvtSetSpeedSModbusRtuCmdEx.is_finish = &CvtSetSpeedIsFinish;
	CvtSetSpeedSModbusRtuCmdEx.is_timeout = &CvtGetSpeedTimeout;
	CvtSetSpeedSModbusRtuCmdEx.read_enb = false;
	CvtSetSpeedSModbusRtuCmdEx.start_adress = 0x8001;
	CvtSetSpeedSModbusRtuCmdEx.data_len = 1;

	CvtSetDirectionSModbusRtuCmdEx.is_finish = &CvtSetDirectionIsFinish;
	CvtSetDirectionSModbusRtuCmdEx.is_timeout = &CvtGetDirectionTimeout;
	CvtSetDirectionSModbusRtuCmdEx.read_enb = false;
	CvtSetDirectionSModbusRtuCmdEx.start_adress = 0x0101;
	CvtSetDirectionSModbusRtuCmdEx.data_len = 1;

	CvtSetStatusSModbusRtuCmdEx.is_finish = &CvtSetStatusIsFinish;
	CvtSetStatusSModbusRtuCmdEx.is_timeout = &CvtSetStatusTimeout;
	CvtSetStatusSModbusRtuCmdEx.read_enb = false;
	CvtSetStatusSModbusRtuCmdEx.start_adress = 0x8000;
	CvtSetStatusSModbusRtuCmdEx.data_len = 1;
}

CvtSpindle::~CvtSpindle(){
}

short CvtSpindle::SpindleConnect(){
	STcpServerInfo info;
	char* ip = "192.168.0.7";
	strcpy(info.ip,ip);
	info.port = 502;
	CvtModebusRtu.resinfo(&info,1);
	SpindleComStatus = 1;
	return 0;
}
short CvtSpindle::SpindleServorStatusSet(short mStatus){
	if(SpindleComStatus == 0){
		return 1;
	}
	else if(SpindleComStatus == 1){
		unsigned short data_on = 0x0001;
		unsigned short data_off = 0x0000;
		SpindleStatus = mStatus;
		if(SpindleStatus==2){  
			CvtSetDirectionSModbusRtuCmdEx.p_data = &data_on;
		}
		else if(SpindleStatus==3){//����ر�
			CvtSetDirectionSModbusRtuCmdEx.p_data = &data_off;
		}
		CvtModebusRtu.addCmdEx(&CvtSetDirectionSModbusRtuCmdEx);
		return 0;
	}
	return 0;
}

short CvtSpindle::SpindleGetRealSpeed(int& mRealSpeed){
	if(SpindleComStatus == 0){
		return 1;
	}
	else if(SpindleComStatus == 1){
		if(SpindleDirection == 1)
			SpindleSpeedReal = CvtSpindleModebusRtuSpeedReal * 10;
		else{
			SpindleSpeedReal = -(65536 - CvtSpindleModebusRtuSpeedReal) * 10;
			if (SpindleSpeedReal == -655360)
				SpindleSpeedReal = 0;
		}
		mRealSpeed = SpindleSpeedReal;
		CvtSpindleModebusRtuSpeedReal = 0x0001;
		CvtGetSpeedSModbusRtuCmdEx.p_data = &CvtSpindleModebusRtuSpeedReal;
		CvtModebusRtu.addCmdEx(&CvtGetSpeedSModbusRtuCmdEx);
		return 0;
	}
	return 0;
}

short CvtSpindle::SpindleSetSpeed(int mSetSpeed){
	if(SpindleComStatus == 0){
		return 1;
	}
	else if(SpindleComStatus == 1){
		unsigned short speed_hz = abs(mSetSpeed);
		SpindleSpeedSet=mSetSpeed;
		CvtSetSpeedSModbusRtuCmdEx.p_data = &speed_hz;
		CvtModebusRtu.addCmdEx(&CvtSetSpeedSModbusRtuCmdEx);

		if(SpindleSpeedSet<  0) SpindleSetDirection(0);
		if(SpindleSpeedSet>= 0)	SpindleSetDirection(1);

		return 0;
	}
	return 0;
}

short CvtSpindle::SpindleSetDirection(short mDirection){
	if(SpindleComStatus == 0){
		return 1;
	}
	else if(SpindleComStatus == 1){
		unsigned short data_right = 0x0000;
		unsigned short data_left = 0x0001;
		SpindleDirection = mDirection;
		if(SpindleDirection==1){ //˳ʱ����ת
			CvtSetDirectionSModbusRtuCmdEx.p_data = &data_right;
		} 
		else if(SpindleDirection==-1){//��ʱ����ת
			CvtSetDirectionSModbusRtuCmdEx.p_data = &data_left;
		}
		CvtModebusRtu.addCmdEx(&CvtSetDirectionSModbusRtuCmdEx);
		return 0;
	}
	return 0;
}