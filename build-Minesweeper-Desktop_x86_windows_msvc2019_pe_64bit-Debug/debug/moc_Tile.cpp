/****************************************************************************
** Meta object code from reading C++ file 'Tile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Minesweeper/Tile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tile_t {
    const uint offsetsAndSize[24];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Tile_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Tile_t qt_meta_stringdata_Tile = {
    {
QT_MOC_LITERAL(0, 4), // "Tile"
QT_MOC_LITERAL(5, 11), // "leftPressed"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 12), // "leftReleased"
QT_MOC_LITERAL(31, 12), // "rightPressed"
QT_MOC_LITERAL(44, 13), // "rightReleased"
QT_MOC_LITERAL(58, 19), // "leftPressedRevealed"
QT_MOC_LITERAL(78, 20), // "leftReleasedRevealed"
QT_MOC_LITERAL(99, 15), // "mousePressEvent"
QT_MOC_LITERAL(115, 12), // "QMouseEvent*"
QT_MOC_LITERAL(128, 1), // "e"
QT_MOC_LITERAL(130, 17) // "mouseReleaseEvent"

    },
    "Tile\0leftPressed\0\0leftReleased\0"
    "rightPressed\0rightReleased\0"
    "leftPressedRevealed\0leftReleasedRevealed\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "mouseReleaseEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tile[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    0 /* Public */,
       3,    0,   63,    2, 0x06,    1 /* Public */,
       4,    0,   64,    2, 0x06,    2 /* Public */,
       5,    0,   65,    2, 0x06,    3 /* Public */,
       6,    0,   66,    2, 0x06,    4 /* Public */,
       7,    0,   67,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   68,    2, 0x08,    6 /* Private */,
      11,    1,   71,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Tile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->leftPressed(); break;
        case 1: _t->leftReleased(); break;
        case 2: _t->rightPressed(); break;
        case 3: _t->rightReleased(); break;
        case 4: _t->leftPressedRevealed(); break;
        case 5: _t->leftReleasedRevealed(); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tile::leftPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tile::leftReleased)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tile::rightPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Tile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tile::rightReleased)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Tile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tile::leftPressedRevealed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Tile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tile::leftReleasedRevealed)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Tile::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_Tile.offsetsAndSize,
    qt_meta_data_Tile,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Tile_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tile.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Tile::leftPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tile::leftReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tile::rightPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Tile::rightReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Tile::leftPressedRevealed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Tile::leftReleasedRevealed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
