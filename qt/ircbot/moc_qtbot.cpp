/****************************************************************************
** Meta object code from reading C++ file 'qtbot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qtbot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtbot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtBot_t {
    QByteArrayData data[10];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtBot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtBot_t qt_meta_stringdata_QtBot = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QtBot"
QT_MOC_LITERAL(1, 6, 4), // "done"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 4), // "read"
QT_MOC_LITERAL(4, 17, 8), // "bconnect"
QT_MOC_LITERAL(5, 26, 5), // "parse"
QT_MOC_LITERAL(6, 32, 4), // "line"
QT_MOC_LITERAL(7, 37, 4), // "send"
QT_MOC_LITERAL(8, 42, 3), // "com"
QT_MOC_LITERAL(9, 46, 5) // "setup"

    },
    "QtBot\0done\0\0read\0bconnect\0parse\0line\0"
    "send\0com\0setup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtBot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void QtBot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtBot *_t = static_cast<QtBot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->read(); break;
        case 2: _t->bconnect(); break;
        case 3: _t->parse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtBot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtBot::done)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtBot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtBot.data,
      qt_meta_data_QtBot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtBot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtBot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtBot.stringdata0))
        return static_cast<void*>(const_cast< QtBot*>(this));
    return QObject::qt_metacast(_clname);
}

int QtBot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtBot::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
