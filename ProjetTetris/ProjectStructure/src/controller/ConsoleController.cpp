#include "ConsoleController.h"
#include "iostream"

ConsoleController::ConsoleController(Game& model)
    :model(model),view(model){
    model.registerObserver(&view);
}

void ConsoleController::setupBoard() {
    std::string choice;
    int width = model.getGameBoard().getBoardWidth();
    int height = model.getGameBoard().getBoardHeight();
    bool emptyBoard = true;

    std::cout << "Do you want to choose the size of the board? (y/n): ";
    std::getline(std::cin, choice);
    choice = std::tolower(choice[0]);

    while (choice != "y" && choice != "n") {
        std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
        std::getline(std::cin, choice);
        choice = std::tolower(choice[0]);
    }

    if (choice == "y") {
        do {
            std::cout << "Enter the width of the board (between 5 and 50): ";
            std::cin >> width;
        } while (width < 5 || width > 50);

        do {
            std::cout << "Enter the height of the board (between 5 and 50): ";
            std::cin >> height;
        } while (height < 5 || height > 50);
    }

    std::cout << "Do you want a pre-filled board? (y/n): ";
    std::getline(std::cin, choice);
    choice = std::tolower(choice[0]);

    while (choice != "y" && choice != "n") {
        std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
        std::getline(std::cin, choice);
        choice = std::tolower(choice[0]);
    }

    if (choice == "y") {
        emptyBoard = false;
    }
    model.resetGame(width, height, emptyBoard);
    model.start();
    view.displayControls();
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
    case 'l':
        return false; //exit, leave the game
    case 'h':
        view.displayControls();
    default:
        std::cout << "input is not recognized: \n";
    }
    return true;
}
