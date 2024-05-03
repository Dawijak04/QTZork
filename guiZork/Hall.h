#ifndef HALL_H
#define HALL_H
#include "Room.h"
#include "mainwindow.h"
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
private:
    static MainWindow* mainWindowPtr;
    Hall();
    static Hall* instance;
};

#endif // HALL_H
