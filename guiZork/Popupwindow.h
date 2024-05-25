#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H
#include <QDialog>

namespace Ui{
    class PopupWindow;
}

class PopupWindow : public QDialog{

    Q_OBJECT

public:
    explicit PopupWindow(QWidget *parent = nullptr);
    ~PopupWindow();

    void setText(const QString& text);

private:
    Ui::PopupWindow *ui;
};

#endif // POPUPWINDOW_H



