#include <iostream>
#include "ConsoleController.h"
using namespace std;

int main()
{
    cout << "Test affichage tetris" << endl;
    Game model = Game();
    ConsoleController(model,ConsoleView());

    return 0;
}
