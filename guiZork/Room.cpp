//BASE CLASS FOR ROOMS
#include "Room.h"

//namespace declaration
using namespace std;

//Debug macro
//#define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(msg) \
std::cerr << "Debug: " << msg << std::endl;
#else
#define DEBUG_MSG(msg)
#endif


//Constructor
Room::Room(string name):
   name(name){}

//name getter
string Room::getName() const{
    return name;
}

//name setter
void Room::setName(string n){
    name = n;
}

//setter for background
void Room::setRoom() const{
    DEBUG_MSG("setting room");
}



//changing room functions
void Room::goDown(){
    DEBUG_MSG("going down");
}

void Room::goUp(){
    DEBUG_MSG("going up");
}

void Room::goLeft(){
    DEBUG_MSG("going left");
}

void Room::goRight(){
    DEBUG_MSG("going right");
}

