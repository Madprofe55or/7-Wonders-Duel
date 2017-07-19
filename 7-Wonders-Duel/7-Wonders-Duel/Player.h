// 7 Wonders Duel
// Player Class header

#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Game_Constants.h"
#include <map>
using namespace std;

class Player
{
public:
	Player(int playerNumber);
	~Player();
	void constructorDebug();
	int getPlayerNumber();
	void setGoesFirst(bool goesfirst);
	bool getGoesFirst();
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
	int getNumOfScienceSymbols(string symbolType);
	void setNumOfScienceSymbols(string symbolType, int changeInSymbols);
	bool getTradeFlag(string resourceType);
	void setTradeFlag(string resourceType, bool flagSetting);
	
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


	map<string, int> scienceSymbolsMap = { {"Arch", 0}, {"Wheel", 0}, {"Quill", 0}, {"Mortar", 0}, {"Balance", 0}, {"Tablet", 0}, {"Globe", 0} };
	map<string, bool> tradeFlagsMap = { {"Wood", false}, {"Stone", false}, {"Clay", false}, {"Papyrus", false}, {"Glass", false} };
	

};

#endif // PLAYER_H
