// 7 Wonders Duel 
// Progress token class functions

#include "ProgressToken.h"
#include <stdarg.h>
#include <iostream>
using namespace std;
using namespace Seven_Wonders;

namespace Seven_Wonders {

	ProgressToken::ProgressToken(int indexNumber)
	{
		setName(indexNumber);
	}

	string ProgressToken::getName()
	{
		return mName;
	}

	void ProgressToken::setName(int indexNumber)
	{
		mName = progressTokenNames[indexNumber];
	}

	int ProgressToken::getOwner()
	{
		return mOwner;
	}

	void ProgressToken::setOwner(int playerNumber)
	{
		mOwner = playerNumber;
	}



}
