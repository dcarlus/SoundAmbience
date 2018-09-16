#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "model/AmbianceModel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow* ui;

        AmbianceModel m_model ;

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        void updateSoundList();
        void makeConnections();
};

#endif // MAINWINDOW_H
