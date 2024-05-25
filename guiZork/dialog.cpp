#include "dialog.h"
#include "ui_dialog.h"
#include "Exceptions.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    setImageLabel(ui->mapLabel, ":/images/images/Empty.png");
}


//destructor
Dialog::~Dialog()
{
    delete ui;
}


//setting label to image
void Dialog::setImageLabel(QLabel* label, const QString& imagePath) {
    if (!label || imagePath.isEmpty()) {
        return;
    }
    QPixmap pix(imagePath);
    if (pix.isNull()) {
        return;
    }
    int w = label->width();
    int h = label->height();
    label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}


//methods to set message to label

//Welcome
void Dialog::setLabelWelcomeMessage() {
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    ui->MessageLabel->setText("Welcome to Zork  \n\nYou're mission is to break into the house and collect \nthe most valuable items you can find. \nYou've 5 spaces in your inventory (plus 1 for car keys) \n- Diamonds are worth $20 \n- Gold is worth $15 \n- Cash is worth $10\nInventory value is displayed in the red box\nRemember, once you picked something up, you \ncan't but it back down or else you'd be leaving \nfingerprints. \nCollect atleast $75 to win, also don't forget to collect \nthe car keys \n\n Good Luck!");
}

//Win
void Dialog::setLabelWinningMessage(){
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    ui->MessageLabel->setText("You win");
}

//Lose
void Dialog::setLabelLosingMessage(){
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    ui->MessageLabel->setText("You lose");
}

//Display map
void Dialog::showMap(){
    ui->MessageLabel->setText("");
    setImageLabel(ui->BackgroundLabel, ":/images/images/Map.png");
}

//invalid room choce exception
void Dialog::errorMessageInvalidRoom(){
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    try {
        throw InvalidDirectionException();
    } catch (const InvalidDirectionException& e) {
        ui->MessageLabel->setText(e.message());
    }
}

//no car keys exception
void Dialog::errorMessageRestrictedAccess(){
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    try {
        throw RestrictedAccessException();
    } catch (const RestrictedAccessException& e) {
        ui->MessageLabel->setText(e.message());
    }
}

//full inventory exception
void Dialog::errorMessageFullInventory(){
    setImageLabel(ui->BackgroundLabel, ":/images/images/OldPaper.webp");
    try {
        throw FullInventoryException();
    } catch (const FullInventoryException& e) {
        ui->MessageLabel->setText(e.message());
    }
}
