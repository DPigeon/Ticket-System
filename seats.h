#ifndef SEATS_H
#define SEATS_H

#include <QDialog>

namespace Ui {
class Seats;
}

class Seats : public QDialog
{
    Q_OBJECT

public:
    explicit Seats(QWidget *parent = 0);
    ~Seats();

private:
    Ui::Seats *ui;
};

#endif // SEATS_H
