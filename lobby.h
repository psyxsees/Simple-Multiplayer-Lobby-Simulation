#ifndef LOBBY_H
#define LOBBY_H

class Lobby 
{
	public:
		Lobby(int maxSize, Pool &allPlayers) 
		{
			this->maxSize = maxSize;
			this->allPlayers = &allPlayers;
		}
		~Lobby() { delete allPlayers; }
		queue<Player> GetQueue();
		list<Player> GetLobby();
		void QueuePlayers();
		void AssignWL(); // assign wins and losses to corresponding teammates
		void BuildLobby();
		void PrintLobby();
	private:
		Pool* allPlayers;
		queue<Player> lobbyQueue;
		list<Player> playersInLobby;

		int maxSize; //max size of queue and list
};

#endif