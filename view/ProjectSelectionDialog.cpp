#include "ProjectSelectionDialog.h"

ProjectSelectionDialog::ProjectSelectionDialog(QWidget* parent)
    : QFileDialog(parent)
{
    setNameFilter(tr("Ambience project (*.ap)"));
    setViewMode(QFileDialog::Detail);
}
