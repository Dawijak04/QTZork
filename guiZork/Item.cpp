#include "Item.h"

Item::Item() : name(""), value(0), path(""), exists(false) {}

Item::Item(string name, int value, string path, bool exists)
    : name(name), value(value), path(path), exists(exists) {}


string Item::getName() const {
    return Item::name;
}

int Item::getValue() const {
    return Item::value;
}

string Item::getPath() const {
    return Item::path;
}

bool Item::getExists() const {
    return Item::exists;
}

void Item::setExists(bool exists) {
    Item::exists = exists;
}



