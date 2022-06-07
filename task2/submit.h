#ifndef SUBMIT_H
#define SUBMIT_H

#include <QDialog>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QLabel>

#include "baseWindowbuilder.h"

namespace Ui {
class Submit;
}

class Submit : public QDialog
{
    Q_OBJECT

public:
    explicit Submit(QWidget *parent = nullptr);

    QHBoxLayout* setWindow(QString name, const QVarLengthArray<int, 4>& windowSizes);

    QLabel* setLabel(QString labelText);
    QDialogButtonBox* setDialogButtons();

    inline void setLayout_(QHBoxLayout* layout) {
        setLayout(layout);
    }

    ~Submit();
    Ui::Submit *ui;
};

class SubmitBuilder : public WindowBuilder<Submit> {
public:
    Submit* BuildWindow() override;
};

#endif // SUBMIT_H
