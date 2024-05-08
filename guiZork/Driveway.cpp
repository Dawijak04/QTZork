#include "Driveway.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Driveway* Driveway::instance = nullptr;
MainWindow* Driveway::mainWindowPtr = nullptr;
vector<Item> Driveway::Items;

Driveway& Driveway::getInstance(){
    if(!instance){
        instance = new Driveway();
    }
    return *instance;
}
Driveway::Driveway():
    Room("Driveway")
{}

void Driveway::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Driveway::setRoom() const{
    cout<<"set room to driveway"<<endl;
    mainWindowPtr->setDriveway();
}

void Driveway::goDown(){
    cout<<"invalid from drive"<<endl;
}
void Driveway::goUp(){
    mainWindowPtr->setHall();
}
void Driveway::goLeft(){
    cout<<"invalid"<<endl;
}
void Driveway::goRight(){
    cout<<"invalid"<<endl;
}


void Driveway::createItems(){
    Item car = Item("Car", 0, "D:/Downloads/ZorkImages/car.png", 1);
    Items.push_back(car);
}

vector<Item> Driveway::getItems(){
    return Items;
}


