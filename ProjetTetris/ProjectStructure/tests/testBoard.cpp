#include <catch2/catch_test_macros.hpp>
#define private public
#include "model/Board.h"


TEST_CASE("Board initialization", "[board]") {
    Board board; //width = 10, height = 20
    REQUIRE(board.getBoardArea()[0].size() == 10); // Check if the board width is initialized correctly
    REQUIRE(board.getBoardArea().size() == 20); // Check if the board height is initialized correctly

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

    Board board;
    Brick brick(TypeShape::L_SHAPE, Orientation::UP, Position(0, 1));
    REQUIRE(board.setCurrentBrick(brick) == true); // Check if the brick can be successfully set

    auto boardArea = board.getBoardArea();

    // Check if the brick is set correctly on the board
    REQUIRE(boardArea[0][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[1][0].value() == TypeShape::L_SHAPE); //Position(0,1) correspond to [1][0] in the boardArea
    REQUIRE(boardArea[2][0].value() == TypeShape::L_SHAPE);
    REQUIRE(boardArea[2][1].value() == TypeShape::L_SHAPE);


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



}




/*
TEST_CASE("Move current brick", "[board]") {
    // Création d'un plateau de jeu rempli et une brique courante
    Board board;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<board.getBoardWidth()-1; ++j){
            board.getBoardArea()[board.getBoardHeight()-i-1][j] = TypeShape::I_SHAPE;
        }
    }

    Brick brick(TypeShape::L_SHAPE, Orientation::DOWN, Position(9, 19));
    board.setCurrentBrick(brick);

    REQUIRE(board.moveCurrentBrick(Direction::LEFT) == false); // Check if the brick can be translated to the left


    REQUIRE_FALSE(cell.has_value());
    auto boardArea = board.getBoardArea();

    Brick initialBrick(TypeShape::L_SHAPE, Orientation::UP, Position(5, 0)); // Placer la brique initialement en (5, 0)
    board.setCurrentBrick(initialBrick);

    SECTION("Move right") {
        REQUIRE(board.moveCurrentBrick(Direction::RIGHT) == true); // Déplacer la brique vers la droite
        // Vérifier si la brique a été déplacée correctement vers la droite sur le plateau
        auto boardArea = board.getBoardArea();
        REQUIRE(boardArea[0][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[1][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[1][6].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[1][7].value() == TypeShape::L_SHAPE);
    }

    SECTION("Move left") {
        REQUIRE(board.moveCurrentBrick(Direction::LEFT) == true); // Déplacer la brique vers la gauche
        // Vérifier si la brique a été déplacée correctement vers la gauche sur le plateau
        auto boardArea = board.getBoardArea();
        REQUIRE(boardArea[0][3].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[1][3].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[1][4].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[1][5].value() == TypeShape::L_SHAPE);
    }

    SECTION("Move down") {
        REQUIRE(board.moveCurrentBrick(Direction::DOWN) == true); // Déplacer la brique vers le bas
        // Vérifier si la brique a été déplacée correctement vers le bas sur le plateau
        auto boardArea = board.getBoardArea();
        REQUIRE(boardArea[1][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[2][5].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[2][6].value() == TypeShape::L_SHAPE);
        REQUIRE(boardArea[2][7].value() == TypeShape::L_SHAPE);
    }

}
*/

