// Board.cpp
#include "Board.h"
#include <iostream>
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
    if(!emptyBoard){
        for (int i = ((height / 3) * 2); i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(j == 0){
                    // first column is always filled
                    boardArea[i][j] = generateRandomBrick(true);
                }else if(j==width-1){
                    // last column is always empty
                    boardArea[i][j] = std::nullopt;
                }else{
                    boardArea[i][j] = generateRandomBrick(false);
                }
            }
        }
    }
}

std::optional<TypeShape> Board::generateRandomBrick(bool onlyTypeShape) {
    static std::random_device rd;
    static std::default_random_engine gen(rd());  // Initialize a pseudo-random number generator
    // Define a distribution for generating random numbers to determine if the piece should be empty or not
    static std::uniform_int_distribution<int> disEmpty(0, 1);
    // Define a distribution for generating random numbers to determine the type of shape
    static std::uniform_int_distribution<int> disShape(0, static_cast<int>(TypeShape::TYPESHAPE_NUMBER) - 1);

    // If onlyTypeShape is true, return a random TypeShape
    if (onlyTypeShape) {
        return static_cast<TypeShape>(disShape(gen));
    } else {
        // If not onlyTypeShape, generate a random number to determine if the piece should be empty
        if (disEmpty(gen) == 0) {
            // If the random number is 0, return an empty piece (std::nullopt)
            return std::nullopt;
        } else {
            // If the random number is not 0, return a random TypeShape
            return static_cast<TypeShape>(disShape(gen));
        }
    }
}

bool Board::setCurrentBrick(const Brick& brick) {
    return !isCollision(brick) ? (currentBrick = brick,updateArea(true), true) : false;
}

bool Board::moveCurrentBrick(Direction direction) {
    Position newCurBrickPos = currentBrick.getBoardPosition();

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
    Brick newCurBrick(currentBrick.getTypeShape(), newCurBrickOrientation, currentBrick.getBoardPosition());

    //handle area current brick removal, collision check, and area update
    return handleBrickAdjustment(newCurBrick);
}

// Helper function for handling area brick removal, collision check, and area update
bool Board::handleBrickAdjustment(const Brick& newCurBrick) {
    // Remove the current brick from the boardArea to check collision with the new one
    updateArea(false);

    // Check for collision with the new brick
    if (!isCollision(newCurBrick)) { // If there is no collision, the current brick can be moved or rotated
        currentBrick = newCurBrick;
        updateArea(true); // Add the new current brick on the boardArea
        return true;
    }

    // If there is a collision with the new current brick, redraw the old current brick
    updateArea(true);
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


bool Board::isCurrentBrickFallen() {
    // Create a new position one unit below the current brick's position
    Position newCurBrickPos(currentBrick.getBoardPosition().getPosX(), currentBrick.getBoardPosition().getPosY() + 1);

    // Create a new brick with the updated position
    Brick newCurBrick(currentBrick.getTypeShape(), currentBrick.getOrientation(), newCurBrickPos);

    // Temporarily remove the current brick from the area to check for collisions with the new one
    updateArea(false);


    // Check if the new brick cannot be moved down = if there is collision
    bool cannotBeMovedDown = isCollision(newCurBrick);

    // Add the current brick to the boardArea
    updateArea(true);

    // Return true if the brick cannot be moved down = the brick is fallen, false otherwise
    return cannotBeMovedDown;
}


int Board::deletePossibleLines() {
    int linesDeleted = 0;

    // Iterate through each row from bottom to top of the board
    for (int row = boardHeight - 1; row >= 0; --row) {

        // Check if all cells in the row are occupied (complete)
        bool isRowComplete = true;
        for (int col = 0; col < boardWidth; ++col) {
            // Si une cellule n'est pas occupée, la ligne n'est pas complète
            if (!boardArea[row][col].has_value()) {
                isRowComplete = false;
                break;
            }
        }

        // Si la ligne est complète, supprimez-la
        if (isRowComplete) {
            // Supprime la ligne complète du boardArea
            boardArea.erase(boardArea.begin() + row);

            boardArea.insert(boardArea.begin(), std::vector<std::optional<TypeShape>>(boardWidth));

            // Incrémente le nombre de lignes supprimées
            ++linesDeleted;

            // Incrémente row pour vérifier la ligne décalée lors de la prochaine itération
            ++row;

        }
    }

    return linesDeleted;
}

bool Board::isCollision(const Brick& brick) const {

    // Get the positions on the board that the brick occupies
    std::vector<Position> brickBoardPositions = getBrickBoardPositions(brick);

    // Check if any of the positions collide with existing shapes on the board
    for (const Position& pos : brickBoardPositions) {
        int posX = pos.getPosX();
        int posY = pos.getPosY();

        // Check if the position is within the board boundaries
        if (posX < 0 || posX >= boardWidth || posY < 0 || posY >= boardHeight) {
            // The position is outside the board boundaries, indicating a collision
            return true;
        }


        try {
            // Check if the position is occupied by an existing shape on the board
            if (boardArea[posY][posX].has_value()) {
                // The position is occupied, indicating a collision
                return true;
            }
        } catch (const std::exception& ex) {
            std::cout << "Exception caught: " << typeid(ex).name() << std::endl;
        }

    }


    // No collision detected
    return false;
}


void Board::updateArea(bool addBrick) {
    // Get the positions on the board that the current brick occupies
    std::vector<Position> brickBoardPositions = getBrickBoardPositions(currentBrick);

    // Update the boardArea based on the addBrick parameter
    for (const Position& pos : brickBoardPositions) {
        int posX = pos.getPosX();
        int posY = pos.getPosY();

        // Check if the position is within the board boundaries
        if (posX >= 0 && posX < boardWidth && posY >= 0 && posY < boardHeight) {
            if (addBrick) {
                // Set the shape at the position on the board to the type of the current brick
                boardArea[posY][posX] = currentBrick.getTypeShape();
            } else {
                // Clear the shape from the position on the board
                boardArea[posY][posX] = std::nullopt;
            }
        }
    }
}



std::vector<Position> Board::getBrickBoardPositions(const Brick& brick) const {
    std::vector<Position> brickBoardPositions;

    // Get the vector of positions for the given brick type and orientation from ShapesRotation
    const std::vector<Position>& brickPositions = shapesRotation->getBrickPositions(brick.getTypeShape(), brick.getOrientation());

    // Calculate the corresponding real board positions
    for (const Position& brickPos : brickPositions) {
        int boardPosX = brick.getBoardPosition().getPosX() + brickPos.getPosX();
        int boardPosY = brick.getBoardPosition().getPosY() + brickPos.getPosY();

        // Use emplace_back to construct a new Position object directly at the end of the vector.
        // The arguments (boardPosX, boardPosY) are utilized to construct the Position object without the need for temporary object copies.
        brickBoardPositions.emplace_back(boardPosX, boardPosY);

    }

    return brickBoardPositions;
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

void Board::setBoardArea(const std::vector<std::vector<std::optional<TypeShape>>>& area) {
    boardArea = area;
}


