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

FSW::FSW(QWidget *parent){
	ui.setupUi(this);
	BR_RsiInit();
	BGDCvtSpindleInit();
	FSWHmiVarInit();
	
	ConnectSpindleSignalSlots();
	ConnectOffsetSignalSlots();
	BR_RsiFswMartixUpdate(hmi_fwsmartix);

	RegisterPLCLoopRun();
}
FSW::~FSW(){
	BR_RsiDeinit();
	BGDCvtSpindleDeInit();
}
void FSW::FSWHmiVarInit(){
	SpindleSpeedSet = 0;//设定的主轴转速
	SpindleSpeedGet = 0;//获取的主轴转速
	SpindleGetStatus = 0;//获取的主轴状态
	SpindleSetStatus = 0;//设定的主轴状态

	OffsetSumY = 0;     //修正Y总量
	OffsetSumZ = 0;     //修正Z总量
	OffsetStatus = 0;   //修正状态

	OffsetManSumY = 0;  //手动修正Y总量
	OffsetManSumZ = 0;  //手动修正Z总量
	OffsetManStep = 0;  //手动修正步距

	SriCorrectSumZ = 0;      //力控Z方向修正总量
	SriFzNow = 0;                 //当前的顶锻力
	SriFzSet = 4500;           //设定的顶锻力
	hmi_sri_status = false;         //修正状态   0关闭修正 1开启修正
	hmi_sri_connect_status = false; //连接状态   0关闭连接 1开启连接
	hmi_sri_ask_status = false;     //是否开启问询
	SriConnectStatusNow = 0; //问询连接状态

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
				BR_RsiManOffsetY(1);
			break;
		case Qt::Key_S:
			if(OffsetStatus==true)
				BR_RsiManOffsetY(0);
			break;
		case Qt::Key_Z:
			if(OffsetStatus==true)
				BR_RsiManOffsetZ(0);
			break;
		case Qt::Key_X:
			if(OffsetStatus==true)
				BR_RsiManOffsetZ(1);
			break;
		case Qt::Key_7:
			SriFzSet = SriFzSet + 100;
			BR_RsiSriSetFz(SriFzSet);
			break;
		case Qt::Key_4:
			SriFzSet = SriFzSet - 100;
			if(SriFzSet <= 0) SriFzSet = 0;
			BR_RsiSriSetFz(SriFzSet);	
			break;
		case Qt::Key_0:
			OffsetManStep = OffsetManStep - 0.1;
			if(OffsetManStep <= 0) OffsetManStep = 0;
			BR_RsiSetOffsetStep(OffsetManStep);
			break;
		case Qt::Key_1:
			OffsetManStep = OffsetManStep + 0.1;
			BR_RsiSetOffsetStep(OffsetManStep);
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
	GTR_RegisterPlcLoop(2,BR_PlcLoopRun_AskSriData);
	GTR_RegisterPlcLoop(3,BR_PlcLoopRun_AskManOffset);
	GTR_RegisterPlcLoop(4,BR_PlcLoopRun_AskFswOffset);
	GTR_RegisterPlcLoop(5,BR_PlcLoopRun_DoOffset);
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
		case 2:	ui.mlabel_spindle_status->setText("开启"); break;
		case 3:	ui.mlabel_spindle_status->setText("关闭"); break;
	}
	ui.mlcdnumber_spindle_set->display(SpindleSpeedSet);
	ui.mlcdnumber_spindle_real->display(SpindleSpeedGet);
}
void FSW::GetOffsetParameters(){
	OffsetSumZ = BR_RsiRreadOffsetZ();
	OffsetSumY = BR_RsiRreadOffsetY();
	OffsetManSumY =  BR_RsiReadManOffsetY();
	OffsetManSumZ =  BR_RsiReadManOffsetZ();
	SriCorrectSumZ = BR_RsiRreadSriOffsetZ();
	SriConnectStatusNow = BR_RsiSriReadConnectStatus();
	SriFzNow = BR_RsiReadSriFz();
	SriFzSet = SriFzSet;

	switch (SriConnectStatusNow){
		case 1:  ui.mlabel_sri_status_connect->setText("已连接");	 break;
		case 2:  ui.mlabel_sri_status_connect->setText("正在连接"); break;
		default: ui.mlabel_sri_status_connect->setText("未连接");   break;
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
	SpindleSetStatus = 2;
	BGDCvtSpindleStatusSet(SpindleSetStatus);
}
void FSW::onpbtnclicked_mpushbutton_spindle_off(){
	SpindleSetStatus = 3;
	BGDCvtSpindleStatusSet(SpindleSetStatus);
}
void FSW::onpbtnclicked_mpushbutton_spindle_speed_up100(){
	SpindleSpeedSet = SpindleSpeedSet+100;
	BGDCvtSpindleSetSpeed(SpindleSpeedSet);
}
void FSW::onpbtnclicked_mpushbutton_spindle_speed_down100(){
	SpindleSpeedSet = SpindleSpeedSet-100;
	BGDCvtSpindleSetSpeed(SpindleSpeedSet);
}
void FSW::oncheckboxclicked_checkbox_rsi_on(){
	OffsetStatus = true;

	ui.checkbox_rsi_off->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_status_on->setEnabled(true);
	ui.mcheckbox_sri_status_off->setEnabled(true);
	ui.mpushbutton_rsi_man_y_up->setEnabled(true);
	ui.mpushbutton_rsi_man_y_down->setEnabled(true);
	ui.mpushbutton_rsi_man_z_up->setEnabled(true);
	ui.mpushbutton_rsi_man_z_down->setEnabled(true);

	BR_RsiVarRest();
	BR_RsiSetStatus(OffsetStatus);
}

void FSW::oncheckboxclicked_checkbox_rsi_off(){
	OffsetStatus = false;

	ui.checkbox_rsi_on->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_status_on->setEnabled(false);
	ui.mcheckbox_sri_status_off->setEnabled(false);
	ui.mpushbutton_rsi_man_y_up->setEnabled(false);
	ui.mpushbutton_rsi_man_y_down->setEnabled(false);
	ui.mpushbutton_rsi_man_z_up->setEnabled(false);
	ui.mpushbutton_rsi_man_z_down->setEnabled(false);

	BR_RsiSetStatus(OffsetStatus);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_step_up(){
	OffsetManStep = OffsetManStep + 0.1;
	BR_RsiSetOffsetStep(OffsetManStep);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_step_down(){
	OffsetManStep = OffsetManStep - 0.1;
	if(OffsetManStep <= 0) OffsetManStep = 0;
	BR_RsiSetOffsetStep(OffsetManStep);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_y_up(){
	BR_RsiManOffsetY(0);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_y_down(){	
	BR_RsiManOffsetY(1);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_z_up(){
	BR_RsiManOffsetZ(0);
}

void FSW::onpbtnclicked_mpushbutton_rsi_man_z_down(){
	BR_RsiManOffsetZ(1);
}

void FSW::oncheckboxclicked_mcheckbox_sri_connect(){
	hmi_sri_connect_status = true;
	ui.mcheckbox_sri_disconnect->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_ask->setEnabled(true);
	ui.mcheckbox_sri_stop->setEnabled(true);
	BR_RsiSriConnect(hmi_sri_connect_status);
}
void FSW::oncheckboxclicked_mcheckbox_sri_disconnect(){
	hmi_sri_connect_status = false;
	ui.mcheckbox_sri_connect->setCheckState(Qt::Unchecked);
	ui.mcheckbox_sri_ask->setEnabled(false);
	ui.mcheckbox_sri_stop->setEnabled(false);
	BR_RsiSriConnect(hmi_sri_connect_status);
}
void FSW::onpbtnclicked_mpushbutton_sri_zero(){
	BR_RsiSriSetZero();
}
void FSW::oncheckboxclicked_mcheckbox_sri_ask(){
	hmi_sri_ask_status = true;
	ui.mcheckbox_sri_stop->setCheckState(Qt::Unchecked);
	BR_RsiSriSetAskStatus(hmi_sri_ask_status);
}
void FSW::oncheckboxclicked_mcheckbox_sri_stop(){
	hmi_sri_ask_status = false;
	ui.mcheckbox_sri_ask->setCheckState(Qt::Unchecked);
	BR_RsiSriSetAskStatus(hmi_sri_ask_status);
}
void FSW::oncheckboxclicked_mcheckbox_sri_status_on(){
	hmi_sri_status = true;
	ui.mcheckbox_sri_status_off->setCheckState(Qt::Unchecked);
	BR_RsiSriSetStatus(hmi_sri_status);
}
void FSW::oncheckboxclicked_mcheckbox_sir_status_off(){
	hmi_sri_status = false;
	ui.mcheckbox_sri_status_on->setCheckState(Qt::Unchecked);
	BR_RsiSriSetStatus(hmi_sri_status);
}

void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_up(){
	SriFzSet = SriFzSet + 100;
	BR_RsiSriSetFz(SriFzSet);
}
void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_down(){
	SriFzSet = SriFzSet - 100;
	if(SriFzSet <= 0) SriFzSet = 0;
	BR_RsiSriSetFz(SriFzSet);
}

Q_EXPORT_PLUGIN2("RobotHmi",FSW);