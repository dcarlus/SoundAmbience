#ifndef SOUNDSOURCE_H
#define SOUNDSOURCE_H

#include "Sound.h"
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
        /// \brief  ID of the OpenAL sound.
        ///
        ALuint m_source = 0;

        ///
        /// \brief  Sound the source can play.
        ///
        std::unique_ptr<Sound> m_sound;

    public:
        ///
        /// \brief  Create a new sound source.
        /// \param  soundPath   Path to the sound file used by the source.
        ///
        SoundSource(const QString& soundPath);

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
};

#endif // SOUNDSOURCE_H
