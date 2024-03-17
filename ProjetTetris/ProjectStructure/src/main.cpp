#include <iostream>
#include "controller/ConsoleController.h"
using namespace std;

int main()
{
    cout << "Test affichage tetris" << endl;
    Game model = Game();
    cout<< "le model a bien ete cree" <<endl;
    ConsoleView view = ConsoleView(model);
    model.registerObserver(&view);

    cout<< "la vieuw a bien ete cree" <<endl;
    ConsoleController controller =ConsoleController(model);
    char input;
    bool running = true;
    while (running) {
        running = controller.handleInput(controller.getInput());
    }

    return 0;
}
