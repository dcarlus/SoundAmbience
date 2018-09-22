#ifndef AMBIANCE_H
#define AMBIANCE_H

#include "OpenAL.h"
#include "model/AmbianceModel.h"
#include "SoundSource.h"
#include "Sound.h"

#include <vector>
#include <memory>

///
/// \brief  Sound ambiance.
///
class Ambiance final
{
    private:
        ///
        /// \brief  Ambiance is playing if true; stopped if false.
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

    public:
        ///
        /// \brief  Create a new sound ambiance.
        /// \param  model   Model containing all the paths to sound files.
        ///
        Ambiance(const AmbianceModel& model);

        ///
        /// \brief  Play the sound ambiance.
        ///
        void play();

        ///
        /// \brief  Stop the sound ambiance.
        ///
        void stop();

        ///
        /// \brief  Check if the sound ambiance is playing.
        ///
        bool isPlaying() const;
};

#endif // AMBIANCE_H
