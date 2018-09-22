#ifndef SOUNDSOURCEPARAMETERS_H
#define SOUNDSOURCEPARAMETERS_H

#include <QString>

///
/// \brief  Parameters for a sound source.
///
struct SoundSourceParameters final
{
    public:
        ///
        /// \brief  ID of the sound source.
        ///
        int32_t ID;

        ///
        /// \brief  Path to the sound file.
        ///
        QString SoundPath;
};

#endif // SOUNDSOURCEPARAMETERS_H
