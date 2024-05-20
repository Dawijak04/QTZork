#include "Car.h"
#include <iostream>
#include "Player.h"



Car* Car::instance = nullptr;

Car::Car():
    Item("Car", 0, "D:/Downloads/ZorkImages/car.png", 1)

{}

Car& Car::getInstance(){
    if(!instance){
        instance = new Car();
    }
    return *instance;
}


bool Car::completeGame(){
    std::cout<<"Game complete by car"<<endl;
    if(Player::getInstance().getInventoryValue()>=75){
        return 1;
    }
    else{
        return 0;
    }
}
