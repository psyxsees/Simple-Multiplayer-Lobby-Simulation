#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    float killDeathRatio;
    float winLossRatio;

public:
    Player();
    Player(std::string name, float kd, float wl);

    float getKDR() const;
    float getWLR() const;
    std::string getName() const;

    void print() const;
};

#endif
