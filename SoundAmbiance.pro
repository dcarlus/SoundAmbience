#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T09:24:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoundAmbiance
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


win32 {
    contains(QT_ARCH, i386) {
        LIBS += -L$$PWD/../lib/OpenAL/lib/Win32/ -lOpenAL32
        LIBS += -L$$PWD/../lib/libsndfile/lib/Win32/ -llibsndfile-1
    } else {
        LIBS += -L$$PWD/../lib/OpenAL/lib/Win64/ -lOpenAL32
        LIBS += -L$$PWD/../lib/libsndfile/lib/Win64/ -llibsndfile-1
    }

    INCLUDEPATH += $$PWD/../lib/OpenAL/include $$PWD/../lib/libsndfile/include
    DEPENDPATH += $$PWD/../lib/OpenAL/include $$PWD/../lib/libsndfile/include
}


SOURCES += \
    main.cpp \
    AppStrings.cpp \
    view/SoundSelectionDialog.cpp \
    view/MainWindow.cpp \
    model/AmbianceModel.cpp \
    sound/OpenAL.cpp \
    sound/Sound.cpp \
    sound/SoundSource.cpp \
    sound/Ambiance.cpp \
    sound/AmbianceThread.cpp

HEADERS += \
    AppStrings.h \
    view/SoundSelectionDialog.h \
    view/MainWindow.h \
    model/AmbianceModel.h \
    sound/OpenAL.h \
    sound/Sound.h \
    sound/SoundSource.h \
    sound/Ambiance.h \
    sound/AmbianceThread.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    icons.qrc
