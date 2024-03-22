#include "Score.h"

Score::Score(int score) : score(score) {}

void Score::updateScore(int deletedLines, int dropDistance, int currentLevel) {
    int augmentation = 0;
    if (deletedLines <= 1) {
        augmentation = (40 * deletedLines + dropDistance) * currentLevel;
    } else if (deletedLines == 2) {
        augmentation = (100 * deletedLines + dropDistance) * currentLevel;
    } else if (deletedLines == 3) {
        augmentation = (300 * deletedLines + dropDistance) * currentLevel;
    } else if (deletedLines == 4) {
        augmentation = (1200 * deletedLines + dropDistance) * currentLevel;
    }
    this->score += augmentation;
}

int Score::getScore() const {
    return score;
}
