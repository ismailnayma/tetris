#ifndef BOARD_H
#define BOARD_H

#include "Enums.h"
#include "Position.h"
#include "Brick.h"
#include "ShapesRotation.h"
#include <vector>
#include <optional>

class Board {
private:
    int boardWidth;
    int boardHeight;
    std::vector<std::vector<std::optional<TypeShape>>> boardArea;
    Brick currentBrick;
    const ShapesRotation* shapesRotation;

    bool isCollision(const Brick& brick) const;

    void addBrickToBoard();

    /**
     * @brief Helper function for handling area brick removal, collision check, and area update.
     */
    bool handleBrickAdjustment(const Brick& newCurBrick);
    void setBoardArea(const std::vector<std::vector<std::optional<TypeShape>>>& area);
    std::optional<TypeShape> generateRandomShape(bool onlyTypeShape);
    bool fallen = false;

public:
    Board(int width = 10, int height = 20, bool emptyBoard = true);
    bool setCurrentBrick(const Brick& brick);
    bool moveCurrentBrick(Direction direction);
    bool rotateCurrentBrick(Rotation rotation);
    int dropCurrentBrick();
    bool isCurrentBrickFallen();
    int deletePossibleLines();
    const std::vector<std::vector<std::optional<TypeShape>>>& getBoardArea() const;
    const int& getBoardHeight() const;
    const int& getBoardWidth() const;
    std::vector<Position> getBrickBoardPositions(const Brick& brick) const;
    const Brick& getBrick() const;
};

#endif // BOARD_H
