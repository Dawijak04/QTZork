#include "Diningroom.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Diningroom* Diningroom::instance = nullptr;
MainWindow* Diningroom::mainWindowPtr = nullptr;

Diningroom& Diningroom::getInstance(){
    if(!instance){
        instance = new Diningroom();
    }
    return *instance;
}

Diningroom::Diningroom():
    Room("Dining Room")
{}


void Diningroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Diningroom::setRoom() const{
    mainWindowPtr->setDiningRoom();
}

void Diningroom::goDown(){
    mainWindowPtr->setKitchen();

}
void Diningroom::goUp(){
    mainWindowPtr->setBathroom1();

}
void Diningroom::goLeft(){
    mainWindowPtr->setLivingRoom();
}
void Diningroom::goRight(){
    cout<<"invalid"<<endl;
}
