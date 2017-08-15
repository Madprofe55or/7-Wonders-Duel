// 7 Wonders Duel
// Progress Token class header

#pragma once
#ifndef PROGRESSTOKEN_H
#define PROGRESSTOKEN_H
#include <string>
#include <vector>
#include "Game_Constants.h"
using namespace std;

namespace Seven_Wonders {

	class ProgressToken
	{
	public:
		ProgressToken(int indexNumber);
		string getName();
		void setName(int indexNumber);
		int getOwner();
		void setOwner(int playerNumber);
		void doEffect();

	private:
		string mName;
		bool mInThisGame;
		int mOwner;
		std::vector<float> mPosition = START_POSITION;
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

}

#endif // PROGRESSTOKEN_H
