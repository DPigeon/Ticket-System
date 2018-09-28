#ifndef SEATS_H
#define SEATS_H
#include <string>

using namespace std;

#include <QDialog>

namespace Ui {
class Seats;
}

class Seats : public QDialog
{
    Q_OBJECT

public:
    explicit Seats(QWidget *parent = 0);
    void gridLayoutButton();
    string getSeat(int i, int j);
    ~Seats();

private slots:

    void gridClicked();

private:
    Ui::Seats *ui;
};

#endif // SEATS_H
