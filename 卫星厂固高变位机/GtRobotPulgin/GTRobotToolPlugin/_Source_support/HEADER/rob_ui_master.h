#ifndef ROBUIMASTER_H
#define ROBUIMASTER_H

#include <QWidget>
#include "../frontend/gtrobot_frontend_interface.h"

#ifdef ROBUI_LIB
# define ROBUI_EXPORT extern "C" __declspec(dllexport) //Q_DECL_EXPORT
#else
# define ROBUI_EXPORT extern "C" __declspec(dllimport) //Q_DECL_IMPORT
#endif


//����v0.6.0��ǰ�İ汾
ROBUI_EXPORT FrameInterface* GetInsatnce(QWidget * object = 0);

//v0.6.0�����Խӿ�
ROBUI_EXPORT FrameInterface* GetSysInsatnce(QWidget * object = 0);

//��ʼ��������ϵͳ
ROBUI_EXPORT bool InitRobotSystem();


ROBUI_EXPORT short GetSysLanguageType();

#endif // ROBUIMASTER_H
