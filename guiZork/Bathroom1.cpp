#include "Bathroom1.h"
#include "mainwindow.h"

//Attributes
Bathroom1* Bathroom1::instance = nullptr;
MainWindow* Bathroom1::mainWindowPtr = nullptr;
vector<Item> Bathroom1::Items; //Items in Bathroom1

//Singleton
Bathroom1& Bathroom1::getInstance(){
    if(!instance){
        instance = new Bathroom1();
    }
    return *instance;
}

//Constructor
Bathroom1::Bathroom1():
    Room("Bathroom 1")
{}


//Reassigning pointer to MainWindow
void Bathroom1::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Bathroom1::setRoom() const{
    mainWindowPtr->setBathroom1();
}

//Setting dining room
void Bathroom1::goDown(){
    mainWindowPtr->setDiningRoom();
}

//Invalid
void Bathroom1::goUp(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bathroom1::goLeft(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bathroom1::goRight(){
    mainWindowPtr->invalidRoomError();
}

//Creating items for room
void Bathroom1::createItems(){
    Item gold = Item("Gold", 15, 0,":/images/images/Gold.png", 1);
    Items.push_back(gold);
}

//getter
vector<Item> Bathroom1::getItems(){
    return Items;
}

