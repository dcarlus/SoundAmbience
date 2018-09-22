#ifndef AMBIENCE_H
#define AMBIENCE_H

#include "OpenAL.h"
#include "model/AmbienceModel.h"
#include "SoundSource.h"
#include "Sound.h"

#include <QList>
#include <vector>
#include <memory>

///
/// \brief  Sound ambience.
///
class Ambience final
{
    private:
        ///
        /// \brief  Ambience is playing if true; stopped if false.
        ///
        bool m_isPlaying = false;

        ///
        /// \brief  Instance of OpenAL.
        ///
        OpenAL m_alInstance;

        ///
        /// \brief  Main sound source. Played at listener's position in the 3D
        ///         space.
        ///
        std::unique_ptr<SoundSource> m_mainSource;

        ///
        /// \brief  Source list of additional sounds. Played in 3D space.
        ///
        std::vector<std::unique_ptr<SoundSource>> m_additionalSources;

        ///
        /// \brief  ID of sources that are free to be played.
        ///
        QList<int32_t> m_availableSources;

    public:
        ///
        /// \brief  Create a new sound ambience.
        /// \param  model   Model containing all the paths to sound files.
        ///
        Ambience(const AmbienceModel& model);

        ///
        /// \brief  Play the main loop of the sound ambience.
        ///
        void playMainLoopSound();

        ///
        /// \brief  Randomly play an additional sound.
        ///
        void playAdditionalSound();

        ///
        /// \brief  Stop the sound ambience.
        ///
        void stop();

        ///
        /// \brief  Check if the sound ambience is playing.
        ///
        bool isPlaying() const;

    private:
        ///
        /// \brief  Put back sounds that have finished to play as available.
        ///
        void restorePlayedSounds();
};

#endif // AMBIENCE_H
