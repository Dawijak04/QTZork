#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
public:
    Item();
    Item(string name, int intValue, double doubleValue, string path, bool exists);
    string getName() const;
    int getIntValue() const;
    double getDoubleValue() const;
    string getPath() const;
    bool getExists() const;
    void setExists(bool exists);
    Item(const Item& other);
    ~Item();
private:
    string name;
    union {
        int intValue;
        double doubleValue;
    };
    string path;
    bool exists;
};


#endif // ITEM_H
