#include "Player.h"
#include <iostream>
Player* Player::instance = nullptr;
ArrayList<Item> Player::Inventory;
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
    Inventory + item;
}

int Player::getInventorySize(){
    return Inventory.getSize();
}

int Player::getInventoryValue(){
    int totalValue = 0;
    for(int i = 0; i<Inventory.getSize();i++){
        const Item& item = Inventory[i];
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




