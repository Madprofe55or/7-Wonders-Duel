// 7 Wonders Duel
// Conflict Pawn class functions

#include "ConflictPawn.h"
#include <stdarg.h>
#include <iostream>

ConflictPawn::ConflictPawn()
{
	setLocation(0, 0);
	setName("Conflict Pawn");
	constructorDebug(); // display successful creation event
}

void ConflictPawn::constructorDebug()
{
	string name = getName();
	int *location;
	location = getLocation();
	cout << "Created conflict pawn, named " << name << ", at location " << location[0] << ", " << location[1] << "..." << endl << endl;
}

string ConflictPawn::getName()
{
	return mName;
}

void ConflictPawn::setName(string name)
{
	mName = name;
}

int* ConflictPawn::getLocation() 
{
	return mLocation;
}

void ConflictPawn::setLocation(int xPosition, int yPosition)
{
	mLocation[0] = xPosition;
	mLocation[1] = yPosition;
}

int ConflictPawn::getThreat()
{
	return mthreatLevel;
}

// numOfShields can be passed by the number of shields on the red card
// direction will be determined by currentplayer (+1 for player 1, -1 for player 2)
void ConflictPawn::setThreat(int numOfShields, int direction)
{
	mthreatLevel += (numOfShields * direction);
}


void ConflictPawn::doEffect()
{

}
