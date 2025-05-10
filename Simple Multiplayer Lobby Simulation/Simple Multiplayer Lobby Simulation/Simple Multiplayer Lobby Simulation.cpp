// Simple Multiplayer Lobby Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    To Do:
        DataStructures:
            A hash table to store player objects
            A list representing the lobby and the players in it
            A queue for players waiting for a match
        Features:
            See the players in the lobby with their stats printed, im thinking the lobby should probably have a dedicated class for it
            Enqueue players into the queue
            Add players to the lobby from the queue(preferably balanced based on stats although this is not required it would be cool)

        Feel free to add to this or modify for clarity if i missed anything, 
        please don't delete any of these tasks when done, 
        just put a star next to it if it's done. 
*/

#include <iostream>

#include "player.cpp"

int main()
{
    Player* dude = new Player("guy");
    dude->PrintPlayerData();
    delete dude;



}
