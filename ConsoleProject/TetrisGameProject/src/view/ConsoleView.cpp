#include "ConsoleView.h"


ConsoleView::ConsoleView(Game& game):game(game){};

void ConsoleView::showBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea) const{
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

void ConsoleView::displayMessage(const std::string& message) const{
    std::cout << message;
}

void ConsoleView::update() {
    ConsoleView::displayLevelAndScore();
    ConsoleView::showBoard(game.getGameBoard().getBoardArea());
    if(game.getGameState() == GameState::LOSS){
        std::cout<<"You lost :("<<std::endl;
    } else if(game.getGameState() == GameState::SCOREWIN){
        std::cout<<"You reached the maximum score!, Congragulations, you won ! :)"<<std::endl;
    } else if(game.getGameState() == GameState::LINESWIN){
        std::cout<<"You reached the maximum number of deleted lines!,Congragulations, you won ! :)"<<std::endl;
    }
}
