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

    //handle area current brick removal, collision check, and area update
    return handleBrickAdjustment(newCurBrick);
}


bool Board::rotateCurrentBrick(Rotation rotation) {
    Orientation newCurBrickOrientation;
    int currentOrientationValue = static_cast<int>(currentBrick.getOrientation());

    // Adjust the orientation based on the specified rotation
    switch (rotation) {
    case Rotation::CLOCKWISE:
        //increase the orientation value and use modulo to ensure circular rotation (ex: if newValue == 4 then nawValue == 0)
        newCurBrickOrientation = static_cast<Orientation>((currentOrientationValue + 1) % 4);
        break;
    case Rotation::COUNTERCLOCKWISE:
        //decrease the orientation value and use modulo to ensure circular rotation (ex: if newValue == -1 then nawValue == 3)
        newCurBrickOrientation = static_cast<Orientation>((currentOrientationValue - 1 + 4) % 4);
        break;
    }

    // 'newCurBrickOrientation' now holds the new orientation after rotation

    // Create a new brick with the updated orientation, representing the rotated brick on the board
    Brick newCurBrick(currentBrick.getTypeShape(), newCurBrickOrientation, currentBrick.getPosition());

    //handle area current brick removal, collision check, and area update
    return handleBrickAdjustment(newCurBrick);
}

// Helper function for handling area brick removal, collision check, and area update
bool Board::handleBrickAdjustment(const Brick& newCurBrick) {
    // Remove the old brick from the area to check collision with the new one
    removeCurrentBrickOnArea();

    // Check for collision with the new brick
    if (!isCollision(newCurBrick)) { // If there is no collision, the current brick can be moved or rotated
        currentBrick = newCurBrick;
        updateArea(); // Draw the new brick on the boardArea
        return true;
    }

    // If there is a collision with the new brick, redraw the old current brick
    updateArea();
    return false;
}


int Board::dropCurrentBrick() {
    int dropDistance = 0;

    // Move the current brick down as long as there is no collision
    while (moveCurrentBrick(Direction::DOWN)) {
        dropDistance++;
    }

    // Return the distance the brick was able to drop
    return dropDistance;
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
