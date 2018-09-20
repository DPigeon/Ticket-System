#include "search.h"
#include "ui_search.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QBrush>
#include <QTextCharFormat>
#include "seats.h"

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_listWidget_itemSelectionChanged()
{
    //Here, the infos could be stored in SQL instead (try later)

    /*Color of the square in the calendar*/
    QBrush brush;
    brush.setColor(Qt::gray);

    /*Seven Lions*/
    QDate newDate1(2018, 11, 3);
    if(ui->listWidget->currentItem()->text() == "Seven Lions"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate1); //Goes to the date on calendar
        ui->label_price->setText("$35.00 CAD"); //Sets the price
        ui->label_time->setText("10:00PM to 3:00AM"); //Sets the time
        ui->label_location->setText("MTelus, Montreal");
    }

    /*Excision*/
    QDate newDate2(2018, 10, 5);
    if(ui->listWidget->currentItem()->text() == "Excision"){ //We get the name of the show
      //ui->calendarWidget->se //make it so it deletes old selection
        ui->calendarWidget->setSelectedDate(newDate2);
        ui->label_price->setText("$90.00 CAD");
        ui->label_time->setText("6:00PM to 3:00AM");
        ui->label_location->setText("Olympic Stadium, Montreal");
    }

    /*Metallica*/
    QDate newDate3(2018, 12, 21);
    if(ui->listWidget->currentItem()->text() == "Metallica"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate3);
        ui->label_price->setText("$120.00 CAD");
        ui->label_time->setText("7:00PM to 1:00AM");
        ui->label_location->setText("Parlement, Ottawa");
    }

    /*Petit Biscuit*/
    QDate newDate4(2018, 10, 21);
    if(ui->listWidget->currentItem()->text() == "Petit Biscuit"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate4);
        ui->label_price->setText("$50.00 CAD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("MTelus, Montreal");
    }

    /*K?D*/
    QDate newDate5(2018, 12, 2);
    if(ui->listWidget->currentItem()->text() == "K?D"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate5);
        ui->label_price->setText("$20.00 CAD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("Belmont, Montreal");
    }

    /*3DG*/
    QDate newDate6(2019, 2, 16);
    if(ui->listWidget->currentItem()->text() == "Three Days Grace"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate6);
        ui->label_price->setText("$40.00 USD");
        ui->label_time->setText("8:00PM to 1:00AM");
        ui->label_location->setText("Jaypeak, Vermont");
    }

    /*Barely Alive*/
    QDate newDate7(2019, 4, 24);
    if(ui->listWidget->currentItem()->text() == "Barely Alive"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate7);
        ui->label_price->setText("$25.00 CAD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("CN Tower, Toronto");
    }

    /*Zomboy*/
    QDate newDate8(2019, 1, 2);
    if(ui->listWidget->currentItem()->text() == "Zomboy"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate8);
        ui->label_price->setText("$30.00 USD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("Madison Square Garden, NY");
    }

    /*Herobust*/
    QDate newDate9(2019, 3, 27);
    if(ui->listWidget->currentItem()->text() == "Herobust"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate9);
        ui->label_price->setText("$20.00 USD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("New City Gas, Montreal");
    }

    /*Pink Floyd*/
    QDate newDate10(2019, 7, 1);
    if(ui->listWidget->currentItem()->text() == "Pink Floyd"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate10);
        ui->label_price->setText("$200.00 USD");
        ui->label_time->setText("7:00PM to 1:00AM");
        ui->label_location->setText("To Be Announced");
    }

    /*Linkin Park*/
    QDate newDate11(2018, 11, 1);
    if(ui->listWidget->currentItem()->text() == "Linkin Park"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate11);
        ui->label_price->setText("$75.00 USD");
        ui->label_time->setText("9:00PM to 2:00AM");
        ui->label_location->setText("Theatre Corona, Montreal");
    }

    /*Snails*/
    QDate newDate12(2019, 5, 12);
    if(ui->listWidget->currentItem()->text() == "Snails"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate12);
        ui->label_price->setText("$30.00 USD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("New City Gas, Montreal");
    }

    /*Papa Roach*/
    QDate newDate13(2019, 1, 22);
    if(ui->listWidget->currentItem()->text() == "Papa Roach"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate13);
        ui->label_price->setText("$55.00 USD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("MTelus, Montreal");
    }

    /*Tiesto*/
    QDate newDate14(2019, 2, 7);
    if(ui->listWidget->currentItem()->text() == "Tiesto"){ //We get the name of the show
        ui->calendarWidget->setSelectedDate(newDate14);
        ui->label_price->setText("$60.00 USD");
        ui->label_time->setText("10:00PM to 3:00AM");
        ui->label_location->setText("New City Gas, Montreal");
    }
}

void Search::on_confirmShow_clicked() //Maybe customize each theatre later ?
{
    if(ui->listWidget->currentItem()->isSelected()){ //If a show is selected
    seats = new Seats(this);
    seats->show(); //Open the window
    }
    else {
        QMessageBox::critical(this, "Choose A Show", "Please, select a show before choosing your seat."); //Otherwise tell the user
    }
}
