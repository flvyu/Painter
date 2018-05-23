HEADERS += my_widget.h \
    paintarea.h \
    paintwindow.h \
    pendialog.h \
    paintPen.h \
    linedialog.h \
    eraserdialog.h \
    rectangledialog.h
SOURCES += my_widget.cpp main.cpp \
    paintarea.cpp \
    paintwindow.cpp \
    pendialog.cpp \
    linedialog.cpp \
    eraserdialog.cpp \
    rectangledialog.cpp
CONFIG += qt warn_on
CONFIG += debug
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RESOURCES += \
    icons.qrc

DISTFILES += \
    ReadMe
