#pragma once

#ifndef SHAREMEMORYDLL_H
#define SHAREMEMORYDLL_H

#ifdef SHAREMEMORYDLL_LIB
# define ShareMemoryApi extern "C" __declspec(dllexport) 
#else
# define ShareMemoryApi extern "C" __declspec(dllimport)	
#endif

#include "ShareMemoryParaDef.h"

namespace ShareMemory
{
	ShareMemoryApi AxisConfig  * GetAxisConfig(int id = 0);
	ShareMemoryApi SystemConfig * GetSystemConfig();
	ShareMemoryApi GroupConfig * GetGroupConfig(int group = 0);
	ShareMemoryApi MotionOutput * GetMotionOutput();
	ShareMemoryApi PlcInterface * GetPlcInterface();
	ShareMemoryApi PublicVariable * GetPublicVariable();
	ShareMemoryApi WatchConfig * GetWatchConfig();
	ShareMemoryApi HmiParam * GetHmiParam();	
	ShareMemoryApi UserParam * GetUserParam();
	ShareMemoryApi void ReleaseMemory();
}

#endif // SHAREMEMORYDLL_H
