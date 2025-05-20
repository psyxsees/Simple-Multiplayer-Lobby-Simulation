#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
	public:
		Player(); // make the compiler stop crying
		Player(string username, string heroClass); // all stats besides username should be 0
		string GetUsername(); // returns username
		double GetKD(); // returns kd
		int GetWinBalance(); // returns win loss balance
		void UpdateKD(); // num Kills should be added to allKills, same with allDeaths, and using those updated values find KD.
		void UpdateWinBalance(int outcome); // outcome will be added to winLossBalance, and should be (0,1, or -1)
		void AddKD(int kills, int deaths); // adds kills and deaths to allKills and allDeaths
		void PrintPlayerData();
	private:
		string username;
		string team;
		string heroClass;

		double kd; // kill death ratio
		int allKills;
		int allDeaths;

		int winLossBalance; // ratio of wins and losses
};
#endif