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
    void createItems() override;
    vector<Item> getItems() override;
private:
    static MainWindow* mainWindowPtr;
    Bathroom2();
    static Bathroom2* instance;
    static vector<Item> Items;
};

#endif // BATHROOM2_H
