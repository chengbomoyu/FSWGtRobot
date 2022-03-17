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
#include "_Source_my/Interface/SensorSri.h"

FSW::FSW(QWidget *parent){
	ui.setupUi(this);
	this->FSWHmiVarInit(); //HMI变量的初始化
 
	ConnectSpindleSignalSlots(); //连接电主轴槽函数
	BGDCvtSpindleInit();         //电主轴的初始化
	//BGDCvtSpindleConnect();      //连接蓝海华腾电主轴

	ConnectSensorSignalSlots(); //连接传感器槽函数
	BGDSRIInit();               //传感器初始化

	ConnectOffsetSignalSlots();	 //连接动态偏移槽函数
	BGDOffsetInit();                  //动态偏移的初始化

	//ConnectFswTecSignalSlots();
	//BGDFswMartixUpdate(hmi_fwsmartix);//传递系数矩阵
	
	RegisterPLCLoopRun();             //注册PLC循环函数


}

FSW::~FSW(){
	BGDCvtSpindleDeInit();//回收电主轴的内存
	BGDSRIDeinit();       //回收传感器的内存
	BGDOffsetDeinit();    //回收动态偏移的内存
}
void FSW::FSWHmiVarInit(){
	this->SpindleSpeedSet = 0;//设定的主轴转速
	this->SpindleSpeedGet = 0;//获取的主轴转速
	this->SpindleGetStatus = 0;//获取的主轴状态
	this->SpindleSetStatus = 0;//设定的主轴状态

	this->OffsetStatus = false;   //修正状态
	this->OffsetSumY = 0;     //修正Y总量
	this->OffsetSumZ = 0;     //修正Z总量

	this->OffsetManSumY = 0;  //手动修正Y总量
	this->OffsetManSumZ = 0;  //手动修正Z总量
	this->OffsetManStep = 0.1;  //手动修正步距

	this->SriConnectSetStatus = false; //连接状态     0关闭连接 1开启连接
	this->SriAskStatus = false;        //是否开启问询
	this->SriOffsetStatus = false;     //力修正状态   0关闭修正 1开启修正
	this->SriConnectStatusNow = 0;     //问询连接状态

	this->SriCorrectSumZ = 0;      //力控Z方向修正总量
	this->SriFzNow = 0;            //当前的顶锻力
	this->SriFzSet = 4500;         //设定的顶锻力

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
			//BGDSriSetFz(SriFzSet);
			break;
		case Qt::Key_4:
			SriFzSet = SriFzSet - 100;
			if(SriFzSet <= 0) SriFzSet = 0;
			//BGDSriSetFz(SriFzSet);	
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
	//GTR_RegisterPlcLoop(1,BGDCvtSpindleModebusLoopRun);
	GTR_RegisterPlcLoop(2,BGDGetSriDataLoopRun);
	GTR_RegisterPlcLoop(3,BGDDoOffsetLoopRun);
}

void FSW::ConnectSpindleSignalSlots(){
	connect(ui.mpushbutton_spindle_on,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_on()));
	connect(ui.mpushbutton_spindle_off,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_off()));
	connect(ui.mpushbutton_spindle_speed_up100,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_speed_up100()));
	connect(ui.mpushbutton_spindle_speed_down100,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_speed_down100()));
}

void FSW::ConnectOffsetSignalSlots(){
	connect(ui.mpushbutton_offset_status_set,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_offset_status_set()));
	connect(ui.mpushbutton_rsi_man_step_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_step_up()));
	connect(ui.mpushbutton_rsi_man_step_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_step_down()));
	connect(ui.mpushbutton_rsi_man_y_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_y_up()));
	connect(ui.mpushbutton_rsi_man_y_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_y_down()));
	connect(ui.mpushbutton_rsi_man_z_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_z_up()));
	connect(ui.mpushbutton_rsi_man_z_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_z_down()));
}
void FSW::ConnectFswTecSignalSlots(){
	connect(ui.mpushbutton_sri_fzsetting_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_sri_fzsetting_up()));
	connect(ui.mpushbutton_sri_fzsetting_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_sri_fzsetting_down()));
}

void FSW::ConnectSensorSignalSlots(){
	connect(ui.mcheckbox_sri_connect,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_connect()));
	connect(ui.mcheckbox_sri_status_on,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_status_on()));
	connect(ui.mcheckbox_sri_ask,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_sri_ask()));
	connect(ui.mpushbutton_sri_zero,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_sri_zero()));

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
	//GetSpindleParameters();
	GetOffsetParameters();
}
void FSW::GetSpindleParameters(){
	BGDCvtSpindleGetSpeed(SpindleSpeedGet);
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
	BGDRreadOffsetSumY(OffsetSumY);
	BGDRreadOffsetSumZ(OffsetSumZ);
	BGDGetManOffsetSumY(OffsetManSumY);
	BGDGetManOffsetSumZ(OffsetManSumZ);
	//BGDRreadSriOffsetZ(SriCorrectSumZ);
	BGDSriReadConnectStatus(SriConnectStatusNow);
	BGDReadSriFz(SriFzNow);

	//0未连接1正常2异常3未采集
	switch (SriConnectStatusNow){
		case 0:	 ui.mlabel_sri_status_connect->setText("未连接");	 break;
		case 1:  ui.mlabel_sri_status_connect->setText("采集中");	 break;
		case 2:  ui.mlabel_sri_status_connect->setText("异常！");    break;
		case 3:  ui.mlabel_sri_status_connect->setText("未采集");	 break;
		default: ui.mlabel_sri_status_connect->setText("其他");     break;
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
void FSW::onpbtnclicked_mpushbutton_offset_status_set(){
	if(OffsetStatus == STATUS_ON){
		this->OffsetStatus = STATUS_OFF;
		BGDOffsetStatusSet(STATUS_OFF);
		ui.mpushbutton_offset_status_set->setText("偏移（开）");
	} 
	else if(OffsetStatus == STATUS_OFF){
		this->OffsetStatus = STATUS_ON;
		BGDOffsetVarRest();
		BGDOffsetStatusSet(STATUS_ON);
		ui.mpushbutton_offset_status_set->setText("偏移（关）");
	}
	else{}
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
	if(SriConnectSetStatus == STATUS_ON){
		SriConnectSetStatus = STATUS_OFF;
		BGDSriConnectSet(STATUS_OFF);
	}
	else if(SriConnectSetStatus == STATUS_OFF){
		SriConnectSetStatus = STATUS_ON;
		BGDSriConnectSet(STATUS_ON);
	}
	else{}
}

void FSW::onpbtnclicked_mpushbutton_sri_zero(){
	BGDSriSetZero();
}

void FSW::oncheckboxclicked_mcheckbox_sri_ask(){
	if(SriAskStatus == STATUS_ON){
		SriAskStatus = STATUS_OFF;
		BGDSriSetAskStatus(STATUS_OFF);
	}
	else if(SriAskStatus == STATUS_OFF){
		SriAskStatus = STATUS_ON;
		BGDSriSetAskStatus(STATUS_ON);
	}
	else{}
}

void FSW::oncheckboxclicked_mcheckbox_sri_status_on(){
	if(SriOffsetStatus == STATUS_ON){
		SriOffsetStatus = STATUS_OFF;
		//BGDSriSetStatus(STATUS_OFF);
	}
	else if(SriOffsetStatus == STATUS_OFF){
		SriOffsetStatus = STATUS_ON;
		//BGDSriSetStatus(STATUS_ON);
	}
	else{}
}

void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_up(){
	SriFzSet = SriFzSet + FORCE_CTRL_MIN_STEP;
	//BGDSriSetFz(SriFzSet);
}
void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_down(){
	SriFzSet = SriFzSet - FORCE_CTRL_MIN_STEP;
	if(SriFzSet <= 0) SriFzSet = 0;
	//BGDSriSetFz(SriFzSet);
}

Q_EXPORT_PLUGIN2("RobotHmi",FSW);