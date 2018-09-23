void MainWindow::newProject(const bool)
{
    m_model.clearProject();

    ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);
    updateSoundList();
    makeGenerationUIAvailable(false);
}

void MainWindow::openProject(const bool)
{
    newProject(false);

    QString fileName = QFileDialog::getOpenFileName
    (
        this,
        Strings::MainWindow_LoadAmbience,
        QString(),
        Strings::MainWindow_AmbienceProjectFile
    );

    if (fileName.isEmpty())
    {
        return;
    }

    m_model.load(fileName);
    makeGenerationUIAvailable(!m_model.mainSoundLoopPath().isEmpty());

    elideLabelText(ui -> soundLoopPathLabel, m_model.mainSoundLoopPath());
    updateSoundList();
}

void MainWindow::saveProject(const bool)
{
    if (!m_model.projectPath().isEmpty())
    {
        m_model.save(m_model.projectPath());
    }
    else
    {
        saveProjectAs(false);
    }
}

void MainWindow::saveProjectAs(const bool)
{
    QString fileName = QFileDialog::getSaveFileName
    (
        this,
        Strings::MainWindow_SaveAmbience,
        QString(),
        Strings::MainWindow_AmbienceProjectFile
    );

    if (!fileName.isEmpty())
    {
        m_model.save(fileName);
    }
}

void MainWindow::quitApp(const bool)
{
    QApplication::quit();
}

void MainWindow::setMainLoopSound(const bool)
{
    SoundSelectionDialog dialog(this);

    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
    }

    if (fileNames.size() == 0)
    {
        return;
    }

    Q_ASSERT(fileNames.size() == 1) ;
    m_model.defineMainSoundLoopPath(fileNames[0]);
    elideLabelText(ui -> soundLoopPathLabel, m_model.mainSoundLoopPath());

    makeGenerationUIAvailable(true);
}

void MainWindow::resetMainLoopSound(const bool)
{
    m_model.clearMainSoundLoopPath();
    ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);

    makeGenerationUIAvailable(false);
}

void MainWindow::addSounds(const bool)
{
    SoundSelectionDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);

    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
    }

    for (QString path : fileNames)
    {
        m_model.addAdditionalSoundPath(path);
    }

    updateSoundList();
}

void MainWindow::removeSound(const bool)
{
    int selection = ui -> additionalSoundsListWidget -> currentRow();
    m_model.removeAdditionalSoundPath(selection);
    updateSoundList();
}

void MainWindow::clearSounds(const bool)
{
    m_model.clearMainSoundLoopPath();
    m_model.clearAdditionalSoundPaths();

    ui -> soundLoopPathLabel -> setText(Strings::MainWindow_NoSelectedFile);
    updateSoundList();

    makeGenerationUIAvailable(false);
}

void MainWindow::generateAmbience(const bool)
{
    m_playingDialog = new PlayingAmbienceDialog(m_model, this);
    m_playingDialog -> show();

    hide();
}

void MainWindow::showAboutDialog(const bool)
{
    m_aboutDialog -> show();
}
