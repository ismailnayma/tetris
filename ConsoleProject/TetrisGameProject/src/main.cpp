#include "controller/ConsoleController.h"

int main()
{
    Game model = Game();
    ConsoleController controller = ConsoleController(model);
    controller.playTetris();

    return 0;
}
