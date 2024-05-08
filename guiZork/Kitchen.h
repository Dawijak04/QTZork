#ifndef KITCHEN_H
#define KITCHEN_H
#include "Room.h"
#include "mainwindow.h"
using namespace std;

class Kitchen : public Room
{
public:
    static Kitchen& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;
    void createItems() override;
    vector<Item> getItems() override;

private:
    static MainWindow* mainWindowPtr;
    Kitchen();
    static Kitchen* instance;
    static vector<Item> Items;
};

#endif // KITCHEN_H

