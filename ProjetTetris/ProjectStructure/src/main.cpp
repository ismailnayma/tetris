#include <iostream>
#include "ConsoleController.h"
using namespace std;

int main()
{
    cout << "Test affichage tetris" << endl;
    Game model = Game();
    cout<< "le model a bien ete cree" <<endl;
    ConsoleView view = ConsoleView();

    cout<< "la vieuw a bien ete cree" <<endl;
    ConsoleController(model, view);

    return 0;
}
