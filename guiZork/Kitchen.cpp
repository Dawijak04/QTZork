#include "Kitchen.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Kitchen* Kitchen::instance = nullptr;
MainWindow* Kitchen::mainWindowPtr = nullptr;
vector<Item> Kitchen::Items;

Kitchen& Kitchen::getInstance(){
    if(!instance){
        instance = new Kitchen();
    }
    return *instance;
}

Kitchen::Kitchen():
Room("Kitchen")
{}

void Kitchen::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Kitchen::setRoom() const{
    cout<<"set room to kitchen"<<endl;
    mainWindowPtr->setKitchen();
}

void Kitchen::goDown(){
    cout<<"invalid"<<endl;
}
void Kitchen::goUp(){
    cout<<"set room to dining room"<<endl;
    mainWindowPtr->setDiningRoom();
}
void Kitchen::goLeft(){
    cout<<"invalid"<<endl;
    mainWindowPtr->setHall();
}
void Kitchen::goRight(){
    cout<<"invalid"<<endl;
}

void Kitchen::createItems(){
    Item keys = Item("Car Keys", 0, "D:/Downloads/ZorkImages/Keys.png", 1);
    Items.push_back(keys);
}

vector<Item> Kitchen::getItems(){
    return Items;
}







