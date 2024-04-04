#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "../model/Game.h"
#include "../util/Observer.h"
#include "iostream"


class ConsoleView : public Observer{
private:
    Game& game;
public:
    ConsoleView(Game& game);
    void displayLineBorder() const;
    void showBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea) const;
    void displayControls() const;
    void displayLevelAndScore() const;
    void displayMessage(const std::string& message) const;
    void update() override;
};

#endif // CONSOLEVIEW_H
