/****************************************************************************
** Meta object code from reading C++ file 'paintwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bitmap/paintwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PaintWindow_t {
    QByteArrayData data[19];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaintWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaintWindow_t qt_meta_stringdata_PaintWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PaintWindow"
QT_MOC_LITERAL(1, 12, 4), // "save"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "newImage"
QT_MOC_LITERAL(4, 27, 4), // "open"
QT_MOC_LITERAL(5, 32, 12), // "saveAsBitmap"
QT_MOC_LITERAL(6, 45, 15), // "foregroundColor"
QT_MOC_LITERAL(7, 61, 15), // "backgroundColor"
QT_MOC_LITERAL(8, 77, 4), // "undo"
QT_MOC_LITERAL(9, 82, 4), // "redo"
QT_MOC_LITERAL(10, 87, 10), // "clearImage"
QT_MOC_LITERAL(11, 98, 7), // "penTool"
QT_MOC_LITERAL(12, 106, 5), // "erase"
QT_MOC_LITERAL(13, 112, 9), // "rectangle"
QT_MOC_LITERAL(14, 122, 4), // "line"
QT_MOC_LITERAL(15, 127, 11), // "resizeImage"
QT_MOC_LITERAL(16, 139, 5), // "about"
QT_MOC_LITERAL(17, 145, 11), // "setPenWidth"
QT_MOC_LITERAL(18, 157, 8) // "newWidth"

    },
    "PaintWindow\0save\0\0newImage\0open\0"
    "saveAsBitmap\0foregroundColor\0"
    "backgroundColor\0undo\0redo\0clearImage\0"
    "penTool\0erase\0rectangle\0line\0resizeImage\0"
    "about\0setPenWidth\0newWidth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaintWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void PaintWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PaintWindow *_t = static_cast<PaintWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->newImage(); break;
        case 2: _t->open(); break;
        case 3: _t->saveAsBitmap(); break;
        case 4: _t->foregroundColor(); break;
        case 5: _t->backgroundColor(); break;
        case 6: _t->undo(); break;
        case 7: _t->redo(); break;
        case 8: _t->clearImage(); break;
        case 9: _t->penTool(); break;
        case 10: _t->erase(); break;
        case 11: _t->rectangle(); break;
        case 12: _t->line(); break;
        case 13: _t->resizeImage(); break;
        case 14: _t->about(); break;
        case 15: _t->setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PaintWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PaintWindow.data,
      qt_meta_data_PaintWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PaintWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PaintWindow.stringdata0))
        return static_cast<void*>(const_cast< PaintWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PaintWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
