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

#define STATUS_ON true
#define STATUS_OFF false

#define SPINDLE_ON 2
#define SPINDLE_OFF 3
#define SPINDLE_SPEED_STEP 100 //ת�ٲ���

#define SENSOR_SRI_CONNECTERROR 3
#define SENSOR_SRI_DAQ 2
#define SENSOR_SRI_UNDAQ 0
#define SENSOR_SRI_CLIENTERROR 1
#define SENSOR_SRI_UNCONNECT 4

#define MAN_OFFSET_MINS_TEP 0.1 //���ڻ�·��������
#define MAN_OFFSET_PD 0 //�ֶ�������
#define MAN_OFFSET_ND 1 //�ֶ�������

#define FORCE_CTRL_MIN_STEP 100

class FSW : public GtAppFrameInterface{
Q_OBJECT
	Q_INTERFACES(GtAppFrameInterface)
public:
	FSW(QWidget *parent = 0);
	~FSW();
public:
	void FSWHmiVarInit();				 //����HMI�����ĳ�ʼ��
	void keyPressEvent(QKeyEvent *event);//�����¼�
public:
	void RegisterPLCLoopRun();		  //ע��PLC����
	void ConnectSpindleSignalSlots(); //ע�������Ļص�����
	void ConnectOffsetSignalSlots();  //ע�ᶯ̬ƫ�ƵĻص�����
	void ConnectSensorSignalSlots();  //ע�ᴫ�����Ļص�����
	void ConnectFswTecSignalSlots();
public:
	void GetSpindleParameters();  //����ͬ��������Ϣ
	void GetSensorSriParameters();//����ͬ��SRI��������Ϣ
	void GetOffsetParameters();   //����ͬ����̬ƫ����Ϣ
public slots:
		void onpbtnclicked_mpushbutton_spindle_on();
		void onpbtnclicked_mpushbutton_spindle_off();
		void onpbtnclicked_mpushbutton_spindle_speed_up100();
		void onpbtnclicked_mpushbutton_spindle_speed_down100();

		void oncheckboxclicked_mcheckbox_sri_connect();
		void oncheckboxclicked_mcheckbox_sri_ask();
		void onpbtnclicked_mpushbutton_sri_zero();

		void onpbtnclicked_mpushbutton_offset_status_set();
		void onpbtnclicked_mpushbutton_rsi_man_step_up();
		void onpbtnclicked_mpushbutton_rsi_man_step_down();
		void onpbtnclicked_mpushbutton_rsi_man_y_up();
		void onpbtnclicked_mpushbutton_rsi_man_y_down();
		void onpbtnclicked_mpushbutton_rsi_man_z_up();
		void onpbtnclicked_mpushbutton_rsi_man_z_down();

		void oncheckboxclicked_mcheckbox_sri_status_on();
		void onpbtnclicked_mpushbutton_sri_fzsetting_up();
		void onpbtnclicked_mpushbutton_sri_fzsetting_down();

protected:
	QString getFrameName();
	QString getVersion();
	bool readLastTimeStatus();
	bool saveLastTimeStatus();
	bool showFrame();
	bool hideFrame();
	void setPermission(short type);
protected:
	void FastTimerLoop();
	void SlowTimerLoop();
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
	bool   SriOffsetStatus;     //����״̬   0�ر����� 1��������
	bool   SriConnectSetStatus; //����״̬   0�ر����� 1��������
	bool   SriAskStatus;        //�Ƿ�����ѯ
	short  SriConnectStatusNow; //��ѯ����״̬
};

#endif // FSW_H
