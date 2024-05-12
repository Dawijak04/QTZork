#include "Escaperoute.h"
#include "Player.h"

Escaperoute::Escaperoute() {}

bool checkEligibility(){
    if(Player::getInstance().getHasCarKeys()){
        return 1;
    }
    else return 0;
}
void completeGame(){

}
