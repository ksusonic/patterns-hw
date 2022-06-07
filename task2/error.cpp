#include "error.h"
#include "ui_error.h"

Error::Error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{}

QHBoxLayout* Error::setWindow(QString windowName, const QVarLengthArray<int, 4>& windowSizes) {
    QHBoxLayout *layout = new QHBoxLayout(this);
    setGeometry(windowSizes[0], windowSizes[1],windowSizes[2],windowSizes[3]);
    setWindowTitle(windowName);
    return layout;
}

QLabel* Error::setLabel(QString labelText) {
    QLabel *label = new QLabel(this);
    label->setText(labelText);
    return label;
}

QPushButton* Error::setButton(QString errText) {
    QPushButton *button = new QPushButton(this);
    button->setText(errText);
    connect(button, &QPushButton::clicked, this, &Error::close);
    return button;
}

Error::~Error()
{
    delete ui;
}

Error* ErrorWindowBuilder::BuildWindow() {
    Error *error = new Error();
    QHBoxLayout* window = error->setWindow("Окно с ошибкой", {5,1,500,250});

    QLabel* label = error->setLabel("Привет. Я - сообщение об ошибке.");
    QPushButton* button = error->setButton("Понял ошибку. Закрывай");

    window->addWidget(label);
    window->addWidget(button);

    error->setLayout_(window);
    error->ui->setupUi(error);
    return error;
}
