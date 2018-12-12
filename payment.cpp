#include "payment.h"
#include "ui_payment.h"

Payment::Payment(QWidget *parent, QString p) :
    QDialog(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);
    p = price;
}

/*All getters*/

string Payment::getfName()
{
    return fname;
}

string Payment::getlName()
{
    return lname;
}

string Payment::getShipAddress()
{
    return shipAddress;
}

string Payment::getEmail()
{
    return email;
}

string Payment::getCardCode()
{
    return cardCode;
}

string Payment::getCardName()
{
    return cardName;
}

int Payment::getVerification()
{
    return verification;
}

int Payment::getExp1()
{
    return exp1;
}

int Payment::getExp2()
{
    return exp2;
}

int Payment::getExp3()
{
    return exp3;
}

Payment::~Payment()
{
    delete ui;
}
