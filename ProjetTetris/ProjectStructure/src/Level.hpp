#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <stdexcept>

class Level {
    int actualLevel;
    //speed is the duration of one time unit, the integer divided by 60 will be the time unit
    int speed;
    int deletedLines;
    void setSpeed(int level){

        switch (level) {
        case 1:
            speed = 60;
            break;
        case 2:
            speed=53;
            break;
        case 3:
            speed=49;
            break;
        case 4:
            speed=45;
            break;
        case 5:
            speed=41;
            break;
        case 6:
            speed=37;
            break;
        case 7:
            speed=33;
            break;
        case 8:
            speed=28;
            break;
        case 9:
            speed=23;
            break;
        case 10:
            speed=18;
            break;
        case 11:
            speed=13;
            break;
        case 12:
            speed=8;
            break;
        case 13:
            speed=9;
            break;
        case 14:
            speed=8;
            break;
        case 15:
            speed=7;
            break;
        case 16:
            speed=6;
            break;
        case 17:
            speed=5;
            break;
        case 18:
            speed=4;
            break;
        case 19:
            speed=3;
            break;
        case 20:
            speed=2;
            break;
        default:
            if(level>20){
                speed=2;
            }else{
                throw std::out_of_range("Value is outside the allowed range");
            }
        }
    }
public:
    Level(int level=1):actualLevel(level), deletedLines(0){
        setSpeed(level);
    }

    //Receive the the deleted lines of an action and update the level
    void updateLevel(int removedLines){
        this->deletedLines += removedLines;
        actualLevel = 1 + (deletedLines/10);
        setSpeed(actualLevel);
    }

    int getActualLevel() const {
        return actualLevel;
    }

    int getSpeed() const {
        return speed;
    }

    int getDeletedLines() const {
        return deletedLines;
    }


};

#endif // LEVEL_HPP
