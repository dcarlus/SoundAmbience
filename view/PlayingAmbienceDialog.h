#ifndef PLAYINGAMBIENCEDIALOG_H
#define PLAYINGAMBIENCEDIALOG_H

#include "model/AmbienceModel.h"
#include "sound/AmbienceThread.h"
#include <QAction>
#include <QDialog>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

namespace Ui {
    class PlayingAmbienceDialog;
}

///
/// \brief  Dialog that is displayed when the ambience is played.
///
class PlayingAmbienceDialog final : public QDialog
{
    Q_OBJECT

    private:
        ///
        /// \brief  UI of the dialog.
        ///
        Ui::PlayingAmbienceDialog* ui;

        ///
        /// \brief  Main window of the application.
        ///
        QMainWindow* m_mainWindow = nullptr;

        ///
        /// \brief  Thread in which the sound ambience is played.
        ///
        std::unique_ptr<AmbienceThread> m_thread;

        ///
        /// \brief  Icon in the system tray.
        ///
        QSystemTrayIcon* m_trayIcon = nullptr;

        ///
        /// \brief  Icon menu in system tray.
        ///
        QMenu* m_trayIconMenu = nullptr;

        ///
        /// \brief  Action to stop ambience from system tray.
        ///
        QAction* m_stopAction = nullptr;

    public:
        ///
        /// \brief  Create a new PlayingAmbienceDialog.
        /// \param  model   Ambience model.
        /// \param  parent  Parent widget.
        ///
        explicit PlayingAmbienceDialog
        (
            const AmbienceModel& model,
            QMainWindow* parent = nullptr
        );

        ///
        /// \brief  Destruction of the dialog.
        ///
        ~PlayingAmbienceDialog();

        ///
        /// \brief  Detect when the window is closed.
        /// \param  event   Close event.
        ///
        virtual void closeEvent(QCloseEvent* event) final;

    private:
        ///
        /// \brief  Make the UI connections to logic.
        ///
        void makeConnections();

        ///
        /// \brief  Properly stop the sound ambience thread.
        ///
        void stopAmbienceThread();

        void createTrayIcon();

        void setIcon();

    private slots:
        ///
        /// \brief  System tray icon is activated.
        /// \param  reason  Reason of the activation.
        ///
        void iconActivated(QSystemTrayIcon::ActivationReason reason);

        ///
        /// \brief  Callback to minimize the window to tray.
        ///
        void minimizeToTray(const bool);

        ///
        /// \brief  Callback to stop the ambience sounds.
        ///
        void stopAmbience(const bool);
};

#endif // PLAYINGAMBIENCEDIALOG_H
