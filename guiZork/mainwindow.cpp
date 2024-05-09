#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include "Player.h"

#include "Driveway.h"
#include "Hall.h"
#include "Livingroom.h"
#include "Kitchen.h"
#include "Diningroom.h"
#include "Bathroom1.h"
#include "Bathroom2.h"
#include "Garden.h"
#include "Pool.h"
#include "Bedroom.h"

using namespace std;

QList<QLabel*> inventorySlots ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inventorySlots = { ui->InventorySlot1, ui->InventorySlot2, ui->InventorySlot3, ui->InventorySlot4, ui->InventorySlot5 };
    inventorySpaces = {ui->InventorySpace1, ui->InventorySpace2, ui->InventorySpace3, ui->InventorySpace4, ui->InventorySpace5};
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setBackground(const QString& imagePath) {
    QPixmap pix(imagePath);
    if (pix.isNull()) {
        qDebug() << "Failed to load image from" << imagePath;
        return;
    }
    QString styleSheet = QString("background-image: url(%1);").arg(imagePath);
    setStyleSheet(styleSheet);
}




void MainWindow::setImageLabel(QLabel* label, const QString& imagePath) {
    if (!label || imagePath.isEmpty()) {
        return;
    }
    QPixmap pix(imagePath);
    if (pix.isNull()) {
        qDebug() << "Failed to load image from" << imagePath;
        return;
    }
    int w = label->width();
    int h = label->height();
    label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}



void MainWindow::setImageButton(QPushButton* button, const QString& imagePath) {
    if (!button || imagePath.isEmpty()) {
        return;
    }

    QPixmap icon(imagePath);
    if (icon.isNull()) {
        qDebug() << "Failed to load icon from" << imagePath;
        return;
    }
    QSize buttonSize = button->size();
    icon = icon.scaled(buttonSize, Qt::KeepAspectRatio);

    button->setIcon(QIcon(icon));
    button->setIconSize(buttonSize);

    button->setStyleSheet("background-color: transparent; border: none;");
}



void MainWindow::startScreen(){
    //setBackground("D:/Downloads/ZorkImages/start.jpeg");
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/start.jpeg");
    setImageButton(ui->startButton, "D:/Downloads/ZorkImages/start.png");
    hideItems();
    createInventory();
    ui->startButton->setEnabled(true);
    modifyButtonVisibility(false);

}


void MainWindow::setDriveway(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/driveway.jpg");
    hideItems();
    showItemsDriveway();
    Player::getInstance().setRoom(&Driveway::getInstance());
}

void MainWindow::setHall(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/hall.jpg");
    hideItems();
    showItemsHall();
    Player::getInstance().setRoom(&Hall::getInstance());
}

void MainWindow::setKitchen(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/kitchen.png");
    hideItems();
    showItemsKitchen();
    Player::getInstance().setRoom(&Kitchen::getInstance());
}

void MainWindow::setDiningRoom(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/diningRoom.webp");
    hideItems();
    showItemsDiningroom();
    Player::getInstance().setRoom(&Diningroom::getInstance());
}

void MainWindow::setLivingRoom(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/livingRoom.jpg");
    hideItems();
    showItemsLivingroom();
    Player::getInstance().setRoom(&Livingroom::getInstance());
}

void MainWindow::setBathroom1(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/bathroom1.webp");
    hideItems();
    showItemsBathroom1();
    Player::getInstance().setRoom(&Bathroom1::getInstance());
}

void MainWindow::setGarden(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/garden.webp");
    hideItems();
    showItemsGarden();
    Player::getInstance().setRoom(&Garden::getInstance());
}

void MainWindow::setBedroom(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/bedroom.jpg");
    hideItems();
    showItemsBedroom();
    Player::getInstance().setRoom(&Bedroom::getInstance());
}

void MainWindow::setPool(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/pool.jpg");
    hideItems();
    showItemsPool();
    Player::getInstance().setRoom(&Pool::getInstance());
}

void MainWindow::setBathroom2(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/bathroom2.jpg");
    hideItems();
    showItemsBathroom2();
    Player::getInstance().setRoom(&Bathroom2::getInstance());
}






void MainWindow::modifyButtonVisibility(bool isVisible) {
    ui->leftButton->setVisible(isVisible);
    ui->rightButton->setVisible(isVisible);
    ui->downButton->setVisible(isVisible);
    ui->upButton->setVisible(isVisible);
    ui->mapButton->setVisible(isVisible);

    ui->InventorySlot1->setVisible(isVisible);
    ui->InventorySlot2->setVisible(isVisible);
    ui->InventorySlot3->setVisible(isVisible);
    ui->InventorySlot4->setVisible(isVisible);
    ui->InventorySlot5->setVisible(isVisible);
}

void MainWindow::modifyButtonAvailability(bool isEnabled) {
    ui->leftButton->setEnabled(isEnabled);
    ui->rightButton->setEnabled(isEnabled);
    ui->downButton->setEnabled(isEnabled);
    ui->upButton->setEnabled(isEnabled);
    ui->mapButton->setEnabled(isEnabled);
}

void MainWindow::collectItem(QPushButton* button, Item item){
    if(Player::getInstance().getInventorySize() < 5){
        button->setEnabled(false);
        setImageButton(button, "D:/Downloads/ZorkImages/Empty.png");
        cout<<"Collected Item: " + item.getName()<<endl;



        Item ItemCopy = Item(item.getName(), item.getValue(),item.getPath(), item.getExists());
        Player::getInstance().addItem(ItemCopy);
        addToInventory(ItemCopy);
    }else{
        cout<<"Full inventory"<<endl;
    }
}

bool MainWindow::isLabelDisplayingImage(const QLabel* label) {
    if (label) {
        const QPixmap pixmap = label->pixmap().copy(); // Copy the pixmap
        return !pixmap.isNull();
    }
    return false;
}



void MainWindow::createInventory(){
    for (QLabel* label : inventorySlots) {
        setImageLabel(label, "D:/Downloads/ZorkImages/slot.webp");
    }
}
void MainWindow::addToInventory(Item item){
    for (QLabel* label : inventorySpaces) {
        if (!isLabelDisplayingImage(label)) {
            setImageLabel(label, QString::fromStdString(item.getPath()));
            //Player::getInstance().addItem(item);
            break;
        }
    }
}

void MainWindow::on_startButton_clicked(){
    Driveway::getInstance().setMainWindow(this);
    Hall::getInstance().setMainWindow(this);
    Livingroom::getInstance().setMainWindow(this);
    Kitchen::getInstance().setMainWindow(this);
    Diningroom::getInstance().setMainWindow(this);
    Bathroom1::getInstance().setMainWindow(this);
    Garden::getInstance().setMainWindow(this);
    Pool::getInstance().setMainWindow(this);
    Bedroom::getInstance().setMainWindow(this);
    Bathroom2::getInstance().setMainWindow(this);

    initializeItems();

    modifyButtonVisibility(true);
    modifyButtonAvailability(true);
    ui->startButton->hide();

    Player::getInstance().setRoom(&Driveway::getInstance());
    Player::getInstance().getRoom()->setRoom();

}

void MainWindow::initializeItems(){
    //Driveway Items
    Driveway::getInstance().createItems();
    setImageButton(ui->ItemDriveway1, QString::fromStdString(Driveway::getInstance().getItems().at(0).getPath()));

    //Hall Items
    Hall::getInstance().createItems();
    setImageButton(ui->ItemHall1, QString::fromStdString(Hall::getInstance().getItems().at(0).getPath()));

    //Living Room Items
    Livingroom::getInstance().createItems();
    setImageButton(ui->ItemLivingroom1, QString::fromStdString(Livingroom::getInstance().getItems().at(0).getPath()));
    setImageButton(ui->ItemLivingroom2, QString::fromStdString(Livingroom::getInstance().getItems().at(1).getPath()));

    //Kitchen Items
    Kitchen::getInstance().createItems();
    setImageButton(ui->ItemKitchen1, QString::fromStdString(Kitchen::getInstance().getItems().at(0).getPath()));

    //Bathroom1 Items
    Bathroom1::getInstance().createItems();
    setImageButton(ui->ItemBathroom11, QString::fromStdString(Bathroom1::getInstance().getItems().at(0).getPath()));

    //Bedroom Items
    Bedroom::getInstance().createItems();
    setImageButton(ui->ItemBedroom1, QString::fromStdString(Bedroom::getInstance().getItems().at(0).getPath()));
    setImageButton(ui->ItemBedroom2, QString::fromStdString(Bedroom::getInstance().getItems().at(1).getPath()));

    //Dining Room Items
    Diningroom::getInstance().createItems();
    setImageButton(ui->ItemDiningroom1, QString::fromStdString(Diningroom::getInstance().getItems().at(0).getPath()));

    //Bathroom2 Items
    Bathroom2::getInstance().createItems();
    setImageButton(ui->ItemBathroom21, QString::fromStdString(Bathroom2::getInstance().getItems().at(0).getPath()));

    //Garden Items
    Garden::getInstance().createItems();
    setImageButton(ui->ItemGarden1, QString::fromStdString(Garden::getInstance().getItems().at(1).getPath()));
    setImageButton(ui->ItemGarden2, QString::fromStdString(Garden::getInstance().getItems().at(0).getPath()));

    //Pool Items
    Pool::getInstance().createItems();
    setImageButton(ui->ItemPool1, QString::fromStdString(Pool::getInstance().getItems().at(0).getPath()));


}

void MainWindow::hideItems(){
    ui->ItemDriveway1->hide();
    ui->ItemHall1->hide();
    ui->ItemLivingroom1->hide();
    ui->ItemLivingroom2->hide();
    ui->ItemKitchen1->hide();
    ui->ItemBathroom11->hide();
    ui->ItemBedroom1->hide();
    ui->ItemBedroom2->hide();
    ui->ItemDiningroom1->hide();
    ui->ItemBathroom21->hide();
    ui->ItemGarden1->hide();
    ui->ItemGarden2->hide();
    ui->ItemPool1->hide();

}

void MainWindow::showItemsDriveway(){
    ui->ItemDriveway1->show();
}

void MainWindow::showItemsHall(){
    ui->ItemHall1->show();
}

void MainWindow::showItemsLivingroom(){
    ui->ItemLivingroom1->show();
    ui->ItemLivingroom2->show();
}


void MainWindow::showItemsDiningroom(){
    ui->ItemDiningroom1->show();

}
void MainWindow::showItemsKitchen(){
    ui->ItemKitchen1->show();

}

void MainWindow::showItemsBedroom(){
    ui->ItemBedroom1->show();
    ui->ItemBedroom2->show();
}
void MainWindow::showItemsBathroom1(){
    ui->ItemBathroom11->show();
}
void MainWindow::showItemsBathroom2(){
    ui->ItemBathroom21->show();
}
void MainWindow::showItemsGarden(){
    ui->ItemGarden1->show();
    ui->ItemGarden2->show();
}
void MainWindow::showItemsPool(){
    ui->ItemPool1->show();
}






void MainWindow::on_upButton_clicked()
{
    //cout<<"up button:" << Player::getInstance().getRoom()->getName()<<endl;


    Player::getInstance().getRoom()->goUp();

}


void MainWindow::on_downButton_clicked()
{
    //cout<< "down button:"<< Player::getInstance().getRoom()->getName()<<endl;

    Player::getInstance().getRoom()->goDown();
}


void MainWindow::on_leftButton_clicked()
{
    Player::getInstance().getRoom()->goLeft();
}


void MainWindow::on_rightButton_clicked()
{
    Player::getInstance().getRoom()->goRight();
}


void MainWindow::on_mapButton_clicked()
{
    cout<<"SHOW MAP"<<endl;
}





//Collecting items
void MainWindow::on_ItemHall1_clicked()
{
    collectItem(ui->ItemHall1, Hall::getInstance().getItems().at(0));

}


void MainWindow::on_ItemBathroom11_clicked()
{
    collectItem(ui->ItemBathroom11, Bathroom1::getInstance().getItems().at(0));
}


void MainWindow::on_ItemBathroom21_clicked()
{
    collectItem(ui->ItemBathroom21, Bathroom2::getInstance().getItems().at(0));
}


void MainWindow::on_ItemBedroom1_clicked()
{
    collectItem(ui->ItemBedroom1, Bedroom::getInstance().getItems().at(0));
}


void MainWindow::on_ItemBedroom2_clicked()
{
    collectItem(ui->ItemBedroom2, Bedroom::getInstance().getItems().at(1));
}


void MainWindow::on_ItemDiningroom1_clicked()
{
    collectItem(ui->ItemDiningroom1, Diningroom::getInstance().getItems().at(0));
}


void MainWindow::on_ItemGarden1_clicked()
{
    collectItem(ui->ItemGarden1, Garden::getInstance().getItems().at(1));
}


void MainWindow::on_ItemGarden2_clicked()
{
    collectItem(ui->ItemGarden2, Garden::getInstance().getItems().at(0));
}


void MainWindow::on_ItemKitchen1_clicked()
{
    collectItem(ui->ItemKitchen1, Kitchen::getInstance().getItems().at(0));
}


void MainWindow::on_ItemLivingroom1_clicked()
{
    collectItem(ui->ItemLivingroom1, Livingroom::getInstance().getItems().at(0));
}


void MainWindow::on_ItemLivingroom2_clicked()
{
    collectItem(ui->ItemLivingroom2, Livingroom::getInstance().getItems().at(1));
}


void MainWindow::on_ItemPool1_clicked()
{
    collectItem(ui->ItemPool1, Pool::getInstance().getItems().at(0));
}

