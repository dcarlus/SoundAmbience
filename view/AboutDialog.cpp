#include "AboutDialog.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui -> setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setModal(true);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::mousePressEvent(QMouseEvent* event)
{
    event -> accept();
    close();
}
