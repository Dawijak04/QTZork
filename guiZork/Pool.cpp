#include "Pool.h"
#include "mainwindow.h"

Pool* Pool::instance = nullptr;
MainWindow* Pool::mainWindowPtr = nullptr;
vector<Item> Pool::Items;

Pool& Pool::getInstance(){
    if(!instance){
        instance = new Pool();
    }
    return *instance;
}
Pool::Pool():
    Room("Pool")
{}

void Pool::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Pool::setRoom() const{
    mainWindowPtr->setPool();
}

void Pool::goDown(){
    mainWindowPtr->invalidRoomError();
}
void Pool::goUp(){
    mainWindowPtr->invalidRoomError();
}
void Pool::goLeft(){
    mainWindowPtr->invalidRoomError();
}
void Pool::goRight(){
    mainWindowPtr->setGarden();
}

void Pool::createItems(){
    Item diamond = Item("Diamond", 20, "D:/Downloads/ZorkImages/Diamond.png", 1);
    Items.push_back(diamond);
}

vector<Item> Pool::getItems(){
    return Items;
}
