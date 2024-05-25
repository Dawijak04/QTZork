#include "Driveway.h"
#include "mainwindow.h"

//Attributes
Driveway* Driveway::instance = nullptr;
MainWindow* Driveway::mainWindowPtr = nullptr;
vector<Item> Driveway::Items;

//Singleton
Driveway& Driveway::getInstance(){
    if(!instance){
        instance = new Driveway();
    }
    return *instance;
}

//Constructor
Driveway::Driveway():
    Room("Driveway")
{}

//Assigning pointer to window
void Driveway::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Driveway::setRoom() const{
    mainWindowPtr->setDriveway();
}

//Invalid
void Driveway::goDown(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Driveway::goUp(){
    mainWindowPtr->setHall();
}

//Invalid
void Driveway::goLeft(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Driveway::goRight(){
    mainWindowPtr->invalidRoomError();
}

//Creating items for room
void Driveway::createItems(){
    Item car = Item("Car", 0, 0,":/images/images/car.png", 1);
    Items.push_back(car);

}

//getter
vector<Item> Driveway::getItems(){
    return Items;
}


