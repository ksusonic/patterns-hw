#ifndef ERROR_H
#define ERROR_H

#include "baseWindowbuilder.h"
#include <QLabel>
#include <QVarLengthArray>
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>

namespace Ui {
class Error;
}

class Error : public QDialog {
    Q_OBJECT

public:
    explicit Error(QWidget *parent = nullptr);

    QHBoxLayout* setWindow(QString name, const QVarLengthArray<int, 4>& windowSizes);

    QLabel* setLabel(QString labelText);
    QPushButton* setButton(QString errText);

    inline void setLayout_(QHBoxLayout* layout) {
        setLayout(layout);
    }

    ~Error();
    Ui::Error *ui;
};


class ErrorWindowBuilder : public WindowBuilder<Error> {
public:
    Error* BuildWindow() override;
};

#endif // ERROR_H
