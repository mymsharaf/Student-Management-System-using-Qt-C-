#include "Login.h"
#include <QApplication>
#include <QTabWidget>
#include <QPushButton>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleSheetFile(":/qss/Irrorater.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    //  display a Splash Screen ......

    QSplashScreen * splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/Splash.png"));
    splash->show();

    Login w;

    QTimer::singleShot(2500,splash,SLOT(close()));

    QTimer::singleShot(2500,&w,SLOT(show()));
    //w.show();
    return a.exec();
}

