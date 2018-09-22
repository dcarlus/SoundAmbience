#include "SoundSelectionDialog.h"

SoundSelectionDialog::SoundSelectionDialog(QWidget* parent)
    : QFileDialog(parent)
{
    setNameFilter(tr("Sound (*.wav *.ogg)"));
    setViewMode(QFileDialog::Detail);
}
