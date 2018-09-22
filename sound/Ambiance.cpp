#include "Ambiance.h"
#include <utility>

Ambiance::Ambiance(const AmbianceModel& model)
{
    m_mainSource = std::make_unique<SoundSource>(model.mainSoundLoopPath());
    m_mainSource -> setLooping(true);

    for (QString soundPath : model.additionalSounds())
    {
        std::unique_ptr<SoundSource> source = std::make_unique<SoundSource>(soundPath);
        m_additionalSources.push_back(std::move(source));
    }
}

void Ambiance::play()
{
    m_isPlaying = true;
    m_mainSource -> play();
}

void Ambiance::stop()
{
    m_isPlaying = false;
}

bool Ambiance::isPlaying() const
{
    return m_isPlaying;
}
