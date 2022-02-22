#ifndef GTR_USER_INTERFACE_H
#define GTR_USER_INTERFACE_H
#include <QWidget>
#include <QString>
#include <QMultiMap>

#include "gtrobot_frontend_define.h"

///////////////////////////////////////////////////////////////////////// 
/// GTRobot	�̸߿Ƽ� ����ʽ�����鹤ҵ�����˿���ϵͳ����ƽ̨
/// Copyright (C) 2020 Googol Technology Ltd. All Rights Reserved.  
///   
/// @file		gtr_user_interface.h    
/// @brief		GTR���ջ����˿���ϵͳ-����ӿ�-���ݽӿڶ���  
/// @version 	v2.0.7.0         
//////////////////////////////////////////////////////////////////////////


class FrameInterface: public QWidget	//FrontEndInterface
{

public:
	virtual ~FrameInterface(){}
	
/**
 * @brief		��ʼ��������ϵͳ
 * @param[in]	��
 * @param[out]	��
 * @note		�ú�������������ϵͳ����ģ��ĳ�ʼ������PLC��NC������ģ���
 * @return		<0>: ��ʼ���ɹ�
 * @return		<1>: ��ʼ��ʧ��
 */	
	virtual short InitRobotSystem() = 0;
	
/**
 * @brief		��ȡ������ϵͳ�û�Ȩ�޵ȼ�
 * @param[in]	��
 * @param[out]	<PermissionLevel &level>: �û�Ȩ�޵ȼ�
 * @note		PermissionLevel::OPERATOR ������
 *				PermissionLevel::MANAGER  ����Ա
 *				PermissionLevel::FACTORY  ��������
 * @code		
 *				PermissionLevel level;
 *				FrameInterface *robot_interface = GetSysInstance(0);	//��ȡ������ϵͳ����
 * 				robot_interface->GetPermissionLevel(level);				//��ȡ�����˵�ǰ�û�Ȩ��
 * @endcode	
 * @return		<0>: ��ȡ�ɹ�
 * @return		<1>: ��ȡʧ��
 */
	virtual short GetPermissionLevel(front_gtr::PermissionLevel &level) = 0;
	
/**
 * @brief		���û�����ϵͳ�û�Ȩ�޵ȼ�
 * @param[in]	<PermissionLevel level>: �û�Ȩ�޵ȼ�
 * @note		PermissionLevel::OPERATOR ������
 *				PermissionLevel::MANAGER  ����Ա
 *				PermissionLevel::FACTORY  ��������
 * @code		
 *				PermissionLevel level = PermissionLevel::FACTORY;
 *				FrameInterface *robot_interface = GetSysInstance(0);	//��ȡ������ϵͳ����
 * 				robot_interface->SetPermissionLevel(level);				//���û����˵�ǰ�û�Ȩ��Ϊ"��������"
 * @endcode	
 * @return		<0>: ���óɹ�
 * @return		<1>: ����ʧ��
 */
	virtual short SetPermissionLevel(front_gtr::PermissionLevel level) = 0;

/**
 * @brief		��ȡ������ϵͳ�汾��Ϣ
 * @param[in]	��
 * @param[out]	<QString &version>: �汾��Ϣ
 * @note		�汾��ʽ��x.x.x.x ��2.0.1.2
 * @code		
 *				QString version;
 *				FrameInterface *robot_interface = GetSysInstance(0);	//��ȡ������ϵͳ����
 * 				robot_interface->GetRobotVersion(version);				//���û�����ϵͳ�汾��Ϣ
 * @endcode	
 * @return		<0>: ��ȡ�ɹ�
 * @return		<1>: ��ȡʧ��
 */	
	virtual short GetRobotVersion(QString &version) = 0;

	/**
 * @brief		��ȡ��ģ��汾��Ϣ
 * @param[in]	<ModuleType type>: ģ������
 * @param[out]	<QString &version>: �汾��Ϣ
 */
	virtual void GetModuleVersion(front_gtr::ModuleType type,QString &version) = 0;
	
/**
 * @brief		���ָ�������������ļ�(������������ʵ���͡��ַ��ͱ���)
 * @param[in]	<NumericVarType type>:��������
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:��������
 * @param[out]	<double &progress>:�洢������
 * @note		�������ļ��в�����ʱ�Զ�������xml�ڵ㣬��������ʱ����xml�ڵ�ֵ,�����������ڴ��д
 *				�����ڲ�����ʼ��progressΪ0����ɶ�д����ʱprocess = 100;
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
/*	virtual short SaveVarNumberToFile(front_gtr::NumericVarType type,QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;*/

/**
 * @brief		��Ӳ����ͱ����������ļ�
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:��������
 * @param[out]	<double &progress>:�洢������
 * @note		�������ļ��в�����ʱ�Զ�������xml�ڵ㣬��������ʱ����xml�ڵ�ֵ,�����������ڴ��д
 *				�����ڲ�����ʼ��progressΪ0����ɶ�д����ʱprocess = 100;
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveVarBToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;

/**
 * @brief		��������ͱ����������ļ�
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:��������
 * @param[out]	<double &progress>:�洢������
 * @note		�������ļ��в�����ʱ�Զ�������xml�ڵ㣬��������ʱ����xml�ڵ�ֵ,�����������ڴ��д
 *				�����ڲ�����ʼ��progressΪ0����ɶ�д����ʱprocess = 100;
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveVarIToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;

	/**
 * @brief		���ʵ���ͱ����������ļ�
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:��������
 * @param[out]	<double &progress>:�洢������
 * @note		�������ļ��в�����ʱ�Զ�������xml�ڵ㣬��������ʱ����xml�ڵ�ֵ,�����������ڴ��д
 *				�����ڲ�����ʼ��progressΪ0����ɶ�д����ʱprocess = 100;
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveVarRToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;

/**
 * @brief		����ַ��ͱ����������ļ�
 * @param[in]	<QMap<int,VAR_IableNumber> var_map>:��������
 * @param[out]	<double &progress>:�洢������
 * @note		�������ļ��в�����ʱ�Զ�������xml�ڵ㣬��������ʱ����xml�ڵ�ֵ,�����������ڴ��д
 *				�����ڲ�����ʼ��progressΪ0����ɶ�д����ʱprocess = 100;
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveVarStrToFile(QMap<int,front_gtr::VarNumber> var_map,double &progress) = 0;
/**
 * @brief		���ָ��id�������ļ�(λ�á�����λ���ͱ���)
 * @param[in]	<PositionVarType type>: ��������
 * @param[in]	<int id>: ����id
 * @param[out]	<VarPosition var>: ��Ҫ�洢��λ���ͱ���
 * @note		���ļ�β��׷���±����ڵ�,�����������ڴ��д
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveVarPToFile(front_gtr::PositionVarType type,int id,front_gtr::VarPosition var) = 0;
	
/**
 * @brief		����д��������ļ�(λ�á�����λ���ͱ���)
 * @param[in]	<PositionVarType type>: ��������
 * @param[in]	<QMap<int,VarPosition> var_map>: ��������
 * @param[out]	<double &progress>: �洢������
 * @note		�������ļ��в�����ʱ�Զ�������xml�ڵ㣬��������ʱ����xml�ڵ�ֵ,�����������ڴ��д
 *				�����ڲ�����ʼ��progressΪ0����ɶ�д����ʱprocess = 100;
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveVarsPToFile(front_gtr::PositionVarType type,QMap<int,front_gtr::VarPosition> var_map,double &progress) = 0;

/**
 * @brief		���浱ǰ����ʹ�õĿ������������ļ�
 * @param[in]	<front_gtr::SysCtlParam para>: �����������ṹ��
 * @param[out]	��
 * @note		ֻ���������ļ���д��,�����������ڴ��д
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 */
	virtual short SaveControllerConfigToFile(front_gtr::SystemParam para) = 0;

/**
 * @brief		���浱ǰ����ʹ�õ�ͨ���������ļ�
 * @param[in]	<int id>: ��Ҫ�����ͨ��ID��
 * @param[out]	��
 * @note		ֻ���������ļ���д��,�����������ڴ��д
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 */
	virtual short SaveChannelConfigToFile(short id) = 0;

/**
 * @brief		������ؽڲ������ļ�
 * @param[in]	<AxisConfig para>: ��ؽڲ����ṹ��
 * @param[in]	<int id>: ��Ҫ�������ID��
 * @param[out]	��
 * @note		ֻ���������ļ��Ķ�д(����д��ϱȲ���),�����������ڴ��д,id�±��0��ʼ����0Ϊ1��ؽڲ���
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveAxisConfigToFile(short id) = 0;

/**
 * @brief		���������ò������ļ�
 * @param[in]	<GroupConfig para>: �����ò����ṹ��
 * @param[in]	<int id>: ��Ҫ�������ID��
 * @param[out]	��
 * @note		ֻ���������ļ��Ķ�д(����д����ѧģ�Ͳ���),�����������ڴ��д,id�±��0��ʼ����0Ϊgroup1����
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */
	virtual short SaveGroupConfigToFile(short id) = 0;

/**
 * @brief		����DH�������ļ�
 * @param[in]	<DhCouplePara para>: ���˼���ϱ����ò���
 * @param[out]	��
 * @note		ֻ���������ļ��Ķ�д,�����������ڴ��д
 * @return		<0>: ��ӳɹ�
 * @return		<1>: ���ļ�ʧ��
 * @return		<2>: ���ʧ�ܣ��ڵ��Ѵ���
 * @return		<3>: ���ʧ�ܣ������쳣
 */	
	virtual short SaveMechModelConfigToFile(front_gtr::DhPara para,short group) = 0;

/**
 * @brief		��ȡ�����б������������Ϣ
 * @param[in]	<long &id>: ����id
 * @param[in]	<QString &msg>: ������Ϣ
 * @param[out]	��
 * @return		<0>: ��ȡ������Ϣ�ɹ�
 * @return		<-1>: ����ʧ�ܣ�������ϢΪ��
 * @note		���ϵͳ����״̬�������б�һ�����������ֵΪ-1
 */
	virtual short GetCurrentAlarm(QString &id,QString &msg) = 0;

/**
 * @brief		�����ݿ��������뱨����ʷ
 * @param[in]	<QMultiMap<int,QString> &alarm_map>: ������ʷ��Ϣ��int->����id,QString->��������
 * @param[out]	��
 * @note		ֻ���������ļ��Ķ�д,�����������ڴ��д
 * @return		<0>: ��ȡ�ɹ�
 * @return		<1>: ��ȡʧ��
 */	
	virtual short LoadAlarmFromFile(QMultiMap<QString,QString> &alarm_map) = 0;

/**
 * @brief		����д�뱨����ʷ���ļ�
 * @param[in]	<QMap<int,QString> &alarm_map>: ������ʷ��Ϣ��int:������ʷid,QString:��������
 * @param[out]	��
 * @note		��ȡ���100��������ʷ��¼
 * @return		<0>: д��ɹ�
 * @return		<n>: д��ʧ�ܣ�n Ϊд��ʧ�ܵ���Ŀ��
 */	
	virtual short SaveAlarmToFile(QMultiMap<QString,QString> &alarm_map) = 0;

/**
 * @brief		�����ݿ��������������־
 * @param[in]	��
 * @param[out]	<QList<LogItem> &log_list>: ������־��Ϣ
 * @note		��ȡ���100��������־��¼
 * @return		<0>: ��ȡ�ɹ�
 * @return		<1>: ��ȡʧ��
 */	
	virtual short LoadLogFromFile(QList<front_gtr::LogItem> &log_list) = 0;

/**
 * @brief		����д�������־���ļ�
 * @param[in]	<QString log>: ������־��Ϣ
 * @param[out]	��
 * @note		ֻ���������ļ��Ķ�д,�����������ڴ��д
 * @return		<0>: д��ɹ�
 * @return		<1>: д��ʧ��
 */	
	virtual short SaveLogToFile(QString log) = 0;

	/**
 * @brief		��ʾ������ϵͳHMI
 * @param[in]	��
 * @param[out]	��
 * @return		<0>: ���óɹ�
 * @return		<1>: ����ʧ��
 */		
	virtual short ShowHMI() = 0;
	
/**
 * @brief		���ػ�����ϵͳHMI
 * @param[in]	��
 * @param[out]	��
 * @return		<0>: ���óɹ�
 * @return		<1>: ����ʧ��
 */	
	virtual short HideHMI() = 0;


/**
 * @brief		�趨��ϼ���������+���ϵ���+��������Ƿ��˳�רҵ����
 * @param[in]	<bool flag>: true������Ч��false������Ч
 * @param[out]	��
 */
	virtual void EnableQuitKey(bool flag) = 0;

/**
 * @brief		�Ƿ񴴽�רҵ������̶���
 * @param[in]	<bool flag>: true�������̶���false���������̶���
 * @param[out]	��
 */
	virtual void CreateKeyBoard(bool flag) = 0;


/**
 * @brief		���ü��̵���ģʽ
 * @param[in]	<bool mode>: false������רҵ����ļ���,true����רҵ����ļ���
 * @param[out]	��
 */
	virtual void SetKeyBoardMode(bool mode) = 0;
	
/**
 * @brief		��ȡ���̵���ģʽ
 * @param[in]	��
 * @param[out]	��
 * @return		<false>: ������רҵ����ļ���
 * @return		<true>: ����רҵ����ļ���
 */
	virtual bool GetKeyBoardMode() = 0;

/**
* @brief		��ʾ���½ǡ����˵�����ť
* @param[out]	��
* @return		<0>: ���óɹ�
* @return		<1>: ����ʧ��
*/	
	virtual short ShowMainButton() = 0;

/**
 * @brief		�������½ǡ����˵�����ť
 * @param[out]	��
 * @return		<0>: ���óɹ�
 * @return		<1>: ����ʧ��
 */	
	virtual short HideMainButton() = 0;

signals:
	void SignalMStackWidget(int iPageNum);

}; 


#endif