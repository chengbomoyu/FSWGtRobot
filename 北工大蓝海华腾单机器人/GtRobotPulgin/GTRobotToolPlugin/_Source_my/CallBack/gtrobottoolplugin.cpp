#include "qstring.h"

#include <QIODevice>
#include <QKeyEvent>

#include "gtrobottoolplugin.h"
#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "plc_standard_class.h"
#include "comm_struct_define.h"
#include "robot_comm_interface.h"

#include "_Source_my/Interface/SpindleInterface.h"
#include "_Source_my/Interface/OffsetInterface.h"
#include "_Source_my/Interface/OffsetInterfaceEx.h"

FSW::FSW(QWidget *parent){
	ui.setupUi(this);
	this->FSWHmiVarInit(); //HMI�����ĳ�ʼ��
 
	ConnectSpindleSignalSlots(); //���ӵ�����ۺ���
	ConnectOffsetSignalSlots();	 //���Ӷ�̬ƫ�Ʋۺ���
	
	BGDOffsetInit();                  //��̬ƫ�Ƶĳ�ʼ��
	BGDCvtSpindleInit();              //������ĳ�ʼ��

	BGDFswMartixUpdate(hmi_fwsmartix);//����ϵ������
	
	RegisterPLCLoopRun();             //ע��PLCѭ������
}

FSW::~FSW(){
	BGDOffsetDeinit();    //���ն�̬ƫ�Ƶ��ڴ�
	BGDCvtSpindleDeInit();//���յ�������ڴ�
}
void FSW::FSWHmiVarInit(){
	this->SpindleSpeedSet = 0;//�趨������ת��
	this->SpindleSpeedGet = 0;//��ȡ������ת��
	this->SpindleGetStatus = 0;//��ȡ������״̬
	this->SpindleSetStatus = 0;//�趨������״̬

	this->OffsetStatus = 0;   //����״̬
	this->OffsetSumY = 0;     //����Y����
	this->OffsetSumZ = 0;     //����Z����

	this->OffsetManSumY = 0;  //�ֶ�����Y����
	this->OffsetManSumZ = 0;  //�ֶ�����Z����
	this->OffsetManStep = 0;  //�ֶ���������

	this->SriConnectSetStatus = false; //����״̬   0�ر����� 1��������
	this->SriAskStatus = false;        //�Ƿ�����ѯ
	this->SriOffsetStatus = false;     //������״̬   0�ر����� 1��������
	this->SriConnectStatusNow = 0;     //��ѯ����״̬

	this->SriCorrectSumZ = 0;      //����Z������������
	this->SriFzNow = 0;            //��ǰ�Ķ�����
	this->SriFzSet = 4500;         //�趨�Ķ�����

	/********************************************/
	hmi_fwsmartix[1][1] = 0.8;
	hmi_fwsmartix[1][2] = 0.8;
	hmi_fwsmartix[1][3] = 0.8;
	hmi_fwsmartix[1][4] = 0.8;
	hmi_fwsmartix[1][5] = 0.8;
	hmi_fwsmartix[1][6] = 0.8;
	/********************************************/
	hmi_fwsmartix[3][1] = 0.2;
	hmi_fwsmartix[3][2] = 0.2;
	hmi_fwsmartix[3][3] = 0.2;
	hmi_fwsmartix[3][4] = 0.2;
	hmi_fwsmartix[3][5] = 0.2;
	hmi_fwsmartix[3][6] = 0.2;
	/********************************************/
	hmi_fwsmartix[4][1] = -0.5;
	hmi_fwsmartix[4][2] = -0.3;
	hmi_fwsmartix[4][3] = 0;
	hmi_fwsmartix[4][4] = 0;
	hmi_fwsmartix[4][5] = 0.1;
	hmi_fwsmartix[4][6] = 0.15;
	/********************************************/
	hmi_fwsmartix[5][1] = 0;
	hmi_fwsmartix[5][2] = 0;
	hmi_fwsmartix[5][3] = 0;
	hmi_fwsmartix[5][4] = 0;
	hmi_fwsmartix[5][5] = 0;
	hmi_fwsmartix[5][6] = 0;
	/********************************************/
	hmi_fwsmartix[6][1] = -0.5;
	hmi_fwsmartix[6][2] = -0.3;
	hmi_fwsmartix[6][3] = 0;
	hmi_fwsmartix[6][4] = 0;
	hmi_fwsmartix[6][5] = 0.15;
	hmi_fwsmartix[6][6] = 0.2;
	/********************************************/
	hmi_fwsmartix[7][1] = 0;
	hmi_fwsmartix[7][2] = 0;
	hmi_fwsmartix[7][3] = 0;
	hmi_fwsmartix[7][4] = 0;
	hmi_fwsmartix[7][5] = 0;
	hmi_fwsmartix[7][6] = 0;
	/********************************************/
	hmi_fwsmartix[8][1] = -0.5;
	hmi_fwsmartix[8][2] = -0.3;
	hmi_fwsmartix[8][3] = 0;
	hmi_fwsmartix[8][4] = 0;
	hmi_fwsmartix[8][5] = 0.2;
	hmi_fwsmartix[8][6] = 0.25;
	/********************************************/
	hmi_fwsmartix[9][1] = -1;
	hmi_fwsmartix[9][2] = -1;
	hmi_fwsmartix[9][3] = -1;
	hmi_fwsmartix[9][4] = -1;
	hmi_fwsmartix[9][5] = -1;
	hmi_fwsmartix[9][6] = -1;
	/********************************************/
}
void FSW::keyPressEvent(QKeyEvent *event){
	switch(event->key()){
		case Qt::Key_A:
			if(OffsetStatus==true)
				BGDDoManOffsetY(1);
			break;
		case Qt::Key_S:
			if(OffsetStatus==true)
				BGDDoManOffsetY(0);
			break;
		case Qt::Key_Z:
			if(OffsetStatus==true)
				BGDDoManOffsetZ(0);
			break;
		case Qt::Key_X:
			if(OffsetStatus==true)
				BGDDoManOffsetZ(1);
			break;
		case Qt::Key_7:
			SriFzSet = SriFzSet + 100;
			BGDSriSetFz(SriFzSet);
			break;
		case Qt::Key_4:
			SriFzSet = SriFzSet - 100;
			if(SriFzSet <= 0) SriFzSet = 0;
			BGDSriSetFz(SriFzSet);	
			break;
		case Qt::Key_0:
			OffsetManStep = OffsetManStep - 0.1;
			if(OffsetManStep <= 0) OffsetManStep = 0;
			BGDManualOffsetStepSet(OffsetManStep);
			break;
		case Qt::Key_1:
			OffsetManStep = OffsetManStep + 0.1;
			BGDManualOffsetStepSet(OffsetManStep);
			break;
		case Qt::Key_8:
			this->SpindleSpeedSet = SpindleSpeedSet + 100;
			BGDCvtSpindleSetSpeed(SpindleSpeedSet);
			break;
		case Qt::Key_5:
			this->SpindleSpeedSet = SpindleSpeedSet - 100;
			BGDCvtSpindleSetSpeed(SpindleSpeedSet);
			break;
	}
}
void FSW::RegisterPLCLoopRun(){
	GTR_RegisterPlcLoop(1,BGDCvtSpindleModebusLoopRun);
	GTR_RegisterPlcLoop(2,BGDGetSriDataLoopRun);
	GTR_RegisterPlcLoop(3,BGDDoOffsetLoopRun);
}

void FSW::ConnectSpindleSignalSlots(){
	connect(ui.pbSpindleConnect,SIGNAL(clicked()),this,SLOT(onpbpbSpindleConnect()));
	connect(ui.mpushbutton_spindle_on,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_on()));
	connect(ui.mpushbutton_spindle_off,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_off()));
	connect(ui.mpushbutton_spindle_speed_up100,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_speed_up100()));
	connect(ui.mpushbutton_spindle_speed_down100,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_speed_down100()));
}

void FSW::ConnectOffsetSignalSlots(){
	connect(ui.checkbox_rsi_on,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_checkbox_rsi_on()));
	connect(ui.checkbox_rsi_off,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_checkbox_rsi_off()));
	
	connect(ui.mpushbutton_rsi_man_step_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_step_up()));
	connect(ui.mpushbutton_rsi_man_step_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_step_down()));
	connect(ui.mpushbutton_rsi_man_y_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_y_up()));
	connect(ui.mpushbutton_rsi_man_y_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_y_down()));
	connect(ui.mpushbutton_rsi_man_z_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_z_up()));
	connect(ui.mpushbutton_rsi_man_z_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_z_down()));

	connect(ui.mcheckbox_sri_connect,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_connect()));
	connect(ui.mcheckbox_sri_disconnect,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_disconnect()));
	connect(ui.mcheckbox_sri_status_on,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_status_on()));
	connect(ui.mcheckbox_sri_status_off,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sir_status_off()));
	connect(ui.mcheckbox_sri_ask,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_ask()));
	connect(ui.mcheckbox_sri_stop,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_stop()));
	connect(ui.mpushbutton_sri_zero,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_sri_zero()));

	connect(ui.mpushbutton_sri_fzsetting_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_sri_fzsetting_up()));
	connect(ui.mpushbutton_sri_fzsetting_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_sri_fzsetting_down()));
}
bool FSW::showFrame(){
	this->show();
	return true;
}
bool FSW::hideFrame(){
	this->hide();
	return true;
}
void FSW::SlowTimerLoop(){
}

void FSW::FastTimerLoop(){
	GetSpindleParameters();
	GetOffsetParameters();
}
void FSW::GetSpindleParameters(){
	BGDCvtSpindleGetSpeed(SpindleSpeedGet);
	SpindleSpeedSet = SpindleSpeedSet;
	SpindleGetStatus = SpindleSetStatus;
	
	switch(SpindleGetStatus){
		case 0:	break;
		case 1:	break;
		case 2:	ui.mlabel_spindle_status->setText("����"); break;
		case 3:	ui.mlabel_spindle_status->setText("�ر�"); break;
	}
	ui.mlcdnumber_spindle_set->display(SpindleSpeedSet);
	ui.mlcdnumber_spindle_real->display(SpindleSpeedGet);
}
void FSW::GetOffsetParameters(){
	BGDRreadOffsetSumY(OffsetSumY);
	BGDRreadOffsetSumZ(OffsetSumZ);
	BGDGetManOffsetSumY(OffsetManSumY);
	BGDGetManOffsetSumZ(OffsetManSumZ);
	BGDRreadSriOffsetZ(SriCorrectSumZ);
	BGDSriReadConnectStatus(SriConnectStatusNow);
	BGDReadSriFz(SriFzNow);
	SriFzSet = SriFzSet;

	//0δ����1����2�쳣3δ�ɼ�
	switch (SriConnectStatusNow){
		case 0:	 ui.mlabel_sri_status_connect->setText("δ����");	 break;
		case 1:  ui.mlabel_sri_status_connect->setText("�ɼ���");	 break;
		case 2:  ui.mlabel_sri_status_connect->setText("�쳣��");    break;
		case 3:  ui.mlabel_sri_status_connect->setText("δ�ɼ�");	 break;
		default: ui.mlabel_sri_status_connect->setText("����");     break;

	}
	ui.mlcdnumber_sri_Fz->display(SriFzNow);
	ui.mlcdnumber_sri_fzsetting->display(SriFzSet);
	ui.lcdnumber_rsi_dy->display(OffsetSumY);
	ui.lcdnumber_rsi_dz->display(0-OffsetSumZ);
	ui.mlcdnumber_rsi_man_sum_z->display(0-OffsetManSumZ);
	ui.mlcdnumber_rsi_man_sum_y->display(OffsetManSumY);
	ui.mlcdnumber_sri_correct_sum_z->display(0-SriCorrectSumZ);
	ui.mlcdnumber_rsi_man_step->display(OffsetManStep);
}

QString FSW::getFrameName(){
	return "FSW";
}
QString FSW::getVersion(){
	return "v1.0.0";
}

bool FSW::readLastTimeStatus(){
	return true;
}

bool FSW::saveLastTimeStatus(){
	return true;
}

void FSW::setPermission(short type){
}

void FSW::onpbpbSpindleConnect(){
	BGDCvtSpindleConnect();
}
void FSW::onpbtnclicked_mpushbutton_spindle_on(){
	SpindleSetStatus = SPINDLE_ON;
	BGDCvtSpindleStatusSet(SpindleSetStatus);
}
void FSW::onpbtnclicked_mpushbutton_spindle_off(){
	SpindleSetStatus = SPINDLE_OFF;
	BGDCvtSpindleStatusSet(SpindleSetStatus);
}
void FSW::onpbtnclicked_mpushbutton_spindle_speed_up100(){
	SpindleSpeedSet = SpindleSpeedSet+SPINDLE_SPEED_STEP;
	BGDCvtSpindleSetSpeed(SpindleSpeedSet);
}
void FSW::onpbtnclicked_mpushbutton_spindle_speed_down100(){
	SpindleSpeedSet = SpindleSpeedSet-SPINDLE_SPEED_STEP;
	BGDCvtSpindleSetSpeed(SpindleSpeedSet);
}
void FSW::oncheckboxclicked_checkbox_rsi_on(){
	OffsetStatus = STATUS_ON;

	ui.checkbox_rsi_off->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_status_on->setEnabled(true);
	ui.mcheckbox_sri_status_off->setEnabled(true);
	ui.mpushbutton_rsi_man_y_up->setEnabled(true);
	ui.mpushbutton_rsi_man_y_down->setEnabled(true);
	ui.mpushbutton_rsi_man_z_up->setEnabled(true);
	ui.mpushbutton_rsi_man_z_down->setEnabled(true);

	BGDOffsetVarRest();
	BGDOffsetStatusSet(STATUS_ON);
	BGDManualOffsetStatusSet(STATUS_ON);
}

void FSW::oncheckboxclicked_checkbox_rsi_off(){
	OffsetStatus = STATUS_OFF;

	ui.checkbox_rsi_on->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_status_on->setEnabled(false);
	ui.mcheckbox_sri_status_off->setEnabled(false);
	ui.mpushbutton_rsi_man_y_up->setEnabled(false);
	ui.mpushbutton_rsi_man_y_down->setEnabled(false);
	ui.mpushbutton_rsi_man_z_up->setEnabled(false);
	ui.mpushbutton_rsi_man_z_down->setEnabled(false);

	BGDOffsetStatusSet(STATUS_OFF);
	BGDManualOffsetStatusSet(STATUS_OFF);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_step_up(){
	OffsetManStep = OffsetManStep + MAN_OFFSET_MINS_TEP;
	BGDManualOffsetStepSet(OffsetManStep);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_step_down(){
	OffsetManStep = OffsetManStep - MAN_OFFSET_MINS_TEP;
	if(OffsetManStep <= 0) OffsetManStep = 0;
	BGDManualOffsetStepSet(OffsetManStep);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_y_up(){
	BGDDoManOffsetY(MAN_OFFSET_PD);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_y_down(){	
	BGDDoManOffsetY(MAN_OFFSET_ND);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_z_up(){
	BGDDoManOffsetZ(MAN_OFFSET_PD);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_z_down(){
	BGDDoManOffsetZ(MAN_OFFSET_ND);
}

void FSW::oncheckboxclicked_mcheckbox_sri_connect(){
	SriConnectSetStatus = STATUS_ON;
	ui.mcheckbox_sri_disconnect->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_ask->setEnabled(true);
	ui.mcheckbox_sri_stop->setEnabled(true);
	BGDSriConnectSet(STATUS_ON);
}
void FSW::oncheckboxclicked_mcheckbox_sri_disconnect(){
	SriConnectSetStatus = STATUS_OFF;
	ui.mcheckbox_sri_connect->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_ask->setEnabled(false);
	ui.mcheckbox_sri_stop->setEnabled(false);
	BGDSriConnectSet(STATUS_OFF);
}
void FSW::onpbtnclicked_mpushbutton_sri_zero(){
	BGDSriSetZero();
}
void FSW::oncheckboxclicked_mcheckbox_sri_ask(){
	SriAskStatus = STATUS_ON;
	ui.mcheckbox_sri_stop->setCheckState(Qt::Unchecked);
	BGDSriSetAskStatus(STATUS_ON);
}
void FSW::oncheckboxclicked_mcheckbox_sri_stop(){
	SriAskStatus = STATUS_OFF;
	ui.mcheckbox_sri_ask->setCheckState(Qt::Unchecked);
	BGDSriSetAskStatus(STATUS_OFF);
}
void FSW::oncheckboxclicked_mcheckbox_sri_status_on(){
	SriOffsetStatus = STATUS_ON;
	ui.mcheckbox_sri_status_off->setCheckState(Qt::Unchecked);
	BGDSriSetStatus(STATUS_ON);
}
void FSW::oncheckboxclicked_mcheckbox_sir_status_off(){
	SriOffsetStatus = STATUS_OFF;
	ui.mcheckbox_sri_status_on->setCheckState(Qt::Unchecked);
	BGDSriSetStatus(STATUS_OFF);
}

void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_up(){
	SriFzSet = SriFzSet + FORCE_CTRL_MIN_STEP;
	BGDSriSetFz(SriFzSet);
}
void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_down(){
	SriFzSet = SriFzSet - FORCE_CTRL_MIN_STEP;
	if(SriFzSet <= 0) SriFzSet = 0;
	BGDSriSetFz(SriFzSet);
}

Q_EXPORT_PLUGIN2("RobotHmi",FSW);