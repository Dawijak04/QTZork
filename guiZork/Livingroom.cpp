#include "Livingroom.h"
#include <iostream>
#include "mainwindow.h"

using namespace std;



Livingroom* Livingroom::instance = nullptr;
MainWindow* Livingroom::mainWindowPtr = nullptr;

Livingroom& Livingroom::getInstance(){
    if(!instance){
        instance = new Livingroom();
    }
    return *instance;
}

Livingroom::Livingroom():
    Room("Living Room")
{}

void Livingroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Livingroom::setRoom() const{
    cout<<"set room to living room"<<endl;
    mainWindowPtr->setLivingRoom();
}

void Livingroom::goDown(){
    cout<<"set room to Hall"<<endl;
    mainWindowPtr->setHall();
}

void Livingroom::goUp(){
    cout<<"set room to garden"<<endl;
    mainWindowPtr->setGarden();

}
void Livingroom::goLeft(){
    cout<<"set room to Bedroom"<<endl;
    mainWindowPtr->setBedroom();
}
void Livingroom::goRight(){
    cout<<"set room to dining room"<<endl;
    mainWindowPtr->setDiningRoom();
}



