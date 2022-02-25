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
	void FSWHmiVarInit();				 //����HMI�����ĳ�ʼ��
	void keyPressEvent(QKeyEvent *event);//�����¼�
public:
	void RegisterPLCLoopRun();		  //ע��PLC����
	void ConnectSpindleSignalSlots();//ע�������Ļص�����
	void ConnectOffsetSignalSlots(); //ע�ᶯ̬ƫ�ƵĻص�����
public:
	void GetSpindleParameters();//����ͬ��������Ϣ
	void GetOffsetParameters(); //����ͬ����̬ƫ����Ϣ
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
	int SpindleSpeedSet;   //�趨������ת��
	int SpindleSpeedGet;   //��ȡ������ת��
	short SpindleGetStatus;//��ȡ������״̬
	short SpindleSetStatus;//�趨������״̬

	double OffsetSumY;     //����Y����
	double OffsetSumZ;     //����Z����
	bool   OffsetStatus;   //����״̬

	double OffsetManSumY;  //�ֶ�����Y����
	double OffsetManSumZ;  //�ֶ�����Z����
	double OffsetManStep;  //�ֶ���������

	double SriCorrectSumZ;      //����Z������������
	double SriFzNow;            //��ǰ�Ķ�����
	double SriFzSet;            //�趨�Ķ�����
	bool   SriOffsetStatus;             //����״̬   0�ر����� 1��������
	bool   SriConnectSetStatus;     //����״̬   0�ر����� 1��������
	bool   SriAskStatus;         //�Ƿ�����ѯ
	short  SriConnectStatusNow;        //��ѯ����״̬

	double hmi_fwsmartix[11][7];	   //��λ��Ͽ��ƾ���
};

#endif // FSW_H
