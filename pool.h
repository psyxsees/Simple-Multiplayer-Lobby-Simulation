#ifndef POOL_H
#define POOL_H

#include <list>
#include "Player.h"

class Pool {
private:
    std::list<Player> players;

public:
    void fillPool(int count);
    void sortPool();
    void printPool() const;
    std::list<Player>& getPlayers();
};

#endif
