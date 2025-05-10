#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		Player(string username); // all stats besides username should be 0
		string GetUsername(); // returns username
		double GetKD(); // returns kd
		int GetWinBalance(); // returns win loss balance
		void UpdateKD(); // num Kills should be added to allKills, same with allDeaths, and using those updated values find KD.
		void UpdateWinBalance(int outcome); // outcome will be added to winLossBalance, and should be (0,1, or -1)
		void AddDeath();// adds to tempDeath
		void AddKill(); // adds to tempKill
		void Reset(); // any variables that need to be reset after a game can be reset here
		void PrintPlayerData();
	private:
		string username;
		string team;

		double kd; // kill death ratio
		int allKills;
		int allDeaths;

		int tempKill; //should be set back to 0 after every game
		int tempDeath;

		int winLossBalance; // ratio of wins and losses
};
#endif