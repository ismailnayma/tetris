#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>
#include <atomic>
#include "Game.h"

class Timer {
public:
    Timer(Game& game);
    ~Timer();

    void startGameOverTimer(std::chrono::seconds duration);
    void startPeriodicTimer(std::chrono::milliseconds interval);
    void stop();

private:
    std::atomic_bool running_;
    Game& game;

    void runGameOverTimer(std::chrono::seconds duration);
    void runPeriodicTimer(std::chrono::milliseconds interval);
};

#endif // TIMER_H
