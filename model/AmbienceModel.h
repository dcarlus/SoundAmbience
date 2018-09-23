#ifndef MODELAMBIENCEMODEL_H
#define MODELAMBIENCEMODEL_H

#include "interfaces/ISerializable.h"
#include <QString>
#include <QVector>

///
/// \brief  A very simple model implementation bypassing all sugar required by
///         Qt because it is quite boring for just some strings!
///
class AmbienceModel final : public ISerializable
{
    private:
        ///
        /// \brief  Path to the project of the ambience.
        ///
        QString m_projectPath;

        ///
        /// \brief  Path to the main sound loop file.
        ///
        QString m_mainSoundLoopPath;

        ///
        /// \brief  Paths to additional sounds that can be randomly played.
        ///
        QVector<QString> m_additionalSoundPaths;

    public:
        ///
        /// \brief  Load data from a file.
        /// \param  path    Path to the file.
        ///
        virtual void load(const QString& path) final;

        ///
        /// \brief  Save data to a file.
        /// \param  path    Path to the file.
        ///
        virtual void save(const QString& path) final;

        ///
        /// \brief  Get the path of the project on disk.
        /// \return Path of the project if saved on disk.
        ///
        QString projectPath() const { return m_projectPath; }

        ///
        /// \brief  Clear the whole project.
        ///
        void clearProject();

        ///
        /// \brief  Set the path to the main sound loop file.
        /// \param  path    Path to the main sound loop file.
        /// \return true if the path is valid; false otherwise.
        ///
        bool defineMainSoundLoopPath(const QString& path);

        ///
        /// \brief  Clear the main sound loop path.
        ///
        void clearMainSoundLoopPath() { m_mainSoundLoopPath = QString(); }

        ///
        /// \brief  Get the path to the main sound loop file.
        /// \return Path to the main sound loop file.
        ///
        const QString& mainSoundLoopPath() const { return m_mainSoundLoopPath; }

        ///
        /// \brief  Add additional sound path.
        /// \param  path    Path to an additional sound.
        /// \return true if the path is valid; false otherwise.
        ///
        bool addAdditionalSoundPath(const QString& path);

        ///
        /// \brief  Remove the additional sound path at the provided index in
        ///         the list.
        /// \param  index   Index of the sound to remove from the list of
        ///                 additional sounds.
        ///
        void removeAdditionalSoundPath(const int index);

        ///
        /// \brief  Clear all additional sound paths.
        ///
        void clearAdditionalSoundPaths() { m_additionalSoundPaths.clear(); }

        ///
        /// \brief  Get the list of additional sound paths.
        /// \return List of additional sound paths.
        ///
        const QVector<QString>& additionalSounds() const { return m_additionalSoundPaths; }
};

#endif // MODELAMBIENCEMODEL_H
