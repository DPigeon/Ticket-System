#include "payment.h"
#include "ui_payment.h"

Payment::Payment(QWidget *parent, QString p) :
    QDialog(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);
    p = price;
}

Payment::~Payment()
{
    delete ui;
}
