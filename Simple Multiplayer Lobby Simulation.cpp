#include "Pool.h"
#include "Lobby.h"
#include <iostream>

int main() {
    Pool pool;
    pool.fillPool(20);
    std::cout << "=== Player Pool ===" << std::endl;
    pool.printPool();

    pool.sortPool();
    std::cout << "\n=== Sorted Player Pool ===" << std::endl;
    pool.printPool();

    Lobby lobby1;
    lobby1.buildLobby(pool.getPlayers());
    std::cout << "\n=== Lobby ===" << std::endl;
    lobby1.printLobby();

    return 0;
}
