#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "../model/Game.h"
#include "../view/ConsoleView.h"

class ConsoleController {
private:
    Game& model;
    ConsoleView view;

    void setBoard();
    char getUserInput();
    bool handleUserInput(char input);
    int getValidInteger(const std::string& prompt, int min, int max);
    char getValidChoiceInput(const std::string& prompt);

public:
    ConsoleController(Game& model);
    void playTetris();
};

#endif // CONSOLECONTROLLER_H
