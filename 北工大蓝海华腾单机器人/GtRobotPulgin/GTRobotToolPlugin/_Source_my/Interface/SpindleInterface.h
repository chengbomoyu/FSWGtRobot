#ifndef SPINDLE_INTERFACE_H
#define SPINDLE_INTERFACE_H

#include "qstring.h"

#define NULL 0

void BGDCvtSpindleModebusLoopRun();

void BGDCvtSpindleInit();
void BGDCvtSpindleDeInit();
void BGDCvtSpindleConnect();
void BGDCvtSpindleStatusSet(short status);
void BGDCvtSpindleSetSpeed(int mSetSpeed);
void BGDCvtSpindleGetSpeed(int& mRealSpeed);
void BGDCvtSpindleSetDirection(short mDirection);

#endif // SPINDLE_INTERFACE_H