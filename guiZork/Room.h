#ifndef ROOM_H
#define ROOM_H
#include <string>
#include "Item.h"
#include <vector>



using namespace std;

class Room{
protected:
    string name;

public:
    Room(string name);
    virtual void setRoom() const;
    void setName(string n);
    string getName() const;
    virtual void goLeft();
    virtual void goRight();
    virtual void goUp();
    virtual void goDown();
    virtual void createItems() = 0;
    virtual vector<Item> getItems() = 0;

};

#endif // ROOM_H
