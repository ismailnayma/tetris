#include "Brick.h"

Brick::Brick(TypeShape s, Orientation o, Position p) : shape(s), orientation(o), boardPosition(p) {}

Orientation Brick::getOrientation() const {
    return orientation;
}

void Brick::setOrientation(Orientation o) {
    orientation = o;
}

Position Brick::getBoardPosition() const {
    return boardPosition;
}

void Brick::setBoardPosition(Position p) {
    boardPosition = p;
}

TypeShape Brick::getTypeShape() const {
    return shape;
}
