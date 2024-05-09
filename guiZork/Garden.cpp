#include "Garden.h"
#include "mainwindow.h"

Garden* Garden::instance = nullptr;
MainWindow* Garden::mainWindowPtr = nullptr;
vector<Item> Garden::Items;

Garden& Garden::getInstance(){
    if(!instance){
        instance = new Garden();
    }
    return *instance;
}
Garden::Garden():
    Room("Garden")
{}

void Garden::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Garden::setRoom() const{
    mainWindowPtr->setGarden();
}

void Garden::goDown(){
    mainWindowPtr->setLivingRoom();
}
void Garden::goUp(){

}
void Garden::goLeft(){
    mainWindowPtr->setPool();
}
void Garden::goRight(){
}

void Garden::createItems(){
    Item cash = Item("Cash", 10, "D:/Downloads/ZorkImages/Cash.png", 1);
    Items.push_back(cash);
    Item gold = Item("Gold", 15, "D:/Downloads/ZorkImages/Gold.png", 1);
    Items.push_back(gold);
}

vector<Item> Garden::getItems(){
    return Items;
}
