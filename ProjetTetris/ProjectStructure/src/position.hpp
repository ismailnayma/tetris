#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
private:
    int posX; // column of the board (0 starting from the left bottom)
    int posY; // line of the board ( 0 starting from de top)

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
