#include "ConsoleView.h"
#include "iostream"
#include <iomanip>
#include <unordered_map>

// Define ANSI escape sequences for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define GRAY    "\033[90m"

ConsoleView::ConsoleView(Game& game):game(game){};

void ConsoleView::showBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea){
    displayLineBorder();
    for (const auto& row : boardArea) {
        std::cout <<" |";
        for (const auto& cell : row) {
            if (!cell.has_value()) {
                std::cout << '.';
            } else {
                switch (cell.value()) {
                case TypeShape::O_SHAPE:
                    std::cout << 'O';
                    break;
                case TypeShape::I_SHAPE:
                    std::cout << 'I';
                    break;
                case TypeShape::S_SHAPE:
                    std::cout << 'S';
                    break;
                case TypeShape::Z_SHAPE:
                    std::cout << 'Z';
                    break;
                case TypeShape::L_SHAPE:
                    std::cout << 'L';
                    break;
                case TypeShape::J_SHAPE:
                    std::cout << 'J';
                    break;
                case TypeShape::T_SHAPE:
                    std::cout << 'T';
                    break;
                default:
                    break;

                }
            }
            std::cout << ' ';  // add a space
        }
        std::cout<<"| " << '\n';  // next line
    }
}

void ConsoleView::colorShowBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea) {
    constexpr char BLOCK_CHAR = 219;  // ASCII code for a solid block character
    constexpr char EMPTY_CHAR = ' ';  // Character for an empty space

    // Define colors for each type of shape
    std::unordered_map<TypeShape, std::string> shapeColors = {
        {TypeShape::O_SHAPE, RED},    // Square shape
        {TypeShape::I_SHAPE, GREEN},  // Straight shape
        {TypeShape::S_SHAPE, YELLOW},  // S shape
        {TypeShape::Z_SHAPE, BLUE},  // Z shape
        {TypeShape::L_SHAPE, MAGENTA},  // L shape
        {TypeShape::J_SHAPE, CYAN},  // J shape
        {TypeShape::T_SHAPE, GRAY}   // T shape
    };
    displayLineBorder();
    // Iterate through the board area and print the shapes
    for (const auto& row : boardArea) {
        std::cout <<" |";
        for (const auto& cell : row) {
            if (cell.has_value()) {
                TypeShape shape = cell.value(); // Extract the shape from optional
                std::string color = shapeColors[shape]; // Access color based on shape
                std::cout << color << BLOCK_CHAR << BLOCK_CHAR;  // Print two characters for each block for better aspect ratio
            } else {
                std::cout << EMPTY_CHAR << EMPTY_CHAR;  // Print two empty spaces for each block for better aspect ratio
            }
        }
        std::cout << RESET<<"| "<< '\n';  // Reset color and move to next line
    }
    //displayLineBorder();
    std::cout <<"\n";
}

void ConsoleView::displayLineBorder() const{
    for(int i =0; i<game.getGameBoard().getBoardWidth()+1;i++){
        if(i==0){
            std::cout <<"  ";
        }else{
            std::cout <<"__";
        }
    }
    std::cout<<"\n";
}
void ConsoleView::displayControls() const {
    std::cout << "Controls:\n"
              << "Q - Move Left\n"
              << "D - Move Right\n"
              << "S - Move Down\n"
              << "A - Rotate Left\n"
              << "Z - Rotate Right\n"
              << "E - Drop\n"
              << "H - Help(controls)\n"
              << "L - Leave\n";
}

void ConsoleView::displayLevelAndScore() const{
    std::cout<<"\n";
    std::cout << "  Score: "<< game.getGameScore().getScore()<<"\n"
              << "  Level: "<< game.getGameLevel().getActualLevel()<<"\n"
              << "  Lines: "<< game.getGameLevel().getDeletedLines()<<"\n" ;
}

void ConsoleView::update(){
    ConsoleView::displayLevelAndScore();
    ConsoleView::colorShowBoard(game.getGameBoard().getBoardArea());
    //ConsoleView::showBoard(game.getGameBoard().getBoardArea());
    if(game.getGameState() == GameState::LOSS){
        std::cout<<"You lost :("<<std::endl;
    } else if(game.getGameState() == GameState::SCOREWIN){
         std::cout<<"You reached the maximum score!, Congragulations, you won ! :)"<<std::endl;
    } else if(game.getGameState() == GameState::LINESWIN){
        std::cout<<"You reached the maximum number of deleted lines!,Congragulations, you won ! :)"<<std::endl;
    }
}
