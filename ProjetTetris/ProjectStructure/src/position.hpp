#ifndef POSITION_HPP
#define POSITION_HPP

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
    Position() = default;
    /**
     * @brief Constructor for the Position class.
     * @param x The column position.
     * @param y The line position.
     */
    Position(int x, int y) : posX(x), posY(y) {}

    /**
     * @brief Getter for the column position.
     * @return The column position (posX).
     */
    int getPosX() const {
        return posX;
    }

    /**
     * @brief Getter for the line position.
     * @return The line position (posY).
     */
    int getPosY() const {
        return posY;
    }
};

#endif // POSITION_HPP
