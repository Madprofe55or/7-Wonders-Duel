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

		int World::getAge()
		{
			return mAge;
		}

		void World::setAge(int age)
		{
			mAge = age;
		}

		/* Run when a player picks the build card option
		   The parameter passed in the cardpickerstate is the index of the card
		   on the board. The corresponding board pointer
		   is copied to the Player.playerCity vector and then the original board pointer
		   is set to nullptr.  Effects::doEffect() is run. World::exposeCards() is then run to update the 
		   exposed and faceup settings of each card on the board. Then the current player
		   is switched to the opposing player. */
		void World::buildCard(int clickedCardIndex)
		{
			currentPlayer->playerCity.push_back(board[clickedCardIndex]);

			Effects::doEffect(currentPlayer, board[clickedCardIndex]);

			board[clickedCardIndex] = nullptr;

			exposeCards();

			if (currentPlayer == &player1) currentPlayer = &player2;
			else if (currentPlayer == &player2) currentPlayer = &player1;
		}

		/* Run when a player picks the discard card option
		   The paramter passed inthe cardpickerstate is the index of the card
		   on the board. The corresponding board pointer
		   is copied to the World.discardDeck vector and then the original board pointer
		   is set to nullptr. Current player gold is updated by counting the number of 
		   yellow cards in Player.playerCity vector, then the current player is switched
		   to the opposing player. */
		void World::discardCard(int clickedCardIndex)
		{
			discardDeck.push_back(board[clickedCardIndex]);

			currentPlayer->setCoins(currentPlayer->getDiscardGoldValue());

			board[clickedCardIndex] = nullptr;

			exposeCards();

			if (currentPlayer == &player1) currentPlayer = &player2;
			else if (currentPlayer == &player2) currentPlayer = &player1;

		}

		/* Algorithm for updating cards' exposure and faceup settings
		   Run after each card is picked on each player's turn 
		   REFACTORING: Not all cards need their faceup value updated, but it's written as such, 
		   because some cards start faceup already. There are likely ways to 
		   combine some of these conditional statements. */
		void World::exposeCards()
		{
			if (mAge == 1)
			{

				for (int i = 0; i < 20; i++)
				{
					if ((i == 0 || i == 1) && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr && board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 2 || i == 3 || i == 4) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr && board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 5 || i == 6 || i == 7 || i == 8) && board[i] != nullptr)
					{
						if (board[i + 4] == nullptr && board[i + 5] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 9 || i == 10 || i == 11 || i == 12 || i == 13) && board[i] != nullptr)
					{
						if (board[i + 5] == nullptr && board[i + 6] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}

				}
			}

			if (mAge == 2)
			{
				for (int i = 0; i < 20; i++)
				{

					if (i == 0 && board[i] != nullptr)
					{
						if (board[i + 6] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 1 || i == 2 || i == 3 || i ==4) && board[i] != nullptr)
					{
						if (board[i + 5] == nullptr && board[i + 6] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 5 && board[i] != nullptr)
					{
						if (board[i + 5] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 6 && board[i] != nullptr)
					{
						if (board[i + 5] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 7 || i == 8 || i == 9) && board[i] != nullptr)
					{
						if (board[i + 4] == nullptr && board[i + 5] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 10 && board[i] != nullptr)
					{
						if (board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 11 && board[i] != nullptr)
					{
						if (board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 12 || i == 13) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr && board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 14 && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 15 && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 16 && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr && board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if (i == 17 && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
				}
			}

			if (mAge == 3)
			{
				for (int i = 0; i < 20; i++)
				{
					if ((i == 0 || i == 1) && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr && board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 2 || i == 3 || i == 4) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr && board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 5 || i == 6) && board[i] != nullptr)
					{
						if (board[9] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 7 || i == 8) && board[i] != nullptr)
					{
						if (board[10] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 9) && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr && board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 10) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr && board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 11) && board[i] != nullptr)
					{
						if (board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 12 || i == 13) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr && board[i + 4] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 14) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 15) && board[i] != nullptr)
					{
						if (board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 16) && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr && board[i + 3] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
					if ((i == 17) && board[i] != nullptr)
					{
						if (board[i + 2] == nullptr)
						{
							board[i]->setFaceup(true);
							board[i]->setExposed(true);
						}
					}
				}

			}
		}

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

		for (int i = 0; i < 5; i++)
		{
			progressTokenDeck.pop_back();
		}
		// End progress token deck, shuffling, and selection

		// Wonder deck and shuffling
		//Choose Eight Wonder Cards from Deck to be chosen by player 1 and player 2
		//fill wonder deck (vector) with wonder cards
		wonderCardDeck.push_back(cardTheAppianWay);
		wonderCardDeck.push_back(cardCircusMaximus);
		wonderCardDeck.push_back(cardTheColossus);
		wonderCardDeck.push_back(cardTheGreatLibrary);
		wonderCardDeck.push_back(cardTheGreatLighthouse);
		wonderCardDeck.push_back(cardTheHangingGardens);
		wonderCardDeck.push_back(cardTheMausoleum);
		wonderCardDeck.push_back(cardThePyramids);
		wonderCardDeck.push_back(cardPiraeus);
		wonderCardDeck.push_back(cardTheSphinx);
		wonderCardDeck.push_back(cardTheStatueOfZeus);
		wonderCardDeck.push_back(cardTheTempleOfArtemis);

		srand((unsigned)time(NULL));
		random_shuffle(wonderCardDeck.begin(), wonderCardDeck.end());

		for (int i = 0; i < 8; i++)
		{
			wonderCardDeck.pop_back();
			//pop back to delete the wonders that have already 
			//been chosen to remove from deck
		}
		// End Wonder Card Deck, shuffling, and selection


		// Age1 Deck and shuffling
		//Remove three cards from Age 1 Deck and then move cards to correct location on board
		//fill age 1 deck (vector) with all age 1 cards
		age1Deck.push_back(cardLumberYard);
		age1Deck.push_back(cardLoggingCamp);
		age1Deck.push_back(cardClayPool);
		age1Deck.push_back(cardClayPit);
		age1Deck.push_back(cardQuarry);
		age1Deck.push_back(cardStonePit);
		age1Deck.push_back(cardGlassworks);
		age1Deck.push_back(cardPress);
		age1Deck.push_back(cardGuardTower);
		age1Deck.push_back(cardWorkshop);
		age1Deck.push_back(cardApothecary);
		age1Deck.push_back(cardStoneReserve);
		age1Deck.push_back(cardClayReserve);
		age1Deck.push_back(cardWoodReserve);
		age1Deck.push_back(cardStable);
		age1Deck.push_back(cardGarrison);
		age1Deck.push_back(cardPalisade);
		age1Deck.push_back(cardScriptorium);
		age1Deck.push_back(cardPharmacist);
		age1Deck.push_back(cardTheater);
		age1Deck.push_back(cardAltar);
		age1Deck.push_back(cardBaths);
		age1Deck.push_back(cardTavern);
		
		srand((unsigned)time(NULL));
		random_shuffle(age1Deck.begin(), age1Deck.end());

		for (int i = 0; i < 3; i++)
		{
			age1Deck.pop_back();
		}
		for (int i = 0; i < 20; i++)
		{
			age1Deck[i].setPosition(AGE_1_POSITIONS[i]);
			if (i == 2 || i == 3 || i == 4 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13)
			{
				age1Deck[i].setFaceup(false);
				age1Deck[i].setExposed(false);
			}

			if (i != 14 && i != 15 && i != 16 && i != 17 && i != 18 && i != 19)
			{
				age1Deck[i].setExposed(false);
			}

		}
		// end age1 card deck, shuffling, and selection


		// Age2 Deck and shuffling
		//Remove three cards from Age 2 Deck and then move cards to correct location on board
		//Need to move these to a location for players hand and out of deck
		//fill age 1 deck (vector) with all age 2 cards
		age2Deck.push_back(cardSawmill);
		age2Deck.push_back(cardBrickyard);
		age2Deck.push_back(cardShelfQuarry);
		age2Deck.push_back(cardGlassBlower);
		age2Deck.push_back(cardDryingRoom);
		age2Deck.push_back(cardWalls);
		age2Deck.push_back(cardForum);
		age2Deck.push_back(cardCaravansery);
		age2Deck.push_back(cardCustomsHouse);
		age2Deck.push_back(cardTribunal);
		age2Deck.push_back(cardHorseBreeders);
		age2Deck.push_back(cardBarracks);
		age2Deck.push_back(cardArcheryRange);
		age2Deck.push_back(cardParadeGround);
		age2Deck.push_back(cardLibrary);
		age2Deck.push_back(cardDispensary);
		age2Deck.push_back(cardSchool);
		age2Deck.push_back(cardLaboratory);
		age2Deck.push_back(cardStatue);
		age2Deck.push_back(cardTemple);
		age2Deck.push_back(cardAqueduct);
		age2Deck.push_back(cardRostrum);
		age2Deck.push_back(cardBrewery);
		
		srand((unsigned)time(NULL));
		random_shuffle(age2Deck.begin(), age2Deck.end());

		for (int i = 0; i < 3; i++)
		{
			age2Deck.pop_back();
		}
		for (int i = 0; i < 20; i++)
		{
			age2Deck[i].setPosition(AGE_2_POSITIONS[i]);
			if (i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 15 || i == 16 || i == 17)
			{
				age2Deck[i].setFaceup(false);
				age2Deck[i].setExposed(false);
			}

			if (i != 18 && i != 19)
			{
				age2Deck[i].setExposed(false);
			}
		}
		// end age2 card deck, shuffling, and selection


		// Age3 Deck and shuffling
		//Remove three cards from Age 3 Deck and then move cards to correct location on board
		//fill age 3 deck (vector) with all age 2 cards
		age3Deck.push_back(cardArsenal);
		age3Deck.push_back(cardCourthouse);
		age3Deck.push_back(cardAcademy);
		age3Deck.push_back(cardStudy);
		age3Deck.push_back(cardChamberOfCommerce);
		age3Deck.push_back(cardPort);
		age3Deck.push_back(cardArmory);
		age3Deck.push_back(cardPalace);
		age3Deck.push_back(cardTownHall);
		age3Deck.push_back(cardObelisk);
		age3Deck.push_back(cardFortifications);
		age3Deck.push_back(cardSiegeWorkshop);
		age3Deck.push_back(cardCircus);
		age3Deck.push_back(cardUniversity);
		age3Deck.push_back(cardObservatory);
		age3Deck.push_back(cardGardens);
		age3Deck.push_back(cardPantheon);
		age3Deck.push_back(cardSenate);
		age3Deck.push_back(cardLighthouse);
		age3Deck.push_back(cardArena);
		// end age3 card deck, shuffling, and selection
		
		// Guild deck and shuffling
		//create Guild Deck and remove three cards to add to Age 3 deck
		guildDeck.push_back(cardMerchantsGuild);    //will need to seperate the guilds deck
		guildDeck.push_back(cardShipownersGuild);
		guildDeck.push_back(cardBuildersGuild);
		guildDeck.push_back(cardMagistratesGuild);
		guildDeck.push_back(cardMoneylendersGuild);
		guildDeck.push_back(cardTacticiansGuild);
		guildDeck.push_back(cardScientistsGuild);

		//shuffle age 3 deck
		srand((unsigned)time(NULL));
		random_shuffle(age3Deck.begin(), age3Deck.end());

		for (int i = 0; i < 3; i++) //show that cards were succesfully removed from age 3 deck to create room for the three guild cards
		{
			age3Deck.pop_back();
		}

		//shuffle guild deck
		srand((unsigned)time(NULL));
		random_shuffle(guildDeck.begin(), guildDeck.end());

		for (int i = 0; i < 3; i++) //show the guild deck cards added to Age 3 deck
		{
			age3Deck.push_back(guildDeck.back()); //add three guild cards to age 3 final deck
			guildDeck.pop_back();
		}

		//reshuffle age 3 deck
		srand((unsigned)time(NULL));
		random_shuffle(age3Deck.begin(), age3Deck.end());

		// setting positions and starting faceup and exposed properties
		for (int i = 0; i < 20; i++)
		{
			age3Deck[i].setPosition(AGE_3_POSITIONS[i]);
			if (i == 2 || i == 3 || i == 4 || i == 9 || i == 10 || i == 15 || i == 16 || i == 17)
			{
				age3Deck[i].setFaceup(false);
				age3Deck[i].setExposed(false);
			}

			if (i != 18 && i != 19)
			{
				age3Deck[i].setExposed(false);
			}
		}

		// setting up board pointer array
		for (int i = 0; i < 20; i++)
		{
			board[i] = &age1Deck[i];
		}

		currentPlayer = &player1;
	}

	void World::ExitGame()
	{
		age1Deck.clear();
		age2Deck.clear();
		age3Deck.clear();
		guildDeck.clear();
		discardDeck.clear();
		wonderCardDeck.clear();
		player1.playerCity.clear();
		player1.resetResources();
		player2.playerCity.clear();
		player2.resetResources();
		for (int i = 0; i < 20; i++) board[i] = nullptr;
		mAge = 1;
	}

	bool World::checkForNewAge()
	{
		int emptyCount = 0;
		for (int i = 0; i < 20; i++)
		{
			if (board[i] == nullptr) emptyCount++;
		}
		if (emptyCount == 20)
		{
			if (mAge == 1)
			{
				for (int i = 0; i < 20; i++)
				{

					board[i] = &age2Deck[i];
				}
				mAge = 2;
				return true;
			}
			else if (mAge == 2)
			{
				for (int i = 0; i < 20; i++)
				{
					board[i] = &age3Deck[i];
				}
				mAge = 3;
				return true;
			}
			else if (mAge == 3)
			{
				runCivilianVictory();
			}
		}
		else return false;
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

	void World::runCivilianVictory()
	{
	}

}



