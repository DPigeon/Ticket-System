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
    QTimer::singleShot(5000, splashStart, SLOT(close())); //starts the splash screen
    QTimer::singleShot(5025, &w, SLOT(show())); //starts program

    return a.exec();
}
