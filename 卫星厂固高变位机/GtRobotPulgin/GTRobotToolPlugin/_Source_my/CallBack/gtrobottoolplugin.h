#ifndef RSI_H
#define RSI_H

#include <QtGui/QWidget>
#include "qstring.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QKeyEvent>

#include "ui_FSW.h"
#include "gtappframeinterface.h"
#include "gtrobot_backend_define.h"
#include "comm_struct_define.h"
#include "robot_comm_interface.h"
#include "plc_standard_class.h"

class FSW : public GtAppFrameInterface{
Q_OBJECT
	Q_INTERFACES(GtAppFrameInterface)

public:
/******************************************/
	FSW(QWidget *parent = 0);
	~FSW();
/******************************************/
	static short UserCmdCallBack(const Gtr::UserComParam & param, bool bFirst);
	void StatusInformationSynchronization();
/******************************************/
	void signal_slot_connect_rsi();
	void signal_slot_connect_rsi_man();
	void signal_slot_connect_rsi_sri();
	void signal_slot_connect_rsi_plaser();
	void signal_slot_connect_goservo();
	void fsw_martix_init();
	void keyPressEvent(QKeyEvent *event);
/******************************************/
	public slots:
		void oncheckboxclicked_mcheckbox_go_spindle_status_on();
		void oncheckboxclicked_mcheckbox_go_spindle_status_off();
		void onpbtnclicked_mpushbutton_go_spindle_on();
		void onpbtnclicked_mpushbutton_go_spindle_off();
		void onpbtnclicked_mpushbutton_go_spindle_speed_up100();
		void onpbtnclicked_mpushbutton_go_spindle_speed_down100();
/******************************************/
		void oncheckboxclicked_checkbox_rsi_on();
		void oncheckboxclicked_checkbox_rsi_off();
		void onpbtnclicked_mpushbutton_rsi_save();
		void onpbtnclicked_mpushbutton_rsi_savedone();
/******************************************/
		void onpbtnclicked_mpushbutton_rsi_man_step_up();
		void onpbtnclicked_mpushbutton_rsi_man_step_down();
		void onpbtnclicked_mpushbutton_rsi_man_y_up();
		void onpbtnclicked_mpushbutton_rsi_man_y_down();
		void onpbtnclicked_mpushbutton_rsi_man_z_up();
		void onpbtnclicked_mpushbutton_rsi_man_z_down();
/******************************************/
		void oncheckboxclicked_mcheckbox_sri_connect();
		void oncheckboxclicked_mcheckbox_sri_disconnect();
		void oncheckboxclicked_mcheckbox_sri_ask();
		void oncheckboxclicked_mcheckbox_sri_stop();
		void oncheckboxclicked_mcheckbox_sri_status_on();
		void oncheckboxclicked_mcheckbox_sir_status_off();
		void onpbtnclicked_mpushbutton_sri_zero();
		void onpbtnclicked_mpushbutton_sri_fzsetting_up();
		void onpbtnclicked_mpushbutton_sri_fzsetting_down();
/******************************************/
		void oncheckboxclicked_mcheckbox_plaser_status_on();
		void oncheckboxclicked_mcheckbox_plaser_status_off();
		void onpbtnclicked_mpushbutton_plaser_zero();
/******************************************/

protected:
	QString getFrameName();
	QString getVersion();
	void FastTimerLoop();
	void SlowTimerLoop();
	bool readLastTimeStatus();
	bool saveLastTimeStatus();
	bool showFrame();
	bool hideFrame();
	void setPermission(short type);
/******************************************/
private:
	Ui::FSWClass ui;
	/******************************************/
	double hmi_rsi_correct_sum_y;  //Y 方向修正总量
	double hmi_rsi_correct_sum_z;  //Z 方向修正总量
	bool   hmi_rsi_status;         //修正状态   0关闭修正 1开启修正
	bool   hmi_rsi_allow;          //修正允许   0不允许   1允许
	/******************************************/
	double hmi_rsi_man_correct_sum_y;  //y 方向修正总量
	double hmi_rsi_man_correct_sum_z;  //z 方向修正总量
	bool   hmi_rsi_man_status;         //修正状态   0关闭修正 1开启修正
	double hmi_rsi_man_correct_step;   //修正步距
	/******************************************/
	double hmi_sri_correct_sum_z;      //z 方向修正总量
	double hmi_sri_Fz;                 //当前的顶锻力
	double hmi_sri_FzSet;              //设定的顶锻力
	bool   hmi_sri_status;             //修正状态   0关闭修正 1开启修正
	bool   hmi_sri_connect_status;     //连接状态   0关闭连接 1开启连接
	bool   hmi_sri_ask_status;
	short  hmi_sri_ask_connect_status; //问询连接状态
	/******************************************/
	bool   hmi_plaser_status;            
	bool   hmi_plaser_connect_status;     
	double hmi_plaser_correct_sum_z;      
	double hmi_plaser_voltage_set;
	double hmi_plaser_voltage_now;
	double hmi_plaser_thickness;
	/******************************************/
	double hmi_fwsmartix[11][7];
	/******************************************/
	bool hmi_save;
	bool hmi_savedone;

	double hmi_robotpost[8];
	double hmi_joint[8];

	QFile *myFile_data;
	QFile *myFile_joint;

	QTextStream *outfile_data;
	QTextStream *outfile_joint;
	/******************************************/
	bool     hmi_go_spindle_status;             //主轴状态 0复位，1使能
	bool     hmi_go_spindle_poweron;            //主轴开关 0关  ，1开
	int      hmi_go_spindle_speed_set;          //主轴速度设定
	double   hmi_go_spindle_speed_real;         //主轴实际转速
};

#endif // RSI_H
