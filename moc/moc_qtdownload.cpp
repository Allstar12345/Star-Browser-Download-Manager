/****************************************************************************
** Meta object code from reading C++ file 'qtdownload.h'
**
** Created: Sat 16. Aug 12:48:18 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtdownload.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtdownload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtDownload[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      24,   11,   11,   11, 0x05,
      52,   38,   11,   11, 0x05,
      74,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      82,   11,   11,   11, 0x0a,
      98,   93,   11,   11, 0x0a,
     146,  131,   11,   11, 0x0a,
     183,  178,   11,   11, 0x0a,

 // methods: signature, parameters, type, tag, flags
     220,   11,   11,   11, 0x02,
     226,   11,   11,   11, 0x02,
     235,   11,   11,   11, 0x02,
     246,   11,   11,   11, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_QtDownload[] = {
    "QtDownload\0\0showPopup()\0done(QString)\0"
    "currentStatus\0downloadStatus(float)\0"
    "error()\0download()\0data\0"
    "downloadFinished(QNetworkReply*)\0"
    "recieved,total\0downloadProgress(qint64,qint64)\0"
    "code\0onError(QNetworkReply::NetworkError)\0"
    "set()\0cancel()\0openFile()\0remove()\0"
};

const QMetaObject QtDownload::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtDownload,
      qt_meta_data_QtDownload, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtDownload::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtDownload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtDownload::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtDownload))
        return static_cast<void*>(const_cast< QtDownload*>(this));
    return QObject::qt_metacast(_clname);
}

int QtDownload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showPopup(); break;
        case 1: done((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: downloadStatus((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: error(); break;
        case 4: download(); break;
        case 5: downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 7: onError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 8: set(); break;
        case 9: cancel(); break;
        case 10: openFile(); break;
        case 11: remove(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QtDownload::showPopup()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QtDownload::done(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtDownload::downloadStatus(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtDownload::error()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
