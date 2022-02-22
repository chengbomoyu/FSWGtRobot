#include "qstring.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QKeyEvent>
#include <QDebug>

#include "gtrobottoolplugin.h"
#include "gtrobot_backend_define.h"
#include "gtrobot_backend_interface.h"
#include "plc_standard_class.h"
#include "comm_struct_define.h"
#include "robot_comm_interface.h"
#include "fsw_interface.h"

FSW::FSW(QWidget *parent){
	ui.setupUi(this);
}
FSW::~FSW(){
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

/***************************************************************/
void FSW::onpbpbSpindleConnect(){
}
void FSW::onpbtnclicked_mpushbutton_go_spindle_on(){
}
void FSW::onpbtnclicked_mpushbutton_go_spindle_off(){
}
void FSW::onpbtnclicked_mpushbutton_go_spindle_speed_up100(){
}
void FSW::onpbtnclicked_mpushbutton_go_spindle_speed_down100(){
}

Q_EXPORT_PLUGIN2("RobotHmi",FSW);