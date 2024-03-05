#include "Game.h"

Game::Game(int width, int height, int level)
    :gameBoard(Board(width,height)),
      gameBrickBag(gameBoard.getStartPosition()),
      gameState(State::READY),
      gameLevel(level){}

void Game::start(){
    gameState = State::PLAYING;
    if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
    throw std::out_of_range("Error starting the game, the brick has a collision");
    }
}

void Game::moveCurrentBrick(Direction direction){
    int dropDistance = 0;
    if(gameBoard.moveCurrentBrick(direction)){
        if(gameBoard.isCurrentBrickFallen()){
            int deletedLines = gameBoard.deletePossibleLines();
            gameLevel.updateLevel(deletedLines);
            gameScore.updateScore(deletedLines,dropDistance,gameLevel.getActualLevel());
            if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
                gameState=State::GAMEOVER;
            }
        }
    }
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
}

void Game::dropCurrentBrick(){
    int dropDistance = gameBoard.dropCurrentBrick();
    if(gameBoard.isCurrentBrickFallen()){
        int deletedLines = gameBoard.deletePossibleLines();
        gameLevel.updateLevel(deletedLines);
        gameScore.updateScore(deletedLines,dropDistance,gameLevel.getActualLevel());
        if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
            gameState=State::GAMEOVER;
        }
    }
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
