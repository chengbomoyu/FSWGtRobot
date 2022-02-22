/*! 
*@file robot_comm_interface.h
*@brief ������ϵͳͨѶ��
*@author �� zhang.zb@googoltech.com
*@version v1.0.0
*@date 2020-10-12
*/
#ifndef ROBOT_COMM_INTERFACE_H
#define ROBOT_COMM_INTERFACE_H
#include "comm_struct_define.h"
#include <vector>
#include <string>

#ifdef ROBOTCOMM_LIB
#define RobotCommApi extern "C" __declspec(dllexport) //Q_DECL_EXPORT
#define RobotCommCpp __declspec(dllexport)
#else
#define RobotCommApi extern "C" __declspec(dllimport)	//Q_DECL_IMPORT
#define RobotCommCpp __declspec(dllimport)
#endif

using namespace std;
namespace CRobotComm
{

	/**
	 * @brief		ɾ������ͨѶģ���ࡣϵͳ�������ӿ�
	 * @param[in]	�� 
	 * @param[out]	�� 
	 * @note		��ϵͳ����˳�ǰ����,�����ͷ�ͨѶ�������Դ	
	 */
	RobotCommApi void deleteInstance();

	/**
	 * @brief		����ModbusTCP�ͻ���ͨѶ���ò�����ϵͳ�������ӿ�
	 * @param[in] 	<SModbusTcpClientInfo *info>ModbusTcp�ͻ����������ò���ָ��
	 * @param[out]	��
	 * @note		����ͨѶ��ز����������ر�ͨѶ��ͨ������ӿ�ʵ��
	 */
	RobotCommApi void setModbusTcpClientInfo(SModbusTcpClientInfo *info);

	/**
	 * @brief		��ȡModbusTCP�ͻ���ͨѶ���ò�����ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��
	 * @return		���ص�ǰʹ�õ�ModbusTcp�ͻ����������ò���ָ��
	 */
	RobotCommApi SModbusTcpClientInfo * getModbusTcpClientInfo();

	/**
	 * @brief		ModbusTCP�ͻ���ͨѶ����ѭ��ʵ�ֽӿڡ�ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��Ҫ��PLC�߳����ڵ��á����PLC�߳�û���������У��޷�ͨѶ��
	 */
	RobotCommApi void loopModbusTcpClient();

	/**
	 * @brief		��ȡModbusTCP�ͻ���ͨѶ����״̬��ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		�� 	
	 * @return		<false>:������״̬
	 * @return		<true>:����״̬
	 */
	RobotCommApi bool getModbusTcpClientConnectStatus();

	/**
	 * @brief		����ModbusTCP�����ͨѶ���ò�����ϵͳ�������ӿ�
	 * @param[in] 	<SModbusTcpServerInfo *info>ModbusTcp������������ò���ָ��
	 * @param[out]	��
	 * @note		����ͨѶ��ز����������ر�ͨѶ��ͨ������ӿ�ʵ��
	 */
	RobotCommApi void setModbusTcpServerInfo(SModbusTcpServerInfo *info);

	/**
	 * @brief		��ȡModbusTCP�����ͨѶ���ò�����ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��
	 * @return		���ص�ǰʹ�õ�ModbusTcp������������ò���ָ��
	 */
	RobotCommApi SModbusTcpServerInfo * getModbusTcpServerInfo();

	/**
	 * @brief		ModbusTCP�����ͨѶ����ѭ��ʵ�ֽӿڡ�ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��Ҫ��PLC�߳����ڵ��á����PLC�߳�û���������У��޷�ͨѶ��
	 */
	RobotCommApi void loopModbusTcpServer();

	/**
	 * @brief		��ȡModbusTCP�����Զ�������б�ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��
	 * @return		�����������ӵĿͻ����б���Ϣ������IP�Ͷ˿�
	 */
	RobotCommCpp vector<STcpConnectClientInfo> getModbusTcpServerConnectList();


	/**
	 * @brief		����Զ��TCP�����ͨѶ���ò�����ϵͳ�������ӿ�
	 * @param[in] 	<SUserTcpServerInfo *info>��������IP��ַ���˿ڵ���Ϣ
	 * @param[out]	��
	 * @note		Զ��TCPЭ�飬������ϵͳ��ΪTCP����ˣ���Ҫ���ñ��ص�IP��ַ�Ͷ˿ڡ���ͣҲͨ���˽ӿ�ʵ�֡�
	 */
	RobotCommApi void setUserTcpServerInfo(SUserTcpServerInfo *info);

	/**
	 * @brief		��ȡԶ��TCPЭ������ͨѶ���ò�����ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��
	 * @return		���ص�ǰʹ�õ��Զ���TCP������������ò���ָ��
	 */
	RobotCommApi SUserTcpServerInfo * getUserTcpServerInfo();

	/**
	 * @brief		Զ��TCPЭ��,�����˷����ͨѶѭ��ʵ�ֽӿڡ�ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��Ҫ��PLC�߳����ڵ��á����PLC�߳�û���������У��޷�ͨѶ��
	 */
	RobotCommApi void loopUserTcpServer();


	/**
	 * @brief		��ȡԶ��TCP�����Զ�������б�ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��
	 * @return		�����������ӵĿͻ����б���Ϣ������IP�Ͷ˿�
	 */
	RobotCommCpp vector<STcpConnectClientInfo> getUserTcpServerConnectList();


	/**
	 * @brief		����Զ��TCP����Ӧ����ָ�롣ϵͳ�������ӿ�
	 * @param[in] 	Ӧ����ָ��
	 * @param[out]	��
	 * @note		�� 	
	 * @return		<false>:����ʧ��
	 * @return		<true>:���óɹ�
	 */
	RobotCommApi bool setRemoteTcpResponseCallback(RemoteTcpResponseCallback pFunc=NULL);

	/**
	 * @brief		��ȡԶ��TCP����Ӧ����ָ�롣ϵͳ�������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		�� 	
	 * @return		Ӧ����ָ��
	 */
	RobotCommApi RemoteTcpResponseCallback getRemoteTcpResponseCallback();					

	/**
	 * @brief		����Gibbon����ʹ�ܱ���ָ���ͨѶ�������ɺ���ָ�롣ϵͳ�������ӿ�
	 * @param[in] 	ʹ�ܴ�������ָ��
	 * @param[in] 	������ɺ���ָ��
	 * @param[out]	��
	 * @note		�� 	
	 * @return		<false>:����ʧ��
	 * @return		<true>:���óɹ�
	 */
	RobotCommApi bool setGibbonTrig(bool * enb = NULL,GibbonResponseCallback pFunc=NULL);

	/**
	 * @brief		������ModbusTCP�Ӿ��ͻ���ͨѶ���ò������û��������ӿ�
	 * @param[in] 	<SModbusTcpClientInfo *info>ModbusTcp�ͻ����������ò���ָ��
	 * @param[out]	��
	 * @note		����ͨѶ��ز����������ر�ͨѶ��ͨ������ӿ�ʵ��
	 */
	RobotCommApi void setModbusTcpClientVisionInfo(SModbusTcpClientInfo *info);

	/**
	 * @brief		��ȡModbusTCP�Ӿ��ͻ���ͨѶ���ò������û��������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		��
	 * @return		���ص�ǰʹ�õ�ModbusTcp�ͻ����������ò���ָ��
	 */
	RobotCommApi SModbusTcpClientInfo * getModbusTcpClientVisionInfo();

	/**
	 * @brief		��ȡModbusTCP�Ӿ��ͻ���ͨѶ����״̬���û��������ӿ�
	 * @param[in] 	��
	 * @param[out]	��
	 * @note		�� 	
	 * @return		<false>:������״̬
	 * @return		<true>:����״̬
	 */
	RobotCommApi bool getModbusTcpClientVisionConnectStatus();

	/**
	 * @brief		����ModbusTCP�Ӿ��ͻ��˸���ͨѶ����û��������ӿ�
	 * @param[in] 	<SModbusTcpClientCmdEx *cmd>ͨѶ�������ݵ�ָ��
	 * @param[out]	��
	 * @note		��Ӷ����ͨѶ����һ�Σ�ͨ������Ľṹ���ڲ����ݷ���ֵ���жϸ���ͨѶ�����Ƿ�ִ����ɡ���ִ����ɺ�ſ��Խ�����һ�θ���ͨѶ��
	 * @return		<false>:���ʧ��
	 * @return		<true>:��ӳɹ�
	 */
	RobotCommApi bool addModbusTcpClientCmdEx(SModbusTcpClientCmdEx *cmd);


	/**
	 * @brief		���TCP�ͻ������ӣ����ؿͻ��˾�����û��������ӿ�
	 * @param[in] 	<STcpServerInfo *info_>Զ��IP��ַ�Ͷ˿�
	 * @param[out]	��
	 * @note		ͨѶ�����в�����ͨ�������ɡ�
	 * @return		<NULL>:���ʧ��
	 * @return		<����>:���ֵ
	 */
	RobotCommApi HANDLE addTcpClient(STcpServerInfo *info_=NULL);

	/**
	 * @brief		�Ƴ�TCP�ͻ��ˡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
	 * @param[out]	��
	 * @note		�Ƴ�TCP�ͻ��˺���ͨѶ��
	 * @return		<false>:�Ƴ�ʧ�ܣ�����ľ������
	 * @return		<true>:�Ƴ��ɹ�
	 */
	RobotCommApi bool removeTcpClient(HANDLE handle_=NULL);

	/**
	 * @brief		��ȡTCP�ͻ��˵�ǰ״̬���û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
	 * @param[out]	<STcpClientStatus *status_>TCP�ͻ��˵�����״̬�ṹ��ָ��
	 * @note		ÿ�β���TCPͨѶǰ���ã�����ȷ����ǰͨѶ���ӵ�״̬��
	 * @return		<false>:��ȡʧ�ܣ�����ľ������
	 * @return		<true>:��ȡ�ɹ�
	 */
	RobotCommApi bool getTcpClientStatus(HANDLE handle_=NULL,STcpClientStatus *status_=NULL);

	/**
	 * @brief		���ӷ���ˡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
	 * @param[out]	��
	 * @note		�첽����������ָ��ִ�к�ͨ���ͻ��˵�ǰ״̬�ж��Ƿ����ӳɹ���
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:����ָ��ͳɹ�
	 */
	RobotCommApi int connectToServer(HANDLE handle_=NULL);

	/**
	 * @brief		�Ͽ����ӡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
	 * @param[out]	��
	 * @note		�첽�������Ͽ�����ָ��ִ�к�ͨ���ͻ��˵�ǰ״̬�ж��Ƿ�ɹ��Ͽ����ӡ�
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:�Ͽ�����ָ��ͳɹ�
	 */
	RobotCommApi int disConnectToServer(HANDLE handle_=NULL);

	/**
	 * @brief		�ͻ��˷������ݡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
	 * @param[in] 	<char *data_>�������ݵ�ָ��
	 * @param[in] 	<int data_len>�������ݵ��ֽ���
	 * @param[out]	��
	 * @note		�첽������ͨѶ�̺߳�ִ̨�С�
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:���ͳɹ�
	 */
	RobotCommApi int clientSendData(HANDLE handle_=NULL,char *data_=NULL,int data_len=0);

	/**
	 * @brief		�ͻ��˶�ȡ���ݡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP�ͻ��˵ľ��
	 * @param[in] 	<char *data_>�������ݵ�ָ��
	 * @param[out]	��
	 * @note		ͨ���ͻ���״̬��allow_read������ȷ���Ƿ������ݿɶ����ڲ������ݳأ�һ�οɶ�ȡһ�������������ݶ�ȡ��ɺ����ݳ���գ�allow_read״̬��λ��
	 * @return		<-1>:�������󣬾��������
	 * @return		<����>:���յ��������ֽ���
	 */
	RobotCommApi int clientReadData(HANDLE handle_=NULL,char *data_=NULL);

	/**
	 * @brief		���TCP����ˣ����ط���˾�����û��������ӿ�
	 * @param[in] 	<STcpServerInfo *info_>����IP��ַ�Ͷ˿�
	 * @param[out]	��
	 * @note		ͨѶ�����в�����ͨ�������ɡ�
	 * @return		<NULL>:���ʧ��
	 * @return		<����>:���ֵ
	 */
	RobotCommApi HANDLE addTcpServer(STcpServerInfo *info_=NULL);

	/**
	 * @brief		�Ƴ�TCP����ˡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[out]	��
	 * @note		�Ƴ�TCP����˺���ͨѶ��
	 * @return		<false>:�Ƴ�ʧ�ܣ�����ľ������
	 * @return		<true>:�Ƴ��ɹ�
	 */
	RobotCommApi bool removeTcpServer(HANDLE handle_=NULL);

	/**
	 * @brief		��ȡTCP����������б��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[out]	<vector<STcpConnectClientInfo> *>��ǰTCP����˵Ŀͻ��������б�ָ��
	 * @note		�����ϣ�һ������˵����Ӹ���û�����ޡ�
	 * @return		<false>:��ȡʧ�ܣ�����ľ������
	 * @return		<true>:��ȡ�ɹ�
	 */
	RobotCommCpp bool getTcpServerConnectList(HANDLE handle_=NULL,vector<STcpConnectClientInfo> *list=NULL);

	/**
	 * @brief		��������˼������û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[out]	��
	 * @note		��������˼�����ͨ����ȡ�����б�ʵ��ͨѶ
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:�����ɹ�
	 */
	RobotCommApi int startTcpServer(HANDLE handle_=NULL);

	/**
	 * @brief		�Ͽ����ӡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[in] 	<HANDLE connect_>TCP�ͻ��˵ľ��
	 * @param[out]	��
	 * @note		�첽�������Ͽ�����ָ��ִ�к�ͨ������������б��ж��Ƿ�ɹ��Ͽ����ӡ�
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:�Ͽ�����ָ��ͳɹ�
	 */
	RobotCommApi int disConnectToOneClient(HANDLE handle_=NULL,HANDLE connect_=NULL);

	/**
	 * @brief		����˷������ݡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[in] 	<HANDLE connect_>���ӵ��˷�����¿ͻ��˵ľ��
	 * @param[in] 	<char *data_>�������ݵ�ָ��
	 * @param[in] 	<int data_len>�������ݵ��ֽ���
	 * @param[out]	��
	 * @note		�첽������ͨѶ�̺߳�ִ̨�С�
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:���ͳɹ�
	 */
	RobotCommApi int serverSendData(HANDLE handle_=NULL,HANDLE connect_=NULL,char *data_=NULL,int data_len=0);

	/**
	 * @brief		����˶�ȡ���ݡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[in] 	<HANDLE connect_>���ӵ��˷�����¿ͻ��˵ľ��
	 * @param[out] 	<char *data_>�������ݵ�ָ��
	 * @note		��Ҫ������ѯ�����������ȡ���ݡ�
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:û�пɶ�ȡ������
	 * @return		<����>:���յ��������ֽ���
	 */
	RobotCommApi int serverReadData(HANDLE handle_=NULL,HANDLE connect_=NULL,char *data_=NULL);

	/**
	 * @brief		���ModbusTCP����ˣ����ط���˾�����û��������ӿ�
	 * @param[in] 	<STcpServerInfo *info_>����IP��ַ�Ͷ˿�
	 * @param[out]	��
	 * @note		ͨѶ�����в�����ͨ�������ɡ�
	 * @return		<NULL>:���ʧ��
	 * @return		<����>:���ֵ
	 */
	RobotCommApi HANDLE addNormalModbusTcpServer(SModbusTcpServerNormalInfo *info_=NULL);

	/**
	 * @brief		�Ƴ�ModbusTCP����ˡ��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>TCP����˵ľ��
	 * @param[out]	��
	 * @note		�Ƴ�TCP����˺���ͨѶ��
	 * @return		<false>:�Ƴ�ʧ�ܣ�����ľ������
	 * @return		<true>:�Ƴ��ɹ�
	 */
	RobotCommApi bool removeNormalModbusTcpServer(HANDLE handle_=NULL);

	/**
	 * @brief		��ȡModbusTCP����������б��û��������ӿ�
	 * @param[in] 	<HANDLE handle_>ModbusTCP����˵ľ��
	 * @param[out]	<vector<STcpConnectClientInfo> *>��ǰTCP����˵Ŀͻ��������б�ָ��
	 * @note		�����ϣ�һ������˵����Ӹ���û�����ޡ�
	 * @return		<false>:��ȡʧ�ܣ�����ľ������
	 * @return		<true>:��ȡ�ɹ�
	 */
	RobotCommCpp bool getNormalModbusTcpServerConnectList(HANDLE handle_=NULL,vector<STcpConnectClientInfo> *list=NULL);

	/**
	 * @brief		��������˼������û��������ӿ�
	 * @param[in] 	<HANDLE handle_>ModbusTCP����˵ľ��
	 * @param[out]	��
	 * @note		��������˼�����ͨ����ȡ�����б�ʵ��ͨѶ
	 * @return		<-1>:�������󣬾��������
	 * @return		<0>:�����ɹ�
	 */
	RobotCommApi int startNormalModbusTcpServer(HANDLE handle_=NULL);

}

#endif // ROBOT_COMM_INTERFACE_H
