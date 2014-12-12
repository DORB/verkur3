#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <service.h>
#include <QDebug>
#include <QLabel>
#include "utilities.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_input_search_programmers_textChanged(const QString &arg1);

private:
    void displayAllProgrammers();
    void getAllProgrammers();

    Ui::MainWindow *ui;

    Service service;

    PersonContainer currentProgrammers;
    PersonContainer currentlyDisplayedProgs;
    /*
    CompContainer currentComputers;
    CompContainer currentlyDisplayedComps;
    */

    QString currentProgrammerSortCol;
};

#endif // MAINWINDOW_H
