QT += widgets core gui

TARGET = VideoStream
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

# Define OpenCV include and library paths using pkg-config
PKGCONFIG += opencv4
INCLUDEPATH += /usr/include/opencv4
LIBS += `pkg-config --libs opencv4`
SOURCES += main.cpp \
           VideoStream.cpp
           
HEADERS += VideoStream.h
