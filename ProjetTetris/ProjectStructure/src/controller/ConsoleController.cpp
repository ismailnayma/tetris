#include "ConsoleController.h"
#include "iostream"

ConsoleController::ConsoleController(Game& model)
    :model(model),view(model){
    model.registerObserver(&view);
}

int ConsoleController::getValidInteger(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        try {
            value = std::stoi(input);
            if (value < min || value > max) {
                std::cerr << "Input must be between " << min << " and " << max << ".\n";
            } else {
                break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Invalid input. Please enter a valid integer.\n";
        }
    }
    return value;
}

char ConsoleController::validateInput(const std::string& prompt) {
    std::string input;
    char choice;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.size() == 1) {
            choice = std::tolower(input[0]);
            if(choice == 'y' || choice == 'n'){
                break;
            }
        } else {
            std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
        }
    }
    return choice;
}

void ConsoleController::setupBoard() {
    char sizeChoice = validateInput("Do you want to choose the size of the board? (y/n): ");
    int width = model.getGameBoard().getBoardWidth();
    int height = model.getGameBoard().getBoardHeight();
    bool emptyBoard = true;

    if (sizeChoice == 'y') {
            width = getValidInteger("Enter the width of the board (between 5 and 50): ", 5, 50);
            height = getValidInteger("Enter the height of the board (between 5 and 50): ", 5, 50);
     }
    char fillChoice = validateInput("Do you want a pre-filled board? (y/n): ");

    if (fillChoice == 'y') {
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
    switch (std::tolower(input)) {
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
