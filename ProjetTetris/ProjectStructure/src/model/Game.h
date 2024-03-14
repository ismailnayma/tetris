#ifndef GAME_H
#define GAME_H

#include "BrickBag.h"
#include "Board.h"
#include "Score.h"
#include "Level.h"
#include "Enums.h"
#include "../util/Observable.h"

class Game : public Observable {
    State gameState;
    Board gameBoard;
    BrickBag gameBrickBag;
    Score gameScore;
    Level gameLevel;

    void updateGame(int dropDistance);

public:
    Game(int width = 10, int height = 20, int level = 1);
    void start();
    void moveCurrentBrick(Direction direction);
    void rotateCurrentBrick(Rotation rotation);
    void dropCurrentBrick();
    bool isGameOver();
    State getGameState() const;
    Score getGameScore() const;
    Level getGameLevel() const;
    Board getGameBoard() const;

};


#endif // GAME_H
