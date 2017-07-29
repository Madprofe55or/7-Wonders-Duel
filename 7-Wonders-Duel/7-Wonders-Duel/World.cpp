// 7 Wonders Duel 
// World class functions

#include "World.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
using namespace Seven_Wonders;

namespace Seven_Wonders {

	World::World()
		:
		player1(1), player2(2),
		conflictPawn(),
		militaryTokenP12(),
		militaryTokenP15(),
		militaryTokenP22(),
		militaryTokenP25(),
		progressTokenAgriculture(0),
		progressTokenArchitecture(1),
		progressTokenEconomy(2),
		progressTokenLaw(3),
		progressTokenMasonry(4),
		progressTokenMathematics(5),
		progressTokenPhilosophy(6),
		progressTokenStrategy(7),
		progressTokenTheology(8),
		progressTokenUrbanism(9),
		cardLumberYard(0),
		cardLoggingCamp(1),
		cardClayPool(2),
		cardClayPit(3),
		cardQuarry(4),
		cardStonePit(5),
		cardGlassworks(6),
		cardPress(7),
		cardGuardTower(8),
		cardWorkshop(9),
		cardApothecary(10),
		cardStoneReserve(11),
		cardClayReserve(12),
		cardWoodReserve(13),
		cardStable(14),
		cardGarrison(15),
		cardPalisade(16),
		cardScriptorium(17),
		cardPharmacist(18),
		cardTheater(19),
		cardAltar(20),
		cardBaths(21),
		cardTavern(22),
		cardSawmill(23),
		cardBrickyard(24),
		cardShelfQuarry(25),
		cardGlassBlower(26),
		cardDryingRoom(27),
		cardWalls(28),
		cardForum(29),
		cardCaravansery(30),
		cardCustomsHouse(31),
		cardTribunal(32),
		cardHorseBreeders(33),
		cardBarracks(34),
		cardArcheryRange(35),
		cardParadeGround(36),
		cardLibrary(37),
		cardDispensary(38),
		cardSchool(39),
		cardLaboratory(40),
		cardStatue(41),
		cardTemple(42),
		cardAqueduct(43),
		cardRostrum(44),
		cardBrewery(45),
		cardArsenal(46),
		cardCourthouse(47),
		cardAcademy(48),
		cardStudy(49),
		cardChamberOfCommerce(50),
		cardPort(51),
		cardArmory(52),
		cardPalace(53),
		cardTownHall(54),
		cardObelisk(55),
		cardFortifications(56),
		cardSiegeWorkshop(57),
		cardCircus(58),
		cardUniversity(59),
		cardObservatory(60),
		cardGardens(61),
		cardPantheon(62),
		cardSenate(63),
		cardLighthouse(64),
		cardArena(65),
		cardMerchantsGuild(66),
		cardShipownersGuild(67),
		cardBuildersGuild(68),
		cardMagistratesGuild(69),
		cardScientistsGuild(70),
		cardMoneylendersGuild(71),
		cardTacticiansGuild(72),
		cardTheAppianWay(73),
		cardCircusMaximus(74),
		cardTheColossus(75),
		cardTheGreatLibrary(76),
		cardTheGreatLighthouse(77),
		cardTheHangingGardens(78),
		cardTheMausoleum(79),
		cardPiraeus(80),
		cardThePyramids(81),
		cardTheSphinx(82),
		cardTheStatueOfZeus(83),
		cardTheTempleOfArtemis(84)
	{}

	void World::Setup()
	{
		// 1. Create vectors for Wonders, Progress Tokens, Age 1, Age 2, Age 3, Guilds -- and shuffle
		//       a.  Age 1 and 2 have 3 cards removed
		//       b.  Guild deck has 3 cards moved to Age 3 deck
		// 2. Pick first 5 Progress Token and setOwner to Board and location to somewhere on visual game board, others moved off-board, keep vector
		// 3. Show first 4 wonders, player 1 picks 1, player 2 picks 2, then player 1 gets last one
		// 4. Show next 4 wonders, player 2 picks 1, player 1 picks 2, then player 2 gets last one, discard remaining 4, destroy the vector
		// 5. Deal Age 1 cards


		// Progress token deck and shuffling
		vector <ProgressToken> progressTokenDeck;
		progressTokenDeck.push_back(progressTokenAgriculture);
		progressTokenDeck.push_back(progressTokenArchitecture);
		progressTokenDeck.push_back(progressTokenEconomy);
		progressTokenDeck.push_back(progressTokenLaw);
		progressTokenDeck.push_back(progressTokenMasonry);
		progressTokenDeck.push_back(progressTokenMathematics);
		progressTokenDeck.push_back(progressTokenPhilosophy);
		progressTokenDeck.push_back(progressTokenStrategy);
		progressTokenDeck.push_back(progressTokenTheology);
		progressTokenDeck.push_back(progressTokenUrbanism);

		srand((unsigned)time(NULL));
		random_shuffle(progressTokenDeck.begin(), progressTokenDeck.end());

		for (int i = 0; i < 10; i++)
		{
			cout << "Progress Token: " << progressTokenDeck[i].getName() << endl;
			system("pause");
		}
		for (int i = 0; i < 5; i++)
		{
			cout << "Dealt: " << progressTokenDeck.back().getName() << endl;
			progressTokenDeck.pop_back();
		}
		for (int i = 0; i < 5; i++)
		{
			cout << "Remaining: " << progressTokenDeck[i].getName() << endl;
		}

		// End progress token deck, shuffling, and selection

	}

	void World::gameLoop()
	{
		// 1. After setup is complete this will run the main game loop
		// 2. It starts with whoever was decided to be the first player
		// 3. At each turn, a player has three choices:
		//		a. Build an available card, if the player has the needed resources.
		//		b. Discard an available card for coins.
		//		c. Use an available card for building a wonder, if the player has the needed resources.
		// 4. After each choice is made, the following will happen:
		//		a. A check will be made for an immeidate effect. If true, then that effect will take place.
		//		b. A check will be made for an immediate victory condition (military, science).
		//		b. Player resources/attributes/etc will be updated.
		// 5. The turn will then pass to the next player, unless the effect was to repeat a turn (some Wonders do this).
		// 6. Steps 3-5 are repeated, alternating players, until the last card is used.
		// 7. If it's the end of Age 1 or 2, then cards will be dealt for the next age, from the appropriate vector.
		// 8. If it's the end of Age 3, and no immediate victory condition was met when the last card was played, the scores will be added up and a winner announced.
		// 9. Player will be asked for another game.

		cout << "Starting main loop..." << endl;
		system("pause");

		if (player1.getGoesFirst() == true) currentPlayer = &player1;
		else if (player2.getGoesFirst() == true)  currentPlayer = &player2;

		// get player input, determine the card that was clicked on based on location of click
		// Card * cardToDisplay = getCardAtLocation(mouseclick);
		// displayCard(cardToDisplay);



	}

	void World::Shutdown()
	{

	}

	void World::displayCard(Card & cardToDisplay)
	{
		// code to change state to zoomed card display and show all important parts of this (to be designed later)
		// selectedCard
	}

	bool World::checkForScienceVictory(Player & currentPlayer)
	{
		int numOfUniqueSymbols = 0;
		if (currentPlayer.getNumOfScienceSymbols("Arch") > 0) numOfUniqueSymbols++;
		if (currentPlayer.getNumOfScienceSymbols("Wheel") > 0) numOfUniqueSymbols++;
		if (currentPlayer.getNumOfScienceSymbols("Quill") > 0) numOfUniqueSymbols++;
		if (currentPlayer.getNumOfScienceSymbols("Mortar") > 0) numOfUniqueSymbols++;
		if (currentPlayer.getNumOfScienceSymbols("Balance") > 0) numOfUniqueSymbols++;
		if (currentPlayer.getNumOfScienceSymbols("Tablet") > 0) numOfUniqueSymbols++;
		if (currentPlayer.getNumOfScienceSymbols("Globe") > 0) numOfUniqueSymbols++;

		if (numOfUniqueSymbols >= 6) return true;
		else return false;
	}
	// need to pass currentPlayer.getPlayerNumber() to function
	int World::checkForMilitaryVictory(int playerNumber, ConflictPawn & conflictPawn)
	{
		if (playerNumber == PLAYER_1 && conflictPawn.getThreat() == 9) return PLAYER_1;
		else if (playerNumber == PLAYER_2 && conflictPawn.getThreat() == -9) return PLAYER_2;
		else return 0;
	}

}

