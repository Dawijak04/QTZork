#include "Exceptions.h"

//Invalid input exception
const char* InvalidDirectionException::message() const noexcept {
    return "INVALID INPUT \nThere are no rooms in this direction";
}

//No car keys exception
const char* RestrictedAccessException::message() const noexcept {
    return "RESTRICTED ACCESS \nFind car keys first";
}

//Full inventory exception
const char* FullInventoryException::message() const noexcept {
    return "INSUFFICIENT SPACE \nInventory is full";
}
