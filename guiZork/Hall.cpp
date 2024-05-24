#include "Hall.h"
#include "mainwindow.h"

//Attributes
Hall* Hall::instance = nullptr;
MainWindow* Hall::mainWindowPtr = nullptr;
vector<Item> Hall::Items;

//Singleton
Hall& Hall::getInstance(){
    if(!instance){
        instance = new Hall();
    }
    return *instance;
}

//Constructor
Hall::Hall():
    Room("Hall")
{}

//Assinging pointer to window
void Hall::setMainWindow(MainWindow* mainWindow){
    mainWindowPtr = mainWindow;
}

//setting background
void Hall::setRoom() const{
    mainWindowPtr->setHall();
}

//setting driveway
void Hall::goDown(){
    mainWindowPtr->setDriveway();
}

//setting living room
void Hall::goUp(){
    mainWindowPtr->setLivingRoom();
}

//invalid
void Hall::goLeft(){
    mainWindowPtr->invalidRoomError();
}

//invalid
void Hall::goRight(){
    mainWindowPtr->setKitchen();
}

//creating items
void Hall::createItems(){
    Item cash = Item("Cash", 10, 0,":/images/images/Cash.png", 1);
    Items.push_back(cash);
}

//getter
vector<Item> Hall::getItems(){
    return Items;
}
