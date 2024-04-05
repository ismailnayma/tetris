#include "Position.h"

Position::Position(int x, int y) : posX(x), posY(y) {}

int Position::getPosX() const {
    return posX;
}

int Position::getPosY() const {
    return posY;
}

void Position::setPosX(int x) {
    posX = x;
}

void Position::setPosY(int y) {
    posY = y;
}

bool Position::operator==(const Position& other) const {
    return posX == other.posX && posY == other.posY;
}
