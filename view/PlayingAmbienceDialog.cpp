#include "PlayingAmbienceDialog.h"
#include "ui_PlayingAmbienceDialog.h"
#include "AppStrings.h"

PlayingAmbienceDialog::PlayingAmbienceDialog
(
    const AmbienceModel& model,
    QMainWindow* parent
) :
    QDialog(parent),
    m_mainWindow(parent),
    ui(new Ui::PlayingAmbienceDialog)
{
    ui -> setupUi(this);

    setIcon();
    createTrayIcon();

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_DeleteOnClose);
    makeConnections();

    m_thread = std::make_unique<AmbienceThread>(model);
    m_thread -> start();
}

PlayingAmbienceDialog::~PlayingAmbienceDialog()
{
    stopAmbienceThread();
    delete ui;
}

void PlayingAmbienceDialog::closeEvent(QCloseEvent*)
{
    stopAmbienceThread();
}

void PlayingAmbienceDialog::makeConnections()
{
    // System tray activation.
    connect
    (
        m_trayIcon,
        SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this,
        SLOT(iconActivated(QSystemTrayIcon::ActivationReason))
    );

    // Minimize to tray.
    connect
    (
        ui -> minimizeButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(minimizeToTray(bool))
    );

    // Stop ambience.
    connect
    (
        ui -> stopButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(stopAmbience(bool))
    );
}

void PlayingAmbienceDialog::stopAmbienceThread()
{
    if (m_thread)
    {
        m_thread -> stop();
        m_thread -> wait();
    }

    m_mainWindow -> show();
}

void PlayingAmbienceDialog::createTrayIcon()
{
    m_stopAction = new QAction(Strings::MainWindow_StopAmbience, this);
    connect(m_stopAction, SIGNAL(triggered(bool)), this, SLOT(stopAmbience(bool)));

    m_trayIconMenu = new QMenu(this);
    m_trayIconMenu -> addAction(m_stopAction);

    m_trayIcon -> setContextMenu(m_trayIconMenu);
    m_trayIcon -> show();
}

void PlayingAmbienceDialog::setIcon()
{
    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon -> setIcon(windowIcon());
    m_trayIcon -> setToolTip(windowTitle());
}

void PlayingAmbienceDialog::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            if (isVisible())
            {
                hide();
            }
            else
            {
                show();
            }
            break;

        default:
            break;
    }
}

void PlayingAmbienceDialog::minimizeToTray(const bool)
{
    hide();
}

void PlayingAmbienceDialog::stopAmbience(const bool)
{
    close();
}
