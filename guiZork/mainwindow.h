#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

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



private slots:
    void setBackground(const QString& imagePath);
    void setImageLabel(QLabel* label, const QString& imagePath);
    void setImageButton(QPushButton* button, const QString& imagePath);
    void on_startButton_clicked();
    void modifyButtonVisibility(bool isVisible);
    void modifyButtonAvailability(bool isEnabled);

    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_mapButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
