#ifndef GAME_H
#define GAME_H

#include "BrickBag.h"
#include "Board.h"
#include "Score.h"
#include "Level.h"
#include "Enums.h"
#include "../util/Observable.h"

class Game : public Observable {
    GameState gameState;
    Board gameBoard;
    BrickBag gameBrickBag;
    Score gameScore;
    Level gameLevel;

    void updateGame(int dropDistance);
    void setCurrentBrick();

public:
    Game(int width = 10, int height = 20, bool emptyBoard = true);
    void start();
    void moveCurrentBrick(Direction direction);
    void rotateCurrentBrick(Rotation rotation);
    void dropCurrentBrick();
    bool isGameOver();
    const GameState& getGameState() const;
    Score getGameScore() const;
    Level getGameLevel() const;
    Board getGameBoard() const;
    void resetGame(int width, int height, bool emptyBoard);

};


#endif // GAME_H
