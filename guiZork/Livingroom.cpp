#include "Livingroom.h"
#include "mainwindow.h"

//Attributes
Livingroom* Livingroom::instance = nullptr;
MainWindow* Livingroom::mainWindowPtr = nullptr;
vector<Item> Livingroom::Items;

//Singleton
Livingroom& Livingroom::getInstance(){
    if(!instance){
        instance = new Livingroom();
    }
    return *instance;
}

//Constrcutor
Livingroom::Livingroom():
    Room("Living Room")
{}

//Reassigning pointer to window
void Livingroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Livingroom::setRoom() const{
    mainWindowPtr->setLivingRoom();
}

//Setting hall
void Livingroom::goDown(){
    mainWindowPtr->setHall();
}

//Setting garden
void Livingroom::goUp(){
    mainWindowPtr->setGarden();

}

//Setting bedroom
void Livingroom::goLeft(){
    mainWindowPtr->setBedroom();
}
void Livingroom::goRight(){
    mainWindowPtr->setDiningRoom();
}

//Creating items
void Livingroom::createItems() {
    Item gold = Item("Gold", 15, 0,":/images/images/Gold.png", 1);
    Item cash = Item("Cash", 10, 0,":/images/images/Cash.png", 1);

    Items.push_back(cash);
    Items.push_back(gold); // Assign the result back to Items

}

//getter
vector<Item> Livingroom::getItems(){
    return Items;
}

