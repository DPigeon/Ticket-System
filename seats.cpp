#include "seats.h"
#include "ui_seats.h"

Seats::Seats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Seats)
{
    ui->setupUi(this);
}

Seats::~Seats()
{
    delete ui;
}
