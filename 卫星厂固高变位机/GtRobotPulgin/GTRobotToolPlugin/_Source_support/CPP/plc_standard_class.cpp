#include "plc_standard_class.h"
using namespace plc;
//������ʵ��
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


//�½���ʵ��
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

//��ʱ��ͨ��ʱ��ʵ��
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
	if (!_IN)	//����ʹ��Ϊfalse
	{
		StartTime = GetTickCount();		//��¼��ʼʱ��
		Q = false;
		ET = 0;
	} 
	else
	{
		DWORD current_time = GetTickCount();
		if (current_time<StartTime)		//ϵͳ������ʱ���Ѿ�����Խ��
			ET = (DWORD)0xffffffff -StartTime +current_time;
		else
			ET = current_time - StartTime;//��ȥ��ʱ��
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

//��ʱ�Ͽ���ʱ��ʵ��
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
	if (_IN)	//����ʹ��Ϊfalse
	{
		StartTime = GetTickCount();		//��¼��ʼʱ��
		Q = true;
		ET = 0;
	} 
	else
		if (Q)
		{
			DWORD current_time = GetTickCount();
			if (current_time<StartTime)		//ϵͳ������ʱ���Ѿ�����Խ��
				ET = (DWORD)0xffffffff -StartTime +current_time;
			else
				ET = current_time - StartTime;//��ȥ��ʱ��
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
