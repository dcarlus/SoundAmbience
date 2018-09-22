#ifndef OPENALINITIALIZER_H
#define OPENALINITIALIZER_H

#include <al.h>
#include <alc.h>

///
/// \brief  Class to encapsulate all initialization / destruction of OpenAL
///         devices and context.
///
class OpenAL final
{
    private:
        ///
        /// \brief  Device for OpenAL.
        ///
        ALCdevice* m_device = nullptr;

        ///
        /// \brief  Context of OpenAL.
        ///
        ALCcontext* m_context = nullptr ;

    public:
        ///
        /// \brief  Initialize the OpenAL device and context.
        ///
        OpenAL();

        ///
        /// \brief  Free OpenAL resources.
        ///
        ~OpenAL();
};

#endif // OPENALINITIALIZER_H
