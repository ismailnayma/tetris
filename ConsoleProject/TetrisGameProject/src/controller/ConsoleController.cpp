#include "ConsoleController.h"
#include "iostream"

ConsoleController::ConsoleController(Game& model)
    :model(model),view(model){
    model.registerObserver(&view);
}

void ConsoleController:: playTetris(){
    setupBoard();
    bool playing = true;

    model.start();
    view.displayControls();

    while (!model.isGameOver() && playing) {
        playing = handleInput(getInput());
        if(model.isGameOver()){
            //ask the player if he wants to start a new game
            char replayChoice = validateInput("Do you want to play a new game? (y/n): ");
            if(replayChoice == 'y'){
                model.resetGame(10, 20, false);
                setupBoard();
                model.start();
            } else {
                playing = false;
            }
        }
    }
}

int ConsoleController::getValidInteger(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        view.displayMessage(prompt);
        std::string input;
        std::getline(std::cin, input);
        try {
            value = std::stoi(input);
            if (value < min || value > max) {
                view.displayMessage("Input must be between " + std::to_string(min) + " and " + std::to_string(max) + ".\n");
            } else {
                break;
            }
        } catch (const std::exception& e) {
            view.displayMessage("Invalid input. Please enter a valid integer: ");
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
            view.displayMessage("Invalid input. Please enter 'y' for yes or 'n' for no: ");
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
}


char ConsoleController::getInput() {
    //return _getch(); // Read a single character without echoing
    std::string line;
    view.displayMessage("Enter a character: ");
    std::getline(std::cin, line);
    return line.empty() ? '\0' : line[0];
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
        view.displayMessage("input is not recognized: ");
    }
    return true;
}
