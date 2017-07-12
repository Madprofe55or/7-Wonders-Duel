// 7 Wonders Duel
// Player Class header

#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Game_Constants.h"

class Player
{
public:
	Player(int playerNumber);
	~Player();
	void constructorDebug();
	int getPlayerNumber();
	void setGoesFirst(bool goesfirst);
	int getCoins();
	void setCoins(int changeInCoins);
	int getWood();
	void setWood(int changeInWood);
	int getStone();
	void setStone(int changeInStone);
	int getClay();
	void setClay(int changeInClay);
	int getPapyrus();
	void setPapyrus(int changeInPapyrus);
	int getGlass();
	void setGlass(int changeInGlass);


private:
	int mPlayerNumber;
	bool mGoesFirst;
	int mCoins = 0;
	int mWood = 0;
	int mStone = 0;
	int mClay = 0;
	int mPapyrus = 0;
	int mGlass = 0;
	static const int STARTING_COINS = 7;
	static const int STARTING_ALL_OTHERS = 0;
};

#endif // PLAYER_H
