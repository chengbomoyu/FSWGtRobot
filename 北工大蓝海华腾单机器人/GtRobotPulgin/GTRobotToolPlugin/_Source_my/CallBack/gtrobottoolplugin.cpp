#include "qstring.h"

#include "gtrobottoolplugin.h"
#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "plc_standard_class.h"
#include "comm_struct_define.h"
#include "robot_comm_interface.h"

#include "_Source_my/Interface/SpindleInterface.h"

FSW::FSW(QWidget *parent){
	ui.setupUi(this);
	FSWHmiVarInit();
	BGDCvtSpindleInit();
	RegisterPLCLoopRun();
}
FSW::~FSW(){
	BGDCvtSpindleDeInit();
}
void FSW::FSWHmiVarInit(){
	int SpindleSetSpeed = 0;//设定的主轴转速
	int SpindleGetSpeed = 0;//获取的主轴转速
	short SpindleGetStatus = 0;//获取的主轴状态
	short SpindleSetStatus = 0;//设定的主轴状态
}
void FSW::RegisterPLCLoopRun(){
	GTR_RegisterPlcLoop(1,BGDCvtSpindleModebusLoopRun);
}
void FSW::ConnectSpindleSignalSlots(){
	connect(ui.pbSpindleConnect,SIGNAL(clicked()),this,SLOT(onpbpbSpindleConnect()));
	connect(ui.mpushbutton_spindle_on,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_on()));
	connect(ui.mpushbutton_spindle_off,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_off()));
	connect(ui.mpushbutton_spindle_speed_up100,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_speed_up100()));
	connect(ui.mpushbutton_spindle_speed_down100,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_spindle_speed_down100()));
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
}
void FSW::GetSpindleParameters(){
	BGDCvtSpindleGetSpeed(SpindleGetSpeed);
	SpindleSetSpeed = SpindleSetSpeed;
	SpindleGetStatus = SpindleSetStatus;
	switch(SpindleGetStatus){
		case 0:	break;
		case 1:	break;
		case 2:	ui.mlabel_spindle_status->setText("开启"); break;
		case 3:	ui.mlabel_spindle_status->setText("关闭"); break;
	}
	ui.mlcdnumber_spindle_set->display(SpindleSetSpeed);
	ui.mlcdnumber_spindle_real->display(SpindleGetSpeed);
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
	SpindleSetSpeed = SpindleSetSpeed+100;
	BGDCvtSpindleSetSpeed(SpindleSetSpeed);
}
void FSW::onpbtnclicked_mpushbutton_spindle_speed_down100(){
	SpindleSetSpeed = SpindleSetSpeed-100;
	BGDCvtSpindleSetSpeed(SpindleSetSpeed);
}

Q_EXPORT_PLUGIN2("RobotHmi",FSW);