#ifndef SOUNDSELECTIONDIALOG_H
#define SOUNDSELECTIONDIALOG_H

#include <QFileDialog>

class SoundSelectionDialog final : public QFileDialog
{
    public:
        SoundSelectionDialog(QWidget* parent = nullptr);
};

#endif // SOUNDSELECTIONDIALOG_H
