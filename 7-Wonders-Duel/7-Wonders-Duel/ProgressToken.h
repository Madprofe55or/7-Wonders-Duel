// 7 Wonders Duel
// Progress Token class header

#pragma once
#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H
#include <string>
using namespace std;

class ProgressToken
{
public:
	ProgressToken(int indexNumber);
	void constructorDebug();
	string getName();
	void setName(int indexNumber);
	int* getLocation();
	void setLocation(int xLocation, int yLocation);
	void doEffect();

private:
	string mName;
	bool mInThisGame;
	int mOwner;
	int mLocation[2];
	string progressTokenNames[10] = { "Agriculture",
									  "Architecture",
									  "Economy",
									  "Law",
									  "Masonry",
									  "Mathematics",
									  "Philosphy",
									  "Strategy",
									  "Theology",
									  "Urbanism" };
};

#endif // PROGRESSTOKEN_H
