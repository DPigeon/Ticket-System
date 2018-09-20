#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*Splash Screen at Beginnning*/
    QSplashScreen *splashStart = new QSplashScreen;
    splashStart->setPixmap(QPixmap(":/images/XenaticyLogo.png"));
    splashStart->show();

    MainWindow w;
    QTimer::singleShot(5000, splashStart, SLOT(close()));
    QTimer::singleShot(5050, &w, SLOT(show()));
    //w.show();

    return a.exec();
}
