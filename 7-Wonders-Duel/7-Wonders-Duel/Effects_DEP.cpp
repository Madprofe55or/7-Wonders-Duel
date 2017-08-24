//// 7 Wonders Duel
//// Effects class definitions
//
//// Should we use these functions to also increase victory points for each player??  
//// Or just wait until the end to add them all up??
//
//#include "Effects.h"
//using namespace Seven_Wonders;
//
//namespace Seven_Wonders {
//
//	Effects::Effects() {}
//	Effects::~Effects() {}
//
//	//void Effects::doEffect(World & world, Player & currentPlayer, Card & card)
//	//{
//	//	if (card.getType() == GREEN_CARD)
//	//	{
//	//		switch (card.getScienceSymbol())
//	//		{
//	//		case SCIENCE_SYMBOL_GLOBE:
//	//			currentPlayer.scienceSymbols.globe++;
//	//			break;
//	//		case SCIENCE_SYMBOL_TABLET:
//	//			currentPlayer.scienceSymbols.tablet++;
//	//			break;
//	//		case SCIENCE_SYMBOL_MORTAR:
//	//			currentPlayer.scienceSymbols.mortar++;
//	//			break;
//	//		case SCIENCE_SYMBOL_ARCH:
//	//			currentPlayer.scienceSymbols.arch++;
//	//			break;
//	//		case SCIENCE_SYMBOL_QUILL:
//	//			currentPlayer.scienceSymbols.quill++;
//	//			break;
//	//		case SCIENCE_SYMBOL_WHEEL:
//	//			currentPlayer.scienceSymbols.wheel++;
//	//			break;
//	//		}
//	//	}
//	//	else if (card.getType() == RED_CARD)
//	//	{
//	//		if (currentPlayer.getPlayerNumber() == PLAYER_1)
//	//		{
//	//			world.mConflict += (card.getShields() + ((currentPlayer.flags.strategyPTFlag) ? (1) : (0)));
//	//		}
//	//		else if (currentPlayer.getPlayerNumber() == PLAYER_2)
//	//		{
//	//			world.mConflict -= (card.getShields() + ((currentPlayer.flags.strategyPTFlag) ? (1) : (0)));
//	//		}
//	//	}
//	//	else if (card.getType() == BLUE_CARD)
//	//	{
//	//		// do stuff //
//	//	}
//	//	else if (card.getType() == BROWN_CARD)
//	//	{
//	//		switch (card.getIndex()) 
//	//		{
//	//		case 0: // lumber yard
//	//			currentPlayer.setWood(1);
//	//			break;
//	//		case 1: // logging camp
//	//			currentPlayer.setWood(1);
//	//			break;
//	//		case 2: // clay pool
//	//			currentPlayer.setClay(1);
//	//			break;
//	//		case 3: // clay pit
//	//			currentPlayer.setClay(1);
//	//			break;
//	//		case 4: // quarry
//	//			currentPlayer.setStone(1);
//	//			break;
//	//		case 5: // stone pit
//	//			currentPlayer.setStone(1);
//	//			break;
//	//		case 23: // saw mill
//	//			currentPlayer.setWood(2);
//	//			break;
//	//		case 24: // brickyard
//	//			currentPlayer.setClay(2);
//	//			break;
//	//		case 25: // shelf quarry
//	//			currentPlayer.setStone(2);
//	//			break;
//	//		}
//	//	}
//	//	else if (card.getType() == GRAY_CARD)
//	//	{
//	//		switch (card.getIndex())
//	//		{
//	//		case 6: // glassworks
//	//			currentPlayer.setGlass(1);
//	//			break;
//	//		case 7: // press
//	//			currentPlayer.setPapyrus(1);
//	//			break;
//	//		case 26: // glassblower
//	//			currentPlayer.setGlass(1);
//	//			break;
//	//		case 27: // drying room
//	//			currentPlayer.setPapyrus(1);
//	//			break;
//	//		}
//	//	}
//	//	else if (card.getType() == YELLOW_CARD)
//	//	{
//
//	//	}
//	//	else if (card.getType() == WONDER_CARD)
//	//	{
//
//	//	}
//	//}
//
//	
//	
//	
//	// Age 1 Cards
//	void Effects::lumberYard(Player * currentPlayer)
//	{
//		currentPlayer->setWood(1);
//	}
//	void Effects::loggingCamp(Player & currentPlayer)
//	{
//		currentPlayer.setWood(1);
//	}
//	void Effects::clayPool(Player & currentPlayer)
//	{
//		currentPlayer.setClay(1);
//	}
//	void Effects::clayPit(Player & currentPlayer)
//	{
//		currentPlayer.setClay(1);
//	}
//	void Effects::quarry(Player & currentPlayer)
//	{
//		currentPlayer.setStone(1);
//	}
//	void Effects::stonePit(Player & currentPlayer)
//	{
//		currentPlayer.setStone(1);
//	}
//	void Effects::glassworks(Player & currentPlayer)
//	{
//		currentPlayer.setGlass(1);
//	}
//	void Effects::press(Player & currentPlayer)
//	{
//		currentPlayer.setPapyrus(1);
//	}
//	void Effects::guardTower(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::stoneReserve(Player & currentPlayer)
//	{
//
//	}
//	void Effects::clayReserve(Player & currentPlayer)
//	{
//
//	}
//	void Effects::woodReserve(Player & currentPlayer)
//	{
//
//	}
//	void Effects::stable(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//	void Effects::garrison(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//	void Effects::palisade(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//	void Effects::scriptorium(Player & currentPlayer)
//	{
//
//	}
//	void Effects::pharmacist(Player & currentPlayer)
//	{
//
//	}
//	void Effects::theater(Player & currentPlayer)
//	{
//		// no effect
//	}
//	void Effects::altar(Player & currentPlayer)
//	{
//		// no effect
//	}
//	void Effects::baths(Player & currentPlayer)
//	{
//		// no effect
//	}
//	void Effects::tavern(Player & currentPlayer)
//	{
//		currentPlayer.setCoins(4);
//	}
//
//	// Age 2 Cards
//	void Effects::sawmill(Player & currentPlayer)
//	{
//		currentPlayer.setWood(2);
//	}
//	void Effects::brickyard(Player & currentPlayer)
//	{
//		currentPlayer.setClay(2);
//	}
//	void Effects::shelfQuarry(Player & currentPlayer)
//	{
//		currentPlayer.setStone(2);
//	}
//	void Effects::glassBlower(Player & currentPlayer)
//	{
//		currentPlayer.setGlass(1);
//	}
//	void Effects::dryingRoom(Player & currentPlayer)
//	{
//		currentPlayer.setPapyrus(1);
//	}
//	void Effects::walls(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//	void Effects::forum(Player & currentPlayer)
//	{
//		// need to figure out how to flag decision-based resources from yellow cards
//	}
//	void Effects::caravansery(Player & currentPlayer)
//	{
//		// need to figure out how to flag decision-based resources from yellow cards
//	}
//	void Effects::customsHouse(Player & currentPlayer)
//	{
//
//	}
//	void Effects::tribunal(Player & currentPlayer)
//	{
//
//	}
//
//	void Effects::horseBreeders(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::barracks(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::archeryRange(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::paradeGround(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::statue(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::temple(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::aqueduct(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::rostrum(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::brewery(Player & currentPlayer)
//	{
//		currentPlayer.setCoins(6);
//	}
//
//
//	// Age 3 Cards
//	void Effects::arsenal(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::courthouse(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::chamberOfCommerce(Player & currentPlayer)
//	{
//		// count number of gray cards in player's possession
//		// adjust player coins by that number x3
//	}
//
//	void Effects::port(Player & currentPlayer)
//	{
//		// count number of brown cards in player's possession
//		// adjust player coins by that number x2
//	}
//
//	void Effects::armory(Player & currentPlayer)
//	{
//		// count number of red cards in player's possession
//		// adjust player coins by that number x1
//	}
//
//	void Effects::palace(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::townHall(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::obelisk(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::fortifications(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::siegeWorkshop(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::circus(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::gardens(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::pantheon(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::senate(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::lighthouse(Player & currentPlayer)
//	{
//		// count number of yellow cards in player's possession, including this one
//		// adjust player coins by that amount x1
//	}
//
//	void Effects::arena(Player & currentPlayer)
//	{
//		// count number of wonders in player's possession
//		// adjust player coins by that amuont x2
//	}
//
//	void Effects::merchantsGuild(Player & currentPlayer)
//	{
//		// count number of yellow cards in EACH player's city
//		// determine which is greater
//		// adjust player coins by that amount x1
//	}
//
//	void Effects::shipownersGuild(Player & currentPlayer)
//	{
//		// count number of brown and gray cards in EACH player's city
//		// determine which is greater
//		// adjust player coins by that amount x1
//	}
//
//	void Effects::buildersGuild(Player & currentPlayer)
//	{
//		// count number of wonders in EACH player's city
//		// determine which is greater
//		// adjust player coins by that amount x2
//	}
//
//	void Effects::magistratesGuild(Player & currentPlayer)
//	{
//		// count number of blue cards in EACH player's city
//		// determine which is greater
//		// adjust player coins by that amount x1
//	}
//
//	void Effects::scientistsGuild(Player & currentPlayer)
//	{
//		// count number of green cards in EACH player's city
//		// determine which is greater
//		// adjust player coins by that amount x1
//	}
//
//	void Effects::moneylendersGuild(Player & currentPlayer)
//	{
//		// no effect
//	}
//
//	void Effects::tacticiansGuild(Player & currentPlayer)
//	{
//		// count number of red cards in EACH player's city
//		// determine which is greater
//		// adjust player coins by that amount x1
//	}
//
//	// Wonders
//	void Effects::theAppianWay(Player & currentPlayer, Player & opposingPlayer)
//	{
//		currentPlayer.setCoins(3);
//		opposingPlayer.setCoins(-3);
//		// need to handle how to flag current player for a second turn
//	}
//
//	void Effects::circusMaximus(Player & currentPlayer, Player & opposingPlayer)
//	{
//		// need to handle how to destroy opposing player's gray card (this will require current player input)
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::theColossus(Player & currentPlayer)
//	{
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::theGreatLibrary(Player & currentPlayer)
//	{
//		// show 3 random progress tokens that weren't played for this game
//		// have current player pick one
//		// play that and its effect
//	}
//
//	void Effects::theGreatLighthouse(Player & currentPlayer)
//	{
//		// need to figure out how to flag decision-based resources
//	}
//
//	void Effects::theHangingGardens(Player & currentPlayer)
//	{
//		currentPlayer.setCoins(6);
//		// need to handle how to flag current player for a second turn
//	}
//
//	void Effects::theMausoleum(Player & currentPlayer)
//	{
//		// show all cards that have been discarded throghout the game EXCEPT for cards that were discarded as part of setup
//		// have current player pick one
//		// play that and its effect
//	}
//
//	void Effects::piraeus(Player & currentPlayer)
//	{
//		// need to handle how to flag decision-based resources
//		// need to handle how to flag current player for a second turn
//	}
//
//	void Effects::thePyramids(Player & currentPlayer)
//	{
//		// no effect, worth 9 VP at end of game
//	}
//
//	void Effects::theSphinx(Player & currentPlayer)
//	{
//		// need to handle how to flag current player for a second turn
//	}
//
//	void Effects::theStatueOfZeus(Player & currentPlayer, Player & opposingPlayer)
//	{
//		// need to handle how to destroy opposing player's gray card (this will require current player input)
//		if (currentPlayer.getPlayerNumber() == PLAYER_1) {} // need to change position of conflictPawn
//		else if (currentPlayer.getPlayerNumber() == PLAYER_2) {} //  need to change position of conflictPawn
//	}
//
//	void Effects::theTempleOfArtemis(Player & currentPlayer)
//	{
//		currentPlayer.setCoins(12);
//	}
//
//
//	// Progress Tokens
//	void Effects::agriculture(Player & currentPlayer)
//	{
//		currentPlayer.setCoins(6);
//	}
//
//	void Effects::architecture(Player & currentPlayer)
//	{
//		// need to figure out how to flag for building wonders with two fewer resources
//	}
//
//	void Effects::economy(Player & currentPlayer)
//	{
//		// need to figure out how to flag for receiving opponent's coins when opponent spends coins for trading
//	}
//
//	void Effects::law(Player & currentPlayer)
//	{
//		
//	}
//
//	void Effects::masonry(Player & currentPlayer)
//	{
//		// need to figure out how to flag for building blue cards with two fewer resources
//	}
//
//	void Effects::mathematics(Player & currentPlayer)
//	{
//		// no effect, worth 3 VP for each progress token at the end of the game
//	}
//
//	void Effects::philosphy(Player & currentPlayer)
//	{
//		// no effect, wroth 7 VP
//	}
//
//	void Effects::strategy(Player & currentPlayer)
//	{
//		
//	}
//
//	void Effects::theology(Player & currentPlayer)
//	{
//		// need to figure out how to flag for current player getting a second turn when building EVERY wonder after this
//	}
//
//	void Effects::urbanism(Player & currentPlayer)
//	{
//		currentPlayer.setCoins(6);
//		// need to figure out how to flag for current player getting coins when building future cards through linking
//	}
//
//	void Effects::greenCardEffects(Player & currentPlayer, Card & greenCard)
//	{
//		//currentPlayer.setNumOfScienceSymbols(greenCard.getSymbol(), 1);
//	}
//
//	// Pass de-references to current player, the card being player, and the conflict pawn
//	void Effects::redCardEffects(Player & currentPlayer, Card & redCard, ConflictPawn & conflictPawn)
//	{
//
//	}
//
//}
//
