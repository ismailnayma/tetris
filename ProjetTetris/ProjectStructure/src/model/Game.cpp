#include "Game.h"
#include "iostream"
#include "../util/Observable.h"

Game::Game(int width, int height, int level, bool emptyBoard)
    :gameBoard(Board(width,height,emptyBoard)),
      gameBrickBag(Position(width/2,1)),
      gameState(State::READY),
      gameLevel(level){}

void Game::start(){
    gameState = State::PLAYING;
    //Set the first board currentBrick from the game brickBag
    std::cout<< "je suis dans start"<< std::endl;
    if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
    throw std::out_of_range("Error starting the game, the brick has a collision");
    }
    std::cout<< "setCurrentBrick s'est bien passé"<< std::endl;
    Game::notifyObservers();
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
    //notifyObservers();
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
