#include "Bathroom2.h"
#include "mainwindow.h"

Bathroom2* Bathroom2::instance = nullptr;
MainWindow* Bathroom2::mainWindowPtr = nullptr;

Bathroom2& Bathroom2::getInstance(){
    if(!instance){
        instance = new Bathroom2();
    }
    return *instance;
}
Bathroom2::Bathroom2():
    Room("Bathroom 2")
{}

void Bathroom2::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Bathroom2::setRoom() const{
    mainWindowPtr->setBathroom2();
}

void Bathroom2::goDown(){
}
void Bathroom2::goUp(){
    mainWindowPtr->setBedroom();
}
void Bathroom2::goLeft(){
}
void Bathroom2::goRight(){
}
