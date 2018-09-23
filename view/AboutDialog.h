#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
    class AboutDialog;
}

///
/// \brief  About dialog box.
///
class AboutDialog final : public QDialog
{
    Q_OBJECT

    private:
        Ui::AboutDialog* ui;

    public:
        explicit AboutDialog(QWidget* parent = nullptr);
        ~AboutDialog();



        // QWidget interface
    protected:
        virtual void mousePressEvent(QMouseEvent* event) override;
};

#endif // ABOUTDIALOG_H
