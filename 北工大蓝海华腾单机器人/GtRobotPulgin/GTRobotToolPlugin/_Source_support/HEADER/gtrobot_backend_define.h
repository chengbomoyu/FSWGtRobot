#pragma once
#ifndef GTROBOT_BACKEND_DEFINE_H
#define GTROBOT_BACKEND_DEFINE_H

#include <string>
#include <Windows.h>

const short GtrCurrentGroup = -1;
const short GtrCurrentChannel = -1;

const short GtrMaxChannelNum =	2;	// ������ϵͳ֧�ֵ����ͨ����
const short GtrMaxGroupNum =	3;	// ������ϵͳ֧�ֵ�����������
const short GtrMaxAxisNum =		16;	// ������ϵͳ֧�ֵ��������

const short GtrMaxCraftNum =	32;	// ������ϵͳ֧�ֵ����������

const short GtrMaxBufSize =		256;// ������ϵͳ�α�������������


namespace Gtr{


#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

	//Group����
	struct GroupPoint
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
	};

	//����������
	struct Point
	{
		GroupPoint groupPoint[2];  
		double extJoint[8];
		unsigned char used;			//λ�õ��Ƿ���Ч���궨����0��Ч��>0��Ч
		unsigned char dynSynch;		//��̬���٣�0��Ч�� 1ʹ��
		unsigned char rev[6];
		char comment[256];			//λ���ͱ���ע����Ϣ
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

		// 100�����ⲿ�������

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
		double absZeroRefPos;						// <������Ч> �ο���λ�ã�Ĭ��0������λ��mm��ȡ����Ա��������(absEncoderZeroPos)��Ӧ�Ļ������ꡣ	
		double revd64[14];
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

		double axisMoveVel;		//<������Ч>	�ӹ�ʱ�������˶��ٶȣ�		��λ��mm/s���/s��
		double axisMoveAcc;		//<������Ч>	�ӹ�ʱ�������˶����ٶȣ�	��λ��mm/s^2���/s^2��
		double axisMoveDec;		//<������Ч>	�ӹ�ʱ�������˶����ٶȣ�	��λ��mm/s^2���/s^2��

		double rev64[140];
	};



	//ͨ����Group�����ÿ��Ʋ���
	struct GroupConfig
	{
		//8λ������Ԥ��100��/////////
		bool bEnBlending;				//  <��λ��Ч>	�����켣blending
		bool bEnableDynPara;			//  <��λ��Ч>	��������ѧ����
		bool bEnableLookAhead;			//  <��λ��Ч>	����ǰհ

		bool bEnAcsPosiLmt[8];			//  <��λ��Ч>	ACS�¿�����������λ
		bool bEnAcsNegaLmt[8];			//  <��λ��Ч>	ACS�¿�����������λ
		bool bEnMcsPosiLmt[3];			//  <��λ��Ч>	MCS�¿�����������λ
		bool bEnMcsNegaLmt[3];			//  <��λ��Ч>	MCS�¿�����������λ
		bool bEnPcsPosiLmt[3];			//  <��λ��Ч>	PCS�¿�����������λ
		bool bEnPcsNegaLmt[3];			//  <��λ��Ч>	PCS�¿�����������λ

		bool bEnAxisJointOffset;			// <��λ��Ч>	�ؽ�ƫ��(JointOffset)�Ƿ���������(absZeroRefPos)ƫ�ƣ�false�����ӡ�true���ӣ�Ĭ��false��

		bool rev8[68];

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

		short acsVelMode;  //<����>	ACS������ϵ���˶���ָ���ٶȺͼ��ٶȵ����͡�
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
		double teachAcsMovVel;				// <����>	�˶����㣺ACS�ؽ�����ϵ���˶��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
		double teachAcsMovAcc;				// <����>	�˶����㣺ACS�ؽ�����ϵ���˶����ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
		
		//ʾ�����˶����㣺�ѿ�������ϵ���˶�����
		double teachMcsMovVel;				// <����>	�˶����㣺MCS�ؽ�����ϵ���˶��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s��
		double teachMcsMovAcc;				// <����>	�˶����㣺MCS�ؽ�����ϵ���˶����ٶ�,ȡֵ��Χ��(0,...)����λ��mm/s^2��
		
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

		double acsPosiLmtOffset[8];			//  <��λ��Ч>	ACS����������λƫ��ֵ
		double acsNegaLmtOffset[8];			//  <��λ��Ч>	ACS�¸�������λƫ��ֵ
		double mcsPosiLmtOffset[3];			//  <��λ��Ч>	MCS����������λƫ��ֵ
		double mcsNegaLmtOffset[3];			//  <��λ��Ч>	MCS�¸�������λƫ��ֵ
		double pcsPosiLmtOffset[3];			//  <��λ��Ч>	PCS����������λƫ��ֵ
		double pcsNegaLmtOffset[3];			//  <��λ��Ч>	PCS�¸�������λƫ��ֵ

		double arcErr;							//  <��λ��Ч>	Բ��������

		//dec ���ٶ�
		double movjDec;						// <����>	MOVJĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
		double movlDec;						// <����>	MOVLĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
		double movcDec;						// <����>	MOVCĬ�ϼ��ٶȣ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
		double teachAcsMovDec;				// <����>	�˶����㣺ACS�ؽ�����ϵ���˶����ٶȡ�ȡֵ��Χ��(0,...)����λ��mm/s^2��
		double teachMcsMovDec;				// <����>	�˶����㣺�ѿ�������ϵ���˶����ٶȡ�ȡֵ��Χ��(0,...)����λ��mm/s^2��

		double rev64[211];
	};


	struct SysCtlParam
	{
		//8λ������Ԥ��40��

		bool nWatchMode;			// <����>		WATCHģʽ  0�ر�WATCHģʽ��1����WATCHģʽ��Ĭ��0.
		bool bGxnExtModule;			// <������Ч>	�Ƿ�������GXN��չģ�飨0��ʾ�ޣ�1�У���Ĭ��0.
		bool bDisableAxisStopDI;	// <��λ��Ч>	�Ƿ�ر���ֹͣ�źţ�0���� 1�رգ���Ĭ��0��

		//16λ������Ԥ��40��
		short nCardType;		// <������Ч>	���ƿ����������ͣ�GtRobotDef::CardType 
		short nSysAxisNum;		// <������Ч>	ϵͳ��������
		short nSysChannelNum;	// <������Ч>	ϵͳͨ������[1,2],Ĭ��1
		short nSysGroupNum;		// <������Ч>	ϵͳ����Group����[1,2],Ĭ��1
		short eHmiType;			// <������Ч>	eHMI������ͣ�0��ʾ����壩
		short eHmiDiNum;		// <������Ч>	eHMI���Di����
		short eHmiDoNum;		// <������Ч>	eHMI���Do����

		short iDebugMsgLevel;	// <����>		������Ϣ����ȼ���Ĭ��0��ϵͳ�ڲ����ݲ�ͬ�ĵȼ��������ͬ������Ϣ������ϵͳ����Ų����⣩

		short nCardOpenChannel;	// <������Ч>	Ĭ��5.	GTN_Open(short channel=5,short param=1) 
		short nCardOpenParam;	// <������Ч>	Ĭ��1.	GTN_Open(short channel=5,short param=1)

		short nBoolVarNum;		// <����>		֧�ֵ�BOOL���ڲ�����������[0,20],Ĭ��0
		short nLongVarNum;		// <����>		֧�ֵ�Long���ڲ�����������[0,20],Ĭ��0
		short nDoubleVarNum;	// <����>		֧�ֵ�Double���ڲ�����������[0,20],Ĭ��0

		short nRemoteMode;		//<����> Զ��ģʽѡ��	0������,1Զ��IOģʽ,2Զ��TCPģʽ

		short nReplayIoEnable;	//<����> �ط�ģʽ��IO������Чʹ�ܣ�0��ʹ��IO��1ʹ��IO
		short nReplayBtnDisable;//<����> �ط�ģʽ���ֳֺ��̵���׵�����ʹ�ܣ�0���β�ʹ�ܣ�1����ʹ��

		short nSwitchTon;		//<����> ���ο��ؽ�ͨ��ʱ,��λms
		short nSwitchTof;		//<����> ���ο��ضϿ���ʱ,��λms

		unsigned short nSynPosCycleTime;	// <����>	ϵͳ����ʱ��λ��ͬ�����ڡ���λms��Ĭ��1000ms��<1ʱ��ͬ��
		short nCapturePosType;				// <����>	�źŴ�������λ�õ�����	
											//			0 �滮λ�ã��ޱ�����ʱ�������ã���
											//			1 ������λ��(ʵ��ʹ��)
											//			Ĭ��1

		short nEstopMode;		//<����> ��ͣģʽ 0��ͣ������ʹ�ܣ�1��ͣ���ٵ�0����ʹ�ܣ�Ĭ��0
		short nRuntoPointMode;	//<����> �˶�����ģʽ 0��ǰ����ϵ�����˶��岹��1ǿ�ƽ��йؽڲ岹��2ǿ�ƽ���ֱ�ǲ岹 Ĭ��0

		short nCoordinateMode;	//<����> ����ϵģʽ 0���л���������ϵ��1����TCS��PCS�л�(�����������������TCS��PCS)��Ĭ��0
		short nSystemLanguage;	//<����> ������ϵͳ��ǰ�������ͣ�0���ģ�1Ӣ��
		short nSystemChannel;	//<����> ������ϵͳͨ����
		short nSystemGroup;		//<����> ������ϵͳ��ǰ��Group��0-��һ��Group��1-�ڶ���Group��2-������Group
		short nbreakModeEnable;	//<����> �Ƿ����ϵ�������0-�رգ�1-����
		short nSpeedMode;		//<����> ȫ�ֱ����л�ģʽ 0��HMI���б����л� 1��PLC���б����л�
		short nPositionerJogMode;//<����> ��λ��JOGģʽ 0���л���������2����jog 1��ʹ����չ�ᰴ������JOG
		short nRecordPosMode;		//<����> ��¼λ�õ�ģʽ 0����ǰ����ϵ 1��ǿ�Ƽ�¼ACSλ�� 2��ǿ�Ƽ�¼MCSλ�� 

		short nGxnExtModuleNum;		//<����> GXN��չIOģ��ĸ���
		short sSvalogToFile;		//<����> ϵͳ������־���� 0:�˳�ϵͳʱ������־ 1:�˳�ϵͳ��ʱ������־
	};

	//ͨ�����Ʋ���
	struct SysChannelCtrlParam
	{
		//8λ������Ԥ��40��
		unsigned char bEnableDynamicCoordinate;   // <��λ��Ч> �Ƿ�ʹ�ܶ�̬����ϵ���١�0��ʹ�� 1ʹ�ܣ�Ĭ��0

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
		
		long forcedReplayStartLine;			//<����> �ط�ģʽǿ�������к�
		
		double jogStepLen;					// ʾ��ģʽ�£��ֶ�����ģʽ�Ĳ�������λmm��ȡ�

		char forceReplayStartPrg[256];		//<����> �ط�ģʽǿ����������Ŀ¼
	};


	//��ϱȲ���
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
	struct HmiCoupleGroupPara
	{
		CouplePara couple_para[4];
	};

	//����ϵ����
	struct CoordSystem
	{
		short type;				// ����
		short orientationMode;	// ��̬����ģʽ(Ĭ��=GroupConfig::orientationMode)��
								// ����ϵΪ�ѿ�������ϵʱ����Ҫָ����̬������ģʽ��
								// 0 ORI_MODE_NONE������̬������
								// 1 ORI_MODE_EULER��ŷ������̬������
								// 2 ORI_MODE_QUAD����Ԫ����̬������
								// 3 ORI_MODE_VECTOR������ʸ����̬������
								// 4 ORI_MODE_ROTATE_AXIS_POS����ת��λ����̬����
		short rev16[2];

		//������
		double pos[3];
		double ori[4];
	};

	struct TcpServerConfig
	{
		bool b_enable;					///<ʹ��
		char ip[20];					///<IP��ַ
		unsigned short port;			///<�˿�
	};

	struct TcpConnectClientInfo
	{
		std::string ip;					///<IP��ַ
		unsigned short port;			///<�˿�
		unsigned long last_comm_time;	///<��һ�����ݽ���ʱ��(ms)
	};


	struct ModbusServerConfig
	{
		bool b_enable;					///<ʹ��
		char ip[20];					///<IP��ַ
		unsigned short port;			///<�˿�
		unsigned short *p_di_data;		///<�������ݵ�ַ
		unsigned short *p_do_data;		///<������ݵ�ַ
		unsigned short time_out;		///<��ʱʱ��
	};

	struct ModbusClientConfig
	{
		bool b_enable;					///<ͨѶ����ʹ��
		bool b_read;					///<ͨѶ���ڶ�ʹ��
		bool b_write;					///<ͨѶ����дʹ��
		char ip[20];					///<IP��ַ
		unsigned short port;			///<�˿�
		unsigned short station_id;		///<վ��ַ
		unsigned short read_start_adress;///<����ʼ��ַ
		unsigned short read_data_len;	///<�����ݳ���
		unsigned short write_start_adress;///<д��ʼ��ַ
		unsigned short write_data_len;	///<д���ݳ���
		unsigned short *p_di_data;		///<�������ݵ�ַ
		unsigned short *p_do_data;		///<������ݵ�ַ
		unsigned short time_out;		///<��ʱʱ��,��λ����
	};


	//��״̬
	struct AxisStatus
	{
		bool is_servo_alarm;		//�ŷ�����״̬
		bool is_pos_error;			//��������
		bool is_positive_limit;		//����λ����
		bool is_negative_limit;		//����λ����
		bool is_stop_io;			//��ֹͣ�ź�
		bool is_estop_io;			//��ͣIO
		bool is_axis_on;			//�ŷ�״̬
		bool is_profile_running;	//�˶��滮��
		bool is_inpos;				//�˶���λ
	};


	//������״̬
	struct DriverStatus
	{
		bool is_over_current;			//����
		bool is_over_voltage;			//��ѹ
		bool is_under_voltage;			//Ƿ��ѹ
		bool is_input_outphase;			//����ȱ��
		bool is_encoder_error;			//����������
		bool is_over_load;				//����
		bool is_over_temperature;		//����
		bool is_io_error;				//IO����
		bool is_register_protection;	//�Ĵ�������
		bool is_power_error;			//����ģ�����
		bool is_over_speed;				//���ٶ�
		bool is_over_pressure;			//��ѹ
		bool is_direction_protection;	//���򱣻�
		bool is_instant_over_current;	//˲�����
		bool is_output_offline;			//�������
	};

#pragma pack(pop)

	// �����ڻ����ͼ�����
	struct GroupWeavePrm
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

	};


	// ����ֱ�ӵ���ֵ
	struct GroupSuperpositionValueDirect
	{
		double value[8];                         // ����ֵ
		double reserve[24];
	};

	struct GroupSuperpositionWeaveEx
	{
		short mode;                              // �ڻ�������ģʽ 0���ڻ�����ģʽ 1��Ԥ�ڻ�ģʽ
		short pad[3];                            // ����
		double time;                             // Ԥ�ڻ�ģʽ�ĳ���ʱ��
		double velocity;                         // Ԥ�ڻ�ģʽ���ٶ�
		double reserve[29];
	};

	union GroupSuperpositionUnion
	{
		GroupSuperpositionValueDirect direct;   // ֱ�ӵ���ֵ
		GroupSuperpositionWeaveEx weaveEx;      // �ڻ�������չģʽ
		double data[32];
	};

	//group���˶����ӹ��ܲ���
	struct GroupSuperpositionPrm{
		
		short enable;         // �����Ƿ�ʹ��
		short mode;           // ����ģʽ 0��ֱ�ӵ��� 1������ʱ����аڻ����� 2���ڻ�������չģʽ
		short pad[2];
		double smoothTime;    // ƽ��ʱ��
		GroupSuperpositionUnion data;
	};


	struct UserComParam
	{
		short channel_index;
		short user_id;			//��ӦUSERָ�������ID
		long  long_param[4];	//��ӦUSERָ�������L1��L2��L3��L4
		double double_param[4]; //��ӦUSERָ�������D1��D2��D3��D4
	};

	//��־
	struct LogItem
	{
		short log_type;
		short user_type;
		char log_id[256];
		char text[256];
		char datetime[256];

		LogItem(){

			log_type = -1;
			user_type = -1;
			memset(log_id,0,256);
			memset(text,0,256);
			memset(datetime,0,256);
		}
	};

	//��־-���ݾɰ汾
	struct GT_LogItem
	{
		char username[256];
		char text[256];
		char datetime[256];

		GT_LogItem(){

			memset(username,0,256);
			memset(text,0,256);
			memset(datetime,0,256);
		}
	};

	//TCPͨ��
	struct STcpServerInfo
	{
		char ip[20];					///<IP��ַ
		unsigned short port;			///<�˿�
	};

	struct STcpClientStatus
	{
		bool is_connecting;				///<��������״̬
		bool is_connected;				///<�Ѿ�������
		bool allow_read;				///<�����ȡ
	};

	typedef short (*GtrUserCom)(const UserComParam &param,bool first);
	typedef short (*GtrUserRun)();
	typedef void (*GtrPlcLoop)();


	//����ϵ
	enum TYPE_COORD
	{
		PCS = 0,		//COORD_SYSTEM_PCS,
		MCS = 1,		//COORD_SYSTEM_MCS,
		ACS = 2,		//COORD_SYSTEM_ACS,
		TCS = 3,		//COORD_SYSTEM_TCS,
		VCS	= 4,		//COORD_SYSTEM_VCS,
		FCS = 5,		//COORD_SYSTEM_FCS,
		CURRENT = 6,	//��ǰ����ϵ
		MVCS = 10,		//COORD_SYSTEM_MVCS
		PCS2 = 40		//COORD_SYSTEM_PCS2
	};

	enum Key
	{
		Key_EStop =			0,	// ��ͣ��ť
		Key_Start,				// ����
		Key_Stop,				// ֹͣ/��ͣ
		Key_ThreeStateSwitch,	// ���ο���

		Key_ServoOn =		10,	// �ŷ�׼����
		Key_Reset,				// ��λ/�������
		Key_SpeedUp,			// ����
		Key_SpeedDown,			// ����
		Key_MoveForward,		// ǰ����ǰ����飬���˶����㣩
		Key_MoveBackward,		// ���ˣ����ȼ�飬���˶����㣩
		Key_OverrideLimit,		// ȡ������

		Key_SwitchExtAxis =	20,	// �л��ⲿ��
		Key_SwitchRobotGroup,	// �л���������
		Key_SwitchCoord,		// �л�����ϵ
		Key_SwitchCmdType,		// �л�ָ�����ͣ��л����岹�����ͣ�

		Key_CmdList =		30,	// ����һ��
		Key_Insert,				// ����
		Key_Delete,				// ɾ��
		Key_Edit,				// �޸�
		Key_Confirm,			// ȷ��

		Key_Shift =			40,	// �ϵ�
		Key_Ctrl,				// ����
		Key_PageDown,			// ��ҳ
		Key_Up,					// ���������
		Key_Down,				// ���������
		Key_Left,				// ���������
		Key_Right,				// ���������

		Key_0 =				50,	// ����0
		Key_1,					// ����0
		Key_2,					// ����0
		Key_3,					// ����0
		Key_4,					// ����0
		Key_5,					// ����0
		Key_6,					// ����0
		Key_7,					// ����0
		Key_8,					// ����0
		Key_9,					// ����0

		Key_Dot =			60,	// Ӣ�ľ��(��".")
		Key_Minus,				// ���ţ����"-"��

		Key_X_Negative  =	70,	//�ֳֺа���X-
		Key_X_Positive,			//�ֳֺа���X+
		Key_Y_Negative,			//�ֳֺа���Y-
		Key_Y_Positive,			//�ֳֺа���Y+
		Key_Z_Negative,			//�ֳֺа���Z-
		Key_Z_Positive,			//�ֳֺа���Z+
		Key_RX_Negative,		//�ֳֺа���RX-
		Key_RX_Positive,		//�ֳֺа���RX+
		Key_RY_Negative,		//�ֳֺа���RY-
		Key_RY_Positive,		//�ֳֺа���RY+
		Key_RZ_Negative,		//�ֳֺа���RZ-
		Key_RZ_Positive,		//�ֳֺа���RZ+
		Key_E1_Negative,		//�ֳֺа���E1-
		Key_E1_Positive,		//�ֳֺа���E1+
		Key_E2_Negative,		//�ֳֺа���E2-
		Key_E2_Positive,		//�ֳֺа���E2+
	};

	//ԭö������ Running_Mode 2021.05.16
	enum RUNNING_MODE{

		MODE_TEACH = 1,		//ʾ��ģʽ
		MODE_REPLAY,		//�ط�ģʽ
		MODE_REMOTE			//Զ��ģʽ
	};

	//ԭö������ Running_Status 2021.05.16
	enum RUNNING_STATUS{

		IDLE = 1,			//����״̬
		PAUSE ,				//��ͣ״̬
		RUNNING				//����״̬
	};

	enum TEACH_STATUS{

		TEACH_IDLE = 1,				//ʾ��ģʽ-����״̬
		TEACH_FORWARD_STATUS,		//ʾ��ģʽ-ǰ�����״̬
		TEACH_BACKWARD_STATUS,		//ʾ��ģʽ-���˼��״̬
		TEACH_MOVE_TO_POINT_STATUS,	//ʾ��ģʽ-�˶�����״̬
		TEACH_JOG_STATUS			//ʾ��ģʽ-JOG�˶�״̬
	};

	//ԭö������ Compare_Option 2021.05.16
	enum COMPARE_OPTION{
	
		 CP_LT = 1,			//С��<
		 CP_LE,				//С�ڵ���<=
		 CP_GT,				//����>
		 CP_GE,				//����>=
		 CP_EQ,				//����=
		 CP_NEQ				//������!=
	};

	//ԭö������ LogType 2021.05.16
	//��־����
	enum LOG_TYPE{

		TYPE_DEBUG,
		TYPE_INFO,
		TYPE_WARNING,
		TYPE_ALARM,
		TYPE_CRITICAL
	};

	// ������ϵͳ�α�����������
	enum DataType
	{
		TYPE_FLOAT = 0,			// ��������
		TYPE_DOUBLE = 1,		// ˫���ȣ�ʵ���ͱ�����
		TYPE_BOOL = 2,			// �����ͣ������ͱ�����
		TYPE_SHORT = 3,			// ������
		TYPE_UNSIGNED_SHORT = 4,// �޷��Ŷ����ͣ��Ĵ���������
		TYPE_LONG = 5,			// �����ͣ������ͱ�����
		TYPE_UNSIGNED_LONG = 6,	// �޷��Ŷ�����
		TYPE_UNSIGNED_CHAR = 7, // �޷����ַ���
		TYPE_POINT = 10,		// ͨ��λ�ã�λ���ͱ�����
		TYPE_GROUP_POINT = 11,	// ��������λ��
		TYPE_COORD_SYSTEM = 12,	// ����ϵ
		TYPE_STR = 20,			// �ַ������ַ��ͱ�����
	};

	// ������ϵͳ�α�����������
	enum ActionType
	{
		GET_FROM_ROBOT = 0,	// �ӻ�������������ȡ����������
		SET_TO_ROBOT = 1	// ������������д�������������
	};

	// �����˹�������
	enum CraftType
	{
		CRAFT_SYSTEM =		0,	// ������ϵͳ

		CRAFT_USER =		10,	// �û��Զ��幤��
		CRAFT_PALLETIZE =	11,	// ���
		CRAFT_PUNCH =		12,	// ��ѹ
		CRAFT_SCREW =		13,	// š��
		CRAFT_SORT =		14,	// �ּ�
		CRAFT_BEND =		15,	// ����
		CRAFT_GRIND =		16,	// ��ĥ
		CRAFT_ARCWELD =		17,	// ����
		CRAFT_SPRAY =		18,	// ��Ϳ
		CRAFT_OTHER =		19,	// ��������
	};

	// �α�����������������ԭ��
	// @param [in/out] const char * ����/����Ĳα�������������󳤶�ΪGtrMaxBufSize
	// @param [in/out] Gtr::DataType & ����/����ı�����������
	// @param [in] const Gtr::ActionType & �����������
	// @param [in] const long & ����ı�������
	// @param [in] const short & ����Ķ�������
	// @param [in] const short & �������������
	typedef short(*GTR_RobotValueAction)(char buf[GtrMaxBufSize],  
		Gtr::DataType &,
		const Gtr::ActionType &, 
		const long &, 
		const short &, 
		const short &);
}

#endif