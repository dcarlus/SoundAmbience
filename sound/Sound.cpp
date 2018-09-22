#include "Sound.h"
#include "AppStrings.h"
#include <sndfile.h>
#include <stdexcept>
#include <QDebug>

Sound::Sound(const QString& filepath)
{
    readFile(filepath);
    fillBuffer();
}

Sound::~Sound()
{
    alDeleteBuffers(1, &m_buffer);
    m_buffer = 0;
}

void Sound::readFile(const QString& filepath)
{
    std::string cppFilePath = filepath.toStdString();

    // Read the sound file using the libsndfile library.
    SF_INFO fileInfos;
    SNDFILE* file = sf_open(cppFilePath.c_str(), SFM_READ, &fileInfos);

    if (!file)
    {
        throw std::runtime_error(Strings::Sound_ErrorLoading.toStdString() + cppFilePath);
    }

    // Get sound informations (samples count and rate).
    m_samplesCount = static_cast<ALuint>(fileInfos.channels * fileInfos.frames);
    m_sampleRate = static_cast<ALuint>(fileInfos.samplerate);
    m_duration = m_samplesCount / m_sampleRate;

    // Get samples.
    m_samples.resize(m_samplesCount);
    if (sf_read_short(file, m_samples.data(), m_samplesCount) < m_samplesCount)
    {
        throw std::runtime_error(Strings::Sound_ErrorSampleCount.toStdString() + cppFilePath);
    }

    // Free file handler.
    sf_close(file);

    switch (fileInfos.channels)
    {
        case 1:
            m_format = AL_FORMAT_MONO16;
            break;
        case 2:
            m_format = AL_FORMAT_STEREO16;
            break;
        default:
            throw std::runtime_error(Strings::Sound_ErrorFormat.toStdString() + cppFilePath);
    }
}

void Sound::fillBuffer()
{
    alGenBuffers(1, &m_buffer);

    alBufferData
    (
        m_buffer,
        m_format,
        m_samples.data(),
        m_samplesCount * sizeof(ALushort),
        m_sampleRate
    );

    if (alGetError() != AL_NO_ERROR)
    {
        throw std::runtime_error(Strings::OpenAL_ErrorSoundBuffer.toStdString());
    }
}
