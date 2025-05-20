#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

#include "pool.h"

Pool::Pool(int maxSize)
{
	this->maxSize = maxSize;
	playerCount = 0;
	playerPool = new unordered_map<string, Player*>;
	srand(static_cast<unsigned>(time(0)));
}

unordered_map<string, Player*>* Pool::GetMap()
{
	return playerPool;
}

int Pool::GetSize()
{
	return maxSize;
}

int Pool::GetPlayerNum()
{
	return playerCount;
}

void Pool::AddToPool()
{
	ifstream ifs("usernames.txt");
	vector<string> usernames;
	string line;

	// Check for file open success
	if (!ifs.is_open())
	{
		cout << "Error: Failed to open usernames.txt" << endl;
	}

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

		if (username == "-1") 
		{
			check = true;
			while (check)
			{
				cout << "Username: ";
				cin >> username;

				if (playerPool->count(username) > 0)
				{
					check = true;
					cout << "That user has already joined, please enter another username.\n";
				}
				else
				{
					check = false;
				}
			}

			// define hero class
			hero = rand() % 3;
			if (hero == 0) {
				heroClass = "Heavy";
			}
			else if (hero == 1) {
				heroClass = "Medium";
			}
			else {
				heroClass = "Light";
			}

			Player* newPlayer = new Player(username, heroClass);
			playerPool->emplace(username, newPlayer);

			playerCount++;
		} 
		else 
		{
			//dupe check + get random username
			
			check = true;
			while (check)
			{
				username = usernames[rand() % usernames.size()];

				if (playerPool->count(username) > 0) 
				{
					check = true;
				}
				else check = false;
			}

			// define hero class
			hero = rand() % 3;
			if (hero == 0) {
				heroClass = "Heavy";
			}
			else if (hero == 1) {
				heroClass = "Medium";
			}
			else {
				heroClass = "Light";
			}

			Player* newPlayer = new Player(username, heroClass);
			playerPool->emplace(username, newPlayer);

			playerCount++;
		}
	}
}

void Pool::PrintPool()
{
	cout << "--- Player Pool ---" << endl;
	for (auto& item : *playerPool) {
		item.second->PrintPlayerData();
	}
}