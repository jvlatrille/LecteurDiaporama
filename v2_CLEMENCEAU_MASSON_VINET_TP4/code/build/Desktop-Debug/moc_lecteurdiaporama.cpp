/****************************************************************************
** Meta object code from reading C++ file 'lecteurdiaporama.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lecteurdiaporama.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecteurdiaporama.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lecteurDiaporama_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lecteurDiaporama_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lecteurDiaporama_t qt_meta_stringdata_lecteurDiaporama = {
    {
QT_MOC_LITERAL(0, 0, 16), // "lecteurDiaporama"
QT_MOC_LITERAL(1, 17, 10), // "sl_suivant"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "sl_precedent"
QT_MOC_LITERAL(4, 42, 8), // "sl_pause"
QT_MOC_LITERAL(5, 51, 15), // "sl_chargerDiapo"
QT_MOC_LITERAL(6, 67, 10), // "sl_quitter"
QT_MOC_LITERAL(7, 78, 14), // "sl_enleverDipo"
QT_MOC_LITERAL(8, 93, 20), // "sl_vitesseDefilement"
QT_MOC_LITERAL(9, 114, 11), // "sl_modeAuto"
QT_MOC_LITERAL(10, 126, 13), // "sl_modeManuel"
QT_MOC_LITERAL(11, 140, 10) // "sl_aPropos"

    },
    "lecteurDiaporama\0sl_suivant\0\0sl_precedent\0"
    "sl_pause\0sl_chargerDiapo\0sl_quitter\0"
    "sl_enleverDipo\0sl_vitesseDefilement\0"
    "sl_modeAuto\0sl_modeManuel\0sl_aPropos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lecteurDiaporama[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

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

       0        // eod
};

void lecteurDiaporama::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lecteurDiaporama *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sl_suivant(); break;
        case 1: _t->sl_precedent(); break;
        case 2: _t->sl_pause(); break;
        case 3: _t->sl_chargerDiapo(); break;
        case 4: _t->sl_quitter(); break;
        case 5: _t->sl_enleverDipo(); break;
        case 6: _t->sl_vitesseDefilement(); break;
        case 7: _t->sl_modeAuto(); break;
        case 8: _t->sl_modeManuel(); break;
        case 9: _t->sl_aPropos(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject lecteurDiaporama::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_lecteurDiaporama.data,
    qt_meta_data_lecteurDiaporama,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lecteurDiaporama::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lecteurDiaporama::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lecteurDiaporama.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int lecteurDiaporama::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
