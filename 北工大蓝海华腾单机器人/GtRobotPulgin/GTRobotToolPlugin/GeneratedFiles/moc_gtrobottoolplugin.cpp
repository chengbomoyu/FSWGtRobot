/****************************************************************************
** Meta object code from reading C++ file 'gtrobottoolplugin.h'
**
** Created: Thu Feb 24 21:42:26 2022
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../_Source_my/CallBack/gtrobottoolplugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gtrobottoolplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FSW[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      28,    4,    4,    4, 0x0a,
      67,    4,    4,    4, 0x0a,
     107,    4,    4,    4, 0x0a,
     155,    4,    4,    4, 0x0a,
     205,    4,    4,    4, 0x0a,
     241,    4,    4,    4, 0x0a,
     278,    4,    4,    4, 0x0a,
     322,    4,    4,    4, 0x0a,
     368,    4,    4,    4, 0x0a,
     409,    4,    4,    4, 0x0a,
     452,    4,    4,    4, 0x0a,
     493,    4,    4,    4, 0x0a,
     536,    4,    4,    4, 0x0a,
     578,    4,    4,    4, 0x0a,
     623,    4,    4,    4, 0x0a,
     661,    4,    4,    4, 0x0a,
     700,    4,    4,    4, 0x0a,
     744,    4,    4,    4, 0x0a,
     789,    4,    4,    4, 0x0a,
     826,    4,    4,    4, 0x0a,
     871,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FSW[] = {
    "FSW\0\0onpbpbSpindleConnect()\0"
    "onpbtnclicked_mpushbutton_spindle_on()\0"
    "onpbtnclicked_mpushbutton_spindle_off()\0"
    "onpbtnclicked_mpushbutton_spindle_speed_up100()\0"
    "onpbtnclicked_mpushbutton_spindle_speed_down100()\0"
    "oncheckboxclicked_checkbox_rsi_on()\0"
    "oncheckboxclicked_checkbox_rsi_off()\0"
    "onpbtnclicked_mpushbutton_rsi_man_step_up()\0"
    "onpbtnclicked_mpushbutton_rsi_man_step_down()\0"
    "onpbtnclicked_mpushbutton_rsi_man_y_up()\0"
    "onpbtnclicked_mpushbutton_rsi_man_y_down()\0"
    "onpbtnclicked_mpushbutton_rsi_man_z_up()\0"
    "onpbtnclicked_mpushbutton_rsi_man_z_down()\0"
    "oncheckboxclicked_mcheckbox_sri_connect()\0"
    "oncheckboxclicked_mcheckbox_sri_disconnect()\0"
    "oncheckboxclicked_mcheckbox_sri_ask()\0"
    "oncheckboxclicked_mcheckbox_sri_stop()\0"
    "oncheckboxclicked_mcheckbox_sri_status_on()\0"
    "oncheckboxclicked_mcheckbox_sir_status_off()\0"
    "onpbtnclicked_mpushbutton_sri_zero()\0"
    "onpbtnclicked_mpushbutton_sri_fzsetting_up()\0"
    "onpbtnclicked_mpushbutton_sri_fzsetting_down()\0"
};

const QMetaObject FSW::staticMetaObject = {
    { &GtAppFrameInterface::staticMetaObject, qt_meta_stringdata_FSW,
      qt_meta_data_FSW, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FSW::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FSW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FSW::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FSW))
        return static_cast<void*>(const_cast< FSW*>(this));
    if (!strcmp(_clname, "RobotHmi"))
        return static_cast< GtAppFrameInterface*>(const_cast< FSW*>(this));
    return GtAppFrameInterface::qt_metacast(_clname);
}

int FSW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GtAppFrameInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onpbpbSpindleConnect(); break;
        case 1: onpbtnclicked_mpushbutton_spindle_on(); break;
        case 2: onpbtnclicked_mpushbutton_spindle_off(); break;
        case 3: onpbtnclicked_mpushbutton_spindle_speed_up100(); break;
        case 4: onpbtnclicked_mpushbutton_spindle_speed_down100(); break;
        case 5: oncheckboxclicked_checkbox_rsi_on(); break;
        case 6: oncheckboxclicked_checkbox_rsi_off(); break;
        case 7: onpbtnclicked_mpushbutton_rsi_man_step_up(); break;
        case 8: onpbtnclicked_mpushbutton_rsi_man_step_down(); break;
        case 9: onpbtnclicked_mpushbutton_rsi_man_y_up(); break;
        case 10: onpbtnclicked_mpushbutton_rsi_man_y_down(); break;
        case 11: onpbtnclicked_mpushbutton_rsi_man_z_up(); break;
        case 12: onpbtnclicked_mpushbutton_rsi_man_z_down(); break;
        case 13: oncheckboxclicked_mcheckbox_sri_connect(); break;
        case 14: oncheckboxclicked_mcheckbox_sri_disconnect(); break;
        case 15: oncheckboxclicked_mcheckbox_sri_ask(); break;
        case 16: oncheckboxclicked_mcheckbox_sri_stop(); break;
        case 17: oncheckboxclicked_mcheckbox_sri_status_on(); break;
        case 18: oncheckboxclicked_mcheckbox_sir_status_off(); break;
        case 19: onpbtnclicked_mpushbutton_sri_zero(); break;
        case 20: onpbtnclicked_mpushbutton_sri_fzsetting_up(); break;
        case 21: onpbtnclicked_mpushbutton_sri_fzsetting_down(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
