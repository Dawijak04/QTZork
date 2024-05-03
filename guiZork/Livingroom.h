#ifndef LIVINGROOM_H
#define LIVINGROOM_H
#include "Room.h"
#include "mainwindow.h"

class Livingroom : public Room
{
public:
    static Livingroom& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown()override;
    void goLeft()override;
    void goRight()override;


private:
    Livingroom();
    static MainWindow* mainWindowPtr;
    static Livingroom* instance;
};

#endif // LIVINGROOM_H
