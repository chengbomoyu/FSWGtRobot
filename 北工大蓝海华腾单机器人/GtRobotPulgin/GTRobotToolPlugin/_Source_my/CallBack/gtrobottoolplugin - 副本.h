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
	void signal_slot_connect_rsi();
	void signal_slot_connect_rsi_man();
	void signal_slot_connect_rsi_sri();
	void fsw_martix_init();
	void keyPressEvent(QKeyEvent *event);
/******************************************/
	public slots:
		void onpbtnclicked_mpushbutton_spindle_on();
		void onpbtnclicked_mpushbutton_spindle_off();
		void onpbtnclicked_mpushbutton_spindle_speed_up100();
		void onpbtnclicked_mpushbutton_spindle_speed_down100();
/******************************************/
		void oncheckboxclicked_checkbox_rsi_on();
		void oncheckboxclicked_checkbox_rsi_off();
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
	double hmi_rsi_correct_sum_y;      //Y ������������
	double hmi_rsi_correct_sum_z;      //Z ������������
	bool   hmi_rsi_status;             //����״̬   0�ر����� 1��������
	bool   hmi_rsi_allow;              //��������   0������   1����
	/******************************************/
	double hmi_rsi_man_correct_sum_y;  //y ������������
	double hmi_rsi_man_correct_sum_z;  //z ������������
	double hmi_rsi_man_correct_step;   //��������
	/******************************************/
	double hmi_sri_correct_sum_z;      //z ������������
	double hmi_sri_Fz;                 //��ǰ�Ķ�����
	double hmi_sri_FzSet;              //�趨�Ķ�����
	bool   hmi_sri_status;             //����״̬   0�ر����� 1��������
	bool   hmi_sri_connect_status;     //����״̬   0�ر����� 1��������
	short  hmi_sri_ask_connect_status; //��ѯ����״̬
	/******************************************/
	double hmi_fwsmartix[11][7];       //����ϵ������
};

#endif // RSI_H
