// 7 Wonders Duel 
// Player class functions
// Playing with pointers

#include "Player.h"
#include <stdarg.h>
#include <iostream>
using namespace std;
using namespace Seven_Wonders;

namespace Seven_Wonders {

	Player::Player(int playerNumber) // constructor will need to set all starting resource values
	{
		if (playerNumber == PLAYER_1)
		{
			mPlayerNumber = PLAYER_1;
			setGoesFirst(true); // for now Player 1 will go first
		}
		else if (playerNumber == PLAYER_2)
		{
			mPlayerNumber = PLAYER_2;
			setGoesFirst(false);
		}

	}

	Player::~Player()
	{
	}

	void Player::constructorDebug()
	{
		cout << "Created Player, #" << getPlayerNumber() << ", with the following starting resources:" << endl <<
			"Coins: " << getCoins() << endl <<
			"Wood: " << getWood() << endl <<
			"Stone: " << getStone() << endl <<
			"Clay: " << getClay() << endl <<
			"Papyrus: " << getPapyrus() << endl <<
			"Glass: " << getGlass() << endl << endl;
	}

	int Player::getPlayerNumber()
	{
		return mPlayerNumber;
	}

	void Player::setGoesFirst(bool goesfirst)
	{
		mGoesFirst = goesfirst;
	}

	bool Player::getGoesFirst()
	{
		return mGoesFirst;
	}

	int Player::getCoins()
	{
		return mCoins;
	}

	void Player::setCoins(int changeInCoins)
	{
		mCoins = mCoins + changeInCoins;
	}

	int Player::getWood()
	{
		return mWood;
	}

	void Player::setWood(int changeInWood)
	{
		mWood = mWood + changeInWood;
	}

	int Player::getStone()
	{
		return mStone;
	}

	void Player::setStone(int changeInStone)
	{
		mStone = mStone + changeInStone;
	}

	int Player::getClay()
	{
		return mClay;
	}

	void Player::setClay(int changeInClay)
	{
		mClay = mClay + changeInClay;
	}

	int Player::getPapyrus()
	{
		return mPapyrus;
	}

	void Player::setPapyrus(int changeInPapyrus)
	{
		mPapyrus = mPapyrus + changeInPapyrus;
	}

	int Player::getGlass()
	{
		return mGlass;
	}


	void Player::setGlass(int changeInGlass)
	{
		mGlass = mGlass + changeInGlass;
	}

	int Player::getDiscardGoldValue()
	{
		int yellowCardCount = 0;
		if (!playerCity.empty()) // check if there are cards in the city yet
		{
			for (std::vector<Card*>::iterator it = playerCity.begin(); it != playerCity.end(); ++it)
			{
				if ((*it)->getType() == YELLOW_CARD) yellowCardCount++;
			}
			return yellowCardCount + 2; // 2 gold is the base and each yellow card adds one to the gold value
		}
		else return 2; // if there are no cards in the city yet, then just return the base gold value of 2
	}

	/* Will need to reset flags for special conditions eventually too.*/
	void Player::resetResources()
	{
		mCoins = 7;
		mWood = 0;
		mStone = 0;
		mClay = 0;
		mPapyrus = 0;
		mGlass = 0;

	}

}


