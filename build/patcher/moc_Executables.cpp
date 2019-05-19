/****************************************************************************
** Meta object code from reading C++ file 'Executables.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../patcher/Executables.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Executables.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Executables_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Executables_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Executables_t qt_meta_stringdata_Executables = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Executables"
QT_MOC_LITERAL(1, 12, 14), // "exeListChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "addExe"
QT_MOC_LITERAL(4, 35, 11), // "ExeHandler*"
QT_MOC_LITERAL(5, 47, 3), // "exe"
QT_MOC_LITERAL(6, 51, 9), // "removeExe"
QT_MOC_LITERAL(7, 61, 5), // "clear"
QT_MOC_LITERAL(8, 67, 19) // "onChildStateChanged"

    },
    "Executables\0exeListChanged\0\0addExe\0"
    "ExeHandler*\0exe\0removeExe\0clear\0"
    "onChildStateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Executables[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Executables::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Executables *_t = static_cast<Executables *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exeListChanged(); break;
        case 1: _t->addExe((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 2: _t->removeExe((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 3: _t->clear(); break;
        case 4: _t->onChildStateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Executables::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Executables::exeListChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Executables::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Executables.data,
      qt_meta_data_Executables,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Executables::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Executables::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Executables.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Executables::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Executables::exeListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
