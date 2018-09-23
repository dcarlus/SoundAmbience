#include "AppStrings.h"
#include <QObject>

namespace Strings
{
    const QString MainWindow_NoSelectedFile = QObject::tr(u8"No selected file...") ;
    const QString MainWindow_SaveAmbience = QObject::tr(u8"Save ambience") ;
    const QString MainWindow_AmbienceProjectFile = QObject::tr(u8"Ambience project (*.ap)") ;

    const QString OpenAL_ErrorDeviceInit = QObject::tr(u8"Unable to initialize OpenAL device.");
    const QString OpenAL_ErrorContextInit = QObject::tr(u8"Unable to initialize OpenAL context.");
    const QString OpenAL_ErrorSetContext = QObject::tr(u8"Error while setting the current OpenAL context.");
    const QString OpenAL_ErrorSoundBuffer = QObject::tr(u8"Error while filling the sound buffer.");
    const QString OpenAL_ErrorSoundPlaying = QObject::tr(u8"Error while playing sound.");

    const QString Sound_ErrorLoading = QObject::tr(u8"Error while loading sound file: ");
    const QString Sound_ErrorSampleCount = QObject::tr(u8"Error while sampling the sound file: ");
    const QString Sound_ErrorFormat = QObject::tr(u8"Unknown sound format for: ");
}
