#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../model/Game.h"
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(Game& game, QWidget *parent = nullptr);
    void initialize();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;
    Game& game;

    QColor getColorForShape(std::optional<TypeShape> shapeOpt) const;
    void displayBoard();
    void displayCurrentBrick();
};

#endif // MAINWINDOW_H

