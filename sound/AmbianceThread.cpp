#include "AmbianceThread.h"
#include "AppStrings.h"
#include <QDebug>

AmbianceThread::AmbianceThread(const AmbianceModel& model)
{
    m_ambiance = std::make_unique<Ambiance>(model);
}

void AmbianceThread::stop()
{
    m_running = false;
}

void AmbianceThread::run()
{
    m_running = true;
    m_ambiance -> play();

    while (m_ambiance -> isPlaying() && m_running)
    {
        if (alGetError() != AL_NO_ERROR)
        {
            qDebug() << Strings::OpenAL_ErrorSoundPlaying;
        }

        QThread::usleep(16);
    }
}
