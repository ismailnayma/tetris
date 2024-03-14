#ifndef SCORE_H
#define SCORE_H

class Score {
private:
    int score;

public:
    Score(int score = 0);

    void updateScore(int deletedLines, int dropDistance, int currentLevel);

    int getScore() const;
};


#endif // SCORE_H
