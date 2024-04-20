#ifndef BRICKWIDGET_H
#define BRICKWIDGET_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include "../../model/Brick.h"

class BrickWidget : public QWidget, public QGraphicsItem {
    Q_OBJECT
public:
    explicit BrickWidget(QWidget *parent = nullptr);
    void setBrickType(TypeShape type); // Set the type of brick
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

private:
    TypeShape brickType;
};

#endif // BRICKWIDGET_H
