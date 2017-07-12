// 7 Wonders Duel
// Conflict Pawn class header

#pragma once
#ifndef CONFLICTPAWN_H
#define CONFLICTPAWN_H
#include <string>
using namespace std;

class ConflictPawn
{
public:
	ConflictPawn();
	void constructorDebug();
	string getName();
	void setName(string name);
	int* getLocation();
	void setLocation(int xPosition, int yPosition);
	void movePawn(int moveAmount);
	void doEffect();
	
private:
	string mName; // pretty much for debugging
	int mLocation[2];
	const int STARTING_LOCATION = 0;
	
};

#endif // CONFLICTPAWN_H
