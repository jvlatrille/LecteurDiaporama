QT       += core gui
QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apropos.cpp \
    charger.cpp \
    database.cpp \
    diaporama.cpp \
    imagedansdiaporama.cpp \
    lecteur.cpp \
    lecteurvue.cpp \
    main.cpp \
    modele.cpp \
    presentation.cpp \
    vit.cpp

HEADERS += \
    apropos.h \
    charger.h \
    database.h \
    diaporama.h \
    imagedansdiaporama.h \
    lecteur.h \
    lecteurvue.h \
    modele.h \
    presentation.h \
    vit.h

FORMS += \
    apropos.ui \
    charger.ui \
    lecteurvue.ui \
    lecteurvue.ui \
    vit.ui

RESOURCES += \
    ressources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
