#ifndef OFFSET_INTERFACE_EX_H
#define OFFSET_INTERFACE_EX_H
#include "qstring.h"
#define NULL 0

short BGDOffsetInit();   //RSI�ӿڳ�ʼ��
short BGDOffsetDeinit(); //RSI�ӿ��ͷ�
short BGDOffsetVarRest();//RSI���ֽӿڱ�������

short BGDOffsetStatusSet(bool status);      //RSI�ӿ�״̬�趨
short BGDSriSetStatus(bool status);         //�趨����ƫ��״̬
short BGDManualOffsetStatusSet(bool status);//�趨�ֶ�ƫ�ƿ���
short BGDRreadOffsetSumY(double& value);    //��ȡRSI Y��ƫ��
short BGDRreadOffsetSumZ(double& value);    //��ȡRSI Z��ƫ��
short BGDGetManOffsetSumY(double& value);   //��ȡ�ֶ�ƫ��Yֵ�ܺ�
short BGDGetManOffsetSumZ(double& value);   //��ȡ�ֶ�ƫ��Zֵ�ܺ�
short BGDRreadSriOffsetZ(double& value);    //��ѯƫ��Z
short BGDSriSetFz(double value);            //�趨ѹ��

short BGDManualOffsetStepSet(double step);  //�趨�ֶ���������
short BGDDoManOffsetY(short Dir);           //�ֶ�����Y��0�ϣ�1�£�
short BGDDoManOffsetZ(short Dir);           //�ֶ�����Z��0�ϣ�1�£�

short BGDFswMartixUpdate(double Martix[][7]); //����ϵ������

void BGDGetManOffsetDataLoopRun();//��ѯ���ڻ�·����
void BGDDoOffsetLoopRun();        //���ж�̬ƫ��

#endif // OFFSET_INTERFACE_EX_H