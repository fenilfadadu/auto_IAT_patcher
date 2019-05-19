/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../patcher/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadCounter_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadCounter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadCounter_t qt_meta_stringdata_ThreadCounter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ThreadCounter"
QT_MOC_LITERAL(1, 14, 14), // "counterChanged"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "ThreadCounter\0counterChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadCounter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ThreadCounter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadCounter *_t = static_cast<ThreadCounter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->counterChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ThreadCounter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadCounter::counterChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ThreadCounter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadCounter.data,
      qt_meta_data_ThreadCounter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ThreadCounter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadCounter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadCounter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadCounter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ThreadCounter::counterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[40];
    char stringdata0[575];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "exeSelected"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "ExeHandler*"
QT_MOC_LITERAL(4, 36, 3), // "exe"
QT_MOC_LITERAL(5, 40, 10), // "exeUpdated"
QT_MOC_LITERAL(6, 51, 13), // "hookRequested"
QT_MOC_LITERAL(7, 65, 13), // "thunkSelected"
QT_MOC_LITERAL(8, 79, 8), // "offset_t"
QT_MOC_LITERAL(9, 88, 5), // "thunk"
QT_MOC_LITERAL(10, 94, 19), // "replacementAccepted"
QT_MOC_LITERAL(11, 114, 10), // "filterLibs"
QT_MOC_LITERAL(12, 125, 3), // "str"
QT_MOC_LITERAL(13, 129, 11), // "filterFuncs"
QT_MOC_LITERAL(14, 141, 10), // "takeAction"
QT_MOC_LITERAL(15, 152, 20), // "loadingStatusChanged"
QT_MOC_LITERAL(16, 173, 15), // "onLoadingFailed"
QT_MOC_LITERAL(17, 189, 8), // "fileName"
QT_MOC_LITERAL(18, 198, 9), // "selectExe"
QT_MOC_LITERAL(19, 208, 14), // "refreshExeView"
QT_MOC_LITERAL(20, 223, 19), // "customMenuRequested"
QT_MOC_LITERAL(21, 243, 3), // "pos"
QT_MOC_LITERAL(22, 247, 22), // "functionsMenuRequested"
QT_MOC_LITERAL(23, 270, 15), // "onHookRequested"
QT_MOC_LITERAL(24, 286, 7), // "exeHndl"
QT_MOC_LITERAL(25, 294, 17), // "updateReplacement"
QT_MOC_LITERAL(26, 312, 7), // "libName"
QT_MOC_LITERAL(27, 320, 8), // "funcName"
QT_MOC_LITERAL(28, 329, 20), // "onExportReplacements"
QT_MOC_LITERAL(29, 350, 20), // "onImportReplacements"
QT_MOC_LITERAL(30, 371, 16), // "setThunkSelected"
QT_MOC_LITERAL(31, 388, 22), // "onLoaderThreadFinished"
QT_MOC_LITERAL(32, 411, 14), // "rowChangedSlot"
QT_MOC_LITERAL(33, 426, 7), // "openExe"
QT_MOC_LITERAL(34, 434, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(35, 456, 23), // "on_reloadButton_clicked"
QT_MOC_LITERAL(36, 480, 25), // "on_clearAllButton_clicked"
QT_MOC_LITERAL(37, 506, 21), // "on_hookButton_clicked"
QT_MOC_LITERAL(38, 528, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(39, 550, 24) // "on_actionAbout_triggered"

    },
    "MainWindow\0exeSelected\0\0ExeHandler*\0"
    "exe\0exeUpdated\0hookRequested\0thunkSelected\0"
    "offset_t\0thunk\0replacementAccepted\0"
    "filterLibs\0str\0filterFuncs\0takeAction\0"
    "loadingStatusChanged\0onLoadingFailed\0"
    "fileName\0selectExe\0refreshExeView\0"
    "customMenuRequested\0pos\0functionsMenuRequested\0"
    "onHookRequested\0exeHndl\0updateReplacement\0"
    "libName\0funcName\0onExportReplacements\0"
    "onImportReplacements\0setThunkSelected\0"
    "onLoaderThreadFinished\0rowChangedSlot\0"
    "openExe\0on_pushButton_clicked\0"
    "on_reloadButton_clicked\0"
    "on_clearAllButton_clicked\0"
    "on_hookButton_clicked\0on_saveButton_clicked\0"
    "on_actionAbout_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       5,    1,  157,    2, 0x06 /* Public */,
       6,    1,  160,    2, 0x06 /* Public */,
       7,    1,  163,    2, 0x06 /* Public */,
      10,    0,  166,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  167,    2, 0x08 /* Private */,
      13,    1,  170,    2, 0x08 /* Private */,
      14,    0,  173,    2, 0x08 /* Private */,
      15,    0,  174,    2, 0x08 /* Private */,
      16,    1,  175,    2, 0x08 /* Private */,
      18,    1,  178,    2, 0x08 /* Private */,
      19,    1,  181,    2, 0x08 /* Private */,
      20,    1,  184,    2, 0x08 /* Private */,
      22,    1,  187,    2, 0x08 /* Private */,
      23,    1,  190,    2, 0x08 /* Private */,
      25,    2,  193,    2, 0x08 /* Private */,
      28,    1,  198,    2, 0x08 /* Private */,
      29,    1,  201,    2, 0x08 /* Private */,
      30,    1,  204,    2, 0x08 /* Private */,
      31,    0,  207,    2, 0x08 /* Private */,
      32,    2,  208,    2, 0x08 /* Private */,
      33,    0,  213,    2, 0x08 /* Private */,
      34,    0,  214,    2, 0x08 /* Private */,
      35,    0,  215,    2, 0x08 /* Private */,
      36,    0,  216,    2, 0x08 /* Private */,
      37,    0,  217,    2, 0x08 /* Private */,
      38,    0,  218,    2, 0x08 /* Private */,
      39,    0,  219,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void, 0x80000000 | 3,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   26,   27,
    QMetaType::Void, 0x80000000 | 3,   24,
    QMetaType::Void, 0x80000000 | 3,   24,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exeSelected((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 1: _t->exeUpdated((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 2: _t->hookRequested((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 3: _t->thunkSelected((*reinterpret_cast< offset_t(*)>(_a[1]))); break;
        case 4: _t->replacementAccepted(); break;
        case 5: _t->filterLibs((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->filterFuncs((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->takeAction(); break;
        case 8: _t->loadingStatusChanged(); break;
        case 9: _t->onLoadingFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->selectExe((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 11: _t->refreshExeView((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 12: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 13: _t->functionsMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 14: _t->onHookRequested((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 15: _t->updateReplacement((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->onExportReplacements((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 17: _t->onImportReplacements((*reinterpret_cast< ExeHandler*(*)>(_a[1]))); break;
        case 18: _t->setThunkSelected((*reinterpret_cast< offset_t(*)>(_a[1]))); break;
        case 19: _t->onLoaderThreadFinished(); break;
        case 20: _t->rowChangedSlot((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 21: _t->openExe(); break;
        case 22: _t->on_pushButton_clicked(); break;
        case 23: _t->on_reloadButton_clicked(); break;
        case 24: _t->on_clearAllButton_clicked(); break;
        case 25: _t->on_hookButton_clicked(); break;
        case 26: _t->on_saveButton_clicked(); break;
        case 27: _t->on_actionAbout_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
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
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ExeHandler* >(); break;
            }
            break;
        case 17:
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
            typedef void (MainWindow::*_t)(ExeHandler * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::exeSelected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(ExeHandler * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::exeUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(ExeHandler * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hookRequested)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(offset_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::thunkSelected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::replacementAccepted)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::exeSelected(ExeHandler * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::exeUpdated(ExeHandler * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::hookRequested(ExeHandler * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::thunkSelected(offset_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::replacementAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
