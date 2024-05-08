#ifndef POOL_H
#define POOL_H
#include "Room.h"
#include "mainwindow.h"

class Pool : public Room
{
public:
    static Pool& getInstance();
    void setMainWindow(MainWindow* mainWindow);
    void setRoom() const override;
    void goUp() override;
    void goDown() override;
    void goLeft() override;
    void goRight() override;
    void createItems() override;
    vector<Item> getItems() override;
private:
    Pool();
    static MainWindow* mainWindowPtr;
    static Pool* instance;
    static vector<Item> Items;
};

#endif // POOL_H



