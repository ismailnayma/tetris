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
    switch(direction){
    case Direction::RIGHT:
    case Direction::DOWN:
    case Direction::LEFT:
    }

    // Implémenter la méthode moveCurrentBrick
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
