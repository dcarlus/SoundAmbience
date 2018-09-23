#ifndef PROJECTSELECTIONDIALOG_H
#define PROJECTSELECTIONDIALOG_H

#include <QFileDialog>

class ProjectSelectionDialog final : public QFileDialog
{
    public:
        ProjectSelectionDialog(QWidget* parent = nullptr);
};

#endif // PROJECTSELECTIONDIALOG_H
