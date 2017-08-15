// 7 Wonders Duel
// Conflict Pawn class header

#pragma once
#ifndef CONFLICTPAWN_H
#define CONFLICTPAWN_H
#include <string>
#include <vector>
#include "Game_Constants.h"
using namespace std;

namespace Seven_Wonders {

	class ConflictPawn
	{
	public:
		ConflictPawn();
		string getName();
		void setName(string name);
		int getThreat();
		void setThreat(int numOfShields, int direction);
		void doEffect();

	private:
		string mName; // pretty much for debugging
		std::vector<float> mPosition = START_POSITION;
		int mthreatLevel = 0;

	};

}

#endif // CONFLICTPAWN_H
