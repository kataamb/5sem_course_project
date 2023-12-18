QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app_facade.cpp \
    cylinder.cpp \
    main.cpp \
    mainwindow.cpp \
    parallelepiped.cpp \
    polygonmodel.cpp \
    visualize_builder.cpp

HEADERS += \
    app_facade.h \
    cylinder.h \
    mainwindow.h \
    parallelepiped.h \
    polygonmodel.h \
    visualize_builder.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
