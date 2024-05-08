#include "Hall.h"
#include <iostream>
#include "mainwindow.h"

using namespace std;


Hall* Hall::instance = nullptr;
MainWindow* Hall::mainWindowPtr = nullptr;
vector<Item> Hall::Items;

Hall& Hall::getInstance(){
    if(!instance){
        instance = new Hall();
    }
    return *instance;
}

Hall::Hall():
    Room("Hall")
{}

void Hall::setMainWindow(MainWindow* mainWindow){
    mainWindowPtr = mainWindow;
}

void Hall::setRoom() const{
    //cout<<"setting room to hall" << endl;
    mainWindowPtr->setHall();
}

void Hall::goDown(){
    mainWindowPtr->setDriveway();
    //Player::getInstance().setRoom(&Driveway::getInstance());
}

void Hall::goUp(){
    //cout<<"up from hall"<<endl;
    mainWindowPtr->setLivingRoom();
    //Player::getInstance().setRoom(&Livingroom::getInstance());


}
void Hall::goLeft(){
    cout<<"invalid"<<endl;
}
void Hall::goRight(){
    mainWindowPtr->setKitchen();
}

void Hall::createItems(){
    Item cash = Item("Cash", 10, "D:/Downloads/ZorkImages/Cash.png", 1);
    Items.push_back(cash);
}

vector<Item> Hall::getItems(){
    return Items;
}
