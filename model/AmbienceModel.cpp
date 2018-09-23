#include "AmbienceModel.h"
#include "AmbienceSchema_generated.h"
#include <QFile>
#include <QDataStream>

void AmbienceModel::load(const QString&)
{

}

void AmbienceModel::save(const QString& path)
{
    // Create the buffer builder that will contain all the buffers that will be
    // created to save data. Its original size is 1024 bytes but it will
    // automatically grow if required.
    flatbuffers::FlatBufferBuilder builder(1024);

    // Create the ambience data filling the values.
    std::vector<flatbuffers::Offset<flatbuffers::String>> fbAdditionalSounds;
    for (QString soundPath : m_additionalSoundPaths)
    {
        auto fbSoundPath = builder.CreateString(soundPath.toStdString());
        fbAdditionalSounds.push_back(fbSoundPath);
    }

    auto mainLoop = builder.CreateString(m_mainSoundLoopPath.toStdString());
    auto additionalSounds = builder.CreateVector(fbAdditionalSounds.data(), fbAdditionalSounds.size());
    auto data = CreateAmbienceData(builder, mainLoop, additionalSounds);

    // Make the buffer ready to be written on disk.
    builder.Finish(data);

    // Get binary data to be saved.
    char* buffer = reinterpret_cast<char*>(builder.GetBufferPointer());
    int bufferSize = builder.GetSize();

    // Write the binary file.
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out.writeBytes(buffer, bufferSize);
    file.close();

    m_projectPath = path;
}

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
