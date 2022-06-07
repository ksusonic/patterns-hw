#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include "textbrowserwrapper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void generalAppend();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton* button;
    QLineEdit* line;
    TextBrowserWrapper *browser;
};
#endif // MAINWINDOW_H
