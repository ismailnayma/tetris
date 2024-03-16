// Board.cpp
#include "Board.h"
#include <iostream>
#include <vector>
#include <vector>
#include <optional>

#include <cstdlib> // Pour rand
#include <ctime>   // Pour time


Board::Board(int width, int height, int filledLines)
    : boardWidth(width),
    boardHeight(height),
    shapesRotation(ShapesRotation::getInstance()) {

    // Initialize the boardArea vector with the specified width and height
    boardArea.resize(height);
    for (int i = 0; i < height; ++i) {
        boardArea[i].resize(width);
    }

    // Initialiser le générateur de nombres aléatoires avec une graine basée sur l'horloge système
   /* std::srand(std::time(nullptr));


    for (int i = height-1; i > height - filledLines-1; --i) {
        // Remplir chaque case avec une probabilité de 50% d'être remplie
        for (int j = 0; j < width; ++j) {
            bool isFilled = (std::rand() % 2 == 0); // 50% de chance d'être remplie
            if (isFilled) {
                // Remplir la case avec quelque chose (par exemple, un type de forme)
                // Ici, nous utilisons std::nullopt pour indiquer que la case est vide
                boardArea[i][j] = std::nullopt;
            }
        }
    }


    if (filledLines > 0) {
        // Remplir le nombre de lignes spécifié
        for (int i = 0; i < filledLines; ++i) {
            int row = std::rand() % height; // Choisir aléatoirement une ligne
            int col = std::rand() % width;  // Choisir aléatoirement une colonne
            boardArea[row][col] = std::nullopt; // S'assurer qu'il y a au moins une case vide par ligne
        }
    }

    if(filledLines < 0 || filledLines > height/2){
        //exception
    } else {
        for(int i = 0; i<filledLines; ++i){
            for(int j = 0; j<boardArea[i].size(); ++j){

            }
        }
    }

    */
}



bool Board::setCurrentBrick(const Brick& brick) {
    std::cout<< "je suis dans setCurrentBricj dans board"<< std::endl;
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
        for (int col = 0; col < boardWidth; ++col) {
            // If any cell is unoccupied, the row is not complete, so break the loop
            if (!boardArea[row][col].has_value()) {
                break;
            }

            // Erase the complete row from the boardArea
            boardArea.erase(boardArea.begin() + row);

            // Add a new empty row at the beginning of the boardArea vector to maintain correct row indexes
            boardArea.insert(boardArea.begin(), std::vector<std::optional<TypeShape>>(boardWidth));

            // Increment the count of deleted lines
            ++linesDeleted;

            // To ensure that the new shifted row at actual index row is also checked in the next iteration.
            ++row;
        }
    }

    return linesDeleted;
}


bool Board::isCollision(const Brick& brick) const {
    std::cout << "Je suis dans isCollision" << std::endl;

    // Get the positions on the board that the brick occupies
    std::vector<Position> brickBoardPositions = getBrickBoardPositions(brick);
    std::cout << "J'ai créé le vecteur de positions sur le board" << std::endl;

    // Check if any of the positions collide with existing shapes on the board
    for (const Position& pos : brickBoardPositions) {
        std::cout << "Je suis dans le for" << std::endl;
        int posX = pos.getPosX();
        int posY = pos.getPosY();

        // Check if the position is within the board boundaries
        if (posX < 0 || posX >= boardWidth || posY < 0 || posY >= boardHeight) {
            // The position is outside the board boundaries, indicating a collision
            std::cout << "La position est en dehors des limites du board" << std::endl;
            return true;
        }

        std::cout << "Je suis après le premier if dans le for" << std::endl;

        try {
            // Check if the position is occupied by an existing shape on the board
            if (boardArea[posY][posX].has_value()) {
                // The position is occupied, indicating a collision
                std::cout << "Je suis dans le deuxième if dans le for" << std::endl;
                return true;
            }
        } catch (const std::exception& ex) {
            std::cout << "Exception caught: " << typeid(ex).name() << std::endl;
        }

        std::cout << "Je suis après le deuxième if dans le for" << std::endl;
    }

    std::cout << "Je suis à la fin de isCollision" << std::endl;

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

    // Calculate the corresponding board positions
    for (const Position& brickPos : brickPositions) {
        int boardPosX = brick.getBoardPosition().getPosX() + brickPos.getPosX();
        int boardPosY = brick.getBoardPosition().getPosY() + brickPos.getPosY();

        // Use emplace_back to construct a new Position object directly at the end of the vector.
        // The arguments (boardPosX, boardPosY) are utilized to construct the Position object without the need for temporary object copies.
        brickBoardPositions.emplace_back(boardPosX, boardPosY);

    }

    return brickBoardPositions;
}

std::vector<std::vector<std::optional<TypeShape>>>& Board::getBoardArea()  {
    return boardArea;
}

const int& Board::getBoardHeight(){
    return boardHeight;
}

const int& Board::getBoardWidth(){
    return boardWidth;
}

// Implémentation de la méthode setBoardArea
void Board::setBoardArea(const std::vector<std::vector<std::optional<TypeShape>>>& area) {
    boardArea = area;
}

/*
Board& Board::operator=(const Board& other) {
    if (this != &other) { // compares the adresses
        boardWidth = other.boardWidth;
        boardHeight = other.boardHeight;
        boardArea = other.boardArea;
    }
    return *this;
}
*/
