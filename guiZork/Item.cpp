#include "Item.h"
//#define DEBUG

//debug macro
#ifdef DEBUG
#define DEBUG_MSG(msg) \
std::cerr << "Debug: " << msg << std::endl;
#else
#define DEBUG_MSG(msg)
#endif

//Default constructor
Item::Item() : name(""), intValue(0), path(""), exists(false) {}

//Constructor (including different value data types)
Item::Item(string name, int intValue, double doubleValue, string path, bool exists)
    : name(name), path(path), exists(exists) {
    if (doubleValue == 0 && intValue != 0) {
        this->intValue = intValue;
    } else {
        this->doubleValue = doubleValue;
    }
}

// Shallow copy constructor for Item
Item::Item(const Item& other)
    : name(other.name), path(other.path), exists(other.exists) {
    if (other.doubleValue == 0 && other.intValue != 0) {
        this->intValue = other.intValue;
    } else {
        this->doubleValue = other.doubleValue;
}
}


//name getter
string Item::getName() const {
    return Item::name;
}

//getter value (integer)
int Item::getIntValue() const {
    return intValue;
}

//getter value (double)
double Item::getDoubleValue() const {
    return doubleValue;
}

//path getter
string Item::getPath() const {
    return Item::path;
}

//item exists getter
bool Item::getExists() const {
    return Item::exists;
}

//item exists setter
void Item::setExists(bool exists) {
    Item::exists = exists;
}


//Item destrcutor
Item::~Item() {
    DEBUG_MSG(Item::name + " deleted");
}


