// 7 Wonders Duel
// Military Token class header

#pragma once
#ifndef MILITARYTOKEN_H
#define MILITARYTOKEN_H

class MilitaryToken
{
public:
	MilitaryToken();
	void constructorDebug();
	void setStartingLocation(int xPosition, int yPosition);
	void doEffect(int playerNumber);
	void removeFromGame();

private:
	int mLocation[2]; //this needs to be an x, y position in the game
	bool mActive; //this will be used to determine if it's still on the game board or not

};

#endif // MILITARYTOKEN_H
