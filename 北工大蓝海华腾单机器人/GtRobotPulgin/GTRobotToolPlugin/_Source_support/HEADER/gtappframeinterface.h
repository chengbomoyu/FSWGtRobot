#ifndef GTAPPFRAMEINTERFACE_H
#define GTAPPFRAMEINTERFACE_H
#include <QWidget>
#include <QDialog>
#include <vector>
#include <QString>
#include <QtPlugin>

/**
 * @brief			�û������գ��������ӿ�
 * @note			�û��������ս�����ʱ����̳�GtAppFrameInterface
 * @note 			�ڲ��ָ��ʵ�ֵ�ĩβ����Ҫ��ע�����Կ�Լ��û����������
 * @example  	class UserHmi: public GtAppFrameInterface
							{
								Q_OBJECT
									Q_INTERFACES(GtAppFrameInterface)
								
								......
								
							public:
								QString getFrameName();
								QString getVersion();
								void FastTimerLoop();
								
								......
							}
							
							.....
							
							QString UserHmi::getVersion()
							{
								return "v1.0";
							}
							
							void UserHmi::FastTimerLoop()
							{
								// do something
							}
							
							......
							
							// ��ע�����Կ����RobotHmi�����Լ��û���������ƣ�UserDllName��
							Q_EXPORT_PLUGIN2("RobotHmi", UserDllName);	
 */
class GtAppFrameInterface: public QWidget
{
	
public:
	virtual ~GtAppFrameInterface(){}

/**
 * @brief			��ȡ���������
 * @param[in]	<void>
 * @return		<QString> �û����صĽ�������
 * @note			�������ƽ�������־�ļ�¼
 */
	virtual QString getFrameName() = 0;

/**
 * @brief			��ȡ����İ汾��Ϣ
 * @param[in]	<void>
 * @return		<QString> �û����صİ汾��Ϣ
 * @note			�汾��Ϣ�����ڰ汾���
 */
	virtual QString getVersion() = 0;

/**
 * @brief			����ܽ��涨���ڵ��øú�������Ƶ�ʣ�Լ100ms~120ms����һ�Σ�
 * @param[in]	<void>
 * @return 		<void>
 * @note			�û��豣֤���ú������ε���ʱ�䲻�ܹ�����������ѭ��
 */
	virtual void FastTimerLoop(){}

/**
 * @brief			����ܽ��涨���ڵ��øú�������Ƶ�ʣ�Լ1000ms����һ�Σ�
 * @param[in]	<void>
 * @return 		<void>
 * @note			�û��豣֤���ú������ε���ʱ�䲻�ܹ�����������ѭ��
 */
	virtual void SlowTimerLoop(){}

/**
 * @brief			����������һ��״̬
 * @param[in]	<void>
 * @return 		<bool> ����true��ʾִ������
 * @note			�ڲ��ӿڣ�����showFrame()����ǰ�Զ�����
 */
	virtual bool readLastTimeStatus(){ return false;}

 /**
 * @brief			���������ֳ�״̬
 * @param[in]	<void>
 * @return 		<bool> ����true��ʾִ������
 * @note			�ڲ��ӿڣ�����showFrame()�������Զ�����
 */
	virtual bool saveLastTimeStatus(){ return false;}

/**
 * @brief			��ʾ����
 * @param[in]	<void>
 * @return 		<bool> ����true��ʾִ������
 * @note			��ʾ���棬��������涨ʱ�����д����
 */
	virtual bool showFrame() = 0;
	
/**
 * @brief			���ؽ���
 * @param[in]	<void>
 * @return 		<bool> ����true��ʾִ������
 * @note			���ؽ��棬��������涨ʱ�����д����
 */
	virtual bool hideFrame() = 0;

/**
 * @brief			��ȡ�Ҳ���ʾ�����棨���������˵���ָ��
 * @param[in]	<void>
 * @return		<QDialog*>	�û�������ʾ�����棨���������˵����Ŀؼ�ָ��
 * @note			���������Ϸ��������������ʾ����ť��������Ļ�Ҳ൯������ʾ�����档�������ڡ���ʾ������������˵���ѡ�С����ա�������ʾ����ָ���Ӧ�Ŀؼ�
 * @note			�����߽�������Ϊ��ģ̬����
 */
	virtual QWidget* getRightShowFramePtr(){ return NULL;}

/**
 * @brief			��ȡ�����������ĸ���ť�˵�����
 * @param[in]	<const QString &menu_name> �˵�����
 * @param[in]	<const QString &icon_path> �˵�ͼ��·��
 * @return 		<QDialog*>	��ʾ����ָ��
 * @return		<NULL> ����ʧ��
 * @note			�����߰ѽ�����Ϊģ̬����
 */
	virtual QDialog* getForthMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			��ȡ���������������ť�˵�����
 * @param[in]	<const QString &menu_name> �˵�����
 * @param[in]	<const QString &icon_path> �˵�ͼ��·��
 * @return 		<QDialog*>	��ʾ����ָ��
 * @return		<NULL> ����ʧ��
 * @note			�����߽�������Ϊģ̬����
 */
	virtual QDialog* getFifthMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			��ȡ����������������ť�˵�����
 * @param[in]	<const QString &menu_name> �˵�����
 * @param[in]	<const QString &icon_path> �˵�ͼ��·��
 * @return 		<QDialog*>	��ʾ����ָ��
 * @return		<NULL> ����ʧ��
 * @note			�����߽�������Ϊģ̬����
 */
	virtual QDialog* getSixthMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			��ȡ�����������߸���ť�˵�����
 * @param[in]	<const QString &menu_name> �˵�����
 * @param[in]	<const QString &icon_path> �˵�ͼ��·��
 * @return 		<QDialog*>	��ʾ����ָ��
 * @return		<NULL> ����ʧ��
 * @note			�����߽�������Ϊģ̬����
 */
	virtual QDialog* getSeventhMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			��ȡ�û�ָ��༭������ָ��
 * @param[in]		<short cmd_id> �û�ָ��ID
 * @param[in]		<std::vector<double> para_vector> �û�ָ������б�
 * @return			<QDialog*>	�û����ز�������ҳ���ָ��
 * @note			��ʾ�̳�����棬ѡ���û�ָ�������༭���󣬽����ϳ��ֹ���ָ��༭��ť���������ٴε��ָ��༭��ť������ʾ����ָ���Ӧ�Ŀؼ�
 * @note			�����߽�������Ϊģ̬����
 */
	virtual QDialog* getCmdEditFramePtr(short cmd_id,std::vector<double> para_vector){ return NULL;}

/**
 * @brief		��ȡָ�ǰ��״̬��Ϣ
 * @param[in]	<short cmd_id> �û�ָ��ID
 * @param[in]	<std::vector<double>> para_vector �û�ָ������б�
 * @return 		<QString> ָ���״̬��Ϣ
 * @return		<����> ���ַ�������ʾ����ʧ��
 * @note		�����߻�ȡ�û����ص��ַ�����Ϣ�󣬽�����Ϣ��ӡ���������·���ɫ����Ϣ����
 */
	virtual QString getCmdFeedBackInfo(short cmd_id,std::vector<double> para_vector){ return "";}


/**
 * @brief		�����û�Ȩ��
 * @param[in]	short type:�û�Ȩ�޵ȼ�,
 *				type = 0: ������ԱȨ��
 *				type = 1: ����ԱȨ��
 *				type = 2: ����Ȩ��
 * @note		ÿ���л�����������ϵͳ�û�Ȩ�޸ı�ʱ���˺���������
 */
	virtual void setPermission(short type) = 0;


signals:
	void appHide();

};


QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(GtAppFrameInterface, "RobotHmi");
QT_END_NAMESPACE

#endif