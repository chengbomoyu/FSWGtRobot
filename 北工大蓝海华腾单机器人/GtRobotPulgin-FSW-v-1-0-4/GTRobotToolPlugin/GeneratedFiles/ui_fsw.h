/********************************************************************************
** Form generated from reading UI file 'fsw.ui'
**
** Created: Thu Mar 10 10:30:04 2022
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
    QLabel *mlabel_rsie_status_onoff;
    QLabel *mlabel_plaser_status_onoff;
    QFrame *line_3;
    QGridLayout *gridLayout_5;
    QLabel *label_2;
    QLCDNumber *mlcdnumber_sri_fzsetting;
    QLabel *label_25;
    QLCDNumber *mlcdnumber_sri_Fz;
    QLabel *label_19;
    QLabel *label_4;
    QLCDNumber *mlcdnumber_plaser_vlotageset;
    QLabel *label_5;
    QLCDNumber *mlcdnumber_plaser_vlotagenow;
    QLCDNumber *mlcdnumber_rsi_man_step;
    QFrame *line_4;
    QFrame *line_9;
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
    QLabel *label;
    QLCDNumber *lcdNumber;
    QFrame *line_10;
    QFrame *line_5;
    QFrame *line_11;
    QGridLayout *gridLayout_6;
    QCheckBox *checkBox_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QCheckBox *checkbox_rsi_on;
    QCheckBox *checkbox_rsi_off;
    QCheckBox *mcheckbox_sri_status_off;
    QCheckBox *mcheckbox_sri_status_on;
    QCheckBox *mcheckbox_sri_disconnect;
    QCheckBox *mcheckbox_plaser_status_off;
    QCheckBox *mcheckbox_plaser_status_on;
    QCheckBox *checkBox_4;
    QPushButton *mpushbutton_sri_zero;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *mpushbutton_plaser_zero;
    QCheckBox *mcheckbox_sri_connect;
    QCheckBox *mcheckbox_sri_ask;
    QCheckBox *mcheckbox_sri_stop;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QPushButton *mpushbutton_rsi_man_y_down;
    QPushButton *mpushbutton_rsi_man_y_up;
    QPushButton *mpushbutton_rsi_save;
    QPushButton *mpushbutton_rsi_savedone;
    QPushButton *mpushbutton_rsi_man_z_up;
    QPushButton *mpushbutton_rsi_man_z_down;
    QPushButton *mpushbutton_go_spindle_on;
    QPushButton *mpushbutton_go_spindle_off;
    QPushButton *mpushbutton_rsi_man_step_down;
    QPushButton *mpushbutton_rsi_man_step_up;
    QPushButton *mpushbutton_sri_fzsetting_down;
    QPushButton *mpushbutton_sri_fzsetting_up;
    QPushButton *mpushbutton_plaser_possetting_down;
    QPushButton *mpushbutton_plaser_possetting_up;

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
        font.setPointSize(12);
        mlabel1->setFont(font);

        gridLayout->addWidget(mlabel1, 0, 0, 1, 1);

        mlabel_sri_status_connect = new QLabel(FSWClass);
        mlabel_sri_status_connect->setObjectName(QString::fromUtf8("mlabel_sri_status_connect"));
        mlabel_sri_status_connect->setFont(font);

        gridLayout->addWidget(mlabel_sri_status_connect, 0, 1, 1, 1);

        mlabel_rsie_status_onoff = new QLabel(FSWClass);
        mlabel_rsie_status_onoff->setObjectName(QString::fromUtf8("mlabel_rsie_status_onoff"));
        mlabel_rsie_status_onoff->setEnabled(true);
        mlabel_rsie_status_onoff->setFont(font);

        gridLayout->addWidget(mlabel_rsie_status_onoff, 0, 2, 1, 1);

        mlabel_plaser_status_onoff = new QLabel(FSWClass);
        mlabel_plaser_status_onoff->setObjectName(QString::fromUtf8("mlabel_plaser_status_onoff"));
        mlabel_plaser_status_onoff->setEnabled(true);
        mlabel_plaser_status_onoff->setFont(font);

        gridLayout->addWidget(mlabel_plaser_status_onoff, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line_3 = new QFrame(FSWClass);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_2 = new QLabel(FSWClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setFont(font);

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        mlcdnumber_sri_fzsetting = new QLCDNumber(FSWClass);
        mlcdnumber_sri_fzsetting->setObjectName(QString::fromUtf8("mlcdnumber_sri_fzsetting"));
        mlcdnumber_sri_fzsetting->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        mlcdnumber_sri_fzsetting->setFont(font1);
        mlcdnumber_sri_fzsetting->setProperty("value", QVariant(4500));
        mlcdnumber_sri_fzsetting->setProperty("intValue", QVariant(4500));

        gridLayout_5->addWidget(mlcdnumber_sri_fzsetting, 0, 1, 1, 1);

        label_25 = new QLabel(FSWClass);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font);

        gridLayout_5->addWidget(label_25, 1, 0, 1, 1);

        mlcdnumber_sri_Fz = new QLCDNumber(FSWClass);
        mlcdnumber_sri_Fz->setObjectName(QString::fromUtf8("mlcdnumber_sri_Fz"));
        mlcdnumber_sri_Fz->setEnabled(true);
        mlcdnumber_sri_Fz->setMinimumSize(QSize(0, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(16);
        mlcdnumber_sri_Fz->setFont(font2);

        gridLayout_5->addWidget(mlcdnumber_sri_Fz, 1, 1, 1, 1);

        label_19 = new QLabel(FSWClass);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        gridLayout_5->addWidget(label_19, 0, 6, 1, 1);

        label_4 = new QLabel(FSWClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout_5->addWidget(label_4, 0, 2, 1, 1);

        mlcdnumber_plaser_vlotageset = new QLCDNumber(FSWClass);
        mlcdnumber_plaser_vlotageset->setObjectName(QString::fromUtf8("mlcdnumber_plaser_vlotageset"));
        mlcdnumber_plaser_vlotageset->setProperty("value", QVariant(0));
        mlcdnumber_plaser_vlotageset->setProperty("intValue", QVariant(0));

        gridLayout_5->addWidget(mlcdnumber_plaser_vlotageset, 0, 3, 1, 1);

        label_5 = new QLabel(FSWClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_5->addWidget(label_5, 1, 2, 1, 1);

        mlcdnumber_plaser_vlotagenow = new QLCDNumber(FSWClass);
        mlcdnumber_plaser_vlotagenow->setObjectName(QString::fromUtf8("mlcdnumber_plaser_vlotagenow"));

        gridLayout_5->addWidget(mlcdnumber_plaser_vlotagenow, 1, 3, 1, 1);

        mlcdnumber_rsi_man_step = new QLCDNumber(FSWClass);
        mlcdnumber_rsi_man_step->setObjectName(QString::fromUtf8("mlcdnumber_rsi_man_step"));
        mlcdnumber_rsi_man_step->setFont(font);
        mlcdnumber_rsi_man_step->setProperty("value", QVariant(0.1));

        gridLayout_5->addWidget(mlcdnumber_rsi_man_step, 1, 6, 1, 1);

        line_4 = new QFrame(FSWClass);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_4, 0, 5, 2, 1);

        line_9 = new QFrame(FSWClass);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_9, 0, 4, 2, 1);


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
        label_18->setFont(font);

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        lcdnumber_rsi_dy = new QLCDNumber(FSWClass);
        lcdnumber_rsi_dy->setObjectName(QString::fromUtf8("lcdnumber_rsi_dy"));
        lcdnumber_rsi_dy->setEnabled(true);
        lcdnumber_rsi_dy->setMinimumSize(QSize(0, 24));
        lcdnumber_rsi_dy->setFont(font);

        gridLayout_4->addWidget(lcdnumber_rsi_dy, 0, 1, 1, 1);

        label_21 = new QLabel(FSWClass);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);

        gridLayout_4->addWidget(label_21, 0, 3, 1, 1);

        lcdnumber_rsi_dz = new QLCDNumber(FSWClass);
        lcdnumber_rsi_dz->setObjectName(QString::fromUtf8("lcdnumber_rsi_dz"));
        lcdnumber_rsi_dz->setMinimumSize(QSize(0, 24));
        lcdnumber_rsi_dz->setFont(font);

        gridLayout_4->addWidget(lcdnumber_rsi_dz, 0, 4, 1, 1);

        label_10 = new QLabel(FSWClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        mlcdnumber_rsi_man_sum_y = new QLCDNumber(FSWClass);
        mlcdnumber_rsi_man_sum_y->setObjectName(QString::fromUtf8("mlcdnumber_rsi_man_sum_y"));
        mlcdnumber_rsi_man_sum_y->setMinimumSize(QSize(0, 24));
        mlcdnumber_rsi_man_sum_y->setFont(font);

        gridLayout_4->addWidget(mlcdnumber_rsi_man_sum_y, 1, 1, 1, 1);

        label_9 = new QLabel(FSWClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout_4->addWidget(label_9, 1, 3, 1, 1);

        mlcdnumber_rsi_man_sum_z = new QLCDNumber(FSWClass);
        mlcdnumber_rsi_man_sum_z->setObjectName(QString::fromUtf8("mlcdnumber_rsi_man_sum_z"));
        mlcdnumber_rsi_man_sum_z->setMinimumSize(QSize(0, 24));
        mlcdnumber_rsi_man_sum_z->setFont(font);
        mlcdnumber_rsi_man_sum_z->setSmallDecimalPoint(false);
        mlcdnumber_rsi_man_sum_z->setProperty("value", QVariant(0));

        gridLayout_4->addWidget(mlcdnumber_rsi_man_sum_z, 1, 4, 1, 1);

        label_42 = new QLabel(FSWClass);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font);

        gridLayout_4->addWidget(label_42, 2, 3, 1, 1);

        mlcdnumber_sri_correct_sum_z = new QLCDNumber(FSWClass);
        mlcdnumber_sri_correct_sum_z->setObjectName(QString::fromUtf8("mlcdnumber_sri_correct_sum_z"));
        mlcdnumber_sri_correct_sum_z->setEnabled(true);
        mlcdnumber_sri_correct_sum_z->setMinimumSize(QSize(0, 24));
        mlcdnumber_sri_correct_sum_z->setFont(font);

        gridLayout_4->addWidget(mlcdnumber_sri_correct_sum_z, 2, 4, 1, 1);

        label = new QLabel(FSWClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_4->addWidget(label, 2, 0, 1, 1);

        lcdNumber = new QLCDNumber(FSWClass);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(0, 24));
        lcdNumber->setFont(font);

        gridLayout_4->addWidget(lcdNumber, 2, 1, 1, 1);

        line_10 = new QFrame(FSWClass);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_10, 0, 2, 3, 1);


        verticalLayout->addLayout(gridLayout_4);

        line_5 = new QFrame(FSWClass);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        line_11 = new QFrame(FSWClass);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_11);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        checkBox_5 = new QCheckBox(FSWClass);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setEnabled(false);
        checkBox_5->setFont(font);
        checkBox_5->setChecked(false);

        gridLayout_6->addWidget(checkBox_5, 6, 3, 1, 1);

        line_6 = new QFrame(FSWClass);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_6, 1, 1, 6, 1);

        line_7 = new QFrame(FSWClass);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_7, 4, 2, 1, 3);

        line_8 = new QFrame(FSWClass);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_8, 4, 0, 1, 1);

        checkbox_rsi_on = new QCheckBox(FSWClass);
        checkbox_rsi_on->setObjectName(QString::fromUtf8("checkbox_rsi_on"));
        checkbox_rsi_on->setFont(font);

        gridLayout_6->addWidget(checkbox_rsi_on, 1, 0, 1, 1);

        checkbox_rsi_off = new QCheckBox(FSWClass);
        checkbox_rsi_off->setObjectName(QString::fromUtf8("checkbox_rsi_off"));
        checkbox_rsi_off->setFont(font);
        checkbox_rsi_off->setChecked(true);

        gridLayout_6->addWidget(checkbox_rsi_off, 3, 0, 1, 1);

        mcheckbox_sri_status_off = new QCheckBox(FSWClass);
        mcheckbox_sri_status_off->setObjectName(QString::fromUtf8("mcheckbox_sri_status_off"));
        mcheckbox_sri_status_off->setEnabled(false);
        mcheckbox_sri_status_off->setFont(font);
        mcheckbox_sri_status_off->setChecked(true);

        gridLayout_6->addWidget(mcheckbox_sri_status_off, 5, 0, 1, 1);

        mcheckbox_sri_status_on = new QCheckBox(FSWClass);
        mcheckbox_sri_status_on->setObjectName(QString::fromUtf8("mcheckbox_sri_status_on"));
        mcheckbox_sri_status_on->setEnabled(false);
        mcheckbox_sri_status_on->setFont(font);

        gridLayout_6->addWidget(mcheckbox_sri_status_on, 6, 0, 1, 1);

        mcheckbox_sri_disconnect = new QCheckBox(FSWClass);
        mcheckbox_sri_disconnect->setObjectName(QString::fromUtf8("mcheckbox_sri_disconnect"));
        mcheckbox_sri_disconnect->setFont(font);
        mcheckbox_sri_disconnect->setChecked(false);

        gridLayout_6->addWidget(mcheckbox_sri_disconnect, 6, 2, 1, 1);

        mcheckbox_plaser_status_off = new QCheckBox(FSWClass);
        mcheckbox_plaser_status_off->setObjectName(QString::fromUtf8("mcheckbox_plaser_status_off"));
        mcheckbox_plaser_status_off->setEnabled(true);
        mcheckbox_plaser_status_off->setFont(font);
        mcheckbox_plaser_status_off->setCheckable(false);
        mcheckbox_plaser_status_off->setChecked(false);

        gridLayout_6->addWidget(mcheckbox_plaser_status_off, 6, 4, 1, 1);

        mcheckbox_plaser_status_on = new QCheckBox(FSWClass);
        mcheckbox_plaser_status_on->setObjectName(QString::fromUtf8("mcheckbox_plaser_status_on"));
        mcheckbox_plaser_status_on->setEnabled(true);
        mcheckbox_plaser_status_on->setFont(font);

        gridLayout_6->addWidget(mcheckbox_plaser_status_on, 5, 4, 1, 1);

        checkBox_4 = new QCheckBox(FSWClass);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        checkBox_4->setFont(font);
        checkBox_4->setChecked(false);

        gridLayout_6->addWidget(checkBox_4, 3, 4, 1, 1);

        mpushbutton_sri_zero = new QPushButton(FSWClass);
        mpushbutton_sri_zero->setObjectName(QString::fromUtf8("mpushbutton_sri_zero"));
        mpushbutton_sri_zero->setMinimumSize(QSize(78, 30));
        mpushbutton_sri_zero->setFont(font);

        gridLayout_6->addWidget(mpushbutton_sri_zero, 3, 2, 1, 1);

        checkBox_2 = new QCheckBox(FSWClass);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        checkBox_2->setFont(font);
        checkBox_2->setChecked(true);

        gridLayout_6->addWidget(checkBox_2, 1, 3, 1, 1);

        checkBox_3 = new QCheckBox(FSWClass);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setEnabled(false);
        checkBox_3->setFont(font);
        checkBox_3->setCheckable(false);
        checkBox_3->setChecked(false);

        gridLayout_6->addWidget(checkBox_3, 5, 3, 1, 1);

        mpushbutton_plaser_zero = new QPushButton(FSWClass);
        mpushbutton_plaser_zero->setObjectName(QString::fromUtf8("mpushbutton_plaser_zero"));
        mpushbutton_plaser_zero->setMinimumSize(QSize(78, 30));
        mpushbutton_plaser_zero->setFont(font);

        gridLayout_6->addWidget(mpushbutton_plaser_zero, 3, 3, 1, 1);

        mcheckbox_sri_connect = new QCheckBox(FSWClass);
        mcheckbox_sri_connect->setObjectName(QString::fromUtf8("mcheckbox_sri_connect"));
        mcheckbox_sri_connect->setEnabled(true);
        mcheckbox_sri_connect->setFont(font);
        mcheckbox_sri_connect->setChecked(false);

        gridLayout_6->addWidget(mcheckbox_sri_connect, 1, 2, 1, 1);

        mcheckbox_sri_ask = new QCheckBox(FSWClass);
        mcheckbox_sri_ask->setObjectName(QString::fromUtf8("mcheckbox_sri_ask"));
        mcheckbox_sri_ask->setEnabled(false);
        mcheckbox_sri_ask->setFont(font);

        gridLayout_6->addWidget(mcheckbox_sri_ask, 5, 2, 1, 1);

        mcheckbox_sri_stop = new QCheckBox(FSWClass);
        mcheckbox_sri_stop->setObjectName(QString::fromUtf8("mcheckbox_sri_stop"));
        mcheckbox_sri_stop->setEnabled(false);
        mcheckbox_sri_stop->setFont(font);
        mcheckbox_sri_stop->setChecked(false);

        gridLayout_6->addWidget(mcheckbox_sri_stop, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 4);
        verticalLayout->setStretch(4, 5);

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
        mpushbutton_rsi_man_y_down->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_man_y_down, 0, 1, 1, 1);

        mpushbutton_rsi_man_y_up = new QPushButton(FSWClass);
        mpushbutton_rsi_man_y_up->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_y_up"));
        mpushbutton_rsi_man_y_up->setEnabled(false);
        mpushbutton_rsi_man_y_up->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_y_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_y_up->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_man_y_up, 0, 2, 1, 1);

        mpushbutton_rsi_save = new QPushButton(FSWClass);
        mpushbutton_rsi_save->setObjectName(QString::fromUtf8("mpushbutton_rsi_save"));
        mpushbutton_rsi_save->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_save->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_save->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_save, 11, 1, 1, 1);

        mpushbutton_rsi_savedone = new QPushButton(FSWClass);
        mpushbutton_rsi_savedone->setObjectName(QString::fromUtf8("mpushbutton_rsi_savedone"));
        mpushbutton_rsi_savedone->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_savedone->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_savedone->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_savedone, 11, 2, 1, 1);

        mpushbutton_rsi_man_z_up = new QPushButton(FSWClass);
        mpushbutton_rsi_man_z_up->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_z_up"));
        mpushbutton_rsi_man_z_up->setEnabled(false);
        mpushbutton_rsi_man_z_up->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_z_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_z_up->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_man_z_up, 1, 1, 1, 1);

        mpushbutton_rsi_man_z_down = new QPushButton(FSWClass);
        mpushbutton_rsi_man_z_down->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_z_down"));
        mpushbutton_rsi_man_z_down->setEnabled(false);
        mpushbutton_rsi_man_z_down->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_z_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_z_down->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_man_z_down, 1, 2, 1, 1);

        mpushbutton_go_spindle_on = new QPushButton(FSWClass);
        mpushbutton_go_spindle_on->setObjectName(QString::fromUtf8("mpushbutton_go_spindle_on"));
        mpushbutton_go_spindle_on->setEnabled(false);
        mpushbutton_go_spindle_on->setMinimumSize(QSize(78, 35));
        mpushbutton_go_spindle_on->setMaximumSize(QSize(85, 16777215));
        mpushbutton_go_spindle_on->setFont(font);

        gridLayout_2->addWidget(mpushbutton_go_spindle_on, 2, 1, 1, 1);

        mpushbutton_go_spindle_off = new QPushButton(FSWClass);
        mpushbutton_go_spindle_off->setObjectName(QString::fromUtf8("mpushbutton_go_spindle_off"));
        mpushbutton_go_spindle_off->setEnabled(false);
        mpushbutton_go_spindle_off->setMinimumSize(QSize(78, 35));
        mpushbutton_go_spindle_off->setMaximumSize(QSize(85, 16777215));
        mpushbutton_go_spindle_off->setFont(font);

        gridLayout_2->addWidget(mpushbutton_go_spindle_off, 2, 2, 1, 1);

        mpushbutton_rsi_man_step_down = new QPushButton(FSWClass);
        mpushbutton_rsi_man_step_down->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_step_down"));
        mpushbutton_rsi_man_step_down->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_step_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_step_down->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_man_step_down, 8, 1, 1, 1);

        mpushbutton_rsi_man_step_up = new QPushButton(FSWClass);
        mpushbutton_rsi_man_step_up->setObjectName(QString::fromUtf8("mpushbutton_rsi_man_step_up"));
        mpushbutton_rsi_man_step_up->setMinimumSize(QSize(78, 35));
        mpushbutton_rsi_man_step_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_rsi_man_step_up->setFont(font);

        gridLayout_2->addWidget(mpushbutton_rsi_man_step_up, 8, 2, 1, 1);

        mpushbutton_sri_fzsetting_down = new QPushButton(FSWClass);
        mpushbutton_sri_fzsetting_down->setObjectName(QString::fromUtf8("mpushbutton_sri_fzsetting_down"));
        mpushbutton_sri_fzsetting_down->setEnabled(true);
        mpushbutton_sri_fzsetting_down->setMinimumSize(QSize(78, 35));
        mpushbutton_sri_fzsetting_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_sri_fzsetting_down->setFont(font);

        gridLayout_2->addWidget(mpushbutton_sri_fzsetting_down, 3, 1, 1, 1);

        mpushbutton_sri_fzsetting_up = new QPushButton(FSWClass);
        mpushbutton_sri_fzsetting_up->setObjectName(QString::fromUtf8("mpushbutton_sri_fzsetting_up"));
        mpushbutton_sri_fzsetting_up->setEnabled(true);
        mpushbutton_sri_fzsetting_up->setMinimumSize(QSize(78, 35));
        mpushbutton_sri_fzsetting_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_sri_fzsetting_up->setFont(font);

        gridLayout_2->addWidget(mpushbutton_sri_fzsetting_up, 3, 2, 1, 1);

        mpushbutton_plaser_possetting_down = new QPushButton(FSWClass);
        mpushbutton_plaser_possetting_down->setObjectName(QString::fromUtf8("mpushbutton_plaser_possetting_down"));
        mpushbutton_plaser_possetting_down->setEnabled(true);
        mpushbutton_plaser_possetting_down->setMinimumSize(QSize(78, 35));
        mpushbutton_plaser_possetting_down->setMaximumSize(QSize(85, 16777215));
        mpushbutton_plaser_possetting_down->setFont(font);

        gridLayout_2->addWidget(mpushbutton_plaser_possetting_down, 4, 1, 1, 1);

        mpushbutton_plaser_possetting_up = new QPushButton(FSWClass);
        mpushbutton_plaser_possetting_up->setObjectName(QString::fromUtf8("mpushbutton_plaser_possetting_up"));
        mpushbutton_plaser_possetting_up->setEnabled(true);
        mpushbutton_plaser_possetting_up->setMinimumSize(QSize(78, 35));
        mpushbutton_plaser_possetting_up->setMaximumSize(QSize(85, 16777215));
        mpushbutton_plaser_possetting_up->setFont(font);

        gridLayout_2->addWidget(mpushbutton_plaser_possetting_up, 4, 2, 1, 1);


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
        mlabel_rsie_status_onoff->setText(QApplication::translate("FSWClass", "\345\205\211\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        mlabel_plaser_status_onoff->setText(QApplication::translate("FSWClass", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FSWClass", "\350\256\276\345\256\232\345\212\233\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("FSWClass", "\345\275\223\345\211\215\345\212\233\357\274\232", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("FSWClass", "  \346\255\245\350\267\235", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FSWClass", "\350\256\276\345\256\232\351\253\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FSWClass", "\345\275\223\345\211\215\351\253\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("FSWClass", "\316\224Y\346\200\273\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("FSWClass", "\316\224Z\346\200\273\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("FSWClass", "\346\211\213\345\212\250Y\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FSWClass", "\346\211\213\345\212\250Z\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("FSWClass", "\345\205\211/\345\212\233Z\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FSWClass", "\345\205\211Y\344\277\256\346\255\243\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("FSWClass", "\345\205\211\345\201\234\351\227\256", 0, QApplication::UnicodeUTF8));
        checkbox_rsi_on->setText(QApplication::translate("FSWClass", "\345\274\200\345\220\257\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        checkbox_rsi_off->setText(QApplication::translate("FSWClass", "\345\205\263\351\227\255\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_status_off->setText(QApplication::translate("FSWClass", "\345\212\233\344\277\256\346\255\243\345\205\263", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_status_on->setText(QApplication::translate("FSWClass", "\345\212\233\344\277\256\346\255\243\345\274\200", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_disconnect->setText(QApplication::translate("FSWClass", "\345\212\233\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        mcheckbox_plaser_status_off->setText(QApplication::translate("FSWClass", "\345\205\211\344\277\256\346\255\243\345\205\263", 0, QApplication::UnicodeUTF8));
        mcheckbox_plaser_status_on->setText(QApplication::translate("FSWClass", "\345\205\211\344\277\256\346\255\243\345\274\200", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("FSWClass", "\345\205\211\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
        mpushbutton_sri_zero->setText(QApplication::translate("FSWClass", "\345\212\233\351\233\266\347\202\271\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("FSWClass", "\345\205\211\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("FSWClass", "\345\205\211\351\227\256\350\257\242", 0, QApplication::UnicodeUTF8));
        mpushbutton_plaser_zero->setText(QApplication::translate("FSWClass", "\345\205\211\351\233\266\347\202\271\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_connect->setText(QApplication::translate("FSWClass", "\345\212\233\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_ask->setText(QApplication::translate("FSWClass", "\345\212\233\351\227\256\350\257\242", 0, QApplication::UnicodeUTF8));
        mcheckbox_sri_stop->setText(QApplication::translate("FSWClass", "\345\212\233\345\201\234\351\227\256", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_y_down->setText(QApplication::translate("FSWClass", "\345\267\246(Y-)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_y_up->setText(QApplication::translate("FSWClass", "\345\217\263(Y+)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_save->setText(QApplication::translate("FSWClass", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_savedone->setText(QApplication::translate("FSWClass", "\347\273\223\346\235\237", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_z_up->setText(QApplication::translate("FSWClass", "\344\270\213(Z-)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_z_down->setText(QApplication::translate("FSWClass", "\344\270\212(Z+)", 0, QApplication::UnicodeUTF8));
        mpushbutton_go_spindle_on->setText(QApplication::translate("FSWClass", "\345\274\200\344\270\273\350\275\264", 0, QApplication::UnicodeUTF8));
        mpushbutton_go_spindle_off->setText(QApplication::translate("FSWClass", "\345\201\234\344\270\273\350\275\264", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_step_down->setText(QApplication::translate("FSWClass", "\346\255\245\350\267\235-(0)", 0, QApplication::UnicodeUTF8));
        mpushbutton_rsi_man_step_up->setText(QApplication::translate("FSWClass", "\346\255\245\350\267\235+(1)", 0, QApplication::UnicodeUTF8));
        mpushbutton_sri_fzsetting_down->setText(QApplication::translate("FSWClass", "\345\212\233-(4)", 0, QApplication::UnicodeUTF8));
        mpushbutton_sri_fzsetting_up->setText(QApplication::translate("FSWClass", "\345\212\233+(7)", 0, QApplication::UnicodeUTF8));
        mpushbutton_plaser_possetting_down->setText(QApplication::translate("FSWClass", "\344\275\215-", 0, QApplication::UnicodeUTF8));
        mpushbutton_plaser_possetting_up->setText(QApplication::translate("FSWClass", "\344\275\215+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FSWClass: public Ui_FSWClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSW_H
