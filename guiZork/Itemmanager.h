#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include <iostream>
#include "Item.h"
using namespace std;

class ItemManager
{
public:
    void setItemAttributes(Item& item, string& name, string& path);
    ~ItemManager();
};

#endif // ITEMMANAGER_H
