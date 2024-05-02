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
public:
    explicit GUIController(QObject *parent = nullptr);
    void update() override;
    void stopTimer();

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
