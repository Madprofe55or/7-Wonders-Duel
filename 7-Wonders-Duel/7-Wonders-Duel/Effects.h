// 7 Wonders Duel
// Effects class header

#pragma once
#ifndef EFFECTS_H
#define EFFECTS_H
#include "Player.h"

class Effects
{
public:
	Effects();
	~Effects();

	void lumberYard(Player & currentPlayer);
	void loggingCamp(Player & currentPlayer);
	void clayPool(Player & currentPlayer);
	void clayPit(Player & currentPlayer);
	void quarry(Player & currentPlayer);
	void stonePit(Player & currentPlayer);
	void glassworks(Player & currentPlayer);
	void press(Player & currentPlayer);
	void guardTower(Player & currentPlayer);
	void workshop();
	void apothecary();
	void stoneReserve();
	void clayReserve();
	void woodReserve();
	void stable();
	void garrison();
	void palisade();




};

#endif // EFFECTS_H

