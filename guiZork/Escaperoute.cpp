#include "Escaperoute.h"
#include "Player.h"
#include <iostream>


Escaperoute::Escaperoute() {}

bool Escaperoute::checkEligibility(){
    if(Player::getInstance().hasCarKeys){
        return 1;
    }
    else return 0;
}
bool Escaperoute::completeGame(){
    std::cout<<"game finished"<<endl;
    return 0;
}
