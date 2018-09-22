#include "AmbianceThread.h"
#include "AppStrings.h"
#include <QRandomGenerator>
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
    m_ambiance -> playMainLoopSound();

    while (m_ambiance -> isPlaying() && m_running)
    {
        m_ambiance -> playAdditionalSound();

        if (alGetError() != AL_NO_ERROR)
        {
            qDebug() << Strings::OpenAL_ErrorSoundPlaying;
        }

        int sleepTime = QRandomGenerator::global() -> bounded(1, 3);
        QThread::sleep(sleepTime);
    }
}
