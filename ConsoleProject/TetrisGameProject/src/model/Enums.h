#ifndef ENUMS_H
#define ENUMS_H

// Enum for TypeShape
enum class TypeShape {
    O_SHAPE,
    I_SHAPE,
    S_SHAPE,
    Z_SHAPE,
    L_SHAPE,
    J_SHAPE,
    T_SHAPE,
    TYPESHAPE_NUMBER
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


// Enum for GameState
enum class GameState {
    PLAYING,
    LOSS,
    SCOREWIN,
    LINESWIN
};


#endif // ENUMS_H
