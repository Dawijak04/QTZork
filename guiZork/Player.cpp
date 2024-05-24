#include "Player.h"

//Attributes
Player* Player::instance = nullptr;
ArrayList<Item> Player::Inventory;
Player::Player() : currentRoom(nullptr), items(0) {} //Default constructor
bool Player::hasCarKeys;

//Singleton
Player& Player::getInstance(){
    if(!instance){
        instance = new Player();
    }
    return *instance;
}

//getters for current room
Room* Player::getRoom(){
    return currentRoom;
};

//setter for current room
void Player::setRoom(Room* r){
    currentRoom = r;
};

//adding item to player inventory
void Player::addItem(Item item){
    Inventory + item;
}

//getter for inventory size
int Player::getInventorySize(){
    return Inventory.getSize();
}

//getter for inventory value
int Player::getInventoryValue(){
    int totalValue = 0;
    for(int i = 0; i<Inventory.getSize();i++){
        const Item& item = Inventory[i];
        totalValue += item.getIntValue();
    }
    return totalValue;
}

//getter for car keys
bool Player::getHasCarKeys(){
    return hasCarKeys;
}

//setter for car keys
void Player::setHasCarKeys(bool keys){
    hasCarKeys = keys;
}




