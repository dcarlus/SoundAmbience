#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <memory>
#include "model/AmbienceModel.h"
#include "sound/AmbienceThread.h"

namespace Ui {
    class MainWindow;
}

class Ambience;

///
/// \brief  The main window of the application.
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        ///
        /// \brief  UI elements of the window.
        ///
        Ui::MainWindow* ui;

        ///
        /// \brief  Model of the sound ambience.
        ///
        AmbienceModel m_model ;

        ///
        /// \brief  Thread in which the sound ambience is played.
        ///
        std::unique_ptr<AmbienceThread> m_thread;

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
        /// \brief  Detect when the window is closed.
        /// \param  event   Close event.
        ///
        virtual void closeEvent(QCloseEvent* event) final;

        ///
        /// \brief  Update the sound list.
        ///
        void updateSoundList();

        ///
        /// \brief  Make the UI connections to logic.
        ///
        void makeConnections();

        ///
        /// \brief  Properly stop the sound ambience thread.
        ///
        void stopAmbienceThread();
};

#endif // MAINWINDOW_H
