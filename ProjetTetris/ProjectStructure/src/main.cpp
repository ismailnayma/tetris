#include <iostream>
#include "controller/ConsoleController.h"
using namespace std;

int main()
{
    Game model = Game();
    ConsoleController controller =ConsoleController(model);
    char input;
    controller.playTetris();

    return 0;
}
