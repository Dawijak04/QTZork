#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item
{
public:
    Item(string name, int value, string path, bool exists);
    string getName();
    int getValue() const;
    string getPath();
    bool getExists();
    void setExists(bool exists);

private:
    string name;
    int value;
    string path;
    bool exists;
};

#endif // ITEM_H
