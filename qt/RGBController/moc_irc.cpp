/****************************************************************************
** Meta object code from reading C++ file 'irc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "irc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_irc_t {
    QByteArrayData data[9];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_irc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_irc_t qt_meta_stringdata_irc = {
    {
QT_MOC_LITERAL(0, 0, 3), // "irc"
QT_MOC_LITERAL(1, 4, 7), // "sendcmd"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 3), // "cmd"
QT_MOC_LITERAL(4, 17, 4), // "read"
QT_MOC_LITERAL(5, 22, 3), // "con"
QT_MOC_LITERAL(6, 26, 6), // "handle"
QT_MOC_LITERAL(7, 33, 3), // "str"
QT_MOC_LITERAL(8, 37, 13) // "pingcheckfunc"

    },
    "irc\0sendcmd\0\0cmd\0read\0con\0handle\0str\0"
    "pingcheckfunc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_irc[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void irc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        irc *_t = static_cast<irc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendcmd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->read(); break;
        case 2: _t->con(); break;
        case 3: _t->handle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->pingcheckfunc(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (irc::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&irc::sendcmd)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject irc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_irc.data,
      qt_meta_data_irc,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *irc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *irc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_irc.stringdata0))
        return static_cast<void*>(const_cast< irc*>(this));
    return QObject::qt_metacast(_clname);
}

int irc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void irc::sendcmd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
