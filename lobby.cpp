#include "Lobby.h"
#include <iostream>

//Build a competitive 5v5 lobby from the sorted pool
void Lobby::buildLobby(std::list<Player>& sortedPlayers) {
    int count = 0;
    auto it = sortedPlayers.begin();
    while (it != sortedPlayers.end() && count < 5) {
        lobby.push_front(*it);
        it = sortedPlayers.erase(it);
        lobby.push_back(*it);
        it = sortedPlayers.erase(it);
        ++count;
    }
}

void Lobby::printLobby() const {
    std::cout << "--- Blue Team ---" << std::endl;
    int count = 0;
    for (const auto& player : lobby) {
        if (count == 5)
            std::cout << "--- Red Team ---" << std::endl;
        player.print();
        ++count;
    }
}
