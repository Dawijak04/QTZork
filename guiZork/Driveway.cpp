#include "Driveway.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Driveway* Driveway::instance = nullptr;
MainWindow* Driveway::mainWindowPtr = nullptr;

Driveway& Driveway::getInstance(){
    if(!instance){
        instance = new Driveway();
    }
    return *instance;
}
Driveway::Driveway():
    Room("Driveway")
{}

void Driveway::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Driveway::setRoom() const{
    cout<<"set room to driveway"<<endl;
    mainWindowPtr->setDriveway();
}

void Driveway::goDown(){
    cout<<"invalid from drive"<<endl;
}
void Driveway::goUp(){
    mainWindowPtr->setHall();
}
void Driveway::goLeft(){
    cout<<"invalid"<<endl;
}
void Driveway::goRight(){
    cout<<"invalid"<<endl;
}
