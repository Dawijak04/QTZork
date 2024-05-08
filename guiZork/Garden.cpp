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
}

vector<Item> Garden::getItems(){
    return Items;
}
