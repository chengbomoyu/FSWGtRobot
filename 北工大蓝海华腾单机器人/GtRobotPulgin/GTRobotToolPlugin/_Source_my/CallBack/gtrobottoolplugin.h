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
#define SPINDLE_SPEED_STEP 100 //转速步距

#define SENSOR_SRI_CONNECTERROR 3
#define SENSOR_SRI_DAQ 2
#define SENSOR_SRI_UNDAQ 0
#define SENSOR_SRI_CLIENTERROR 1
#define SENSOR_SRI_UNCONNECT 4

#define MAN_OFFSET_MINS_TEP 0.1 //人在回路调整步距
#define MAN_OFFSET_PD 0 //手动正方向
#define MAN_OFFSET_ND 1 //手动负方向

#define FORCE_CTRL_MIN_STEP 100

class FSW : public GtAppFrameInterface{
Q_OBJECT
	Q_INTERFACES(GtAppFrameInterface)
public:
	FSW(QWidget *parent = 0);
	~FSW();
public:
	void FSWHmiVarInit();				 //用于HMI变量的初始化
	void keyPressEvent(QKeyEvent *event);//键盘事件
public:
	void RegisterPLCLoopRun();		  //注册PLC函数
	void ConnectSpindleSignalSlots(); //注册电主轴的回调函数
	void ConnectOffsetSignalSlots();  //注册动态偏移的回调函数
	void ConnectSensorSignalSlots();  //注册传感器的回调函数
	void ConnectFswTecSignalSlots();
public:
	void GetSpindleParameters();  //上行同步主轴信息
	void GetSensorSriParameters();//上行同步SRI传感器信息
	void GetOffsetParameters();   //上行同步动态偏移信息
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
	int SpindleSpeedSet;   //设定的主轴转速
	int SpindleSpeedGet;   //获取的主轴转速
	short SpindleGetStatus;//获取的主轴状态
	short SpindleSetStatus;//设定的主轴状态

	double OffsetSumY;     //修正Y总量
	double OffsetSumZ;     //修正Z总量
	bool   OffsetStatus;   //修正状态

	double OffsetManSumY;  //手动修正Y总量
	double OffsetManSumZ;  //手动修正Z总量
	double OffsetManStep;  //手动修正步距

	double SriCorrectSumZ;      //力控Z方向修正总量
	double SriFzNow;            //当前的顶锻力
	double SriFzSet;            //设定的顶锻力
	bool   SriOffsetStatus;     //修正状态   0关闭修正 1开启修正
	bool   SriConnectSetStatus; //连接状态   0关闭连接 1开启连接
	bool   SriAskStatus;        //是否开启问询
	short  SriConnectStatusNow; //问询连接状态
};

#endif // FSW_H
