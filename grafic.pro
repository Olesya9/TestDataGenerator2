QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Desktop/TestDataGenerator/DataGenerator.cpp \
    ../../Desktop/TestDataGenerator/HarmonicMotionDataGenerator.cpp \
    ../../Desktop/TestDataGenerator/abstactfactory.cpp \
    ../../Desktop/TestDataGenerator/basecontroller.cpp \
    ../../Desktop/TestDataGenerator/dataGetter.cpp \
    ../../Desktop/TestDataGenerator/harmoniccontroller.cpp \
    ../../Desktop/TestDataGenerator/harmonicdata.cpp \
    ../../Desktop/TestDataGenerator/harmonicfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../../Desktop/TestDataGenerator/DataGenerator.h \
    ../../Desktop/TestDataGenerator/HarmonicMotionDataGenerator.h \
    ../../Desktop/TestDataGenerator/abstractfactory.h \
    ../../Desktop/TestDataGenerator/basecontroller.h \
    ../../Desktop/TestDataGenerator/data.h \
    ../../Desktop/TestDataGenerator/dataGetter.h \
    ../../Desktop/TestDataGenerator/harmoniccontroller.h \
    ../../Desktop/TestDataGenerator/harmonicdata.h \
    ../../Desktop/TestDataGenerator/harmonicfactory.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
