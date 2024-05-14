#include "Level.h"

void Level::setSpeed(int level) {
    switch (level) {
    case 1:
        speed = 60;
        break;
    case 2:
        speed = 53;
        break;
    case 3:
        speed = 49;
        break;
    case 4:
        speed = 45;
        break;
    case 5:
        speed = 41;
        break;
    case 6:
        speed = 37;
        break;
    case 7:
        speed = 33;
        break;
    case 8:
        speed = 28;
        break;
    case 9:
        speed = 23;
        break;
    case 10:
        speed = 18;
        break;
    case 11:
        speed = 13;
        break;
    case 12:
        speed = 9;
        break;
    case 13:
        speed = 9;
        break;
    case 14:
        speed = 8;
        break;
    case 15:
        speed = 7;
        break;
    case 16:
        speed = 6;
        break;
    case 17:
        speed = 5;
        break;
    case 18:
        speed = 4;
        break;
    case 19:
        speed = 3;
        break;
    case 20:
        speed = 2;
        break;
    default:
        if (level > 20) {
            speed = 2;
        }
    }
}

Level::Level(int level) : actualLevel(level), deletedLines(0) {
    setSpeed(level);
}

void Level::updateLevel(int removedLines) {
    this->deletedLines += removedLines;
    actualLevel = 1 + (deletedLines / 1);
    setSpeed(actualLevel);
}

int Level::getActualLevel() const {
    return actualLevel;
}

int Level::getSpeed() const {
    return speed;
}

int Level::getDeletedLines() const {
    return deletedLines;
}
