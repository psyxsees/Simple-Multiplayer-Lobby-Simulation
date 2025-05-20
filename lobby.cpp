#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <ctime>
using namespace std;

#include "lobby.h"

queue<Player> Lobby::GetQueue() 
{
	return lobbyQueue;
}
list<Player> Lobby::GetLobby() 
{
	return playersInLobby;
}

// choose players to add to the lobby queue that will be added to the lobby list later when some empty spots show up
void Lobby::QueuePlayers() 
{
    string input;

    if (lobbyQueue.size() < maxSize) {
        allPlayers->PrintPool();
        cout << endl;
        cout << "\nChoose players to queue (-1 stop):" << endl;

        cin >> input;
        while (input != "-1" && lobbyQueue.size() < maxSize) {
            // pushing players from hashmap to lobby queue
            if (allPlayers->count(input)) {
                lobbyQueue.push((*allPlayers)[input]);
                cout << "Queued: " << input << endl;
            }
            else {
                cout << "Player not found. Try again: ";
            }
            cin >> input;
        }
    }
}

// assigns win and loss to corresponding teams
void Lobby::AssignWL() 
{
    srand(static_cast<unsigned>(time(0)));
    int winRed = rand() % 2; // 1 is win 0 loss
    int winBlue;
    int count;

    if (winRed > 0) {
        win = 'r';
        winBlue = 0;
    } else {
        win = 'b';
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
//if queue is full and no game has been started, than fill lobby with pushfront being red team and pushback being blue team (lobby is a list btw)
void Lobby::BuildLobby() 
{
    int count = 0;

    cout << "-Adding players from the queue to the lobby" << endl;

    while (!lobbyQueue.empty() && count < maxSize/2) {
        //front is blue team
        playersInLobby.push_front(lobbyQueue.front());
        lobbyQueue.pop();
        //back is red team
        playersInLobby.push_back(lobbyQueue.front());
        lobbyQueue.pop();
        ++count;
    }
}

void Lobby::PrintLobby() 
{
    cout << "--- Blue Team ---" << std::endl;
    if (win == 'b') { cout << "       WIN       " << endl; } 
    else { cout << "       LOSS       " << endl; }

    int count = 0;
    for (Player player : playersInLobby) {
        player.UpdateKD();
        if (count >= maxSize / 2) {
            cout << "--- Red Team ---" << std::endl;
            if (win == 'r') { cout << "       WIN       " << endl; }
            else { cout << "       LOSS       " << endl; }
        }
        player.PrintPlayerData();
        ++count;
    }
}

// supposed to random disconnect some players if the user decides to continue and not restart
// if they restart disconnect all players
void Lobby::AllocateLobbyPlayers() 
{
    srand(static_cast<unsigned>(time(0)));
    
    list<Player>* temp;

    for (Player player : playersInLobby) {
        if (rand() > 0.5) {
            temp->push_front(player);
        }
    }

    playersInLobby = *temp;
}