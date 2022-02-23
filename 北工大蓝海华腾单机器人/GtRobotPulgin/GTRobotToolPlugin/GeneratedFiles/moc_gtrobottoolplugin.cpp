/****************************************************************************
** Meta object code from reading C++ file 'gtrobottoolplugin.h'
**
** Created: Wed Feb 23 14:46:12 2022
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
       5,   14, // methods
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

       0        // eod
};

static const char qt_meta_stringdata_FSW[] = {
    "FSW\0\0onpbpbSpindleConnect()\0"
    "onpbtnclicked_mpushbutton_spindle_on()\0"
    "onpbtnclicked_mpushbutton_spindle_off()\0"
    "onpbtnclicked_mpushbutton_spindle_speed_up100()\0"
    "onpbtnclicked_mpushbutton_spindle_speed_down100()\0"
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
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
