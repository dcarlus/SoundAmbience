#include "AmbienceModel.h"

bool AmbienceModel::defineMainSoundLoopPath(const QString& path)
{
    bool validPath = !path.isEmpty() && !m_additionalSoundPaths.contains(path);

    if (validPath)
    {
        m_mainSoundLoopPath = path;
    }

    return validPath;
}

bool AmbienceModel::addAdditionalSoundPath(const QString& path)
{
    bool alreadyInside = m_additionalSoundPaths.contains(path);
    bool alreadyMainLoop = path == m_mainSoundLoopPath;

    if (!alreadyInside && !alreadyMainLoop)
    {
        m_additionalSoundPaths.append(path);
    }

    return !alreadyInside;
}

void AmbienceModel::removeAdditionalSoundPath(const int index)
{
    if (m_additionalSoundPaths.size() > index)
    {
        m_additionalSoundPaths.removeAt(index);
    }
}
