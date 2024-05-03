/****************************************************************************
** Meta object code from reading C++ file 'lecteurvue.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lecteurvue.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecteurvue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSlecteurVueENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSlecteurVueENDCLASS = QtMocHelpers::stringData(
    "lecteurVue",
    "sl_suivant",
    "",
    "sl_precedent",
    "sl_pause",
    "sl_chargerDiapo",
    "sl_quitter",
    "sl_enleverDiapo",
    "sl_vitesseDefilement",
    "sl_modeAuto",
    "sl_modeManuel",
    "sl_aPropos"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlecteurVueENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x0a,    3 /* Public */,
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    0,   78,    2, 0x0a,    5 /* Public */,
       7,    0,   79,    2, 0x0a,    6 /* Public */,
       8,    0,   80,    2, 0x0a,    7 /* Public */,
       9,    0,   81,    2, 0x0a,    8 /* Public */,
      10,    0,   82,    2, 0x0a,    9 /* Public */,
      11,    0,   83,    2, 0x0a,   10 /* Public */,

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

Q_CONSTINIT const QMetaObject lecteurVue::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSlecteurVueENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlecteurVueENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlecteurVueENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<lecteurVue, std::true_type>,
        // method 'sl_suivant'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_precedent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_chargerDiapo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_quitter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_enleverDiapo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_vitesseDefilement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_modeAuto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_modeManuel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sl_aPropos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void lecteurVue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lecteurVue *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sl_suivant(); break;
        case 1: _t->sl_precedent(); break;
        case 2: _t->sl_pause(); break;
        case 3: _t->sl_chargerDiapo(); break;
        case 4: _t->sl_quitter(); break;
        case 5: _t->sl_enleverDiapo(); break;
        case 6: _t->sl_vitesseDefilement(); break;
        case 7: _t->sl_modeAuto(); break;
        case 8: _t->sl_modeManuel(); break;
        case 9: _t->sl_aPropos(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *lecteurVue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lecteurVue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlecteurVueENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int lecteurVue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
