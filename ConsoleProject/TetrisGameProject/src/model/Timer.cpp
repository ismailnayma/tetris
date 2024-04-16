#include "Timer.h"
#include <iostream>

Timer::Timer(Game& game) : running_(false), game(game) {}

Timer::~Timer() {
    stop();
}

void Timer::startGameOverTimer(std::chrono::seconds duration) {
    running_ = true;
    std::thread(&Timer::runGameOverTimer, this, duration).detach();
}

void Timer::startPeriodicTimer(std::chrono::milliseconds interval) {
    running_ = true;
    std::thread(&Timer::runPeriodicTimer, this, interval).detach();
}

void Timer::stop() {
    running_ = false;
}

void Timer::runGameOverTimer(std::chrono::seconds duration) {
    std::this_thread::sleep_for(duration);
    if (running_) {
       // game.setState(GameState::TIMELOSS);
        //stop();
    }
}

void Timer::runPeriodicTimer(std::chrono::milliseconds interval) {
    while (running_) {
        std::this_thread::sleep_for(interval);
        if (running_) {
            std::cout << "Action exécutée chaque " << interval.count() << " milliseconds" << std::endl;
            // What we want to execute every interval
        }
    }
}
