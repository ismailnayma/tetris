#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_startwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::StartWindow *ui;
    QGraphicsScene _scene;

public:
    explicit StartWindow(QWidget *parent = nullptr);
    int getWidthSpinBox() const;
    int getHeightSpinBox() const;
    bool getPrefilledChoice() const;
    Ui::StartWindow& getUi() const;
    ~StartWindow();

public slots:
   // void playButton();

};

#endif // STARTWINDOW_H
