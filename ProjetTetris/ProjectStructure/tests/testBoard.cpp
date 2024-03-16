#include <catch2/catch_test_macros.hpp>
#define private public
#include "model/Board.h"

TEST_CASE("Board Initialization", "[board]") {
    Board board; // Standard Tetris board: width = 10, height = 20

    // Check if the board width is initialized correctly
    REQUIRE(board.getBoardArea()[0].size() == 10);

    // Check if the board height is initialized correctly
    REQUIRE(board.getBoardArea().size() == 20);

    // Verify that all cells are initially empty (no shapes)
    auto boardArea = board.getBoardArea();
    for (const auto& row : boardArea) {
        for (const auto& cell : row) {
            REQUIRE_FALSE(cell.has_value());
        }
    }
}

TEST_CASE("Set Default Current Brick", "[board]") {
    Board board;

    // Check default brick parameters
    REQUIRE(board.currentBrick.getOrientation() == Orientation::UP);
    REQUIRE(board.currentBrick.getTypeShape() == TypeShape::I_SHAPE);
    REQUIRE(board.currentBrick.getBoardPosition() == Position(0, 0));

    // Check default brick placement
    REQUIRE(!board.getBoardArea()[0][0].has_value());
}

TEST_CASE("Set Current Brick", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));

    // Attempt to set the brick on the board
    REQUIRE(board.setCurrentBrick(brick));

    // Check if the brick is set correctly on the board
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[0][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][0].value() == TypeShape::L_SHAPE); // Position(0,1) corresponds to [1][0] on the boardArea
    REQUIRE(boardArea[2][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][1].value() == TypeShape::L_SHAPE);

    // Attempt to set another brick at the same position
    Brick brick2(TypeShape::I_SHAPE, Orientation::UP, Position(0, 1));

    // Ensure that the second brick cannot be set
    REQUIRE_FALSE(board.setCurrentBrick(brick2));

    // Check that the current brick remains unchanged
    REQUIRE(board.currentBrick.getTypeShape() == TypeShape::L_SHAPE);
}

TEST_CASE("Move the Current Brick", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(4, 4));
    board.setCurrentBrick(brick);

    // Move the current brick and check its position after each movement
    SECTION("Move left") {
        board.moveCurrentBrick(Direction::LEFT);
        REQUIRE(board.currentBrick.getBoardPosition() == Position(3, 4));
    }

    SECTION("Move down") {
        board.moveCurrentBrick(Direction::DOWN);
        REQUIRE(board.currentBrick.getBoardPosition() == Position(4, 5));
    }

    SECTION("Move right") {
        board.moveCurrentBrick(Direction::RIGHT);
        REQUIRE(board.currentBrick.getBoardPosition() == Position(5, 4));
    }
}

TEST_CASE("Move the Current Brick to the Left Out of Bounds", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    board.setCurrentBrick(brick);

    // Attempt to move the brick left
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::LEFT)); // Check that the brick cannot be moved out of bounds

    // Check that the brick didn't move on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[0][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][0].value() == TypeShape::L_SHAPE); // Position(0,1) corresponds to [1][0] in the boardArea
    REQUIRE(boardArea[2][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][1].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its board position isn't supposed to be changed
    REQUIRE(board.currentBrick.getBoardPosition() == Position(0,1));
}

TEST_CASE("Move Current Brickto the Right Out of Bounds", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(8, 1));
    board.setCurrentBrick(brick);

    // Attempt to move the brick right
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::RIGHT)); // Check that the brick cannot be moved out of bounds

    // Check that the brick didn't move on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[0][8].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][8].value() == TypeShape::L_SHAPE); // Position(1, 8) corresponds to [1][8] in the boardArea
    REQUIRE(boardArea[2][8].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][9].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its board position isn't supposed to be changed
    REQUIRE(board.currentBrick.getBoardPosition() == Position(8,1));
}

TEST_CASE("Move Current Brick Down Out of Bounds", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 18));
    board.setCurrentBrick(brick);

    // Attempt to move the brick down
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::DOWN)); // Check that the brick cannot be moved out of bounds

    // Check that the brick didn't move on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[17][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[18][0].value() == TypeShape::L_SHAPE); // Position(0,18) corresponds to [18][0] in the boardArea
    REQUIRE(boardArea[19][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][1].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its board position isn't supposed to be changed
    REQUIRE(board.currentBrick.getBoardPosition() == Position(0,18));
}

TEST_CASE("Move Current Brick within bounds but encountering Collision", "[board]") {
    Board board;

    // Create a filled testBoardArea to simulate a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth())
        );

    testBoardArea[4][4] = TypeShape::L_SHAPE;
    board.setBoardArea(testBoardArea);

    // MOVE LEFT
    Brick brickLeft(TypeShape::L_SHAPE, Orientation::UP, Position(5, 4));
    board.setCurrentBrick(brickLeft);
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::LEFT)); // Check that the brick cannot be moved to the left due to collision

    // Check that the brick didn't move on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[3][5].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[4][5].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[5][5].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[5][6].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its board position isn't supposed to be changed
    REQUIRE(board.currentBrick.getBoardPosition() ==  Position(5,4));

    // MOVE RIGHT
    Brick brickRight(TypeShape::L_SHAPE, Orientation::UP, Position(3, 4));
    board.setCurrentBrick(brickRight);
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::RIGHT)); // Check that the brick cannot be moved to the right due to collision

    // Check that the brick didn't move on the boardArea
    boardArea = board.getBoardArea();
    REQUIRE(boardArea[3][3].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[4][3].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[5][3].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[5][4].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its board position isn't supposed to be changed
    REQUIRE(board.currentBrick.getBoardPosition() ==  Position(3,4));

    // MOVE DOWN
    Brick brickDown(TypeShape::I_SHAPE, Orientation::UP, Position(4, 1));
    board.setCurrentBrick(brickDown);
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::DOWN)); // Check that the brick cannot be moved down due to collision

    // Check that the brick didn't move on the boardArea
    boardArea = board.getBoardArea();
    REQUIRE(boardArea[0][4].value() == TypeShape::I_SHAPE);
    REQUIRE(boardArea[1][4].value() == TypeShape::I_SHAPE);
    REQUIRE(boardArea[2][4].value() == TypeShape::I_SHAPE);
    REQUIRE(boardArea[3][4].value() == TypeShape::I_SHAPE);

    // Check the currentBrick's parameters, its board position isn't supposed to be changed
    REQUIRE(board.currentBrick.getBoardPosition() ==  Position(4,1));
}

TEST_CASE("Rotation of Current Brick", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(4, 4));
    board.setCurrentBrick(brick);

    // Rotate the brick clockwise and verify its orientation
    board.rotateCurrentBrick(Rotation::CLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::RIGHT);

    board.rotateCurrentBrick(Rotation::CLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::DOWN);

    board.rotateCurrentBrick(Rotation::CLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::LEFT);

    board.rotateCurrentBrick(Rotation::CLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::UP);

    // Rotate the brick counterclockwise and verify its orientation
    board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::LEFT);

    board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::DOWN);

    board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::RIGHT);

    board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
    REQUIRE(board.currentBrick.getOrientation() == Orientation::UP);
<<<<<<< HEAD
=======

}

TEST_CASE("Move current brick", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    REQUIRE(board.setCurrentBrick(brick) == true);
    SECTION("left collision out of board"){
    REQUIRE_FALSE(board.moveCurrentBrick(Direction::LEFT));
    }
    SECTION("down ok"){
    REQUIRE(board.moveCurrentBrick(Direction::DOWN));
    }
    SECTION("right ok"){
    REQUIRE(board.moveCurrentBrick(Direction::RIGHT));
    }
    std::vector<std::vector<std::optional<TypeShape>>> area;
    area.resize(board.getBoardWidth());
    for (int i = 0; i < board.getBoardHeight(); ++i) {
        area[i].resize(board.getBoardWidth());
    }



>>>>>>> a11fea26689137ee07a20b9219d4c4adc5a25489
}

TEST_CASE("Out of Bounds Rotation of Current Brick to the Left", "[board]") {
    // Create a board and set a brick near the left bound
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    board.setCurrentBrick(brick);

    // Check that the brick cannot be rotated due to being out of bounds
    REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE));
    REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::CLOCKWISE));

    // Check that the brick remains at its original position on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[0][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][1].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters: its orientation shouldn't change
    REQUIRE(board.currentBrick.getOrientation() ==  Orientation::UP);
}

TEST_CASE("Out of Bounds Rotation of Current Brick to the Right", "[board]") {
    // Create a board and set a brick at the right boundary position
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::DOWN, Position(9, 1));
    board.setCurrentBrick(brick);

    // Check that the brick cannot be rotated due to being out of bounds
    REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE));
    REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::CLOCKWISE));

    // Check that the brick didn't move on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[0][8].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[0][9].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][9].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][9].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its orientation isn't supposed to change
    REQUIRE(board.currentBrick.getOrientation() == Orientation::DOWN);
}

TEST_CASE("Out of Bounds Rotation of Current Brick to the Bottom", "[board]") {
    // Create a board and set a brick at the bottom boundary position
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 18));
    board.setCurrentBrick(brick);

    // Check that the brick cannot be rotated bc out of bounds
    REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE));
    REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::CLOCKWISE));

    // Check that the brick didn't move on the bordArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[17][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[18][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][1].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters, its orientation isn't supposed to change
    REQUIRE(board.currentBrick.getOrientation() ==  Orientation::UP);
}

TEST_CASE("Rotation of Current Brick within bounds but encountering Collision", "[board]") {
    Board board;

    // Create a filled testBoardArea to simulate a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth())
        );

    // Place a brick on the testBoardArea to check collisions
    testBoardArea[4][4] = TypeShape::L_SHAPE;
    board.setBoardArea(testBoardArea);

    // CASE 1: Brick collides with left bound
    {
        Brick brickLeft(TypeShape::L_SHAPE, Orientation::UP, Position(5, 4));
        board.setCurrentBrick(brickLeft);

        // Check that the brick cannot be rotated due to collisions
        REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE));
        REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::CLOCKWISE));

        // Check that the brick didn't move on the boardArea
        auto boardArea = board.getBoardArea();
        REQUIRE(boardArea[3][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[4][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[5][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[5][6].value() == TypeShape::L_SHAPE);

        // Check the currentBrick's parameters; its orientation isn't supposed to change
        REQUIRE(board.currentBrick.getOrientation() == Orientation::UP);
    }

    // CASE 2: Brick collides with right bound
    {
        Brick brickRight(TypeShape::L_SHAPE, Orientation::UP, Position(3, 4));
        board.setCurrentBrick(brickRight);

        // Check that the brick cannot be rotated due to collisions
        REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE));
        REQUIRE_FALSE(board.rotateCurrentBrick(Rotation::CLOCKWISE));

        // Check that the brick didn't move on the boardArea
        auto boardArea = board.getBoardArea();
        REQUIRE(boardArea[3][3].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[4][3].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[5][3].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[5][4].value() == TypeShape::L_SHAPE);

        // Check the currentBrick's parameters; its orientation isn't supposed to change
        REQUIRE(board.currentBrick.getOrientation() == Orientation::UP);
    }
}

TEST_CASE("Drop Current Brick from Top to Bottom on an Empty BoardArea", "[board]") {
    Board board;

    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    board.setCurrentBrick(brick);

    // Drop the current brick and check the drop distance
    REQUIRE(board.dropCurrentBrick() == 17); // The drop distance should be 17, as the board height is 20

    // Check that the brick was successfully dropped onto the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[17][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[18][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][1].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters; its board position is expected to change after dropping
    REQUIRE(board.currentBrick.getBoardPosition() ==  Position(0,18));
}

TEST_CASE("Drop Current Brick onto filled boardArea", "[board]") {
    Board board;

    // Create a filled testBoardArea to simulate a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth())
        );

    testBoardArea[6][6] = TypeShape::L_SHAPE; // Place a brick on the testBoardArea

    // Set the testBoardArea on the board
    board.setBoardArea(testBoardArea);

    // Set the current brick
    Brick brick(TypeShape::L_SHAPE, Orientation::DOWN, Position(7, 5));
    board.setCurrentBrick(brick);

    // Drop the current brick onto the filled boardArea
    REQUIRE(board.dropCurrentBrick() == 1); // Drop distance should be 1

    // Check that the dropped brick occupies the correct positions on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[5][6].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[5][7].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[6][7].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[7][7].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters to ensure its board position is updated
    REQUIRE(board.currentBrick.getBoardPosition() == Position(7, 6));
}

TEST_CASE("Drop Current Brick but encountering Collision", "[board]") {
    Board board;

    // Create a filled testBoardArea to simulate a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth())
        );

    // Place a brick on the testBoardArea to check for collisions
    testBoardArea[6][6] = TypeShape::L_SHAPE;

    // Set the testBoardArea on the board
    board.setBoardArea(testBoardArea);

    // Set the current brick
    Brick brick(TypeShape::L_SHAPE, Orientation::DOWN, Position(7, 6));
    board.setCurrentBrick(brick);

    // Drop the current brick and check the drop distance (expected to be 0 due to collision)
    REQUIRE(board.dropCurrentBrick() == 0);

    // Check that the brick was not dropped and still occupies the same positions on the boardArea
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[5][6].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[5][7].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[6][7].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[7][7].value() == TypeShape::L_SHAPE);

    // Check the currentBrick's parameters to ensure its board position remains unchanged
    REQUIRE(board.currentBrick.getBoardPosition() == Position(7, 6));
}

TEST_CASE("Deletion of lines from an empty boardArea", "[board]") {
    Board board;
    REQUIRE(board.deletePossibleLines() == 0); // No lines deleted from an empty board
}

TEST_CASE("Deletion of lines when no lines are eligible for deletion", "[board]") {
    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::DOWN, Position(7, 5));
    board.setCurrentBrick(brick);
    REQUIRE(board.deletePossibleLines() == 0); // No lines eligible for deletion
}

TEST_CASE("Deletion of lines when all lines eligible for deletion", "[board]") {
    Board board;

    // Create a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth(), TypeShape::L_SHAPE)
        );

    // Set the testBoardArea on the board
    board.setBoardArea(testBoardArea);

    // All lines from the board should be deleted
    REQUIRE(board.deletePossibleLines() == board.getBoardHeight());
}

TEST_CASE("Deletion of 2 consecutive lines", "[board]") {
    Board board;

    // Create a filled testBoardArea to simulate a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth())
        );

    // Fill the bottom two lines with bricks
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            testBoardArea[board.getBoardHeight() - 1 - i][j] = TypeShape::L_SHAPE;
        }
    }

    // Set the testBoardArea on the board
    board.setBoardArea(testBoardArea);

    // Set the current brick
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 16));
    board.setCurrentBrick(brick);

    // Delete lines and verify the number of lines deleted
    REQUIRE(board.deletePossibleLines() == 2);

    // Check that the lines have been deleted and the boardArea has shifted accordingly
    auto boardArea = board.getBoardArea();
    REQUIRE(boardArea[17][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[18][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[19][1].value() == TypeShape::L_SHAPE);
}

TEST_CASE("Deletion of 2 non-consecutive lines", "[board]") {
    Board board;

    // Create a filled testBoardArea to simulate a filled boardArea
    std::vector<std::vector<std::optional<TypeShape>>> testBoardArea(
        board.getBoardHeight(),
        std::vector<std::optional<TypeShape>>(board.getBoardWidth())
        );

    // Fill the bottom four rows with bricks
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            testBoardArea[board.getBoardHeight() - 1 - i][j] = TypeShape::L_SHAPE;
        }
    }

    // Mark some cells for deletion
    testBoardArea[19][1] = std::nullopt;
    testBoardArea[19][9] = std::nullopt;
    testBoardArea[17][1] = std::nullopt;
    testBoardArea[15][1] = TypeShape::L_SHAPE;

    // Set the testBoardArea on the board
    board.setBoardArea(testBoardArea);

    // Delete lines and verify the number of lines deleted
    REQUIRE(board.deletePossibleLines() == 2);

    // Check that the marked lines have been deleted and the boardArea has shifted accordingly
    auto boardArea = board.getBoardArea();
    REQUIRE(!boardArea[19][1].has_value());
    REQUIRE(!boardArea[18][1].has_value());
    REQUIRE(!boardArea[19][9].has_value());
    REQUIRE(boardArea[17][1].value() == TypeShape::L_SHAPE);
}

TEST_CASE("check if the current brick has fallen to the bottom of the board", "[board]") {
    Board board;

    // Place a brick at the top of the board
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    board.setCurrentBrick(brick);
    REQUIRE_FALSE(board.isCurrentBrickFallen()); // Ensure the brick hasn't fallen yet

    // Move another brick to the bottom of the board
    Brick brick2(TypeShape::L_SHAPE, Orientation::UP, Position(0, 18));
    board.setCurrentBrick(brick2);
    REQUIRE(board.isCurrentBrickFallen()); // Verify that the brick has fallen to the bottom
}
