#include "Kitchen.h"
#include "mainwindow.h"

//Attributes
Kitchen* Kitchen::instance = nullptr;
MainWindow* Kitchen::mainWindowPtr = nullptr;
vector<Item> Kitchen::Items;

//Singleton
Kitchen& Kitchen::getInstance(){
    if(!instance){
        instance = new Kitchen();
    }
    return *instance;
}

//Constructor
Kitchen::Kitchen():
Room("Kitchen")
{}

//Assigning pointerto window
void Kitchen::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Kitchen::setRoom() const{
    mainWindowPtr->setKitchen();
}

//Invalid
void Kitchen::goDown(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Kitchen::goUp(){
    mainWindowPtr->setDiningRoom();
}

//Invalid
void Kitchen::goLeft(){
    mainWindowPtr->setHall();
}

//Invalid
void Kitchen::goRight(){
    mainWindowPtr->invalidRoomError();
}

//Creating items
void Kitchen::createItems(){
    Item keys = Item("Car Keys", 0, 0,":/images/images/Keys.png", 1);
    Items.push_back(keys);
}

//getter
vector<Item> Kitchen::getItems(){
    return Items;
}







