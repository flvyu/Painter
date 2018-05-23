/****************************************************************************
** Meta object code from reading C++ file 'linedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bitmap/linedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineDialog_t {
    QByteArrayData data[12];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineDialog_t qt_meta_stringdata_LineDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LineDialog"
QT_MOC_LITERAL(1, 11, 11), // "setJoinType"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "join"
QT_MOC_LITERAL(4, 29, 11), // "setDrawType"
QT_MOC_LITERAL(5, 41, 4), // "draw"
QT_MOC_LITERAL(6, 46, 10), // "setCapType"
QT_MOC_LITERAL(7, 57, 3), // "cap"
QT_MOC_LITERAL(8, 61, 12), // "setLineWidth"
QT_MOC_LITERAL(9, 74, 5), // "width"
QT_MOC_LITERAL(10, 80, 12), // "setStyleType"
QT_MOC_LITERAL(11, 93, 5) // "style"

    },
    "LineDialog\0setJoinType\0\0join\0setDrawType\0"
    "draw\0setCapType\0cap\0setLineWidth\0width\0"
    "setStyleType\0style"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void LineDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineDialog *_t = static_cast<LineDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setJoinType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setDrawType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setCapType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setStyleType((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LineDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LineDialog.data,
      qt_meta_data_LineDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LineDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LineDialog.stringdata0))
        return static_cast<void*>(const_cast< LineDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LineDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
