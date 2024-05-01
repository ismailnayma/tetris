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

#include <QKeyEvent>
#include <QDebug>
#include <QShortcut> // Si vous utilisez des raccourcis clavier
#include "CustomMessageBox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    explicit MainWindow(Game* game, QWidget *parent = nullptr);
    ~MainWindow();
    void update() override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene; // La scène pour QGraphicsView
    Game* game;

    QColor getColorForShape(std::optional<TypeShape> shapeOpt) const;
    void displayBoard();
    void displayCurrentBrick();
    void initialize();
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // MAINWINDOW_H

