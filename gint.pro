CONFIG -= qt
CONFIG += console
DEFINES += _DEBUG
DEFINES += GTEST
LIBS += -lgtest_main -lgtest -pthread
SOURCES += *.cpp
HEADERS += *.h
