// 7 Wonders Duel 
// Progress token class functions

#include "ProgressToken.h"
#include <stdarg.h>
#include <iostream>
using namespace std;

ProgressToken::ProgressToken(int indexNumber)
{
	setName(indexNumber);
	setLocation(0, 0);
	constructorDebug();
}

void ProgressToken::constructorDebug()
{
	string name = getName();
	int *location;
	location = getLocation();
	cout << "Created progress token, named " << name << ", at location " << location[0] << ", " << location[1] << "..." << endl << endl;
	system("pause");
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

int* ProgressToken::getLocation()
{
	return mLocation;
}

void ProgressToken::setLocation(int xPosition, int yPosition) 
{
	mLocation[0] = xPosition;
	mLocation[1] = yPosition;
}

void ProgressToken::doEffect() 
{

}
