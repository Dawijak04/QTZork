#include "Hall.h"
#include "mainwindow.h"
#include "Player.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    //std::cout << user.getItems() << endl;



    // Hall startRoom;


    // Room* currentRoom;
    // currentRoom = &startRoom;

    // currentRoom->setRoom();

    w.startScreen();


    return a.exec();
}
