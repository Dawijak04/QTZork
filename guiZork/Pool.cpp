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
}
void Pool::goUp(){
}
void Pool::goLeft(){
}
void Pool::goRight(){
    mainWindowPtr->setGarden();
}

void Pool::createItems(){
}

vector<Item> Pool::getItems(){
    return Items;
}
