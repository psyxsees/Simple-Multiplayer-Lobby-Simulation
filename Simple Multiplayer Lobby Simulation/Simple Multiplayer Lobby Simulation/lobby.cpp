#include <iostream>
#include <queue>
#include <list>
using namespace std;

#include "lobby.h"

Lobby::Lobby(int maxSize, Pool &allPlayers) {
	this->maxSize = maxSize;
	this->allPlayers = &allPlayers;
}
queue<Player> Lobby::GetQueue() {
	return lobbyQueue;
}
list<Player> Lobby::GetLobby() {
	return playersInLobby;
}
void Lobby::EnqueuePlayers() {
	allPlayers->PrintPlayers();
	cout << "choose players to queue" << endl;
	
	//if queue is full and no game has been started, than fill lobby with pushfront being red team and pushback being blue team (lobby is a list btw)
}
void Lobby::AssignWL() {

}
void Lobby::AssignKD() {

}