#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QObject>
#include "../model/Game.h"
#include "../view/gui/startwindow.h"
#include "../view/gui/mainwindow.h"
#include "../view/gui/CustomMessageBox.h"
#include "../util/Observer.h"


class GUIController : public QObject, public Observer
{
    Q_OBJECT
public:
    explicit GUIController(QObject *parent = nullptr);
    void update() override;

public slots:
    void playButtonHandler();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Game model;
    StartWindow startWindow;
    MainWindow mainWindow;
    CustomMessageBox messageBox;

};

#endif // GUICONTROLLER_H
