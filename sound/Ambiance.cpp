#include "Ambiance.h"
#include <QRandomGenerator>
#include <QDebug>
#include <utility>

Ambiance::Ambiance(const AmbianceModel& model)
{
    m_mainSource = std::make_unique<SoundSource>(model.mainSoundLoopPath());
    m_mainSource -> setLooping(true);

    int32_t sourceID = 0;
    for (QString soundPath : model.additionalSounds())
    {
        SoundSourceParameters params = { sourceID, soundPath };

        std::unique_ptr<SoundSource> source = std::make_unique<SoundSource>(params);
        m_additionalSources.push_back(std::move(source));
        m_availableSources.push_back(sourceID);

        sourceID++;
    }
}

void Ambiance::playMainLoopSound()
{
    m_isPlaying = true;
    m_mainSource -> play();
}

void Ambiance::playAdditionalSound()
{
    if (!m_isPlaying)
    {
        return ;
    }

    restorePlayedSounds();

    // Play a new sound if the random value is 1.
    int playSoundDecision = QRandomGenerator::global() -> bounded(0, 2);

    if (playSoundDecision == 0)
    {
        return ;
    }

    // Pick a sound that is available (if possible, otherwise return).
    int minIndex = 0;
    int maxIndex = static_cast<int>(m_availableSources.size());

    if (maxIndex == 0)
    {
        return ;
    }

    int sourceIndex = QRandomGenerator::global() -> bounded(minIndex, maxIndex);
    int sourceID = m_availableSources[sourceIndex];

    // Set a random position.
    QVector3D randomPosition
    (
        QRandomGenerator::global() -> bounded(-10, 10),
        QRandomGenerator::global() -> bounded(-10, 10),
        QRandomGenerator::global() -> bounded(-10, 10)
    );
    m_additionalSources[sourceID] -> setPosition(randomPosition);
    m_additionalSources[sourceID] -> play();

    m_availableSources.removeAll(m_additionalSources[sourceID] -> id());
}

void Ambiance::stop()
{
    m_isPlaying = false;
}

bool Ambiance::isPlaying() const
{
    return m_isPlaying;
}

void Ambiance::restorePlayedSounds()
{
    for (std::unique_ptr<SoundSource>& source : m_additionalSources)
    {
        if (!source -> isPlaying())
        {
            m_availableSources.push_back(source -> id());
        }
    }
}
