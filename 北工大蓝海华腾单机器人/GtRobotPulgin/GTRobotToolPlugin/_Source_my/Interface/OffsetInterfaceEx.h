#ifndef OFFSET_INTERFACE_H
#define OFFSET_INTERFACE_H
#include "qstring.h"
#define NULL 0

short BGDOffsetInit(); //RSI�ӿڳ�ʼ��
short BGDOffsetDeinit();//RSI�ӿ��ͷ�
short BGDOffsetVarRest();//RSI���ֽӿڱ�������

short BGDOffsetStatusSet(bool status);        //RSI�ӿ�״̬�趨
short BGDRreadOffsetSumY(double& value);       //��ȡRSI Y��ƫ��
short BGDRreadOffsetSumZ(double& value);       //��ȡRSI Z��ƫ��

short BGDManualOffsetStatusSet(bool status);//�趨�ֶ�ƫ�ƿ���
short BGDManualOffsetStepSet(double step);//�趨�ֶ���������
short BGDDoManOffsetY(short Dir);         //�ֶ�����Y��0�ϣ�1�£�
short BGDDoManOffsetZ(short Dir);         //�ֶ�����Z��0�ϣ�1�£�
short BGDGetManOffsetSumY(double& value);    //��ȡ�ֶ�ƫ��Yֵ�ܺ�
short BGDGetManOffsetSumZ(double& value);    //��ȡ�ֶ�ƫ��Zֵ�ܺ�

short BGDSriConnectSet(bool status); //SRI��������
short BGDSriReadConnectStatus(short& status);  //��ѯ����״̬
short BGDSriSetStatus(bool status);//�趨����ƫ��״̬
short BGDSriSetAskStatus(bool status);//������ѯ
short BGDSriSetZero();//�趨���
short BGDSriSetFz(double value);//
short BGDReadSriFz(double& value);//��ѯZֵ
short BGDRreadSriOffsetZ(double& value); //��ѯƫ��Z

short BGDFswMartixUpdate(double Martix[][7]);

void BGDGetSriDataLoopRun();  //��ѯSRI����
void BGDGetManOffDataLoopRun();//��ѯ���ڻ�·����
void BGDDoOffsetLoopRun();    //���ж�̬ƫ��

#endif // OFFSET_INTERFACE_H