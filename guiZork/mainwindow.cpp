#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QPixmap>
#include "Player.h"
#include "dialog.h"

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
#include "Car.h"
#include "globals.h"



//namespace declaration
using namespace std;

//Debug macro
//#define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(msg) \
    cerr << "Debug: " << msg << endl;
#else
    #define DEBUG_MSG(msg)
#endif





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    //GUI element lists
    inventorySlots = { ui->InventorySlot1, ui->InventorySlot2, ui->InventorySlot3, ui->InventorySlot4, ui->InventorySlot5, ui->InventorySlotKeys };
    inventorySpaces = {ui->InventorySpace1, ui->InventorySpace2, ui->InventorySpace3, ui->InventorySpace4, ui->InventorySpace5, ui->InventorySpaceKeys};
    arrowButtons = {ui->mapButton, ui->leftButton, ui->rightButton, ui->downButton, ui->upButton};
    items = {ui->ItemDriveway1, ui->ItemHall1, ui->ItemLivingroom1, ui->ItemLivingroom2, ui->ItemKitchen1, ui->ItemBathroom11, ui->ItemBedroom1, ui->ItemBedroom2, ui->ItemDiningroom1, ui->ItemBathroom21, ui->ItemGarden1, ui->ItemGarden2, ui->ItemPool1};


}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
    DEBUG_MSG("deleting main window");

}


//Function to set background label
void MainWindow::setBackground(const QString& imagePath) {
    QPixmap pix(imagePath);
    if (pix.isNull()) {
        DEBUG_MSG("failed to load image");
        return;
    }
    QString styleSheet = QString("background-image: url(%1);").arg(imagePath);
    setStyleSheet(styleSheet);
}


//Sets labels to images
void MainWindow::setImageLabel(QLabel* label, const QString& imagePath) {
    if (!label || imagePath.isEmpty()) {
        return;
    }
    QPixmap pix(imagePath);
    if (pix.isNull()) {
        DEBUG_MSG("failed to load image");
        return;
    }
    int w = label->width();
    int h = label->height();
    label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}


//Sets buttons to images
void MainWindow::setImageButton(QPushButton* button, const QString& imagePath) {
    if (!button || imagePath.isEmpty()) {
        return;
    }
    QPixmap icon(imagePath);
    if (icon.isNull()) {
        DEBUG_MSG("failed to load image");
        return;
    }
    QSize buttonSize = button->size();
    icon = icon.scaled(buttonSize, Qt::KeepAspectRatio);
    button->setIcon(QIcon(icon));
    button->setIconSize(buttonSize);
    button->setStyleSheet("background-color: transparent; border: none;");
}






//Start screen
void MainWindow::startScreen(){
    setImageLabel(ui->label_background, ":/images/images/start.jpeg");
    setImageButton(ui->startButton, ":/images/images/start.png");
    hideItems();
    createInventory();
    ui->startButton->setEnabled(true);
    modifyButtonVisibility(false);
    DEBUG_MSG("start screen initialized");

}


//Setters for background image (set GUI, show specific items and update player instance location)
void MainWindow::setDriveway(){
    setImageLabel(ui->label_background, ":/images/images/driveway.jpg");
    hideItems();
    showItemsDriveway();
    Player::getInstance().setRoom(&Driveway::getInstance());
    DEBUG_MSG("set driveway");
}

void MainWindow::setHall(){
    setImageLabel(ui->label_background, ":/images/images/hall.jpg");
    hideItems();
    showItemsHall();
    Player::getInstance().setRoom(&Hall::getInstance());
    DEBUG_MSG("set hall");
}

void MainWindow::setKitchen(){
    setImageLabel(ui->label_background, ":/images/images/kitchen.png");
    hideItems();
    showItemsKitchen();
    Player::getInstance().setRoom(&Kitchen::getInstance());
    DEBUG_MSG("set kitchen");
}

void MainWindow::setDiningRoom(){
    setImageLabel(ui->label_background, ":/images/images/diningRoom.webp");
    hideItems();
    showItemsDiningroom();
    Player::getInstance().setRoom(&Diningroom::getInstance());
    DEBUG_MSG("set dining room");
}

void MainWindow::setLivingRoom(){
    setImageLabel(ui->label_background, ":/images/images/livingRoom.jpg");
    hideItems();
    showItemsLivingroom();
    Player::getInstance().setRoom(&Livingroom::getInstance());
    DEBUG_MSG("set living room");
}

void MainWindow::setBathroom1(){
    setImageLabel(ui->label_background, ":/images/images/bathroom1.webp");
    hideItems();
    showItemsBathroom1();
    Player::getInstance().setRoom(&Bathroom1::getInstance());
    DEBUG_MSG("set bathroom 1");
}

void MainWindow::setGarden(){
    setImageLabel(ui->label_background, ":/images/images/garden.webp");
    hideItems();
    showItemsGarden();
    Player::getInstance().setRoom(&Garden::getInstance());
    DEBUG_MSG("set garden");
}

void MainWindow::setBedroom(){
    setImageLabel(ui->label_background, ":/images/images/bedroom.jpg");
    hideItems();
    showItemsBedroom();
    Player::getInstance().setRoom(&Bedroom::getInstance());
    DEBUG_MSG("set bedroom");
}

void MainWindow::setPool(){
    setImageLabel(ui->label_background, ":/images/images/pool.jpg");
    hideItems();
    showItemsPool();
    Player::getInstance().setRoom(&Pool::getInstance());
    DEBUG_MSG("set pool");
}

void MainWindow::setBathroom2(){
    setImageLabel(ui->label_background, ":/images/images/bathroom2.jpg");
    hideItems();
    showItemsBathroom2();
    Player::getInstance().setRoom(&Bathroom2::getInstance());
    DEBUG_MSG("set bathroom 2");
}





//Modifies visibility of arrow pad, and inventory
void MainWindow::modifyButtonVisibility(bool isVisible) {
    for (QPushButton* button : arrowButtons) {
        button->setVisible(isVisible);
    }

    for (QLabel* label : inventorySlots){
        label->setVisible(isVisible);
    }
    ui->valueLabel->setVisible(isVisible);
}

//Modifies arrow pad availability
void MainWindow::modifyButtonAvailability(bool isEnabled) {
    for (QPushButton* button: arrowButtons){
        button->setEnabled(isEnabled);
    }
}

//Function to collect items
void MainWindow::collectItem(QPushButton* button, Item item){

    if(Player::getInstance().getInventorySize() < ::MAX_ITEMS){ //checks inventory size
        button->setEnabled(false); //disables item
        setImageButton(button, "D:/Downloads/ZorkImages/Empty.png"); //removes from GUI
        DEBUG_MSG("item:" << item.getName() <<" collected (GUI)");

        Item ItemCopy = Item(item); //shallow copy constructor
        Player::getInstance().addItem(ItemCopy); //adds to player inventory
        addToInventory(ItemCopy);  //adds to GUI inventory
        DEBUG_MSG("item: " << ItemCopy.getName()<<" collected (Player)");

        ui->InventoryValue->setText("$" + QString::number(Player::getInstance().getInventoryValue())); //updates inventory value

    }else{
        DEBUG_MSG("Full inventory");
        fullInventoryError(); //full inventory exception
    }
}


//checks if image is displaying
bool MainWindow::isLabelDisplayingImage(const QLabel* label) {
    if (label) {
        const QPixmap pixmap = label->pixmap().copy();
        return !pixmap.isNull();
    }
    return false;
}


//initializes GUI inventory
void MainWindow::createInventory(){
    for (QLabel* label : inventorySlots) {
        setImageLabel(label, ":/images/images/slot.webp");
    }
    setImageLabel(ui->valueLabel, ":/images/images/valueLabel.webp");
}

//adds to GUI inventory
void MainWindow::addToInventory(Item item){
    for (QLabel* label : inventorySpaces) {
        if (!isLabelDisplayingImage(label)) {
            setImageLabel(label, QString::fromStdString(item.getPath()));
            break;
        }
    }
}


//Welcome message
void MainWindow::showPopUpWelcome(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.setLabelWelcomeMessage();
    popUp.exec();
}

//Winning message
void MainWindow::showPopUpWin(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.setLabelWinningMessage();
    popUp.exec();
}

//Losing message
void MainWindow::showPopUpLose(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.setLabelLosingMessage();
    popUp.exec();
}

//Display map
void MainWindow::showMap(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.showMap();
    popUp.exec();
}

//Full inventory excpetion
void MainWindow::fullInventoryError(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.errorMessageFullInventory();
    popUp.exec();
}

//Invalid room exception
void MainWindow::invalidRoomError(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.errorMessageInvalidRoom();
    popUp.exec();
}

//Restricted access exception
void MainWindow::restrictedAccessError(){
    Dialog popUp;
    popUp.setModal(true);
    popUp.errorMessageRestrictedAccess();
    popUp.exec();
}

//Start button pressed
void MainWindow::on_startButton_clicked(){
    //Assign pointer to window to main window
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

    //initialize items in each room
    initializeItems();

    //set start value for inventory
    ui->InventoryValue->setText(QString::number(Player::getInstance().getInventoryValue()));


    //show inventory and arrow pads
    modifyButtonVisibility(true);

    //enable arrow pads
    modifyButtonAvailability(true);

    //hide start button
    ui->startButton->hide();

    //set player location to start location (i.e. driveway)
    Player::getInstance().setRoom(&Driveway::getInstance());
    //set background
    Player::getInstance().getRoom()->setRoom();
    //set having car keys to false
    Player::getInstance().setHasCarKeys(0);

    //display welcome message pop up window
    showPopUpWelcome();

}


//create items for each room and add them to each rooms vector of items
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

//hide all items
void MainWindow::hideItems(){
    for(QPushButton* item : items){
        item->hide();
    }
}




//show unique items for each room

//driveway
void MainWindow::showItemsDriveway(){
    ui->ItemDriveway1->show();
}

//hall
void MainWindow::showItemsHall(){
    ui->ItemHall1->show();
}

//living room
void MainWindow::showItemsLivingroom(){
    ui->ItemLivingroom1->show();
    ui->ItemLivingroom2->show();
}

//dining room
void MainWindow::showItemsDiningroom(){
    ui->ItemDiningroom1->show();
}

//kitchen
void MainWindow::showItemsKitchen(){
    ui->ItemKitchen1->show();
}

//bedroom
void MainWindow::showItemsBedroom(){
    ui->ItemBedroom1->show();
    ui->ItemBedroom2->show();
}

//bathroom 1
void MainWindow::showItemsBathroom1(){
    ui->ItemBathroom11->show();
}

//bathroom 2
void MainWindow::showItemsBathroom2(){
    ui->ItemBathroom21->show();
}

//garden
void MainWindow::showItemsGarden(){
    ui->ItemGarden1->show();
    ui->ItemGarden2->show();
}

//pool
void MainWindow::showItemsPool(){
    ui->ItemPool1->show();
}



//Arrow pad button handling functions


void MainWindow::on_upButton_clicked(){
    Player::getInstance().getRoom()->goUp();//set to room above current
}


void MainWindow::on_downButton_clicked(){
    Player::getInstance().getRoom()->goDown(); //set to room below current
}


void MainWindow::on_leftButton_clicked(){
    Player::getInstance().getRoom()->goLeft(); //set to room left of current
}

void MainWindow::on_rightButton_clicked(){
    Player::getInstance().getRoom()->goRight(); //set to room right of current
}


//display map pop up
void MainWindow::on_mapButton_clicked(){
    showMap();
}





//Collecting items
void MainWindow::on_ItemHall1_clicked(){
    collectItem(ui->ItemHall1, Hall::getInstance().getItems().at(0));
}

void MainWindow::on_ItemBathroom11_clicked(){
    collectItem(ui->ItemBathroom11, Bathroom1::getInstance().getItems().at(0));
}

void MainWindow::on_ItemBathroom21_clicked(){
    collectItem(ui->ItemBathroom21, Bathroom2::getInstance().getItems().at(0));
}

void MainWindow::on_ItemBedroom1_clicked(){
    collectItem(ui->ItemBedroom1, Bedroom::getInstance().getItems().at(0));
}

void MainWindow::on_ItemBedroom2_clicked(){
    collectItem(ui->ItemBedroom2, Bedroom::getInstance().getItems().at(1));
}

void MainWindow::on_ItemDiningroom1_clicked(){
    collectItem(ui->ItemDiningroom1, Diningroom::getInstance().getItems().at(0));
}

void MainWindow::on_ItemGarden1_clicked()
{
    collectItem(ui->ItemGarden1, Garden::getInstance().getItems().at(1));
}

void MainWindow::on_ItemGarden2_clicked(){
    collectItem(ui->ItemGarden2, Garden::getInstance().getItems().at(0));
}


//car keys are handled uniquely because they've a reserved spot outside of inventory
void MainWindow::on_ItemKitchen1_clicked(){
    ui->ItemKitchen1->setEnabled(false);
    setImageButton(ui->ItemKitchen1, ":/images/images/Empty.png");
    setImageLabel(ui->InventorySpaceKeys, QString::fromStdString(Kitchen::getInstance().getItems().at(0).getPath()));
    Player::getInstance().setHasCarKeys(1);
}

void MainWindow::on_ItemLivingroom1_clicked(){
    collectItem(ui->ItemLivingroom1, Livingroom::getInstance().getItems().at(0));
}

void MainWindow::on_ItemLivingroom2_clicked(){
    collectItem(ui->ItemLivingroom2, Livingroom::getInstance().getItems().at(1));
}


void MainWindow::on_ItemPool1_clicked(){
    collectItem(ui->ItemPool1, Pool::getInstance().getItems().at(0));
}


//Finishing game (clicking on car)
void MainWindow::on_ItemDriveway1_clicked(){
    if(Car::getInstance().checkEligibility()){
        MainWindow::close();

        if(Car::getInstance().completeGame()){
            showPopUpWin();
            DEBUG_MSG("player wins");
        }else{
            showPopUpLose();
            DEBUG_MSG("player loses");
        }

    }else{
        restrictedAccessError();
        DEBUG_MSG("no access to car");
    };
}



