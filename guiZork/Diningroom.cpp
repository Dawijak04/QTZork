#include "Diningroom.h"
#include "mainwindow.h"

//Attributes
Diningroom* Diningroom::instance = nullptr;
MainWindow* Diningroom::mainWindowPtr = nullptr;
vector<Item> Diningroom::Items;

//Singleton
Diningroom& Diningroom::getInstance(){
    if(!instance){
        instance = new Diningroom();
    }
    return *instance;
}

//Constructor
Diningroom::Diningroom():
    Room("Dining Room")
{}


//Assinging pointer to window
void Diningroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Seting background
void Diningroom::setRoom() const{
    mainWindowPtr->setDiningRoom();
}

//Setting kitchen
void Diningroom::goDown(){
    mainWindowPtr->setKitchen();
}

//Setting bathroom1
void Diningroom::goUp(){
    mainWindowPtr->setBathroom1();
}

//Setting living room
void Diningroom::goLeft(){
    mainWindowPtr->setLivingRoom();
}

//Invalid
void Diningroom::goRight(){
    mainWindowPtr->invalidRoomError();
}

//Creating items
void Diningroom::createItems(){
    Item cash = Item("Cash", 10, 0,":/images/images/Cash.png", 1);
    Items.push_back(cash);
}


//getter
vector<Item> Diningroom::getItems(){
    return Items;
}
