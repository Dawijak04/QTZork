#include "Livingroom.h"
#include <iostream>
#include "mainwindow.h"

using namespace std;



Livingroom* Livingroom::instance = nullptr;
MainWindow* Livingroom::mainWindowPtr = nullptr;
vector<Item> Livingroom::Items;

Livingroom& Livingroom::getInstance(){
    if(!instance){
        instance = new Livingroom();
    }
    return *instance;
}

Livingroom::Livingroom():
    Room("Living Room")
{}

void Livingroom::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Livingroom::setRoom() const{
    cout<<"set room to living room"<<endl;
    mainWindowPtr->setLivingRoom();
}

void Livingroom::goDown(){
    cout<<"set room to Hall"<<endl;
    mainWindowPtr->setHall();
}

void Livingroom::goUp(){
    cout<<"set room to garden"<<endl;
    mainWindowPtr->setGarden();

}
void Livingroom::goLeft(){
    cout<<"set room to Bedroom"<<endl;
    mainWindowPtr->setBedroom();
}
void Livingroom::goRight(){
    cout<<"set room to dining room"<<endl;
    mainWindowPtr->setDiningRoom();
}


void Livingroom::createItems(){
    Item gold = Item("Gold", 15, "D:/Downloads/ZorkImages/Gold.png", 1);
    Items.push_back(gold);

    Item cash = Item("Cash", 10, "D:/Downloads/ZorkImages/Cash.png", 1);
    Items.push_back(cash);
}

vector<Item> Livingroom::getItems(){
    return Items;
}

