#include <iostream>
#include <unordered_map>
using namespace std;

#include "pool.h"

Pool::Pool(int maxSize) {
	this->maxSize = maxSize;
	playerCount = 0;
}

unordered_map<string, Player> Pool::GetMap() {
	return playerPool;
}

void Pool::AddToPool() {
	string username;
	string heroClass;

	cout << "Create players for the Player Pool" << endl;

	while (playerCount < maxSize) {
		cout << "username: ";
		cin >> username;
		cout << "pick class: ";
		cin >> heroClass;
		cout << endl;

		Player player(username, heroClass);
		*playerPool[username] = player;

		playerCount++;
	}
}

void Pool::printPool() const {
	for (const auto& player : playerPool) {
		player.print();
	}
}

list<Player>& Pool::getPlayers() {
	return players;
}