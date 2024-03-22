#include "controller/ConsoleController.h"
using namespace std;

int main()
{
    Game model = Game();
    ConsoleController controller =ConsoleController(model);
    controller.playTetris();

    return 0;
}
