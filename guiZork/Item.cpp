#include "Item.h"

Item::Item(string name, int value, string path, bool exists) {
    Item::name = name;
    Item::value = value;
    Item::path = path;
    Item::exists = exists;
}


string Item::getName(){
    return Item::name;
}
int Item::getValue() const{
    return Item::value;
}
string Item::getPath(){
    return Item::path;
}

bool Item::getExists(){
    return Item::exists;
}

void Item::setExists(bool exists){
    Item::exists = exists;
}

