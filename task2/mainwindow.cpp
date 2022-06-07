#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    ErrorWindowBuilder().BuildWindow()->show();
}

void MainWindow::on_pushButton_2_clicked() {
    TextInputBuilder().BuildWindow()->show();
}

void MainWindow::on_pushButton_3_clicked() {
    SubmitBuilder().BuildWindow()->show();
}

void MainWindow::on_pushButton_4_clicked() {
    FileChooseBuilder().BuildWindow()->show();
}
