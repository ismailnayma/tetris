#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include "../model/Game.h"
#include "../view/gui/startwindow.h"
#include "../view/gui/mainwindow.h"
#include "../view/gui/restartwindow.h"
#include "../util/Observer.h"
#include <QObject>
#include <QTimer>

class GUIController : public QObject, public Observer
{
    Q_OBJECT

private:
    Game model;
    StartWindow startWindow;
    MainWindow mainWindow;
    RestartWindow restartWindow;
    QTimer timerInterval;
    QTimer timerDuration;

    bool eventFilter(QObject *obj, QEvent *event) override;
    void update() override;
    void stopTimers();
    void handleEndGame(QString message = "");

private slots:
    void playButtonHandler();
    void intervalAction();
    void restartGame();
    void quitGame();

public:
    explicit GUIController(QObject *parent = nullptr);
};

#endif // GUICONTROLLER_H
