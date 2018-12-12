#ifndef SEATS_H
#define SEATS_H
#include <string>
#include <payment.h>

using namespace std;

#include <QDialog>

namespace Ui {
class Seats;
}

class Seats : public QDialog
{
    Q_OBJECT

public:
    explicit Seats(QWidget *parent, QString name, QString time, QString price, QString location);
    void gridLayoutButton();
    char intToChar(int c);
    ~Seats();

private slots:

    void gridClicked();

    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    QString paymentPrice;
    Ui::Seats *ui;
    Payment *payment;
};

#endif // SEATS_H
