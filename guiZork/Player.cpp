#include "Player.h"
#include "Driveway.h"
#include <iostream>
Player* Player::instance = nullptr;

Player::Player() : currentRoom(nullptr), items(0) {}

Player& Player::getInstance(){
    if(!instance){
        instance = new Player();
    }
    return *instance;
}

Room* Player::getRoom(){
    return currentRoom;
};

void Player::setRoom(Room* r){
    currentRoom = r;
    std::cout<<"set current room (player)" << endl;
    std::cout<<currentRoom->getName() << endl;
};
int Player::getItems(){
    return items;
};
void Player::setItems(int number){
    items = number;
};



