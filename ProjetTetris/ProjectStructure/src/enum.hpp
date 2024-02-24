#ifndef ENUM_HPP
#define ENUM_HPP

// Enum for TypeShape
enum class TypeShape {
    O_SHAPE,
    I_SHAPE,
    S_SHAPE,
    Z_SHAPE,
    L_SHAPE,
    J_SHAPE,
    T_SHAPE
};

// Enum for Orientation
enum class Orientation {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Enum for Direction
enum class Direction {
    RIGHT,
    DOWN,
    LEFT
};

// Enum for Rotation
enum class Rotation {
    CLOCKWISE,
    COUNTERCLOCKWISE
};


// Enum for State
enum class State {
    READY,
    PLAYING,
    GAMEOVER
};



#endif // ENUM_HPP
