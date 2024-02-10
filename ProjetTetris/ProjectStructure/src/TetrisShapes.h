#ifndef TETRISSHAPES_H
#define TETRISSHAPES_H

#include <array>

class TetrisShapes {
private:

    static TetrisShapes* tetrisShapesinstance;
    static constexpr int NUM_BRICK_TYPES = 7;
    static constexpr int NUM_ROTATIONS = 4;
    static constexpr int SIZE = 4;
    std::array<std::array<std::array<std::array<int, SIZE>, SIZE>, NUM_ROTATIONS>, NUM_BRICK_TYPES> shapes;

    TetrisShapes() : shapes(createShapes()) {}
    static std::array<std::array<std::array<std::array<int, SIZE>, SIZE>, NUM_ROTATIONS>, NUM_BRICK_TYPES>  createShapes();


public:
    TetrisShapes(TetrisShapes &other)= delete;
    void operator=(const TetrisShapes &)= delete;
    static TetrisShapes* getInstance();
    const std::array<std::array<int, SIZE>, SIZE>& getShape(int kind, int orientation) const;
   // ~TetrisShapes();

};


#endif // TETRISSHAPES_H
