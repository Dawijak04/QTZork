#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    w.setFixedSize(950, 750);
    w.show();
    w.startScreen();



    return a.exec();

}
