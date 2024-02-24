#ifndef ShapesRotation_H
#define ShapesRotation_H

#include
#include <array>



#endif // ShapesRotation_H
class ShapesRotation {
private:
    static ShapesRotation* ShapesRotationInstance;

    std::vector<std::vector<std::vector<Position>>> shapes;

    ShapesRotation() : shapes(createShapes()) {}
    std::vector<std::vector<std::vector<Position>>> createShapes();

public:
    ShapesRotation(const ShapesRotation&) = delete;
    ShapesRotation& operator=(const ShapesRotation&) = delete;
    static ShapesRotation* getInstance();
    const std::vector<std::vector<Position>>& getShape(TetrisShapeType kind, TetrisRotation orientation) const;
    // ~ShapesRotation();
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


