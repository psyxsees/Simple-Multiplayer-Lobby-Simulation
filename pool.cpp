#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

#include "pool.h"

Pool::Pool(int maxSize) 
{
	this->maxSize = maxSize;
	playerCount = 0;
}

unordered_map<string, Player>* Pool::GetMap() 
{
	return playerPool;
}

int Pool::GetSize() 
{
	return playerCount;
}

void Pool::AddToPool() 
{
	std::ifstream ifs;
	ifs.open("usernames.txt", std::ifstream::in);

	string username;
	string heroClass;
	int hero;

	cout << "Create players for the Player Pool:" << endl;

	while (playerCount < maxSize) {
		srand(static_cast<unsigned>(time(0)));

		cout << "Custom or Random username? (-1 custom, 0 random):";
		cin >> username;
		if (username == "-1") {
			cout << "username: ";
			cin >> username;
		} else {
			// implement random username
			username;
		}
		
		// define hero class
		hero = rand() % 3;
		if (hero == 0) {
			heroClass = "Heavy";
		} else if (hero == 1) {
			heroClass = "Medium";
		} else {
			heroClass = "Small";
		}

		Player player(username, heroClass);
		*playerPool[username] = player;

		playerCount++;
	}

	ifs.close();
}

void Pool::PrintPool() 
{
	for (Player player : *playerPool) {
		player.PrintPlayerData();
	}
}