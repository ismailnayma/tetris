#include "../controller/ConsoleController.h"
#include "iostream"

ConsoleController::ConsoleController(Game& model)
    :model(model){
    std::cout<< "je suis dans le controlleur" <<std::endl;
    model.start();
}

char ConsoleController::getInput() {
    return _getch(); // Read a single character without echoing
}

bool ConsoleController::handleInput(char input) {
    switch (input) {
    case 'q':
        model.moveCurrentBrick(Direction::LEFT);
        break;
    case 'd':
        model.moveCurrentBrick(Direction::RIGHT);
        break;
    case 's':
        model.moveCurrentBrick(Direction::DOWN);
        break;
    case 'a':
        model.rotateCurrentBrick(Rotation::COUNTERCLOCKWISE);
        break;
    case 'z':
        model.rotateCurrentBrick(Rotation::CLOCKWISE);
        break;
    case 'e':
        model.dropCurrentBrick();
        break;
    default:
        return false; // Return false if input is not recognized
    }
    return true; // Return true if input is recognized
}
