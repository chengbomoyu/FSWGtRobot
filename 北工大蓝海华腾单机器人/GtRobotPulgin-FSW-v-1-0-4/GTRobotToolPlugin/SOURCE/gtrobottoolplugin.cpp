#include "qstring.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QKeyEvent>
#include <QDebug>

#include"gtrobottoolplugin.h"
#include"gtrobot_backend_define.h"
#include"gtrobot_backend_interface.h"
#include"plc_standard_class.h"
#include"comm_struct_define.h"
#include "robot_comm_interface.h"
#include "fsw_interface.h"

FSW::FSW(QWidget *parent){
	ui.setupUi(this);
	BR_RsiInit();
/***************************************************************/
	this->hmi_rsi_correct_sum_z = 0;  //Z 方向修正总量
	this->hmi_rsi_correct_sum_y = 0;  //y 方向修正总量
	this->hmi_rsi_status = false;     //修正状态   0关闭修正 1开启修正
	this->hmi_rsi_allow = false;      //允许修正   0允许 1允许
	this->signal_slot_connect_rsi();  //注册信号与槽
/***************************************************************/
	this->hmi_rsi_man_correct_sum_y = 0;  //y 方向修正总量
	this->hmi_rsi_man_correct_sum_z = 0;  //z 方向修正总量
	this->hmi_rsi_man_status = false;     //修正状态   0关闭修正 1开启修正
	this->hmi_rsi_man_correct_step = 0.1; //修正步距
	this->signal_slot_connect_rsi_man();
/***************************************************************/
	this->hmi_sri_correct_sum_z = 0;
	this->hmi_sri_Fz = 0;
	this->hmi_sri_FzSet = 4500;
	this->hmi_sri_status = false;         
	this->hmi_sri_connect_status = false;
	this->hmi_sri_ask_status = false;
	this->hmi_sri_ask_connect_status = 0;
	this->signal_slot_connect_rsi_sri();
/***************************************************************/
	this->hmi_plaser_status = false;            
	this->hmi_plaser_connect_status = false;     
	this->hmi_plaser_correct_sum_z = 0;      
	this->hmi_plaser_voltage_set = 1.2;
	this->hmi_plaser_voltage_now = 0;
	this->hmi_plaser_thickness = 0;
	this->signal_slot_connect_rsi_plaser();
/***************************************************************/
	this->fsw_martix_init();
/***************************************************************/
	this->hmi_save = false;
	this->hmi_savedone = true;
	for(int i=0 ;i<8;i++){
		this->hmi_joint[i] = 0;
		this->hmi_robotpost[0] = 0;
	}
/***************************************************************/
	GTR_RegisterUserCom(100,(Gtr::GtrUserCom)UserCmdCallBack);
/***************************************************************/
	GTR_RegisterPlcLoop(2,BR_PlcLoopRun_AskPlaserDate);
	GTR_RegisterPlcLoop(3,BR_PlcLoopRun_AskSriData);
	GTR_RegisterPlcLoop(4,BR_PlcLoopRun_AskManOffset);
	GTR_RegisterPlcLoop(5,BR_PlcLoopRun_AskFswOffset);
	GTR_RegisterPlcLoop(6,BR_PlcLoopRun_DoOffset);
}
FSW::~FSW(){
	BR_RsiDeinit();
}
/***************************************************************/
short FSW::UserCmdCallBack(const Gtr::UserComParam & param, bool bFirst){
	switch (param.user_id){
			break;
		case 106:
			BR_RsiZeroRest();
			BR_RsiSetStatus(true);
			BR_RsiSetAllow(true);
			BR_RsiManSetStatus(true);
			break;
		case 107:
			BR_RsiSetStatus(false);
			BR_RsiSetAllow(false);
			BR_RsiManSetStatus(false);
			break;
		case 108:
			BR_RsiSriSetStatus(true);
			break;
		case 109:
			BR_RsiSriSetStatus(false);
			break;
		case 110:
			BR_RsiSriSetFz(param.long_param[0]);
			break;
	} 
	return 0;
}
/***************************************************************/
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
	/***************************************************************/
	hmi_rsi_correct_sum_z = BR_RsiRreadOffsetZ();
	hmi_rsi_correct_sum_y = BR_RsiRreadOffsetY();
	ui.lcdnumber_rsi_dy->display(hmi_rsi_correct_sum_y);
	ui.lcdnumber_rsi_dz->display(0-hmi_rsi_correct_sum_z);
	hmi_rsi_man_correct_sum_y = BR_RsiReadManOffsetY();
	hmi_rsi_man_correct_sum_z = BR_RsiReadManOffsetZ();
	ui.mlcdnumber_rsi_man_sum_z->display(0-hmi_rsi_man_correct_sum_z);
	ui.mlcdnumber_rsi_man_sum_y->display(hmi_rsi_man_correct_sum_y);
	/***************************************************************/
	hmi_sri_ask_connect_status = BR_RsiSriReadConnectStatus();
	if(hmi_sri_ask_connect_status == 1){
		ui.mlabel_sri_status_connect->setText("已连接");
	}
	else if(hmi_sri_ask_connect_status == 2){
		ui.mlabel_sri_status_connect->setText("正在连接");
	}
	else
		ui.mlabel_sri_status_connect->setText("未连接");
	this->hmi_sri_Fz = BR_RsiReadSriFz();
	ui.mlcdnumber_sri_Fz->display(hmi_sri_Fz);
	/***************************************************************/
	hmi_plaser_voltage_now =  BR_RsiReadPlaser();
	ui.mlcdnumber_plaser_vlotagenow->display(hmi_plaser_voltage_now);
	/***************************************************************/
	this->hmi_sri_correct_sum_z = BR_RsiRreadSriOffsetZ();
	this->hmi_plaser_correct_sum_z = BR_RsiRreadPlaerOffsetZ();
	ui.mlcdnumber_sri_correct_sum_z->display(0-hmi_sri_correct_sum_z-hmi_plaser_correct_sum_z);
	/***************************************************************/
	if(hmi_save == true){
		GTR_GetAxisProfilePosition(hmi_joint[0],0);
		GTR_GetAxisProfilePosition(hmi_joint[1],1);
		GTR_GetAxisProfilePosition(hmi_joint[2],2);
		GTR_GetAxisProfilePosition(hmi_joint[3],3);
		GTR_GetAxisProfilePosition(hmi_joint[4],4);
		GTR_GetAxisProfilePosition(hmi_joint[5],5);
		GTR_GetAxisProfilePosition(hmi_joint[6],6);
		GTR_GetAxisProfilePosition(hmi_joint[7],7);

		*outfile_data <<hmi_plaser_voltage_set<<","<<hmi_plaser_voltage_now<<"," 
					  <<hmi_sri_FzSet<<","<<hmi_sri_Fz<<","
					  <<hmi_rsi_correct_sum_y << "," <<0-hmi_rsi_correct_sum_z << ","
					  <<hmi_joint[0]<<","<<hmi_joint[1]<<","<<hmi_joint[2]<<","
				      <<hmi_joint[3]<<","<<hmi_joint[4]<<","<<hmi_joint[5]<<","
					  <<hmi_joint[6]<<","<<hmi_joint[7]<<"\n";
	}
	/***************************************************************/
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

void FSW::signal_slot_connect_rsi(){
	connect(ui.checkbox_rsi_on,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_checkbox_rsi_on()));
	connect(ui.checkbox_rsi_off,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_checkbox_rsi_off()));
	connect(ui.mpushbutton_rsi_save,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_save()));
	connect(ui.mpushbutton_rsi_savedone,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_savedone()));
}

void FSW::signal_slot_connect_rsi_man(){//手动修正界面信号槽建立
	connect(ui.mpushbutton_rsi_man_step_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_step_up()));
	connect(ui.mpushbutton_rsi_man_step_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_step_down()));
	connect(ui.mpushbutton_rsi_man_y_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_y_up()));
	connect(ui.mpushbutton_rsi_man_y_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_y_down()));
	connect(ui.mpushbutton_rsi_man_z_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_z_up()));
	connect(ui.mpushbutton_rsi_man_z_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_rsi_man_z_down()));
}

void FSW::signal_slot_connect_rsi_sri(){//六维力控制界面信号槽连接
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
void FSW::signal_slot_connect_rsi_plaser(){
	connect(ui.mcheckbox_plaser_status_on,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_plaser_status_on()));
	connect(ui.mcheckbox_plaser_status_off,SIGNAL(clicked()),this,SLOT(oncheckboxclicked_mcheckbox_plaser_status_off()));
	connect(ui.mpushbutton_plaser_zero,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_plaser_zero()));
	connect(ui.mpushbutton_plaser_possetting_down,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_plaser_possetting_down()));
	connect(ui.mpushbutton_plaser_possetting_up,SIGNAL(clicked()),this,SLOT(onpbtnclicked_mpushbutton_plaser_possetting_up()));
}
/***************************************************************/
void FSW::keyPressEvent(QKeyEvent *event){
	switch(event->key()){
		case Qt::Key_A:
			if(hmi_rsi_man_status==true)
				BR_RsiManOffsetY(1);
			break;
		case Qt::Key_S:
			if(hmi_rsi_man_status==true)
				BR_RsiManOffsetY(0);
			break;
		case Qt::Key_Z:
			if(hmi_rsi_man_status==true)
				BR_RsiManOffsetZ(0);
			break;
		case Qt::Key_X:
			if(hmi_rsi_man_status==true)
				BR_RsiManOffsetZ(1);
			break;
		case Qt::Key_7:
			hmi_sri_FzSet = hmi_sri_FzSet + 100;
			ui.mlcdnumber_sri_fzsetting->display(hmi_sri_FzSet);
			BR_RsiSriSetFz(hmi_sri_FzSet);
			break;
		case Qt::Key_4:
			hmi_sri_FzSet = hmi_sri_FzSet - 100;
			if(hmi_sri_FzSet <= 0) hmi_sri_FzSet = 0;
			ui.mlcdnumber_sri_fzsetting->display(hmi_sri_FzSet);
			BR_RsiSriSetFz(hmi_sri_FzSet);	
			break;
		case Qt::Key_0:
			hmi_rsi_man_correct_step = hmi_rsi_man_correct_step - 0.1;
			if(hmi_rsi_man_correct_step <= 0) hmi_rsi_man_correct_step = 0;
			ui.mlcdnumber_rsi_man_step->display(hmi_rsi_man_correct_step);
			BR_RsiSetOffsetStep(hmi_rsi_man_correct_step);
			break;
		case Qt::Key_1:
			hmi_rsi_man_correct_step = hmi_rsi_man_correct_step + 0.1;
			ui.mlcdnumber_rsi_man_step->display(hmi_rsi_man_correct_step);
			BR_RsiSetOffsetStep(hmi_rsi_man_correct_step);
			break;
		case Qt::Key_2:
			GTR_GetProfilePosition(hmi_robotpost,Gtr::PCS2,0,0);
			GTR_GetAxisProfilePosition(hmi_joint[6],6);
			GTR_GetAxisProfilePosition(hmi_joint[7],7);
			*outfile_joint   <<"MOVL V=100.0 BL=2 VBL=0.00 " 
				<<"@40,1,0,1,1,0,0,0,"
				<<hmi_robotpost[0]<<","<<hmi_robotpost[1]<<","<<hmi_robotpost[2]<<","
				<<hmi_robotpost[3]<<","<<hmi_robotpost[4]<<","<<hmi_robotpost[5]<<","
				<<"0.00000000,0.00000000"
				<<"$2,1,0,1,1,0,0,0,"
				<<hmi_joint[6]<<","<<hmi_joint[7]
				<<",0,0,0,0,0,0$0,0,0,0,0,0,0,0$1,1,0,0,0,0,0,0"
				<<"\n";
			break;
	}
}
/***************************************************************/
void FSW::fsw_martix_init(){
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
	BR_RsiFswMartixUpdate(hmi_fwsmartix);
}
/******************************************/
void FSW::oncheckboxclicked_checkbox_rsi_on(){
	BR_RsiZeroRest();
	hmi_rsi_status = true;
	ui.checkbox_rsi_off->setCheckState(Qt::Unchecked);
	BR_RsiSetStatus(hmi_rsi_status);
	/******************************************************/
	hmi_rsi_allow = true;
	ui.mcheckbox_sri_status_on->setEnabled(true);
	ui.mcheckbox_sri_status_off->setEnabled(true);
	BR_RsiSetAllow(hmi_rsi_allow);
	/******************************************************/
	hmi_rsi_man_status = true;
	ui.mpushbutton_rsi_man_y_up->setEnabled(true);
	ui.mpushbutton_rsi_man_y_down->setEnabled(true);
	ui.mpushbutton_rsi_man_z_up->setEnabled(true);
	ui.mpushbutton_rsi_man_z_down->setEnabled(true);
	BR_RsiManSetStatus(hmi_rsi_man_status);
}
void FSW::oncheckboxclicked_checkbox_rsi_off(){
	hmi_rsi_status = false;
	hmi_rsi_allow = false;
	ui.checkbox_rsi_on->setCheckState(Qt::Unchecked);
	BR_RsiSetStatus(hmi_rsi_status);
	/******************************************************/
	hmi_rsi_allow = false;
	ui.mcheckbox_sri_status_on->setEnabled(false);
	ui.mcheckbox_sri_status_off->setEnabled(false);
	BR_RsiSetAllow(hmi_rsi_allow);
	/******************************************************/
	hmi_rsi_man_status = false;
	ui.mpushbutton_rsi_man_y_up->setEnabled(false);
	ui.mpushbutton_rsi_man_y_down->setEnabled(false);
	ui.mpushbutton_rsi_man_z_up->setEnabled(false);
	ui.mpushbutton_rsi_man_z_down->setEnabled(false);
	BR_RsiManSetStatus(hmi_rsi_man_status);
}

/******************************************/
void FSW::onpbtnclicked_mpushbutton_rsi_man_step_up(){
	hmi_rsi_man_correct_step = hmi_rsi_man_correct_step + 0.1;
	ui.mlcdnumber_rsi_man_step->display(hmi_rsi_man_correct_step);
	BR_RsiSetOffsetStep(hmi_rsi_man_correct_step);
}
void FSW::onpbtnclicked_mpushbutton_rsi_man_step_down(){
	hmi_rsi_man_correct_step = hmi_rsi_man_correct_step - 0.1;
	if(hmi_rsi_man_correct_step <= 0) hmi_rsi_man_correct_step = 0;
	ui.mlcdnumber_rsi_man_step->display(hmi_rsi_man_correct_step);
	BR_RsiSetOffsetStep(hmi_rsi_man_correct_step);
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
/******************************************/
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
void FSW::onpbtnclicked_mpushbutton_sri_zero(){
	for(int i = 0 ; i < 10 ; i++){
		BR_RsiSriSetZero();
	}
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
	hmi_sri_FzSet = hmi_sri_FzSet + 100;
	ui.mlcdnumber_sri_fzsetting->display(hmi_sri_FzSet);
	BR_RsiSriSetFz(hmi_sri_FzSet);
}
void FSW::onpbtnclicked_mpushbutton_sri_fzsetting_down(){
	hmi_sri_FzSet = hmi_sri_FzSet - 100;
	if(hmi_sri_FzSet <= 0) hmi_sri_FzSet = 0;
	ui.mlcdnumber_sri_fzsetting->display(hmi_sri_FzSet);
	BR_RsiSriSetFz(hmi_sri_FzSet);
}
void FSW::onpbtnclicked_mpushbutton_rsi_save(){
	hmi_save = true;
	hmi_savedone = false;

	QString filename_data = "./data.csv";
	myFile_data = new QFile(filename_data);
	myFile_data->open(QIODevice::WriteOnly | QIODevice::Text);
	outfile_data = new QTextStream(myFile_data);
	*outfile_data << "SetH" << "," << "H" << "," 
				  << "SetFz" << "," << "Fz" << "," 
		          << "dy" << "," << "dz" << ","
	              << "J1" << ","<< "J2" << ","<< "J3" << ","
			      << "J4" << ","<< "J5" << ","<< "J6"<< ","
				  << "E1" << ","<< "E2" << "\n";
	
	QString filename_joint = "./trajectory.prg";
	myFile_joint = new QFile(filename_joint);
	myFile_joint->open(QIODevice::WriteOnly | QIODevice::Text);
	outfile_joint = new QTextStream(myFile_joint);
	*outfile_joint   <<"NOP\n";
}

void FSW::onpbtnclicked_mpushbutton_rsi_savedone(){
	hmi_save = false;
	hmi_savedone = true;
	*outfile_joint   <<"END";
	myFile_data->close();
	myFile_joint->close();
}
/******************************************///点激光控制设置
void FSW::oncheckboxclicked_mcheckbox_plaser_status_on(){
	hmi_plaser_status = true;
	ui.mlabel_plaser_status_onoff->setText("开启");
	ui.mcheckbox_plaser_status_off->setCheckState(Qt::Unchecked);
	BR_RsiPlaserSetStatus(hmi_plaser_status);
}
void FSW::oncheckboxclicked_mcheckbox_plaser_status_off(){
	hmi_plaser_status = false;
	ui.mlabel_plaser_status_onoff->setText("关闭");
	ui.mcheckbox_plaser_status_on->setCheckState(Qt::Unchecked);
	BR_RsiPlaserSetStatus(hmi_plaser_status);
}

void FSW::onpbtnclicked_mpushbutton_plaser_zero(){
	hmi_plaser_voltage_set = hmi_plaser_voltage_now;
	ui.mlcdnumber_plaser_vlotageset->display(hmi_plaser_voltage_set);
	BR_RsiPlaerSetZero(hmi_plaser_voltage_set);
}
void FSW::onpbtnclicked_mpushbutton_plaser_possetting_up(){
	hmi_plaser_voltage_set = hmi_plaser_voltage_set+0.1;
	ui.mlcdnumber_plaser_vlotageset->display(hmi_plaser_voltage_set);
	BR_RsiPlaerSetZero(hmi_plaser_voltage_set);
}
void FSW::onpbtnclicked_mpushbutton_plaser_possetting_down(){
	hmi_plaser_voltage_set = hmi_plaser_voltage_set-0.1;
	ui.mlcdnumber_plaser_vlotageset->display(hmi_plaser_voltage_set);
	BR_RsiPlaerSetZero(hmi_plaser_voltage_set);
}
/******************************************/
Q_EXPORT_PLUGIN2("RobotHmi",FSW);