#ifndef CONTACTS_H
#define CONTACTS_H

#include <QDialog>

namespace Ui {
class Contacts;
}

class Contacts : public QDialog
{
    Q_OBJECT

public:
    explicit Contacts(QWidget *parent = 0);
    ~Contacts();

private:
    Ui::Contacts *ui;
};

#endif // CONTACTS_H
