/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../demoRMR/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[46];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 15), // "uiValuesChanged"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 9), // "newrobotX"
QT_MOC_LITERAL(38, 9), // "newrobotY"
QT_MOC_LITERAL(48, 10), // "newrobotFi"
QT_MOC_LITERAL(59, 11), // "phiFeedback"
QT_MOC_LITERAL(71, 16), // "distanceFeedback"
QT_MOC_LITERAL(88, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(112, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(136, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(160, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(184, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(208, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(232, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(254, 11), // "getNewFrame"
QT_MOC_LITERAL(266, 11), // "positioning"
QT_MOC_LITERAL(278, 11), // "coordinates"
QT_MOC_LITERAL(290, 14), // "setCoordinates"
QT_MOC_LITERAL(305, 11), // "setUiValues"
QT_MOC_LITERAL(317, 6), // "robotX"
QT_MOC_LITERAL(324, 6), // "robotY"
QT_MOC_LITERAL(331, 7) // "robotFi"

    },
    "MainWindow\0uiValuesChanged\0\0newrobotX\0"
    "newrobotY\0newrobotFi\0phiFeedback\0"
    "distanceFeedback\0on_pushButton_9_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_6_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_clicked\0"
    "getNewFrame\0positioning\0coordinates\0"
    "setCoordinates\0setUiValues\0robotX\0"
    "robotY\0robotFi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,   86,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   97,    2, 0x08,    6 /* Private */,
       9,    0,   98,    2, 0x08,    7 /* Private */,
      10,    0,   99,    2, 0x08,    8 /* Private */,
      11,    0,  100,    2, 0x08,    9 /* Private */,
      12,    0,  101,    2, 0x08,   10 /* Private */,
      13,    0,  102,    2, 0x08,   11 /* Private */,
      14,    0,  103,    2, 0x08,   12 /* Private */,
      15,    0,  104,    2, 0x08,   13 /* Private */,
      16,    1,  105,    2, 0x08,   14 /* Private */,
      18,    0,  108,    2, 0x08,   16 /* Private */,
      19,    5,  109,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Float, QMetaType::Float,    3,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 17,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Float, QMetaType::Float,   20,   21,   22,    6,    7,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->uiValuesChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 1: _t->on_pushButton_9_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->getNewFrame(); break;
        //case 9: { bool _r = _t->positioning((*reinterpret_cast< coordinates(*)>(_a[1])));
          //  if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        //case 10: _t->setCoordinates(); break;
        case 11: _t->setUiValues((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(double , double , double , float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::uiValuesChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<coordinates, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>


>,
    nullptr
} };


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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::uiValuesChanged(double _t1, double _t2, double _t3, float _t4, float _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
