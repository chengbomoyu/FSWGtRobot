#ifndef GTROBOT_BACKEND_INTERNAL_H
#define GTROBOT_BACKEND_INTERNAL_H

#include <QString>
#include <QMap>
#include <vector>
#include "gtrobot_backend_define.h"


#ifdef GTR_BACKEND_LIB
#define GTR_INTERNAL_EXPORT extern "C" __declspec(dllexport)
//#define GTR_INTERNAL_EXPORT __declspec(dllexport)
#else
#define GTR_INTERNAL_EXPORT extern "C" __declspec(dllimport)
//#define GTR_INTERNAL_EXPORT __declspec(dllimport)
#endif


namespace gtr_internal{

	//���˵�����
	enum MENU_TYPE
	{
		PROGRAM = 0,
		VARIABLE,
		CRAFT,
		STATUS,
		LOG,
		SETTING,
		SYSTEM,
		APPLICATION
	};

	//�û�Ȩ��
	enum USER_TYPE
	{
		OPERATOR = 0,
		MANAGER,
		FACTORY
	};

	//ԭö������ Axis_Type 2021.05.16
	enum AXIS_TYPE{

		FIRST_ROBOT,			//������1
		SECOND_ROBOT,			//������2
		EXT_AXIS,				//�ⲿ��
		NONE
	};


	//ԭö������ Firmware_Type 2021.05.16
	enum FIRMWARE_TYPE{

		ARM = 1,			//ARM�̼�
		FPGA = 2			//FPGA�̼�
	};

	//���˵�����
	struct MyMenuItem
	{
		QString class_name;
		QString menu_name;
		bool visiable;
	};


	//�����Ϣ
	struct ApplicationInfo
	{
		QString name;
		QString dllName;
		bool menuVis;
		bool launch;
		QString icon_menu;
		QString icon_common;
		QString icon_craft;
	};

	//ʾ�̳�����Ϣ
	struct RobProgramInfo 
	{
		char directory[256];
		char name[256];
	};

	struct CraftPipeParam
	{
		short craft_id;			
		long  long_param[4];
		double double_param[4];
	};


	struct WatchInfo
	{
		short enable;						// WATCHʹ�� 
		short run;							// WATCH״̬
		unsigned long time;					// WATCH����
		unsigned long head;					// WATCHͷָ��

		unsigned long threshold;			// ������ɲɼ�����
		short interval;						// �ɼ����
		short mode;							// �ɼ�ģʽ

		unsigned short count_before_event;	// �¼�����֮ǰ�Ĳɼ�����
		unsigned short count_after_event;	// �¼������Ժ�Ĳɼ�����
		unsigned short var_count;			// �ɼ�������Ŀ
		unsigned short event_count;			// �ɼ��¼�����
	};


	//(PCS/TCS)�ѿ�������ϵ�任����
	struct CartesianTransPrm
	{
		double transX;		//X��ƫ��������λ��mm��
		double transY;		//Y��ƫ��������λ��mm��
		double transZ;		//Z��ƫ��������λ��mm��
		double rotAngle1;	//��ת�Ƕ�1����λ���ȡ�
		double rotAngle2;	//��ת�Ƕ�2����λ���ȡ�
		double rotAngle3;	//��ת�Ƕ�3����λ���ȡ�
	};


	typedef short (*CraftPipeCallBack)(const CraftPipeParam &param,void *,void *);

}



//��ȡ�����ʱ��
GTR_INTERNAL_EXPORT short GTR_GetCompileDate(char time[256]);
//��ȡ���汾��Ϣ
GTR_INTERNAL_EXPORT short GTR_GetVersion(char version[100]);

//��ȡ�̼��汾��Ϣ
GTR_INTERNAL_EXPORT short GTR_GetFirmwareVersion(char version[20], gtr_internal::FIRMWARE_TYPE type);

/**
* @brief		ָ�������Ϣʹ�ܿ���
* @param[in]	none
* @note		������ʱ���������ö����ڿ���̨�ϴ�ӡ����������
*				Ĭ�ϹرոĹ���
*/
GTR_INTERNAL_EXPORT short GTR_DebugInfoEnable(const bool enable);



//��ȡDSP�滮���� 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetDspProfileTime(short core,unsigned long &time,unsigned long &timeMax);

//��ȡϵͳ�����ڴ�(��λ: byte) 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetAvailablePhysicalMemory(unsigned long &mem);

//��ȡϵͳ�����ڴ�ռ���� 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetAvailablePhysicalMemoryRate(unsigned long &rate);

//��ȡCPUռ���� 2021.06.25
GTR_INTERNAL_EXPORT short GTR_GetCpuUseRate(unsigned long &rate);

//��ȡNC�̵߳ĵ���ִ������ 2021.07.26
GTR_INTERNAL_EXPORT short GTR_GetNcPeriodTime(unsigned long &time);
//��ȡNC�̵߳�ѭ������ 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetNcCycleTime(unsigned long &time);

//��ȡPLC�̵߳ĵ���ִ������ 2021.07.26
GTR_INTERNAL_EXPORT short GTR_GetPlcPeriodTime(unsigned long &time);
//��ȡPLC�̵߳�ѭ������ 2021.09.22
GTR_INTERNAL_EXPORT short GTR_GetPlcCycleTime(unsigned long &time);


//��ȡ���籣���ź� 2021.07.26
GTR_INTERNAL_EXPORT short GTR_GetPowerStatus(long &status);


//ʾ��ģʽ-ǰ������˶���λ״̬ 2021.06.26
GTR_INTERNAL_EXPORT short GTR_IsForwardCheckFinished(bool &status,short channel);


//���������ģʽ 2021.06.30
GTR_INTERNAL_EXPORT short GTR_SetAxisSimulation(bool status,short axis_id);
GTR_INTERNAL_EXPORT short GTR_IsAxisSimulation(bool &status,short axis_id);

//����������λ 2021.06.30
GTR_INTERNAL_EXPORT short GTR_SetAxisSoftLimitEnable(bool enable,short axis_id);
GTR_INTERNAL_EXPORT short GTR_IsAxisSoftLimitEnable(bool &enable,short axis_id);


//���ս����ص�����
GTR_INTERNAL_EXPORT short GTR_RegisterCraftPipeCallback(short craft_type, gtr_internal::CraftPipeCallBack func);
//�๤�ս�����������
GTR_INTERNAL_EXPORT short GTR_CallCraftPipeFunc(short craft_type, const gtr_internal::CraftPipeParam &param, void *input, void *output);


//���ù���״̬
GTR_INTERNAL_EXPORT short GTR_SetCraftStatus(const short &status, short channel = GtrCurrentChannel);
GTR_INTERNAL_EXPORT short GTR_GetCraftStatus(short &status, short channel = GtrCurrentChannel);


//���ù����ٶ�---!!!��ָ������!!!
GTR_INTERNAL_EXPORT short GTR_SetCraftSpeed(const double &speed, short channel = GtrCurrentChannel);
GTR_INTERNAL_EXPORT short GTR_GetCraftSpeed(double &speed, short channel = GtrCurrentChannel);



//������+��λ���������� 2021.07.03
GTR_INTERNAL_EXPORT short GTR_SetGroupDynamicCoordinateParameter(short channel,bool enable);


//�������˲����� 2021.09.01
GTR_INTERNAL_EXPORT short GTR_SetAxisMotionSmooth(const double &time,const double &pk,const unsigned short &axis_index);
GTR_INTERNAL_EXPORT short GTR_GetAxisMotionSmooth(double &time, double &pk,const unsigned short &axis_index);



/************************************************************************/
/*						�ļ�����ģ�� 2021.09.15                         */
/************************************************************************/

//������ϵͳȫ�ֱ���-�����ͱ��������ļ����� 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarBFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarBToFile();

//������ϵͳȫ�ֱ���-�����ͱ��������ļ����� 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarIFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarIToFile();

//������ϵͳȫ�ֱ���-ʵ���ͱ��������ļ����� 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarRFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarRToFile();

//������ϵͳȫ�ֱ���-�ַ��ͱ��������ļ����� 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarSTRFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarSTRToFile();

//������ϵͳȫ�ֱ���-λ���ͱ��������ļ����� 2021.09.15
GTR_INTERNAL_EXPORT short GTR_ReadUsedVarPFromFile();
GTR_INTERNAL_EXPORT short GTR_SaveUsedVarPToFile();



/************************************************************************/
/*						Ȩ��ģ�� 2021.03.25                             */
/************************************************************************/

//��Ȩ�ޡ�-ϵͳȨ�����2021.03.25
GTR_INTERNAL_EXPORT short  GTR_SetSysPermission(const unsigned short &level);
GTR_INTERNAL_EXPORT short  GTR_GetSysPermission(unsigned short &level);

//��Ȩ�ޡ�-�����û�Ȩ��2021.04.14
GTR_INTERNAL_EXPORT short  GTR_SetUserType(const gtr_internal::USER_TYPE &user_type);
GTR_INTERNAL_EXPORT short  GTR_GetUserType(gtr_internal::USER_TYPE &user_type);

//��Ȩ�ޡ�-�����û�Ȩ��2021.04.14
GTR_INTERNAL_EXPORT short  GTR_GetUserTypeStr(QString &user_type_str);

//��Ȩ�ޡ�-�����û�Ȩ��2021.04.14
GTR_INTERNAL_EXPORT short  GTR_SetUserPwdStr(const QString &user_pwd_str,const gtr_internal::USER_TYPE &user_type);
GTR_INTERNAL_EXPORT short  GTR_GetUserPwdStr(QString &user_pwd_str,const gtr_internal::USER_TYPE &user_type);

//��Ȩ�ޡ�-�����û�Ȩ��2021.04.14
GTR_INTERNAL_EXPORT short GTR_GetMenuPermission(const gtr_internal::MENU_TYPE &menu_type, QList<gtr_internal::MyMenuItem>& permission);

//��Ȩ�ޡ�-��ȡ�����Ϣ2021.04.14
GTR_INTERNAL_EXPORT short GTR_ReadAppInfoList(const gtr_internal::USER_TYPE &user_type, QMap<short, gtr_internal::ApplicationInfo> &info_map);




/************************************************************************/
/*							ͨѶģ��				                    */
/************************************************************************/

//��ͨѶ��-�ⲿ����,�Ƿ���ԤԼ״̬
GTR_INTERNAL_EXPORT short GTR_SetRemoteReserveStatus(bool status, short channel = GtrCurrentChannel);
//��ͨѶ��-�ⲿ����,��ȡԤԼ״̬
GTR_INTERNAL_EXPORT short GTR_GetRemoteReserveStatus(bool &status, short channel = GtrCurrentChannel);

//��ͨѶ��-�ⲿ����,�Ƿ����ظ�ԤԼ
GTR_INTERNAL_EXPORT short GTR_SetRemoteRepeatReserveStatus(bool status, short channel = GtrCurrentChannel);
//��ͨѶ��-�ⲿ����,��ȡ�ظ�ԤԼ
GTR_INTERNAL_EXPORT short GTR_GetRemoteRepeatReserveStatus(bool &status, short channel = GtrCurrentChannel);

//��ͨѶ��-�ⲿ����,����ԤԼ�����б�
GTR_INTERNAL_EXPORT short GTR_SetProgramConfigList(gtr_internal::RobProgramInfo *info, int len, short channel = GtrCurrentChannel);
//��ͨѶ��-�ⲿ����,��ȡԤԼ�����б�
GTR_INTERNAL_EXPORT short GTR_GetProgramOrderList(std::vector<gtr_internal::RobProgramInfo> &info_vector, short channel = GtrCurrentChannel);
//��ͨѶ��-�ⲿ����,���ԤԼ�����б�
GTR_INTERNAL_EXPORT short GTR_ClearProgramOrderList(short channel = GtrCurrentChannel);


//��ͨѶ��-TCPָ������
GTR_INTERNAL_EXPORT short GTR_SetTcpServerConfig(const Gtr::TcpServerConfig config);
GTR_INTERNAL_EXPORT short GTR_GetTcpServerConfig(Gtr::TcpServerConfig &config);
GTR_INTERNAL_EXPORT short GTR_GetTcpServerConnectListList(std::vector<Gtr::TcpConnectClientInfo> &list);
GTR_INTERNAL_EXPORT short GTR_GetModbusTcpClientConnectStatus(bool &status);

//��ͨѶ��-Modbus���������
GTR_INTERNAL_EXPORT short GTR_SetModbusServerConfig(const Gtr::ModbusServerConfig config);
GTR_INTERNAL_EXPORT short GTR_GetModbusServerConfig(Gtr::ModbusServerConfig &config);
GTR_INTERNAL_EXPORT short GTR_GetModbusTcpServerConnectList(std::vector<Gtr::TcpConnectClientInfo> &list);

//��ͨѶ��-Modbus�ͻ�������
GTR_INTERNAL_EXPORT short GTR_SetModbusClientConfig(const Gtr::ModbusClientConfig config);
GTR_INTERNAL_EXPORT short GTR_GetModbusClientConfig(Gtr::ModbusClientConfig &config);





/************************************************************************/
/*						WATCHģ�� 2021.05.24                            */
/************************************************************************/
GTR_INTERNAL_EXPORT short GTR_GetcontrollerWatchInfo(short core,gtr_internal::WatchInfo &info);
GTR_INTERNAL_EXPORT short GTR_ControllerWatchOn(short core,char* path);
GTR_INTERNAL_EXPORT short GTR_ControllerWatchOffAndPrint(short core,char* path);



//PCS��TCSƫ�ƽӿ� 2021.06.01
GTR_INTERNAL_EXPORT short GTR_SetGroupCartesianTransform(short group, Gtr::TYPE_COORD coordSystem,gtr_internal::CartesianTransPrm para);
GTR_INTERNAL_EXPORT short GTR_GetGroupCartesianTransform(short group, Gtr::TYPE_COORD coordSystem,gtr_internal::CartesianTransPrm &para);




/************************************************************************/
/*						JOG����ģ�� 2021.06.12                          */
/************************************************************************/

//�л�����һ�������JOG���� 2021.06.12
GTR_INTERNAL_EXPORT short GTR_NextRobotJogControlMap(short channel);
//�л�����һ�������JOG���� 2021.06.12
GTR_INTERNAL_EXPORT short GTR_PreviousRobotJogControlMap(short channel);

//�л�����һ���ⲿ��JOG���� 2021.06.12
GTR_INTERNAL_EXPORT short GTR_NextExtJointJogControlMap(short channel);
//�л�����һ���ⲿ��JOG���� 2021.06.12
GTR_INTERNAL_EXPORT short GTR_PreviousExtJointJogControlMap(short channel);

//�л���������JOG���� 2021.06.12
GTR_INTERNAL_EXPORT short GTR_ChangeToRobotMode(short channel);
//�л����ⲿ��JOG���� 2021.06.12
GTR_INTERNAL_EXPORT short GTR_ChangeToExtJointMode(short channel);

//�л���������-˫���λ��JOG����
GTR_INTERNAL_EXPORT short GTR_ChangeToRobotPositionerMode(short group,short channel);
//�л���������-˫�ⲿ��JOG����
GTR_INTERNAL_EXPORT short GTR_ChangeToTwoExtJointControlMode(short channel);



/************************************************************************/
/*						��־ģ��(�ڲ��ӿ�) 2021.07.26                   */
/************************************************************************/

//����־�����ύ�����ݿ�(д�ļ�) 2021.07.26
GTR_INTERNAL_EXPORT short GTR_CommitToLogDataBase();




/************************************************************************/
/*						����ģ��(�ڲ��ӿ�) 2021.07.26                   */
/************************************************************************/

//����־�����ύ�����ݿ�(д�ļ�) 2021.07.26
GTR_INTERNAL_EXPORT short GTR_CommitToAlarmDataBase();



/************************************************************************/
/*							ͨ��ģ��									*/
/************************************************************************/

/**
* @brief		���TCP�ͻ������ӣ����ؿͻ��˾�����û��������ӿ�
* @param[in] 	<STcpServerInfo *info_>Զ��IP��ַ�Ͷ˿�
* @param[out] 	<HANDLE &client_handle> ���tcpclient�󷵻صľ�������ʧ����Ϊnull
* @note			����ͨѶ�����в�����ͨ�������ɡ�
* @return		
*/
GTR_INTERNAL_EXPORT short GTR_AddTcpClient(HANDLE &handle,Gtr::STcpServerInfo *info_=NULL);

/**
* @brief		�Ƴ�TCP�ͻ��ˡ��û��������ӿ�
* @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
* @param[out]	��
* @note			�Ƴ�TCP�ͻ��˺���ͨѶ��
* @return		<0>:�Ƴ�ʧ�ܣ�����ľ������
* @return		<1>:�Ƴ��ɹ�
*/
GTR_INTERNAL_EXPORT short GTR_RemoveTcpClient(HANDLE handle_=NULL);

/**
* @brief		��ȡTCP�ͻ��˵�ǰ״̬���û��������ӿ�
* @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
* @param[out]	<STcpClientStatus *status_>TCP�ͻ��˵�����״̬�ṹ��ָ��
* @note			ÿ�β���TCPͨѶǰ���ã�����ȷ����ǰͨѶ���ӵ�״̬��
* @return		<0>:��ȡʧ�ܣ�����ľ������
* @return		<1>:��ȡ�ɹ�
*/
GTR_INTERNAL_EXPORT short GTR_GetTcpClientStatus(HANDLE handle_=NULL,Gtr::STcpClientStatus *status_=NULL);


/**
* @brief		���ӷ���ˡ��û��������ӿ�
* @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
* @param[out]	��
* @note			�첽����������ָ��ִ�к�ͨ���ͻ��˵�ǰ״̬�ж��Ƿ����ӳɹ���
* @return		<-1>:�������󣬾��������
* @return		<0>:����ָ��ͳɹ�
*/
GTR_INTERNAL_EXPORT short GTR_ConnectToServer(HANDLE handle_=NULL);

/**
* @brief		�Ͽ����ӡ��û��������ӿ�
* @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
* @param[out]	��
* @note			�첽�������Ͽ�����ָ��ִ�к�ͨ���ͻ��˵�ǰ״̬�ж��Ƿ�ɹ��Ͽ����ӡ�
* @return		<-1>:�������󣬾��������
* @return		<0>:�Ͽ�����ָ��ͳɹ�
*/
GTR_INTERNAL_EXPORT short GTR_DisConnectToServer(HANDLE handle_=NULL);

/**
* @brief		�ͻ��˷������ݡ��û��������ӿ�
* @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
* @param[in] 	<char *data_>�������ݵ�ָ��
* @param[in] 	<int data_len>�������ݵ��ֽ���
* @param[out]	��
* @note			�첽������ͨѶ�̺߳�ִ̨�С�
* @return		<-1>:�������󣬾��������
* @return		<0>:���ͳɹ�
*/
GTR_INTERNAL_EXPORT short GTR_ClientSendData(HANDLE handle_=NULL,char *data_=NULL,int data_len=0);

/**
* @brief		�ͻ��˶�ȡ���ݡ��û��������ӿ�
* @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
* @param[in] 	<char *data_>�������ݵ�ָ��
* @param[out]	��
* @note			ͨ���ͻ���״̬��allow_read������ȷ���Ƿ������ݿɶ����ڲ������ݳأ�һ�οɶ�ȡһ�������������ݶ�ȡ��ɺ����ݳ���գ�allow_read״̬��λ��
* @return		<-1>:�������󣬾��������
* @return		<����>:���յ��������ֽ���
*/
GTR_INTERNAL_EXPORT short GTR_ClientReadData(HANDLE handle_=NULL,char *data_=NULL);





/************************************************************************/
/*							���ݽ���ģ��									*/
/************************************************************************/

// ִ�л�����ϵͳ�α�����������
// @param [in/out] buf ����/����Ĳα�������������󳤶�ΪGtrMaxBufSize
// @param [in/out] data_type ����/����ı�����������
// @param [in] action �����������
// @param [in] craft ���빤������
// @param [in] id ����α���ID
// @param [in] id2 ����Ķ���������Ĭ��Ϊ1
// @param [in] id3 ���������������Ĭ��Ϊ1
GTR_INTERNAL_EXPORT short GTR_DoRobotValueAction(char buf[GtrMaxBufSize], 
												 Gtr::DataType & data_type,
												 const Gtr::ActionType & action, 
												 const Gtr::CraftType & craft,
												 const long id, 
												 const short id2=1, 
												 const short id3=1);

// ע�������ϵͳ�α�����������
// @param [in] craft ���빤������
// @param [in] func ����ĺ���ָ��
// @note: ������øýӿڣ������ٴε��øýӿڣ���������ĺ���ָ������ΪNULL
GTR_INTERNAL_EXPORT short GTR_RegisterRobotValueAction(Gtr::CraftType craft, Gtr::GTR_RobotValueAction func);


/*-------------�α����ӿ� - ��������ת������-----------------------*/

// ��������ϵͳ����������ת��Ϊ�ɶ��ַ���
// @param [out] out_str, ����Ŀɶ��ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
// @param [in] in_buf, ����Ķ���������, ���ݵ���󳤶�ΪGtrMaxBufSize
// @param [in] data_type ���������ݵ���������
GTR_INTERNAL_EXPORT short GTR_BinToStr(char out_str[GtrMaxBufSize], char in_buf[GtrMaxBufSize], const Gtr::DataType & data_type);


// ���ɶ��ַ���ת��Ϊ������ϵͳ����������
// @param [out] out_buf, ����Ķ���������, ���ݵ���󳤶�ΪGtrMaxBufSize
// @param [in] in_str, ����Ŀɶ��ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
// @param [in] data_type ���������ݵ���������
GTR_INTERNAL_EXPORT short GTR_StrToBin(char out_buf[GtrMaxBufSize], char in_str[GtrMaxBufSize], const Gtr::DataType & data_type);


// ��������ϵͳ����������λ�á�����ת��Ϊ�ַ���
// @param [out] out_str, ����ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
// @param [in] value, �����������λ��
GTR_INTERNAL_EXPORT short GTR_GroupPointToStr(char out_str[GtrMaxBufSize], const Gtr::GroupPoint & value);


// ���ַ���ת��Ϊ������ϵͳ����������λ�á�����
// @param [out] value, �����������λ��
// @param [in] in_str, �����ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
GTR_INTERNAL_EXPORT short GTR_StrToGroupPoint(Gtr::GroupPoint & value, char in_str[GtrMaxBufSize]);


// ��������ϵͳ��λ���͡�����ת��Ϊ�ַ���
// @param [out] out_str, ����ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
// @param [in] value, ����λ���ͱ���
GTR_INTERNAL_EXPORT short GTR_PointToStr(char out_str[GtrMaxBufSize], const Gtr::Point & value);


// ���ַ���ת��Ϊ������ϵͳ��λ���͡�����
// @param [out] value, ���λ���ͱ���
// @param [in] in_str, �����ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
GTR_INTERNAL_EXPORT short GTR_StrToPoint(Gtr::Point & value, char in_str[GtrMaxBufSize]);


// ��������ϵͳ������ϵ������ת��Ϊ�ַ���
// @param [out] out_str, ����ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
// @param [in] value, ��������ϵ����
GTR_INTERNAL_EXPORT short GTR_CoordSystemToStr(char out_str[GtrMaxBufSize], const Gtr::CoordSystem & value);


// ���ַ���ת��Ϊ������ϵͳ������ϵ������
// @param [out] value, �������ϵ����
// @param [in] in_str, �����ַ���, �ַ�������󳤶�ΪGtrMaxBufSize
GTR_INTERNAL_EXPORT short GTR_StrToCoordSystem(Gtr::CoordSystem & value, char in_str[GtrMaxBufSize]);

//���ûط���������ʹ���źţ�Ĭ��Ϊtrue��Ĭ�Ͽ���ֱ�������ط�����
// @param [out] ��
// @param [in] enable, ���벼���ͱ�����Ĭ��Ϊtrue����ֱ�������ط����У���Ϊfalseʱ��ֹʾ����������ʹ��
GTR_INTERNAL_EXPORT short GTR_SetReplayStartEnable(bool enable);

//@brief		���ûط�ģʽǿ�������к�
//@param[in]	<line> �����к�
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_INTERNAL_EXPORT short GTR_SetForcedReplayStartLine(long line,short channel);

//@brief		��ȡ�ط�ģʽǿ�������к�
//@param[in]	<line> �����к�
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_INTERNAL_EXPORT short GTR_GetForcedReplayStartLine(long &line,short channel);

//@brief		���ûط�ģʽǿ�����������ļ���
//@param[in]	<line>�ط����������ļ���
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_INTERNAL_EXPORT short GTR_SetForcedReplayStartPrgDir(char path[256],short channel);

//@brief		��ȡ�ط�ģʽǿ�����������ļ���
//@param[in]	<line>�ط����������ļ���
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_INTERNAL_EXPORT short GTR_GetForcedReplayStartPrgDir(char path[256],short channel);

//@brief		���ûط�ģʽǿ�����������ļ���
//@param[in]	<line>�ط����������ļ���
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_INTERNAL_EXPORT short GTR_SetForcedReplayStartPrgName(char path[256],short channel);

//@brief		��ȡ�ط�ģʽǿ�����������ļ���
//@param[in]	<line>�ط����������ļ���
//@param[in] 	<channel> ͨ����
//@param[out]	��		
GTR_INTERNAL_EXPORT short GTR_GetForcedReplayStartPrgName(char path[256],short channel);



#endif