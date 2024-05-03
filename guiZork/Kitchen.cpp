#include "Kitchen.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Kitchen* Kitchen::instance = nullptr;
MainWindow* Kitchen::mainWindowPtr = nullptr;

Kitchen& Kitchen::getInstance(){
    if(!instance){
        instance = new Kitchen();
    }
    return *instance;
}

Kitchen::Kitchen():
Room("Kitchen")
{}

void Kitchen::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Kitchen::setRoom() const{
    cout<<"set room to kitchen"<<endl;
    mainWindowPtr->setKitchen();
}

void Kitchen::goDown(){
    cout<<"invalid"<<endl;
}
void Kitchen::goUp(){
    cout<<"set room to dining room"<<endl;
    mainWindowPtr->setDiningRoom();
}
void Kitchen::goLeft(){
    cout<<"invalid"<<endl;
    mainWindowPtr->setHall();
}
void Kitchen::goRight(){
    cout<<"invalid"<<endl;
}







