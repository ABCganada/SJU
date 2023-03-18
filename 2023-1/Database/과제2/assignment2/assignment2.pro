TEMPLATE = app
TARGET = FileWorker

QT = core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

SOURCES += \
    function.cpp \
    main.cpp

HEADERS += \
    header.h
