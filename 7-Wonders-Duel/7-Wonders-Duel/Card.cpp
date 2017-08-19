// 7 Wonders Duel 
// Card class functions
// Going to work with pointers

#include "Card.h"
#include "CardProperties.h"
#include <stdarg.h>
#include <iostream>
using namespace std;
using namespace Seven_Wonders;

namespace Seven_Wonders {

	Card::Card(int cardIndexNumber)
	{
		setName(cardIndexNumber);
		setIndex(cardIndexNumber);
		setAge(cardIndexNumber);
		setType(cardIndexNumber);
		setCoinCost(cardIndexNumber);
		setWoodCost(cardIndexNumber);
		setStoneCost(cardIndexNumber);
		setClayCost(cardIndexNumber);
		setPapyrusCost(cardIndexNumber);
		setGlassCost(cardIndexNumber);
	}

	int Card::getOwner()
	{
		return mOwner;
	}

	void Card::setOwner(int playerNumber)
	{
		mOwner = playerNumber;
	}

	string Card::getName()
	{
		return mName;
	}

	void Card::setName(int cardIndexNumber)
	{
		mName = cardName[cardIndexNumber];
	}

	int Card::getIndex()
	{
		return mIndex;
	}

	void Card::setIndex(int cardIndexNumber)
	{
		mIndex = cardIndexNumber;
	}

	int Card::getAge()
	{
		return mAge;
	}

	void Card::setAge(int cardIndexNumber)
	{
		mAge = cardAge[cardIndexNumber];
	}

	int Card::getType()
	{
		return mType;
	}

	void Card::setType(int cardIndexNumber)
	{
		mType = cardType[cardIndexNumber];
	}

	int Card::getCoinCost()
	{
		return mCoinCost;
	}

	void Card::setCoinCost(int cardIndexNumber)
	{
		mCoinCost = coinCost[cardIndexNumber];
	}

	int Card::getWoodCost()
	{
		return mWoodCost;
	}

	void Card::setWoodCost(int cardIndexNumber)
	{
		mWoodCost = woodCost[cardIndexNumber];
	}

	int Card::getStoneCost()
	{
		return mStoneCost;
	}
	void Card::setStoneCost(int cardIndexNumber)
	{
		mStoneCost = stoneCost[cardIndexNumber];
	}

	int Card::getClayCost()
	{
		return mClayCost;
	}

	void Card::setClayCost(int cardIndexNumber)
	{
		mClayCost = clayCost[cardIndexNumber];
	}

	int Card::getPapyrusCost()
	{
		return mPapyrusCost;
	}

	void Card::setPapyrusCost(int cardIndexNumber)
	{
		mPapyrusCost = papyrusCost[cardIndexNumber];
	}

	int Card::getGlassCost()
	{
		return mGlassCost;
	}

	void Card::setGlassCost(int cardIndexNumber)
	{
		mGlassCost = glassCost[cardIndexNumber];
	}

	bool Card::getFaceup()
	{
		return mFaceup;
	}

	void Card::setFaceup(bool faceup)
	{
		mFaceup = faceup;
	}

	bool Card::getExposed()
	{
		return mExposed;
	}

	void Card::setExposed(bool exposed)
	{
		mExposed = exposed;
	}

	vector<float> Card::getPosition()
	{
		return mPosition;
	}

	void Card::setPosition(vector<float> position)
	{
		mPosition = position;
	}

	void Card::DoEffect()
	{

	}

}