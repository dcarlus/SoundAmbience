#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <memory>
#include "model/AmbienceModel.h"

namespace Ui {
    class MainWindow;
}

class Ambience;
class PlayingAmbienceDialog;

///
/// \brief  The main window of the application.
///
class MainWindow final : public QMainWindow
{
    Q_OBJECT

    private:
        ///
        /// \brief  UI elements of the window.
        ///
        Ui::MainWindow* ui;

        ///
        /// \brief  Dialog that is visible when the ambience is playing.
        ///
        PlayingAmbienceDialog* m_playingDialog = nullptr;

        ///
        /// \brief  Model of the sound ambience.
        ///
        AmbienceModel m_model ;

    public:
        ///
        /// \brief  Creation of the main window.
        /// \param  parent  Parent widget.
        ///
        explicit MainWindow(QWidget* parent = nullptr);

        ///
        /// \brief  Destruction of the main window.
        ///
        ~MainWindow();

    private:
        ///
        /// \brief  Update the sound list.
        ///
        void updateSoundList();

        ///
        /// \brief  Make the UI connections to logic.
        ///
        void makeConnections();

        ///
        /// \brief  Make UI element that allow the sound generation available
        ///         or not.
        /// \param  available   true to make UI available; false otherwise.
        ///
        void makeGenerationUIAvailable(const bool available);

    private slots:
        ///
        /// \brief  Callback to create a new project.
        ///
        void newProject(const bool);

        ///
        /// \brief  Callback to open a project.
        ///
        void openProject(const bool);

        ///
        /// \brief  Callback to save the current project.
        ///
        void saveProject(const bool);

        ///
        /// \brief  Callback to save the current project.
        ///
        void saveProjectAs(const bool);

        ///
        /// \brief  Callback to close the application.
        ///
        void quitApp(const bool);


        ///
        /// \brief  Callback to set the main loop sound.
        ///
        void setMainLoopSound(const bool);

        ///
        /// \brief  Callback to reset the main loop sound.
        ///
        void resetMainLoopSound(const bool);


        ///
        /// \brief  Callback to add sounds.
        ///
        void addSounds(const bool);

        ///
        /// \brief  Callback to remove sounds.
        ///
        void removeSound(const bool);

        ///
        /// \brief  Callback to clear all sounds.
        ///
        void clearSounds(const bool);


        ///
        /// \brief  Callback to generate the ambience.
        ///
        void generateAmbience(const bool);
};

#endif // MAINWINDOW_H
