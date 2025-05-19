#include <iostream>
#include <queue>
#include <list>
using namespace std;

#include "lobby.h"

queue<Player> Lobby::GetQueue() {
	return lobbyQueue;
}
list<Player> Lobby::GetLobby() {
	return playersInLobby;
}
void Lobby::QueuePlayers() {
    string input;

    if (lobbyQueue.size() < maxSize) {
        allPlayers->PrintPlayers();
        cout << endl;
        cout << "choose players to queue" << endl;

        cin >> input;
        while (input != "-1" && lobbyQueue.size() < maxSize) {
            lobbyQueue.push(allPlayers[input]); // pushing players from hashmap to lobby queue
            cin >> input;
        }
    }
	
	//if queue is full and no game has been started, than fill lobby with pushfront being red team and pushback being blue team (lobby is a list btw)
}

void Lobby::AssignWL() {
    srand(static_cast<unsigned>(time(0)));
    int winRed = rand() % 2; // 1 is win 0 loss
    int winBlue;
    int count;

    if (winRed > 0) {
        winBlue = 0;
    } else {
        winBlue = 1;
    }

    for (Player player : playersInLobby) {
        if (count < playersInLobby.size() / 2) {
            player.UpdateWinBalance(winBlue);
        } else {
            player.UpdateWinBalance(winRed);
        }
        player.AddKD(rand() % 50, rand() % 50);
        count++;
    }
}

//adds players to lobby from queue
void Lobby::BuildLobby() {
    int count = 0;
    while (!lobbyQueue.empty() && count < maxSize/2) {
        playersInLobby.push_front(lobbyQueue.front());
        lobbyQueue.pop();
        playersInLobby.push_back(lobbyQueue.front());
        lobbyQueue.pop();
        ++count;
    }
}

void Lobby::PrintLobby() 
{
    std::cout << "--- Blue Team ---" << std::endl;
    int count = 0;
    for (Player player : playersInLobby) {
        player.UpdateKD();
        if (count == maxSize / 2)
            std::cout << "--- Red Team ---" << std::endl;
        player.PrintPlayerData();
        ++count;
    }
}