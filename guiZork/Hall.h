#ifndef HALL_H
#define HALL_H
#include "Room.h"
#include "mainwindow.h"
#include "Item.h"
using namespace std;

class Hall : public Room{
public:
    static Hall& getInstance();
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
    Hall();
    static Hall* instance;
    static vector<Item> Items;
};

#endif // HALL_H
