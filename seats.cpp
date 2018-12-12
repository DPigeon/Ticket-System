#include "seats.h"
#include "ui_seats.h"
#include <iostream>
#include <QtWidgets>
#include <sstream>
#include <search.h>
#include <payment.h>

using namespace std;

const int gridSize = 10; //Size of the matrix
const int buttonSize = 30; //Size of a button that can display one char
int col[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char row[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int r;
char c;

QPushButton* gridButton[gridSize][gridSize];
string seat;

Seats::Seats(QWidget *parent, QString name, QString time, QString price, QString location) :
    QDialog(parent),
    ui(new Ui::Seats)
{
    ui->setupUi(this);
    gridLayoutButton(); //Initializes the grid
    Search search;
    //Gets all the infos of the show previously selected
    ui->labelShow->setText(name);
    ui->labelTime->setText(time);
    ui->labelPrice->setText(price);
    ui->labelLocation->setText(location);
    paymentPrice = price;
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
            auto textCoords = QString{"%1,%2"}.arg(i).arg(j);
            gridButton[i][j] = new QPushButton(textCoords, ui->pushButton); //Creates buttons
            //Converting to get the full seat
            char convert = intToChar(i);
            stringstream ss;
            ss<<convert<<j;
            string s = ss.str();
            QString q = s.c_str();
            gridButton[i][j]->setText(q);
            gridButton[i][j]->setMaximumSize(buttonSize, buttonSize); //Sets size for button
            ui->gridLayout->addWidget(gridButton[i][j], i, j); //Adds the buttons to the layout
            connect(gridButton[i][j], SIGNAL(clicked()), this, SLOT(gridClicked())); //Connects the button to an action (clicked)
            gridButton[i][j]->show(); //Show the grid
        }
    }
}

char Seats::intToChar(int c){
    //convert int to char
    char index = row[c];
    return index;
}

void Seats::gridClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender()); //Sends the to connection
    QString B = button->text();
    ui->labelSeat->setText(B); //Gets the text and puts it in seat
}

void Seats::on_pushButton_clicked() //General Admission button
{
    ui->labelSeat->setText("GA");
}

void Seats::on_buttonBox_accepted() //The OK button
{
    if(ui->labelSeat->text() != ""){ //Looks if the user chose a seat
        payment = new Payment(this, paymentPrice); //Initializing a new page with parameters
        payment->show(); //Open the window
    }
    else {
        QMessageBox::critical(this, "Choose A Seat", "Please, select a seat before going further."); //Otherwise tell the user
    }
}

void Seats::on_buttonBox_rejected() //The Cancel Button
{
    this->close();
}
