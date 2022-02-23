#include "SpindleInterface.h"
#include "_Source_my/Source/Spindle.h"

static CvtSpindle *mCvtSpindle = NULL;


void BGDCvtSpindleInit(){
	mCvtSpindle = new CvtSpindle();
}
void BGDCvtSpindleDeInit(){
	delete mCvtSpindle;
}
void BGDCvtSpindleModebusLoopRun(){
	if(mCvtSpindle->SpindleComStatus==1){
		mCvtSpindle->CvtModebusRtu.loopRun();
	}
}

void BGDCvtSpindleConnect(){
	mCvtSpindle->SpindleConnect();
}

void BGDCvtSpindleStatusSet(short status){
	mCvtSpindle->SpindleServorStatusSet(status);
}

void BGDCvtSpindleSetSpeed(int mSetSpeed){
	mCvtSpindle->SpindleSetSpeed(mSetSpeed);
}

void BGDCvtSpindleGetSpeed(int& mRealSpeed){
	mCvtSpindle->SpindleGetRealSpeed(mRealSpeed);
}

void BGDCvtSpindleSetDirection(short mDirection){
	mCvtSpindle->SpindleSetDirection(mDirection);
}
