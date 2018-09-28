#include "seats.h"
#include "ui_seats.h"
#include <iostream>
#include <QtWidgets>
#include <sstream>
#include <qDebug>

using namespace std;

const int gridSize = 10; //Size of the matrix
const int buttonSize = 25; //Size of a button that can display one char
int row[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char col[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int r;
char c;

QPushButton* gridButton[gridSize][gridSize];
string seat;

Seats::Seats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Seats)
{
    ui->setupUi(this);
    gridLayoutButton(); //Initializes the grid
}


Seats::~Seats()
{
    delete ui;
}

void Seats::gridLayoutButton()
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            gridButton[i][j] = new QPushButton("-", ui->pushButton); //Creates buttons
            gridButton[i][j]->setMaximumSize(buttonSize, buttonSize); //Sets size for button
            ui->gridLayout->addWidget(gridButton[i][j], i, j); //Adds the buttons to the layout
            connect(gridButton[i][j], SIGNAL(clicked()), this, SLOT(gridClicked())); //Connects the button to an action (clicked)
            getSeat(i, j) = seat;
            gridButton[i][j]->show(); //Show the grid
        }
    }
}

string Seats::getSeat(int i, int j) //i = letters, row[]
{
    //int convert = charToInt(j); //Converts
    stringstream ss;
    r = row[i];
    c = col[j];
    ss<<r+c;
    string s = ss.str();
    //qDebug()<<s;
    return s;
}

void Seats::gridClicked()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender()); //Sends the to connection

    //Toggling on and off
    if(button->text() == "-")
        button->setText("X");
    else
        button->setText("-");

    QString q = seat.c_str();

    ui->labelSeat->setText(q);


}
