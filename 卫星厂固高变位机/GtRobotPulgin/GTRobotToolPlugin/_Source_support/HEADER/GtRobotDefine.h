#pragma once

#ifndef GTROBOTDEFINE_H
#define GTROBOTDEFINE_H

#include "windef.h"  

//#define HOOK_MC_CMD         

#define GRT_MAX_AXIS_NUM			(16)		//������ϵͳ����������
#define GRT_MAX_CHANNEL_NUM			(2)			//������ϵͳ���ͨ����
#define GRT_MAX_GROUP_NUM				(3)			//������ϵͳ���Group��
#define GRT_MAX_GROUP_AXIS_NUM		(8)			//Group�������
#define GRT_MAX_COORDINATE_NUM		(64)		//��PCS/TCS������ϵ������

#define R688_MAX_AXES               (24)	    //R688�������

#define GRT_MIN_LIST_SPACE          (300)	    // List��Сʣ��ռ�
#define GRT_MAX_LIST_SPACE          (4096)     // List���ռ�

#define GRT_PUBLIC_BOOL_NUM			(10000)		//bool�͹�������������B0~B9999
#define GRT_PUBLIC_INT_NUM			(10000)		//int�͹������������� I0~I9999
#define GRT_PUBLIC_DOUBLE_NUM		(10000)		//double�͹�������������R0~R9999
#define GRT_PUBLIC_POINT_NUM		(10000)		//λ���͹�������������P0~P9999
#define GRT_PUBLIC_STRING_NUM		(1000)		//�ַ����͹�������������STR0~STR999
#define GRT_PUBLIC_STRING_LEN		(256)		//�����ַ����͹�����������

#define GRT_FILEPATH_STRING_LEN		(256)		//�ļ�·���������ַ�������

#define GRT_PLC_DATA16_NUM			(1000)		//PLC��16λX/Y/F/G/M�����������磬X0.0~X199.15

#define GRT_PLC_DATA32_NUM			(3000)		//PLC��32λD���������������з���$0~$2999��
#define GRT_PLC_DATA64_NUM			(3000)		//PLC��32λD���������������з���$3000~$5999��


#define GRT_MAX_DIO_GROUP_NUM			(8)			//DIO��������ź�����
#define GRT_MAX_DIO_GROUP_PORT_NUM		(64)		//����DIO֧�ֵ��źŸ�����ԭ��Ϊ32��


#define GRT_MAX_DAC_NUM				(20)		//Dac���ͨ����
#define GRT_MAX_ADC_NUM				(20)		//Adc����ͨ����

#define GRT_MAX_XY_SIGNAL_NUM		(400)		//�����õ�XY�źŸ���

#define GRT_SLEEP_NC        		(10)//(10)		//(1)
#define GRT_SLEEP_PLC        		(10)//(2)			//(18)
#define GRT_SLEEP_PAUSE       		(100)

#define GRT_ERROR_OPEN              (-6)
#define GRT_NONE                    (-1)
#define GRT_SUCCESS       		    (0)
#define GRT_ERROR_EXECUTE           (1)
#define GRT_ERROR_PARAMETER         (7)
#define GRT_ERROR_UNKNOWN           (8)
#define GRT_ERROR_LOADFILE          (-1)

#define GRT_LIST_FULL       		 (10700) //ָ���������´�����ѹָ�� 20200720

#define GRT_DEBUG_MSG_LEN           (512)

#define GRT_MIN_FILE_LEN            (2)
#define GRT_MAX_FILE_LEN            (256)

#define GRT_MIN_OVERRIDE            (0.00001)
#define GRT_MAX_OVERRIDE            (100.00001)

#define GRT_SCALE_PERCENT           (0.01)
#define GRT_SCALE_MILLI             (0.001)
#define GRT_SCALE_PPM               (0.000001)

#define GRT_ZERO_FLOAT              (0.001)

#define GRT_STEP_LENGTH             (50)



#define GRT_NO_INIT                 (-1)

#define GRT_OVERRIDE_DEFAULT        (1.0)

#define GRT_SYS_STATUS_UNLOCK   	(0)
#define GRT_SYS_STATUS_LOCK		    (1)
#define GRT_SYS_STATUS_NOALARM   	(0)
#define GRT_SYS_STATUS_ALARM	    (1)

#define GRT_LOOKAHEAD_NUM_DEFAULT   (2) //(100)

#define GRT_DECODER_REPEAT_ONCE   	(1)
#define GRT_DECODER_REPEAT_LOOP     (-1)

#define GRT_GROUP_AXIS_NUM_MCS      (6)

#define GRT_GROUP_DIFFERENT_POS_THRESHOLD     (10.0)

namespace GtRobotDef
{
	//����ϵ
	enum TYPE_COORD
	{
		PCS = 0,	//COORD_SYSTEM_PCS,
		MCS = 1,	//COORD_SYSTEM_MCS,
		ACS = 2,	//COORD_SYSTEM_ACS,
		TCS = 3,	//COORD_SYSTEM_TCS,
		VCS	= 4,	//COORD_SYSTEM_VCS,
		FCS = 5,	//COORD_SYSTEM_FCS
		MVCS = 10,	//COORD_SYSTEM_MVCS
		PCS2 = 40,		//COORD_SYSTEM_PCS2 
		PCS3 = 41		//COORD_SYSTEM_PCS3
	};

	//����������
	enum TYPE_CONTROLER
	{
		MARVIE4 = 0, //����4
		MARVIE6,
		R688C,
		R688S
	};

	//�ṹ����
	enum TYPE_KIN
	{
		KIN_ORTHOGONAL = 0,			//��׼��������ṹ��
		KIN_NON_ORTHOGONAL,			//�������ṹ��
		KIN_ROBOT,					//�����˽ṹ��
		KIN_FIVE_AXIS,				//����ṹ��
		KIN_MULTI_AXIS				//����ṹ��
	};

	//����������
	enum TYPE_ROBOT
	{
		SCARA = 0,
		SIX_R_S_WRIST,
		DELTA
	};

	//�ᷴ������������
	enum TYPE_ENCODER
	{
		ENCODER_ABS=0,		//���Ա�����
		ENCODER_INC,		//����������
		ENCODER_PULSE		//������������ޱ�������
	};

	//�����ģʽ
	enum TYPE_AXIS_CTRL_MODE
	{
		CTRL_MODE_PULSEDIR = 0,		//����+����
		CTRL_MODE_DAC,				//ģ����
		CTRL_MODE_NPPULSE			//��������
	};


	//������
	enum TYPE_AXIS
	{
		LINEAR = 0,
		ROTARY,
		HELIX
	};

	//DIO��Ч��ƽ
	enum SENCES_LEVEL
	{
		LEVEL_LOW = 0,	//�͵�ƽ����������
		LEVEL_HIGH		//�ߵ�ƽ����������
	};

	//DI����
	enum TYPE_DI
	{
		GPI = 0,		//����
		EHMI_DI,		//eHmi���
		GXN_EXTDI		//GXN��չģ��
	};

	//DO����
	enum TYPE_DO
	{
		GPO = 0,		//����
		EHMI_DO,		//eHmi���
		GXN_EXTDO		//GXN��չģ��
	};

	//Adc����
	enum TYPE_ADC
	{
		ADC = 0,		//����
		AU_ADC,			//����
		GXN_EXTAI		//GXN��չģ��
	};

	//Dac����
	enum TYPE_DAC
	{
		DAC = 0,		//����
		AU_DAC,			//����
		GXN_EXTAO		//GXN��չģ��
	};

	//PLC��XY��������
	enum TYPE_PLC
	{
		VAR = 0,	//��ͨ��������ֵ�ɳ������
		CONST_0,		//����0(ǿ��0)
		CONST_1		//����1(ǿ��1)
	};

	//Group����
	typedef struct 
	{
		short coordType;		//����ϵ���ͣ�
									//#define COORD_SYSTEM_PCS				(0)
									//#define COORD_SYSTEM_MCS				(1)
									//#define COORD_SYSTEM_ACS				(2)
									//#define COORD_SYSTEM_TCS				(3)
									//#define COORD_SYSTEM_VCS				(4)
		//short m_coord_idx;	//����ϵ�ţ�
		//short m_tool_idx;		/�ߺţ�TCS����ϵ�ţ���
		short configNumber;		//����ѡ���˶�·����ѡ��ACS����Ϊ1��
		short posType;			//�������ͣ�����:0���� 1����, Ĭ��Ϊ0��
		short orientationMode;	//ָ��λ�õ���̬����ģʽ(Ĭ��=GroupConfig::orientationMode)��
								//��ָ��λ�õ���������ϵΪ�ѿ�������ϵʱ����Ҫָ����̬������ģʽ��
									// #define ORI_MODE_NONE				    (0)������̬����
									// #define ORI_MODE_EULER				    (1)��ŷ������̬����
									// #define ORI_MODE_QUAD				    (2)����Ԫ����̬����
									// #define ORI_MODE_VECTOR				    (3)������ʸ����̬����
									// #define ORI_MODE_ROTATE_AXIS_POS			(4)����ת��λ����̬����
		short groupIndex;		// Group����[1,2]��Point::groupPoint[1]��Ч��
		short rev[3];
		double joint[8];		//����ֵ���ڹؽ�����ϵ�±�ʾ�����ؽڵ�ֵ���ڵѿ�������ϵ�±�ʾλ�ú���Ԫ��(��ŷ����)��ʾ����̬��[0,2]ΪXYZλ�ã�[3,6]Ϊ��̬��
	}GroupPoint;

	//����������
	typedef struct 
	{
		GroupPoint groupPoint[2];  
		double extJoint[8];
		unsigned char used;			//λ�õ��Ƿ���Ч���궨����0��Ч��>0��Ч
		unsigned char dynSynch;		//��̬���٣�0��Ч�� 1ʹ��
		unsigned char rev[6];
	}Point;


	//��״̬(32λ)
	typedef struct 
	{
		unsigned long bit0: 1;
		unsigned long servoAlm: 1;
		unsigned long bit2: 1;
		unsigned long bit3: 1;
		unsigned long posErr: 1;	//4
		unsigned long posiLmt: 1;	//5
		unsigned long negaLmt: 1;	//6
		unsigned long stopIO: 1;	//7
		unsigned long eStopIO: 1;	//8
		unsigned long axisOn: 1;	//9
		unsigned long prfRun: 1;	//10
		unsigned long inpos: 1;		//11
		unsigned long bit12: 20;
	}TRAxisStatus;

	//ָ����״̬
	typedef struct 
	{
		short execute;			//ָ����ִ��״̬��0��δִ�У�1������ִ�С�
		short empty;			//ָ�����ܿ�״̬��0��δ�ܿչ���1���ܿչ����ܿ�״̬���ٴε�������ָ����ָ��������ָ��������ʱ�������Ҳ���Ե������ָ����״̬��ָ����������
		short stopInfo;			//ָ����ֹͣ��Ϣ, 0����ֹͣ��Ϣ
								//1������ָ��GTN_StopCommandListֹͣ
								//2������ָ��GTN_Stopֹͣ
								//3������ָ��GTN_GroupStopֹͣ
								//4������ָ��GTN_ConditionStopCommandList����������ֹͣ
								//10��ָ�����ܿ�ֹͣ
								//11���ȴ�������ʱֹͣ
								//20����λ����ֹͣ
								//21����������ֹͣ
								//22����������ֹͣ
								//23�����Ÿ�������ֹͣ
								//24��ָ��GTN_SetStopIo���õ�IO��������ֹͣ
								//30��Group�������ֹͣ
		short commandType;		//����ִ�е�ָ������
								//COMMAND_LIST_TYPE_NONE(-1)��δ֪����
								//COMMAND_LIST_TYPE_MOTION_COMMAND(1)���˶�����ָ��
								//COMMAND_LIST_TYPE_DELAY_COMMAND(2)����ʱ����ָ��
								//COMMAND_LIST_TYPE_IO_COMMAND(3)��IO����ָ��
								//COMMAND_LIST_TYPE_WAIT_COMMAND(4)���ȴ�����ָ��
								//COMMAND_LIST_TYPE_OTHER_COMMAND(5)����������ָ��
		short	cmmand;		//����ִ�е�ָ��

		short remainderSegCount; //20200707 DSP�ռ��ʣ��δִ�ж�������������ָ����ʱ���ж����ݡ�

		short rev16[2];			

		long executeSegNum;		//ָ������ǰִ�жζκš�
		long space;				//ָ����DSPʣ��ռ䡣 20200707 ��ΪDSP�ռ��ȥǰհ����
		long userTag;
	}TRListStatus;


	//ָ��������
	typedef struct 
	{
		short list;				// ָ�����ţ�ȡֵ��Χ��[0,4]��0ʱ��ָ��Ϊ����ָ��,>0ʱ��ָ��Ϊָ����ָ��
		short modal;			// 0������ģʽ��1����ģʽ���ȴ���ǰָ���˶���ɡ�
		long segNum;			// ָ��κţ�ȡֵ��Χ��[-2147483648,2147483647]��
		long line;				// ָ���кţ����ڱ�����ʾ��
	}TRListInfo;


	//�����λ�˶�����(�����˶�)
	typedef struct
	{
		double pos;					// Ŀ��λ�ã���λmm��
		double vel;					// Ŀ���ٶȣ���λmm/s��
		double velEnd;				// �յ��ٶȣ���λmm/s��
		double acc;					// ���ٶ�,��λmm/s2
		double dec;					// ���ٶ�,��λmm/s2
		short direction;			// �˶�������ת��ģʽ����Ч��
		short overrideSelect;		// ����ѡ�񣬷�Χ��[0,16]��0��ʾ���ܱ���Ӱ��
		short reserve[2];
	} TRAxisAbsoluteMovePrm;

	//�����λ�˶�����(��Զ��˶�)
	typedef struct  
	{
		double distance;
		double vel;
		double velEnd;
		double acc;
		double dec;
		short overrideSelect;
		short reserve[3];
	} TRAxisRelativeMovePrm;


	//�����˶�ģʽ
	enum TYPE_AXIS_MOVE_MODE
	{
		AXIS_MOVE_ABS = 0,			//����ģʽ
		AXIS_MOVE_REL,				//���ģʽ
		AXIS_MOVE_JOG,				//Jogģʽ
		AXIS_MOVE_PROFILE_GEAR,		//����������滮ͬ���˶� 
		AXIS_MOVE_GROUP_GEAR,		//����group�ϳɹ滮ͬ���˶� 

		AXIS_MOVE_HMI_CMD=100		//���ⲿ����/ģʽ����
	};
	//�����˶�����
	typedef struct
	{
		short mode;					// �˶�ģʽ��TYPE_AXIS_MOVE_MODE��
		short direction;			// �˶����򣺾���ģʽ����ת��ģʽ����Ч��
		short overrideSelect;		// ����ѡ�񣬷�Χ��[0,16]��0��ʾ���ܱ���Ӱ��
		short reserve[1];

		double pos;					// Ŀ��λ��(����ģʽ)����λmm��
		double distance;			// һ������(���ģʽ)����λmm��
		double vel;					// Ŀ���ٶȣ���λmm/s�� ��JOGģʽ�£��ٶ�����ֵ�����˶�����
		double velEnd;				// �յ��ٶȣ���λmm/s��
		double acc;					// ���ٶ�,��λmm/s2
		double dec;					// ���ٶ�,��λmm/s2	
	} TRAxisMovePrm;



	//ֱ�߲岹�˶�����
	typedef struct  
	{
		double pos[GRT_MAX_GROUP_AXIS_NUM];	// Ŀ��λ�ã���λmm��
		short  dir[GRT_MAX_GROUP_AXIS_NUM];	// �˶�������ת��ģʽ����Ч��
		double vel;							// �ϳ��ٶȣ���λmm/s��ʵ�ʹ滮�ٶ�=�ϳ��ٶ�*�ٶȱ��ʣ�
		double acc;							// ���ٶ�,��λmm/s2	
		double dec;									// ���ٶ�,��λmm/s2
		double blendLen;					// blend���ȣ���λmm��
		short  overrideSelect;				// ����ѡ��
		short  endVelocityMode;			//�յ��ٶ�ģʽ��0��ǰհʹ��ʱ���յ��ٶ���ǰհģ�������1���յ��ٶ�Ϊ0��
		short  orientationDir;				// ��̬�仯����0����·������1����·������
		short  reserve2[1];
	} TRGroupLineMovePrm;


	//Բ���岹�˶�����
	typedef struct
	{
		short arcMode;								//Բ������ģʽ��CIRCULAR_MODE_SPACE_BORDER��
		short arcPlane;								//Բ���岹ƽ�棬XY,YZ,ZX
		short endPointMode;						//Բ���յ�ָ��ģʽ��0���յ�Ϊ������յ�λ�ã�1���յ���Բ�ĽǾ���
		short arcPathChoice;						//Բ���岹����ƽ��Բ��ʱΪ����(1����ʱ�룬-1��˳ʱ��)���ռ�Բ��Ϊ���ӻ�(1���ӻ���-1���Ż�)
		
		short auxPointCommandCoord;         //�м��λ����������ϵ
		short auxPointOrientationMode;		//�м��λ��������̬
		short auxPointConfigIndex;				 //�м�㹹�ͽ�
		short auxStartPointCommandCoord;    //�������λ����������ϵ

		short auxStartPointOrientationMode;	//�������λ��������̬
		short auxStartPointConfigIndex;		//������㹹�ͽ�

		short overrideSelect;						// ����ѡ��
		short endVelocityMode;					//�յ��ٶ�ģʽ��0��ǰհʹ��ʱ���յ��ٶ���ǰհģ�������1���յ��ٶ�Ϊ0��
		short  orientationDir;						// ��̬�仯����0����·������1����·������
		short  rev[3];	

		double arcRadius;							//Բ���뾶����λ��mm��
		double centralAngle;						//Բ�Ľǣ���λ���ȡ�
		double auxPoint[GRT_MAX_GROUP_AXIS_NUM];	//Բ���ĸ�����λ�ã�Բ�Ļ��м�㣩����λ��mm��
		double auStartPoint[GRT_MAX_GROUP_AXIS_NUM];//�������λ�ã�4��Բ��������λmm��

		double pos[GRT_MAX_GROUP_AXIS_NUM];			// �յ�λ�ã���λmm��
		double vel;									// �ϳ��ٶȣ���λmm/s��ʵ�ʹ滮�ٶ�=�ϳ��ٶ�*�ٶȱ��ʣ�
		double acc;									// ���ٶ�,��λmm/s2
		double dec;									// ���ٶ�,��λmm/s2
		double blendLen;							// blend���ȣ���λmm��

	}TRGroupCircularMovePrm;

	//(PCS/TCS)�ѿ�������ϵ�任����
	typedef struct
	{
		double transX;		//X��ƫ��������λ��mm��
		double transY;		//Y��ƫ��������λ��mm��
		double transZ;		//Z��ƫ��������λ��mm��
		double rotAngle1;	//��ת�Ƕ�1����λ���ȡ�
		double rotAngle2;	//��ת�Ƕ�2����λ���ȡ�
		double rotAngle3;	//��ת�Ƕ�3����λ���ȡ�
	}TRCartesianTransPrm;

	typedef struct
	{
		double vel;				        // λ���ٶȣ���λmm/s
		double oriVel;                  // ��̬�ٶȣ���λ��/s
		double reserve[18];
	}TRCartesianTransformVelConstraint;

	typedef union
	{
		TRCartesianTransformVelConstraint velConstraint;
		double value[20];
	}TRCartesianTransformConstraintUnion;

	typedef struct 
	{
		short mode;			// ģʽ
		short reserve[3];	
		TRCartesianTransformConstraintUnion data;
	}TRCartesianTransformConstraint;

	//���ù켣blending������ǰհ������Ч��
	typedef struct 
	{
		short blendType;	// �켣blending����:	0 BLEND_MODE_NONE��������
							//						1 BLEND_MODE_ARC�� Բ��blending
							//						2 BLEND_MODE_BIARC��˫Բ��blending
		short prmType;		// �켣blending���ɶβ�������:
							// 0 BLEND_PARA_TYPE_ERROR����ֻ��BLEND_MODE_ARC��Ч
							// 1 BLEND_PARA_TYPE_RADIUS������Բ���뾶��ֻ��BLEND_MODE_ARC��Ч
							// 2 BLEND_PARA_TYPE_DISTANCE������
		double prm;			// blending���ɶβ�������Բ���뾶�����룩����λmm��
		double minAngle;	// blending�������С�Ƕȣ����켣ʸ���Ƕȱ仯С�ڸýǶ�ʱ�����д���
		double maxAngle;	// blending��������Ƕȣ����켣ʸ���Ƕȱ仯���ڸýǶ�ʱ�����д���	
	}TRPathBlendingPrm;



	//�ȴ�DI�����ź�
	typedef struct
	{
		//MC_LIMIT_POSITIVE������λ��[1,24]
		//MC_LIMIT_NEGATIVE������λ��[1,24]
		//MC_ALARM������������[1,24]
		//MC_HOME��ԭ�㿪�ء�[1,24]
		//MC_GPI��ͨ�����롣[1,100]
		//MC_ARRIVE�������λ�źš�[1,24]
		//MC_MPG������MPG��ѡ�ͱ����źţ�5V��ƽ���룩��[1,28]

		short diType;
		short diIndex;
		short diCount;
		short rev1[1];
		short diValue[8];
		long  diOverTime;  // �ȴ���ʱʱ�䣬��0, 0Ϊ���ߵȴ�
		long  rev2[1];
	}TRWaitDIPrm;

	//����DO���״̬��
	typedef struct
	{
		//doType=MC_ENABLEʱ��doIndexȡֵ��ΧΪ��[1,24]��
		//doType=MC_CLEARʱ��doIndexȡֵ��ΧΪ��[1,24]��
		//doType=MC_GPOʱ��doIndexȡֵ��ΧΪ��[1,40]��
		//doType=MC_EHMI_DOʱ��doIndexȡֵ��Χ��[1,n]��nΪ��ʼ��EHMI�ӿ�ʱ�����õ�����

		//mode��do���ģʽ
		//	0����������������ƽ������
		//	1���ھ���Ŀ��㻹��ָ������ʱ����ʱһ��ʱ������
		//	2���Ⱦ��������
		//	3����ʱ�������

		// 101: ANTOUT DELAY
		// 102: ANTOUT DIS
		// 103: ANTOUT T

		short mode;              //Do���ģʽ
		short doType;
		short doIndex;
		short doCount;			  //[1,8]
		short doValue[8];

		double distance;	//mode1��ָ������,		mode2������	, ��λmm
		double time;		//mode1����ʱʱ��,		mode3��ʱ��	, ��λms
	}TRWriteDOPrm;


	//����ģ���������ѹ
	typedef struct
	{
		//aoType=MC_DACʱ��		aoIndexȡֵ��Χ��[1,8]��	aoValueȡֵ��Χ��[-10,10]���������Ϊ0.0003V��
		//aoType=MC_AU_DACʱ��	aoIndexȡֵ��Χ��[1,4]��	aoValueȡֵ��Χ��[0,10]���������Ϊ0.0024V��
		short aoType;
		short aoIndex;
		short count;
		short rev1;
		double aoValue[8];
	}TRWriteAOPrm;


	//����group���ٶȹ滮����
	typedef struct 
	{
		short mode;					// 40�� ROFILE_MODE_SMOOTH��ƽ��ģʽ;  46�� PROFILE_MODE_JERK��Jerkģʽ
		short jerkBeginPercent;		// Jerkģʽ����ʼ���ٶȰٷֱȣ�ȡֵ��Χ��[0,100]��
		short jerkEndPercent;		// Jerkģʽ����ֹ���ٶȰٷֱȣ�ȡֵ��Χ��[0,100]��
		short rev16[5];	

		double jerkValue;			// Jerkģʽ���Ӽ��ٶ�,ȡֵ��Χ��(0,...)����λ��mm/s^3

		double smoothAccTime;		// ƽ��ģʽ�����ٶȱ仯ʱ��
		double smoothK;				// ƽ��ģʽ����̬ϵ����ȡֵ��Χ��[0,1000]��

	} TRVelProfilePrm;


	//�ȴ�����ָ�����
	typedef struct
	{
		short enable;				// ʹ��
		short iCmdType;				// ָ�����ͣ�ListWait �� AstWait 
		short iResult;				// �ȴ����

		short iWaitType;			// P1 �ȴ����ͣ�DI��AI��VAR��DIS��T
		short iConditionParaType;	// P2 �Ƚ�DI��AI�����ͣ�VAR\B\I\R������
		short iConditionParaIndex;	// P3 �Ƚ�DI��AI�˿ںţ�
		short iConditionOption;		// P4 �Ƚ�ѡ�񣺴��ڡ�С��.....

		short iOutVarType;			// P8 ����������ͣ�VAR\B\I\R
		short iOutVarIndex;			// P9 �������������
		short iOverTimeOption;		// P10 ��ʱ����ѡ����ͣ��ֹͣ��������������
		short iMode;				// P11 �Ƿ�ģ̬��1ģ̬ 0��ģ̬
		short rev16[5];	
		
		long lContiTime;		// P6 ����ʱ��
		long lOverTime;			// P7 �ȴ���ʱʱ�䣬��0, 0Ϊ���ߵȴ�
		long lValue;			// P5 ���ͱȽ�ֵ��DI
		long segnum;			// �κ�

		double	dValue;			// P5 double�ͱȽ�ֵ��AI��VAR��DIS��T	
	}TRWaitConditionPrm;

	//�ȴ�����ָ��ִ��״̬
	typedef struct
	{
		short conditionDone;	//״̬��0�ȴ�����δ��ɣ�1�ȴ����������
		short modal;				//ģ̬��
		long segNum;				//�κ�
		long userTag;				//�к�
	}TRWaitConditionInfo;


	//ͬ��ָ��
	typedef struct
	{
		short enable;				//0����ʹ�ܣ�1��ʹ��
		short masterType;			// ����
		short masterIndex;			// ����
		short masterSubIndex;		// ��������
	
		short slaveType;			// ����
		short slaveIndex;			// ����
		short slaveSubIndex;		// ��������
	
		double masterEven;			// ������ϵ��������λ��
		double slaveEven;			// ������ϵ��������λ��	

		double slavePos;			// ����Ŀ��λ��
	}TRMoveSynPrm;

	//��̬����
	typedef struct
	{
		short groupID;
		short enable;    //0����ʹ�ܣ�1��ʹ��
		short masterType;
		short masterIndex;
		short masterMoveType;
		short trackMode;
		double originPrfPos;
		double masterOrigin[6];
		double pcsToMasterTcs[6];
	}TRDynTransPrm;


	// �����ڻ����ͼ�����
	typedef struct  
	{
		short type;				// �ڻ�����: (0)�����ΰڻ����ڻ����ӵ���������ϵ��Y�᷽��; (100)�����ΰڻ����ڻ����ӵ���������ϵ��X�᷽��;

		short weaveMode;		// �ڻ�ģʽ
								// 0���ڻ�����ʾ�ýṹ��������õ��ǰڻ�����
								// 1��Ԥ�ڻ�����ʾ�ýṹ��������õ���Ԥ�ڻ�����

		short frequencyMode;	// Ƶ��ģʽ
								// 0�������ڻ�ΪͬһƵ��
								// 1�������ڻ�ͨ��weavePrm[0]��weavePrm[1]����Ƶ�ʱ���

		double amplitude;		// �ڻ��������Χ��(0,10]����λ��mm 

		double frequency;		// �ڻ�Ƶ�ʣ���Χ��(0,100]����λ��Hz

		double weavePrm [10];	// �ڻ����β�������СΪ10�����顣
								// ���ڻ�����Ϊ�����Ͱڻ�ʱ��ͨ��weavePrm[0]��weavePrm[1]�����ֱ���������͸���ķ�ֵ������ȡֵ��ΧΪ[0,1]��
								// ���ڻ�����Ϊ����ΰڻ�ʱ��ͨ��weavePrm[0]������������ΰڻ��ļ��β���k��ȡֵ��ΧΪ[-1.5,1.5]��

		short startPosition;	// �ڻ���ʼλ�á�
								// 0�����м俪ʼ�ڻ�
								// 1������࿪ʼ�ڻ����ӵ���ֵΪ����������ʼ�ڶ�
								// 2�����Ҳ࿪ʼ�ڻ����ӵ���ֵΪ��������ʼ�ڶ�

		short dweelFullStop;	// ��ȫֹͣʹ��
								// 0����ʹ�ܡ����ڻ�ͣ��ʱ�䲻Ϊ0ʱ���˶��滮��ֹͣ��ֻ�ǲ����аڻ��˶���
								// 1��ʹ�ܡ����ڻ�ͣ��ʱ�䲻Ϊ0ʱ���滮ֹͣ�����ڻ�ͣ��ʱ��Ϊ0ʱ��dweelFullStopʹ�ܻ�ʹ�ܣ��滮����ֹͣ��

		double dweelLeft;		// �ڻ���ͣ��ʱ�䣬�ڵ���ֵΪ��������ʱ��ͣ��ʱ�䣬��λ��ms

		double dwellMid;		// �ڻ���ͣ��ʱ�䣬�ڵ���ֵΪ0ʱ��ͣ��ʱ�䣬��λ��ms

		double dwellRight;		// �ڻ���ͣ��ʱ�䣬�ڵ���ֵΪ������ʱ��ͣ��ʱ�䣬��λ��ms

		short oriControlMode;	// �ڻ���̬����ģʽ
								// 0���ڶ������в��ı�ԭ����̬��
								// 1���ڶ�������������̬���ƣ�ԭ�滮��̬����Ч�����ݲ�֧�֣�

		double rotateAngleX;	// ���˶�����ϵ��X�����ת�ǣ����ڿ�����������ת�ǣ�
								// ����ת�Ǵ���0��Ϊ���㣬��ת��С��0��Ϊ���㣬��Χ��[-90,90]����λ����

		double rotateAngleY;	// ���˶�����ϵ��Y�����ת�ǣ����ڿ���ǰ������ת�ǣ�
								// ��ת�Ǵ���0��Ϊǰ�㣬��ת��С��0��Ϊ���㣬��Χ��[-90,90]����λ����

		double rotateAngleZ;	// ���˶�����ϵ��Z�����ת�ǣ���Χ��[-90,90]����λ����

	}TRGroupWeavePrm;


	

	// ����ֱ�ӵ���ֵ
	typedef struct  
	{
		double value[8];                         // ����ֵ
		double reserve[24];
	}TRGroupSuperpositionValueDirect;

	typedef struct
	{
		short mode;                              // �ڻ�������ģʽ 0���ڻ�����ģʽ 1��Ԥ�ڻ�ģʽ
		short pad[3];                            // ����
		double time;                             // Ԥ�ڻ�ģʽ�ĳ���ʱ��
		double velocity;                         // Ԥ�ڻ�ģʽ���ٶ�
		double reserve[29];
	}TRGroupSuperpositionWeaveEx;

	typedef union  
	{
		TRGroupSuperpositionValueDirect direct;   // ֱ�ӵ���ֵ
		TRGroupSuperpositionWeaveEx weaveEx;      // �ڻ�������չģʽ
		double data[32];
	}TRGroupSuperpositionUnion;

	//group���˶����ӹ��ܲ���
	typedef struct  
	{
		short enable;         // �����Ƿ�ʹ��
		short mode;           // ����ģʽ 0��ֱ�ӵ��� 1������ʱ����аڻ����� 2���ڻ�������չģʽ
		short pad[2];
		double smoothTime;    // ƽ��ʱ��
		TRGroupSuperpositionUnion data;
	}TRGroupSuperpositionPrm;

	typedef struct  
	{
		short coordSystem;
		short oriMode;
		short configIndex;
		short targetOriMode;
		short reserve1[8];
		double inputPos[8];
		double preAcsPos[8];
		double reserve2[24];
	}TRGroupPosTransformInput;

	typedef struct  
	{
		short configIndex;
		short singularity;
		short reserve1[10];
		double pcsPos[8];
		double mcsPos[8];
		double acsPos[8];
		double reserve2[16];
	}TRGroupPosTransformOutput;
}
#endif