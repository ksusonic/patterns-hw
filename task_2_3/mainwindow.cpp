#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , chartref(new ListMemento())
    , memoref(new MementoData())
    , takerref(new Memento())
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setColumnCount(5);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_saveButton_clicked() {
    takerref->newMem(ui->listWidget, memoref);
}

void MainWindow::on_tableWidget_cellChanged() {
    chartref->upmemo(ui->tableWidget, memoref);
}

void MainWindow::on_openButton_clicked() {
    takerref->popMem(ui->listWidget, chartref, ui->tableWidget);
}
