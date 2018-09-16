#include "SoundSelectionDialog.h"

SoundSelectionDialog::SoundSelectionDialog(QWidget* parent)
    : QFileDialog(parent)
{
    setNameFilter(tr("Sound (*.wav *.mp3 *.ogg)"));
    setViewMode(QFileDialog::Detail);
}
