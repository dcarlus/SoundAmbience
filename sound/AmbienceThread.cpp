#include "AmbienceThread.h"
#include "AppStrings.h"
#include <QRandomGenerator>
#include <QDebug>

AmbienceThread::AmbienceThread(const AmbienceModel& model)
{
    m_ambience = std::make_unique<Ambience>(model);
}

void AmbienceThread::stop()
{
    m_running = false;
}

void AmbienceThread::run()
{
    m_running = true;
    m_ambience -> playMainLoopSound();

    while (m_ambience -> isPlaying() && m_running)
    {
        m_ambience -> playAdditionalSound();

        if (alGetError() != AL_NO_ERROR)
        {
            qDebug() << Strings::OpenAL_ErrorSoundPlaying;
        }

        int sleepTime = QRandomGenerator::global() -> bounded(1, 3);
        QThread::sleep(sleepTime);
    }
}
