#include "Brick.h"

Brick::Brick(TypeShape typeShape, Orientation orientation, Position position)
    : shape(typeShape), orientation(orientation), boardPosition(position) {}

Orientation Brick::getOrientation() const {
    return orientation;
}

void Brick::setOrientation(Orientation orientation) {
    orientation = orientation;
}

Position Brick::getBoardPosition() const {
    return boardPosition;
}

void Brick::setBoardPosition(Position position) {
    boardPosition = position;
}

TypeShape Brick::getTypeShape() const {
    return shape;
}
