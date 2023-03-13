QT += widgets core gui

CONFIG += c++11
CONFIG -= app_bundle
CONFIG += -Bbuild
CONFIG += -o build

TEMPLATE = app

# Define OpenCV include and library paths using pkg-config
PKGCONFIG += opencv4
INCLUDEPATH += /usr/include/opencv4
LIBS += `pkg-config --libs opencv4`

SRC_DIR = ./src
SOURCES += $$SRC_DIR/main.cpp \
           $$SRC_DIR/VideoPlayer.cpp \
           $$SRC_DIR/VideoVisor.cpp
           
HEADERS_DIR = ./include
INCLUDEPATH += $$HEADERS_DIR
HEADERS += $$HEADERS_DIR/VideoPlayer.h \
		   $$HEADERS_DIR/VideoVisor.h

TARGET_DIR = ../bin
TARGET = videoVisor
TARGET_PATH = $$TARGET_DIR/$$TARGET
TARGET = $$TARGET_PATH

DESTDIR = ./build
OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$OBJECTS_DIR/moc
UI_DIR = $$OBJECTS_DIR/ui
RESOURCES_DIR = $$OBJECTS_DIR

MAKEFILE = ./Makefile

QMAKE_POST_LINK += $$system(mkdir -p $$TARGET_DIR $$DESTDIR)
