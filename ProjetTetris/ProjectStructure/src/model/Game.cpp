#include "../util/Observable.h"
#include "Game.h"
#include "iostream"


Game::Game(int width, int height, bool emptyBoard)
    :gameBoard(Board(width,height,emptyBoard)),
      gameBrickBag(Position(width/2,1)),
      gameState(State::READY),
      gameLevel(Level()),
      gameScore(Score()){}

void Game::start(){
    gameState = State::PLAYING;
    //Set the first board currentBrick from the game brickBag
    if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
    throw std::out_of_range("Error starting the game, the brick has a collision");
    }
    notifyObservers();

}

void Game::moveCurrentBrick(Direction direction){
    int dropDistance = 0;
    if(gameBoard.moveCurrentBrick(direction)){
        updateGame(dropDistance);
    }
}

void Game::rotateCurrentBrick(Rotation rotation){
    int dropDistance = 0;
    if(gameBoard.rotateCurrentBrick(rotation)){
        updateGame(dropDistance);
    }
}

void Game::dropCurrentBrick(){
    //retrieves the distance dropped
    int dropDistance = gameBoard.dropCurrentBrick();
    updateGame(dropDistance);
}


 //If the current brick is fallen update the Board, Score,Level and State
void Game::updateGame(int dropDistance) {
    if (gameBoard.isCurrentBrickFallen()) {
        int deletedLines = gameBoard.deletePossibleLines();
        gameLevel.updateLevel(deletedLines);
        gameScore.updateScore(deletedLines, dropDistance, gameLevel.getActualLevel());
        if (!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())) {
            gameState = State::GAMEOVER;
        }
    }
    notifyObservers();
}


bool Game::isGameOver(){
    return gameState==State::GAMEOVER;
}

Score Game::getGameScore() const{
    return gameScore;
}

Level Game::getGameLevel() const{
    return gameLevel;
}

Board Game::getGameBoard() const{
    return gameBoard;
}

void Game::resetGame(int width, int height, bool emptyBoard) {
    gameBoard = Board(width, height, emptyBoard);
    gameBrickBag = BrickBag(Position(width / 2, 1));
    gameState = State::READY;
    gameLevel = Level();
    gameScore = Score();
}
