#pragma once

#ifndef CHART_H
    #define CHART_H
    #include <QTableWidget>
    #include <QStringList>

class MementoData {
private:
    QStringList savedtable = {"", "", "", "", "", "", "", "", ""};

public:
    void placememo(QStringList newObject) {
        savedtable = newObject;
    }

    QStringList getmemo() {
        return savedtable;
    }

    void addcounter(QString prefix) {
        savedtable.push_front(prefix);
    }
};

class ListMemento {
public:
    void upmemo(QTableWidget* table, MementoData* object) {
        QStringList newtable = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                QTableWidgetItem* elstr = table->item(i, j);
                QString itemText = "";
                if (elstr) {
                    itemText = elstr->text();
                }
                newtable.push_back(itemText);
            }
        }
        object->placememo(newtable);
    }

    void smemo(QTableWidget* table, MementoData* object) {
        QStringList data = object->getmemo();
        data.pop_front();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++) {
                QTableWidgetItem* item = new QTableWidgetItem(data.first());
                table->setItem(i, j, item);
                data.pop_front();
            }
    }
};

#endif // CHART_H
