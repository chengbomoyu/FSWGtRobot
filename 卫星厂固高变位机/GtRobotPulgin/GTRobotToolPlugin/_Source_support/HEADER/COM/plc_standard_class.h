
#ifndef PLC_STANDARD_CLASS_H
#define PLC_STANDARD_CLASS_H
#pragma once
#include <windows.h>

namespace plc
{


//������
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


//�½���ʵ��
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


//��ʱ��ͨ��ʱ����PTʱ������ĵ�λ��ms��
class TON
{
public:
	TON(void);
	~TON(void);
	void Execute(bool _IN = false,DWORD PT = 0);
	bool GetQValue();
	DWORD GetETValue();			//��ȥ��ʱ��
private:
	bool Q;				
	DWORD ET;			//��ȥ��ʱ��
	bool M;				//�м���̱���
	DWORD StartTime;	//��ʼʱ�� 
};

//��ʱ�Ͽ���ʱ����PTʱ������ĵ�λ��ms��
class TOF
{
public:
	TOF(void);
	~TOF(void);
	void Execute(bool _IN = false,DWORD PT = 0);
	bool GetQValue();
	DWORD GetETValue();			//��ȥ��ʱ��
private:
	bool Q;				
	DWORD ET;			//��ȥ��ʱ��
	bool M;				//�м���̱���
	DWORD StartTime;	//��ʼʱ�� 
};


}

#endif