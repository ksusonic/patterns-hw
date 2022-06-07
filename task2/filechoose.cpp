#include "filechoose.h"
#include "ui_filechoose.h"

FileChoose::FileChoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileChoose)
{}

FileChoose::~FileChoose()
{
    delete ui;
}

QHBoxLayout* FileChoose::setWindow(QString windowName, const QVarLengthArray<int, 4>& windowSizes) {
    QHBoxLayout *layout = new QHBoxLayout(this);
    setGeometry(windowSizes[0], windowSizes[1],windowSizes[2],windowSizes[3]);
    setWindowTitle(windowName);
    return layout;
}

QTreeView* FileChoose::setTree() {
    QTreeView *tree = new QTreeView(this);
    return tree;
}

QLineEdit* FileChoose::setLineEdit() {
    QLineEdit *lineEdit = new QLineEdit(this);
    return lineEdit;
}

QComboBox* FileChoose::setComboBox() {
    QComboBox *combo = new QComboBox(this);
    combo->addItems({"json", "cpp/h", "go", "python"});
    return combo;
}

QDialogButtonBox* FileChoose::setDialogButtons() {
    QDialogButtonBox *button = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    return button;
}

FileChoose* FileChooseBuilder::BuildWindow() {
    FileChoose *fileChoose= new FileChoose();
    QHBoxLayout* window = fileChoose->setWindow("Окно с вводом текста", {10,5,700,300});

    QTreeView* tree = fileChoose->setTree();
    QLineEdit* line = fileChoose->setLineEdit();
    QComboBox* combo = fileChoose->setComboBox();
    QDialogButtonBox* button = fileChoose->setDialogButtons();

    window->addWidget(tree);
    window->addWidget(line);
    window->addWidget(combo);
    window->addWidget(button);

    fileChoose->setLayout_(window);
    fileChoose->ui->setupUi(fileChoose);
    return fileChoose;
}
