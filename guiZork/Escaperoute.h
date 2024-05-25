#ifndef ESCAPEROUTE_H
#define ESCAPEROUTE_H
#include <string>

class Escaperoute
{
public:
    Escaperoute(std::string name);
    bool checkEligibility();
    virtual bool completeGame();
private:
    std::string name;
};

#endif // ESCAPEROUTE_H
