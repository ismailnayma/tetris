#ifndef ENUMS_H
#define ENUMS_H

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

enum class Orientation {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum class Direction {
    RIGHT,
    DOWN,
    LEFT
};

enum class Rotation {
    CLOCKWISE,
    COUNTERCLOCKWISE
};

enum class GameState {
    PLAYING,
    LOSS,
    SCOREWIN,
    LINESWIN,
    TIMELOSS
};

#endif // ENUMS_H
