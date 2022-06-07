#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , button(new QPushButton("Добавить"))
    , line(new QLineEdit("Введите, что хотите добавить"))
    , browser(new TextBrowserWrapper())
{
    ui->setupUi(this);


    connect(button, &QPushButton::clicked, this, &MainWindow::generalAppend);

    QWidget * wdg = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(wdg);

    layout->addWidget(browser);
    layout->addWidget(line);
    layout->addWidget(button);
    setCentralWidget(wdg);
}

void MainWindow::generalAppend() {
    const QString& text = line->text();
    browser->append(text);
}

MainWindow::~MainWindow()
{
    delete line;
    delete button;
    delete browser;
    delete ui;
}

