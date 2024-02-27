#ifndef BRICK_HPP
#define BRICK_HPP

#include "enum.hpp"
#include "position.hpp"
#include <iostream>

class Brick {
private:
    TypeShape shape;
    Orientation orientation;
    Position boardPosition;

public:

    Brick() = default;
    /**
     * @brief Constructor for the Brick class.
     * @param s TypeShape of the brick.
     * @param o Initial orientation of the brick.
     * @param p Initial position of the brick.
     */
    Brick(TypeShape s, Orientation o, Position p) : shape(s), orientation(o), boardPosition(p) {}

    /**
     * @brief Getter for the orientation of the brick.
     * @return The current orientation.
     */
    Orientation getOrientation() const {
        return orientation;
    }

    /**
     * @brief Setter for the orientation of the brick.
     * @param o The new orientation to set.
     */
    void setOrientation(Orientation o) {
        orientation = o;
    }

    /**
     * @brief Getter for the position of the brick.
     * @return The current position.
     */
    Position getBoardPosition() const {
        return boardPosition;
    }

    /**
     * @brief Setter for the position of the brick.
     * @param p The new position to set.
     */
    void setBoardPosition(Position p) {
        boardPosition = p;
    }

    /**
     * @brief Getter for the TypeShape of the brick.
     * @return The TypeShape of the brick.
     */
    TypeShape getTypeShape() const {
        return shape;
    }
};



#endif // BRICK_HPP
