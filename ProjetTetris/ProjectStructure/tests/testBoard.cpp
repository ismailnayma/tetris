#include <catch2/catch_test_macros.hpp>
#include "model/Board.h"
#include "model/ShapesRotation.h"


TEST_CASE("Board initialization", "[board]") {
    Board board(10, 20);
    REQUIRE(board.getBoardArea().size() == 20); // Check if the board height is initialized correctly
    REQUIRE(board.getBoardArea()[0].size() == 10); // Check if the board width is initialized correctly
    //we make a test here because we use resize() in the Board constructor
}
