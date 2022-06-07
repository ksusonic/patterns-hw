#include "textinput.h"
#include "ui_textinput.h"
#include <QToolButton>
#include <QMenu>

TextInput::TextInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextInput)
{}

QHBoxLayout* TextInput::setWindow(QString windowName, const QVarLengthArray<int, 4>& windowSizes) {
    QHBoxLayout *layout = new QHBoxLayout(this);
    setGeometry(windowSizes[0], windowSizes[1],windowSizes[2],windowSizes[3]);
    setWindowTitle(windowName);
    return layout;
}

QToolBar* TextInput::setToolbar() {
    QToolBar *toolbar = new QToolBar(this);
    QToolButton *saveButton=new QToolButton(this);
    saveButton->setText("Save");
    saveButton->setPopupMode(QToolButton::InstantPopup);
    QMenu *saveMenu=new QMenu(saveButton);
    saveMenu->addAction(new QAction("Сохранить как", this));
    saveMenu->addAction(new QAction("Сохранить", this));
    saveButton->setMenu(saveMenu);
    toolbar->addWidget(saveButton);
    return toolbar;
}

QTextEdit* TextInput::setTextInput() {
    QTextEdit *input = new QTextEdit(this);
    return input;
}

QDialogButtonBox* TextInput::setDialogButtons() {
    QDialogButtonBox *button = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    return button;
}

TextInput::~TextInput()
{
    delete ui;
}

TextInput* TextInputBuilder::BuildWindow() {
    TextInput *textInput= new TextInput();
    QHBoxLayout* window = textInput->setWindow("Окно с вводом текста", {7,3,500,250});

    QToolBar* toolbar = textInput->setToolbar();
    QTextEdit* input = textInput->setTextInput();
    QDialogButtonBox* button = textInput->setDialogButtons();

    window->addWidget(toolbar);
    window->addWidget(input);
    window->addWidget(button);

    textInput->setLayout_(window);
    textInput->ui->setupUi(textInput);
    return textInput;
}
