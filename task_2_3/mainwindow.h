#pragma once

#ifndef MAINWINDOW_H
    #define MAINWINDOW_H

    #include <QMainWindow>
    #include <widget.h>
    #include <memento.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveButton_clicked();
    void on_openButton_clicked();
    void on_tableWidget_cellChanged();

private:
    Ui::MainWindow* ui;
    ListMemento *chartref;
    MementoData *memoref;
    Memento *takerref;
};
#endif // MAINWINDOW_H
