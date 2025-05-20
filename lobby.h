#ifndef LOBBY_H
#define LOBBY_H

#include "pool.h"
#include <queue>

class Lobby 
{
	public:
		Lobby(int maxSize, Pool *allPlayers) 
		{
			this->maxSize = maxSize;
			this->allPlayers = allPlayers;
			//activePlayers = 0;
			srand(static_cast<unsigned>(time(0)));
		}

		queue<Player*> GetQueue();
		list<Player*> GetLobby();
		void QueuePlayers();
		void AssignWL(); // assign wins and losses to corresponding teammates
		void BuildLobby();
		void PrintLobby(bool showWin);
		void AllocateLobbyPlayers();
	private:
		Pool* allPlayers;
		queue<Player*> lobbyQueue;
		list<Player*> playersInLobby;

		char win = ' '; // r red b blue for PrintLobby
		//int activePlayers;
		int maxSize; //max size of queue and list

		bool FindInQueue(string name);
};

#endif