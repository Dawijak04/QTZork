#ifndef PLAYER_H
#define PLAYER_H
#include "Room.h"
#include "ArrayList.h"


class Player{

friend class Escaperoute;

private:
    int items;
    Room* currentRoom;///////////////////&
    static Player* instance;
    Player();
    static ArrayList<Item> Inventory;
    static bool hasCarKeys;


public:
    static Player& getInstance();
    Room* getRoom();////////////////&
    void setRoom(Room* room);
    void addItem(Item item);
    int getInventorySize();
    int getInventoryValue();
    bool getHasCarKeys();
    void setHasCarKeys(bool keys);






};


#endif // PLAYER_H
