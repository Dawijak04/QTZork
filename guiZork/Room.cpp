#include "Room.h"
#include <iostream>
using namespace std;


Room::Room(string name):
   name(name){}

string Room::getName() const{
    return name;
}

void Room::setName(string n){
    name = n;
}

void Room::setRoom() const{
    cout<<"set room background"<<endl;
}

void Room::goDown(){
     cout<<"going down"<<endl;
}

void Room::goUp(){
     cout<<"going up"<<endl;
}

void Room::goLeft(){
     cout<<"going left"<<endl;
}

void Room::goRight(){
     cout<<"going right"<<endl;
}

