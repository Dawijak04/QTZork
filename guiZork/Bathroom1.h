#ifndef BATHROOM1_H
#define BATHROOM1_H
#include "Room.h"
#include "mainwindow.h"
using namespace std;

class Bathroom1 : public Room
{
public:
    static Bathroom1& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;
private:
    static MainWindow* mainWindowPtr;
    Bathroom1();
    static Bathroom1* instance;
};

#endif // BATHROOM1_H

