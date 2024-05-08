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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}



void MainWindow::startScreen(){
    //setBackground("D:/Downloads/ZorkImages/start.jpeg");
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/start.jpeg");
    setImageButton(ui->startButton, "D:/Downloads/ZorkImages/start.png");
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
    Player::getInstance().setRoom(&Kitchen::getInstance());
}

void MainWindow::setDiningRoom(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/diningRoom.webp");
    hideItems();
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
    Player::getInstance().setRoom(&Bathroom1::getInstance());
}

void MainWindow::setGarden(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/garden.webp");
    hideItems();
    Player::getInstance().setRoom(&Garden::getInstance());
}

void MainWindow::setBedroom(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/bedroom.jpg");
    hideItems();
    Player::getInstance().setRoom(&Bedroom::getInstance());
}

void MainWindow::setPool(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/pool.jpg");
    hideItems();
    Player::getInstance().setRoom(&Pool::getInstance());
}

void MainWindow::setBathroom2(){
    setImageLabel(ui->label_background, "D:/Downloads/ZorkImages/bathroom2.jpg");
    hideItems();
    Player::getInstance().setRoom(&Bathroom2::getInstance());
}






void MainWindow::modifyButtonVisibility(bool isVisible) {
    ui->leftButton->setVisible(isVisible);
    ui->rightButton->setVisible(isVisible);
    ui->downButton->setVisible(isVisible);
    ui->upButton->setVisible(isVisible);
    ui->mapButton->setVisible(isVisible);
}

void MainWindow::modifyButtonAvailability(bool isEnabled) {
    ui->leftButton->setEnabled(isEnabled);
    ui->rightButton->setEnabled(isEnabled);
    ui->downButton->setEnabled(isEnabled);
    ui->upButton->setEnabled(isEnabled);
    ui->mapButton->setEnabled(isEnabled);
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
    setImageLabel(ui->ItemDriveway1, QString::fromStdString(Driveway::getInstance().getItems().at(0).getPath()));

    //Hall Items
    Hall::getInstance().createItems();
    setImageLabel(ui->ItemHall1, QString::fromStdString(Hall::getInstance().getItems().at(0).getPath()));

    //Living Room Items
    Livingroom::getInstance().createItems();
    setImageLabel(ui->ItemLivingroom1, QString::fromStdString(Livingroom::getInstance().getItems().at(0).getPath()));
    setImageLabel(ui->ItemLivingroom2, QString::fromStdString(Livingroom::getInstance().getItems().at(1).getPath()));



    hideItems();

}

void MainWindow::hideItems(){
    ui->ItemDriveway1->hide();
    ui->ItemHall1->hide();
    ui->ItemLivingroom1->hide();
    ui->ItemLivingroom2->hide();

}

void MainWindow::showItemsDriveway(){
    hideItems();
    ui->ItemDriveway1->show();
}

void MainWindow::showItemsHall(){
    hideItems();
    ui->ItemHall1->show();
}

void MainWindow::showItemsLivingroom(){
    hideItems();
    ui->ItemLivingroom1->show();
    ui->ItemLivingroom2->show();
}


void MainWindow::showItemsDiningroom(){

}
void MainWindow::showItemsKitchen(){

}

void MainWindow::showItemsBedroom(){

}
void MainWindow::showItemsBathroom1(){

}
void MainWindow::showItemsBathroom2(){

}
void MainWindow::showItemsGarden(){

}
void MainWindow::showItemsPool(){

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

