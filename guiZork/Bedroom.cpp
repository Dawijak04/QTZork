#include "Bedroom.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Bedroom* Bedroom::instance = nullptr;
MainWindow* Bedroom::mainWindowPtr = nullptr;
vector<Item> Bedroom::Items;

Bedroom& Bedroom::getInstance(){
    if(!instance){
        instance = new Bedroom();
    }
    return *instance;
}
Bedroom::Bedroom():
    Room("Bedroom")
{}

void Bedroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Bedroom::setRoom() const{
    mainWindowPtr->setBedroom();
}

void Bedroom::goDown(){
    mainWindowPtr->setBathroom2();
}
void Bedroom::goUp(){
}
void Bedroom::goLeft(){
}
void Bedroom::goRight(){
    mainWindowPtr->setLivingRoom();
}

void Bedroom::createItems(){
}

vector<Item> Bedroom::getItems(){
    return Items;
}
