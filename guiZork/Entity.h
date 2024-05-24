// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

class Room;

class Entity {
public:
    virtual Room* getRoom() = 0;
    virtual void setRoom(Room* room) = 0;
    virtual ~Entity() {}
};

#endif // ENTITY_H
