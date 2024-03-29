#include "Game.h"

Game::Game(int width, int height, bool emptyBoard)
    :gameBoard(Board(width,height,emptyBoard)),
      gameBrickBag(Position(width/2,1)),
      gameState(GameState::READY),
      gameLevel(Level()),
      gameScore(Score()){}

void Game::resetGame(int width, int height, bool emptyBoard) {
    gameBoard = Board(width, height, emptyBoard);
    gameBrickBag = BrickBag(Position(width / 2, 1));
}

void Game::start(){
    gameState = GameState::PLAYING;
    setCurrentBrick();
    notifyObservers();
}

void Game::setCurrentBrick(){
    //Set the board currentBrick from the brickBag
    if(!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())){
        gameState = GameState::LOSS;
    }
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


 //If the current brick is fallen update the Board, Score,Level and GameState
void Game::updateGame(int dropDistance) {
    if (gameBoard.isCurrentBrickFallen()) {
        int deletedLines = gameBoard.deletePossibleLines();

        gameLevel.updateLevel(deletedLines);
        gameScore.updateScore(deletedLines, dropDistance, gameLevel.getActualLevel());

        //conditions for win
        if(gameScore.getScore() > 1000){
            gameState=GameState:: SCOREWIN;
        } else if (gameLevel.getDeletedLines() > 50){
            gameState=GameState:: LINESWIN;
        } else {
            //didn't win
            setCurrentBrick();
        }
    }
    notifyObservers();
}

bool Game::isGameOver(){
    return gameState==GameState::LOSS ||
           gameState==GameState:: LINESWIN ||
           gameState==GameState:: SCOREWIN ;
}

//Getters
const GameState& Game::getGameState() const{
    return gameState;
}

const Board& Game::getGameBoard() const{
    return gameBoard;
}

const Level& Game::getGameLevel() const{
    return gameLevel;
}

const Score& Game::getGameScore() const{
    return gameScore;
}
