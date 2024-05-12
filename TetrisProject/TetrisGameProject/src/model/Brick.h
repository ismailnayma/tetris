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
    TypeShape getTypeShape() const;
    Orientation getOrientation() const;
    Position getBoardPosition() const;
    void setOrientation(Orientation o);
    void setBoardPosition(Position p);
};

#endif // BRICK_H
