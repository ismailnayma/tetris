#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H
#include "../model/Game.h"
#include "ConsoleView.h"

class ConsoleController {
    const Game& model;
    ConsoleView consoleView;

public:
    ConsoleController( Game& model,ConsoleView & consoleView );



};

#endif // CONSOLECONTROLLER_H
