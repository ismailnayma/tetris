#include <catch2/catch_test_macros.hpp>
#include "model/Board.h"


TEST_CASE("Board initialization", "[board]") {
    Board board(10, 20);
    REQUIRE(board.getBoardArea().size() == 20); // Check if the board height is initialized correctly
    REQUIRE(board.getBoardArea()[0].size() == 10); // Check if the board width is initialized correctly
    //we make a test here because we use resize() in the Board constructor

    auto boardArea = board.getBoardArea();
    // Verify that all cells are initially empty (no shapes)
        for (const auto& row : boardArea) {
            for (const auto& cell : row) {
                REQUIRE_FALSE(cell.has_value());
            }
        }
}


TEST_CASE("Set current brick", "[board]") {
    Board board(10, 20);
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    REQUIRE(board.setCurrentBrick(brick) == true); // Check if the brick can be successfully set

    auto boardArea = board.getBoardArea();
    // Check if the brick is set correctly on the board
    REQUIRE(boardArea[0][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[0][1].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[0][2].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][2].value() == TypeShape::L_SHAPE);


}
