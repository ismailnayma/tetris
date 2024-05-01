#include "Board.h"
#include <vector>
#include <random>
#include <vector>
#include <optional>

Board::Board(int width, int height, bool emptyBoard)
    : boardWidth(width),
    boardHeight(height),
    shapesRotation(ShapesRotation::getInstance()) {

    // Initialize the boardArea vector with the specified width and height
    boardArea.resize(height);
    for (int i = 0; i < height; ++i) {
        boardArea[i].resize(width);
    }

    // Initialize a pre-filled board if "emptyBoard" is false
    if (!emptyBoard) {
        // Loop through rows starting from 2/3 of the height to the end
        for (int row = ((height / 3) * 2); row < height; ++row) {
            bool isFull = true;
            for (int col = 0; col < width; ++col) {
                if((boardArea[row][col] = generateRandomShape()) == std::nullopt){
                    isFull = false;
                }
            }
            if (isFull) {
                boardArea[row][width-1] = std::nullopt;
            }

        }
    }
}

bool Board::setCurrentBrick(const Brick& brick) {
    return !isCollision(brick) ? (currentBrick = brick,fallen = false, true) : false;
}

bool Board::moveCurrentBrick(Direction direction) {
    Position newCurBrickPos = currentBrick.getBoardPosition();

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

    // Handle the adjustment of the current brick, including removal, collision check, and area update
    return handleBrickAdjustment(newCurBrick);
}

bool Board::rotateCurrentBrick(Rotation rotation) {
    Orientation newCurBrickOrientation;
    int currentOrientationValue = static_cast<int>(currentBrick.getOrientation());

    switch (rotation) {
    case Rotation::CLOCKWISE:
        // Increase the orientation value and use modulo to ensure circular rotation
        // (e.g., if newValue == 4 then newValue == 0)
        newCurBrickOrientation = static_cast<Orientation>((currentOrientationValue + 1) % 4);
        break;
    case Rotation::COUNTERCLOCKWISE:
        // Decrease the orientation value and use modulo to ensure circular rotation
        // (e.g., if newValue == -1 then newValue == 3)
        newCurBrickOrientation = static_cast<Orientation>((currentOrientationValue - 1 + 4) % 4);
        break;
    }

    // Create a new brick with the updated orientation, representing the rotated brick on the board
    Brick newCurBrick(currentBrick.getTypeShape(), newCurBrickOrientation, currentBrick.getBoardPosition());

    // Handle area current brick removal, collision check, and area update
    return handleBrickAdjustment(newCurBrick);
}

int Board::dropCurrentBrick() {
    int dropDistance = 0;

    while (moveCurrentBrick(Direction::DOWN)) {
        dropDistance++;
    }

    return dropDistance;
}

bool Board::isCurrentBrickFallen() {
    return fallen;
}

int Board::deletePossibleLines() {
    int linesDeleted = 0;

    // Iterate through each row from bottom to top of the board
    for (int row = boardHeight - 1; row >= 0; --row) {
        // Check if all cells in the row are occupied
        bool isRowComplete = true;
        for (int col = 0; col < boardWidth; ++col) {
            if (!boardArea[row][col].has_value()) {
                isRowComplete = false;
                break;
            }
        }

        if (isRowComplete) {
            // Delete the completely filled row from "boardArea"
            boardArea.erase(boardArea.begin() + row);
            // Add a new empty row at the top of the board to maintain correct dimensions
            boardArea.insert(boardArea.begin(), std::vector<std::optional<TypeShape>>(boardWidth));

            ++linesDeleted;
            ++row; // Increment row to check the shifted line during the next iteration
        }
    }

    return linesDeleted;
}

bool Board::isCollision(const Brick& brick) const {
    std::vector<Position> brickBoardPositions = getBrickBoardPositions(brick);

    for (const Position& pos : brickBoardPositions) {
        int posX = pos.getPosX();
        int posY = pos.getPosY();

        // Check if the position is outside the board boundaries
        if (posX < 0 || posX >= boardWidth || posY < 0 || posY >= boardHeight) {
            return true; // Collision with boundary
        }

        // Check if there is a brick on the board at the position
        if (boardArea[posY][posX].has_value()) {
            return true; // Collision with existing brick
        }
    }

    return false; // No collision detected
}

bool Board::handleBrickAdjustment(const Brick& newCurBrick) {

    if (!isCollision(newCurBrick)) {
        currentBrick = newCurBrick;
        return true;
    }else{
        Position CurBrickPosDown(currentBrick.getBoardPosition().getPosX(),
                                currentBrick.getBoardPosition().getPosY() + 1);
        if(newCurBrick.getBoardPosition()==CurBrickPosDown){
            addBrickToBoard();
            fallen = true;
        }
    }

    return false;
}

void Board::addBrickToBoard() {
    std::vector<Position> brickBoardPositions = getBrickBoardPositions(currentBrick);

    for (const Position& pos : brickBoardPositions) {
        int posX = pos.getPosX();
        int posY = pos.getPosY();

        if (posX >= 0 && posX < boardWidth && posY >= 0 && posY < boardHeight) {
            boardArea[posY][posX] = currentBrick.getTypeShape();

        }
    }

}

std::vector<Position> Board::getBrickBoardPositions(const Brick& brick) const {
    std::vector<Position> brickBoardPositions;

    // Retrieve the vector of relative positions for the specified brick type and orientation
    const std::vector<Position>& brickPositions = shapesRotation->getBrickPositions(brick.getTypeShape(),
                                                                                    brick.getOrientation());

    // Calculate the corresponding real board positions
    for (const Position& brickPos : brickPositions) {
        int boardPosX = brick.getBoardPosition().getPosX() + brickPos.getPosX();
        int boardPosY = brick.getBoardPosition().getPosY() + brickPos.getPosY();

        // Construct a new Position object directly at the end of the vector
        // without creating temporary object copies.
        brickBoardPositions.emplace_back(boardPosX, boardPosY);
    }

    return brickBoardPositions;
}

std::optional<TypeShape> Board::generateRandomShape() {
    static std::random_device rd;
    static std::default_random_engine gen(rd());
    // Define a distribution for generating random numbers to determine there should be a shape or not
    static std::uniform_int_distribution<int> disEmpty(0, 5);
    // Define a distribution for generating random numbers to determine the type of shape
    static std::uniform_int_distribution<int> disShape(0, static_cast<int>(TypeShape::TYPESHAPE_NUMBER) - 1);

    // Generate a random number to determine if there should be a shape or not
    if (disEmpty(gen) == 0) {
        return std::nullopt; // No shape generated
    } else {
        return static_cast<TypeShape>(disShape(gen)); // Generate a random shape
    }
}

void Board::setBoardArea(const std::vector<std::vector<std::optional<TypeShape>>>& area) {
    boardArea = area;
}

const std::vector<std::vector<std::optional<TypeShape>>>& Board::getBoardArea() const {
    return boardArea;
}

const int& Board::getBoardHeight() const{
    return boardHeight;
}

const int& Board::getBoardWidth() const{
    return boardWidth;
}

const Brick& Board::getBrick() const{
    return currentBrick;
}
