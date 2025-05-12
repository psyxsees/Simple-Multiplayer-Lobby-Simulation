#ifndef LOBBY_H
#define LOBBY_H

class Lobby 
{
	public:
		Lobby(int maxSize, Pool &allPlayers);
		queue<Player> GetQueue();
		list<Player> GetLobby();
		void EnqueuePlayers();
		void AssignWL(); // assign wins and losses to corresponding teammates
		void AssignKD(); // assign kills and deaths to corresponding teammates
	private:
		Pool* allPlayers;
		queue<Player> lobbyQueue;
		list<Player> playersInLobby;

		int maxSize; //max size of queue and list
};

#endif