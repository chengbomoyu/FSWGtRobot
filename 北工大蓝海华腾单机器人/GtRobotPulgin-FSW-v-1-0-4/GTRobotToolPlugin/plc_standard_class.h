
#ifndef PLC_STANDARD_CLASS_H
#define PLC_STANDARD_CLASS_H
#pragma once
#include <windows.h>

namespace plc
{


//上升沿
class R_TRIG
{
public:
	R_TRIG(void);
	~R_TRIG(void);
	void Execute(bool _IN = false);
	bool GetQValue();
private:
	bool Q;
	bool M;
};


//下降沿实现
class F_TRIG
{
public:
	F_TRIG(void);
	~F_TRIG(void);
	void Execute(bool _IN = false);
	bool GetQValue();
private:
	bool Q;
	bool M;
};


//延时接通定时器，PT时间给定的单位（ms）
class TON
{
public:
	TON(void);
	~TON(void);
	void Execute(bool _IN = false,DWORD PT = 0);
	bool GetQValue();
	DWORD GetETValue();			//过去的时间
private:
	bool Q;				
	DWORD ET;			//过去的时间
	bool M;				//中间过程变量
	DWORD StartTime;	//开始时间 
};

//延时断开定时器，PT时间给定的单位（ms）
class TOF
{
public:
	TOF(void);
	~TOF(void);
	void Execute(bool _IN = false,DWORD PT = 0);
	bool GetQValue();
	DWORD GetETValue();			//过去的时间
private:
	bool Q;				
	DWORD ET;			//过去的时间
	bool M;				//中间过程变量
	DWORD StartTime;	//开始时间 
};


}

#endif