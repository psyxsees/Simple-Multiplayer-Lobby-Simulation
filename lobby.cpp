#include <iostream>
#include <list>
#include <ctime>
using namespace std;

#include "lobby.h"

queue<Player*> Lobby::GetQueue() 
{
	return lobbyQueue;
}

bool Lobby::FindInQueue(string name)
{
    queue<Player*> lobbyQueueCopy = lobbyQueue;

    while (!lobbyQueueCopy.empty())
    {
        if (lobbyQueueCopy.front()->GetUsername() == name)
        {
            return true;
        }
        lobbyQueueCopy.pop();
    }

    return false;
}

list<Player*> Lobby::GetLobby() 
{
	return playersInLobby;
}

// choose players to add to the lobby queue that will be added to the lobby list later when some empty spots show up
void Lobby::QueuePlayers() 
{
    string input;

    if (lobbyQueue.size() < maxSize)
    {
        allPlayers->PrintPool();
        cout << endl;
        cout << "Choose players to queue (-1 stop):" << endl;
        
        input = "";

        while (input != "-1" && lobbyQueue.size() < maxSize) 
        {
            cout << "username: ";
            cin >> input;

            if ((allPlayers->GetMap()->count(input) > 0) && !FindInQueue(input))
            {
                cout << "Player " << input << " Added to queue.\n";
                lobbyQueue.push(allPlayers->GetMap()->at(input));
            }
            else 
            { 
                cout << "Player could not be added. (Is this a duplicate? Is this a real player?)\n";
            }
        }
    }
}

// assigns win and loss to corresponding teams
void Lobby::AssignWL() 
{
    int winRed = rand() % 2; // 1 is win 0 loss
    int winBlue;
    int count = 0;

    if (winRed > 0) {
        win = 'r';
        winBlue = 0;
    } else {
        win = 'b';
        winBlue = 1;
    }

    list<Player*> lobbyListC = playersInLobby;

    Player* curPlayer = nullptr;
    for (int i = 0; i < maxSize; i++)
    {
        curPlayer = lobbyListC.front();
        lobbyListC.pop_front();

        if (i < maxSize / 2) 
        {
            curPlayer->UpdateWinBalance(winBlue);
        }
        else 
        {
            curPlayer->UpdateWinBalance(winRed);
        }

        cout << "running addKD" << endl;
        curPlayer->AddKD(rand() % 50, rand() % 50);
    }
}

//adds players to lobby from queue
//if queue is full and no game has been started, than fill lobby with pushfront being red team and pushback being blue team (lobby is a list btw)
void Lobby::BuildLobby() 
{
    cout << "-Adding players from the queue to the lobby" << endl;

    while (!lobbyQueue.empty()) {//&& count < maxSize/2) {
        //front is blue team
        playersInLobby.push_front(lobbyQueue.front());
        lobbyQueue.pop();

        if (lobbyQueue.empty()) return;
        
        //back is red team
        playersInLobby.push_back(lobbyQueue.front());
        lobbyQueue.pop();
    }
}

void Lobby::PrintLobby(bool showWin) 
{
    cout << "Results: " << std::endl;
    cout << "--- Blue Team ---" << std::endl;
    if (showWin) {
        if (win == 'b') { cout << "       WIN        " << endl; }
        else { cout << "       LOSS       " << endl; }
    }

    int count = 0;
    for (Player* player : playersInLobby) 
    {
        player->UpdateKD();

        if (count == maxSize/2) { cout << "--- Red Team ---" << std::endl; }
        if (count >= maxSize / 2) 
        {
            if (showWin) {
                if (win == 'r') { cout << "       WIN        " << endl; }
                else { cout << "       LOSS       " << endl; }
            }
        }

        player->PrintPlayerData();
        ++count;
    }
}

// when restarting disconnect all players
void Lobby::AllocateLobbyPlayers() 
{
    list<Player*> temp;
    //queue<Player*> emptyQueue;

    /*
    activePlayers = 0;

    for (Player* player : playersInLobby) {
        if (rand() > 0.5) {
            temp.push_front(player);
            activePlayers++;
        }
    }

    if (temp.empty()) return;
    */

    
    while (!lobbyQueue.empty()){
        lobbyQueue.pop();
    }

    playersInLobby = temp;
    //lobbyQueue = emptyQueue;
}
