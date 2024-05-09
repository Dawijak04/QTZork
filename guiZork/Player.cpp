#include "Player.h"
#include <iostream>
Player* Player::instance = nullptr;
vector<Item> Player::Inventory;
Player::Player() : currentRoom(nullptr), items(0) {}
bool Player::hasCarKeys;

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

void Player::addItem(Item item){
    Inventory.push_back(item);
}

int Player::getInventorySize(){
    return Inventory.size();
}

int Player::getInventoryValue(){
    int totalValue = 0;
    for (const Item& item : Inventory) {
        totalValue += item.getValue();
    }
    return totalValue;
}

bool Player::getHasCarKeys(){
    return hasCarKeys;
}
void Player::setHasCarKeys(bool keys){
    hasCarKeys = keys;
}




