#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "../model/Game.h"
#include "../util/Observer.h"

class ConsoleView : public Observer{
private:
    Game& game;
public:
    ConsoleView(Game& game);
    void showBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea);
    // view methods
    void update() override;

};

#endif // CONSOLEVIEW_H
