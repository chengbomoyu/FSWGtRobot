#ifndef GTROBOT_BACKEND_INTERFACE_H
#define GTROBOT_BACKEND_INTERFACE_H

#include <vector>
#include "gtrobot_backend_define.h"

#ifdef GTR_BACKEND_LIB
# define GTR_EXPORT __declspec(dllexport)
#else
# define GTR_EXPORT __declspec(dllimport)
#endif




/*-------------��˽ӿ�-ϵͳ��ʼ��-----------------------*/


//������ϵͳ��ʼ��״̬
GTR_EXPORT short GTR_IsSystemInit(bool &result);

//��ʼ��������ϵͳ
GTR_EXPORT short GTR_InitRobotSystem();

//�˳�������ϵͳ
GTR_EXPORT short GTR_ExitRobotSystem();



/*-------------��˽ӿ�-ϵͳ�߳�-----------------------*/


//NC�߳�Sleepʱ��
GTR_EXPORT short GTR_GetNcSleepTime(unsigned short &time);
GTR_EXPORT short GTR_SetNcSleepTime(const unsigned short &time);
//NC�߳���ͣ�����
GTR_EXPORT short GTR_PauseNcThread();
GTR_EXPORT short GTR_ContinueNcThread();


//PLC�߳�Sleepʱ��
GTR_EXPORT short GTR_GetPlcSleepTime(unsigned short &time);
GTR_EXPORT short GTR_SetPlcSleepTime(const unsigned short &time);
//PLC�߳���ͣ�����
GTR_EXPORT short GTR_PausePlcThread();
GTR_EXPORT short GTR_ContinuePlcThread();


//ע��NC�߳�Userָ��ص�����
GTR_EXPORT short GTR_RegisterUserCom(const short &craft_type,Gtr::GtrUserCom func);
//ע��NC�߳�LoopRun����
GTR_EXPORT short GTR_RegisterUserRun(const short &index,Gtr::GtrUserRun func);
//ע��PLC�̵߳����ڻص�����������Լ8ms��
GTR_EXPORT short GTR_RegisterPlcLoop(const int &index,Gtr::GtrPlcLoop func);









/*-------------��˽ӿ�-ϵͳ״̬-----------------------*/
//����ȫ�ֱ���
GTR_EXPORT short GTR_IsSystemAlarm(bool &result);
//�Ƿ��ڼ�ͣ״̬
GTR_EXPORT short GTR_IsSystemEstopAlarm(bool &result);
//ϵͳ�Ƿ��ھ���״̬
GTR_EXPORT short GTR_IsSystemWarning(bool &result);
//�������
GTR_EXPORT short GTR_ClearSystemAlarm();


//��ȡ������������������Ϣ
GTR_EXPORT short GTR_GetAbsEncoderAlarm(Gtr::DriverStatus &driver_status,const short &axis_id);
//�������������-!!!����ʹ���Ա�����ֵΪ0
GTR_EXPORT short GTR_ClearAbsEncoderAlarm(const short &axis_id);
//��ɲ��
GTR_EXPORT short GTR_ClearAbsEncoderBrake(const short &axis_id);


//��ȡϵͳ����״̬-������ʾ����ط�ģʽ
//0-����״̬
//1-����״̬
//2-��ͣ״̬
//ԭ�ӿ�����GTR_GetRobotRunningStatus 2021.05.16
GTR_EXPORT short GTR_GetSystemRunningStatus(Gtr::RUNNING_STATUS &status);


//��ȡϵͳ����ģʽ(ʾ��ģʽ���ط�ģʽ��Զ��ģʽ)
//ԭ�ӿ�����GTR_GetRobotRunningMode 2021.05.16
GTR_EXPORT short GTR_GetSystemRunningMode(Gtr::RUNNING_MODE &mode,short channel = GtrCurrentChannel);


//��ȡʾ��ģʽ����״̬
GTR_EXPORT short GTR_GetTeachRunningStatus(Gtr::TEACH_STATUS &status,short channel = GtrCurrentChannel);


//��ȡ�ط�ģʽ����״̬
GTR_EXPORT short GTR_GetReplayRunningStatus(Gtr::RUNNING_STATUS &status,short channel = GtrCurrentChannel);


//��ȡԶ��ģʽ����״̬
GTR_EXPORT short GTR_GetRemoteRunningStatus(Gtr::RUNNING_STATUS &status,short channel = GtrCurrentChannel);


//�Ƿ�Ϊ�ָ�����״̬���ط�ģʽ����ͣ�лָ����У�
GTR_EXPORT short GTR_IsReplayResumeStatus(bool &status,short channel = GtrCurrentChannel);


//��д����������
GTR_EXPORT short GTR_SetPrfTorque(short axis_index,short prfTorque);
GTR_EXPORT short GTR_GetAtlTorque(short axis_index,short &atlTorque);

//����GSHD���������������ʣ�ǧ���ʣ��Ľӿ� 2021.12.14
GTR_EXPORT short GTR_SetTorqueLimit(short axis_index, unsigned short torqueMax, unsigned short torquePostive, unsigned short torqueNegitive);
GTR_EXPORT short GTR_GetTorqueLimit(short axis_index, unsigned short &torqueMax, unsigned short &torquePostive, unsigned short &torqueNegitive);

//�������ø������Ľӿڣ�posErrLmt��λ��mm��㣩2021.12.14
GTR_EXPORT short GTR_SetAxisPosErrLimit(short axis_index, double posErrLmt);
GTR_EXPORT short GTR_GetAxisPosErrLimit(short axis_index, double &posErrLmt);

//����������ģʽ�ӿ� 2021.12.15
GTR_EXPORT short GTR_SetMotionMode(short axis_index,short motionMode);
GTR_EXPORT short GTR_GetMotionMode(short axis_index,short &motionMode);

//��д���������� 2021-12-15
GTR_EXPORT short GTR_WriteDriverCmd(short axis_index,unsigned short cmd_index,unsigned short cmd_sub_index,double value);
GTR_EXPORT short GTR_ReadDriverCmd(unsigned short &cmd_index,unsigned short &cmd_sub_index);

//��ȡ����������ϵ�� 2021-12-15
GTR_EXPORT short GTR_ReadDriverTorqueConstant(short axis_index,double &value);
//��ȡ����������� 2021-12-16
GTR_EXPORT short GTR_ReadDriverRatedCurrent(short axis_index,double &value);
//��ȡ��������ֵ���� 2021-12-16
GTR_EXPORT short GTR_ReadDriverPeakCurrent(short axis_index,double &value);


/*-------------��˽ӿ�-IO���豸����-----------------------*/


//����IOֹͣ�ź�
GTR_EXPORT short GTR_IsDisableStopIo(bool &disable);
GTR_EXPORT short GTR_DisableStopIo(const bool &disable);
GTR_EXPORT short GTR_GetStopIoStatus(bool &status,const short &axis_id);


//��ȡDI״̬
//type = 0,EHMI-DI��0~15λ��
//type = 1,����DI-1��0~15λ��
//type = 2,����DI-2��16~31λ��
//type = 3,����DI-3��32~47λ��
//type = 4,��չDI��0~15λ��
GTR_EXPORT short GTR_GetDiValue(unsigned short &value,const short type);
GTR_EXPORT short GTR_GetDiBitValue(bool &value,const short type,const short bit);


//����DO״̬(��λд��)
//type = 0,EHMI-DO��0~15λ��
//type = 1,����DO-1��0~15λ��
//type = 2,����DO-2��16~31λ��
//type = 3,����DO-3��32~47λ��
//type = 4,��չDO��0~15λ��
GTR_EXPORT short GTR_SetDoValue(const unsigned short value,const short type);
GTR_EXPORT short GTR_SetDoBitValue(const bool value,const short type,const short bit);


//����DO״̬
//type = 0,EHMI-DO��0~15λ��
//type = 1,����DO-1��0~15λ��
//type = 2,����DO-2��16~31λ��
//type = 3,����DO-3��32~47λ��
//type = 4,��չDO��0~15λ��
GTR_EXPORT short GTR_GetDoValue(unsigned short &value,const short type);
GTR_EXPORT short GTR_GetDoBitValue(bool &value,const short type,const short bit);


//��ȡAI״̬
//type = 0,����AIO
//type = 1,��չAIO
GTR_EXPORT short GTR_GetAiValue(double &value,const short index,short type = 0);
//��ȡAO״̬
GTR_EXPORT short GTR_GetAoValue(double &value,const short index,short type = 0);
//����AO״̬
GTR_EXPORT short GTR_SetAoValue(const double value,const short index,short type = 0);


//�ֳֺа����������������»��ɿ�
GTR_EXPORT short GTR_PressKey(const Gtr::Key &key); 
GTR_EXPORT short GTR_ReleaseKey(const Gtr::Key &key);


//�ֳֺа�����״̬������ȡ�������ɿ�״̬
GTR_EXPORT short GTR_IsKeyPressed(bool &result,const Gtr::Key &key);
GTR_EXPORT short GTR_IsKeyReleased(bool &result,const Gtr::Key &key);


//��ͣ��ť�ź�����(��ɫ��ͣ��ť)
GTR_EXPORT short GTR_LockEstopSignal(const bool &enable);

//������ʾ����ģʽʹ��״̬
GTR_EXPORT short GTR_SetNoneTeachPendantMode(const bool &enable);
GTR_EXPORT short GTR_GetNoneTeachPendantMode(bool &enable);

//�߼�ģʽ��ť(Կ��ģʽ�л�)
GTR_EXPORT short GTR_SetSystemMode(const Gtr::RUNNING_MODE &mode);








/*-------------��˽ӿ�-ʾ�̳���-----------------------*/

//����ʾ��ģʽʾ�̳��������кţ�����ǰ�����
GTR_EXPORT short GTR_SetTeachStartLine(const long &start_line,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetTeachStartLine(long &start_line,short channel = GtrCurrentChannel);


//����ʾ��ģʽ�µ�������������ǰ�����
GTR_EXPORT short GTR_SetTeachStartPrgFile(char *file_path,short start_line = 1,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetTeachStartPrgFile(char *file_path,short channel = GtrCurrentChannel);


//���ûط�ģʽʾ�̳��������кţ����ڻط�����
GTR_EXPORT short GTR_SetReplayStartLine(const long &start_line,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplayStartLine(long &start_line,short channel = GtrCurrentChannel);


//���ûط�ģʽ�����������ڻط�����
GTR_EXPORT short GTR_SetReplayStartPrgFile(char *file_path,short start_line = 1,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplayStartPrgFile(char *file_path,short channel = GtrCurrentChannel);


//��ȡ�ط�ģʽ�µ�ǰִ�е�ʾ�̳������� ��0=������1=�ӳ���2=ע��ָ�
GTR_EXPORT short GTR_GetReplayCurrentPrgType(short &prg_type,short channel = GtrCurrentChannel);


//��ȡ�ط�ģʽ�µ�ǰִ�е�ʾ���ļ�������������
GTR_EXPORT short GTR_GetReplayCurrentMainPrgName(char *prg_name,short channel = GtrCurrentChannel);


//��ȡ�ط�ģʽ�µ�ǰִ�е�ʾ���ļ�����
GTR_EXPORT short GTR_GetReplayCurrentPrgName(char *sub_prg_name,short channel = GtrCurrentChannel);


//��ȡ�ط�ģʽ�µ�ǰִ�е�ʾ���ļ�(������)�к�
GTR_EXPORT short GTR_GetReplayCurrentMainPrgLineNum(unsigned long &line_num,short channel = GtrCurrentChannel);


//��ȡ�ط�ģʽ�µ�ǰִ�е�ʾ���ļ��к�
GTR_EXPORT short GTR_GetReplayCurrentPrgLineNum(unsigned long &line_num,short channel = GtrCurrentChannel);

//@brief		����JOGģʽ�Ƿ�Ϊ����ģʽ
//@param[in]	<line>����ģʽ��true���ǲ���ģʽ��false
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_EXPORT short GTR_SetTeachJogMode(bool is_step,short channel);

//@brief		��ȡJOGģʽ�Ƿ�Ϊ����ģʽ
//@param[out]	<line>����ģʽ��true���ǲ���ģʽ��false
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_EXPORT short GTR_GetTeachJogMode(bool &is_step,short channel);





/*-------------��˽ӿ�-������д-----------------------*/


//��ȡgroup���Ƶ�����
GTR_EXPORT short GTR_GetChannelCtrlAxisNum(short &result,short channel = GtrCurrentChannel);


//��ȡָ��group�п��Ƶ�����
GTR_EXPORT short GTR_GetChannelRobotAxisNum(short &result,const short &index,short channel = GtrCurrentChannel);
 //��ȡָ��group�п��Ƶ�group�±�
GTR_EXPORT short GTR_GetChannelRobotId(short &result,const short &index,short channel = GtrCurrentChannel);

//��ȡ��һ��group�п��Ƶ�����
GTR_EXPORT short GTR_GetChannelFirstRobotAxisNum(short &result,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetChannelFirstRobotId(short &result,short channel = GtrCurrentChannel);


//��ȡ�ڶ���group�п��Ƶ�����
GTR_EXPORT short GTR_GetChannelSecondRobotAxisNum(short &result,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetChannelSecondRobotId(short &result,short channel = GtrCurrentChannel);


//��ȡָ��ͨ�����ⲿ�������
GTR_EXPORT short GTR_GetChannelExtAxisNum(short &result,short channel = GtrCurrentChannel);
//��ȡָ��ͨ�������Ŵ��������
GTR_EXPORT short GTR_GetChannelGantryAxisNum(short &result,short channel = GtrCurrentChannel);


//�����ò���
GTR_EXPORT short GTR_SetAxisConfig(const Gtr::AxisConfig &config,const short &axis_id);
GTR_EXPORT short GTR_GetAxisConfig(Gtr::AxisConfig &config,const short &axis_id);


//�����ò���-��1��ʼ
GTR_EXPORT short GTR_SetGroupConfig(const Gtr::GroupConfig &config,const short &group_id);
GTR_EXPORT short GTR_GetGroupConfig(Gtr::GroupConfig &config,const short &group_id);


//����������
GTR_EXPORT short GTR_SetControllerConfig(const Gtr::SysCtlParam &config);
GTR_EXPORT short GTR_GetControllerConfig(Gtr::SysCtlParam &config);


//ͨ�����Ʋ���
GTR_EXPORT short GTR_SetChannelConfig(const Gtr::SysChannelCtrlParam &config,short channel);
GTR_EXPORT short GTR_GetChannelConfig(Gtr::SysChannelCtrlParam &config,short channel);


//��λ�궨����
GTR_EXPORT short GTR_SetZeroCaliPosition(const long &abs_pos,const short &axis_id);
GTR_EXPORT short GTR_GetZeroCaliPosition(long &abs_pos,const short &axis_id);


//��ݻ����
GTR_EXPORT short GTR_SetZeroPosConfig(const Gtr::Point &value,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetZeroPosConfig(Gtr::Point &value,short channel = GtrCurrentChannel);


//����ϵ�������
GTR_EXPORT short GTR_SetCoordinateConfig(const Gtr::CoordSystem &config,const Gtr::TYPE_COORD &type,const short &index,short group = GtrCurrentGroup);
GTR_EXPORT short GTR_GetCoordinateConfig(Gtr::CoordSystem &config,const Gtr::TYPE_COORD &type,const short &index,short group = GtrCurrentGroup);


//��ͨѶ��-TCPָ������
GTR_EXPORT short GTR_SetTcpServerInfo(const Gtr::TcpServerConfig &config);
GTR_EXPORT short GTR_GetTcpServerInfo(Gtr::TcpServerConfig &config);

//��ͨѶ��-Modbus���������
GTR_EXPORT short GTR_SetModbusServerInfo(const Gtr::ModbusServerConfig &config);
GTR_EXPORT short GTR_GetModbusServerInfo(Gtr::ModbusServerConfig &config);

//��ͨѶ��-Modbus�ͻ�������
GTR_EXPORT short GTR_SetModbusClientInfo(const Gtr::ModbusClientConfig &config);
GTR_EXPORT short GTR_GetModbusClientInfo(Gtr::ModbusClientConfig &config);


//��λ���궨����
//TYPE = 0: ECS1�궨����
//TYPE = 1��ECS2�궨����
//TYPE = 2��ECS3�궨����
GTR_EXPORT short GTR_SetPositionerConfig(double param[6],const short &type,bool reset_sys,short group,short channel = 0);
GTR_EXPORT short GTR_GetPositionerConfig(double param[6],const short &type,short group,short channel = 0);


//�ع�궨����
//TYPE = 0: GCS1�궨����
//TYPE = 1��GCS2�궨����
GTR_EXPORT short GTR_SetGroundRailConfig(double param[6],const short &type,bool reset_sys,short group,short channel = 0);
GTR_EXPORT short GTR_GetGroundRailConfig(double param[6],const short &type,short group,short channel = 0);





/*-------------��˽ӿ�-ȫ�ֱ�����д-----------------------*/


//ȫ�ֱ���-�����ͱ���
GTR_EXPORT short GTR_SetVarB(const bool &value,const short &index);
GTR_EXPORT short GTR_GetVarB(bool &value,const short &index);
GTR_EXPORT short GTR_SetVarBUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarB(bool &result,const short &index);


//ȫ�ֱ���-�����ͱ���
GTR_EXPORT short GTR_SetVarI(const long &result,const short &index);
GTR_EXPORT short GTR_GetVarI(long &value,const short &index);
GTR_EXPORT short GTR_SetVarIUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarI(bool &result,const short &index);


//ȫ�ֱ���-ʵ���ͱ���
GTR_EXPORT short GTR_SetVarR(const double &result,const short &index);
GTR_EXPORT short GTR_GetVarR(double &value,const short &index);
GTR_EXPORT short GTR_SetVarRUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarR(bool &result,const short &index);


//ȫ�ֱ���-�ַ��ͱ���
GTR_EXPORT short GTR_SetVarSTR(char *result,const short &index);
GTR_EXPORT short GTR_GetVarSTR(char *result,const short &index);
GTR_EXPORT short GTR_SetVarSTRUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarSTR(bool &result,const short &index);


//ȫ�ֱ���-λ���ͱ���
GTR_EXPORT short GTR_SetVarP(const Gtr::Point &result,const short &index);
GTR_EXPORT short GTR_GetVarP(Gtr::Point &value,const short &index);
GTR_EXPORT short GTR_SetVarPUsed(const bool &used,const short &index);
GTR_EXPORT short GTR_IsUsedVarP(bool &result,const short &index);


//ϵͳ�ڲ�����
// index ��Χ�� 9000~9019
GTR_EXPORT short GTR_SetInternalVarB(const bool &value,const short &index); 
// index ��Χ�� 9000~9019
GTR_EXPORT short GTR_SetInternalVarI(const long &value,const short &index); 
// index ��Χ�� 9000~9019
GTR_EXPORT short GTR_SetInternalVarR(const double &value,const short &index); 

//ϵͳ�ڲ�����������ȡ���ӵ�1���ڲ�������ʼ��ȡ
GTR_EXPORT short GTR_SetInternalVarBEx(bool *value,const short &count); 
GTR_EXPORT short GTR_SetInternalVarIEx(long *value,const short &count); 
GTR_EXPORT short GTR_SetInternalVarREx(double *value,const short &count); 

// index ��Χ�� 9000~9019
GTR_EXPORT short GTR_GetInternalVarBEx(bool *value,const short &count); 
// index ��Χ�� 9000~9019
GTR_EXPORT short GTR_GetInternalVarIEx(long *value,const short &count); 
// index ��Χ�� 9000~9019
GTR_EXPORT short GTR_GetInternalVarREx(double *value,const short &count);



/*-------------��˽ӿ�-�������˶�-----------------------*/


//����ϵͳ��ǰͨ������
GTR_EXPORT short GTR_GetCurrentChannel(short &channel);
GTR_EXPORT short GTR_SetCurrentChannel(const short &channel);


//����ϵͳ��ǰGroup����
GTR_EXPORT short GTR_GetCurrentGroup(short &group);
GTR_EXPORT short GTR_SetCurrentGroup(const short &group,short channel = GtrCurrentChannel);


//�����������ŷ�״̬
GTR_EXPORT short GTR_IsChannelServoOn(bool &status,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_IsChannelServoOff(bool &status,short channel = GtrCurrentChannel);


//ֹͣ�����������˶�,��ʾ��ģʽ�µ�ǰ����飬�ط�����ʾ�̳����
GTR_EXPORT short GTR_StopMotion(short channel = GtrCurrentChannel);


//�����������ŷ�
GTR_EXPORT short GTR_RobotTeachServoOn(short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_RobotTeachServoOff(short channel = GtrCurrentChannel);


//�л�����ϵ����
GTR_EXPORT short GTR_SetTeachCoordType(const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup);
GTR_EXPORT short GTR_GetTeachCoordType(Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup);


//�л�����ϵID�ţ�ֻ֧��TCS��PCS(��������ϵ����������ϵ)
GTR_EXPORT short GTR_SetTeachCoordId(const Gtr::TYPE_COORD &coord_type,const short &coord_id,short group = GtrCurrentGroup);
GTR_EXPORT short GTR_GetTeachCoordId(short &coord_id,const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup);


//��Jog�˶�
// axis_type = 0-�ֳֺ�X����
// axis_type = 1-�ֳֺ�Y����
// axis_type = 2-�ֳֺ�Z����
// axis_type = 3-�ֳֺ�RX����
// axis_type = 4-�ֳֺ�RY����
// axis_type = 5-�ֳֺ�RZ����
// axis_type = 6-�ֳֺ�E1����
// axis_type = 7-�ֳֺ�E2����
//dir=true�������˶���dir=false�������˶�
GTR_EXPORT short GTR_StartTeachMoveJog(const Gtr::Key &key_type,bool refresh_abs = false);
GTR_EXPORT short GTR_StopTeachMoveJog(const Gtr::Key &key_type);


//�˶�����
GTR_EXPORT short GTR_StartTeachMoveToPoint(const short &point_id,short channel = GtrCurrentChannel,const bool is_need_forward_check = true);
GTR_EXPORT short GTR_StopTeachMoveToPoint();
GTR_EXPORT short GTR_GetTeachMoveToPointStatus(bool &status);


//ȫ���ٶȱ���-ʾ��ģʽ
GTR_EXPORT short GTR_SetTeachSpeedOverride(const double &speedOverride,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetTeachSpeedOverride(double &speedOverride,short channel = GtrCurrentChannel);

//ȫ���ٶȱ���-�˶����㡢ǰ����顢��ݻ���� 2021.06.26
GTR_EXPORT short GTR_SetMoveToSpeedOverride(const double &speedOverride,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetMoveToSpeedOverride(double &speedOverride,short channel = GtrCurrentChannel);


//�ط�ģʽ���������ŷ�
GTR_EXPORT short GTR_RobotReplayServoOn(short channel = GtrCurrentChannel);
//�ط�ģʽ���������ŷ�
GTR_EXPORT short GTR_RobotReplayServoOff(short channel = GtrCurrentChannel);


//���õ�ǰ�ط�ģʽ�µ�����ģʽ
//-1 �����ڻط�ģʽ
//0-����ѭ�� 
//1-����ѭ�� 
//2-�������� 
//3-��ָ̬��
GTR_EXPORT short GTR_SetReplayRunningMode(const short &mode,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplayRunningMode(short &mode,short channel = GtrCurrentChannel);


//ȫ���ٶȱ���-�ط�ģʽ
GTR_EXPORT short GTR_SetReplaySpeedOverride(const double &speedOverride,short channel = GtrCurrentChannel);
GTR_EXPORT short GTR_GetReplaySpeedOverride(double &speedOverride,short channel = GtrCurrentChannel);


//��ʼ����ʾ�̳���
GTR_EXPORT short GTR_StartReplayRun(short channel = GtrCurrentChannel);
//��ͣ����ʾ�̳���
GTR_EXPORT short GTR_PauseReplayRun(short channel = GtrCurrentChannel);




//HMIAXIS�������ŷ�
GTR_EXPORT short GTR_HmiAxisServoOn(const short &axis_id);
//HMIAXIS�������ŷ�
GTR_EXPORT short GTR_HmiAxisServoOff(const short &axis_id);


//��дHMIAXIS�ٶ�
GTR_EXPORT short GTR_SetHmiAxisVelocity(const short &axis_id,const double &vel);
GTR_EXPORT short GTR_GetHmiAxisVelocity(const short &axis_id,double &vel);

//��дHMIAXIS���ٶ�
GTR_EXPORT short GTR_SetHmiAxisAcceleration(const short &axis_id,const double &acc);
GTR_EXPORT short GTR_GetHmiAxisAcceleration(const short &axis_id,double &acc);

//��дHMIAXIS���ٶ�
GTR_EXPORT short GTR_SetHmiAxisDeceleration(const short &axis_id,const double &dec);
GTR_EXPORT short GTR_GetHmiAxisDeceleration(const short &axis_id,double &dec);

//HMIAXIS��ʼ�˶�
GTR_EXPORT short GTR_HmiAxisStart(const short &axis_id);

//HMIAXISֹͣ�˶�
GTR_EXPORT short GTR_HmiAxisStop(const short &axis_id);


//�����˸�����ϵ�ºϳ��ٶ� 
GTR_EXPORT short GTR_GetProfileSyntheticVelocity(double &vel,const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);
//�����˸�����ϵ�ºϳ��ٶ�(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetProfileSyntheticVelocity(double &vel,const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);


//�����˸�����ϵ�¹滮�ٶ�
GTR_EXPORT short GTR_GetProfileVelocity(double vel_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);
//�����˸�����ϵ�¹滮�ٶ�(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetProfileVelocity(double vel_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);


//�����˸�����ϵ�¹滮λ��
GTR_EXPORT short GTR_GetProfilePosition(double pos_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);
//�����˸�����ϵ�¹滮λ��(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetProfilePosition(double pos_list[8],const Gtr::TYPE_COORD &coord_type,short group = GtrCurrentGroup,short channel = GtrCurrentChannel);


//�����˸���Ĺ滮�ٶ�
GTR_EXPORT short GTR_GetAxisProfileVelocity(double &vel,const short &axis_id);
//�����˸���Ĺ滮�ٶ�(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetAxisProfileVelocity(double &vel,const short &axis_id);


//�����˸���Ĺ滮λ��
GTR_EXPORT short GTR_GetAxisProfilePosition(double &pos,const short &axis_id);
//�����˸���Ĺ滮λ��(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetAxisProfilePosition(double &pos,const short &axis_id);


//�����˸���Ĺ滮���ٶ�
GTR_EXPORT short GTR_GetAxisProfileAcceleration(double &acc,const short &axis_id);
//�����˸���Ĺ滮���ٶ�(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetAxisProfileAcceleration(double &acc,const short &axis_id);


//�����˱������ٶ�
GTR_EXPORT short GTR_GetEncoderVelocity(double &vel,const short &axis_id);
//�����˱������ٶ�(���ٽӿ�)
GTR_EXPORT short GTR_RT_GetEncoderVelocity(double &vel,const short &axis_id);

//�����˱�����λ��
GTR_EXPORT short GTR_GetEncoderPosition(double &pos,const short &axis_id);
//�����˱�����λ��(���ٽӿ�)
GTR_EXPORT short GTR_RT_GetEncoderPosition(double &pos,const short &axis_id);

//�����˱������������
GTR_EXPORT short GTR_GetEncoderFollowError(double &err,const short &axis_id);


//�����������ٶ�,index>=1
GTR_EXPORT short GTR_GetAuEncoderVelocity(double &vel, const short &index);
//�����������ٶ�(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetAuEncoderVelocity(double &vel, const short &index);
//����������λ��,index>=1
GTR_EXPORT short GTR_GetAuEncoderPosition(double &pos, const short &index);
//����������λ��(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetAuEncoderPosition(double &pos, const short &index);


//��������״̬��Ϣ
GTR_EXPORT short GTR_GetAxisStatus(Gtr::AxisStatus &status,const short &axis_id);


//�����˸�����ϵ�¹滮λ�ö�ȡ��λ���ͱ���
GTR_EXPORT short GTR_GetCurrentVarP(Gtr::Point &value,const Gtr::TYPE_COORD coord_type[2],short channel = GtrCurrentChannel);
//�����˸�����ϵ�¹滮λ����λ���ͱ���(���ٽӿ�Real-time��
GTR_EXPORT short GTR_RT_GetCurrentVarP(Gtr::Point &value,const Gtr::TYPE_COORD coord_type[2],short channel = GtrCurrentChannel);


//���Ӱڻ���ؽӿ�	2021.06.06
GTR_EXPORT short GTR_SetGroupWeaveParameter(const Gtr::GroupWeavePrm &para,short group);
GTR_EXPORT short GTR_GetGroupWeaveParameter(Gtr::GroupWeavePrm &para,short group);
//�����˶�������ؽӿ�  20210606
GTR_EXPORT short GTR_SetGroupSuperposition(const Gtr::GroupSuperpositionPrm &para,const short &coordSystem,const short &index,short group);
GTR_EXPORT short GTR_GetGroupSuperposition(Gtr::GroupSuperpositionPrm &para,const short &coordSystem,const short &index,short group);


//��ȡGroup�ĵ��ӹ��ܲ��� 2021.06.29
GTR_EXPORT short GTR_GetGroupSuperpositionValue(const short &group,const short &coordSystem,const short &index,double value[8]);




//���ƫ�ƽӿڣ����������ָ����ã���20211021���壩
//֧�ֵ�����ϵ�У�
//10:	MVCS �˶�����ϵ

/**
* @brief		����ƫ��
* @param[in]	<const & double> smooth_time ƽ��ʱ�� 0~255
* @param[in]	<const short &>coordSystem ƫ�Ƶ�����ϵ����,�ֽ�֧��10���˶�����ϵ��
* @param[in]	<short>group ��������ţ�0~2
* @param[out]	�� 
* @note			��֧��ͬʱ����1������ϵ���͵�ƫ��	
*	֧�ֵ�����ϵ����:10:	MVCS �˶�����ϵ
*/
GTR_EXPORT short GTR_SetOffsetOn(const double & smooth_time,const short &coordSystem,short group = GtrCurrentGroup);

/**
* @brief		�ر�ƫ��
* @param[in]	<short>group ��������ţ�0~2
* @param[out]	�� 
* @note			���ڻ����������˶�ʱ�ɵ���
*/
GTR_EXPORT short GTR_SetOffsetOff(short group = GtrCurrentGroup);

/**
* @brief		�������ƫ����
* @param[in]	<short>group ��������ţ�0~2
* @param[out]	�� 
* @note			���ڻ��������˶�ʱ�ɵ���
*/
GTR_EXPORT short GTR_SetOffsetRelativeValue(double relativeValue[8],short group = GtrCurrentGroup);

/**
* @brief		��ȡƫ��״̬
* @param[in]	<short>group ��������ţ�0~2
* @param[out]	<bool &>is_on ƫ�ƹ����Ƿ��
* @param[out]	<double &>smooth_time ��ǰ��Ч��ƽ��ʱ�䣬��δ���������Ч
* @param[out]	<double &>coordSystem ��ǰ��Ч������ϵ����δ���������Ч
* @note			
*/
GTR_EXPORT short GTR_GetOffsetStatus(bool & is_on, double & smooth_time,short &coordSystem,short group = GtrCurrentGroup);

/**
* @brief		 ��ȡƫ��ֵ�����Ż���
* @param[in]	<short>group  ��������ţ�0~2
* @param[in]	<coord>coordSystem ��ȡĿ������ϵ��ƫ��ֵ  
* @param[out]	<double offset_value[8]��ǰƫ��ֵ
* @note			
*/
GTR_EXPORT short GTR_GetOffsetValue(double offset_value[8],short &coordSystem,short group = GtrCurrentGroup);



/************************************************************************/
/*							����ģ�� 									*/
/************************************************************************/

//��������-��ӱ�����Ϣ
GTR_EXPORT short GTR_PushAlarmInfo(const long &id, long param1 = 0, long param2 = 0, long param3 = 0);
//��������-����Զ������ݱ�����Ϣ 
GTR_EXPORT short GTR_PushAlarmUserInfo(char *info,const long &id);
//��������-��ȡ������Ϣ�������б����Ƴ�������Ϣ
GTR_EXPORT short GTR_PopAlarmInfo(char *info, long &info_size, long &id);
//��������-��ȡ������Ϣ
GTR_EXPORT short GTR_GetAlarmInfo(char *info, long &info_size,long &id,const long &index);
//��������-��ȡ������Ϣ����
GTR_EXPORT short GTR_GetAlarmInfoCount(long &count);
//��������-���ָ��������Ϣ 
GTR_EXPORT short GTR_ClearAlarmInfo(const long &id);
//��������-������б�����Ϣ
GTR_EXPORT short GTR_ClearAllAlarmInfo();


//��������-��ȡ�������ݿ��¼
GTR_EXPORT short GTR_ReadAlarmInfoItem(Gtr::LogItem &item,const long &index);
//��������-������ȡ�������ݿ��¼
GTR_EXPORT short GTR_ReadAlarmInfoItems(std::vector<Gtr::LogItem> &items,const long &start_index,const long &end_index);

//��������-������ݿ��¼�����ݿ⻺��
GTR_EXPORT short GTR_AddAlarmInfoItem(char *id, char *info,const Gtr::LOG_TYPE &type, bool repeatable = true, bool auto_commit = false);

//��������-��ȡ�������ݿ��¼��
GTR_EXPORT short GTR_GetAlarmInfoItemsCount(long &count);

//��������-ɾ��ָ���±걨�����ݿ��¼ 
GTR_EXPORT short GTR_DeleteAlarmInfoItem(const long &index);
//��������-ɾ�����б������ݿ��¼ 
GTR_EXPORT short GTR_DeleteAllAlarmInfoItems();







/************************************************************************/
/*							��־ģ��									*/
/************************************************************************/

//����־��-��־�ȼ���С�����õ���־�ȼ��򲻼�����־���� 
GTR_EXPORT short GTR_GetLogLevel(Gtr::LOG_TYPE &level);
GTR_EXPORT short GTR_SetLogLevel(const Gtr::LOG_TYPE &level);

//����־��-�Զ��ύ�����ݿ�Ļ����¼���������¼���������Զ��ύ���������Զ��ύ�����ݿ� 
GTR_EXPORT short GTR_GetAutoCommitLogCount(long &count);
GTR_EXPORT short GTR_SetAutoCommitLogCount(const long &count);

//����־��-������ȡ���ݿ��¼���������ڰ汾��
GTR_EXPORT short GTR_ReadLogItems(std::vector<Gtr::GT_LogItem> &list, int count = 0);			//�������ڰ汾
GTR_EXPORT short GTR_ReadLogItems(std::vector<Gtr::GT_LogItem> &list,const int &start_index,const int &lenth);	//�������ڰ汾

//����־��-��ȡ���ݿ��¼ 
GTR_EXPORT short GTR_ReadLogItem(Gtr::LogItem &item,const long &index);
//����־��-������ȡ���ݿ��¼ 
GTR_EXPORT short GTR_ReadLogItems(std::vector<Gtr::LogItem> &items,const long &start_index,const long &end_index);

//����־��-������ݿ��¼�����ݿ⻺�� 
GTR_EXPORT short GTR_AddLogItem(char *info,const Gtr::LOG_TYPE &type, bool repeatable = true, bool auto_commit = false);

//����־��-��ȡ���ݿ��¼��
GTR_EXPORT short GTR_GetLogItemsCount(long &count);

//����־��-ɾ��ָ���±����ݿ��¼ 
GTR_EXPORT short GTR_DeleteLogItem(const long &index);
//����־��-ɾ���������ݿ��¼
GTR_EXPORT short GTR_DeleteAllLogItems();


#endif