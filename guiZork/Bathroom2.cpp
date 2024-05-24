#include "Bathroom2.h"
#include "mainwindow.h"

//attributes
Bathroom2* Bathroom2::instance = nullptr;
MainWindow* Bathroom2::mainWindowPtr = nullptr;
vector<Item> Bathroom2::Items; //items in bathroo2

//Singleton
Bathroom2& Bathroom2::getInstance(){
    if(!instance){
        instance = new Bathroom2();
    }
    return *instance;
}

//COnstructor
Bathroom2::Bathroom2():
    Room("Bathroom 2")
{}


//Assigining pointer to window
void Bathroom2::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

//Setting background
void Bathroom2::setRoom() const{
    mainWindowPtr->setBathroom2();
}

//Invalid
void Bathroom2::goDown(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bathroom2::goUp(){
    mainWindowPtr->setBedroom();
}

//Invalid
void Bathroom2::goLeft(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bathroom2::goRight(){
    mainWindowPtr->invalidRoomError();
}

//Invalid
void Bathroom2::createItems(){
    Item cash = Item("Cash", 10, 0,":/images/images/Cash.png", 1);
    Items.push_back(cash);
}

//getter
vector<Item> Bathroom2::getItems(){
    return Items;
}
