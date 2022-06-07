#include "submit.h"
#include "ui_submit.h"

Submit::Submit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Submit)
{}

Submit::~Submit()
{
    delete ui;
}

QHBoxLayout* Submit::setWindow(QString windowName, const QVarLengthArray<int, 4>& windowSizes) {
    QHBoxLayout *layout = new QHBoxLayout(this);
    setGeometry(windowSizes[0], windowSizes[1],windowSizes[2],windowSizes[3]);
    setWindowTitle(windowName);
    return layout;
}

QLabel* Submit::setLabel(QString labelText) {
    QLabel *label = new QLabel(this);
    label->setText(labelText);
    return label;
}

QDialogButtonBox* Submit::setDialogButtons() {
    QDialogButtonBox *button = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    return button;
}

Submit* SubmitBuilder::BuildWindow() {
    Submit *textInput= new Submit();
    QHBoxLayout* window = textInput->setWindow("Окно с вводом текста", {7,3,500,250});

    QLabel* input = textInput->setLabel("Я - ваше подтверждение. Подтвердите?");
    QDialogButtonBox* button = textInput->setDialogButtons();

    window->addWidget(input);
    window->addWidget(button);

    textInput->setLayout_(window);
    textInput->ui->setupUi(textInput);
    return textInput;
}
