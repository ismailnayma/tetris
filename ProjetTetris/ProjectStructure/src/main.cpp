#include <iostream>
#include "controller/ConsoleController.h"
using namespace std;

int main()
{
    Game model = Game();
    ConsoleController controller =ConsoleController(model);
    char input;
    bool running = true;
    controller.setupBoard();
    while (running) {
        running = controller.handleInput(controller.getInput());
    }

    return 0;
}
