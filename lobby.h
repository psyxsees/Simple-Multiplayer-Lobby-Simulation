#ifndef LOBBY_H
#define LOBBY_H

#include <deque>
#include <list>
#include "Player.h"

class Lobby {
private:
    //Double ended queue for push front/back
    std::deque<Player> lobby;

public:
    void buildLobby(std::list<Player>& sortedPlayers);
    void printLobby() const;
};

#endif
