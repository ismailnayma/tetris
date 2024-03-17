#include "../controller/ConsoleController.h"
#include "iostream"

ConsoleController::ConsoleController(Game& model,ConsoleView & consoleView )
    :model(model),consoleView(consoleView){
    std::cout<< "je suis dans le controlleur" <<std::endl;
    model.registerObserver(&consoleView);
    model.start();
    consoleView.showBoard(model.getGameBoard().getBoardArea());

}

char ConsoleController::getInput() {
    return _getch(); // Read a single character without echoing
}

