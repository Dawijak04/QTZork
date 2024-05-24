#include "Car.h"
#include "Player.h"
#include "globals.h"



Car* Car::instance = nullptr;

//Constructor
Car::Car():
    Item("Car", 0, 0,":/images/images/car.png", 1)
{}

//Singleton
Car& Car::getInstance(){
    if(!instance){
        instance = new Car();
    }
    return *instance;
}


//Completes game
bool Car::completeGame(){
    if(Player::getInstance().getInventoryValue()>=::MIN_VALUE){
        return 1;
    }
    else{
        return 0;
    }
}
