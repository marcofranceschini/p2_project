/****************************************************************************
** Meta object code from reading C++ file 'userinfo.h'
**
** Created: Wed Aug 31 16:28:02 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,
      62,    9,    9,    9, 0x08,
      89,    9,    9,    9, 0x08,
     113,    9,    9,    9, 0x08,
     139,    9,    9,    9, 0x08,
     171,  165,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UserInfo[] = {
    "UserInfo\0\0on_toolButton_3_clicked()\0"
    "on_toolButton_4_clicked()\0"
    "on_toolButton_13_clicked()\0"
    "on_toolButton_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_5_clicked()\0index\0"
    "on_tableView_clicked(QModelIndex)\0"
};

void UserInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserInfo *_t = static_cast<UserInfo *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_3_clicked(); break;
        case 1: _t->on_toolButton_4_clicked(); break;
        case 2: _t->on_toolButton_13_clicked(); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->on_toolButton_2_clicked(); break;
        case 5: _t->on_toolButton_5_clicked(); break;
        case 6: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserInfo,
      qt_meta_data_UserInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserInfo))
        return static_cast<void*>(const_cast< UserInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
