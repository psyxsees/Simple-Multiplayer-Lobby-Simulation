#ifndef POOL_H
#define POOL_H

#include "player.h"
#include <unordered_map>

class Pool 
{
	public:
		Pool(int maxSize); //constructor for player pool
		~Pool() { delete playerPool; }
		unordered_map<string, Player*>* GetMap();
		int GetSize();
		int GetPlayerNum();
		void AddToPool();
		void PrintPool();
	private:
		unordered_map<string, Player*>* playerPool; //string is the username

		int maxSize;
		int playerCount;
};

#endif

