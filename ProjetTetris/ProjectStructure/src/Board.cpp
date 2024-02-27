// Board.cpp
#include "Board.h"


Board::Board(int width, int height)
    : boardWidth(width),
    boardHeight(height),
    startPosition(Position(5, 0)),
    shapesRotation(ShapesRotation::getInstance()) {
    // Initialiser d'autres membres si nécessaire
}

bool Board::setCurrentBrick(const Brick& brick) {
    return !isCollision(brick) ? (currentBrick = brick, true) : false;
}


bool Board::moveCurrentBrick(Direction direction) {
    Position newCurBrickPos = currentBrick.getPosition();

    // Move the current brick position based on the specified direction
    switch (direction) {
    case Direction::RIGHT:
        newCurBrickPos.setPosX(newCurBrickPos.getPosX() + 1);
        break;
    case Direction::DOWN:
        newCurBrickPos.setPosY(newCurBrickPos.getPosY() + 1);
        break;
    case Direction::LEFT:
        newCurBrickPos.setPosX(newCurBrickPos.getPosX() - 1);
        break;
    }

    // Create a new brick with the updated position, representing the moved brick on the board
    Brick newCurBrick(currentBrick.getTypeShape(), currentBrick.getOrientation(), newCurBrickPos);

    // Remove the old brick from the area to check collision with the new one
    removeCurrentBrickOnArea();

    // Check for collision with the new brick
    if (!isCollision(newCurBrick)) { // If there is no collision, the current brick can be moved
        currentBrick = newCurBrick;
        updateArea();                // Draw the new brick on the boardArea
        return true;
    }

    // If collision occurs, redraw the old current brick
    updateArea();
    return false;
}


bool Board::rotateCurrentBrick(Direction direction) {
    // Implémenter la méthode rotateCurrentBrick
}

int Board::dropCurrentBrick() {
    // Implémenter la méthode dropCurrentBrick
}

bool Board::isCurrentBrickFallen() const {
    // Implémenter la méthode isCurrentBrickFallen
}

int Board::deletePossibleLines() {
    // Implémenter la méthode deletePossibleLines
}

bool Board::isCollision(const Brick& brick) const {
    // Implémenter la méthode isCollision
}

void Board::removeCurrentBrickOnArea() {
    // Implémenter la méthode removeCurrentBrickOnArea
}

void Board::updateArea() {
    // Implémenter la méthode updateArea
}

std::vector<Position> Board::getBrickBoardPositions(const Brick& brick) const {
    // Implémenter la méthode getBrickBoardPositions
}
