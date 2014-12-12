#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->input_search_programmers->setPlaceholderText("Search programmers...");

    currentProgrammerSortCol = "ID";

    getAllProgrammers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllProgrammers()
{
    ui->table_programmers->clearContents();
    ui->table_programmers->setRowCount(currentProgrammers.size());

    currentlyDisplayedProgs.clear();

    string searchString = ui->input_search_programmers->text().toStdString();
    qDebug() << "currentProgrammers.size() = " << currentProgrammers.size() << endl;

    for(unsigned int i = 0; i < currentProgrammers.size(); i++)
    {
        Person currentProgrammer = currentProgrammers[i];

        if(currentProgrammer.contains(searchString))
        {

            QString programmerName = QString::fromStdString(currentProgrammer.getFName() + " " + currentProgrammer.getLName());
            QString programmerNationality = QString::fromStdString(currentProgrammer.getNationality());
            QString programmerBorn = QString::fromStdString(utils::int2str(currentProgrammer.getBY()));
            QString programmerDead = QString::fromStdString(utils::int2str(currentProgrammer.getDY()));
            QString programmerSex = QString::fromStdString(currentProgrammer.getSex());

            int currentRow = currentlyDisplayedProgs.size();

            ui->table_programmers->setItem(currentRow, 0, new QTableWidgetItem(programmerName));
            ui->table_programmers->setItem(currentRow, 1, new QTableWidgetItem(programmerNationality));
            ui->table_programmers->setItem(currentRow, 2, new QTableWidgetItem(programmerBorn));
            ui->table_programmers->setItem(currentRow, 3, new QTableWidgetItem(programmerDead));
            ui->table_programmers->setItem(currentRow, 4, new QTableWidgetItem(programmerSex));

            currentlyDisplayedProgs.push_back(currentProgrammer);
        }
    }

    ui->table_programmers->setRowCount(currentlyDisplayedProgs.size());
}

void MainWindow::getAllProgrammers()
{
    currentProgrammers = service.getAllProgrammers(currentProgrammerSortCol);
    displayAllProgrammers();
}

void MainWindow::on_input_search_programmers_textChanged(const QString &arg1)
{
    displayAllProgrammers();
}
