// 7 Wonders Duel
// Effects class header

#pragma once
#ifndef EFFECTS_H
#define EFFECTS_H
#include "Player.h"
#include "Card.h"
#include "ConflictPawn.h"

namespace Seven_Wonders {

	class Effects
	{
	public:
		Effects();
		~Effects();

		static void doEffect(Player * currentPlayer, Card * card);

		// Age 1 Cards
		static void lumberYard(Player * currentPlayer);
		static void loggingCamp(Player & currentPlayer);
		static void clayPool(Player & currentPlayer);
		static void clayPit(Player & currentPlayer);
		static void quarry(Player & currentPlayer);
		static void stonePit(Player & currentPlayer);
		static void glassworks(Player & currentPlayer);
		static void press(Player & currentPlayer);
		static void guardTower(Player & currentPlayer);
		static void workshop(Player & currentPlayer);
		static void apothecary(Player & currentPlayer);
		static void stoneReserve(Player & currentPlayer);
		static void clayReserve(Player & currentPlayer);
		static void woodReserve(Player & currentPlayer);
		static void stable(Player & currentPlayer);
		static void garrison(Player & currentPlayer);
		static void palisade(Player & currentPlayer);
		static void scriptorium(Player & currentPlayer);
		static void pharmacist(Player & currentPlayer);
		static void theater(Player & currentPlayer);
		static void altar(Player & currentPlayer);
		static void baths(Player & currentPlayer);
		static void tavern(Player & currentPlayer);

		// Age 2 Cards
		static void sawmill(Player & currentPlayer);
		static void brickyard(Player & currentPlayer);
		static void shelfQuarry(Player & currentPlayer);
		static void glassBlower(Player & currentPlayer);
		static void dryingRoom(Player & currentPlayer);
		static void walls(Player & currentPlayer);
		static void forum(Player & currentPlayer);
		static void caravansery(Player & currentPlayer);
		static void customsHouse(Player & currentPlayer);
		static void tribunal(Player & currentPlayer);
		static void horseBreeders(Player & currentPlayer);
		static void barracks(Player & currentPlayer);
		static void archeryRange(Player & currentPlayer);
		static void paradeGround(Player & currentPlayer);
		static void library(Player & currentPlayer);
		static void dispensary(Player & currentPlayer);
		static void school(Player & currentPlayer);
		static void laboratory(Player & currentPlayer);
		static void statue(Player & currentPlayer);
		static void temple(Player & currentPlayer);
		static void aqueduct(Player & currentPlayer);
		static void rostrum(Player & currentPlayer);
		static void brewery(Player & currentPlayer);

		// Age 3 Cards
		static void arsenal(Player & currentPlayer);
		static void courthouse(Player & currentPlayer);
		static void academy(Player & currentPlayer);
		static void study(Player & currentPlayer);
		static void chamberOfCommerce(Player & currentPlayer);
		static void port(Player & currentPlayer);
		static void armory(Player & currentPlayer);
		static void palace(Player & currentPlayer);
		static void townHall(Player & currentPlayer);
		static void obelisk(Player & currentPlayer);
		static void fortifications(Player & currentPlayer);
		static void siegeWorkshop(Player & currentPlayer);
		static void circus(Player & currentPlayer);
		static void university(Player & currentPlayer);
		static void observatory(Player & currentPlayer);
		static void gardens(Player & currentPlayer);
		static void pantheon(Player & currentPlayer);
		static void senate(Player & currentPlayer);
		static void lighthouse(Player & currentPlayer);
		static void arena(Player & currentPlayer);

		// Guild Cards
		static void merchantsGuild(Player & currentPlayer);
		static void shipownersGuild(Player & currentPlayer);
		static void buildersGuild(Player & currentPlayer);
		static void magistratesGuild(Player & currentPlayer);
		static void scientistsGuild(Player & currentPlayer);
		static void moneylendersGuild(Player & currentPlayer);
		static void tacticiansGuild(Player & currentPlayer);

		// Wonders
		static void theAppianWay(Player & currentPlayer, Player & opposingPlayer);
		static void circusMaximus(Player & currentPlayer, Player & opposingPlayer);
		static void theColossus(Player & currentPlayer);
		static void theGreatLibrary(Player & currentPlayer);
		static void theGreatLighthouse(Player & currentPlayer);
		static void theHangingGardens(Player & currentPlayer);
		static void theMausoleum(Player & currentPlayer);
		static void piraeus(Player & currentPlayer);
		static void thePyramids(Player & currentPlayer);
		static void theSphinx(Player & currentPlayer);
		static void theStatueOfZeus(Player & currentPlayer, Player & opposingPlayer);
		static void theTempleOfArtemis(Player & currentPlayer);

		// Progress Tokens
		static void agriculture(Player & currentPlayer);
		static void architecture(Player & currentPlayer);
		static void economy(Player & currentPlayer);
		static void law(Player & currentPlayer);
		static void masonry(Player & currentPlayer);
		static void mathematics(Player & currentPlayer);
		static void philosphy(Player & currentPlayer);
		static void strategy(Player & currentPlayer);
		static void theology(Player & currentPlayer);
		static void urbanism(Player & currentPlayer);

		static void greenCardEffects(Player & currentPlayer, Card &	greenCard);

		static void redCardEffects(Player & currentPlayer, Card & redCard, ConflictPawn & conflictPawn);

	};


}

#endif // EFFECTS_H

