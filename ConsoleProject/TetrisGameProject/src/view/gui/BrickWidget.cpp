#include "BrickWidget.h"

BrickWidget::BrickWidget(QWidget *parent) : QWidget(parent) {
    // Set default brick type
    brickType = TypeShape::O_SHAPE; // You can set default type as needed
}

void BrickWidget::setBrickType(TypeShape type) {
    brickType = type;
    update(); // Call update to trigger repaint
}

void BrickWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // Draw the brick based on its type
    switch(brickType) {
    case TypeShape::O_SHAPE:
        painter->drawRect(QRectF(0, 0, 20, 20)); // Example drawing for O_SHAPE
        break;
        // Add cases for other brick types as needed
    }
}

QRectF BrickWidget::boundingRect() const {
    return QRectF(0, 0, 20, 20); // Set the bounding rectangle size of the brick widget
}
