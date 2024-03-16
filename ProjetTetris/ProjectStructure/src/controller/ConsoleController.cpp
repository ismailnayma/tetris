#include "ConsoleController.h"
#include "iostream"

ConsoleController::ConsoleController(Game& model,ConsoleView & consoleView )
    :model(model),consoleView(consoleView){
    std::cout<< "je suis dans le controlleur" <<std::endl;
    model.start();
    consoleView.showBoard(model.getGameBoard().getBoardArea());

}
