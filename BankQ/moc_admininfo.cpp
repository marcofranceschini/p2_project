/****************************************************************************
** Meta object code from reading C++ file 'admininfo.h'
**
** Created: Wed Aug 31 16:28:01 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "admininfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admininfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdminInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      37,   10,   10,   10, 0x08,
      61,   10,   10,   10, 0x08,
      87,   10,   10,   10, 0x08,
     113,   10,   10,   10, 0x08,
     139,   10,   10,   10, 0x08,
     171,  165,   10,   10, 0x08,
     205,   10,   10,   10, 0x08,
     231,  165,   10,   10, 0x08,
     270,   10,   10,   10, 0x08,
     296,   10,   10,   10, 0x08,
     320,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdminInfo[] = {
    "AdminInfo\0\0on_toolButton_2_clicked()\0"
    "on_toolButton_clicked()\0"
    "on_toolButton_3_clicked()\0"
    "on_toolButton_4_clicked()\0"
    "on_toolButton_5_clicked()\0"
    "on_toolButton_6_clicked()\0index\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_toolButton_7_clicked()\0"
    "on_comboBox_5_currentIndexChanged(int)\0"
    "on_toolButton_8_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

void AdminInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdminInfo *_t = static_cast<AdminInfo *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_2_clicked(); break;
        case 1: _t->on_toolButton_clicked(); break;
        case 2: _t->on_toolButton_3_clicked(); break;
        case 3: _t->on_toolButton_4_clicked(); break;
        case 4: _t->on_toolButton_5_clicked(); break;
        case 5: _t->on_toolButton_6_clicked(); break;
        case 6: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_toolButton_7_clicked(); break;
        case 8: _t->on_comboBox_5_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_toolButton_8_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdminInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdminInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AdminInfo,
      qt_meta_data_AdminInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdminInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdminInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdminInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdminInfo))
        return static_cast<void*>(const_cast< AdminInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int AdminInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
