#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class Payment;
}

class Payment : public QDialog
{
    Q_OBJECT

public:
    explicit Payment(QWidget *parent, QString price);
    string getfName();
    string getlName();
    string getShipAddress();
    string getEmail();
    string getCardCode();
    string getCardName();
    int getVerification();
    int getExp1();
    int getExp2();
    int getExp3();
    ~Payment();

private:
    QString price;
    Ui::Payment *ui;
    string fname;
    string lname;
    string shipAddress;
    string email;
    string cardCode;
    string cardName;
    int verification;
    int exp1, exp2, exp3; //The expiration card
};

#endif // PAYMENT_H
