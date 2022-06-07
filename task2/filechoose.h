#ifndef FILECHOOSE_H
#define FILECHOOSE_H

#include "baseWindowbuilder.h"
#include <QTreeView>
#include <QComboBox>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include <QHBoxLayout>


namespace Ui {
class FileChoose;
}

class FileChoose : public QDialog
{
    Q_OBJECT

public:
    explicit FileChoose(QWidget *parent = nullptr);

    QHBoxLayout* setWindow(QString name, const QVarLengthArray<int, 4>& windowSizes);

    QTreeView* setTree();
    QLineEdit* setLineEdit();
    QComboBox* setComboBox();
    QDialogButtonBox* setDialogButtons();

    inline void setLayout_(QHBoxLayout* layout) {
        setLayout(layout);
    }
    ~FileChoose();
    Ui::FileChoose *ui;
};


class FileChooseBuilder : public WindowBuilder<FileChoose> {
public:
    FileChoose* BuildWindow() override;
};


#endif // FILECHOOSE_H
