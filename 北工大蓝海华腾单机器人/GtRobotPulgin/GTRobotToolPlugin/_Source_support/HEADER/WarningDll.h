/////////////////////////////////////////////////////////////////////////  
/// COPYRIGHT NOTICE  
/// Copyright (c) 2016,  ����Ȩ������  
/// All rights reserved.  
///  
/// @file          WarningDll.h  
/// @brief         �����������ģ��  &&   ��ǰ��־��¼����ģ��
///    
///  
/// @version 1.0        
/// @author        ��ƽ 
/// @date          2016��6��6�� 
///   
/// �޶�˵��������汾  
//////////////////////////////////////////////////////////////////////////

#pragma once

#include <Windows.h>

#ifdef WARNINGDLL_EXPORTS
#define WARNING_DLL_API __declspec(dllexport)
#else
#define WARNING_DLL_API __declspec(dllimport)
#endif

#define  EXTERN_C    extern "C"

#include "windef.h"  
///--------------------�����������ģ��------------------------

/// ���ܣ���ʼ������ģ��
/// 
/// @param[in]	��
/// @param[out]	��
/// @return 0: �����ɹ�
/// @return -1: ����ʧ��  ԭ�򴴽������ڴ�ʧ��
/// 
/// \code
/// �μ��ӿڣ�GTC_UpdateWarningInfo();
///\endcode
EXTERN_C WARNING_DLL_API short	 GTC_InitWarningModule();  //��ʼ������ģ��

/// ���ܣ���λ��������
/// 
/// @param[in]	��
/// @param[out]	��
/// @return 0: �����ɹ�
/// @return -1: ����ʧ��  ԭ��û�г�ʼ������ģ��
/// 
/// \code
/// �μ��ӿڣ�GTC_UpdateWarningInfo();
///\endcode
EXTERN_C WARNING_DLL_API short	 GTC_ResetWarningData();

/// ���ܣ����±����ļ���Ϣ
/// @param[in]  <char *sFilePath>:������Ϣ�ļ�·��
/// @param[out]  ��
/// @return 0:  ���³ɹ�
/// @return -1:   ���ر����ļ�ʧ��
/// \code
/// ����ģ���ʼʱ�����£�
/// short rtn;
/// rtn = GTC_InitWarningModule();
/// rtn = GTC_ResetWarningData();
/// rtn = GTC_UpdateWarningInfo("\\Hard Disk\\CNC_Punch\\NcConfig\\Error_chn.ini");
/// \endcode
EXTERN_C WARNING_DLL_API short   GTC_UpdateWarningInfo(char *sFilePath);


/// ���ܣ��������
/// 
/// @param[in]  <long WarningNo>: �����ţ�ȡֵ��Χ1-9999
/// @param[in]  <long Param1 = 0>: ��������������Ĭ��0������������
/// @param[in]  <long Param2 = 0>: ��������������Ĭ��0������������ļ���
/// @param[in]  <long Param3 = 0>: ��������������Ĭ��0������������к�
/// @param[in]  <LPCWSTR sParam>;  ����������Ϣ���ַ�����Ĭ��Ϊ�գ����127�ַ��������ĺ�����
/// @param[out]	��
/// @return: <0>�ɹ� <-1>ģ��δ��ʼ�� <7>������������磬�����ų���ȡֵ��Χ��
/// 
/// \code
/// short rtn = GTC_HandleWarning(1234,1,2,3,4);
///\endcode
EXTERN_C WARNING_DLL_API short   GTC_HandleWarning(long WarningNo, long Param1 = 0, long Param2 = 0,long Param3 = 0,LPCWSTR sParam=L"");

/// ���ܣ����ָ������
/// 
/// @param[in]  <long WarningNo>: �����ţ�ȡֵ��Χ1-9999
/// @param[out]	��
/// @return: <0>�ɹ� <-1>ģ��δ��ʼ�� <7>�����������
/// 
/// \code
/// short rtn = GTC_ClearWarning(1234);
///\endcode
EXTERN_C WARNING_DLL_API short   GTC_ClearWarning(long WarningNo);

/// ���ܣ�������б���
/// @param[in]  ��
/// @param[out]	��
/// @return 0: �ɹ�
/// 
/// \code
/// short rtn = GTC_ClearAllWarning();
///\endcode
EXTERN_C WARNING_DLL_API short   GTC_ClearAllWarning();

/// ���ܣ��������[C]���ͱ���,[M]���Ͳ����
/// @param[in]  ��
/// @param[out]	��
/// @return 0: �ɹ�
/// 
/// \code
/// short rtn = GTC_SelectClearWarning();
///\endcode
EXTERN_C WARNING_DLL_API short    GTC_SelectClearWarning();



/// ���ܣ���ȡ�����Ŵ���WarningNo����С����
/// @param[inout]  <long &WarningNo>: 
///						����: �����ţ�
///						��������صĴ���WarningNo����С�����ţ�0��ʾ�ޱ���,1-9999����
/// @param[out]  <long &Param1>: ���������������
/// @param[out]  <long &Param2>: ���������������
/// @param[out]  <long &Param3>: ���������������
/// @return 0: �ɹ�
/// 
/// \code
/// //��ȡ��ǰ���б�����Ϣ
/// WCHAR almTxt[256];
/// long lWarningParam1 = 0;
/// long lWarningParam2 = 0;
/// long lWarningParam3 = 0;
/// long lWarningNo = 0;
/// GTC_GetWarning(lWarningNo,lWarningParam1,lWarningParam2,lWarningParam3);

/// while(lWarningNo>0)
/// {
/// 	GTC_GetWarningInfoW(almTxt,256,lWarningNo,lWarningParam1,lWarningParam2,lWarningParam3);
/// 	GTC_GetWarning(lWarningNo,lWarningParam1,lWarningParam2,lWarningParam3);
/// }
///\endcode
EXTERN_C WARNING_DLL_API short GTC_GetWarning(long &WarningNo,long &Param1,long &Param2,long &Param3);


/// ���ܣ���ȡָ�������ı�����Ϣ
/// 
/// @param[out]  <char *WarningInfo>: ���������Ϣ(�뱣ָ֤�루*WarningInfo����Ч���ҷ���Ŀռ��㹻)
/// @param[out]  <WCHAR *WarningInfo>: ���������Ϣ(�뱣ָ֤�루*WarningInfo����Ч���ҷ���Ŀռ��㹻)
/// @param[in]  <int infoSize>: ������Ϣ(WarningInfo)ʵ�ʷ���Ŀռ��С,��Χ>20
/// @param[in]  <long WarningNo>: ������
/// @param[in]  <long WarningParam1>: ������������
/// @param[in]  <long WarningParam2>: ������������
/// @param[in]  <long WarningParam3>: ������������
/// @param[in]  <bool bShowNo>: ����ı�����Ϣ�����Ƿ����������

/// @return 0: �ɹ�	,��������	
/// 
/// \code
/// �μ�GTC_GetWarning()
///\endcode
EXTERN_C WARNING_DLL_API short  GTC_GetWarningInfo(char *WarningInfo,int infoSize,long WarningNo,long WarningParam1=0,long WarningParam2=0,long WarningParam3=0,bool bShowNo=false);
EXTERN_C WARNING_DLL_API short  GTC_GetWarningInfoW(WCHAR *WarningInfo,int infoSize,long WarningNo,long WarningParam1=0,long WarningParam2=0,long WarningParam3=0,bool bShowNo=false);


/// ���ܣ�׼����ʼ��ȡ������־
/// @param[in]  ��
/// @param[out]	��
/// @return :  ʣ��δ��������־����
/// 
/// \code
/// short rtn = GTC_BeginWarningLog();
/// \endcode
EXTERN_C WARNING_DLL_API short   GTC_BeginWarningLog();

/// ���ܣ���ȡ������־��Ϣ����ɾ���Ѷ�ȡ�ı�����־��Ϣ
/// 
/// @param[out]  <char *WarningInfo>: ���������Ϣ(�뱣ָ֤�루*WarningInfo����Ч���ҷ���Ŀռ��㹻)
/// @param[out]  <WCHAR *WarningInfo>: ���������Ϣ(�뱣ָ֤�루*WarningInfo����Ч���ҷ���Ŀռ��㹻)
/// @param[in]  <int infoSize>: ������Ϣ(WarningInfo)ʵ�ʷ���Ŀռ��С,��Χ>20
/// @param[out]  <long WarningNo>: ���������
/// @param[out]  <long WarningParam1>: ���������������
/// @param[out]  <long WarningParam2>: ���������������
/// @param[out]  <long WarningParam3>: ���������������
/// @param[out]  <bool bShowNo>: ����ı�����Ϣ�����Ƿ����������
///
/// @return 0:  ����δ��������־
/// @return -1:  û��δ��������־
/// 
/// \code
/// ��ȡ������־
/// WCHAR almTxt[256];
/// short hasWarningForLog = 0;
/// long lWarningParam1 = 0;
/// long lWarningParam2 = 0;
/// long lWarningParam3 = 0;
/// long lWarningNo = 0;
/// short iLeftLog = GTC_BeginWarningLog();

/// while(0==hasWarningForLog && iLeftLog>0)
/// {
/// 	hasWarningForLog = GTC_PopWarningLogW(almTxt,256,lWarningNo,lWarningParam1,lWarningParam2,lWarningParam3);
/// 	if (0==hasWarningForLog && lWarningNo>0 && lWarningNo<10000)
/// 	{
/// 		;//��ʾ����¼������־��ʡ��......,�û����濪���Դ���;	
/// 	}
/// }
/// \endcode
EXTERN_C WARNING_DLL_API short  GTC_PopWarningLog(char *WarningInfo,int infoSize,long &WarningNo,long &WarningParam1,long&WarningParam2,long&WarningParam3,bool bShowNo=false);
EXTERN_C WARNING_DLL_API short  GTC_PopWarningLogW(WCHAR *WarningInfo,int infoSize,long &WarningNo,long &WarningParam1,long&WarningParam2,long&WarningParam3,bool bShowNo=false);






///��־����ӿ�///////////////////////////////////////////////////////////////////////

/// ���ܣ���ʼ����־ģ��
/// @return: <0> �ɹ�
EXTERN_C WARNING_DLL_API short GTC_InitLogModule();  

/// ���ܣ���¼��־��Ϣ
/// @param[in]  <char *logInfo>: �������־��Ϣ(�뱣ָ֤�루logInfo����Ч��
/// @return: <0> �ɹ�  <-1>δ��ʼ��  <-2>�������� 
EXTERN_C WARNING_DLL_API short GTC_RecLogInfo(char *logInfo);

/// ���ܣ���ȡ��־��Ϣ��ɾ���Ѷ�ȡ����־��Ϣ
/// @param[inout]  <char *logInfo>: �����־��Ϣ(�뱣ָ֤�루logInfo����Ч���ҷ���Ŀռ��㹻����512��)
/// @param[in]  <int infoSize>: ��־��Ϣ(logInfo)ʵ�ʷ���Ŀռ��С����Χ��512��Ĭ��512
/// @return: <0> ��ȡ��Ϣ�ɹ�  <-1>δ��ʼ��������Ϣ  <-2>�������� 

/// \code
/// 	char logInfo[512];
/// 	if (0==GTC_GetLogInfoAndRemove(logInfo))
/// 	{
/// 		;//��־��Ϣ��Ч��������ϢlogInfo ���磺��ʾ��д����־�ļ���
/// 	}
/// \endcode
EXTERN_C WARNING_DLL_API short GTC_GetLogInfoAndRemove(char *logInfo,int infoSize=512);






//������Ϣ//////////////////////////////////////////////////////////////////////////

/// ���ܣ���ʼ��������Ϣģ��
/// @param[in]  <unsigned short nSize>: ���õ�����Ϣ��¼��������������1000��
/// @return: <0> �ɹ���<����>ʧ��
EXTERN_C WARNING_DLL_API short   GTC_InitDebugMsg(unsigned short nSize = 500);

/// ���ܣ��Ƿ���������Ϣ��¼����
/// @param[in]  <bool bEnable>: false����¼������Ϣ��true��¼������Ϣ
/// @return: ��
EXTERN_C WARNING_DLL_API void   GTC_EnableDebugCtrl(bool bEnable=true);

/// ���ܣ���¼������Ϣ
/// @param[in]  <char *cInfo>: ����ĵ�����Ϣ(�뱣ָ֤�루cInfo����Ч��
/// @return: <0> ��¼��Ϣ�ɹ� <-1>δ��ʼ����δʹ��
EXTERN_C WARNING_DLL_API short   GTC_RecDebugMsg(char *cInfo, double lval1=0, double lval2=0, double lval3=0);

/// ���ܣ���ȡ������Ϣ��ɾ���Ѷ�ȡ�ĵ�����Ϣ
/// @param[inout]  <char *cInfo>: ����ĵ�����Ϣ(�뱣ָ֤�루cInfo����Ч���ҷ���Ŀռ��㹻����512��)
/// @return: <0> ��ȡ��Ϣ�ɹ� <-1>δʹ�ܻ�����Ϣ
EXTERN_C WARNING_DLL_API short   GTC_GetDebugMsgAndRemove(char *cInfo, double &lval1, double &lval2, double &lval3, long &lTime);

//////////////////////////////////////////////////////////////////////////

/// ��ȡ��ı���ʱ��
/// @param[inout]  <pData>:��ı���ʱ�䣬�����û�Ԥ��256���ֽڵ��ַ��ռ�
/// @return   0: ����, ����:ʧ��
EXTERN_C WARNING_DLL_API short GTC_GetWarningDllCompData(char* pData);




//////////////////////////////////////////
/// ���ܣ�����Զ��屨����Ϣ������Ҫ�����ļ����ã�20191212 chenjc
/// 
/// @param[in]  <WarningNo>:	�����ţ�ȡֵ��Χ1-9999
/// @param[in]  <sAlmInfo>;	�Զ��屨����Ϣ���ַ��������127�ַ���
/// @param[in]  <bRstClear>:	�ñ����Ƿ�ɸ�λ�����true�����;false���������Ĭ��Ϊtrue��;
///									�������ļ��������˸ñ���<WarningNo>ʱ������<bRstClear>��Ч���Ƿ�ɸ�λ������������ļ��е����þ�����	
/// @return: <0>�ɹ� <-1>ģ��δ��ʼ�� <7>������������磬�����ų���ȡֵ��Χ��
/// 
/// \code
/// short rtn = GTC_HandleWarningUser(1234,_T("[P]�Զ��屨����Ϣ"));
///\endcode
EXTERN_C WARNING_DLL_API short  GTC_HandleWarningUser(long WarningNo, char *sAlmInfo, bool bRstClear=true);
EXTERN_C WARNING_DLL_API short  GTC_HandleWarningUserW(long WarningNo, WCHAR *sAlmInfo, bool bRstClear=true);

//��ȡ��ǰָ����Χ����С����󱨾���
EXTERN_C WARNING_DLL_API bool GTC_GetWarningRange(long &MinWarningNo,long &MaxWarningNo);