/////////////////////////////////////////////////////////////////////////  
/// COPYRIGHT NOTICE  
/// Copyright (c) 2016,  （版权声明）  
/// All rights reserved.  
///  
/// @file          WarningDll.h  
/// @brief         报警警告管理模块  &&   当前日志记录管理模块
///    
///  
/// @version 1.0        
/// @author        卜平 
/// @date          2016年6月6日 
///   
/// 修订说明：最初版本  
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
///--------------------报警警告管理模块------------------------

/// 功能：初始化报警模块
/// 
/// @param[in]	无
/// @param[out]	无
/// @return 0: 创建成功
/// @return -1: 创建失败  原因创建共享内存失败
/// 
/// \code
/// 参见接口：GTC_UpdateWarningInfo();
///\endcode
EXTERN_C WARNING_DLL_API short	 GTC_InitWarningModule();  //初始化报警模块

/// 功能：复位报警数据
/// 
/// @param[in]	无
/// @param[out]	无
/// @return 0: 创建成功
/// @return -1: 创建失败  原因没有初始化报警模块
/// 
/// \code
/// 参见接口：GTC_UpdateWarningInfo();
///\endcode
EXTERN_C WARNING_DLL_API short	 GTC_ResetWarningData();

/// 功能：更新报警文件信息
/// @param[in]  <char *sFilePath>:报警信息文件路径
/// @param[out]  无
/// @return 0:  更新成功
/// @return -1:   加载报警文件失败
/// \code
/// 报警模块初始时序如下：
/// short rtn;
/// rtn = GTC_InitWarningModule();
/// rtn = GTC_ResetWarningData();
/// rtn = GTC_UpdateWarningInfo("\\Hard Disk\\CNC_Punch\\NcConfig\\Error_chn.ini");
/// \endcode
EXTERN_C WARNING_DLL_API short   GTC_UpdateWarningInfo(char *sFilePath);


/// 功能：输出报警
/// 
/// @param[in]  <long WarningNo>: 报警号，取值范围1-9999
/// @param[in]  <long Param1 = 0>: 报警附带参数，默认0，如译码错误号
/// @param[in]  <long Param2 = 0>: 报警附带参数，默认0，如译码错误文件号
/// @param[in]  <long Param3 = 0>: 报警附带参数，默认0，如译码错误行号
/// @param[in]  <LPCWSTR sParam>;  报警附加信息，字符串，默认为空，最多127字符，如出错的函数名
/// @param[out]	无
/// @return: <0>成功 <-1>模块未初始化 <7>输入参数错误（如，报警号超出取值范围）
/// 
/// \code
/// short rtn = GTC_HandleWarning(1234,1,2,3,4);
///\endcode
EXTERN_C WARNING_DLL_API short   GTC_HandleWarning(long WarningNo, long Param1 = 0, long Param2 = 0,long Param3 = 0,LPCWSTR sParam=L"");

/// 功能：清除指定报警
/// 
/// @param[in]  <long WarningNo>: 报警号，取值范围1-9999
/// @param[out]	无
/// @return: <0>成功 <-1>模块未初始化 <7>输入参数错误
/// 
/// \code
/// short rtn = GTC_ClearWarning(1234);
///\endcode
EXTERN_C WARNING_DLL_API short   GTC_ClearWarning(long WarningNo);

/// 功能：清除所有报警
/// @param[in]  无
/// @param[out]	无
/// @return 0: 成功
/// 
/// \code
/// short rtn = GTC_ClearAllWarning();
///\endcode
EXTERN_C WARNING_DLL_API short   GTC_ClearAllWarning();

/// 功能：清除所有[C]类型报警,[M]类型不清除
/// @param[in]  无
/// @param[out]	无
/// @return 0: 成功
/// 
/// \code
/// short rtn = GTC_SelectClearWarning();
///\endcode
EXTERN_C WARNING_DLL_API short    GTC_SelectClearWarning();



/// 功能：获取报警号大于WarningNo的最小报警
/// @param[inout]  <long &WarningNo>: 
///						输入: 报警号；
///						输出：返回的大于WarningNo的最小报警号，0表示无报警,1-9999报警
/// @param[out]  <long &Param1>: 输出报警附带参数
/// @param[out]  <long &Param2>: 输出报警附带参数
/// @param[out]  <long &Param3>: 输出报警附带参数
/// @return 0: 成功
/// 
/// \code
/// //读取当前所有报警信息
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


/// 功能：读取指定报警的报警信息
/// 
/// @param[out]  <char *WarningInfo>: 输出报警信息(请保证指针（*WarningInfo）有效，且分配的空间足够)
/// @param[out]  <WCHAR *WarningInfo>: 输出报警信息(请保证指针（*WarningInfo）有效，且分配的空间足够)
/// @param[in]  <int infoSize>: 报警信息(WarningInfo)实际分配的空间大小,范围>20
/// @param[in]  <long WarningNo>: 报警号
/// @param[in]  <long WarningParam1>: 报警附带参数
/// @param[in]  <long WarningParam2>: 报警附带参数
/// @param[in]  <long WarningParam3>: 报警附带参数
/// @param[in]  <bool bShowNo>: 输出的报警信息报警是否包含报警号

/// @return 0: 成功	,其他错误	
/// 
/// \code
/// 参见GTC_GetWarning()
///\endcode
EXTERN_C WARNING_DLL_API short  GTC_GetWarningInfo(char *WarningInfo,int infoSize,long WarningNo,long WarningParam1=0,long WarningParam2=0,long WarningParam3=0,bool bShowNo=false);
EXTERN_C WARNING_DLL_API short  GTC_GetWarningInfoW(WCHAR *WarningInfo,int infoSize,long WarningNo,long WarningParam1=0,long WarningParam2=0,long WarningParam3=0,bool bShowNo=false);


/// 功能：准备开始读取报警日志
/// @param[in]  无
/// @param[out]	无
/// @return :  剩余未处理报警日志数量
/// 
/// \code
/// short rtn = GTC_BeginWarningLog();
/// \endcode
EXTERN_C WARNING_DLL_API short   GTC_BeginWarningLog();

/// 功能：读取报警日志信息，并删除已读取的报警日志信息
/// 
/// @param[out]  <char *WarningInfo>: 输出报警信息(请保证指针（*WarningInfo）有效，且分配的空间足够)
/// @param[out]  <WCHAR *WarningInfo>: 输出报警信息(请保证指针（*WarningInfo）有效，且分配的空间足够)
/// @param[in]  <int infoSize>: 报警信息(WarningInfo)实际分配的空间大小,范围>20
/// @param[out]  <long WarningNo>: 输出报警号
/// @param[out]  <long WarningParam1>: 输出报警附带参数
/// @param[out]  <long WarningParam2>: 输出报警附带参数
/// @param[out]  <long WarningParam3>: 输出报警附带参数
/// @param[out]  <bool bShowNo>: 输出的报警信息报警是否包含报警号
///
/// @return 0:  还有未处理报警日志
/// @return -1:  没有未处理报警日志
/// 
/// \code
/// 读取报警日志
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
/// 		;//显示并记录报警日志（省略......,用户界面开发自处理）;	
/// 	}
/// }
/// \endcode
EXTERN_C WARNING_DLL_API short  GTC_PopWarningLog(char *WarningInfo,int infoSize,long &WarningNo,long &WarningParam1,long&WarningParam2,long&WarningParam3,bool bShowNo=false);
EXTERN_C WARNING_DLL_API short  GTC_PopWarningLogW(WCHAR *WarningInfo,int infoSize,long &WarningNo,long &WarningParam1,long&WarningParam2,long&WarningParam3,bool bShowNo=false);






///日志管理接口///////////////////////////////////////////////////////////////////////

/// 功能：初始化日志模块
/// @return: <0> 成功
EXTERN_C WARNING_DLL_API short GTC_InitLogModule();  

/// 功能：记录日志信息
/// @param[in]  <char *logInfo>: 输入的日志信息(请保证指针（logInfo）有效）
/// @return: <0> 成功  <-1>未初始化  <-2>参数错误 
EXTERN_C WARNING_DLL_API short GTC_RecLogInfo(char *logInfo);

/// 功能：读取日志信息并删除已读取的日志信息
/// @param[inout]  <char *logInfo>: 输出日志信息(请保证指针（logInfo）有效，且分配的空间足够（≥512）)
/// @param[in]  <int infoSize>: 日志信息(logInfo)实际分配的空间大小。范围≥512，默认512
/// @return: <0> 读取信息成功  <-1>未初始化或无信息  <-2>参数错误 

/// \code
/// 	char logInfo[512];
/// 	if (0==GTC_GetLogInfoAndRemove(logInfo))
/// 	{
/// 		;//日志信息有效：处理信息logInfo （如：显示并写入日志文件）
/// 	}
/// \endcode
EXTERN_C WARNING_DLL_API short GTC_GetLogInfoAndRemove(char *logInfo,int infoSize=512);






//调试信息//////////////////////////////////////////////////////////////////////////

/// 功能：初始化调试信息模块
/// @param[in]  <unsigned short nSize>: 设置调试信息记录的容量，不超过1000条
/// @return: <0> 成功，<其他>失败
EXTERN_C WARNING_DLL_API short   GTC_InitDebugMsg(unsigned short nSize = 500);

/// 功能：是否开启调试信息记录功能
/// @param[in]  <bool bEnable>: false不记录调试信息，true记录调试信息
/// @return: 无
EXTERN_C WARNING_DLL_API void   GTC_EnableDebugCtrl(bool bEnable=true);

/// 功能：记录调试信息
/// @param[in]  <char *cInfo>: 输入的调试信息(请保证指针（cInfo）有效）
/// @return: <0> 记录信息成功 <-1>未初始化或未使能
EXTERN_C WARNING_DLL_API short   GTC_RecDebugMsg(char *cInfo, double lval1=0, double lval2=0, double lval3=0);

/// 功能：获取调试信息并删除已读取的调试信息
/// @param[inout]  <char *cInfo>: 输出的调试信息(请保证指针（cInfo）有效，且分配的空间足够（≥512）)
/// @return: <0> 读取信息成功 <-1>未使能或无信息
EXTERN_C WARNING_DLL_API short   GTC_GetDebugMsgAndRemove(char *cInfo, double &lval1, double &lval2, double &lval3, long &lTime);

//////////////////////////////////////////////////////////////////////////

/// 获取库的编译时间
/// @param[inout]  <pData>:库的编译时间，建议用户预留256个字节的字符空间
/// @return   0: 正常, 其它:失败
EXTERN_C WARNING_DLL_API short GTC_GetWarningDllCompData(char* pData);




//////////////////////////////////////////
/// 功能：输出自定义报警信息（不需要配置文件配置）20191212 chenjc
/// 
/// @param[in]  <WarningNo>:	报警号，取值范围1-9999
/// @param[in]  <sAlmInfo>;	自定义报警信息，字符串，最多127字符。
/// @param[in]  <bRstClear>:	该报警是否可复位清除（true可清除;false不可清除。默认为true）;
///									当配置文件中配置了该报警<WarningNo>时：参数<bRstClear>无效；是否可复位清除，由配置文件中的配置决定。	
/// @return: <0>成功 <-1>模块未初始化 <7>输入参数错误（如，报警号超出取值范围）
/// 
/// \code
/// short rtn = GTC_HandleWarningUser(1234,_T("[P]自定义报警信息"));
///\endcode
EXTERN_C WARNING_DLL_API short  GTC_HandleWarningUser(long WarningNo, char *sAlmInfo, bool bRstClear=true);
EXTERN_C WARNING_DLL_API short  GTC_HandleWarningUserW(long WarningNo, WCHAR *sAlmInfo, bool bRstClear=true);

//获取当前指定范围的最小、最大报警号
EXTERN_C WARNING_DLL_API bool GTC_GetWarningRange(long &MinWarningNo,long &MaxWarningNo);