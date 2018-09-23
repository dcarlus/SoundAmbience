#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "PlayingAmbienceDialog.h"
#include "ProjectSelectionDialog.h"
#include "SoundSelectionDialog.h"
#include "sound/Ambience.h"
#include "AppStrings.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);

    makeGenerationUIAvailable(false);

    makeConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSoundList()
{
    ui -> additionalSoundsListWidget -> clear();
    const QVector<QString>& additionalSounds = m_model.additionalSounds();
    for (QString sound : additionalSounds)
    {
        ui -> additionalSoundsListWidget -> addItem(sound);
    }
}

void MainWindow::makeConnections()
{
    // New project.
    connect
    (
        ui -> actionNew_ambience,
        SIGNAL(triggered(bool)),
        this,
        SLOT(newProject(bool))
    );

    // Open project.
    connect
    (
        ui -> actionLoad_ambience,
        SIGNAL(triggered(bool)),
        this,
        SLOT(openProject(bool))
    );

    // Save project.
    connect
    (
        ui -> actionSave,
        SIGNAL(triggered(bool)),
        this,
        SLOT(saveProject(bool))
    );

    connect
    (
        ui -> actionSave_As,
        SIGNAL(triggered(bool)),
        this,
        SLOT(saveProjectAs(bool))
    );

    // Quit application.
    connect
    (
        ui -> actionQuit,
        SIGNAL(triggered(bool)),
        this,
        SLOT(quitApp(bool))
    );

    // Set main loop sound.
    connect
    (
        ui -> soundLoopBrowseButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(setMainLoopSound(bool))
    );

    // Reset main loop sound.
    connect
    (
        ui -> soundLoopRemoveButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(resetMainLoopSound(bool))
    );

    // Add sounds.
    connect
    (
        ui -> addSoundsButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(addSounds(bool))
    );

    connect
    (
        ui -> actionAdd_sounds,
        SIGNAL(triggered(bool)),
        this,
        SLOT(addSounds(bool))
    );

    // Remove a sound.
    connect
    (
        ui -> removeSoundButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(removeSound(bool))
    );

    // Clear all sounds.
    connect
    (
        ui -> clearButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(clearSounds(bool))
    );

    connect
    (
        ui -> actionClear_sounds,
        SIGNAL(triggered(bool)),
        this,
        SLOT(clearSounds(bool))
    );

    // Generate ambience.
    connect
    (
        ui -> generateButton,
        SIGNAL(clicked(bool)),
        this,
        SLOT(generateAmbience(bool))
    );

    connect
    (
        ui -> actionGenerate_ambience,
        SIGNAL(triggered(bool)),
        this,
        SLOT(generateAmbience(bool))
    );
}

void MainWindow::makeGenerationUIAvailable(const bool available)
{
    ui -> generateButton -> setEnabled(available);
    ui -> actionGenerate_ambience -> setEnabled(available);

    ui -> actionSave -> setEnabled(available);
    ui -> actionSave_As -> setEnabled(available);
}

#include "MainWindowSlots.cpp"
