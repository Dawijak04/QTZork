#include "Escaperoute.h"
#include "Player.h"


//Constructor
Escaperoute::Escaperoute(std::string name) {
    this->name = name;
}

//Checks car keys
bool Escaperoute::checkEligibility(){
    if(Player::getInstance().flags.hasCarKeys){
        return 1;
    }
    else return 0;
}

//Ends game
bool Escaperoute::completeGame(){
    return 0;
}
