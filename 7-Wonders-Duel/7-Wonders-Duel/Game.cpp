// 7 Wonders Duel 
// Game class functions

#include "Game.h"
#include "DecksCreator.h"
#include <algorithm>
#include <vector>
#include <stdarg.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

Game::Game()
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

{
	cout << "exit Game constructor" << endl << endl;
	system("pause");
}

void Game::Run()
{
	cout << "Starting Game::Run()" << endl << endl;
	system("pause");
	Setup();
	gameLoop();
	Shutdown();
	cout << "Exiting Game::Run()" << endl << endl;
}

void Game::Setup()
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

void Game::gameLoop()
{
	
}

void Game::Shutdown()
{

}

