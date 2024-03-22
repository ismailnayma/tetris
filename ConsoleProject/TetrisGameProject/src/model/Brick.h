#ifndef BRICK_H
#define BRICK_H

#include "Enums.h"
#include "Position.h"

class Brick {
private:
    TypeShape shape;
    Orientation orientation;
    Position boardPosition;

public:

    Brick(TypeShape s = TypeShape::I_SHAPE, Orientation o = Orientation::UP, Position p = Position());

    Orientation getOrientation() const;
    void setOrientation(Orientation o);

    Position getBoardPosition() const;
    void setBoardPosition(Position p);

    TypeShape getTypeShape() const;
};
#endif // BRICK_H
