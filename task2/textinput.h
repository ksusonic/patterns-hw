#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <QDialog>
#include <QToolBar>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QHBoxLayout>

#include "baseWindowbuilder.h"

namespace Ui {
class TextInput;
}

class TextInput : public QDialog
{
    Q_OBJECT

public:
    explicit TextInput(QWidget *parent = nullptr);

    QHBoxLayout* setWindow(QString name, const QVarLengthArray<int, 4>& windowSizes);

    QToolBar* setToolbar();
    QTextEdit* setTextInput();
    QDialogButtonBox* setDialogButtons();

    inline void setLayout_(QHBoxLayout* layout) {
        setLayout(layout);
    }

    ~TextInput();
    Ui::TextInput *ui;
};

class TextInputBuilder : public WindowBuilder<TextInput> {
public:
    TextInput* BuildWindow() override;
};

#endif // TEXTINPUT_H
