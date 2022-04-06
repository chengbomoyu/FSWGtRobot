#ifndef FSW_INTERFACE_H
#define FSW_INTERFACE_H
#include "qstring.h"
#define NULL 0

short BGDFswInit();   //FSW�ӿڳ�ʼ��
short BGDFswDeinit(); //FSW�ӿ��ͷ�
short BGDFswVarRest();//FSW���ֽӿڱ�������

short BGDForceControlSetStatus(bool status);        //�趨����ƫ��״̬
short BGDPointLaserControlSetStatus(bool status);   //�趨����ƫ��״̬
short BGDForceControlSetFz(double value);           //�趨ѹ��
short BGDPointLaserSetVoltage(double value);             
short BGDFswOffsetDataGet(double& data);
short BGDRreadFswOffsetZ(double& value);

#endif // FSW_INTERFACE_H