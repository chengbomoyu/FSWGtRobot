#ifndef FSW_H
#define FSW_H

#include <QtGui/QWidget>
#include "qstring.h"

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
	FSW(QWidget *parent = 0);
	~FSW();
	void FSWHmiVarInit();
	void keyPressEvent(QKeyEvent *event);
public:
	void RegisterPLCLoopRun();
	void ConnectSpindleSignalSlots();
	void ConnectOffsetSignalSlots();
public:
	void GetSpindleParameters();
	void GetOfficeParameters();
public slots:
		void onpbpbSpindleConnect();
		void onpbtnclicked_mpushbutton_spindle_on();
		void onpbtnclicked_mpushbutton_spindle_off();
		void onpbtnclicked_mpushbutton_spindle_speed_up100();
		void onpbtnclicked_mpushbutton_spindle_speed_down100();

		void oncheckboxclicked_checkbox_rsi_on();
		void oncheckboxclicked_checkbox_rsi_off();

		void onpbtnclicked_mpushbutton_rsi_man_step_up();
		void onpbtnclicked_mpushbutton_rsi_man_step_down();
		void onpbtnclicked_mpushbutton_rsi_man_y_up();
		void onpbtnclicked_mpushbutton_rsi_man_y_down();
		void onpbtnclicked_mpushbutton_rsi_man_z_up();
		void onpbtnclicked_mpushbutton_rsi_man_z_down();

		void oncheckboxclicked_mcheckbox_sri_connect();
		void oncheckboxclicked_mcheckbox_sri_disconnect();
		void oncheckboxclicked_mcheckbox_sri_ask();
		void oncheckboxclicked_mcheckbox_sri_stop();
		void oncheckboxclicked_mcheckbox_sri_status_on();
		void oncheckboxclicked_mcheckbox_sir_status_off();
		void onpbtnclicked_mpushbutton_sri_zero();
		void onpbtnclicked_mpushbutton_sri_fzsetting_up();
		void onpbtnclicked_mpushbutton_sri_fzsetting_down();

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
private:
	Ui::FSWClass ui;
private:
	int SpindleSetSpeed;   //�趨������ת��
	int SpindleGetSpeed;   //��ȡ������ת��
	short SpindleGetStatus;//��ȡ������״̬
	short SpindleSetStatus;//�趨������״̬

	double OffsetSumY;     //����Y����
	double OffsetSumZ;     //����Z����
	bool   OffsetStatus;   //����״̬

	double OffsetManSumY;  //�ֶ�����Y����
	double OffsetManSumZ;  //�ֶ�����Z����
	double OffsetManStep;  //�ֶ���������

	double hmi_sri_correct_sum_z;      //����Z������������
	double hmi_sri_Fz;                 //��ǰ�Ķ�����
	double hmi_sri_FzSet;              //�趨�Ķ�����
	bool   hmi_sri_status;             //����״̬   0�ر����� 1��������
	bool   hmi_sri_connect_status;     //����״̬   0�ر����� 1��������
	bool   hmi_sri_ask_status;         //�Ƿ�����ѯ
	short  hmi_sri_ask_connect_status; //��ѯ����״̬

	double hmi_fwsmartix[11][7];
};

#endif // FSW_H
