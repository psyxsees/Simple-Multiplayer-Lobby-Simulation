#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "pool.h"

Pool::Pool(int maxSize)
{
	this->maxSize = maxSize;
	playerCount = 0;
	playerPool = new unordered_map<string, Player>;
	srand(static_cast<unsigned>(time(0)));
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
	ifstream ifs("usernames.txt");
	vector<string> usernames;
	string line;
	ifs.open("usernames.txt", std::ifstream::in);

	// Load all usernames into a vector
	while (getline(ifs, line)) {
		if (!line.empty())
			usernames.push_back(line);
	}
	ifs.close();

	string username;
	string heroClass;
	int hero;
	bool check = false;

	cout << "Create players for the Player Pool:" << endl;

	while (playerCount < maxSize) {
		cout << "Custom or Random username? (-1 custom, 0 random):";
		cin >> username;

		if (username == "-1") {
			//dupe check + ask for username
			do {
				cout << "username: ";
				cin >> username;

				if (playerPool->count(username) > 0) {
					check = true;
				}
				else { check = false; }
			} while (check);
		} else {
			//dupe check + get random username
			do {
				username = usernames[rand() % usernames.size()];

				if (playerPool->count(username) > 0) {
					check = true;
				}
				else { check = false; }
			} while (check);

			// define hero class
			hero = rand() % 3;
			if (hero == 0) {
				heroClass = "Heavy";
			}
			else if (hero == 1) {
				heroClass = "Medium";
			}
			else {
				heroClass = "Small";
			}

			Player player(username, heroClass);
			(*playerPool)[username] = player;

			playerCount++;
		}
	}
}

void Pool::PrintPool()
{
	for (auto& pair : *playerPool) {
		pair.second.PrintPlayerData();
	}
}