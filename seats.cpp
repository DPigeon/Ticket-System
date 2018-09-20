#include "seats.h"
#include "ui_seats.h"

using namespace std;

string seatsArray[7][20]; //Array of all the seats

Seats::Seats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Seats)
{
    ui->setupUi(this);
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 20; j++)
            seatsArray[i][j] == ""; //Initializing the seats to 'not taken'
}

Seats::~Seats()
{
    delete ui;
}
