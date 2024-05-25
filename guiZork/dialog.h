#ifndef DIALOG_H
#define DIALOG_H
#include <QLabel>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setImageLabel(QLabel* label, const QString& imagePath);
    void setLabelWelcomeMessage();
    void setLabelWinningMessage();
    void setLabelLosingMessage();
    void showMap();
    void errorMessageInvalidRoom();
    void errorMessageRestrictedAccess();
    void errorMessageFullInventory();



private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
