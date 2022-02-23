#ifndef OFFSET_INTERFACE_H
#define OFFSET_INTERFACE_H
#include "qstring.h"
#define NULL 0

void BR_RsiInit(); //RSI�ӿڳ�ʼ��
void BR_RsiDeinit();//RSI�ӿ��ͷ�
void BR_RsiVarRest();//RSI���ֽӿڱ�������

void BR_RsiSetStatus(bool status); //RSI�ӿ�״̬�趨
double BR_RsiRreadOffsetY();       //��ȡRSI Y��ƫ��
double BR_RsiRreadOffsetZ();       //��ȡRSI Z��ƫ��

void BR_RsiSetOffsetStep(double step);//RSI�趨�ֶ���������
void BR_RsiManOffsetY(short Dir);     //�ֶ�����Y��0�ϣ�1�£�
void BR_RsiManOffsetZ(short Dir);     //�ֶ�����Z��0�ϣ�1�£�
double BR_RsiReadManOffsetY();        //��ȡ�ֶ�ƫ��Yֵ
double BR_RsiReadManOffsetZ();        //��ȡ�ֶ�ƫ��Zֵ

void  BR_RsiSriConnect(bool status); //SRI��������
short BR_RsiSriReadConnectStatus();  //��ѯ����״̬
void BR_RsiSriSetStatus(bool status);//�趨ƫ��״̬
void BR_RsiSriSetAskStatus(bool status);//������ѯ
void BR_RsiSriSetZero();//�趨���
void BR_RsiSriSetFz(double value);//�趨���
double BR_RsiReadSriFz();//��ѯZֵ
double BR_RsiRreadSriOffsetZ(); //��ѯƫ��Z

void BR_RsiFswMartixUpdate(double Martix[][7]);

void BR_PlcLoopRun_AskSriData();  //��ѯSRI����
void BR_PlcLoopRun_AskManOffset();//��ѯ���ڻ�·ƫ��
void BR_PlcLoopRun_AskFswOffset();//��ѯ��λ���ƫ��
void BR_PlcLoopRun_DoOffset();    //���ж�̬ƫ��

#endif // OFFSET_INTERFACE_H