#include "ConsoleController.h"
#include <iostream>

ConsoleController::ConsoleController(Game& model)
    :model(model),view(model){
    model.registerObserver(&view);
}

void ConsoleController:: playTetris(){
    setBoard(); // asks user if he wants a specific size board or a pre-filled board
    bool playing = true;

    model.start();
    view.displayControls();

    while (!model.isGameOver() && playing) {
        playing = handleUserInput(getUserInput());

        if(model.isGameOver()){
            char replayChoice = getValidChoiceInput("Do you want to play a new game? (y/n): ");

            if(replayChoice == 'y'){
                model.resetGame();
                setBoard();
                model.start();
                view.displayControls();
            } else {
                playing = false;
            }
        }
    }
}

void ConsoleController::setBoard() {
    char userSizeChoice = getValidChoiceInput("Do you want to choose the size of the board? (y/n): ");
    int boardWidth = model.getGameBoard().getBoardWidth();
    int boardHeight = model.getGameBoard().getBoardHeight();
    bool emptyBoard = true;

    if (userSizeChoice == 'y') {
        boardWidth = getValidInteger("Enter the width of the board (between 5 and 50): ", 5, 50);
        boardHeight = getValidInteger("Enter the height of the board (between 5 and 50): ", 5, 50);
    }

    char fillBoardChoice = getValidChoiceInput("Do you want a pre-filled board? (y/n): ");

    if (fillBoardChoice == 'y') {
        emptyBoard = false;
    }

    if(fillBoardChoice == 'y' || userSizeChoice == 'y'){
        model.resetGame(boardWidth, boardHeight, emptyBoard);
    }
}

char ConsoleController::getUserInput() {
    std::string userInput;
    char userChoice;

    view.displayMessage("Enter a character: ");
    std::getline(std::cin, userInput);

    if (userInput.size() == 1) {
        userChoice = std::tolower(userInput[0]);
        return userChoice;
    }else{
        return '\0';
    }
}

bool ConsoleController::handleUserInput(char input) {
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
        model.unregisterObserver(&view);
        return false; //exit, leave the game
    case 'h':
        view.displayControls();
        break;
    default:
        view.displayMessage("The user input is not recognized (enter 'h' for help) \n");
        break;
    }
    return true;
}

int ConsoleController::getValidInteger(const std::string& prompt, int min, int max) {
    int value;

    while (true) {
        std::string userInput;

        view.displayMessage(prompt);
        std::getline(std::cin, userInput);

        try {
            value = std::stoi(userInput);

            if (value < min || value > max) {
                view.displayMessage("Input must be between " + std::to_string(min)
                                    + " and " + std::to_string(max) + ".\n");
            } else {
                break;
            }
        } catch (const std::exception& e) {
            view.displayMessage("Invalid input. Please enter a valid integer: \n");
        }
    }
    return value;
}

char ConsoleController::getValidChoiceInput(const std::string& prompt) {
    std::string userInput;
    char userChoice;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, userInput);

        if (userInput.size() == 1) {
            userChoice = std::tolower(userInput[0]);

            if(userChoice == 'y' || userChoice == 'n'){
                break;
            }
        } else {
            view.displayMessage("Invalid input. Please enter 'y' for yes or 'n' for no: \n");
        }
    }
    return userChoice;
}
