#pragma once

#ifndef TEKER_H
    #define TEKER_H
    #include <QStringList>
    #include <QListWidget>
    #include <widget.h>

class Memento {
public:
    void newMem(QListWidget* list, MementoData *object) {
        QString counter = QString::number(data.count());
        QString getarr = object->getmemo().join("-").replace("--", "- -");

        if (getarr[0] == ',')
            getarr = getarr.remove(0, 1);

        if (getarr[getarr.length() - 1] == ',')
            getarr = getarr.remove(getarr.length() - 1, 1);

        list->addItem(counter + ") " + getarr);
        object->addcounter(counter);
        data.push_back(*object);
    }

    void popMem(QListWidget* list, ListMemento* object, QTableWidget* table) {
        if (list->selectedItems().isEmpty()) {
            return;
        }
        QString thiselement = list->selectedItems().last()->text();
        if (thiselement != nullptr) {
            QString pref = thiselement.split(')').first();
            for (MementoData& stdmemeo : data) {
                auto memolist = stdmemeo.getmemo().first();
                if (memolist.contains(pref)) {
                    object->smemo(table, &stdmemeo);
                    break;
                }
            }
        }
    }

private:
    QList<MementoData> data{};
};
#endif // TEKER_H
