#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T09:24:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoundAmbience
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
    LIBS += -L$$PWD/lib/OpenAL/lib/ -lOpenAL32
    LIBS += -L$$PWD/lib/libsndfile/lib/ -llibsndfile-1

    INCLUDEPATH += $$PWD/lib/OpenAL/include \
                    $$PWD/lib/libsndfile/include \
                    $$PWD/lib/FlatBuffers/include
    DEPENDPATH += $$PWD/lib/OpenAL/include \
                    $$PWD/lib/libsndfile/include \
                    $$PWD/lib/FlatBuffers/include

    RC_FILE = resources/icons/win/win.rc


    # Install dependency DLLs
    Release:DESTDIR = $$OUT_PWD/release/$$OUTPUT_DIRNAME
    Debug:DESTDIR = $$OUT_PWD/debug/$$OUTPUT_DIRNAME

    required_dlls.files += $$PWD/lib/OpenAL/dll/OpenAL32.dll \
                            $$PWD/lib/libsndfile/dll/libsndfile-1.dll
    required_dlls.path = $$DESTDIR
    INSTALLS += required_dlls

    # Run Qt deploy
    QT_BINARIES = $$dirname(QMAKE_QMAKE)
    DEPLOY_COMMAND = $$QT_BINARIES/windeployqt.exe
    DEPLOY_TARGET = $$shell_quote($$shell_path($${DESTDIR}/$${TARGET}.exe))
    QMAKE_POST_LINK = $${DEPLOY_COMMAND} $${DEPLOY_TARGET}
}

linux {
    LIBS += -lopenal -lsndfile -lflatbuffers

    INCLUDEPATH += /usr/include/AL
    DEPENDPATH += /usr/include/AL
}


SOURCES += \
    main.cpp \
    AppStrings.cpp \
    view/SoundSelectionDialog.cpp \
    view/MainWindow.cpp \
    sound/OpenAL.cpp \
    sound/Sound.cpp \
    sound/SoundSource.cpp \
    sound/Ambience.cpp \
    sound/AmbienceThread.cpp \
    model/AmbienceModel.cpp \
    view/MainWindowSlots.cpp \
    view/ProjectSelectionDialog.cpp \
    view/PlayingAmbienceDialog.cpp \
    view/AboutDialog.cpp

HEADERS += \
    AppStrings.h \
    view/SoundSelectionDialog.h \
    view/MainWindow.h \
    sound/OpenAL.h \
    sound/Sound.h \
    sound/SoundSource.h \
    sound/SoundSourceParameters.h \
    sound/Ambience.h \
    sound/AmbienceThread.h \
    model/AmbienceModel.h \
    model/AmbienceSchema_generated.h \
    interfaces/ISerializable.h \
    view/ProjectSelectionDialog.h \
    view/PlayingAmbienceDialog.h \
    view/AboutDialog.h

FORMS += \
    MainWindow.ui \
    PlayingAmbienceDialog.ui \
    AboutDialog.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    model/AmbienceSchema.fbs
