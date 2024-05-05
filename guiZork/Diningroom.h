#ifndef DININGROOM_H
#define DININGROOM_H
#include "Room.h"
#include "mainwindow.h"
using namespace std;

class Diningroom : public Room
{
public:
    static Diningroom& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;

private:
    static MainWindow* mainWindowPtr;
    Diningroom();
    static Diningroom* instance;
};

#endif // DININGROOM_H

