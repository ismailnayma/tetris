#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QObject>
#include "../model/Game.h"

class GUIController : public QObject
{
    Q_OBJECT
public:
    explicit GUIController(Game &model, QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Game& model;
};

#endif // GUICONTROLLER_H
