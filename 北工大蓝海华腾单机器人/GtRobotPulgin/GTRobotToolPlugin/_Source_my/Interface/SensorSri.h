#ifndef SENSOR_SRI_H
#define SENSOR_SRI_H
#include "qstring.h"
#define NULL 0

short BGDSRIInit();   //RSI�ӿڳ�ʼ��
short BGDSRIDeinit(); //RSI�ӿ��ͷ�
short BGDSRIVarRest();//RSI���ֽӿڱ�������

short BGDSriConnectSet(bool status); //SRI��������
short BGDSriReadConnectStatus(short& status);  //��ѯ����״̬

short BGDSriSetAskStatus(bool status);//������ѯ
short BGDSriSetZero();            //�趨���
short BGDReadSriFz(double& value);//��ѯZֵ
void  BGDGetSriDataLoopRun();      //��ѯSRI����

#endif // SENSOR_SRI_H