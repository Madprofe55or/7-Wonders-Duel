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
		mVictoryPoints = setVictoryPoints(cardIndexNumber);
		mScienceSymbol = setScienceSymbol(cardIndexNumber);
		mShields = setShields(cardIndexNumber);

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

	int Card::getVictoryPoints()
	{
		return mVictoryPoints;
	}

	int Card::setVictoryPoints(int cardIndexNumber)
	{
		switch (cardIndexNumber)
		{
		case 19: // theater
			return 3;
			break;
		case 20: // altar
			return 3;
			break;
		case 21: // baths
			return 3;
			break;
		case 32: // tribunal
			return 5;
			break;
		case 41: // statue
			return 4;
			break;
		case 42: // temple
			return 4;
			break;
		case 43: // aqueduct
			return 5;
			break;
		case 44: // rostrum
			return 4;
			break;
		case 53: // palace
			return 7;
			break;
		case 54: // town hall
			return 7;
			break;
		case 55: // obelisk
			return 5;
			break;
		case 61: // gardens
			return 6;
			break;
		case 62: // pantheon
			return 6;
			break;
		case 63: // senate
			return 5;
			break;
		case 9: // workshop
			return 1;
			break;
		case 10: // apothecary
			return 1;
			break;
		case 37: // library
			return 2;
			break;
		case 38: // dispensary
			return 2;
			break;
		case 39: // school
			return 1;
			break;
		case 40: // laboratory
			return 1;
			break;
		case 48: // academy
			return 3;
			break;
		case 49: // study
			return 3;
			break;
		case 59: // university
			return 2;
			break;
		case 60: // observatory
			return 2;
			break;
		case 50: // chamber of commerce
			return 3;
			break;
		case 51: // port
			return 3;
			break;
		case 52: // armory
			return 3;
			break;
		case 64: // lighthouse
			return 3;
			break;
		case 65: // arena
			return 3;
			break;
		case 73: // the appian way
			return 3;
			break;
		case 74: // circus maximus
			return 3;
			break;
		case 75: // the colossus
			return 3;
			break;
		case 76: // the great library
			return 4;
			break;
		case 77: // the great lighthouse
			return 4;
			break;
		case 78: // the hanging gardens
			return 3;
			break;
		case 79: // the mausoleum
			return 2;
			break;
		case 80: // piraeus
			return 2;
			break;
		case 81: // the pyramids
			return 9;
			break;
		case 82: // the sphinx
			return 6;
			break;
		case 83: // the statue of zeus
			return 3;
			break;
		default:
			return 0;
		}
	}

	int Card::getScienceSymbol()
	{
		return mScienceSymbol;
	}

	int Card::setScienceSymbol(int cardIndexNumber)
	{
		switch (cardIndexNumber)
		{
		case 9: // workshop
			return SCIENCE_SYMBOL_ARCH;
			break;
		case 10: // apothecary
			return SCIENCE_SYMBOL_WHEEL;
			break;
		case 17: // sciptorium
			return SCIENCE_SYMBOL_QUILL;
			break;
		case 18: // pharmacist
			return SCIENCE_SYMBOL_MORTAR;
			break;
		case 37: // library
			return SCIENCE_SYMBOL_QUILL;
			break;
		case 38: // dispensary
			return SCIENCE_SYMBOL_MORTAR;
			break;
		case 39: // school
			return SCIENCE_SYMBOL_WHEEL;
			break;
		case 40: // laboratory
			return SCIENCE_SYMBOL_ARCH;
			break;
		case 48: // academy
			return SCIENCE_SYMBOL_TABLET;
			break;
		case 49: // study
			return SCIENCE_SYMBOL_TABLET;
			break;
		case 59: // university
			return SCIENCE_SYMBOL_GLOBE;
			break;
		case 60: // observatory
			return SCIENCE_SYMBOL_GLOBE;
			break;
		default:
			return SCIENCE_SYMBOL_NONE;
			break;
		}
	}

	int Card::setShields(int cardIndexNumber)
	{
		switch (cardIndexNumber)
		{
		case 8: // guard tower
			return 1;
			break;
		case 14: // stable
			return 1;
			break;
		case 15: // garrison
			return 1;
			break;
		case 16: // palisade
			return 1;
			break;
		case 28: // walls
			return 2;
			break;
		case 33: // horse breeders
			return 1;
			break;
		case 34: // barracks
			return 1;
			break;
		case 35: // archery range
			return 2;
			break;
		case 36: // parade ground
			return 2;
			break;
		case 46: // arsenal
			return 3;
			break;
		case 47: // courthouse
			return 3;
			break;
		case 56: // fortifications
			return 2;
			break;
		case 57: // siege workshop
			return 2;
			break;
		case 58: // circus
			return 2;
			break;
		case 74: // circus maximus
			return 1;
			break;
		case 75: // the colossus
			return 2;
			break;
		case 83: // the statue of zeus
			return 1;
			break;
		default:
			return 0;
		}
	}

	int Card::getShields()
	{
		return mShields;
	}

	vector<float> Card::getPosition()
	{
		return mPosition;
	}

	void Card::setPosition(vector<float> position)
	{
		mPosition = position;
	}
}