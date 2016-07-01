/****************************************************************************
** Meta object code from reading C++ file 'controllerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RGBController/controllerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_controllerWindow_t {
    QByteArrayData data[19];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controllerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controllerWindow_t qt_meta_stringdata_controllerWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "controllerWindow"
QT_MOC_LITERAL(1, 17, 25), // "on_connect_button_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 28), // "on_disconnect_button_clicked"
QT_MOC_LITERAL(4, 73, 30), // "on_refresh_port_button_clicked"
QT_MOC_LITERAL(5, 104, 31), // "on_reload_preset_button_clicked"
QT_MOC_LITERAL(6, 136, 24), // "on_r_slider_valueChanged"
QT_MOC_LITERAL(7, 161, 5), // "value"
QT_MOC_LITERAL(8, 167, 24), // "on_g_slider_valueChanged"
QT_MOC_LITERAL(9, 192, 24), // "on_b_slider_valueChanged"
QT_MOC_LITERAL(10, 217, 21), // "on_red_button_clicked"
QT_MOC_LITERAL(11, 239, 23), // "on_green_button_clicked"
QT_MOC_LITERAL(12, 263, 22), // "on_blue_button_clicked"
QT_MOC_LITERAL(13, 286, 21), // "on_off_button_clicked"
QT_MOC_LITERAL(14, 308, 28), // "on_set_preset_button_clicked"
QT_MOC_LITERAL(15, 337, 39), // "on_presets_dropdown_currentIn..."
QT_MOC_LITERAL(16, 377, 5), // "index"
QT_MOC_LITERAL(17, 383, 29), // "on_preset_save_button_clicked"
QT_MOC_LITERAL(18, 413, 31) // "on_preset_delete_button_clicked"

    },
    "controllerWindow\0on_connect_button_clicked\0"
    "\0on_disconnect_button_clicked\0"
    "on_refresh_port_button_clicked\0"
    "on_reload_preset_button_clicked\0"
    "on_r_slider_valueChanged\0value\0"
    "on_g_slider_valueChanged\0"
    "on_b_slider_valueChanged\0on_red_button_clicked\0"
    "on_green_button_clicked\0on_blue_button_clicked\0"
    "on_off_button_clicked\0"
    "on_set_preset_button_clicked\0"
    "on_presets_dropdown_currentIndexChanged\0"
    "index\0on_preset_save_button_clicked\0"
    "on_preset_delete_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controllerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void controllerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controllerWindow *_t = static_cast<controllerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_connect_button_clicked(); break;
        case 1: _t->on_disconnect_button_clicked(); break;
        case 2: _t->on_refresh_port_button_clicked(); break;
        case 3: _t->on_reload_preset_button_clicked(); break;
        case 4: _t->on_r_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_g_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_b_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_red_button_clicked(); break;
        case 8: _t->on_green_button_clicked(); break;
        case 9: _t->on_blue_button_clicked(); break;
        case 10: _t->on_off_button_clicked(); break;
        case 11: _t->on_set_preset_button_clicked(); break;
        case 12: _t->on_presets_dropdown_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_preset_save_button_clicked(); break;
        case 14: _t->on_preset_delete_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject controllerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_controllerWindow.data,
      qt_meta_data_controllerWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *controllerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controllerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_controllerWindow.stringdata0))
        return static_cast<void*>(const_cast< controllerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int controllerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
