#ifndef BEDROOM_H
#define BEDROOM_H
#include "Room.h"
#include "mainwindow.h"

class Bedroom : public Room
{
public:
    static Bedroom& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;
private:
    Bedroom();
    static MainWindow* mainWindowPtr;
    static Bedroom* instance;

};

#endif // BEDROOM_H


