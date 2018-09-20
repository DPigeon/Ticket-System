#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "search.h"
#include "contacts.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    search = new Search(this);
    search->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    contacts = new Contacts(this);
    contacts->show();
}
