#include "SoundSource.h"
#include <QDateTime>
#include <QRandomGenerator>

SoundSource::SoundSource(const QString& soundPath)
{
    m_sound = std::make_unique<Sound>(soundPath);
    alGenSources(1, &m_source);

    // Attach the sound buffer to the source.
    alSourcei(m_source, AL_BUFFER, m_sound -> buffer());
}

SoundSource::SoundSource(const SoundSourceParameters& params)
    : SoundSource(params.SoundPath)
{
    m_id = params.ID;
}

SoundSource::~SoundSource()
{
    alSourcei(m_source, AL_BUFFER, 0);
    alDeleteSources(1, &m_source);
    m_source = 0;
}

void SoundSource::play()
{
    qint64 currentTimestamp = QDateTime::currentDateTime().toSecsSinceEpoch();

    if (m_nextPlayTime > currentTimestamp)
    {
        return;
    }

    m_lastPlayedTime = currentTimestamp;

    ALdouble randomExtraPauseRatio = QRandomGenerator::global() -> generateDouble();
    int32_t duration = m_sound -> duration();
    m_nextPlayTime = m_lastPlayedTime + duration + (duration * randomExtraPauseRatio);

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
