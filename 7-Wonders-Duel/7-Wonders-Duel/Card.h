// 7 Wonders Duel
// Card Class header

#pragma once
#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>
#include "Game_Constants.h"
using namespace std;

namespace Seven_Wonders {

	class Card
	{
	public:
		Card(int cardIndexNumber);
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
		vector<float> getPosition();
		void setPosition(vector<float> position);
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
		std::vector<float> mPosition = START_POSITION; // needs to be an x,y position, and float to be able to pass to vector2f in SFML
	};

}

#endif // CARD_H