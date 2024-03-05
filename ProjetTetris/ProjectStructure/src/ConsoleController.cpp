#include "ConsoleController.h"


ConsoleController::ConsoleController(Game& model,ConsoleView consoleView )
    :model(model),consoleView(consoleView){
    model.start();
    consoleView.showBoard(model.getGameBoard().getBoardArea());
}
