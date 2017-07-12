// 7 Wonders Duel
// Card Class header

#pragma once
#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card 
{
public:
	Card(int cardIndexNumber);
	void constructorDebug();
	int getOwner();
	void setOwner(int playerNumber);
	string getName();
	void setName(int cardIndexNumber);
	int getIndex();
	void setIndex(int cardIndexNumber);
	int getAge();
	void setAge(int cardIndexNumber);
	int getType();
	void setType(int cardIndexNumber);
	int getCoinCost();
	void setCoinCost(int cardIndexNumber);
	int getWoodCost();
	void setWoodCost(int cardIndexNumber);
	int getStoneCost();
	void setStoneCost(int cardIndexNumber);
	int getClayCost();
	void setClayCost(int cardIndexNumber);
	int getPapyrusCost();
	void setPapyrusCost(int cardIndexNumber);
	int getGlassCost();
	void setGlassCost(int cardIndexNumber);
	int* getLocation();
	void setLocation(int xPosition, int yPosition);
	void DoEffect();

private:
	int mOwner;
	string mName;
	int mIndex;
	int mAge;
	int mType;
	int mCoinCost;
	int mWoodCost;
	int mStoneCost;
	int mClayCost;
	int mPapyrusCost;
	int mGlassCost;
	int mPosition[2]; // needs to be an x,y position
};

#endif // CARD_H