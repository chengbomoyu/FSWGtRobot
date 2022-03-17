#include "plc_standard_class.h"
using namespace plc;
//上升沿实现
R_TRIG::R_TRIG(void)
{
	M = false;
	Q = false;
}
R_TRIG::~R_TRIG(void)
{
}
void R_TRIG::Execute(bool _IN)
{
	Q = (_IN & (!M));
	M = _IN;
}
bool R_TRIG::GetQValue()
{
	return Q;
}


//下降沿实现
F_TRIG::F_TRIG(void)
{
	M = false;
	Q = false;
}
F_TRIG::~F_TRIG(void)
{
}
void F_TRIG::Execute(bool _IN)
{
	Q = (!_IN) & M;
	M = _IN;
}
bool F_TRIG::GetQValue()
{
	return Q;
}

//延时接通定时器实现
TON::TON(void)
{
	StartTime = GetTickCount();
	ET = 0;
	Q = false;
	M = false;
}
TON::~TON(void)
{
}
void TON::Execute(bool _IN,DWORD PT)
{
	if (!_IN)	//输入使能为false
	{
		StartTime = GetTickCount();		//记录初始时间
		Q = false;
		ET = 0;
	} 
	else
	{
		DWORD current_time = GetTickCount();
		if (current_time<StartTime)		//系统开机的时间已经发生越界
			ET = (DWORD)0xffffffff -StartTime +current_time;
		else
			ET = current_time - StartTime;//过去的时间
		if (ET >= PT)
		{
			ET = PT;
			Q = true;
		}
		else
		{
			Q = false;
		}
	}
	M = _IN;
}
bool TON::GetQValue()
{
	return Q;
}
DWORD TON::GetETValue()
{
	return ET;
}

//延时断开定时器实现
TOF::TOF(void)
{
	StartTime = GetTickCount();
	ET = 0;
	Q = false;
	M = false;
}
TOF::~TOF(void)
{
}
void TOF::Execute(bool _IN,DWORD PT)
{
	if (_IN)	//输入使能为false
	{
		StartTime = GetTickCount();		//记录初始时间
		Q = true;
		ET = 0;
	} 
	else
		if (Q)
		{
			DWORD current_time = GetTickCount();
			if (current_time<StartTime)		//系统开机的时间已经发生越界
				ET = (DWORD)0xffffffff -StartTime +current_time;
			else
				ET = current_time - StartTime;//过去的时间
			if (ET > PT)
			{
				ET = PT;
				Q = false;
			}
		} 
		else
		{
			StartTime = 0;
			ET = 0;
			Q = false;
			M = false;
		}
	M = _IN;
}
bool TOF::GetQValue()
{
	return Q;
}
DWORD TOF::GetETValue()
{
	return ET;
}
