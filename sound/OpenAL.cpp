#include "OpenAL.h"
#include "AppStrings.h"
#include <stdexcept>
#include <QDebug>

OpenAL::OpenAL()
{
    qDebug() << "Create OpenAL context and device";

    // Initialize the default device.
    m_device = alcOpenDevice(nullptr);

    if (!m_device)
    {
        throw std::runtime_error(Strings::OpenAL_ErrorDeviceInit.toStdString());
    }

    // Initialize the context.
    m_context = alcCreateContext(m_device, nullptr);

    if (!m_context)
    {
        throw std::runtime_error(Strings::OpenAL_ErrorContextInit.toStdString());
    }

    // Use this context.
    if (!alcMakeContextCurrent(m_context))
    {
        throw std::runtime_error(Strings::OpenAL_ErrorSetContext.toStdString());
    }
}

OpenAL::~OpenAL()
{
    qDebug() << "Destroy OpenAL context and device";

    // Do not use the created context anymore.
    alcMakeContextCurrent(nullptr);

    // Free the context data.
    alcDestroyContext(m_context);
    m_context = nullptr ;

    // Free the device data.
    alcCloseDevice(m_device);
    m_device = nullptr ;
}
