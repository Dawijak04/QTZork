#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "Item.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startScreen();

    void setDriveway();
    void setHall();
    void setKitchen();
    void setDiningRoom();
    void setLivingRoom();
    void setBathroom1();
    void setBedroom();
    void setBathroom2();
    void setGarden();
    void setPool();

    void initializeItems();
    void hideItems();
    void showItemsDriveway();
    void showItemsHall();
    void showItemsDiningroom();
    void showItemsKitchen();
    void showItemsLivingroom();
    void showItemsBedroom();
    void showItemsBathroom1();
    void showItemsBathroom2();
    void showItemsGarden();
    void showItemsPool();
    bool isLabelDisplayingImage(const QLabel* label);
    void showPopUpWelcome();
    void showPopUpLose();
    void showPopUpWin();
    void showMap();
    void invalidRoomError();
    void restrictedAccessError();
    void fullInventoryError();



private slots:
    void setBackground(const QString& imagePath);
    void setImageLabel(QLabel* label, const QString& imagePath);
    void setImageButton(QPushButton* button, const QString& imagePath);
    void on_startButton_clicked();
    void modifyButtonVisibility(bool isVisible);
    void modifyButtonAvailability(bool isEnabled);
    void collectItem(QPushButton* button, Item item);
    void createInventory();
    void addToInventory(Item item);




    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_mapButton_clicked();

    void on_ItemHall1_clicked();

    void on_ItemBathroom11_clicked();

    void on_ItemBathroom21_clicked();

    void on_ItemBedroom1_clicked();

    void on_ItemBedroom2_clicked();

    void on_ItemDiningroom1_clicked();

    void on_ItemGarden1_clicked();

    void on_ItemGarden2_clicked();

    void on_ItemKitchen1_clicked();

    void on_ItemLivingroom1_clicked();

    void on_ItemLivingroom2_clicked();

    void on_ItemPool1_clicked();

    void on_ItemDriveway1_clicked();

private:
    Ui::MainWindow *ui;
    QList<QLabel*> inventorySlots;
    QList<QLabel*> inventorySpaces;
    QList<QPushButton*> arrowButtons;
    QList<QPushButton*> items;




};
#endif // MAINWINDOW_H
