#ifndef SOUNDLOADER_H
#define SOUNDLOADER_H

#include <QString>
#include <QVector>
#include <al.h>

///
/// \brief  Sound that can be played.
///
class Sound final
{
    private:
        ///
        /// \brief  Amount of samples in the sound.
        ///
        ALuint m_samplesCount = 0;

        ///
        /// \brief  Sample rate of the sound.
        ///
        ALuint m_sampleRate = 0;

        ///
        /// \brief  Format of the sound (mono or stereo).
        ///
        ALenum m_format = 0;

        ///
        /// \brief  OpenAL buffer the sound is bound to.
        ///
        ALuint m_buffer = 0;

        ///
        /// \brief  Samples as signed 16-bit values (most common case).
        ///
        QVector<ALshort> m_samples;

    public:
        ///
        /// \brief  Open a sound from a file.
        /// \param  filepath    Path of the sound file.
        ///
        Sound(const QString& filepath);

        ///
        /// \brief  Destruction of the sound structure.
        ///
        ~Sound();

        ///
        /// \brief  Get the buffer of the sound. Useful to play the sound.
        /// \return Buffer of the sound.
        ///
        ALuint buffer() const { return m_buffer; }

    private:
        ///
        /// \brief  Read the sound file and extract data.
        /// \param filepath
        ///
        void readFile(const QString& filepath);

        ///
        /// \brief  Fill the OpenAL sound buffer.
        ///
        void fillBuffer();
};

#endif // SOUNDLOADER_H
