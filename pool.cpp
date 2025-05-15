#include "Pool.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Pool::fillPool(int count) {
    //Seed time for a new random number generator to fill the pool with reasonable stats
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < count; ++i) {
        float kd = static_cast<float>(rand() % 201 + 50) / 100.0f;
        float wl = static_cast<float>(rand() % 201 + 50) / 100.0f;
        players.emplace_back("Player" + std::to_string(i + 1), kd, wl);
    }
}
//Lambda function to sort based on WL KD emphasis change constants to change lobby emphasis
void Pool::sortPool() {
    players.sort([](const Player& a, const Player& b) {
        float scoreA = (a.getKDR() * 0.4f) + (a.getWLR() * 0.6f);
        float scoreB = (b.getKDR() * 0.4f) + (b.getWLR() * 0.6f);
        return scoreA > scoreB;
        });
}

void Pool::printPool() const {
    for (const auto& player : players) {
        player.print();
    }
}

std::list<Player>& Pool::getPlayers() {
    return players;
}
