#include "Garden.h"
#include "mainwindow.h"

//Attributes
Garden* Garden::instance = nullptr;
MainWindow* Garden::mainWindowPtr = nullptr;
vector<Item> Garden::Items;

//Singleton
Garden& Garden::getInstance(){
    if(!instance){
        instance = new Garden();
    }
    return *instance;
}

//COnstructor
Garden::Garden():
    Room("Garden")
{}

//Assigning pointer to window
void Garden::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Garden::setRoom() const{
    mainWindowPtr->setGarden();
}

//Setting living room
void Garden::goDown(){
    mainWindowPtr->setLivingRoom();
}

//Invalid
void Garden::goUp(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Garden::goLeft(){
    mainWindowPtr->setPool();
}

//Invalid
void Garden::goRight(){
    mainWindowPtr->invalidRoomError();
}

//Creating items for room
void Garden::createItems(){
    Item cash =Item("Cash", 10, 0,":/images/images/Cash.png", 1);
    Item gold =Item("Gold", 15, 0,":/images/images/Gold.png", 1);
    Items.push_back(gold);
    Items.push_back(cash);
}

//Getter
vector<Item> Garden::getItems(){
    return Items;
}
