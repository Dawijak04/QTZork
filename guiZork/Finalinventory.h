#ifndef FINALINVENTORY_H
#define FINALINVENTORY_H

#include "Item.h"
#include <vector>

class FinalInventory
{
public:
    FinalInventory(const std::vector<Item>& playerItems);
    void addToInventory(const Item& item);
    int getInventoryValue() const;
    int getInventoryLength() const;
    ~FinalInventory(); // Destructor to release memory allocated for Item pointers

private:
    Item* Inventory[5]; // Array of pointers to Item objects
    int InventoryValue;
    int InventoryLength;
};

#endif // FINALINVENTORY_H
