#ifndef BATHROOM2_H
#define BATHROOM2_H
#include "Room.h"
#include "mainwindow.h"

class Bathroom2 : public Room
{
public:
    static Bathroom2& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;
private:
    static MainWindow* mainWindowPtr;
    Bathroom2();
    static Bathroom2* instance;
};

#endif // BATHROOM2_H
