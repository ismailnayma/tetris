#ifndef POSITION_H
#define POSITION_H

/**
 * @brief The Position class represents a 2D position on a game board.
 *
 * The position is defined by its column (posX) and line (posY) on the board.
 */
class Position {
private:
    int posX; ///< Represents the column of the board (0 starting from the left bottom).
    int posY; ///< Represents the line of the board (0 starting from the top).

public:
    Position();
    Position(int x, int y);

    int getPosX() const;
    int getPosY() const;
    void setPosX(int x);
    void setPosY(int y);


    // Surcharge de l'opérateur ==
    bool operator==(const Position& other) const;
};

#endif // POSITION_H
