#ifndef PLAYER_H
#define PLAYER_H
#include "Room.h"


class Player{
private:
    int items;
    Room* currentRoom;///////////////////&
    static Player* instance;
    Player();


public:
    static Player& getInstance();
    Room* getRoom();////////////////&
    void setRoom(Room* room);
    int getItems();
    void setItems(int number);





};


#endif // PLAYER_H
