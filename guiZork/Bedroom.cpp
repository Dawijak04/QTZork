#include "Bedroom.h"
#include <string>
#include "mainwindow.h"

//Attributes
Bedroom* Bedroom::instance = nullptr;
MainWindow* Bedroom::mainWindowPtr = nullptr;
vector<Item> Bedroom::Items;//items in room


//Singleton
Bedroom& Bedroom::getInstance(){
    if(!instance){
        instance = new Bedroom();
    }
    return *instance;
}

//Constructor
Bedroom::Bedroom():
    Room("Bedroom")
{}


//Assigning pointer to window
void Bedroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Bedroom::setRoom() const{
    mainWindowPtr->setBedroom();
}

//Setting bathroom2
void Bedroom::goDown(){
    mainWindowPtr->setBathroom2();
}

//Invalid
void Bedroom::goUp(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bedroom::goLeft(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bedroom::goRight(){
    mainWindowPtr->setLivingRoom();
}

//Creating items for room
void Bedroom::createItems(){
    Item diamond = Item("Diamond", 20, 0,":/images/images/Diamond.png", 1);
    Item cash = Item("Cash", 10, 0,":/images/images/Cash.png", 1);
    Items.push_back(diamond);
    Items.push_back(cash);


}

vector<Item> Bedroom::getItems(){
    return Items;
}
