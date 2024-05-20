#include "Bedroom.h"
#include <string>
#include "mainwindow.h"
using namespace std;

Bedroom* Bedroom::instance = nullptr;
MainWindow* Bedroom::mainWindowPtr = nullptr;
vector<Item> Bedroom::Items;

Bedroom& Bedroom::getInstance(){
    if(!instance){
        instance = new Bedroom();
    }
    return *instance;
}
Bedroom::Bedroom():
    Room("Bedroom")
{}

void Bedroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Bedroom::setRoom() const{
    mainWindowPtr->setBedroom();
}

void Bedroom::goDown(){
    mainWindowPtr->setBathroom2();
}
void Bedroom::goUp(){
    mainWindowPtr->invalidRoomError();
}
void Bedroom::goLeft(){
    mainWindowPtr->invalidRoomError();
}
void Bedroom::goRight(){
    mainWindowPtr->setLivingRoom();
}

void Bedroom::createItems(){
    Item diamond = Item("Diamond", 20, "D:/Downloads/ZorkImages/Diamond.png", 1);
    Item cash = Item("Cash", 10, "D:/Downloads/ZorkImages/Cash.png", 1);
    Items.push_back(diamond);
    Items.push_back(cash);


}

vector<Item> Bedroom::getItems(){
    return Items;
}
