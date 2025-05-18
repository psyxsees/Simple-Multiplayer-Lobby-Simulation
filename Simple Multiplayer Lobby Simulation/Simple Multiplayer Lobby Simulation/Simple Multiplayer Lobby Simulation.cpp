// Simple Multiplayer Lobby Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    To Do:
        DataStructures:
            A hash table to store player objects
            A list representing the lobby and the players in it
            A queue for players waiting for a match
        Features:
            allow the user to create players that can be added to the hashmap
            See the players in the lobby with their stats printed, im thinking the lobby should probably have a dedicated class for it
            let the user choose and enqueue players into the queue
            And when the 5v5 game ends, the players should have a random number of kills and deaths, and a win or loss for their corresponding team.

        most of this project is basically creating fake multiplayer interactions if that makes sense

        Feel free to add to this or modify if something doesn't make sense, 
        please don't delete any of these tasks when done, 
        just put a star next to it if it's done. 
*/

#include <iostream>

#include "player.cpp"
#include "lobby.cpp"
#include "pool.cpp"

int main()
{
    /*  Test's Player class:
        Player* dude = new Player("guy");
        dude->PrintPlayerData();
        delete dude;
    */

    Pool* allPlayers = new Pool(50);
    Lobby* gameLobby = new Lobby(10, allPlayers);
    
    allPlayers->AddToPool();
    std::cout << "=== Player Pool ===" << std::endl;
    allPlayers->printPool();

    gameLobby->buildLobby();
    std::cout << "\n=== Lobby ===" << std::endl;
    gameLobby->printLobby();

    delete allPlayers;
    delete gameLobby;

    return 0;
}
