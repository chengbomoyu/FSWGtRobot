#ifndef OFFSET_INTERFACE_EX_H
#define OFFSET_INTERFACE_EX_H
#include "qstring.h"
#define NULL 0

short BGDOffsetInit();   //RSI�ӿڳ�ʼ��
short BGDOffsetDeinit(); //RSI�ӿ��ͷ�
short BGDOffsetVarRest();//RSI���ֽӿڱ�������

short BGDOffsetStatusSet(bool status);      //RSI�ӿ�״̬�趨
short BGDRreadOffsetSumY(double& value);
short BGDRreadOffsetSumZ(double& value);

short BGDManualOffsetStepSet(double step);  //�趨�ֶ���������
short BGDDoManOffsetY(short Dir);           //�ֶ�����Y��0�ϣ�1�£�
short BGDDoManOffsetZ(short Dir);           //�ֶ�����Z��0�ϣ�1�£�
short BGDGetManOffsetSumY(double& value);   //��ȡ�ֶ�ƫ��Yֵ�ܺ�
short BGDGetManOffsetSumZ(double& value);   //��ȡ�ֶ�ƫ��Zֵ�ܺ�

void BGDDoOffsetLoopRun();        //���ж�̬ƫ��

#endif // OFFSET_INTERFACE_EX_H