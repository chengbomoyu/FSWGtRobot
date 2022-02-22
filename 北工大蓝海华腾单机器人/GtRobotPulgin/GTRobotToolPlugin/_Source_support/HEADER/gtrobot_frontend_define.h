#ifndef GTR_USER_DEFINE_H
#define GTR_USER_DEFINE_H

///////////////////////////////////////////////////////////////////////// 
/// GTRobot	�̸߿Ƽ� ����ʽ�����鹤ҵ�����˿���ϵͳ����ƽ̨
/// Copyright (C) 2020 Googol Technology Ltd. All Rights Reserved.  
///   
/// @file		gtr_user_define.h    
/// @brief    	GTR���ջ����˿���ϵͳ-����ӿ�-���ݽӿڶ���  
/// @version 	v2.0.7.0          
//////////////////////////////////////////////////////////////////////////

#include<QString>

//����궨��Լ��ֵ
#define SHOWNUMVARCOUNT				8		//��ֵ�ͱ���
#define SHOWBOOLVARCOUNT			8		//�����ͱ���
#define SHOWINTVARCOUNT				8		//�����ͱ���
#define SHOWREALVARCOUNT			8		//ʵ���ͱ���
#define SHOWSTRVARCOUNT				8		//�ַ��ͱ���
#define SHOWAXISCOUNT				8		//λ���ͱ���
#define MAXPOINTCOUNT				999
#define SHOWINCPVARCOUNT			8		//����λ���ͱ���
#define MAXIOROW					4		//IO״̬
#define MAXIOCOLUMN					16
#define MAXCOMMONAXISROW			9		//ͨ����״̬
#define MAXCOMMONAXISCOL			8
#define CURRENTAXISCOUNT			8		//��ǰλ��
#define MAXSHOWAXISCOUNT			8		//ʾ����
#define MAXAXISCONFIGCOUNT			16		//�����ò���
#define MAXCONFIGGROUPCOUNT			2		//�����ò���
#define DHMAXCOUNT					15		//DH����
#define COUPLECOUNT					4		//��ϱ�����
#define JOINTDIRANDOFFSETCOUNT		8		//�ؽڷ�����ƫ������
#define REMOTEXCONFIGSIZE			40		//Զ��ͨѶ����
#define REMOTEYCONFIGSIZE			40
#define REMOTEMAXROW				8
#define REMOTESINGLEPAGE			1
#define REMOTEBINARYPAGE			30
#define MAXSHOWROW					32		//����ϵ��������
#define MAXENCODERCOUNT				8		//��λ�궨����
#define MAXSHOWALARMCOUNT			8		//������ʷ
#define MAXSHOWLOGCOUNT				9		//������־


namespace front_gtr{

enum ModuleType
{
	MODULE_HMI = 0,				//HMIģ��
	MODULE_TASK,				//TASKģ��
	MODULE_WARNING,				//����ģ��
	MODULE_SHAREMEMORY,			//�����ڴ�ģ��
	MODULE_PLC,					//PLCģ��
	MODULE_NC,					//NCģ��
	MODULE_ROBOTAPI,			//�����˿�ģ��
	MODULE_MAINPLCLOGIC,		//��PLC�߼�ģ��
	MODULE_CRAFTLOGIC,			//�����߼�ģ��
	MODULE_WATCH				//watchģ��
};

enum NumericVarType
{
	VAR_B,						//�����ͱ���
	VAR_I,						//�����ͱ���
	VAR_R,						//ʵ���ͱ���
	VAR_STR						//�ַ��ͱ���
};

enum PositionVarType
{
	VAR_P,						//λ���ͱ���
	VAR_INCP					//����λ���ͱ���
};

//�û�Ȩ��
enum PermissionLevel
{
	OPERATOR = 0,				//������
	MANAGER,					//����Ա
	FACTORY						//��������
};


//JOG�˶�������
enum JogAxisType
{
	JOG_NEGATIVE_X = 0,			//X�Ḻ����
	JOG_POSITIVE_X,				//X��������
	JOG_NEGATIVE_Y,				//Y�Ḻ����
	JOG_POSITIVE_Y,				//Y��������
	JOG_NEGATIVE_Z,				//Z�Ḻ����
	JOG_POSITIVE_Z,				//Z��������
	JOG_NEGATIVE_RX,			//RX�Ḻ����
	JOG_POSITIVE_RX,			//RX��������
	JOG_NEGATIVE_RY,			//RY�Ḻ����
	JOG_POSITIVE_RY,			//RY��������
	JOG_NEGATIVE_RZ,			//RZ�Ḻ����
	JOG_POSITIVE_RZ,			//RZ��������
};

struct VarNumber
{
	QString value;
	QString comment;

	VarNumber()
	{
		this->value = "0";
		this->comment = "��";
	}
	VarNumber& operator=(const VarNumber&input)
	{
		this->value = input.value;
		this->comment = input.comment;
		return *this;
	}
	bool operator!=(const VarNumber& input)const
	{
		return (this->value != input.value);
	}
};

struct GroupPoint
{
	QString coordType;			//����ϵ���ͣ�
	//#define COORD_SYSTEM_PCS				(0)
	//#define COORD_SYSTEM_MCS				(1)
	//#define COORD_SYSTEM_ACS				(2)
	//#define COORD_SYSTEM_TCS				(3)
	//#define COORD_SYSTEM_VCS				(4)
	//short m_coord_idx;	//����ϵ�ţ�
	//short m_tool_idx;		/�ߺţ�TCS����ϵ�ţ���
	QString configNumber;		//����ѡ���˶�·����ѡ��ACS����Ϊ1��
	QString posType;			//�������ͣ�����:0���� 1����, Ĭ��Ϊ0��
	QString orientationMode;	//ָ��λ�õ���̬����ģʽ(Ĭ��=GroupConfig::orientationMode)��
	//��ָ��λ�õ���������ϵΪ�ѿ�������ϵʱ����Ҫָ����̬������ģʽ��
	// #define ORI_MODE_NONE				    (0)������̬����
	// #define ORI_MODE_EULER				    (1)��ŷ������̬����
	// #define ORI_MODE_QUAD				    (2)����Ԫ����̬����
	// #define ORI_MODE_VECTOR				    (3)������ʸ����̬����
	// #define ORI_MODE_ROTATE_AXIS_POS			(4)����ת��λ����̬����
	
	QString groupIndex;			// Group����[1,2]��Point::groupPoint[1]��Ч��
	QString dynSynch;
	QString joint[8];			//����ֵ���ڹؽ�����ϵ�±�ʾ�����ؽڵ�ֵ���ڵѿ�������ϵ�±�ʾλ�ú���Ԫ��(��ŷ����)��ʾ����̬��[0,2]ΪXYZλ�ã�[3,6]Ϊ��̬��

	GroupPoint()
	{
		this->coordType = "2";
		this->configNumber = "0";
		this->posType = "0";
		this->orientationMode = "1";
		this->groupIndex = "0";
		this->dynSynch = "0";
		for(int i = 0;i<8;i++){
			this->joint[i] = "0";
		}
	}
};

struct VarPosition
{
	GroupPoint groupPoint[2];
	QString extJoint[8];
	QString comment;
	QString used;
	QString dynSynch;
	QString rev[6];

	VarPosition()
	{
		for(int i = 0;i<8;i++){
			this->extJoint[i] = "0";
		}
		this->comment = "��";
		this->used = "0";
		this->dynSynch = "0";
		
		for(int i = 0;i<6;i++){
			this->rev[i] = "0";
		}
	}
};


struct LogItem
{	
	QString username;
	QString text;
	QString datetime;
	
	LogItem()
	{
		this->username = "";
		this->text = "";
		this->datetime = "";
	}
};

struct RobotStatus
{
	QString pendant_mode;		
	QString run_status;
	QString servo_status;
	QString welding_status;
	QString tcs_id;
	QString coord_system;
	QString teach_speed;
	QString estop_status;
	QString switch_three_stage;
	QString prg_current_line;
	
	RobotStatus()
	{
		this->pendant_mode = "";
		this->run_status = "";
		this->servo_status = "";
		this->welding_status = "";
		this->tcs_id = "";
		this->coord_system = "";
		this->teach_speed = "";
		this->estop_status = "";
		this->switch_three_stage = "";
		this->prg_current_line = "";
	}
};

struct SystemParam
{
	QString nWatchMode;			//Watchģʽ��0�رգ�1����
	QString bGxnExtModule;		// <������Ч>	�Ƿ�������GXN��չģ�飨0��ʾ�ޣ�1�У���Ĭ��0.
	QString bDisableAxisStopDI;	// <��λ��Ч>	�Ƿ�ر���ֹͣ�źţ�0���� 1�رգ���Ĭ��0��

	QString gxnExtDiNum;		// <������Ч>	GXN��չDI����
	QString gxnExtDoNum;		// <������Ч>	GXN��չDO����

	QString nCardType;			//���ƿ����������ͣ�GtRobotDef::CardType 
	QString nSysAxisNum;		// <������Ч>	ϵͳ��������
	QString nSysChannelNum;		// <������Ч>	ϵͳ����ͨ������[1,2],Ĭ��1
	QString nSysGroupNum;		// <������Ч>	ϵͳ����Group����[1,2],Ĭ��1
	QString eHmiType;			//eHMI������ͣ�0��ʾ����壩
	QString eHmiDiNum;			//eHMI���Di����
	QString eHmiDoNum;			//eHMI���Do����

	QString nCardOpenChannel;	//Ĭ��5.	GTN_Open(short channel=5,short param=1) 
	QString nCardOpenParam;		//Ĭ��1.	GTN_Open(short channel=5,short param=1)

	QString nBoolVarNum;		//֧�ֵ�BOOL���ڲ�����������[0,20],Ĭ��0
	QString nLongVarNum;		//֧�ֵ�Long���ڲ�����������[0,20],Ĭ��0
	QString nDoubleVarNum;		//֧�ֵ�Double���ڲ�����������[0,20],Ĭ��0

	QString nRemoteMode;		//Զ��ģʽѡ��	0������,1Զ��IOģʽ,2Զ��TCPģʽ

	QString nReplayIoEnable;	//�ط�ģʽ��IO������Чʹ�ܣ�0��ʹ��IO��1ʹ��IO
	QString nReplayBtnDisable;	//�ط�ģʽ���ֳֺ��̵���׵�����ʹ�ܣ�0���β�ʹ�ܣ�1����ʹ��

	QString nSwitchTon;			//���ο��ؽ�ͨ��ʱ,��λms
	QString nSwitchTof;			//���ο��ضϿ���ʱ,��λms

	QString nSynPosCycleTime;   //ϵͳ����ʱ��λ��ͬ�����ڡ���λms��Ĭ��1000ms��<1ʱ��ͬ��
	QString nCapturePosType;	// <����>	�źŴ�������λ�õ�����	
	//			0 �滮λ�ã��ޱ�����ʱ�������ã���
	//			1 ������λ��(ʵ��ʹ��)
	//			Ĭ��1

	QString localDiNum;			//����DI����
	QString localDoNum;			//����DO����

	QString nEstopMode;			//<����> ��ͣģʽ 0��ͣ������ʹ�ܣ�1��ͣ���ٵ�0����ʹ��
	QString nRuntoPointMode;	//<����> �˶�����ģʽ 0��ǰ����ϵ�����˶��岹��1ǿ�ƽ��йؽڲ岹

	QString nCoordinateMode;	//<����> ����ϵ�л�ģʽ 0���л���������ϵ��1����TCS��PCS�л�(�����������������TCS��PCS)��Ĭ��0
	QString nSystemLanguage;	//<����> ������ϵͳ��ǰ�������ͣ�0���ģ�1Ӣ��
	QString nSystemChannel;		//<����> ������ϵͳ��ǰͨ����
	QString nSystemGroup;		//<����> ������ϵͳ��ǰ��Group��0-��һ��Group��1-�ڶ���Group��2-������Group
	QString nbreakModeEnable;	//<����> �Ƿ����ϵ�������0-�رգ�1-����
	QString nSpeedMode;			//<����> ȫ�ֱ����л�ģʽ 0��HMI���б����л� 1��PLC���б����л�
	QString nPositionerJogMode; //<����> ��λ��JOGģʽ 0���л���������2����jog 1��ʹ����չ�ᰴ������JOG
};

#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

//ͨ�����Ʋ���
struct ChannelParam
{
	//8λ������Ԥ��40��
	unsigned char bEnableDynamicCoordinate;   // <��λ��Ч> �Ƿ�ʹ�ܶ�̬����ϵ���١�0��ʹ�� 1ʹ�ܣ�Ĭ��0
	bool rev8[39];

	//16λ������Ԥ��40��
	//ͨ������������ = Group���� +�ⲿ����+���Ŵ���
	//ͨ��������˳��Group�ᡢ�ⲿ�ᡢ���Ŵ���

	unsigned short nGroupNo[3];		// <������Ч>	ͨ�����Ƶ�Group�ţ�[0,GRT_MAX_GROUP_NUM].
	// nGroupNo[0]����һ��Group��Ĭ��1 ��
	// nGroupNo[1]���ڶ���Group��Ĭ��0 ��
	// nGroupNo[2]��������Group��Ĭ��0 ��
	// 0��ʾ�޸�Group
	// 1��Ӧ��һ��Group��GroupConfig[0]��
	// 2��Ӧ�ڶ���Group��GroupConfig[1]��
	// 3��Ӧ�ڶ���Group��GroupConfig[2]��


	unsigned short nExtAxisNum;			// <������Ч>	ͨ�����Ƶ��ⲿ��������0��Ĭ��0

	unsigned short nGantryAxisNum;		// <������Ч>	ͨ�����Ƶ����Ŵ���������0��Ĭ��0

	unsigned short auGroupDynType;		// <��λ��Ч>	����Group�ڶ�̬�����е����ͣ�0 master�� 1 slave 
	unsigned short auGroupSynType;		// <��λ��Ч>	����Group��ͬ���˶��е����ͣ�0 master�� 1 slave

	short nReplayOverrideSelect;		// <����>	�ط�ģʽ�ٶȱ���ѡ�񣬷�Χ��[0,16]��0��ʾ���ܱ���Ӱ�죬Ĭ��1
	short nTeachOverrideSelect;			// <����>	ʾ��ģʽ�ٶȱ���ѡ�񣬷�Χ��[0,16]��0��ʾ���ܱ���Ӱ�죬Ĭ��1

	short dynTransMode;					// <����> ��̬����ϵģʽѡ��Ĭ��0
	short dynTransPrm;					// <����> ��̬����ϵ������Ĭ��0

	short rev16[29];	

	//32λ������Ԥ��40��
	long rev32[40];

	//64λ������Ԥ��100��
	double dynTransMasterOrigin[3][6];		//  <��λ��Ч>  ��̬���٣�master��MCS��Ե�ǰgroup��MCS������ϵ�任��ϵ
	double dynTransPcsToMasterTcs[3][6];	//  <��λ��Ч>  ��̬���٣�PCS���master��TCS������ϵ�任��ϵ

	double rev64[64];
};


// �����ÿ��Ʋ���
struct AxisConfig
{
	//8λ����(Ԥ��40)////////////////////////////////////////////////////
	bool bEnAlarm;				// <��λ��Ч>	ʹ���ŷ�����
	bool bEnLmtPosi;			// <��λ��Ч>	ʹ������λ
	bool bEnLmtNega;			// <��λ��Ч>	ʹ�ܸ���λ
	bool bEnLmtSoft;			// <��λ��Ч>	ʹ������λ
	bool bPosiLmtSns;			// <��λ��Ч>	����λ���ԣ�	false���գ�true����
	bool bNegaLmtSns;			// <��λ��Ч>	����λ���ԣ�	false���գ�true����
	bool bHomeSns;				// <����>		Home�źż��ԣ�	false���գ�true����
	bool bEncoderSns;			// <������Ч>	���������ԣ�	false������trueȡ��
	bool bSimuMode;				// <������Ч>	����ģʽ��		false����ģʽ��true����ģʽ��Ĭ��false
	bool bEnPathShaping;		// <��λ��Ч>	ʹ��PathShaping���ܣ�false�رգ�true������Ĭ��false
	bool rev8[30];				

	//16λ����(Ԥ��40)////////////////////////////////////////////////////
	short	axisID;				// <������Ч>	��ID��[1,GRT_MAX_AXIS_NUM]
	short	axisType;			// <����>		�����ͣ� 0: linear  1: rotary 
	short	ctrlMode;			// <������Ч>	����ģʽ��0����+����1ģ������2��������
	short   cmdDir;				// <������Ч>	ָ���(0���� 1ȡ����ʹ�øò�����֤���˶������ģ�ͷ��򱣳�һ��)

	short	profileID;			// <������Ч>	��滮���ͨ����1-n��Ĭ��Ϊ��ID
	short	encoderID;			// <������Ч>	�����������ͨ����1-n��Ĭ����ID
	short	stepID;				// <������Ч>	��滮�������ͨ����ȡֵ1-n��Ĭ��Ϊ��ID

	short	encoderType;		// <������Ч>	���������� 0����ʽ 1����ʽ 2�����������Ĭ��0.
	short	absEncoderType;		// <������Ч>	���Ա��������ͣ�0glink 1����ͨ�ţ���Ĭ��0.
	short	absEncoderDir;		// <������Ч>	���Ա���������0�� 1������Ĭ��0.
	short	absEncoderBits;		// <����>		���Ա�����λ�������Ա������ֱ���=pow(2.0, absEncoderBits * 1.0))

	short	motorType;			// <����>		�������,��Χ[0,n]��0���������Ч��>0�����õ������
	short	stationID;			// <����>		վ��

	short	backlashCompDir;	// <��λ��Ч>	�����϶��������0��1��Ĭ��1

	//����ֹͣ�˶��������ź�
	short  stopDiType;			// <��λ��Ч>	����ֹͣ�˶��������ź����ͣ�Ĭ��0
	//#define MC_LIMIT_POSITIVE               (0)
	//#define MC_LIMIT_NEGATIVE               (1)
	//#define MC_ALARM                        (2)
	//#define MC_HOME                         (3)
	//#define MC_GPI                          (4)
	short  stopDiIndex;			// <��λ��Ч>	����ֹͣ�˶��������ź�������Ĭ��-1(��Ч)
	short  stopType;			// <��λ��Ч>	ֹͣ���ͣ�0��ͣ  1ƽ��ֹͣ  2�ر��ŷ���Ĭ��0
	short  stopDiSns;			// <��λ��Ч>	ֹͣ�źż��ԣ�	0���գ�1����, Ĭ��0

	//���˶�Լ�����������ֵ����TAxisMotionConstraint
	short  reverseLimitMode;	// <��λ��Ч>	�˶������ٶ�Լ��ģʽ����ǰհʹ��ʱ��Ч��Ĭ��0
	// 0�����ᷴ��ʱ���յ��ٶȸ���dvMax����Լ��
	// 1�����ᷴ��ʱ���յ��ٶȼ��ٵ�0��
	unsigned short extAxisPrgCtrlType;	// <����ʱ��������Ч>	�ⲿ���ڳ��������е�Ĭ�Ͽ������ͣ��μ�TYPE_AXIS_MOVE_MODE��
	// 0������ģʽ��Ĭ��0��
	// 1�����ģʽ
	// 2��Jogģʽ
	// 3������������滮ͬ���˶� 
	// 4������group�ϳɹ滮λ��ͬ���˶� 
	short velFilterNum;			// <��λ��Ч>	�ٶȹ滮�˲�ֵ,��Χ[0,4096]
	short	rev16[19];		

	//32λ����(Ԥ��40)////////////////////////////////////////////////////
	long absEncoderZeroPos;		// <������Ч>	���Ա��������
	//���Ա���������ͨ�ţ����ã�
	unsigned long motorBrand;	// <������Ч>		���Ʒ��, ��Ͼ���ֵ������absEncoderTypeʹ��
	unsigned long absoluteEncID;// <������Ч>		������ڴ���ͨѶ�ϵ���·ID
	unsigned long port;			// <������Ч>		���ں�
	unsigned long baud;			// <������Ч>			
	unsigned long dataBit;		// <������Ч>		
	unsigned long parity;		// <������Ч>		
	unsigned long stopbit;		// <������Ч>	
	unsigned long absEncMultiLines;		// <������Ч>	(absEncoderType=0ʱ)����ֵ����������(Ĭ��65536)  
	//              (absEncoderType=1ʱ)���Ա�������Ȧ������
	long rev32[31];		

	//64λ����(Ԥ��200)///////////////////////////////////////////////////

	//���嵱��
	double pulse;								// <������Ч>	���һȦ����������λ��pulse
	double pinch;								// <������Ч>	���һȦ�˶����룬��λ��mm���
	double gearRatio;							// <������Ч>	���ٱ�.������ĩ��:��ʵ�ʼ��ٱ�=gearRatio/gearRatioMotor�� 
	double scale;								// <������Ч>	���嵱�����������������NC��ʼ��ʱ���㣺pulse*gearRatio/pinch/gearRatioMotor��, ��λ��pulse/mm �� pulse/�ȡ�
	double gearRatioMotor;						// <������Ч>	���ٱ�.�����: 
	double revd64[15];
	//double couple_ratio[GRT_MAX_AXIS_NUM];	// <������Ч>	���������������ϱ�(20200825 ���ã��Ƶ�GROUP����)
	//�г̣�����λ��
	double minPos;								// <��λ��Ч>	��С�г̣�		��λ��mm��ȡ�
	double maxPos;								// <��λ��Ч>	����г̣�		��λ��mm��ȡ�
	double minPosOffset;						// <��λ��Ч>	��С�г̣�		��λ��mm��ȡ�
	double maxPosOffset;						// <��λ��Ч>	����г̣�		��λ��mm��ȡ�

	//ģ��������
	double kp;									// <��λ��Ч>	�ŷ���������
	double ki;									// <��λ��Ч>	�ŷ���������
	double kd;									// <��λ��Ч>	�ŷ�΢������
	double kvff;								// <��λ��Ч>	�ŷ��ٶ�ǰ������
	double kaff;								// <��λ��Ч>	�ŷ����ٶ�ǰ������
	double mtrBias;								// <��λ��Ч>	��������Ư����������λ��pulse
	double mtrLmt;								// <��λ��Ч>	���ָ������(��ѹ���ͼ���)����λ��V
	double posErrLmt;							// <��λ��Ч>	��������λ��mm��ȡ�

	//���˶�Լ�����������ֵ����TAxisMotionConstraint
	double velMax;			// <��λ��Ч>	����ٶȣ�			��λ��mm/s���/s��
	double accMax;			// <��λ��Ч>	�����ٶȣ�		��λ��mm/s^2���/s^2��
	double decMax;			// <��λ��Ч>	�����ٶȣ�		��λ��mm/s^2���/s^2��
	double jerkMax;			// <��λ��Ч>	���Ӽ��ٶȣ�		��λ��mm/s^3���/s^3��
	double dvMax;			// <��λ��Ч>	����ٶ���������	��λ��mm/s���/s��

	//ֹͣ
	double stopDec;			// <��λ��Ч>	ֹͣ���ٶȣ�		��λ��mm/s^2���/s^2��
	double estopDec;		// <��λ��Ч>	��ͣ���ٶȣ�		��λ��mm/s^2���/s^2��

	//ƽ��
	double smoothTime;		// <��λ��Ч>	��ƽ��ʱ�䡣ȡֵ��Χ��[0,60]����λ��ms 
	double smoothK;			// <��λ��Ч>	ƽ��ϵ����ȡֵ��Χ��[0,1000]

	//�ؽ�����ϵ�£��ֶ�JOG�˶�����	
	double acsJogVel;		// <������Ч>	�ֶ��ؽ�JOG�˶��ٶȣ�		��λ��mm/s���/s��
	double acsJogAcc;		// <������Ч>	�ֶ��ؽ�JOG�˶����ٶȣ�		��λ��mm/s^2���/s^2��

	//�ѿ�������ϵ�£��ֶ�JOG�˶�����
	double cpJogVel;		// <������Ч>	�ֶ��ѿ���JOG�˶��ٶȣ�		��λ��mm/s���/s��
	double cpJogAcc;		// <������Ч>	�ֶ��ѿ���JOG�˶����ٶȣ�	��λ��mm/s^2���/s^2��

	//�ؽ�����ϵ�£��ֶ�Step�˶�����
	double acsStepVel;		//<������Ч>	�ֶ��ؽ�Step�˶��ٶȣ�		��λ��mm/s���/s��
	double acsStepAcc;		//<������Ч>	�ֶ��ؽ�Step�˶����ٶȣ�	��λ��mm/s^2���/s^2��

	//�ѿ�������ϵ�£��ֶ�Step�˶�����
	double cpStepVel;		// <������Ч>	�ֶ��ѿ���Step�˶��ٶȣ�	��λ��mm/s���/s��
	double cpStepAcc;		// <������Ч>	�ֶ��ѿ���Step�˶����ٶȣ�	��λ��mm/s^2���/s^2��

	//�������
	double motorMaxSpeed;				// <����>	���ת�٣�		��λ: rpm 
	double motorRateCurrent;			// <����>	�������		��λ: A
	double motorRateTorque;				// <����>	�Ť�أ�		��λ: N.m
	double motortorqueToCurrentCoef;	// <����>	���ص����ȣ�	��λ: N.m / A

	//PathShaping����
	double pathShapingT1;				// <��λ��Ч>	ϵͳ��Ӧʱ�䣬ͨ���ٶȺ͸������ȷ���ò�����t1=err/vel����λ��s��
	double pathShapingT2;				// <��λ��Ч>	Ŀ����Ӧʱ�䣬ͨ������С��t1��ʱ�����ϵͳ��Ӧ�ٶȡ���λ��s��

	//�����϶����
	double backlashCompValue;			// <��λ��Ч>	�����϶����ֵ����0��0ʱ�޲�������λ��mm���
	double backlashCompTime;			// <��λ��Ч>	�����϶����ʱ�䣬��0��Ϊn�Ļ�����ʾ2^n�η������ڡ�
	double rev64[143];	

};


//ͨ����Group�����ÿ��Ʋ���
struct GroupConfig
{
	//8λ������Ԥ��40��/////////
	bool bEnBlending;			//  <��λ��Ч>	�����켣blending
	bool bEnableDynPara;		//  <��λ��Ч>	��������ѧ����
	bool bEnableLookAhead;		//  <��λ��Ч>	����ǰհ
	
	bool bEnAcsPosiLmt[8];			//  <��λ��Ч>	ACS�¿�����������λ
	bool bEnAcsNegaLmt[8];			//  <��λ��Ч>	ACS�¿�����������λ
	bool bEnMcsPosiLmt[3];			//  <��λ��Ч>	MCS�¿�����������λ
	bool bEnMcsNegaLmt[3];			//  <��λ��Ч>	MCS�¿�����������λ
	bool bEnPcsPosiLmt[3];			//  <��λ��Ч>	PCS�¿�����������λ
	bool bEnPcsNegaLmt[3];			//  <��λ��Ч>	PCS�¿�����������λ
	
	bool rev8[69];

	//16λ������Ԥ��200��///////////////////////////////////////////////////
	short groupID;				// <����>		��ID����Χ[1,2]
	short nGroupAxisNum;		// <������Ч>	���������

	short profileMode;			// <��λ��Ч>	�ٶȹ滮ģʽ��0ƽ��ģʽ 1�߽�ƽ��ģʽ 2Jerkģʽ(����)��Ĭ��Ϊ0

	short nKinType;				// <������Ч>	�ṹ����(Ĭ��ΪKIN_TYPE_ROBOT)��	
	//				0 KIN_TYPE_ORTHOGONAL����׼��������ṹ��
	//				1 KIN_TYPE_NON_ORTHOGONAL���������ṹ��
	//				2 KIN_TYPE_ROBOT�������˽ṹ��
	//				3 KIN_TYPE_FIVE_AXIS������ṹ��
	//				4 KIN_TYPE_MULTI_AXIS������ṹ��

	short orientationMode;		// <������Ч>	ָ��λ�õ���̬����ģʽ(1��2��Ĭ��Ϊ2 ORI_MODE_QUAD)��
	// ��ָ��λ�õ���������ϵΪ�ѿ�������ϵʱ����Ҫָ����̬������ģʽ��
	// 0 ORI_MODE_NONE������̬������
	// 1 ORI_MODE_EULER��ŷ������̬������
	// 2 ORI_MODE_QUAD����Ԫ����̬������
	// 3 ORI_MODE_VECTOR������ʸ����̬������
	// 4 ORI_MODE_ROTATE_AXIS_POS����ת��λ����̬������
	// 5 ORI_MODE_SPACE_ROTATE

	short nRobotKinType;		// <������Ч>	�����˽ṹ����:	0 ROBOT_TYPE_SCARA��SCARA��е�ۡ�
	//					1 ROBOT_TYPE_SIX_REVOLUTE��6���ɶȴ�����е�ۡ�
	//					3 Delta�����ã�
	//					Ĭ��1

	short dynamicsParaNum;				// <����>	����ѧģ�Ͳ�������, ȡֵ��Χ��[1,128]

	short dynCompensateSource;			// <����>	����ѧ�����Ĳο�����Դ��
	//			0 MC_PROFILE: ��滮λ�á�
	//			1 MC_ENCODER���������λ�á�
	//			2 MC_GROUP_PROFILE��group��ACS�滮λ�á�
	//			Ĭ��0
	short dynCompensateEnFriction;		// <����>	����ѧ�����������Ƿ�ʹ��Ħ����������0����ʹ�ܣ�1��ʹ�ܡ�
	short dynCompensateEnable;			// <����>	����ѧ�����������Ƿ��������ѧ����ֵ��0���������1�������


	short LaSegNum;				// <������Ч>		ǰհ��������Χ[150,1000],Ĭ��200��

	short blendType;			// <������Ч>		�켣blending����:	
	//					0 BLEND_MODE_NONE��������
	//					1 BLEND_MODE_ARC�� Բ��blending
	//					2 BLEND_MODE_BIARC��˫Բ��blending
	//					Ĭ��2
	short blendPrmType;			// <������Ч>		�켣blendingԼ����������:
	//					0 BLEND_PARA_TYPE_ERROR����ֻ��BLEND_MODE_ARC��Ч
	//					1 BLEND_PARA_TYPE_RADIUS������Բ���뾶��ֻ��BLEND_MODE_ARC��Ч
	//					2 BLEND_PARA_TYPE_DISTANCE������
	//					Ĭ��2
	short nRobotKinSubType;			// <������Ч>	�����˽ṹ�����ͣ�[0,3]��SCARA��Ч��	Ĭ��0			//20200428
	short nJointDir[8];				// <������Ч>	�ؽڷ���0:�붨�巽��ͬ��1���붨�巽����	Ĭ��0	//20200428

	//����� (coupleAxisMaster[i]>0&&coupleAxisSlave[i]>0��Ӧ����ϲ�����Ч)
	short coupleAxisMaster[4];		//<������Ч>	���.����ID
	short coupleAxisSlave[4];		//<������Ч>	���.����ID

	//�ѿ�������ϵ��ʾ�̣��ֶ������˶����ƶ�������
	short cpGroupMoveType[6];	//[1,6]��Ч��1X����2Y����3Z����4��X������ת��5��Y������ת��6��Z������ת
	//Ĭ��Ϊ{1,2,3,4,5,6}��
	//��Ҫ���ڵѿ����£�GROUP����С��6�ҿ��ƶ��������������
	//�磺4��SCARA,MoveJogû��û����X/Y����ת��ֻ����Z����ת,Ӧ����Ϊ{1,2,3,6,0,0}��
	//�����ѿ�������ϵ�£�NC�յ���4�˶����G6.3�����Զ�ִ����Z����ת�˶�

	short acsVelMode;	//<����>	ACS������ϵ���˶���ָ���ٶȺͼ��ٶȵ����͡�
						//0��Ĭ��ģʽ����λ��mm/s���/s
						//1���ٷֱ�ģʽ

	short rev16[163];

	//32λ������Ԥ��100��///////////////////////////////////////
	long rev32[100];

	//64λ������Ԥ��500��///////////////////////////////////////
	//�켣blending
	double blendMinAngle;		//  <������ʹ��>	����blending�������С�Ƕȣ����켣ʸ���Ƕȱ仯С�ڸýǶ�ʱ�����д���
	double blendMaxAngle;		//  <������ʹ��>	����blending��������Ƕȣ����켣ʸ���Ƕȱ仯���ڸýǶ�ʱ�����д���
	double blendPara;			//  <������ʹ��>	����blending����Ĺ��ɶβ�������Բ���뾶�����룩����λmm��

	//ǰհ
	double LaTime;				//  <������ʹ��>	ǰհת��ϵ����ת��ϵ��Խ�ͣ�ת���ٶ�Խ�ͣ�ת�Ǵ�����������Խ�ߣ�
	//					��֮��ת��ϵ��Խ�ߣ�ת���ٶ�Խ�ߣ�ת�Ǵ�����������Խ�͡�
	//					Ĭ��0.1
	double LaRadiusRatio;		//  <������ʹ��>	ǰհԲ��ϵ����ϵ��Խ��Ŀ���ٶ�Խ�ߣ���֮��ϵ��ԽС��Ŀ���ٶ�ԽС��
	//					Ĭ��1

	//�ٶȹ滮ģʽ��ƽ��ģʽ
	double smoothTime;			//  <��λ��Ч>	 ƽ�������ٶȱ仯��ʱ�䡣
								// profileMode=0ʱ��ȡֵ��Χ��[0,511]����λ��ms����accTimeΪ0ʱ���ٶȹ滮����ΪT�����ߡ�
								// profileMode=1ʱ��ȡֵ��Χ��[0,255]����λ��ms����accTimeΪ0ʱ���ٶȹ滮����ΪT�����ߡ�

	double smoothK;				//  <��λ��Ч>	 ƽ����̬ϵ����ȡֵ��Χ��[0,1000]��

	//�ٶȹ滮ģʽ��Jerkģʽ(����)
	double jerkValue;			// �Ӽ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^3���/s^3��
	double jerkBeginPercent;	// ��ʼ���ٶȰٷֱȣ�ȡֵ��Χ��[0,100]��
	double jerkEndPercent;		// ��ֹ���ٶȰٷֱȣ�ȡֵ��Χ��[0,100]��

	//�ѿ�������ϵ���˶����Ʋ���
	double cpVelMax;			//  <��λ��Ч>	 �ѿ�������ϵ�µ�����ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
	double cpAccMax;			//  <��λ��Ч>	 �ѿ�������ϵ�µ������ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
	double cpDecMax;			//  <��λ��Ч>	 �ѿ�������ϵ�µ������ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
	double cpJerkMax;			//  <��λ��Ч>	 �ѿ�������ϵ�µ����Ӽ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^3��

	//MOVJĬ���˶�����
	double movjVel;				// <����>	MOVJĬ���ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
	double movjAcc;				// <����>	MOVJĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��

	//MOVLĬ���˶�����
	double movlVel;				// <����>	MOVLĬ���ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
	double movlAcc;				// <����>	MOVLĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��

	//MOVCĬ���˶�����
	double movcVel;				// <����>	MOVCĬ���ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
	double movcAcc;				// <����>	MOVCĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��

	//ֹͣ
	double stopDec;				// <��λ��Ч>	 ֹͣ���ٶȣ�		��λ��mm/s^2��
	double stopJerk;			// <��λ��Ч>	 ֹͣ�Ӽ��ٶȣ�	��λ��mm/s^3��
	//��ͣ����ͣ���ŷ���������λ��
	double EStopDec;			// <��λ��Ч>	 ��ͣ���ٶȣ�		��λ��mm/s^2��
	double EStopJerk;			// <��λ��Ч>	 ��ͣ�Ӽ��ٶȣ�	��λ��mm/s^3

	double maxOverride;			// <��λ��Ч>	 ����ʣ�[10,150]��Ĭ��100��


	double kinTransLinkLength[50];	// <��λ��Ч>	 �˶�ѧ�任����: �˳���������λ��mm��	
	double dynamicsParamter[128];	// <��λ��Ч>	 ����ѧģ�Ͳ���ֵ

	double jointOffset[8];			// <��λ��Ч>	�ؽ�ƫ�ƣ�ʵ�ʳ�ʼ��̬�붨��ĳ�ʼ��̬��ƫ��(Ĭ��0��ʵ�ʳ�ʼ��̬�ڶ�������ϵ�µ�λ��)//20200428

	//��̬���Ʋ���
	double oriVelMax;				//  <��λ��Ч>
	double oriAccMax;				//  <��λ��Ч>
	double oriDecMax;				//  <��λ��Ч>
	double oriJerkMax;				//  <��λ��Ч>

	//ʾ�����˶����㣺ACS�ؽ�����ϵ���˶�����
	double teachAcsMovVel;				// <����>	�ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
	double teachAcsMovAcc;				// <����>	���ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��

	//ʾ�����˶����㣺�ѿ�������ϵ���˶�����
	double teachMcsMovVel;				// <����>	�ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
	double teachMcsMovAcc;				// <����>	ȡֵ��Χ��(0,...)����λ��mm/s^2��

	//��ϱ�
	double coupleRatioMaster[4];		//<������Ч>	��ϱ�ֵ.����
	double coupleRatioSlave[4];			//<������Ч>	��ϱ�ֵ.����

	//����λ
	double acsPosiLmtValue[8];			//  <��λ��Ч>	ACS����������λֵ
	double acsNegaLmtValue[8];			//  <��λ��Ч>	ACS�¸�������λֵ
	double mcsPosiLmtValue[3];			//  <��λ��Ч>	MCS����������λֵ
	double mcsNegaLmtValue[3];			//  <��λ��Ч>	MCS�¸�������λֵ
	double pcsPosiLmtValue[3];			//  <��λ��Ч>	PCS����������λֵ
	double pcsNegaLmtValue[3];			//  <��λ��Ч>	PCS�¸�������λֵ

	double acsPosiLmtOffset[8];			//  <��λ��Ч>	ACS����������λƫ��ֵ//liu.zl-2021-6-26
	double acsNegaLmtOffset[8];			//  <��λ��Ч>	ACS�¸�������λƫ��ֵ
	double mcsPosiLmtOffset[3];			//  <��λ��Ч>	MCS����������λƫ��ֵ
	double mcsNegaLmtOffset[3];			//  <��λ��Ч>	MCS�¸�������λƫ��ֵ
	double pcsPosiLmtOffset[3];			//  <��λ��Ч>	PCS����������λƫ��ֵ
	double pcsNegaLmtOffset[3];			//  <��λ��Ч>	PCS�¸�������λƫ��ֵ

	double arcErr;							//  <��λ��Ч>	Բ��������

	//dec ���ٶ�
	double movjDec;						// <����>	MOVJĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
	double movlDec;						// <����>	MOVLĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
	double movcDec;					// <����>	MOVCĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
	double teachAcsMovDec;			// <����>	�˶����㣺ACS�ؽ�����ϵ���˶����ٶȡ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
	double teachMcsMovDec;			// <����>	�˶����㣺�ѿ�������ϵ���˶����ٶȡ�ȡֵ��Χ��(0,...)����λ��mm/s^2��

	double rev64[211];
};


//DH����
struct CouplePara
{
	short master_id;
	double master_value;
	short slave_id;
	double slave_value;
	bool used;
	CouplePara()
	{
		master_id = 0;
		master_value = 0;
		slave_id = 0;
		slave_value = 0;
		used = 0;
	}
};
struct CoupleGroupPara
{
	CouplePara couple_para[COUPLECOUNT];
};
struct DhPara
{
	double kinTransLinkLength[DHMAXCOUNT];
	DhPara()
	{
		memset(this->kinTransLinkLength,0,sizeof(kinTransLinkLength));
	}
};
struct HmiJointDirAndOffset
{
	bool dir[JOINTDIRANDOFFSETCOUNT];
	double offset[JOINTDIRANDOFFSETCOUNT];
	HmiJointDirAndOffset()
	{
		memset(this->dir,0,sizeof(dir));
		memset(this->offset,0,sizeof(offset));
	}
};
struct DhCouplePara
{
	double kinTransLinkLength[DHMAXCOUNT];
	CouplePara couple_para[COUPLECOUNT];
	DhCouplePara()
	{
		memset(this->kinTransLinkLength,0,sizeof(kinTransLinkLength));
	}
};

#pragma pack(pop)

}

#endif
