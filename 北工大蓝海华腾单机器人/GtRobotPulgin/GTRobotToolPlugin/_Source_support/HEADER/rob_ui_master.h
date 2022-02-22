#ifndef ROBUIMASTER_H
#define ROBUIMASTER_H

#include <QWidget>
#include "../frontend/gtrobot_frontend_interface.h"

#ifdef ROBUI_LIB
# define ROBUI_EXPORT extern "C" __declspec(dllexport) //Q_DECL_EXPORT
#else
# define ROBUI_EXPORT extern "C" __declspec(dllimport) //Q_DECL_IMPORT
#endif


//兼容v0.6.0以前的版本
ROBUI_EXPORT FrameInterface* GetInsatnce(QWidget * object = 0);

//v0.6.0新特性接口
ROBUI_EXPORT FrameInterface* GetSysInsatnce(QWidget * object = 0);

//初始化机器人系统
ROBUI_EXPORT bool InitRobotSystem();


ROBUI_EXPORT short GetSysLanguageType();

#endif // ROBUIMASTER_H
