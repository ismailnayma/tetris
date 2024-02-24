#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
private:
    int posX; // X-coordinate
    int posY; // Y-coordinate

public:
    // Constructor with explicit initialization
    Position(int x, int y) : posX(x), posY(y) {}

    // Getter for posX
    int getPosX() const {
        return posX;
    }

    // Getter for posY
    int getPosY() const {
        return posY;
    }
};

#endif // POSITION_HPP
