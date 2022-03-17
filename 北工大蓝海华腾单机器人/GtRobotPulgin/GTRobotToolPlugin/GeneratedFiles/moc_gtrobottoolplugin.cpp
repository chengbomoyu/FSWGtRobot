/****************************************************************************
** Meta object code from reading C++ file 'gtrobottoolplugin.h'
**
** Created: Thu Mar 17 16:09:09 2022
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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      44,    4,    4,    4, 0x0a,
      84,    4,    4,    4, 0x0a,
     132,    4,    4,    4, 0x0a,
     182,    4,    4,    4, 0x0a,
     228,    4,    4,    4, 0x0a,
     272,    4,    4,    4, 0x0a,
     318,    4,    4,    4, 0x0a,
     359,    4,    4,    4, 0x0a,
     402,    4,    4,    4, 0x0a,
     443,    4,    4,    4, 0x0a,
     486,    4,    4,    4, 0x0a,
     528,    4,    4,    4, 0x0a,
     566,    4,    4,    4, 0x0a,
     610,    4,    4,    4, 0x0a,
     647,    4,    4,    4, 0x0a,
     692,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FSW[] = {
    "FSW\0\0onpbtnclicked_mpushbutton_spindle_on()\0"
    "onpbtnclicked_mpushbutton_spindle_off()\0"
    "onpbtnclicked_mpushbutton_spindle_speed_up100()\0"
    "onpbtnclicked_mpushbutton_spindle_speed_down100()\0"
    "onpbtnclicked_mpushbutton_offset_status_set()\0"
    "onpbtnclicked_mpushbutton_rsi_man_step_up()\0"
    "onpbtnclicked_mpushbutton_rsi_man_step_down()\0"
    "onpbtnclicked_mpushbutton_rsi_man_y_up()\0"
    "onpbtnclicked_mpushbutton_rsi_man_y_down()\0"
    "onpbtnclicked_mpushbutton_rsi_man_z_up()\0"
    "onpbtnclicked_mpushbutton_rsi_man_z_down()\0"
    "oncheckboxclicked_mcheckbox_sri_connect()\0"
    "oncheckboxclicked_mcheckbox_sri_ask()\0"
    "oncheckboxclicked_mcheckbox_sri_status_on()\0"
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
        case 0: onpbtnclicked_mpushbutton_spindle_on(); break;
        case 1: onpbtnclicked_mpushbutton_spindle_off(); break;
        case 2: onpbtnclicked_mpushbutton_spindle_speed_up100(); break;
        case 3: onpbtnclicked_mpushbutton_spindle_speed_down100(); break;
        case 4: onpbtnclicked_mpushbutton_offset_status_set(); break;
        case 5: onpbtnclicked_mpushbutton_rsi_man_step_up(); break;
        case 6: onpbtnclicked_mpushbutton_rsi_man_step_down(); break;
        case 7: onpbtnclicked_mpushbutton_rsi_man_y_up(); break;
        case 8: onpbtnclicked_mpushbutton_rsi_man_y_down(); break;
        case 9: onpbtnclicked_mpushbutton_rsi_man_z_up(); break;
        case 10: onpbtnclicked_mpushbutton_rsi_man_z_down(); break;
        case 11: oncheckboxclicked_mcheckbox_sri_connect(); break;
        case 12: oncheckboxclicked_mcheckbox_sri_ask(); break;
        case 13: oncheckboxclicked_mcheckbox_sri_status_on(); break;
        case 14: onpbtnclicked_mpushbutton_sri_zero(); break;
        case 15: onpbtnclicked_mpushbutton_sri_fzsetting_up(); break;
        case 16: onpbtnclicked_mpushbutton_sri_fzsetting_down(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
