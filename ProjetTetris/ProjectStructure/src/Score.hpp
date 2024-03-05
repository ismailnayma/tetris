#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
    int score;

public:
    Score(int score=0):score(score){}

    void updateScore(int deletedLines, int dropDistance, int currentLevel) {
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

    int getScore() const{
        return score;
    }


};

#endif // SCORE_HPP
