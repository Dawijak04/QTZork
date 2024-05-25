#ifndef PLAYER_H
#define PLAYER_H
#include "Room.h"
#include "ArrayList.h"
#include "Entity.h"


class Player: public Entity{

friend class Escaperoute;

private:
    int items;
    Room* currentRoom;
    static Player* instance;
    Player();
    static ArrayList<Item> Inventory;
    struct PlayerFlags {
        bool hasCarKeys : 1;
    };
    static PlayerFlags flags;


public:
    static Player& getInstance();
    Room* getRoom() override;
    void setRoom(Room* room) override;
    void addItem(Item item);
    int getInventorySize();
    int getInventoryValue();
    bool getHasCarKeys();
    void setHasCarKeys(bool keys);

};


#endif // PLAYER_H
