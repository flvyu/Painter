/****************************************************************************
** Meta object code from reading C++ file 'rectangledialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bitmap/rectangledialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rectangledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RectangleDialog_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RectangleDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RectangleDialog_t qt_meta_stringdata_RectangleDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RectangleDialog"
QT_MOC_LITERAL(1, 16, 7), // "setFill"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "fill"
QT_MOC_LITERAL(4, 30, 8), // "setShape"
QT_MOC_LITERAL(5, 39, 5), // "shape"
QT_MOC_LITERAL(6, 45, 17), // "setRectangleCurve"
QT_MOC_LITERAL(7, 63, 5) // "curve"

    },
    "RectangleDialog\0setFill\0\0fill\0setShape\0"
    "shape\0setRectangleCurve\0curve"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RectangleDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void RectangleDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RectangleDialog *_t = static_cast<RectangleDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFill((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setRectangleCurve((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RectangleDialog::staticMetaObject = {
    { &LineDialog::staticMetaObject, qt_meta_stringdata_RectangleDialog.data,
      qt_meta_data_RectangleDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RectangleDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RectangleDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RectangleDialog.stringdata0))
        return static_cast<void*>(const_cast< RectangleDialog*>(this));
    return LineDialog::qt_metacast(_clname);
}

int RectangleDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LineDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
