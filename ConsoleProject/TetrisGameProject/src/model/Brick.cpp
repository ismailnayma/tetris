#include "Brick.h"

Brick::Brick(TypeShape typeShape, Orientation orientation, Position position)
    : shape(typeShape), orientation(orientation), boardPosition(position) {}

TypeShape Brick::getTypeShape() const {
    return shape;
}

Orientation Brick::getOrientation() const {
    return orientation;
}

Position Brick::getBoardPosition() const {
    return boardPosition;
}

void Brick::setOrientation(Orientation orientation) {
    orientation = orientation;
}

void Brick::setBoardPosition(Position position) {
    boardPosition = position;
}
