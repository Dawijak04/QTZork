#ifndef CAR_H
#define CAR_H
#include "Item.h"
#include "Escaperoute.h"
using namespace std;

class Car: public Item, public Escaperoute
{

public:
    Car();
    bool completeGame() override;
    static Car& getInstance();


private:
    static Car* instance;


};

#endif // CAR_H
