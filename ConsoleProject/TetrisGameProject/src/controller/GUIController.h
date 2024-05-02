#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QObject>
#include <QTimer>
#include "../model/Game.h"
#include "../view/gui/startwindow.h"
#include "../view/gui/mainwindow.h"
#include "../view/gui/restartwindow.h"
#include "../util/Observer.h"


class GUIController : public QObject, public Observer
{
    Q_OBJECT
public:
    explicit GUIController(QObject *parent = nullptr);
    void update() override;

private slots:
    void playButtonHandler();
    void restartGame();
    void quitGame();
    void intervalAction();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Game model;
    StartWindow startWindow;
    MainWindow mainWindow;
    RestartWindow restartWindow;
    QTimer timer;

};

#endif // GUICONTROLLER_H
