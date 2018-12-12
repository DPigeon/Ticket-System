#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QListWidgetItem>
#include "seats.h"

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    QString getName();
    QString getTime();
    QString getPrice();
    QString getLocation();
    ~Search();

private slots:

    void on_listWidget_itemSelectionChanged();

    void on_confirmShow_clicked();

private:
    QString name, time, price, location;
    Ui::Search *ui;
    Seats *seats;
};

#endif // SEARCH_H
