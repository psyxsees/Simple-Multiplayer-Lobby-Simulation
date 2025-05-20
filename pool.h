#ifndef POOL_H
#define POOL_H

class Pool 
{
	public:
		Pool(int maxSize); //constructor for player pool
		~Pool() { delete playerPool; }
		unordered_map<string, Player>* GetMap();
		int GetSize();
		void AddToPool();
		void PrintPool();
	private:
		unordered_map<string, Player>* playerPool; //string is the username

		int maxSize;
		int playerCount;
};

#endif