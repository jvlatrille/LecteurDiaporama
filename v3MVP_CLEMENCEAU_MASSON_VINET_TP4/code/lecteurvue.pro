QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apropos.cpp \
    diaporama.cpp \
    imagedansdiaporama.cpp \
    lecteur.cpp \
    lecteurvue.cpp \
    main.cpp \
    modele.cpp \
    presentation.cpp

HEADERS += \
    apropos.h \
    diaporama.h \
    imagedansdiaporama.h \
    lecteur.h \
    lecteurvue.h \
    modele.h \
    presentation.h

FORMS += \
    apropos.ui \
    lecteurvue.ui \
    lecteurvue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../cartesDisney/Disney_0.gif \
    ../cartesDisney/Disney_0.png \
    ../cartesDisney/Disney_1.gif \
    ../cartesDisney/Disney_10.gif \
    ../cartesDisney/Disney_11.gif \
    ../cartesDisney/Disney_12.gif \
    ../cartesDisney/Disney_13.gif \
    ../cartesDisney/Disney_14.gif \
    ../cartesDisney/Disney_15.gif \
    ../cartesDisney/Disney_16.gif \
    ../cartesDisney/Disney_17.gif \
    ../cartesDisney/Disney_18.gif \
    ../cartesDisney/Disney_19.gif \
    ../cartesDisney/Disney_2.gif \
    ../cartesDisney/Disney_20.gif \
    ../cartesDisney/Disney_21.gif \
    ../cartesDisney/Disney_22.gif \
    ../cartesDisney/Disney_23.gif \
    ../cartesDisney/Disney_24.gif \
    ../cartesDisney/Disney_25.gif \
    ../cartesDisney/Disney_26.gif \
    ../cartesDisney/Disney_27.gif \
    ../cartesDisney/Disney_28.gif \
    ../cartesDisney/Disney_29.gif \
    ../cartesDisney/Disney_3.gif \
    ../cartesDisney/Disney_30.gif \
    ../cartesDisney/Disney_31.gif \
    ../cartesDisney/Disney_32.gif \
    ../cartesDisney/Disney_33.gif \
    ../cartesDisney/Disney_34.gif \
    ../cartesDisney/Disney_35.gif \
    ../cartesDisney/Disney_36.gif \
    ../cartesDisney/Disney_37.gif \
    ../cartesDisney/Disney_38.gif \
    ../cartesDisney/Disney_39.gif \
    ../cartesDisney/Disney_4.gif \
    ../cartesDisney/Disney_40.gif \
    ../cartesDisney/Disney_41.gif \
    ../cartesDisney/Disney_42.gif \
    ../cartesDisney/Disney_43.gif \
    ../cartesDisney/Disney_44.gif \
    ../cartesDisney/Disney_45.gif \
    ../cartesDisney/Disney_46.gif \
    ../cartesDisney/Disney_47.gif \
    ../cartesDisney/Disney_48.gif \
    ../cartesDisney/Disney_49.gif \
    ../cartesDisney/Disney_5.gif \
    ../cartesDisney/Disney_50.gif \
    ../cartesDisney/Disney_51.gif \
    ../cartesDisney/Disney_52.gif \
    ../cartesDisney/Disney_53.gif \
    ../cartesDisney/Disney_6.gif \
    ../cartesDisney/Disney_7.gif \
    ../cartesDisney/Disney_8.gif \
    ../cartesDisney/Disney_9.gif \
    ../cartesDisney/Disney_tapis.gif \
    ../cartesDisney/Disney_tapis.png \
    ../cartesDisney/Disney_tapisOld.png \
    ../cartesDisney/aLire.txt
