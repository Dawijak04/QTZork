#ifndef DRIVEWAY_H
#define DRIVEWAY_H
#include "Room.h"
#include "mainwindow.h"
#include "Item.h"

using namespace std;

class Driveway : public Room{
public:
    static Driveway& getInstance();
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
    Driveway();
    static Driveway* instance;
    static vector<Item> Items;




};

#endif // DRIVEWAY_H
