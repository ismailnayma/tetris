#include "Game.h"

Game::Game(int width, int height, bool emptyBoard)
    : gameBoard(Board(width, height, emptyBoard)),
    gameBrickBag(Position(width / 2, 1)),
    gameState(GameState::PLAYING),
    gameLevel(Level()),
    gameScore(Score()) {}

void Game::resetGame(int width, int height, bool emptyBoard) {
    gameBoard = Board(width, height, emptyBoard);
    gameBrickBag = BrickBag(Position(width / 2, 1));
    gameState = GameState::PLAYING;
    gameLevel = Level();
    gameScore = Score();
}

void Game::start() {
    gameState = GameState::PLAYING;
    setCurrentBrick();
    notifyObservers();
}

void Game::setCurrentBrick() {
    // Set the board currentBrick from the brickBag
    if (!gameBoard.setCurrentBrick(gameBrickBag.getNextBrick())) {
        gameState = GameState::LOSS;
    }
}
void Game::moveCurrentBrick(Direction direction) {
    int dropDistance = 0;
    gameBoard.moveCurrentBrick(direction);
    updateGame(dropDistance);

}

void Game::rotateCurrentBrick(Rotation rotation) {
    int dropDistance = 0;
    gameBoard.rotateCurrentBrick(rotation);
    updateGame(dropDistance);
}

void Game::dropCurrentBrick() {
    // Retrieves the distance dropped
    int dropDistance = gameBoard.dropCurrentBrick();
    updateGame(dropDistance);
}

// Update the Board, Score, Level and GameState
void Game::updateGame(int dropDistance) {
    if (gameBoard.isCurrentBrickFallen()) {
        int deletedLines = gameBoard.deletePossibleLines();

        gameLevel.updateLevel(deletedLines);
        gameScore.updateScore(deletedLines, dropDistance, gameLevel.getActualLevel());

        // Conditions for win
        if (!checkVictory()) {
            setCurrentBrick();
        }
    }
    notifyObservers();
}

bool Game::checkVictory() {
    if (gameScore.getScore() > 500) {
        gameState = GameState::SCOREWIN;
    } else if (gameLevel.getDeletedLines() > 1000) {
        gameState = GameState::LINESWIN;
    } else {
        return false;
    }
    return true;
}

bool Game::isGameOver() {
    return gameState == GameState::LOSS ||
           gameState == GameState::LINESWIN ||
           gameState == GameState::SCOREWIN ||
           gameState == GameState::TIMELOSS;
}

const GameState& Game::getGameState() const {
    return gameState;
}

const Board& Game::getGameBoard() const {
    return gameBoard;
}

const Level& Game::getGameLevel() const {
    return gameLevel;
}

const Score& Game::getGameScore() const {
    return gameScore;
}

const int Game::getDuration() const{
    return duration;
}
void Game::setState(GameState state){
    gameState = state;
    notifyObservers();
}
