#ifndef SOUNDSOURCE_H
#define SOUNDSOURCE_H

#include "Sound.h"
#include "SoundSourceParameters.h"
#include <QString>
#include <QVector3D>
#include <memory>
#include <al.h>

///
/// \brief  Source that can play a 3D sound.
///
class SoundSource final
{
    private:
        ///
        /// \brief  ID of the sound source.
        ///
        int32_t m_id = -1;

        ///
        /// \brief  ID of the OpenAL sound.
        ///
        ALuint m_source = 0;

        ///
        /// \brief  Sound the source can play.
        ///
        std::unique_ptr<Sound> m_sound;

        ///
        /// \brief  Time of the last play of the current source.
        ///
        qint64 m_lastPlayedTime = 0;

        ///
        /// \brief  Minimal amount of seconds to wait until the current source
        ///         can be played anymore.
        ///
        qint64 m_nextPlayTime = 0;

    public:
        ///
        /// \brief  Create a new sound source.
        /// \param  soundPath   Path to the sound file used by the source.
        ///
        SoundSource(const QString& soundPath);

        ///
        /// \brief  Create a new sound source.
        /// \param  params  Parameters of the sound source.
        ///
        SoundSource(const SoundSourceParameters& params);

        ///
        /// \brief  Destruction of the sound source structure.
        ///
        ~SoundSource();

        ///
        /// \brief  Play the sound from the current source.
        ///
        void play();

        ///
        /// \brief  Set the position of the source in 3D space.
        /// \param  pos Position of the source in 3D space.
        ///
        void setPosition(const QVector3D& pos);

        ///
        /// \brief  Set sound source looping.
        /// \param  looping true to loop over the sound; false to read once.
        ///
        void setLooping(const bool looping);

        ///
        /// \brief  Get the playing state of the current source.
        /// \return true if the source is playing the attached sound; false
        ///         otherwise.
        ///
        bool isPlaying();

        ///
        /// \brief  Get the source ID.
        /// \return ID of the source.
        ///
        int32_t id() const { return m_id; }
};

#endif // SOUNDSOURCE_H
