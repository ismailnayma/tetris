#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "../model/Game.h"
#include "../view/ConsoleView.h"

class ConsoleController {
    Game& model;
    ConsoleView view;

    int getValidInteger(const std::string& prompt, int min, int max);
    char validateInput(const std::string& prompt);
public:
    ConsoleController(Game& model);
    void playTetris();
    void setupBoard();
    // Function to read user input
    char getInput();
    // Function to handle user input and call corresponding model methods
    bool handleInput(char input);

};

#endif // CONSOLECONTROLLER_H
