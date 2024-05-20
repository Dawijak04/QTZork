#include "Exceptions.h"

const char* InvalidDirectionException::message() const noexcept {
    return "INVALID INPUT \nThere are no rooms in this direction";
}

const char* RestrictedAccessException::message() const noexcept {
    return "RESTRICTED ACCESS \nFind car keys first";
}

const char* FullInventoryException::message() const noexcept {
    return "INSUFFICIENT SPACE \nInventory is full";
}
