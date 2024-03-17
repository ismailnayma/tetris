#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "../model/Game.h"
#include "../view/ConsoleView.h"
#include <conio.h>

class ConsoleController {
    const Game& model;
    const ConsoleView& consoleView;

public:
    ConsoleController( Game& model,ConsoleView & consoleView );
    // Function to read user input
    char getInput();
    bool handleInput(char input);

};

#endif // CONSOLECONTROLLER_H
