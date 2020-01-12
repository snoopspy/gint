CONFIG -= qt
CONFIG += console
DEFINES += GTEST
LIBS += -lgtest_main -lgtest -pthread
SOURCES += *.cpp
HEADERS += *.h
