/********************************************************************************
** Form generated from reading UI file 'fsw.ui'
**
** Created: Thu Feb 24 21:42:25 2022
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSW_H
#define UI_FSW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FSWClass
{
public:
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *mlabel1;
    QLabel *mlabel_sri_status_connect;
    QLabel *label_6;
    QLabel *mlabel_spindle_status;
    QFrame *line_3;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QLCDNumber *mlcdnumber_spindle_set;
    QLabel *label_7;
    QLCDNumber *mlcdnumber_spindle_real;
    QLabel *label_2;
    QLCDNumber *mlcdnumber_sri_fzsetting;
    QLabel *label_25;
    QLCDNumber *mlcdnumber_sri_Fz;
    QFrame *line_2;
    QGridLayout *gridLayout_4;
    QLabel *label_18;
    QLCDNumber *lcdnumber_rsi_dy;
    QLabel *label_21;
    QLCDNumber *lcdnumber_rsi_dz;
    QLabel *label_10;
    QLCDNumber *mlcdnumber_rsi_man_sum_y;
    QLabel *label_9;
    QLCDNumber *mlcdnumber_rsi_man_sum_z;
    QLabel *label_42;
    QLCDNumber *mlcdnumber_sri_correct_sum_z;
    QFrame *line_10;
    QLabel *label_19;
    QLCDNumber *mlcdnumber_rsi_man_step;
    QFrame *line_11;
    QGridLayout *gridLayout_6;
    QCheckBox *mcheckbox_sri_connect;
    QCheckBox *mcheckbox_sri_status_on;
    QCheckBox *mcheckbox_sri_status_off;
    QCheckBox *mcheckbox_sri_ask;
    QCheckBox *mcheckbox_sri_disconnect;
    QCheckBox *mcheckbox_sri_stop;
    QFrame *line_6;
    QCheckBox *checkbox_rsi_on;
    QCheckBox *checkbox_rsi_off;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QPushButton *mpushbutton_rsi_man_y_down;
    QPushButton *mpushbutton_rsi_man_y_up;
    QPushButton *mpushbutton_sri_zero;
    QPushButton *mpushbutton_rsi_man_z_up;
    QPushButton *mpushbutton_rsi_man_z_down;
    QPushButton *mpushbutton_spindle_on;
    QPushButton *mpushbutton_spindle_off;
    QPushButton *mpushbutton_spindle_speed_down100;
    QPushButton *mpushbutton_spindle_speed_up100;
    QPushButton *mpushbutton_rsi_man_step_down;
    QPushButton *mpushbutton_rsi_man_step_up;
    QPushButton *mpushbutton_sri_fzsetting_down;
    QPushButton *mpushbutton_sri_fzsetting_up;
    QPushButton *pbSpindleConnect;

    void setupUi(QWidget *FSWClass)
    {
        if (FSWClass->objectName().isEmpty())
            FSWClass->setObjectName(QString::fromUtf8("FSWClass"));
        FSWClass->resize(690, 390);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FSWClass->sizePolicy().hasHeightForWidth());
        FSWClass->setSizePolicy(sizePolicy);
        FSWClass->setMinimumSize(QSize(690, 390));
        FSWClass->setContextMenuPolicy(Qt::ActionsContextMenu);
        FSWClass->setAutoFillBackground(false);
        gridLayout_7 = new QGridLayout(FSWClass);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mlabel1 = new QLabel(FSWClass);
        mlabel1->setObjectName(QString::fromUtf8("mlabel1"));
        QFont font;
        font.setPointSize(15);
        mlabel1->setFont(font);

        gridLayout->addWidget(mlabel1, 0, 2, 1, 1);

        mlabel_sri_status_connect = new QLabel(FSWClass);
        mlabel_sri_status_connect->setObjectName(QString::fromUtf8("mlabel_sri_status_connect"));
        mlabel_sri_status_connect->setFont(font);

        gridLayout->addWidget(mlabel_sri_status_connect, 0, 3, 1, 1);

        label_6 = new QLabel(FSWClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        mlabel_spindle_status = new QLabel(FSWClass);
        mlabel_spindle_status->setObjectName(QString::fromUtf8("mlabel_spindle_status"));
        mlabel_spindle_status->setFont(font);

        gridLayout->addWidget(mlabel_spindle_status, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line_3 = new QFrame(FSWClass);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_8 = new QLabel(FSWClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setPointSize(12);
        label_8->setFont(font1);

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        mlcdnumber_spindle_set = new QLCDNumber(FSWClass);
        mlcdnumber_spindle_set->setObjectName(QString::fromUtf8("mlcdnumber_spindle_set"));
        mlcdnumber_spindle_set->setFont(font1);
        mlcdnumber_spindle_set->setProperty("value", QVariant(0));
        mlcdnumber_spindle_set->setProperty("intValue", QVariant(0));

        gridLayout_5->addWidget(mlcdnumber_spindle_set, 0, 1, 1, 1);

        label_7 = new QLabel(FSWClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        mlcdnumber_spindle_real = new QLCDNumber(FSWClass);
        mlcdnumber_spindle_real->setObjectName(QString::fromUtf8("mlcdnumber_spindle_real"));
        mlcdnumber_spindle_real->setFont(font1);
        mlcdnumber_spindle_real->setSmallDecimalPoint(false);
        mlcdnumber_spindle_real->setProperty("value", QVariant(0));

        gridLayout_5->addWidget(mlcdnumber_spindle_real, 1, 1, 1, 1);

        label_2 = new QLabel(FSWClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setFont(font1);

        gridLayout_5->addWidget(label_2, 0, 2, 1, 1);

        mlcdnumber_sri_fzsetting = new QLCDNumber(FSWClass);
        mlcdnumber_sri_fzsetting->setObjectName(QString::fromUtf8("mlcdnumber_sri_fzsetting"));
        mlcdnumber_sri_fzsetting->setEnabled(true);
        mlcdnumber_sri_fzsetting->setFont(font1);
        mlcdnumber_sri_fzsetting->setProperty("value", QVariant(4500));
        mlcdnumber_sri_fzsetting->setProperty("intValue", QVariant(4500));

        gridLayout_5->addWidget(mlcdnumber_sri_fzsetting, 0, 3, 1, 1);

        label_25 = new QLabel(FSWClass);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font1);

        gridLayout_5->addWidget(label_25, 1, 2, 1, 1);

        mlcdnumber_sri_Fz = new QLCDNumber(FSWClass);
        mlcdnumber_sri_Fz->setObjectName(QString::fromUtf8("mlcdnumber_sri_Fz"));
        mlcdnumber_sri_Fz->setEnabled(true);
        mlcdnumber_sri_Fz->setMinimumSize(QSize(0, 22));
        mlcdnumber_sri_Fz->setFont(font1);

        gridLayout_5->addWidget(mlcdnumber_sri_Fz, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        line_2 = new QFrame(FSWClass);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_18 = new QLabel(FSWClass);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setEnabled(true);
        label_18->setFont(font1);

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        lcdnumber_rsi_dy = new QLCDNumber(FSWClass);
        lcdnumber_rsi_dy->setObjectName(QString::fromUtf8("lcdnumber_rsi_dy"));
        lcdnumber_rsi_dy->setEnabled(true);
        lcdnumber_rsi_dy->setMinimumSize(QSize(0, 36));
        lcdnumber_rsi_dy->setMaximumSize(QSize(16777215, 36));
        lcdnumber_rsi_dy->setFont(font1);

        gridLayout_4->addWidget(lcdnumber_rsi_dy, 0, 1, 1, 1);

        label_21 = new QLabel(FSWClass);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);

        gridLayout_4->addWidget(label_21, 0, 3, 1, 1);

        lcdnumber_rsi_dz = new QLCDNumber(FSWClass);
        lcdnumber_rsi_dz->setObjectName(QString::fromUtf8("lcdnumber_rsi_dz"));
        lcdnumber_rsi_dz->setMinimumSize(QSize(0, 36));
        lcdnumber_rsi_dz->setMaximumSize(QSize(16777215, 36));
        lcdnumber_rsi_dz->setFont(font1);

        gridLayout_4->addWidget(lcdnumber_rsi_dz, 0, 4, 1, 1);

        label_10 = new QLabel(FSWClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        mlcdnumber_rsi_man_sum_y = new QLCDNumber(FSWClass);
        mlcdnumber_rsi_man_sum_y->setObjectName(QString::fromUtf8("mlcdnumber_rsi_man_sum_y"));
        mlcdnumber_rsi_man_sum_y->setMinimumSize(QSize(0, 36));
        mlcdnumber_rsi_man_sum_y->setMaximumSize(QSize(16777215, 36));
        mlcdnumber_rsi_man_sum_y->setFont(font1);

        gridLayout_4->addWidget(mlcdnumber_rsi_man_sum_y, 1, 1, 1, 1);

        label_9 = new QLabel(FSWClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        gridLayout_4->addWidget(label_9, 1, 3, 1, 1);

        mlcdnumber_rsi_man_sum_z = new QLCDNumber(FSWClass);
        mlcdnumber_rsi_man_sum_z->setObjectName(QString::fromUtf8("mlcdnumber_rsi_man_sum_z"));
        mlcdnumber_rsi_man_sum_z->setMinimumSize(QSize(0, 36));
        mlcdnumber_rsi_man_sum_z->setMaximumSize(QSize(16777215, 36));
        mlcdnumber_rsi_man_sum_z->setFont(font1);
        mlcdnumber_rsi_man_sum_z->setSmallDecimalPoint(false);
        mlcdnumber_rsi_man_sum_z->setProperty("value", QVariant(0));

        gridLayout_4->addWidget(mlcdnumber_rsi_man_sum_z, 1, 4, 1, 1);

        label_42 = new QLabel(FSWClass);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font1);

        gridLayout_4->addWidget(label_42, 2, 3, 1, 1);

        mlcdnumber_sri_correct_sum_z = new QLCDNumber(FSWClass);
        mlcdnumber_sri_correct_sum_z->setObjectName(QString::fromUtf8("mlcdnumber_sri_correct_sum_z"));
        mlcdnumber_sri_correct_sum_z->setEnabled(true);
        mlcdnumber_sri_correct_sum_z->setMinimumSize(QSize(0, 24));
        mlcdnumber_sri_correct_sum_z->setMaximumSize(QSize(16777215, 36));
        mlcdnumber_sri_correct_sum_z->setFont(font1);

        gridLayout_4->addWidget(mlcdnumber_sri_correct_sum_z, 2, 4, 1, 1);

        line_10 = new QFrame(FSWClass);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_10, 0, 2, 3, 1);

        label_19 = new QLabel(FSWClass);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);

        gridLayout_4->addWidget(label_19, 2, 0, 1, 1);

        mlcdnumber_rsi_man_step = new QLCDNumber(FSWClass);
        mlcdnumber_rsi_man_step->setObjectName(QString::fromUtf8("mlcdnumber_rsi_man_step"));
        mlcdnumber_rsi_man_step->setMinimumSize(QSize(0, 36));
        mlcdnumber_rsi_man_step->setMaximumSize(QSize(16777215, 36));
        mlcdnumber_rsi_man_step->setFont(font1);
        mlcdnumber_rsi_man_step->setProperty("value", QVariant(0.1));

        gridLayout_4->addWidget(mlcdnumber_rsi_man_step, 2, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1);
        gridLayout_4->setRowStretch(2, 1);

        verticalLayout->addLayout(gridLayout_4);

        line_11 = new QFrame(FSWClass);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_11);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        mcheckbox_sri_connect = new QCheckBox(FSWClass);
        mcheckbox_sri_connect->setObjectName(QString::fromUtf8("mcheckbox_sri_connect"));
        mcheckbox_sri_connect->setFont(font1);

        gridLayout_6->addWidget(mcheckbox_sri_connect, 0, 2, 1, 1);

        mcheckbox_sri_status_on = new QCheckBox(FSWClass);
        mcheckbox_sri_status_on->setObjectName(QString::fromUtf8("mcheckbox_sri_status_on"));
        mcheckbox_sri_status_on->setEnabled(false);
        mcheckbox_sri_status_on->setFont(font1);

        gridLayout_6->addWidget(mcheckbox_sri_status_on, 0, 4, 1, 1);

        mcheckbox_sri_status_off = new QCheckBox(FSWClass);
        mcheckbox_sri_status_off->setObjectName(QString::fromUtf8("mcheckbox_sri_status_off"));
        mcheckbox_sri_status_off->setEnabled(false);
        mcheckbox_sri_status_off->setFont(font1);
        mcheckbox_sri_status_off->setChecked(true);

        gridLayout_6->addWidget(mcheckbox_sri_status_off, 1, 4, 1, 1);

        mcheckbox_sri_ask = new QCheckBox(FSWClass);
        mcheckbox_sri_ask->setObjectName(QString::fromUtf8("mcheckbox_sri_ask"));
        mcheckbox_sri_ask->setEnabled(false);
        mcheckbox_sri_ask->setFont(font1);

        gridLayout_6->addWidget(mcheckbox_sri_ask, 0, 3, 1, 1);

        mcheckbox_sri_disconnect = new QCheckBox(FSWClass);
        mcheckbox_sri_disconnect->setObjectName(QString::fromUtf8("mcheckbox_sri_disconnect"));
        mcheckbox_sri_disconnect->setFont(font1);
        mcheckbox_sri_disconnect->setChecked(true);

        gridLayout_6->addWidget(mcheckbox_sri_disconnect, 1, 2, 1, 1);

        mcheckbox_sri_stop = new QCheckBox(FSWClass);
        mcheckbox_sri_stop->setObjectName(QString::fromUtf8("mcheckbox_sri_stop"));
        mcheckbox_sri_stop->setEnabled(false);
        mcheckbox_sri_stop->setFont(font1);
        mcheckbox_sri_stop->setChecked(true);

        gridLayout_6->addWidget(mcheckbox_sri_stop, 1, 3, 1, 1);

        line_6 = new QFrame(FSWClass);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_6, 0, 1, 3, 1);

        checkbox_rsi_on = new QCheckBox(FSWClass);
        checkbox_rsi_on->setObjectName(QString::fromUtf8("checkbox_rsi_on"));
        checkbox_rsi_on->setFont(font1);

        gridLayout_6->addWidget(checkbox_rsi_on, 0, 0, 1, 1);

        checkbox_rsi_off = new QCheckBox(FSWClass);
        checkbox_rsi_off->setObjectName(QString::fromUtf8("checkbox_rsi_off"));
        checkbox_rsi_off->setFont(font1);
        checkbox_rsi_off->setChecked(true);

        gridLayout_6->addWidget(checkbox_rsi_off, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(2, 4);
        verticalLayout->setStretch(4, 5);
        verticalLayout->setStretch(6, 2);

        horizontalLayout->addLayout(verticalLayout);

        line = new QFrame(FSWClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mpushbutton_rsi_man_y_down = new QPushButton(FSWClass);
        mpushbutton_rsi_man_y_down->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_y_down"));
        mpushbutton_rsi_man_y_down->setEnabled(false);
        mpushbutton_rsi_man_y_down->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_y_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_y_down->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_rsi_man_y_down, 0, 1, 1, 1);

        mpushbutton_rsi_man_y_up = new QPushButton(FSWClass);
        mpushbutton_rsi_man_y_up->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_y_up"));
        mpushbutton_rsi_man_y_up->setEnabled(false);
        mpushbutton_rsi_man_y_up->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_y_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_y_up->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_rsi_man_y_up, 0, 2, 1, 1);

        mpushbutton_sri_zero = new QPushButton(FSWClass);
        mpushbutton_sri_zero->setObjectName(QString::fromUtf8("mpushbutton_sri_zero"));
        mpushbutton_sri_zero->setMinimumSize(QSize(78, 30));
        mpushbutton_sri_zero->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_sri_zero, 6, 1, 1, 2);

        mpushbutton_rsi_man_z_up = new QPushButton(FSWClass);
        mpushbutton_rsi_man_z_up->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_z_up"));
        mpushbutton_rsi_man_z_up->setEnabled(false);
        mpushbutton_rsi_man_z_up->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_z_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_z_up->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_rsi_man_z_up, 1, 1, 1, 1);

        mpushbutton_rsi_man_z_down = new QPushButton(FSWClass);
        mpushbutton_rsi_man_z_down->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_z_down"));
        mpushbutton_rsi_man_z_down->setEnabled(false);
        mpushbutton_rsi_man_z_down->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_z_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_z_down->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_rsi_man_z_down, 1, 2, 1, 1);

        mpushbutton_spindle_on = new QPushButton(FSWClass);
        mpushbutton_spindle_on->setObjectName(QString::fromUtf8("mpushbutton_spindle_on"));
        mpushbutton_spindle_on->setEnabled(false);
        mpushbutton_spindle_on->setMinimumSize(QSize(78, 35));
        mpushbutton_spindle_on->setMaximumSize(QSize(85, 16777215));
        mpushbutton_spindle_on->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_spindle_on, 2, 1, 1, 1);

        mpushbutton_spindle_off = new QPushButton(FSWClass);
        mpushbutton_spindle_off->setObjectName(QString::fromUtf8("mpushbutton_spindle_off"));
        mpushbutton_spindle_off->setEnabled(false);
        mpushbutton_spindle_off->setMinimumSize(QSize(78, 35));
        mpushbutton_spindle_off->setMaximumSize(QSize(85, 16777215));
        mpushbutton_spindle_off->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_spindle_off, 2, 2, 1, 1);

        mpushbutton_spindle_speed_down100 = new QPushButton(FSWClass);
        mpushbutton_spindle_speed_down100->setObjectName(QString::fromUtf8("mpushbutton_spindle_speed_down100"));
        mpushbutton_spindle_speed_down100->setMinimumSize(QSize(78, 35));
        mpushbutton_spindle_speed_down100->setMaximumSize(QSize(85, 16777215));
        mpushbutton_spindle_speed_down100->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_spindle_speed_down100, 3, 1, 1, 1);

        mpushbutton_spindle_speed_up100 = new QPushButton(FSWClass);
        mpushbutton_spindle_speed_up100->setObjectName(QString::fromUtf8("mpushbutton_spindle_speed_up100"));
        mpushbutton_spindle_speed_up100->setMinimumSize(QSize(78, 35));
        mpushbutton_spindle_speed_up100->setMaximumSize(QSize(85, 16777215));
        mpushbutton_spindle_speed_up100->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_spindle_speed_up100, 3, 2, 1, 1);

        mpushbutton_rsi_man_step_down = new QPushButton(FSWClass);
        mpushbutton_rsi_man_step_down->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_step_down"));
        mpushbutton_rsi_man_step_down->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_step_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_step_down->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_rsi_man_step_down, 5, 1, 1, 1);

        mpushbutton_rsi_man_step_up = new QPushButton(FSWClass);
        mpushbutton_rsi_man_step_up->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_step_up"));
        mpushbutton_rsi_man_step_up->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_step_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_step_up->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_rsi_man_step_up, 5, 2, 1, 1);

        mpushbutton_sri_fzsetting_down = new QPushButton(FSWClass);
        mpushbutton_sri_fzsetting_down->setObjectName(QString::fromUtf8("mpushbutton_sri_fzsetting_down"));
        mpushbutton_sri_fzsetting_down->setEnabled(true);
        mpushbutton_sri_fzsetting_down->setMinimumSize(QSize(78, 35));
        mpushbutton_sri_fzsetting_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_sri_fzsetting_down->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_sri_fzsetting_down, 4, 1, 1, 1);

        mpushbutton_sri_fzsetting_up = new QPushButton(FSWClass);
        mpushbutton_sri_fzsetting_up->setObjectName(QString::fromUtf8("mpushbutton_sri_fzsetting_up"));
        mpushbutton_sri_fzsetting_up->setEnabled(true);
        mpushbutton_sri_fzsetting_up->setMinimumSize(QSize(78, 35));
        mpushbutton_sri_fzsetting_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_sri_fzsetting_up->setFont(font1);

        gridLayout_2->addWidget(mpushbutton_sri_fzsetting_up, 4, 2, 1, 1);

        pbSpindleConnect = new QPushButton(FSWClass);
        pbSpindleConnect->setObjectName(QString::fromUtf8("pbSpindleConnect"));
        pbSpindleConnect->setMinimumSize(QSize(0, 30));
        pbSpindleConnect->setFont(font1);

        gridLayout_2->addWidget(pbSpindleConnect, 7, 1, 1, 2);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 2);

        gridLayout_7->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(FSWClass);

        QMetaObject::connectSlotsByName(FSWClass);
    } // setupUi

    void retranslateUi(QWidget *FSWClass)
    {
        FSWClass->setWindowTitle(QApplication::translate("FSWClass", "FSW", 0, QApplication::UnicodeUTF8));
        mlabel1->setText(QApplication::translate("FSWClass", "\345\212\233\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        mlabel_sri_status_connect->setText(QApplication::translate("FSWClass", "\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FSWClass", "\344\270\273\350\275\264\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        mlabel_spindle_status->setText(QApplication::translate("FSWClass", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FSWClass", "\350\256\276\345\256\232\351\200\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FSWClass", "\345\275\223\345\211\215\351\200\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FSWClass", "\350\256\276\345\256\232\345\212\233\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("FSWClass", "\345\275\223\345\211\215\345\212\233\357\274\232", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("FSWClass", "\316\224Y\346\200\273\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("FSWClass", "\316\224Z\346\200\273\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("FSWClass", "\346\211\213\345\212\250Y\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FSWClass", "\346\211\213\345\212\250Z\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("FSWClass", "\345\212\233Z\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("FSWClass", "  \346\255\245\350\267\235", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_connect->setText(QApplication::translate("FSWClass", "\345\212\233\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_status_on->setText(QApplication::translate("FSWClass", "\345\212\233\344\277\256\346\255\243\345\274\200", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_status_off->setText(QApplication::translate("FSWClass", "\345\212\233\344\277\256\346\255\243\345\205\263", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_ask->setText(QApplication::translate("FSWClass", "\345\212\233\351\227\256\350\257\242", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_disconnect->setText(QApplication::translate("FSWClass", "\345\212\233\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_stop->setText(QApplication::translate("FSWClass", "\345\212\233\345\201\234\351\227\256", 0, QApplication::UnicodeUTF8));
        checkbox_rsi_on->setText(QApplication::translate("FSWClass", "\345\274\200\345\220\257\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        checkbox_rsi_off->setText(QApplication::translate("FSWClass", "\345\205\263\351\227\255\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_y_down->setText(QApplication::translate("FSWClass", "\345\267\246(Y-)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_y_up->setText(QApplication::translate("FSWClass", "\345\217\263(Y+)", 0, QApplication::UnicodeUTF8));
        mpushbutton_sri_zero->setText(QApplication::translate("FSWClass", "\345\212\233\351\233\266\347\202\271\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_z_up->setText(QApplication::translate("FSWClass", "\344\270\213(Z-)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_z_down->setText(QApplication::translate("FSWClass", "\344\270\212(Z+)", 0, QApplication::UnicodeUTF8));
        mpushbutton_spindle_on->setText(QApplication::translate("FSWClass", "\345\274\200\344\270\273\350\275\264", 0, QApplication::UnicodeUTF8));
        mpushbutton_spindle_off->setText(QApplication::translate("FSWClass", "\345\201\234\344\270\273\350\275\264", 0, QApplication::UnicodeUTF8));
        mpushbutton_spindle_speed_down100->setText(QApplication::translate("FSWClass", "\350\275\254\351\200\237-(5)", 0, QApplication::UnicodeUTF8));
        mpushbutton_spindle_speed_up100->setText(QApplication::translate("FSWClass", "\350\275\254\351\200\237+(8)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_step_down->setText(QApplication::translate("FSWClass", "\346\255\245\350\267\235-(0)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_step_up->setText(QApplication::translate("FSWClass", "\346\255\245\350\267\235+(1)", 0, QApplication::UnicodeUTF8));
        mpushbutton_sri_fzsetting_down->setText(QApplication::translate("FSWClass", "\345\212\233-(4)", 0, QApplication::UnicodeUTF8));
        mpushbutton_sri_fzsetting_up->setText(QApplication::translate("FSWClass", "\345\212\233+(7)", 0, QApplication::UnicodeUTF8));
        pbSpindleConnect->setText(QApplication::translate("FSWClass", "\350\277\236\346\216\245\344\270\273\350\275\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FSWClass: public Ui_FSWClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSW_H
