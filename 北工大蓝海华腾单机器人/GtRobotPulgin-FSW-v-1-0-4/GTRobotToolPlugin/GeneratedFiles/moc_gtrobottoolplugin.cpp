/****************************************************************************
** Meta object code from reading C++ file 'gtrobottoolplugin.h'
**
** Created: Thu Mar 10 10:30:05 2022
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SOURCE/gtrobottoolplugin.h"
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
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      41,    4,    4,    4, 0x0a,
      78,    4,    4,    4, 0x0a,
     115,    4,    4,    4, 0x0a,
     156,    4,    4,    4, 0x0a,
     200,    4,    4,    4, 0x0a,
     246,    4,    4,    4, 0x0a,
     287,    4,    4,    4, 0x0a,
     330,    4,    4,    4, 0x0a,
     371,    4,    4,    4, 0x0a,
     414,    4,    4,    4, 0x0a,
     456,    4,    4,    4, 0x0a,
     501,    4,    4,    4, 0x0a,
     539,    4,    4,    4, 0x0a,
     578,    4,    4,    4, 0x0a,
     622,    4,    4,    4, 0x0a,
     667,    4,    4,    4, 0x0a,
     704,    4,    4,    4, 0x0a,
     749,    4,    4,    4, 0x0a,
     796,    4,    4,    4, 0x0a,
     843,    4,    4,    4, 0x0a,
     891,    4,    4,    4, 0x0a,
     931,    4,    4,    4, 0x0a,
     982,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FSW[] = {
    "FSW\0\0oncheckboxclicked_checkbox_rsi_on()\0"
    "oncheckboxclicked_checkbox_rsi_off()\0"
    "onpbtnclicked_mpushbutton_rsi_save()\0"
    "onpbtnclicked_mpushbutton_rsi_savedone()\0"
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
    "oncheckboxclicked_mcheckbox_plaser_status_on()\0"
    "oncheckboxclicked_mcheckbox_plaser_status_off()\0"
    "onpbtnclicked_mpushbutton_plaser_zero()\0"
    "onpbtnclicked_mpushbutton_plaser_possetting_down()\0"
    "onpbtnclicked_mpushbutton_plaser_possetting_up()\0"
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
        case 0: oncheckboxclicked_checkbox_rsi_on(); break;
        case 1: oncheckboxclicked_checkbox_rsi_off(); break;
        case 2: onpbtnclicked_mpushbutton_rsi_save(); break;
        case 3: onpbtnclicked_mpushbutton_rsi_savedone(); break;
        case 4: onpbtnclicked_mpushbutton_rsi_man_step_up(); break;
        case 5: onpbtnclicked_mpushbutton_rsi_man_step_down(); break;
        case 6: onpbtnclicked_mpushbutton_rsi_man_y_up(); break;
        case 7: onpbtnclicked_mpushbutton_rsi_man_y_down(); break;
        case 8: onpbtnclicked_mpushbutton_rsi_man_z_up(); break;
        case 9: onpbtnclicked_mpushbutton_rsi_man_z_down(); break;
        case 10: oncheckboxclicked_mcheckbox_sri_connect(); break;
        case 11: oncheckboxclicked_mcheckbox_sri_disconnect(); break;
        case 12: oncheckboxclicked_mcheckbox_sri_ask(); break;
        case 13: oncheckboxclicked_mcheckbox_sri_stop(); break;
        case 14: oncheckboxclicked_mcheckbox_sri_status_on(); break;
        case 15: oncheckboxclicked_mcheckbox_sir_status_off(); break;
        case 16: onpbtnclicked_mpushbutton_sri_zero(); break;
        case 17: onpbtnclicked_mpushbutton_sri_fzsetting_up(); break;
        case 18: onpbtnclicked_mpushbutton_sri_fzsetting_down(); break;
        case 19: oncheckboxclicked_mcheckbox_plaser_status_on(); break;
        case 20: oncheckboxclicked_mcheckbox_plaser_status_off(); break;
        case 21: onpbtnclicked_mpushbutton_plaser_zero(); break;
        case 22: onpbtnclicked_mpushbutton_plaser_possetting_down(); break;
        case 23: onpbtnclicked_mpushbutton_plaser_possetting_up(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
