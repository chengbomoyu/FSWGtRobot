#ifndef RSI_H
#define RSI_H

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
public:
	void ConnectSpindleSignalSlots();
public slots:
		void onpbpbSpindleConnect();
		void onpbtnclicked_mpushbutton_spindle_on();
		void onpbtnclicked_mpushbutton_spindle_off();
		void onpbtnclicked_mpushbutton_spindle_speed_up100();
		void onpbtnclicked_mpushbutton_spindle_speed_down100();
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
};

#endif // RSI_H
