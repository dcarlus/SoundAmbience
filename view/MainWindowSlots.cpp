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
    ui -> soundLoopPathLabel -> setText(m_model.mainSoundLoopPath());

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
    stopAmbienceThread();

    m_thread = std::make_unique<AmbienceThread>(m_model);
    m_thread -> start();

    makeGenerationUIAvailable(false);
}
