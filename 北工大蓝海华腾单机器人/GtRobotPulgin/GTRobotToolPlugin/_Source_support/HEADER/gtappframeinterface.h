#ifndef GTAPPFRAMEINTERFACE_H
#define GTAPPFRAMEINTERFACE_H
#include <QWidget>
#include <QDialog>
#include <vector>
#include <QString>
#include <QtPlugin>

/**
 * @brief			用户（工艺）界面插件接口
 * @note			用户创建工艺界面插件时，需继承GtAppFrameInterface
 * @note 			在插件指令实现的末尾，需要标注插件密钥以及用户插件的名称
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
							
							// 标注插件密钥（“RobotHmi”）以及用户插件的名称（UserDllName）
							Q_EXPORT_PLUGIN2("RobotHmi", UserDllName);	
 */
class GtAppFrameInterface: public QWidget
{
	
public:
	virtual ~GtAppFrameInterface(){}

/**
 * @brief			获取界面的名称
 * @param[in]	<void>
 * @return		<QString> 用户返回的界面名称
 * @note			界面名称将用于日志的记录
 */
	virtual QString getFrameName() = 0;

/**
 * @brief			获取界面的版本信息
 * @param[in]	<void>
 * @return		<QString> 用户返回的版本信息
 * @note			版本信息将用于版本检查
 */
	virtual QString getVersion() = 0;

/**
 * @brief			主框架界面定周期调用该函数（高频率，约100ms~120ms调用一次）
 * @param[in]	<void>
 * @return 		<void>
 * @note			用户需保证，该函数单次调用时间不能过长，且无死循环
 */
	virtual void FastTimerLoop(){}

/**
 * @brief			主框架界面定周期调用该函数（低频率，约1000ms调用一次）
 * @param[in]	<void>
 * @return 		<void>
 * @note			用户需保证，该函数单次调用时间不能过长，且无死循环
 */
	virtual void SlowTimerLoop(){}

/**
 * @brief			读入界面的上一次状态
 * @param[in]	<void>
 * @return 		<bool> 返回true表示执行正常
 * @note			内部接口，调用showFrame()函数前自动调用
 */
	virtual bool readLastTimeStatus(){ return false;}

 /**
 * @brief			保存界面的现场状态
 * @param[in]	<void>
 * @return 		<bool> 返回true表示执行正常
 * @note			内部接口，调用showFrame()函数后自动调用
 */
	virtual bool saveLastTimeStatus(){ return false;}

/**
 * @brief			显示界面
 * @param[in]	<void>
 * @return 		<bool> 返回true表示执行正常
 * @note			显示界面，并激活界面定时器与读写操作
 */
	virtual bool showFrame() = 0;
	
/**
 * @brief			隐藏界面
 * @param[in]	<void>
 * @return 		<bool> 返回true表示执行正常
 * @note			隐藏界面，并挂起界面定时器与读写操作
 */
	virtual bool hideFrame() = 0;

/**
 * @brief			获取右侧显示栏界面（工艺下拉菜单）指针
 * @param[in]	<void>
 * @return		<QDialog*>	用户返回显示栏界面（工艺下拉菜单）的控件指针
 * @note			在主界面上方导航栏点击“显示”按钮，则在屏幕右侧弹出”显示“界面。操作工在”显示“界面的下拉菜单中选中”工艺“，则显示返回指针对应的控件
 * @note			调用者将界面设为非模态界面
 */
	virtual QWidget* getRightShowFramePtr(){ return NULL;}

/**
 * @brief			获取主导航栏第四个按钮菜单界面
 * @param[in]	<const QString &menu_name> 菜单名称
 * @param[in]	<const QString &icon_path> 菜单图标路径
 * @return 		<QDialog*>	显示界面指针
 * @return		<NULL> 调用失败
 * @note			调用者把界面设为模态界面
 */
	virtual QDialog* getForthMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			获取主导航栏第五个按钮菜单界面
 * @param[in]	<const QString &menu_name> 菜单名称
 * @param[in]	<const QString &icon_path> 菜单图标路径
 * @return 		<QDialog*>	显示界面指针
 * @return		<NULL> 调用失败
 * @note			调用者将界面设为模态界面
 */
	virtual QDialog* getFifthMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			获取主导航栏第六个按钮菜单界面
 * @param[in]	<const QString &menu_name> 菜单名称
 * @param[in]	<const QString &icon_path> 菜单图标路径
 * @return 		<QDialog*>	显示界面指针
 * @return		<NULL> 调用失败
 * @note			调用者将界面设为模态界面
 */
	virtual QDialog* getSixthMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			获取主导航栏第七个按钮菜单界面
 * @param[in]	<const QString &menu_name> 菜单名称
 * @param[in]	<const QString &icon_path> 菜单图标路径
 * @return 		<QDialog*>	显示界面指针
 * @return		<NULL> 调用失败
 * @note			调用者将界面设为模态界面
 */
	virtual QDialog* getSeventhMenuFramePtr(const QString &menu_name,const QString &icon_path){ return NULL;}

/**
 * @brief			获取用户指令“编辑”界面指针
 * @param[in]		<short cmd_id> 用户指令ID
 * @param[in]		<std::vector<double> para_vector> 用户指令参数列表
 * @return			<QDialog*>	用户返回参数配置页面的指针
 * @note			在示教程序界面，选中用户指令，点击“编辑”后，界面上出现工艺指令编辑按钮。操作工再次点击指令编辑按钮，则显示返回指针对应的控件
 * @note			调用者将界面设为模态界面
 */
	virtual QDialog* getCmdEditFramePtr(short cmd_id,std::vector<double> para_vector){ return NULL;}

/**
 * @brief		获取指令当前的状态信息
 * @param[in]	<short cmd_id> 用户指令ID
 * @param[in]	<std::vector<double>> para_vector 用户指令参数列表
 * @return 		<QString> 指令的状态信息
 * @return		<“”> 空字符串，表示调用失败
 * @note		调用者获取用户返回的字符串信息后，将该信息打印在主界面下方绿色的信息栏上
 */
	virtual QString getCmdFeedBackInfo(short cmd_id,std::vector<double> para_vector){ return "";}


/**
 * @brief		设置用户权限
 * @param[in]	short type:用户权限等级,
 *				type = 0: 操作人员权限
 *				type = 1: 管理员权限
 *				type = 2: 厂家权限
 * @note		每次切换至插件界面或系统用户权限改变时，此函数被调用
 */
	virtual void setPermission(short type) = 0;


signals:
	void appHide();

};


QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(GtAppFrameInterface, "RobotHmi");
QT_END_NAMESPACE

#endif