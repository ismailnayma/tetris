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
    std::array<std::array<std::array<std::array<int, SIZE>, SIZE>, NUM_ROTATIONS>, NUM_BRICK_TYPES>  createShapes();


public:
    TetrisShapes(TetrisShapes &other)= delete;
    void operator=(const TetrisShapes &)= delete;
    static TetrisShapes* getInstance();
    const std::array<std::array<int, SIZE>, SIZE>& getShape(int kind, int orientation) const;
   // ~TetrisShapes();

};


#endif // TETRISSHAPES_H
class TetrisShapes {
private:
    static TetrisShapes* tetrisShapesInstance;

    std::vector<std::vector<std::vector<Position>>> shapes;

    TetrisShapes() : shapes(createShapes()) {}
    std::vector<std::vector<std::vector<Position>>> createShapes();

public:
    TetrisShapes(const TetrisShapes&) = delete;
    TetrisShapes& operator=(const TetrisShapes&) = delete;
    static TetrisShapes* getInstance();
    const std::vector<std::vector<Position>>& getShape(TetrisShapeType kind, TetrisRotation orientation) const;
    // ~TetrisShapes();
};

#include <vector>

class Position {
public:
    int posX;
    int posY;

    Position(int x, int y) : posX(x), posY(y) {}
};

enum TetrisShapeType {
    // ... (votre énumération existante)
};

enum TetrisRotation {
    // ... (votre énumération existante)
};


