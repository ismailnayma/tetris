#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>

#include "../../model/Game.h"
#include "../../controller/GUIController.h"
#include "../../util/Observer.h"

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

    QGraphicsScene _scene; // La scène pour QGraphicsView

    Game& game;
    GUIController *controller; // Déclaration du contrôleur

    QColor getColorForShape(std::optional<TypeShape> shapeOpt) const;
    void displayBoard();
    void displayCurrentBrick();
    void initialize();


};

#endif // MAINWINDOW_H

