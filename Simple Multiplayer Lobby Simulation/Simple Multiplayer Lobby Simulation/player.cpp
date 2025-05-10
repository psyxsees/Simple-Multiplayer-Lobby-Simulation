#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "player.h"

// constructor for the player class
// all stats besides username should be 0
Player::Player(string username) {
	this->username = username;
	team = "";

	kd = 0;
	allKills = 0;
	allDeaths = 0;
	tempKill = 0;
	tempDeath = 0;

	winLossBalance = 0;
}

// returns username
string Player::GetUsername() {
	return username;
}

// returns kd
double Player::GetKD() {
	return kd;
}

// returns win loss balance
int Player::GetWinBalance() {
	return winLossBalance;
}

// Using allKills and allDeaths values find KD.
void Player::UpdateKD() {
	kd = allKills / allDeaths;
}

// outcome will be added to winLossBalance, and should be (0,1, or -1)
void Player::UpdateWinBalance(const int outcome) {
	winLossBalance += outcome;
}

void Player::AddDeath() {
	tempDeath++;
}

void Player::AddKill() {
	tempKill++;
}

void Player::Reset() {
	tempDeath = 0;
	tempKill = 0;
}

void Player::PrintPlayerData() {
	cout << "-----Player Data-----" << endl;
	cout << setw(21) << left << "username: " << right << username << endl;
	cout << setw(21) << left << "kd: " << right << kd << endl;
	cout << setw(21) << left << "winLossBalance: " << right << winLossBalance << endl;
}