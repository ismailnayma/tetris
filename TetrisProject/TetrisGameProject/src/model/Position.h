#ifndef POSITION_H
#define POSITION_H

/**
 * @brief The Position class represents a 2D position on a game board.
 *
 * The position is defined by its column (posX) and line (posY) on the board.
 */
class Position {
private:
    int posX;
    int posY;

public:
    Position(int x = 0, int y = 0);
    int getPosX() const;
    int getPosY() const;
    void setPosX(int x);
    void setPosY(int y);
    bool operator==(const Position& other) const;
};

#endif // POSITION_H
