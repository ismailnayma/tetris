#ifndef GAME_H
#define GAME_H

#include "BrickBag.hpp"
#include "Board.h"
#include "Score.hpp"
#include "Level.hpp"
#include "enum.hpp"
#include "Observable.h"

class Game : public Observable {
    State gameState;
    Board gameBoard;
    BrickBag gameBrickBag;
    Score gameScore;
    Level gameLevel;

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



};


#endif // GAME_H
