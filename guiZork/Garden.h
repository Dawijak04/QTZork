#ifndef GARDEN_H
#define GARDEN_H
#include "Room.h"
#include "mainwindow.h"
using namespace std;

class Garden : public Room
{
public:
    static Garden& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;
private:
    Garden();
    static MainWindow* mainWindowPtr;
    static Garden* instance;
};

#endif // GARDEN_H



