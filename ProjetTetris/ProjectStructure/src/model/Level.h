#ifndef LEVEL_H
#define LEVEL_H

#include <stdexcept>

class Level {
private:
    int actualLevel;
    int speed;
    int deletedLines;
    void setSpeed(int level);

public:
    Level(int level = 1);

    void updateLevel(int removedLines);

    int getActualLevel() const;
    int getSpeed() const;
    int getDeletedLines() const;
};

#endif // LEVEL_H
