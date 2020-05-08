QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ab5067_atm.cpp \
    ab5067_atmwindow.cpp \
    ab5067_atmwithdraw.cpp \
    ab5067_balancewindow.cpp \
    ab5067_bank.cpp \
    ab5067_bankatm.cpp \
    ab5067_bankwindow.cpp \
    ab5067_customer.cpp \
    ab5067_depositwindow.cpp \
    ab5067_mainwindow.cpp \
    ab5067_transferdirection.cpp \
    ab5067_withdrawwindow.cpp \
    main.cpp

HEADERS += \
    ab5067_atm.h \
    ab5067_atmwindow.h \
    ab5067_atmwithdraw.h \
    ab5067_balancewindow.h \
    ab5067_bank.h \
    ab5067_bankatm.h \
    ab5067_bankwindow.h \
    ab5067_customer.h \
    ab5067_depositwindow.h \
    ab5067_mainwindow.h \
    ab5067_transferdirection.h \
    ab5067_withdrawwindow.h

FORMS += \
    ab5067_atmwindow.ui \
    ab5067_atmwithdraw.ui \
    ab5067_balancewindow.ui \
    ab5067_bankatm.ui \
    ab5067_bankwindow.ui \
    ab5067_depositwindow.ui \
    ab5067_mainwindow.ui \
    ab5067_transferdirection.ui \
    ab5067_withdrawwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
