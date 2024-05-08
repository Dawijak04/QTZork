#include "Bathroom1.h"
#include <iostream>
#include "mainwindow.h"
using namespace std;

Bathroom1* Bathroom1::instance = nullptr;
MainWindow* Bathroom1::mainWindowPtr = nullptr;
vector<Item> Bathroom1::Items;

Bathroom1& Bathroom1::getInstance(){
    if(!instance){
        instance = new Bathroom1();
    }
    return *instance;
}
Bathroom1::Bathroom1():
    Room("Bathroom 1")
{}

void Bathroom1::setMainWindow(MainWindow* mainWindow) {
    mainWindowPtr = mainWindow;
}

void Bathroom1::setRoom() const{
    mainWindowPtr->setBathroom1();
}

void Bathroom1::goDown(){
    mainWindowPtr->setDiningRoom();
}
void Bathroom1::goUp(){
}
void Bathroom1::goLeft(){
}
void Bathroom1::goRight(){
}

void Bathroom1::createItems(){
}

vector<Item> Bathroom1::getItems(){
    return Items;
}

