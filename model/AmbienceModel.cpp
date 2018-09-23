#include "AmbienceModel.h"
#include "AmbienceSchema_generated.h"
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QDir>
#include <QDebug>

void AmbienceModel::load(const QString& path)
{
    QFileInfo fileInfo(path);
    QString projectDir = fileInfo.absolutePath() + QDir::separator();

    // Read the binary file.
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray blob = file.readAll();
    file.close();

    auto data = GetAmbienceData(blob.data());
    m_mainSoundLoopPath = projectDir + QString::fromStdString(data -> mainSoundLoopPath() -> str());

    for (auto path : (*(data -> additionalSoundPaths())))
    {
        QString soundPath = projectDir + QString::fromStdString(path -> str());
        m_additionalSoundPaths.append(soundPath);
    }
}

void AmbienceModel::save(const QString& path)
{
    QFileInfo fileInfo(path);
    QDir saveDir = fileInfo.absoluteDir();

    // Create the buffer builder that will contain all the buffers that will be
    // created to save data. Its original size is 1024 bytes but it will
    // automatically grow if required.
    flatbuffers::FlatBufferBuilder builder(1024);

    // Create the ambience data filling the values.
    std::vector<flatbuffers::Offset<flatbuffers::String>> fbAdditionalSounds;
    for (QString soundPath : m_additionalSoundPaths)
    {
        QString relativePath = saveDir.relativeFilePath(soundPath);
        auto fbSoundPath = builder.CreateString(relativePath.toStdString());
        fbAdditionalSounds.push_back(fbSoundPath);
    }

    QString relativeMainLoopPath = saveDir.relativeFilePath(m_mainSoundLoopPath);
    auto mainLoop = builder.CreateString(relativeMainLoopPath.toStdString());
    auto additionalSounds = builder.CreateVector
    (
        fbAdditionalSounds.data(),
        fbAdditionalSounds.size()
    );
    auto data = CreateAmbienceData(builder, mainLoop, additionalSounds);

    // Make the buffer ready to be written on disk.
    builder.Finish(data);

    // Get binary data to be saved.
    char* buffer = reinterpret_cast<char*>(builder.GetBufferPointer());
    int bufferSize = builder.GetSize();

    // Write the binary file.
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    file.write(buffer, bufferSize);
    file.close();

    m_projectPath = path;
}

void AmbienceModel::clearProject()
{
    m_projectPath = QString();
    clearMainSoundLoopPath();
    clearAdditionalSoundPaths();
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
