#include "Finalinventory.h"

FinalInventory::FinalInventory(const std::vector<Item>& playerItems) : InvenzInventoryValue(0), InventoryLength(0) {
    for (size_t i = 0; i < playerItems.size() && i < 5; ++i) {
        Inventory[i] = new Item(playerItems[i]); // Assuming Item has a copy constructor
        InventoryValue += playerItems[i].getValue();
        ++InventoryLength;
    }
}







void FinalInventory::addToInventory(Item item){
    if (InventoryLength < 5) { // Check if the Inventory is not full
        Inventory[InventoryLength] = item; // Add the item to the Inventory
        InventoryLength++; // Increment InventoryLength
        InventoryValue+= item.getValue(); // Update InventoryValue with the value of the added item
    }
}
int FinalInventory::getInventoryValue(){
    return InventoryValue;
}
int FinalInventory::getInventoryLength(){
    return InventoryLength;
}
