QT += core gui widgets multimedia

CONFIG += c++11 console warn_on debug

SOURCES += \
    main.cpp \
    ccherointerface.cpp \
    QMNote.cpp \
    Chart.cpp \
    Communication.cpp \
    Editor.cpp \
    MChord.cpp \
    Stage.cpp \
    include/serial/SerialPort.cpp

HEADERS += \
    ccherointerface.h \
    QMNote.h \
    Chart.h \
    Communication.h \
    Editor.h \
    MChord.h \
    Stage.h \
    include/json.hpp \
    include/serial/SerialPort.hpp
