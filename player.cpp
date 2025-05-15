#include "Player.h"

Player::Player() : name("Unknown"), killDeathRatio(0), winLossRatio(0) {}

Player::Player(std::string name, float kd, float wl)
    : name(name), killDeathRatio(kd), winLossRatio(wl) {
}

float Player::getKDR() const {
    return killDeathRatio;
}

float Player::getWLR() const {
    return winLossRatio;
}

std::string Player::getName() const {
    return name;
}

void Player::print() const {
    std::cout << name << " | K/D: " << killDeathRatio << " | W/L: " << winLossRatio << std::endl;
}
