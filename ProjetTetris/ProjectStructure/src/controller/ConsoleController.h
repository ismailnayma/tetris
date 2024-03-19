#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "../model/Game.h"
#include "../view/ConsoleView.h"
#include <conio.h>

class ConsoleController {
    Game& model;
    ConsoleView view;

    int getValidInteger(const std::string& prompt, int min, int max);
public:
    ConsoleController(Game& model);
    void setupBoard();
    // Function to read user input
    char getInput();
     // Function to handle user input and call corresponding model methods
    bool handleInput(char input);

};

#endif // CONSOLECONTROLLER_H
