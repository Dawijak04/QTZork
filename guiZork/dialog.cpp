#include "dialog.h"
#include "ui_dialog.h"
#include "Exceptions.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    setImageLabel(ui->mapLabel, "D:/Downloads/ZorkImages/Empty.png");
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::setImageLabel(QLabel* label, const QString& imagePath) {
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



void Dialog::setLabelWelcomeMessage() {
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    ui->WelcomeMessage->setText("Welcome to Zork  \n\nYou're mission is to break into the house and collect \nthe most valuable items you can find. \nYou've 5 spaces in your inventory (plus 1 for car keys) \n- Diamonds are worth $20 \n- Gold is worth $15 \n- Cash is worth $10\nInventory value is displayed in the red box\nRemember, once you picked something up, you \ncan't but it back down or else you'd be leaving \nfingerprints. \nCollect atleast $75 to win, also don't forget to collect \nthe car keys \n\n Good Luck!");
}

void Dialog::setLabelWinningMessage(){
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    ui->WelcomeMessage->setText("You win");
}
void Dialog::setLabelLosingMessage(){
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    ui->WelcomeMessage->setText("You lose");
}


void Dialog::showMap(){
    ui->WelcomeMessage->setText("");
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/Map.png");
}

void Dialog::errorMessageInvalidRoom(){
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    try {
        throw InvalidDirectionException();
    } catch (const InvalidDirectionException& e) {
        ui->WelcomeMessage->setText(e.message());
    }
}

void Dialog::errorMessageRestrictedAccess(){
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    try {
        throw RestrictedAccessException();
    } catch (const RestrictedAccessException& e) {
        ui->WelcomeMessage->setText(e.message());
    }
}
void Dialog::errorMessageFullInventory(){
    setImageLabel(ui->BackgroundLabel, "D:/Downloads/ZorkImages/OldPaper.webp");
    try {
        throw FullInventoryException();
    } catch (const FullInventoryException& e) {
        ui->WelcomeMessage->setText(e.message());
    }
}
