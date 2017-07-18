// 7 Wonders Duel
// Effects class definitions

#include "Effects.h"

Effects::Effects() {}
Effects::~Effects() {}


void Effects::lumberYard(Player & currentPlayer)
{
	currentPlayer.setWood(1);
}

void Effects::loggingCamp(Player & currentPlayer)
{
	currentPlayer.setWood(1);
}

void Effects::clayPool(Player & currentPlayer)
{
	currentPlayer.setClay(1);
}

void Effects::clayPit(Player & currentPlayer)
{
	currentPlayer.setClay(1);
}

void Effects::quarry(Player & currentPlayer)
{
	currentPlayer.setStone(1);
}

void Effects::stonePit(Player & currentPlayer)
{
	currentPlayer.setStone(1);
}

void Effects::glassworks(Player & currentPlayer)
{
	currentPlayer.setGlass(1);
}

void Effects::press(Player & currentPlayer)
{
	currentPlayer.setPapyrus(1);
}

void Effects::guardTower(Player & currentPlayer)
{
	if (currentPlayer.getPlayerNumber == PLAYER_1) { }
	else if (currentPlayer.getPlayerNumber == PLAYER_2) { }
}

