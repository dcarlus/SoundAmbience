#include "SoundSource.h"

SoundSource::SoundSource(const QString& soundPath)
{
    m_sound = std::make_unique<Sound>(soundPath);
    alGenSources(1, &m_source);

    // Attach the sound buffer to the source.
    alSourcei(m_source, AL_BUFFER, m_sound -> buffer());
}

SoundSource::~SoundSource()
{
    alSourcei(m_source, AL_BUFFER, 0);
    alDeleteSources(1, &m_source);
    m_source = 0;
}

void SoundSource::play()
{
    alSourcePlay(m_source);
}

void SoundSource::setPosition(const QVector3D& pos)
{
    ALfloat alPos[3] = { pos.x(), pos.y(), pos.z() };
    alSourcefv(m_source, AL_POSITION, alPos);
}

void SoundSource::setLooping(const bool looping)
{
    alSourcei(m_source, AL_LOOPING, looping);
}

bool SoundSource::isPlaying()
{
    ALint status;
    alGetSourcei(m_source, AL_SOURCE_STATE, &status);
    return status == AL_PLAYING;
}
