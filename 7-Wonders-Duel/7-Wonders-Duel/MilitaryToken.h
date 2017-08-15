// 7 Wonders Duel
// Military Token class header

#ifndef MILITARYTOKEN_H
#define MILITARYTOKEN_H

#include <vector>
#include "Game_Constants.h"
namespace Seven_Wonders {

	class MilitaryToken
	{
	public:
		MilitaryToken();
		void constructorDebug();
		void doEffect(int playerNumber);

	private:
		std::vector <float> mPosition = START_POSITION; //this needs to be an x, y position in the game
		bool mActive; //this will be used to determine if it's still on the game board or not

	};

}

#endif // MILITARYTOKEN_H
