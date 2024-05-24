#include "Pool.h"
#include "mainwindow.h"

//Attributes
Pool* Pool::instance = nullptr;
MainWindow* Pool::mainWindowPtr = nullptr;
vector<Item> Pool::Items;

//singleton
Pool& Pool::getInstance(){
    if(!instance){
        instance = new Pool();
    }
    return *instance;
}

//Constructor
Pool::Pool():
    Room("Pool")
{}

//Reassigning pointer to window
void Pool::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Pool::setRoom() const{
    mainWindowPtr->setPool();
}

//invalid
void Pool::goDown(){
    mainWindowPtr->invalidRoomError();
}

//invalid
void Pool::goUp(){
    mainWindowPtr->invalidRoomError();
}

//invalid
void Pool::goLeft(){
    mainWindowPtr->invalidRoomError();
}

//setting garden
void Pool::goRight(){
    mainWindowPtr->setGarden();
}

//creating items for pool
void Pool::createItems(){
    Item diamond = Item("Diamond", 20, 0,":/images/images/Diamond.png", 1);
    Items.push_back(diamond);
}

//getter for pool items
vector<Item> Pool::getItems(){
    return Items;
}
