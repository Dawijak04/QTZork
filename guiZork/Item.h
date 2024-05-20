#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item {
public:
    Item();
    Item(string name, int value, string path, bool exists);
    string getName() const;
    int getValue() const;
    string getPath() const;
    bool getExists() const;
    void setExists(bool exists);
private:
    string name;
    int value;
    string path;
    bool exists;
};


#endif // ITEM_H
