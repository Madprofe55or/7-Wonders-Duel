// 7 Wonders Duel
// Military Token class functions

#include "MilitaryToken.h"
#include <stdarg.h>
#include <iostream>
using namespace std;
using namespace Seven_Wonders;

namespace Seven_Wonders {

	MilitaryToken::MilitaryToken() // constructor used just to set active to true..for now
	{
		mActive = true;
	}

	void MilitaryToken::constructorDebug()
	{
		cout << "Military Token created. " << endl << endl;
		system("pause");
	}

	void MilitaryToken::setStartingLocation(int xPosition, int yPosition) // need to figure out parameters to pass to set this correctly
	{
		mLocation[0] = xPosition;
		mLocation[1] = yPosition;
	}

	void MilitaryToken::doEffect(int player) // int player is used to define which player is affected (1 or 2)
	{

	}

	void MilitaryToken::removeFromGame()
	{
		mLocation[0] = 0;
		mLocation[1] = 0;
		mActive = false;
	}

}
