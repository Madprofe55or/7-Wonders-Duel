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

void ConflictPawn::movePawn(int moveAmount) // not sure how to do this movement quite  yet
{
	
}

void ConflictPawn::doEffect()
{

}
