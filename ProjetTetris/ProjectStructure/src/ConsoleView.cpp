#include "ConsoleView.h"
void ConsoleView::showBoard(const std::vector<std::vector<std::optional<TypeShape>>>& boardArea){
    for (const auto& row : boardArea) {
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

                    }
                }
                std::cout << ' ';  // add a space
            }
            std::cout << '\n';  // next line
}
}
