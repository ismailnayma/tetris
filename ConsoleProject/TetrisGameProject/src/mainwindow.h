#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>

#include "model/Game.h"
#include "view/gui/BoardWidget.h"
#include "controller/GUIController.h"
#include "util/Observer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    explicit MainWindow(Game& game, QWidget *parent = nullptr);
    ~MainWindow();
    void update() override;

private:
    Ui::MainWindow *ui;

    //QGraphicsScene _scene; // La scène pour QGraphicsView

    Game& game;
    GUIController *controller; // Déclaration du contrôleur

    BoardWidget *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;

    QLabel *createLabel(const QString &text);

};

#endif // MAINWINDOW_H

