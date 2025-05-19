#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "player.h"

// constructor for the player class
// all stats besides username should be 0
Player::Player(string username, string heroClass) 
{
	this->username = username;
	team = "";
	this->heroClass = heroClass;

	kd = 0;
	allKills = 0;
	allDeaths = 0;

	winLossBalance = 0;
}

// returns username
string Player::GetUsername()
{
	return username;
}

// returns kd
double Player::GetKD() 
{
	return kd;
}

// returns win loss balance
int Player::GetWinBalance() 
{
	return winLossBalance;
}

// Using allKills and allDeaths values find KD.
void Player::UpdateKD() 
{
	kd = allKills / allDeaths;
}

// outcome will be added to winLossBalance, and should be (0,1, or -1)
void Player::UpdateWinBalance(int outcome) 
{
	winLossBalance += outcome;
}

void Player::AddKD(int kills, int deaths)
{
	allKills += kills;
	allDeaths += deaths;
}

void Player::PrintPlayerData() 
{
	cout << "-----Player Data-----" << endl;
	cout << setw(21) << left << "username: " << right << username << endl;
	cout << setw(21) << left << "kd: " << right << kd << endl;
	cout << setw(21) << left << "winLossBalance: " << right << winLossBalance << endl;
	cout << endl;
	cout << "---------------------" << endl;
	cout << endl;
}