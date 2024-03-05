#include "Game.h"

Game::Game(int width, int height, int level)
    :gameBoard(Board(width,height)),
      gameBrickBag(gameBoard.getStartPosition()),
      gameState(State::READY),
      gameLevel(level){}

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
        //If the current brick is fallen update the Board, Score,Level and State
        if(gameBoard.isCurrentBrickFallen()){
            int deletedLines = gameBoard.deletePossibleLines();
            gameLevel.updateLevel(deletedLines);
            gameScore.updateScore(deletedLines,dropDistance,gameLevel.getActualLevel());
            if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
                gameState=State::GAMEOVER;
            }
        }
    }
    notifyObservers();
}

void Game::rotateCurrentBrick(Rotation rotation){
    int dropDistance = 0;
    if(gameBoard.rotateCurrentBrick(rotation)){
        if(gameBoard.isCurrentBrickFallen()){
            int deletedLines = gameBoard.deletePossibleLines();
            gameLevel.updateLevel(deletedLines);
            gameScore.updateScore(deletedLines,dropDistance,gameLevel.getActualLevel());
            if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
                gameState=State::GAMEOVER;
            }
        }
    }
    notifyObservers();
}

void Game::dropCurrentBrick(){
    //retrieves the distance dropped
    int dropDistance = gameBoard.dropCurrentBrick();
    if(gameBoard.isCurrentBrickFallen()){
        int deletedLines = gameBoard.deletePossibleLines();
        gameLevel.updateLevel(deletedLines);
        gameScore.updateScore(deletedLines,dropDistance,gameLevel.getActualLevel());
        if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
            gameState=State::GAMEOVER;
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
