#pragma once

#ifndef GTROBOT_BACKEND_ADVANCED_H
#define GTROBOT_BACKEND_ADVANCED_H

#include "gtrobot_backend_define.h"

#ifdef GTR_BACKEND_LIB
# define GTR_ADVANCED_EXPORT extern "C" __declspec(dllexport)
#else
# define GTR_ADVANCED_EXPORT extern "C" __declspec(dllimport)
#endif



namespace Gtr_Advanced{

#ifdef Q_OS_LINUX 
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif

	struct Cmd_Movj{

		Gtr::Point des_point;	//Ŀ��λ�õ�
		double speed;			//�ٶȷ�Χ0~100(�ٷֱ�)����λ:��
		double blending;			//BL��Χ0~�ޣ���λ:mm
		double vblending;		//VBL��Χ0~100(�ٷֱ�)����λ:��
	};
	struct Cmd_Movl{

		Gtr::Point des_point;	//Ŀ��λ�õ�
		double speed;			//�ٶȷ�Χ0~�ޣ���λ:mm/s
		double blending;			//BL��Χ0~�ޣ���λ:mm
		double vblending;		//VBL��Χ0~100(�ٷֱ�)����λ:��
	};
	struct Cmd_Movc{

		Gtr::Point mid_point;	//�м�λ�õ�
		Gtr::Point des_point;	//Ŀ��λ�õ�
		double speed;			//�ٶȷ�Χ0~�ޣ���λmm/s
		double blending;			//BL��Χ0~�ޣ���λmm
		double vblending;		//VBL��Χ0~100(�ٷֱ�),��λ:��
	};
	struct Cmd_User{

		short type;				//ģ���
		short id;				//�˿ں�
		long long_data[4];		//long�Ͳ���
		double double_data[4];	//double�Ͳ���
	};
	struct Cmd_GetPos{

		short coord_type;		//����ϵ����,PCS:0,MCS:1,ACS:2,TCS:3,VCS:4,
		Gtr::Point output_point;//�����λ�õ�
	};
	struct Cmd_CoordNum{

		short coord_type;		//����ϵ����,PCS:0,MCS:1,ACS:2,TCS:3,VCS:4,
		short id;				//����ϵ����,��0��ʼ
	};
	struct Cmd_GetCapturePos{

		short coord_type;		//����ϵ����,PCS:0,MCS:1,ACS:2,TCS:3,VCS:4,
		Gtr::Point output_point;//�����λ�õ�
	};
	struct Cmd_Modal{

		short id;
		bool value;
	};
	struct Cmd_ExtJoint{
		bool sync;				//�Ƿ���ⲿ��ģ̬
	};
	struct Cmd_Speed{

		double speed;			//�ٶȱ��ʷ�Χ0~100(�ٷֱ�)����λ:��
	};
	struct Cmd_Dyn{

		double acceleration;	//���ٶȱ��ʷ�Χ0~100(�ٷֱ�)����λ:��
		double deceleration;	//���ٶȱ��ʷ�Χ0~100(�ٷֱ�)����λ:��
		double jerk;			//�Ӽ��ٶȷ�Χ0~120����λ:ms
	};
	struct Cmd_Set{

		short var_type;			//��Ҫset�ı�������,0-������B��1-������I��2-ʵ����R
		short var_index;		//����ֵ����
		union
		{
			bool b_value;		//�����ͱ���ֵ
			long i_value;		//�����ͱ���ֵ
			double r_value;		//ʵ���ͱ���ֵ
		}value;
	};
	struct Cmd_Until{

		short wait_type;				//�ȴ����� 0-DI��2-�����ͱ���B��3-�����ͱ���I��4-ʵ���ͱ���
		short wait_para1;				//���ȴ�DI�������DIģ��ţ���������Ϊ�����±�
		short wait_para2;				//���ȴ�DI�������DI�˿ںţ��������͸ò�����Ч
		Gtr::COMPARE_OPTION wait_operator;	//�ȴ�������0-����>��1-����=��2-������!=��3-���ڵ��ڡ�=��4-С�ڵ���<=��5С��<
		double wait_value;				//�ȴ����
		long continue_time;				//����ʱ��
		long over_time;					//��ʱʱ��
		short output_var_type;			//����������� 0-�������2-�����ͱ���B��3-�����ͱ���I��4-ʵ���ͱ���
		short var_index;				//�����������
	};
	struct Cmd_Wait{

		short wait_type;				//�ȴ����� 0-DI��2-�����ͱ���B��3-�����ͱ���I��4-ʵ���ͱ���
		short wait_para1;				//���ȴ�DI�������DIģ��ţ���������Ϊ�����±�
		short wait_para2;				//���ȴ�DI�������DI�˿ںţ��������͸ò�����Ч
		Gtr::COMPARE_OPTION wait_operator;	//�ȴ�������0-����>��1-����=��2-������!=��3-���ڵ��ڡ�=��4-С�ڵ���<=��5С��<
		double wait_value;				//�ȴ����
		long continue_time;				//����ʱ��
		long over_time;					//��ʱʱ��
		short output_var_type;			//����������� 0-�������2-�����ͱ���B��3-�����ͱ���I��4-ʵ���ͱ���
		short var_index;				//�����������
		short overtime_option;			//��ʱ����0-��ͣ�˶���1-ֹͣ�˶��ұ�����2-�����˶�
		bool is_modal;					//�Ƿ�Ϊģָ̬�� 
	};
	struct Cmd_Timer{

		double time;			//��ʱ��Χ0~�ޣ���λ��ms
	};
	struct Cmd_ExtjSpeed{

		short axis_id;			//���
		double speed;			//�ٶȱ��ʷ�Χ0~100(�ٷֱ�)����λ:��
		double acceleration;	//���ٶȱ��ʷ�Χ0~100(�ٷֱ�)����λ:��
		double deceleration;	//���ٶȱ��ʷ�Χ0~100(�ٷֱ�)����λ:��
	};
	struct Cmd_Dout{

		short module;			//DOģ��ţ�1-����IO��2-��չIO
		short port;				//�˿ںţ�-1��������DOģ��,���֧��32λDO
		long value;	//�趨ֵ
	};
	struct Cmd_Din{

		short module;			//DOģ��ţ�1-����IO��2-��չIO
		short port;				//�˿ںţ�-1��������DOģ��,���֧��32λDO
		short output_var_type;	//�������������,0-�����ͱ���B��1-�����ͱ���I
		short output_var_index;	//�������������
	};
	struct Cmd_PauseDecoder{

		short pause_decoder;
	};

#pragma pack(pop)



/*-------------��˽ӿ�-��ָ̬��-----------------------*/


/**
 * @brief		ʹ������ϵͳ���붯ָ̬����ģʽ
 * @param[in]	<int group> ϵͳ���������
 * @note		������ϵͳ�л����ط�-��ָ̬��ģʽ����Ҫ������ǰ(�ֳֺ��̵�����ǰ)���ã�
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:����ָ�����״̬�ɹ�
 * @return		<other value>: ����ָ�����״̬ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_EnterStreamMode(short channel = GtrCurrentChannel);


/**
 * @brief		���û�����ϵͳ��ָ̬��״̬
 * @param[in]	<int group> ϵͳ���������
 *				���������ָ����е�ָ��
 * @return		<0>:����״̬�ɹ�
 * @return		<other value>: ����״̬�ɹ�ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_CancelMotion(bool clear_alarm,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��MOVJ
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddMovj(Gtr_Advanced::Cmd_Movj *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��MOVL
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddMovl(Gtr_Advanced::Cmd_Movl *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��MOVC
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddMovc(Gtr_Advanced::Cmd_Movc *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��USER
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddUser(Gtr_Advanced::Cmd_User *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��GETPOS
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddGetpos(Gtr_Advanced::Cmd_GetPos *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��COORD_NUM
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ���ڿɶ�̬����ָ���״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddCoordNum(Gtr_Advanced::Cmd_CoordNum *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��GETCAPTUREPOS
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddGetCapturePos(Gtr_Advanced::Cmd_GetCapturePos *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		�����ָ��
 * @param[in]	<none>
 * @note		�����ָ����������������ָ��ص�ָ��
 *				����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddBlank(short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��MODAL
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddModal(Gtr_Advanced::Cmd_Modal *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��EXTJOINT
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddExtJoint(Gtr_Advanced::Cmd_ExtJoint *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��SPEED
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddSpeed(Gtr_Advanced::Cmd_Speed *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��DYN
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddDyn(Gtr_Advanced::Cmd_Dyn *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��SET
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddSet(Gtr_Advanced::Cmd_Set *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��UNTIL
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddUntil(Gtr_Advanced::Cmd_Until *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��WAIT
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddWait(Gtr_Advanced::Cmd_Wait *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��TIMER
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddTimer(Gtr_Advanced::Cmd_Timer *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��EXTJSPEED
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddExtjSpeed(Gtr_Advanced::Cmd_ExtjSpeed *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��DIN
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddDin(Gtr_Advanced::Cmd_Din *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��DOUT
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddDout(Gtr_Advanced::Cmd_Dout *cmd,short channel = GtrCurrentChannel);


/**
 * @brief		����ָ��PAUSE_DECODER
 * @param[in]	<none>
 * @note		����ǰȷ��������ϵͳ����ָ������״̬(����short GTR_DYN_Start())
 *				���������ϵͳ�����޷���̬����ָ��
 * @return		<0>:ָ�����ɹ�
 * @return		<other value>: ָ�����ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_AddPauseDecoder(short channel = GtrCurrentChannel);


/**
 * @brief		ʹ������ϵͳ����ָ������״̬����ִ��ָ��
 * @param[in]	<int group> ϵͳ���������
 * @note		���øýӿں�������ָ����ִ����ϣ��������ϵͳ��
 *				�������״̬���ֳֺ��̵�Ϩ�𣩲��Զ����½���ָ������״̬
 * @return		<0>:����ָ�����״̬�ɹ�
 * @return		<other value>: ����ָ�����״̬ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_StartCmdMotion(short channel = GtrCurrentChannel);


/**
 * @brief		��ȡ��ǰָ�����ָ������
 * @param[in]	<int group> ϵͳ���������
 * @note		ָ�������Ϊ4096��ָ��
 * @return		ָ��ص�ǰָ��ָ������
 */
GTR_ADVANCED_EXPORT short GTR_GetCmdCount(long &count,short channel = GtrCurrentChannel);


/**
 * @brief		��յ�ǰָ���������ָ��
 * @param[in]	<int group> ϵͳ���������
 * @return		<0>:���ָ��سɹ�
 * @return		<other value>: ���ָ���ʧ��
 */
GTR_ADVANCED_EXPORT short GTR_ClearCmdPool(short channel = GtrCurrentChannel);


/**
 * @brief		�жϵ�ǰָ����Ƿ�Ϊ��
 * @param[in]	<int group> ϵͳ���������
 *				���������ָ����е�ָ��
 * @return		<false>:ָ���δ��
 * @return		<true>: ָ����ѿ�
 */
GTR_ADVANCED_EXPORT short GTR_IsCmdEmpty(bool &result,short channel = GtrCurrentChannel);


/**
 * @brief		�жϵ�ǰָ����Ƿ�����
 * @param[in]	<int group> ϵͳ���������
 *				���������ָ����е�ָ��
 * @return		<false>:ָ���δ��
 * @return		<true>: ָ�������
 */
GTR_ADVANCED_EXPORT short GTR_IsCmdFull(bool &result,short channel = GtrCurrentChannel);

}

#endif