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
		Player * opposingPlayer;
		if (currentPlayer == &player1) opposingPlayer = &player2;
		else if (currentPlayer == &player2) opposingPlayer = &player1;
		
		if (buildFromDiscard == true)
		{
			int pos = 0;
			for (vector<Card*>::iterator it = discardDeck.begin(); it != discardDeck.end(); ++it)
			{
				if (clickedCardIndex == (*it)->getIndex())
				{
					currentPlayer->playerCity.push_back((*it));
					doEffect(*currentPlayer, (**it));
					(*it) = nullptr;
					discardDeck.erase(discardDeck.begin() + pos);
					buildFromDiscard = false;
					break;
				}
				pos++;
			}

		}
		else if (buildFromDiscard == false)
		{
			currentPlayer->playerCity.push_back(board[clickedCardIndex]);

			doEffect(*currentPlayer, *board[clickedCardIndex]);

			//if not linking used then drain resource of player to build card
			if (buildByLink == false)
			{
				// set building player's coins
				currentPlayer->setCoins(goldCost(*currentPlayer, *board[clickedCardIndex]));
				// set opposing player's coins if that player has the Economy PT
				bool economyFlag = false;
				if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
				{
					economyFlag = true;
				}
				else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
				{
					economyFlag = true;
				}
				else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
				{
					economyFlag = true;
				}
				else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
				{
					economyFlag = true;
				}
				else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
				{
					economyFlag = true;
				}

				if (economyFlag == true) opposingPlayer->setCoins(-1 * (goldCost(*currentPlayer, *board[clickedCardIndex]) - board[clickedCardIndex]->getCoinCost()));

			}

			//if build by linking is true then do not use any of players resources to build the card
			else if (buildByLink == true)
			{
				buildByLink = false;
			}

			board[clickedCardIndex] = nullptr;

			exposeCards();
		}

		if (!progressTokenState)
		{
			if (currentPlayer == &player1) currentPlayer = &player2;
			else if (currentPlayer == &player2) currentPlayer = &player1;
		}
	}

	void World::ChoosePlayer()
	{
		if (player1Chosen)
		{
			currentPlayer = &player1;
		}

		if (player2Chosen)
		{
			currentPlayer = &player2;
		}
	}

	void World::buildProgressToken(int progressTokenNumber)
	{
		if (buildPTFromDiscard == false)
		{
			if (currentPlayer == &player1)
			{
				if (player1CountPT == 0)
				{
					currentPlayer->playerPT1 = progressTokenDeck[progressTokenNumber];
				}

				if (player1CountPT == 1)
				{
					currentPlayer->playerPT2 = progressTokenDeck[progressTokenNumber];
				}

				if (player1CountPT == 2)
				{
					currentPlayer->playerPT3 = progressTokenDeck[progressTokenNumber];
				}

				if (player1CountPT == 3)
				{
					currentPlayer->playerPT4 = progressTokenDeck[progressTokenNumber];
				}

				if (player1CountPT == 4)
				{
					currentPlayer->playerPT5 = progressTokenDeck[progressTokenNumber];
				}

			}

			if (currentPlayer == &player2)
			{
				if (player2CountPT == 0)
				{
					currentPlayer->playerPT1 = progressTokenDeck[progressTokenNumber];
				}

				if (player2CountPT == 1)
				{
					currentPlayer->playerPT2 = progressTokenDeck[progressTokenNumber];
				}

				if (player2CountPT == 2)
				{
					currentPlayer->playerPT3 = progressTokenDeck[progressTokenNumber];
				}

				if (player2CountPT == 3)
				{
					currentPlayer->playerPT4 = progressTokenDeck[progressTokenNumber];
				}

				if (player2CountPT == 4)
				{
					currentPlayer->playerPT5 = progressTokenDeck[progressTokenNumber];
				}

			}

			doEffect(*currentPlayer, *progressTokenDeck[progressTokenNumber]);


			progressTokenDeck[progressTokenNumber] = nullptr;
		}
		else if (buildPTFromDiscard == true)
		{
			if (currentPlayer == &player1)
			{
				if (player1CountPT == 0)
				{
					currentPlayer->playerPT1 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player1CountPT == 1)
				{
					currentPlayer->playerPT2 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player1CountPT == 2)
				{
					currentPlayer->playerPT3 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player1CountPT == 3)
				{
					currentPlayer->playerPT4 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player1CountPT == 4)
				{
					currentPlayer->playerPT5 = progressTokenDiscardDeck[progressTokenNumber];
				}

			}

			if (currentPlayer == &player2)
			{
				if (player2CountPT == 0)
				{
					currentPlayer->playerPT1 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player2CountPT == 1)
				{
					currentPlayer->playerPT2 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player2CountPT == 2)
				{
					currentPlayer->playerPT3 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player2CountPT == 3)
				{
					currentPlayer->playerPT4 = progressTokenDiscardDeck[progressTokenNumber];
				}

				if (player2CountPT == 4)
				{
					currentPlayer->playerPT5 = progressTokenDiscardDeck[progressTokenNumber];
				}

			}

			doEffect(*currentPlayer, *progressTokenDiscardDeck[progressTokenNumber]);


			progressTokenDiscardDeck[progressTokenNumber] = nullptr;
			buildPTFromDiscard = false;
		}



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

	void World::buildWonder(int wonderNumber, int clickedCardIndex)
	{
		currentPlayer->playerWonderDeck[wonderNumber - 1]->builtWonder = true;

		Player * opposingPlayer;
		if (currentPlayer == &player1) opposingPlayer = &player2;
		else if (currentPlayer == &player2) opposingPlayer = &player1;

		//Take in the current Player, if the current player holds the Theology progress Token then return that is the current players turn. Else change turns to other player.
		if (currentPlayer->playerPT1 != nullptr && currentPlayer->playerPT1->getName() == "Theology")
		{
			repeatTurn = true;
		}
		if (currentPlayer->playerPT2 != nullptr && currentPlayer->playerPT2->getName() == "Theology")
		{
			repeatTurn = true;
		}
		if (currentPlayer->playerPT3 != nullptr && currentPlayer->playerPT3->getName() == "Theology")
		{
			repeatTurn = true;
		}
		if (currentPlayer->playerPT4 != nullptr && currentPlayer->playerPT4->getName() == "Theology")
		{
			repeatTurn = true;
		}
		if (currentPlayer->playerPT5 != nullptr && currentPlayer->playerPT5->getName() == "Theology")
		{
			repeatTurn = true;
		}

		currentPlayer->playerWonderDeck[wonderNumber - 1]->builtInAge = getAge();

		doEffect(*currentPlayer, *currentPlayer->playerWonderDeck[wonderNumber - 1]);

		// Coin changes for building player
		currentPlayer->setCoins(goldCost(*currentPlayer, *currentPlayer->playerWonderDeck[wonderNumber - 1]));
		// Coin changes for opposing player if they have the economy PT
		bool economyFlag = false;
		if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
		{
			economyFlag = true;
		}
		else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
		{
			economyFlag = true;
		}
		else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
		{
			economyFlag = true;
		}
		else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
		{
			economyFlag = true;
		}
		else if (opposingPlayer->playerPT1 != nullptr && opposingPlayer->playerPT1->getName() == "Economy")
		{
			economyFlag = true;
		}
		if (economyFlag == true) opposingPlayer->setCoins(-1 * (goldCost(*currentPlayer, *currentPlayer->playerWonderDeck[wonderNumber - 1]) - currentPlayer->playerWonderDeck[wonderNumber - 1]->getCoinCost()));

		board[clickedCardIndex] = nullptr;

		exposeCards();
		if (buildFromDiscard == false && buildPTFromDiscard == false)
		{
			if (currentPlayer == &player1 && repeatTurn == false) currentPlayer = &player2;
			else if (currentPlayer == &player2 && repeatTurn == false) currentPlayer = &player1;
			else if (repeatTurn == true) {} //  this won't change the currentplayer pointer so whoever built the card that flagged repeatTurn should get another turn
		}
		else if (buildFromDiscard == true || buildPTFromDiscard == true) {} // the player turn will be switched in another function

		if (repeatTurn == true) repeatTurn = false; // re-setting the repeatturn flag

		wonderCount++;
	}

	void World::destroyCard(int cardIndex, Player & targetplayer)
	{
		for (vector<Card*>::iterator it = targetplayer.playerCity.begin(); it != targetplayer.playerCity.end(); ++it)
		{
			if (cardIndex = (*it)->getIndex())
			{
				// adjusting player resources
				switch ((*it)->getIndex())
				{
				// brown cards
				case 0: // lumber yard
					targetplayer.setWood(-1);
					break;
				case 1: // logging camp
					targetplayer.setWood(-1);
					break;
				case 2: // clay pool
					targetplayer.setClay(-1);
					break;
				case 3: // clay pit
					targetplayer.setClay(-1);
					break;
				case 4: // quarry
					targetplayer.setStone(-1);
					break;
				case 5: // stone pit
					targetplayer.setStone(-1);
					break;
				case 23: // saw mill
					targetplayer.setWood(-2);
					break;
				case 24: // brickyard
					targetplayer.setClay(-2);
					break;
				case 25: // shelf quarry
					targetplayer.setStone(-2);
					break;
				// gray cards
				case 6: // glassworks
					targetplayer.setGlass(-1);
					break;
				case 7: // press
					targetplayer.setPapyrus(-1);
					break;
				case 26: // glassblower
					targetplayer.setGlass(-1);
					break;
				case 27: // drying room
					targetplayer.setPapyrus(-1);
					break;
				}
				// moving card to discard pile
				discardDeck.push_back((*it));
				targetplayer.playerCity.erase(it);
				break;
			}
		}
		if (destroyBrownCard) destroyBrownCard = false;
		if (destroyGrayCard) destroyGrayCard = false;
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
				if ((i == 1 || i == 2 || i == 3 || i == 4) && board[i] != nullptr)
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
		playAgain = false;
		bool player1MilitaryVictory = false;
		bool player2MilitaryVictory = false;

		bool player1ScienceVictory = false;
		bool player2ScienceVictory = false;

		bool player1CivilianVictory = false;
		bool player2CivlianVictory = false;
		// Progress token deck and shuffling
		progressTokenDeck.push_back(&progressTokenAgriculture);
		progressTokenDeck.push_back(&progressTokenArchitecture);
		progressTokenDeck.push_back(&progressTokenEconomy);
		progressTokenDeck.push_back(&progressTokenLaw);
		progressTokenDeck.push_back(&progressTokenMasonry);
		progressTokenDeck.push_back(&progressTokenMathematics);
		progressTokenDeck.push_back(&progressTokenPhilosophy);
		progressTokenDeck.push_back(&progressTokenStrategy);
		progressTokenDeck.push_back(&progressTokenTheology);
		progressTokenDeck.push_back(&progressTokenUrbanism);

		mConflict = 0;

		srand((unsigned)time(NULL));
		random_shuffle(progressTokenDeck.begin(), progressTokenDeck.end());

		for (int i = 9; i > 4; i--)
		{
			progressTokenDiscardDeck.push_back(progressTokenDeck[i]);
			progressTokenDeck.pop_back();
		}

		// End progress token deck, shuffling, and selection

		// Wonder deck and shuffling
		//Choose Eight Wonder Cards from Deck to be chosen by player 1 and player 2
		//fill wonder deck (vector) with wonder cards
		wonderCardDeck.push_back(&cardTheAppianWay);
		wonderCardDeck.push_back(&cardCircusMaximus);
		wonderCardDeck.push_back(&cardTheColossus);
		wonderCardDeck.push_back(&cardTheGreatLibrary);
		wonderCardDeck.push_back(&cardTheGreatLighthouse);
		wonderCardDeck.push_back(&cardTheHangingGardens);
		wonderCardDeck.push_back(&cardTheMausoleum);
		wonderCardDeck.push_back(&cardThePyramids);
		wonderCardDeck.push_back(&cardPiraeus);
		wonderCardDeck.push_back(&cardTheSphinx);
		wonderCardDeck.push_back(&cardTheStatueOfZeus);
		wonderCardDeck.push_back(&cardTheTempleOfArtemis);

		srand((unsigned)time(NULL));
		random_shuffle(wonderCardDeck.begin(), wonderCardDeck.end());

		for (int i = 0; i < 4; i++)
		{
			wonderCardDeck.pop_back();
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
		progressTokenDeck.clear();
		progressTokenDiscardDeck.clear();
		player1.playerCity.clear();
		player1.resetResources();
		player1.playerWonderDeck.clear();
		player2.playerCity.clear();
		player2.resetResources();
		player2.playerWonderDeck.clear();
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
				checkForChoosePlayer = true;
				mAge = 2;
				playAge2Sound = true; 
				return true;
			}
			else if (mAge == 2)
			{
				for (int i = 0; i < 20; i++)
				{
					board[i] = &age3Deck[i];
				}
				checkForChoosePlayer = true;
				mAge = 3;
				playAge3Sound = true;
				return true;
			}
			else if (mAge == 3)
			{
				runCivilianVictory();
				return false;
			}
		}
	}

	bool World::checkForScienceVictory(Player & currentPlayer)
	{
	
		int symbolCounter = 0;
		if (currentPlayer.scienceSymbols.arch >= 1) symbolCounter++;
		if (currentPlayer.scienceSymbols.balance >= 1) symbolCounter++;
		if (currentPlayer.scienceSymbols.globe >= 1) symbolCounter++;
		if (currentPlayer.scienceSymbols.mortar >= 1) symbolCounter++;
		if (currentPlayer.scienceSymbols.tablet >= 1) symbolCounter++;
		if (currentPlayer.scienceSymbols.wheel >= 1) symbolCounter++;
		if (currentPlayer.scienceSymbols.quill >= 1) symbolCounter++;

		if (symbolCounter >= 6 && currentPlayer.getPlayerNumber() == PLAYER_1) 
		{ 
			player1ScienceVictory = true; 
			return true; 
		}

		if (symbolCounter >= 6 && currentPlayer.getPlayerNumber() == PLAYER_2) 
		{
			player2ScienceVictory = true;
			return true;
		}
		else return false;
	}


	//check to see if progress token in player city is greater or equal to 2
	//allow to build wonder if true


	bool World::canBuild(Player & currentPlayer, Card & card)
	{
		// Checking for link-building
		for (vector<Card*>::iterator it = currentPlayer.playerCity.begin(); it != currentPlayer.playerCity.end(); ++it)
		{
			if ((*it)->getLinkerValue1() == card.getLinkerValue1() && (*it)->getLinkerValue1() != NOLINKVALUE)
			{
				buildByLink = true;
				return true;
			}
			else if ((*it)->getLinkerValue2() == card.getLinkerValue2() && (*it)->getLinkerValue2() != NOLINKVALUE)
			{
				buildByLink = true;
				return true;
			}
		}

		// Checking for Masonry and Architecture PTs
		bool masonryDiscount = false;
		bool architectureDiscount = false;
		if (currentPlayer.playerPT1 != nullptr && currentPlayer.playerPT1->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT2 != nullptr && currentPlayer.playerPT2->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT3 != nullptr && currentPlayer.playerPT3->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT4 != nullptr && currentPlayer.playerPT4->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT5 != nullptr && currentPlayer.playerPT5->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		if (currentPlayer.playerPT1 != nullptr && currentPlayer.playerPT1->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT2 != nullptr && currentPlayer.playerPT2->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT3 != nullptr && currentPlayer.playerPT3->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT4 != nullptr && currentPlayer.playerPT4->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT5 != nullptr && currentPlayer.playerPT5->getName() == "Architecture")
		{
			architectureDiscount = true;
		}

		// need to assign the opposing player
		Player * opposingPlayer;
		if (currentPlayer.getPlayerNumber() == PLAYER_1) opposingPlayer = &player2;
		else if (currentPlayer.getPlayerNumber() == PLAYER_2) opposingPlayer = &player1;

		// need to assign the differences between what the card costs and what the player has
		// PT discounts need to be fully implemented still
		int woodCardDiff = card.getWoodCost() - currentPlayer.getWood();
		int stoneCardDiff = card.getStoneCost() - currentPlayer.getStone();
		int clayCardDiff = card.getClayCost() - currentPlayer.getClay();
		int papyrusCardDiff = card.getPapyrusCost() - currentPlayer.getPapyrus();
		int glassCardDiff = card.getGlassCost() - currentPlayer.getGlass();

		// need to account for forum resources flag
		if (currentPlayer.flags.forumResourcesFlag == true)
		{
			if (papyrusCardDiff > 0 && glassCardDiff <= 0) papyrusCardDiff--;
			else if (papyrusCardDiff <= 0 && glassCardDiff > 0) glassCardDiff--;
			// if they're both above 0, then subtract one from the larger of the two
			else if (papyrusCardDiff > 0 && glassCardDiff > 0)
			{
				if (papyrusCardDiff > glassCardDiff) papyrusCardDiff--;
				else if (papyrusCardDiff < glassCardDiff) glassCardDiff--;
				else papyrusCardDiff--;
			}
		}

		// need to account for caravensery resources flag
		if (currentPlayer.flags.caravenseryResourcesFlag == true)
		{
			if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff <= 0) woodCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff <= 0) stoneCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff > 0) clayCardDiff--;
			// wood and stone above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff <= 0)
			{
				if (woodCardDiff > stoneCardDiff) woodCardDiff--;
				else if (woodCardDiff < stoneCardDiff) stoneCardDiff--;
				else woodCardDiff--;
			}
			// wood and clay above 0
			else if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (woodCardDiff < clayCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
			// stone and clay above 0
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (stoneCardDiff < clayCardDiff) clayCardDiff--;
				else stoneCardDiff--;
			}
			// all three above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > stoneCardDiff && woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (stoneCardDiff > woodCardDiff && stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (clayCardDiff > woodCardDiff && clayCardDiff > stoneCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
		}

		// need to account for piraeus resources flag
		if (currentPlayer.flags.piraeusResourcesFlag == true)
		{
			if (papyrusCardDiff > 0 && glassCardDiff <= 0) papyrusCardDiff--;
			else if (papyrusCardDiff <= 0 && glassCardDiff > 0) glassCardDiff--;
			// if they're both above 0, then subtract one from the larger of the two
			else if (papyrusCardDiff > 0 && glassCardDiff > 0)
			{
				if (papyrusCardDiff > glassCardDiff) papyrusCardDiff--;
				else if (papyrusCardDiff < glassCardDiff) glassCardDiff--;
				else papyrusCardDiff--;
			}
		}

		// need to account for the great lighthouse resources flag
		if (currentPlayer.flags.theGreatLighthouseResourcesFlag == true)
		{
			if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff <= 0) woodCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff <= 0) stoneCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff > 0) clayCardDiff--;
			// wood and stone above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff <= 0)
			{
				if (woodCardDiff > stoneCardDiff) woodCardDiff--;
				else if (woodCardDiff < stoneCardDiff) stoneCardDiff--;
				else woodCardDiff--;
			}
			// wood and clay above 0
			else if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (woodCardDiff < clayCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
			// stone and clay above 0
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (stoneCardDiff < clayCardDiff) clayCardDiff--;
				else stoneCardDiff--;
			}
			// all three above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > stoneCardDiff && woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (stoneCardDiff > woodCardDiff && stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (clayCardDiff > woodCardDiff && clayCardDiff > stoneCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
		}

		// Handling Masonry PT
		if (card.getType() == BLUE_CARD && masonryDiscount == true)
		{
			int numOfDiscounts = 0;

			while (numOfDiscounts < 2)
			{
				if (woodCardDiff > 0)
				{
					woodCardDiff--;
					numOfDiscounts++;
				}
				else if (stoneCardDiff > 0)
				{
					stoneCardDiff--;
					numOfDiscounts++;
				}
				else if (clayCardDiff > 0)
				{
					clayCardDiff--;
					numOfDiscounts++;
				}
				else if (papyrusCardDiff > 0)
				{
					papyrusCardDiff--;
					numOfDiscounts++;
				}
				else if (glassCardDiff > 0)
				{
					glassCardDiff--;
					numOfDiscounts++;
				}

				if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff <= 0 && papyrusCardDiff <= 0 && glassCardDiff <= 0) break;

			}
		}

		// Handling Architecture PT
		if (card.getType() == WONDER_CARD && architectureDiscount == true)
		{
			int numOfDiscounts = 0;

			while (numOfDiscounts < 2)
			{
				if (woodCardDiff > 0)
				{
					woodCardDiff--;
					numOfDiscounts++;
				}
				else if (stoneCardDiff > 0)
				{
					stoneCardDiff--;
					numOfDiscounts++;
				}
				else if (clayCardDiff > 0)
				{
					clayCardDiff--;
					numOfDiscounts++;
				}
				else if (papyrusCardDiff > 0)
				{
					papyrusCardDiff--;
					numOfDiscounts++;
				}
				else if (glassCardDiff > 0)
				{
					glassCardDiff--;
					numOfDiscounts++;
				}

				if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff <= 0 && papyrusCardDiff <= 0 && glassCardDiff <= 0) break;

			}
		}

		// need to assign the cost of trading for resources that are needed
		int woodTradeCost = 0;
		int clayTradeCost = 0;
		int stoneTradeCost = 0;
		int papyrusTradeCost = 0;
		int glassTradeCost = 0;

		if (woodCardDiff > 0 && currentPlayer.flags.woodTradeFlag == false) woodTradeCost += (2 + opposingPlayer->getWood()) * woodCardDiff;
		else if (woodCardDiff > 0 && currentPlayer.flags.woodTradeFlag == true) woodTradeCost += (1 + opposingPlayer->getWood()) * woodCardDiff;

		if (stoneCardDiff > 0 && currentPlayer.flags.stoneTradeFlag == false) stoneTradeCost += (2 + opposingPlayer->getStone()) * stoneCardDiff;
		else if (stoneCardDiff > 0 && currentPlayer.flags.stoneTradeFlag == true) stoneTradeCost += (1 + opposingPlayer->getStone()) * stoneCardDiff;

		if (clayCardDiff > 0 && currentPlayer.flags.clayTradeFlag == false) clayTradeCost += (2 + opposingPlayer->getClay()) * clayCardDiff;
		else if (clayCardDiff > 0 && currentPlayer.flags.clayTradeFlag == true) clayTradeCost += (1 + opposingPlayer->getClay()) * clayCardDiff;

		if (papyrusCardDiff > 0 && currentPlayer.flags.papyrusTradeFlag == false) papyrusTradeCost += (2 + opposingPlayer->getPapyrus()) * papyrusCardDiff;
		else if (papyrusCardDiff > 0 && currentPlayer.flags.papyrusTradeFlag == true) papyrusTradeCost += (1 + opposingPlayer->getPapyrus()) * papyrusCardDiff;

		if (glassCardDiff > 0 && currentPlayer.flags.glassTradeFlag == false) glassTradeCost += (2 + opposingPlayer->getGlass()) * glassCardDiff;
		else if (glassCardDiff > 0 && currentPlayer.flags.glassTradeFlag == true) glassTradeCost += (1 + opposingPlayer->getGlass()) * glassCardDiff;

		int totalCoinsNeeded = woodTradeCost + stoneTradeCost + clayTradeCost + papyrusTradeCost + glassTradeCost;

		// first condition just checks if the player can afford outright
		if (currentPlayer.getCoins() >= card.getCoinCost() &&
			woodTradeCost <= 0 &&
			stoneTradeCost <= 0 &&
			clayTradeCost <= 0 &&
			papyrusTradeCost <= 0 &&
			glassTradeCost <= 0)
		{
			return true;
		}
		// second condition checks if the player has the resources but not enough coins
		else if (currentPlayer.getCoins() < card.getCoinCost() &&
			woodTradeCost <= 0 &&
			stoneTradeCost <= 0 &&
			clayTradeCost <= 0 &&
			papyrusTradeCost <= 0 &&
			glassTradeCost <= 0)
		{
			return false;
		}
		// third condition checks if the player doesn't have the resources but can afford the cost for trading
		else if (totalCoinsNeeded > 0 && currentPlayer.getCoins() >= totalCoinsNeeded)
		{
			return true;
		}
		// fourth condition checks if the player doesn't have the resources and CAN'T afford the cost for trading
		else if (totalCoinsNeeded > 0 && currentPlayer.getCoins() < totalCoinsNeeded)
		{
			return false;
		}
		else return false;
	}

	void World::runCivilianVictory()
	{
		/*
		1. Blue Cards
			a. Just add up the numbers on the cards
		2. Green Cards
			a. Just add up the numbers on the cards
		3. Yellow Cards
			a. Just add up the numbers on the cards
		4. Guild Cards
			a. Use code from buildling these to get gold, in order to add up the victory points
		5. Wonder Cards
			a. Just add up the numbers on the cards
		6. Progress Tokens
			a. Agriculture = 4
			b. Philosophy = 7
			c. Mathematics = 3 x number of PTs (including Mathematics)
		7. Gold Remaining
			a. 1 VP per 3 gold, rounded down
		8. Military Position	
			a. Just based on the position of the conflict pawn
		*/
		
		int player1Points = 0;
		int player2Points = 0;

		if (player1.playerPT1 != nullptr && player1.playerPT1->getName() == "Agriculture")
		{
			player1Points = 4;
		}

		if (player1.playerPT2 != nullptr && player1.playerPT2->getName() == "Agriculture")
		{
			player1Points = 4;
		}

		if (player1.playerPT3 != nullptr && player1.playerPT3->getName() == "Agriculture")
		{
			player1Points = 4;
		}

		if (player1.playerPT4 != nullptr &&player1.playerPT4->getName() == "Agriculture")
		{
			player1Points = 4;
		}

		if (player1.playerPT5 != nullptr && player1.playerPT5->getName() == "Agriculture")
		{
			player1Points = 4;
		}

		if (player2.playerPT1 != nullptr && player2.playerPT1->getName() == "Agriculture")
		{
			player2Points = 4;
		}

		if (player2.playerPT2 != nullptr && player2.playerPT2->getName() == "Agriculture")
		{
			player2Points = 4;
		}

		if (player2.playerPT3 != nullptr && player2.playerPT3->getName() == "Agriculture")
		{
			player2Points = 4;
		}

		if (player2.playerPT4 != nullptr &&player2.playerPT4->getName() == "Agriculture")
		{
			player2Points = 4;
		}

		if (player2.playerPT5 != nullptr && player2.playerPT5->getName() == "Agriculture")
		{
			player2Points = 4;
		}


		//implement addition of victory points from Wonders built
		for (int i = 0; i < 4; i++)
		{

	
			if (player1.playerWonderDeck[i]->getName() == "The Appian Way")
			{
				player1Points += 3;
			}

			if (player1.playerWonderDeck[i]->getName() == "Circus Maximus")
			{
				player1Points += 3;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Colossus")
			{
				player1Points += 3;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Great Library")
			{
				player1Points += 4;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Great Lighthouse")
			{
				player1Points += 4;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Hanging Gardens")
			{
				player1Points += 3;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Mausoleum")
			{
				player1Points += 2;
			}

			if (player1.playerWonderDeck[i]->getName() == "Piraeus")
			{
				player1Points += 2;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Pyramids")
			{
				player1Points += 9;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Sphinx")
			{
				player1Points += 6;
			}

			if (player1.playerWonderDeck[i]->getName() == "The Statue of Zeus")
			{
				player1Points += 3;
			}


			if (player2.playerWonderDeck[i]->getName() == "The Appian Way")
			{
				player2Points += 3;
			}

			if (player2.playerWonderDeck[i]->getName() == "Circus Maximus")
			{
				player2Points += 3;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Colossus")
			{
				player2Points += 3;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Great Library")
			{
				player2Points += 4;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Great Lighthouse")
			{
				player2Points += 4;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Hanging Gardens")
			{
				player2Points += 3;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Mausoleum")
			{
				player2Points += 2;
			}

			if (player2.playerWonderDeck[i]->getName() == "Piraeus")
			{
				player2Points += 2;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Pyramids")
			{
				player2Points += 9;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Sphinx")
			{
				player2Points += 6;
			}

			if (player2.playerWonderDeck[i]->getName() == "The Statue of Zeus")
			{
				player2Points += 3;
			}
		}





		if (player1.playerPT1 != nullptr && player1.playerPT1->getName() == "Philosophy")
		{
			player1Points = 7;
		}

		if (player1.playerPT2 != nullptr && player1.playerPT2->getName() == "Philosophy")
		{
			player1Points = 7;
		}

		if (player1.playerPT3 != nullptr && player1.playerPT3->getName() == "Philosophy")
		{
			player1Points = 7;
		}

		if (player1.playerPT4 != nullptr &&player1.playerPT4->getName() == "Philosophy")
		{
			player1Points = 7;
		}

		if (player1.playerPT5 != nullptr && player1.playerPT5->getName() == "Philosophy")
		{
			player1Points = 7;
		}

		if (player2.playerPT1 != nullptr && player2.playerPT1->getName() == "Philosophy")
		{
			player2Points = 7;
		}

		if (player2.playerPT2 != nullptr && player2.playerPT2->getName() == "Philosophy")
		{
			player2Points = 7;
		}

		if (player2.playerPT3 != nullptr && player2.playerPT3->getName() == "Philosophy")
		{
			player2Points = 7;
		}

		if (player2.playerPT4 != nullptr &&player2.playerPT4->getName() == "Philosophy")
		{
			player2Points = 7;
		}

		if (player2.playerPT5 != nullptr && player2.playerPT5->getName() == "Philosophy")
		{
			player2Points = 7;
		}






		if (player1.playerPT1 != nullptr && player1.playerPT1->getName() == "Mathematics")
		{
			player1Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player1.playerPT2 != nullptr && player1.playerPT2->getName() == "Mathematics")
		{
			player1Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player1.playerPT3 != nullptr && player1.playerPT3->getName() == "Mathematics")
		{
			player1Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player1.playerPT4 != nullptr &&player1.playerPT4->getName() == "Mathematics")
		{
			player1Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player1.playerPT5 != nullptr && player1.playerPT5->getName() == "Mathematics")
		{
			player1Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player2.playerPT1 != nullptr && player2.playerPT1->getName() == "Mathematics")
		{
			player2Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player2.playerPT2 != nullptr && player2.playerPT2->getName() == "Mathematics")
		{
			player2Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player2.playerPT3 != nullptr && player2.playerPT3->getName() == "Mathematics")
		{
			player2Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player2.playerPT4 != nullptr &&player2.playerPT4->getName() == "Mathematics")
		{
			player2Points = 3 * (currentPlayer->playerPT.size());
		}

		if (player2.playerPT5 != nullptr && player2.playerPT5->getName() == "Mathematics")
		{
			player2Points = 3 * (currentPlayer->playerPT.size());
		}

		player1Points += (player1.getCoins() / 3); //add victory points for player 1 for remaining coins divided by 3

		player2Points += (player2.getCoins() / 3); // add victory points for player 1 for remaining coins divided by 3

		for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
		{
			player1Points += (*it)->getVictoryPoints();

		}

		for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
		{
			player2Points += (*it)->getVictoryPoints();
		}

		if (mConflict >= -2 && mConflict <= -1) //add 2 victory points for player 2
		{
			player2Points += 2;
		}

		if (mConflict >= -5 && mConflict <= -3 ) //add 5 victory points for player 1
		{

			player2Points += 5;

		}

		if (mConflict >= -8 && mConflict <= -6 ) //add 10 victory points for player 1
		{
			player2Points += 10;
		}




		if (mConflict >= 1 && mConflict <= 2 ) //add 2 victory points for player 1
		{
			player1Points += 2;

		}

		if (mConflict >= 3 && mConflict <= 5) //add 5 victory points for player 1
		{
			
			player1Points += 5;

		}

		if (mConflict >= 6 && mConflict <= 8) //add 10 victory points for player 1
		{
			player1Points += 10;
		}

		if (player1Points > player2Points)
		{
			player1CivilianVictory = true;
		}

		else
		{
			player2CivlianVictory = true;
		}

	}

	void World::doEffect(Player & currentPlayer, Card & card)
	{
		int goldAdded = 0;
		
		if (card.getType() == GREEN_CARD)
		{
			switch (card.getScienceSymbol())
			{
			case SCIENCE_SYMBOL_GLOBE:
				currentPlayer.scienceSymbols.globe++;
				if (currentPlayer.scienceSymbols.globe == 2) progressTokenState = true;
				break;
			case SCIENCE_SYMBOL_TABLET:
				currentPlayer.scienceSymbols.tablet++;
				if (currentPlayer.scienceSymbols.tablet == 2) progressTokenState = true;
				break;
			case SCIENCE_SYMBOL_MORTAR:
				currentPlayer.scienceSymbols.mortar++;
				if (currentPlayer.scienceSymbols.mortar == 2) progressTokenState = true;
				break;
			case SCIENCE_SYMBOL_ARCH:
				currentPlayer.scienceSymbols.arch++;
				if (currentPlayer.scienceSymbols.arch == 2) progressTokenState = true;
				break;
			case SCIENCE_SYMBOL_QUILL:
				currentPlayer.scienceSymbols.quill++;
				if (currentPlayer.scienceSymbols.quill == 2) progressTokenState = true;
				break;
			case SCIENCE_SYMBOL_WHEEL:
				currentPlayer.scienceSymbols.wheel++;
				if (currentPlayer.scienceSymbols.wheel == 2) progressTokenState = true;
				break;
			}
		}
		else if (card.getType() == RED_CARD)
		{
			if (currentPlayer.getPlayerNumber() == PLAYER_1)
			{
				if (player1.playerPT1 != nullptr && player1.playerPT1->getName() == "Strategy")
				{
					mConflict ++;
				}

				if (player1.playerPT2 != nullptr && player1.playerPT2->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player1.playerPT3 != nullptr && player1.playerPT3->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player1.playerPT4 != nullptr &&player1.playerPT4->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player1.playerPT5 != nullptr && player1.playerPT5->getName() == "Strategy")
				{
					mConflict++;
				}

				
				mConflict += (card.getShields() + ((currentPlayer.flags.strategyPTFlag) ? (1) : (0)));
			}
			else if (currentPlayer.getPlayerNumber() == PLAYER_2)
			{
				if (player2.playerPT1 != nullptr && player2.playerPT1->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player2.playerPT2 != nullptr && player2.playerPT2->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player2.playerPT3 != nullptr && player2.playerPT3->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player2.playerPT4 != nullptr &&player2.playerPT4->getName() == "Strategy")
				{
					mConflict++;
				}

				if (player2.playerPT5 != nullptr && player2.playerPT5->getName() == "Strategy")
				{ 
					mConflict++;
				}
				mConflict -= (card.getShields() + ((currentPlayer.flags.strategyPTFlag) ? (1) : (0)));
			}
			// need to set conflict to -9 or 9 in order to avoid out of range for conflict pawn vector positions
			// if someone plays a card that puts them past the exact win condition they win anyway and it will still be flagged as a win
			if (mConflict < -9) mConflict = -9;
			if (mConflict > 9) mConflict = 9;

			//call military effect of military range special functions dependent upon where the conflict pawn is located.
			militaryTokenZone();

			if (mConflict == -9)
			{
				player2MilitaryVictory = true;
			}

			if (mConflict == 9)
			{
				player1MilitaryVictory = true;
			}


			
		}
		else if (card.getType() == BLUE_CARD)
		{
			// these have no immediate effects //
		}
		else if (card.getType() == BROWN_CARD)
		{
			switch (card.getIndex())
			{
			case 0: // lumber yard
				currentPlayer.setWood(1);
				break;
			case 1: // logging camp
				currentPlayer.setWood(1);
				break;
			case 2: // clay pool
				currentPlayer.setClay(1);
				break;
			case 3: // clay pit
				currentPlayer.setClay(1);
				break;
			case 4: // quarry
				currentPlayer.setStone(1);
				break;
			case 5: // stone pit
				currentPlayer.setStone(1);
				break;
			case 23: // saw mill
				currentPlayer.setWood(2);
				break;
			case 24: // brickyard
				currentPlayer.setClay(2);
				break;
			case 25: // shelf quarry
				currentPlayer.setStone(2);
				break;
			}
		}
		else if (card.getType() == GRAY_CARD)
		{
			switch (card.getIndex())
			{
			case 6: // glassworks
				currentPlayer.setGlass(1);
				break;
			case 7: // press
				currentPlayer.setPapyrus(1);
				break;
			case 26: // glassblower
				currentPlayer.setGlass(1);
				break;
			case 27: // drying room
				currentPlayer.setPapyrus(1);
				break;
			}
		}
		else if (card.getType() == YELLOW_CARD)
		{
			switch (card.getIndex())
			{
			case 11: // stone reserve
				currentPlayer.flags.stoneTradeFlag = true;
				break;
			case 12: // clay reserve
				currentPlayer.flags.clayTradeFlag = true;
				break;
			case 13: // wood reserve
				currentPlayer.flags.woodTradeFlag = true;
				break;
			case 22: // tavern
				currentPlayer.setCoins(4);
				break;
			case 29: // forum
				currentPlayer.flags.forumResourcesFlag = true;
				break;
			case 30: // caravansery
				currentPlayer.flags.caravenseryResourcesFlag = true;
				break;
			case 31: // customs house
				currentPlayer.flags.papyrusTradeFlag = true;
				currentPlayer.flags.glassTradeFlag = true;
				break;
			case 45: // brewery
				currentPlayer.setCoins(6);
				break;
			case 50: // chamber of commerce
				for (vector<Card*>::iterator it = currentPlayer.playerCity.begin(); it != currentPlayer.playerCity.end(); ++it)
				{
					if ((*it)->getType() == GRAY_CARD) goldAdded += 3;
				}
				currentPlayer.setCoins(goldAdded);
				break;
			case 51: // port
				for (vector<Card*>::iterator it = currentPlayer.playerCity.begin(); it != currentPlayer.playerCity.end(); ++it)
				{
					if ((*it)->getType() == BROWN_CARD) goldAdded += 2;
				}
				currentPlayer.setCoins(goldAdded);
				break;
			case 52: // armory
				for (vector<Card*>::iterator it = currentPlayer.playerCity.begin(); it != currentPlayer.playerCity.end(); ++it)
				{
					if ((*it)->getType() == RED_CARD) goldAdded += 1;
				}
				currentPlayer.setCoins(goldAdded);
				break;
			case 64: // lighthouse
				for (vector<Card*>::iterator it = currentPlayer.playerCity.begin(); it != currentPlayer.playerCity.end(); ++it)
				{
					if ((*it)->getType() == YELLOW_CARD) goldAdded += 1;
				}
				currentPlayer.setCoins(goldAdded);
				break;
			case 65: // arena
				for (vector<Card*>::iterator it = currentPlayer.playerWonderDeck.begin(); it != currentPlayer.playerWonderDeck.end(); ++it)
				{
					if ((*it)->builtWonder) goldAdded += 2;
				}
				currentPlayer.setCoins(goldAdded);
				break;
			}
		}
		else if (card.getType() == GUILD_CARD)
		{
			int player1Worth = 0;
			int player2Worth = 0;
			
			switch (card.getIndex())
			{
			case 66: // merchants guild
				for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
				{
					if ((*it)->getType() == YELLOW_CARD) player1Worth++;
				}
				for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
				{
					if ((*it)->getType() == YELLOW_CARD) player2Worth++;
				}

				if (player1Worth >= player2Worth) currentPlayer.setCoins(player1Worth);
				else if (player2Worth > player1Worth) currentPlayer.setCoins(player2Worth);
				
				currentPlayer.flags.merchantsGuildFlag = true;
				break;
			case 67: // shipowners guild
				for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
				{
					if ((*it)->getType() == BROWN_CARD || (*it)->getType() == GRAY_CARD) player1Worth++;
				}
				for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
				{
					if ((*it)->getType() == BROWN_CARD || (*it)->getType() == GRAY_CARD) player2Worth++;
				}

				if (player1Worth >= player2Worth) currentPlayer.setCoins(player1Worth);
				else if (player2Worth > player1Worth) currentPlayer.setCoins(player2Worth);

				currentPlayer.flags.shipownersGuildFlag = true;
				break;
			case 68: // builders guild
				currentPlayer.flags.buildersGuildFlag = true;
				break;
			case 69: // magistrates guild
				for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
				{
					if ((*it)->getType() == BLUE_CARD) player1Worth++;
				}
				for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
				{
					if ((*it)->getType() == BLUE_CARD) player2Worth++;
				}

				if (player1Worth >= player2Worth) currentPlayer.setCoins(player1Worth);
				else if (player2Worth > player1Worth) currentPlayer.setCoins(player2Worth);

				currentPlayer.flags.magistratesGuildFlag = true;
				break;
			case 70: // scientists guild
				for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
				{
					if ((*it)->getType() == GREEN_CARD) player1Worth++;
				}
				for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
				{
					if ((*it)->getType() == GREEN_CARD) player2Worth++;
				}

				if (player1Worth >= player2Worth) currentPlayer.setCoins(player1Worth);
				else if (player2Worth > player1Worth) currentPlayer.setCoins(player2Worth);

				currentPlayer.flags.scientistsGuildFlag = true;
				break;
			case 71: // moneylenders guild
				currentPlayer.flags.moneylendersGuildFlag = true;
				break;
			case 72: // tacticians guild
				for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
				{
					if ((*it)->getType() == RED_CARD) player1Worth++;
				}
				for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
				{
					if ((*it)->getType() == RED_CARD) player2Worth++;
				}

				if (player1Worth >= player2Worth) currentPlayer.setCoins(player1Worth);
				else if (player2Worth > player1Worth) currentPlayer.setCoins(player2Worth);

				currentPlayer.flags.tacticiansGuildFlag = true;
				break;
			}
		}
		else if (card.getType() == WONDER_CARD)
		{
			Player * opposingPlayer;

			if (currentPlayer.getPlayerNumber() == PLAYER_1) opposingPlayer = &player2;
			else if (currentPlayer.getPlayerNumber() == PLAYER_2) opposingPlayer = &player1;
			
			switch (card.getIndex())
			{
			case 73: // the appian way
				currentPlayer.setCoins(3);
				
				// need to reset coins to zero if they go below zero when subtracting the three coins
				// setCoins() changes the amount of coins, it doesn't actually set it (likely should be part of refactoring at some point)
				opposingPlayer->setCoins(-3);
				if (0 - opposingPlayer->getCoins() == -3) opposingPlayer->setCoins(3);
				else if (0 - opposingPlayer->getCoins() == -2) opposingPlayer->setCoins(2);
				else if (0 - opposingPlayer->getCoins() == -1) opposingPlayer->setCoins(1);
				else {}

				// set the repeat turn flag on
				repeatTurn = true;

				break;
			case 74: // circus maximus
				if (currentPlayer.getPlayerNumber() == PLAYER_1) destroyGrayCard = 1;
				else if (currentPlayer.getPlayerNumber() == PLAYER_2) destroyGrayCard = 2;

				if (currentPlayer.getPlayerNumber() == PLAYER_1) mConflict++;
				else if (currentPlayer.getPlayerNumber() == PLAYER_2) mConflict--;
				
				break;
			case 75: // the colossus
				if (currentPlayer.getPlayerNumber() == PLAYER_1) mConflict += 2;
				else if (currentPlayer.getPlayerNumber() == PLAYER_2) mConflict -= 2;
				
				break;
			case 76: // the great library
				buildPTFromDiscard = true;
				
				break;
			case 77: // the great lighthouse
				currentPlayer.flags.theGreatLighthouseResourcesFlag = true;
							
				break;
			case 78: // the hanging gardens
				currentPlayer.setCoins(6);
				repeatTurn = true;
				
				break;
			case 79: // the mausoleum
				buildFromDiscard = true;
				
				break;
			case 80: // piraeus
				currentPlayer.flags.piraeusResourcesFlag = true;
				repeatTurn = true;
				
				break;
			case 81: // the pyramides
				// no immediate effect //
				
				break;
			case 82: // the sphinx
				repeatTurn = true;
				
				break;
			case 83: // the statue of zeus
				if (currentPlayer.getPlayerNumber() == PLAYER_1) destroyBrownCard = 1;
				else if (currentPlayer.getPlayerNumber() == PLAYER_2) destroyBrownCard = 2;

				if (currentPlayer.getPlayerNumber() == PLAYER_1) mConflict++;
				else if (currentPlayer.getPlayerNumber() == PLAYER_2) mConflict--;
				
				break;
			case 84: // the temple of artemis
				currentPlayer.setCoins(12);
				repeatTurn = true;
				
				break;
			}
		}

	}

	void World::doEffect(Player & currentPlayer, ProgressToken & progressToken)
	{
		if (progressToken.getName()=="Agriculture")
		{
			currentPlayer.setCoins(6);
		}

		if (progressToken.getName() == "Urbanism")
		{
			currentPlayer.setCoins(6);
		}

		if (progressToken.getName() == "Law")
		{
			currentPlayer.scienceSymbols.balance++;
		}


	}

	int World::goldCost(Player & currentPlayer, Card & card)
	{
		// Checking for link-building
		if (buildByLink == true) return 0;
		
		// Checking for Masonry and Architecture PTs
		bool masonryDiscount = false;
		bool architectureDiscount = false;
		if (currentPlayer.playerPT1 != nullptr && currentPlayer.playerPT1->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT2 != nullptr && currentPlayer.playerPT2->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT3 != nullptr && currentPlayer.playerPT3->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT4 != nullptr && currentPlayer.playerPT4->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		else if (currentPlayer.playerPT5 != nullptr && currentPlayer.playerPT5->getName() == "Masonry")
		{
			masonryDiscount = true;
		}
		if (currentPlayer.playerPT1 != nullptr && currentPlayer.playerPT1->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT2 != nullptr && currentPlayer.playerPT2->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT3 != nullptr && currentPlayer.playerPT3->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT4 != nullptr && currentPlayer.playerPT4->getName() == "Architecture")
		{
			architectureDiscount = true;
		}
		else if (currentPlayer.playerPT5 != nullptr && currentPlayer.playerPT5->getName() == "Architecture")
		{
			architectureDiscount = true;
		}

		// need to assign the opposing player
		Player * opposingPlayer;
		if (currentPlayer.getPlayerNumber() == PLAYER_1) opposingPlayer = &player2;
		else if (currentPlayer.getPlayerNumber() == PLAYER_2) opposingPlayer = &player1;

		// need to assign the differences between what the card costs and what the player has
		// PT discounts need to be fully implemented still
		int woodCardDiff = card.getWoodCost() - currentPlayer.getWood();
		int stoneCardDiff = card.getStoneCost() - currentPlayer.getStone();
		int clayCardDiff = card.getClayCost() - currentPlayer.getClay();
		int papyrusCardDiff = card.getPapyrusCost() - currentPlayer.getPapyrus();
		int glassCardDiff = card.getGlassCost() - currentPlayer.getGlass();

		// need to account for forum resources flag
		if (currentPlayer.flags.forumResourcesFlag == true)
		{
			if (papyrusCardDiff > 0 && glassCardDiff <= 0) papyrusCardDiff--;
			else if (papyrusCardDiff <= 0 && glassCardDiff > 0) glassCardDiff--;
			// if they're both above 0, then subtract one from the larger of the two
			else if (papyrusCardDiff > 0 && glassCardDiff > 0)
			{
				if (papyrusCardDiff > glassCardDiff) papyrusCardDiff--;
				else if (papyrusCardDiff < glassCardDiff) glassCardDiff--;
				else papyrusCardDiff--;
			}
		}

		// need to account for caravensery resources flag
		if (currentPlayer.flags.caravenseryResourcesFlag == true)
		{
			if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff <= 0) woodCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff <= 0) stoneCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff > 0) clayCardDiff--;
			// wood and stone above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff <= 0)
			{
				if (woodCardDiff > stoneCardDiff) woodCardDiff--;
				else if (woodCardDiff < stoneCardDiff) stoneCardDiff--;
				else woodCardDiff--;
			}
			// wood and clay above 0
			else if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (woodCardDiff < clayCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
			// stone and clay above 0
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (stoneCardDiff < clayCardDiff) clayCardDiff--;
				else stoneCardDiff--;
			}
			// all three above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > stoneCardDiff && woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (stoneCardDiff > woodCardDiff && stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (clayCardDiff > woodCardDiff && clayCardDiff > stoneCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
		}

		// need to account for piraeus resources flag
		if (currentPlayer.flags.piraeusResourcesFlag == true)
		{
			if (papyrusCardDiff > 0 && glassCardDiff <= 0) papyrusCardDiff--;
			else if (papyrusCardDiff <= 0 && glassCardDiff > 0) glassCardDiff--;
			// if they're both above 0, then subtract one from the larger of the two
			else if (papyrusCardDiff > 0 && glassCardDiff > 0)
			{
				if (papyrusCardDiff > glassCardDiff) papyrusCardDiff--;
				else if (papyrusCardDiff < glassCardDiff) glassCardDiff--;
				else papyrusCardDiff--;
			}
		}

		// need to account for the great lighthouse resources flag
		if (currentPlayer.flags.theGreatLighthouseResourcesFlag == true)
		{
			if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff <= 0) woodCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff <= 0) stoneCardDiff--;
			else if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff > 0) clayCardDiff--;
			// wood and stone above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff <= 0)
			{
				if (woodCardDiff > stoneCardDiff) woodCardDiff--;
				else if (woodCardDiff < stoneCardDiff) stoneCardDiff--;
				else woodCardDiff--;
			}
			// wood and clay above 0
			else if (woodCardDiff > 0 && stoneCardDiff <= 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (woodCardDiff < clayCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
			// stone and clay above 0
			else if (woodCardDiff <= 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (stoneCardDiff < clayCardDiff) clayCardDiff--;
				else stoneCardDiff--;
			}
			// all three above 0
			else if (woodCardDiff > 0 && stoneCardDiff > 0 && clayCardDiff > 0)
			{
				if (woodCardDiff > stoneCardDiff && woodCardDiff > clayCardDiff) woodCardDiff--;
				else if (stoneCardDiff > woodCardDiff && stoneCardDiff > clayCardDiff) stoneCardDiff--;
				else if (clayCardDiff > woodCardDiff && clayCardDiff > stoneCardDiff) clayCardDiff--;
				else woodCardDiff--;
			}
		}

		// Handling Masonry PT
		if (card.getType() == BLUE_CARD && masonryDiscount == true)
		{
			int numOfDiscounts = 0;

			while (numOfDiscounts < 2)
			{
				if (woodCardDiff > 0)
				{
					woodCardDiff--;
					numOfDiscounts++;
				}
				else if (stoneCardDiff > 0)
				{
					stoneCardDiff--;
					numOfDiscounts++;
				}
				else if (clayCardDiff > 0)
				{
					clayCardDiff--;
					numOfDiscounts++;
				}
				else if (papyrusCardDiff > 0)
				{
					papyrusCardDiff--;
					numOfDiscounts++;
				}
				else if (glassCardDiff > 0)
				{
					glassCardDiff--;
					numOfDiscounts++;
				}

				if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff <= 0 && papyrusCardDiff <= 0 && glassCardDiff <= 0) break;

			}
		}

		// Handling Architecture PT
		if (card.getType() == WONDER_CARD && architectureDiscount == true)
		{
			int numOfDiscounts = 0;

			while (numOfDiscounts < 2)
			{
				if (woodCardDiff > 0)
				{
					woodCardDiff--;
					numOfDiscounts++;
				}
				else if (stoneCardDiff > 0)
				{
					stoneCardDiff--;
					numOfDiscounts++;
				}
				else if (clayCardDiff > 0)
				{
					clayCardDiff--;
					numOfDiscounts++;
				}
				else if (papyrusCardDiff > 0)
				{
					papyrusCardDiff--;
					numOfDiscounts++;
				}
				else if (glassCardDiff > 0)
				{
					glassCardDiff--;
					numOfDiscounts++;
				}

				if (woodCardDiff <= 0 && stoneCardDiff <= 0 && clayCardDiff <= 0 && papyrusCardDiff <= 0 && glassCardDiff <= 0) break;

			}
		}


		// need to assign the cost of trading for resources that are needed
		int woodTradeCost = 0;
		int clayTradeCost = 0;
		int stoneTradeCost = 0;
		int papyrusTradeCost = 0;
		int glassTradeCost = 0;

		if (woodCardDiff > 0 && currentPlayer.flags.woodTradeFlag == false) woodTradeCost += (2 + opposingPlayer->getWood()) * woodCardDiff;
		else if (woodCardDiff > 0 && currentPlayer.flags.woodTradeFlag == true) woodTradeCost += (1 + opposingPlayer->getWood()) * woodCardDiff;

		if (stoneCardDiff > 0 && currentPlayer.flags.stoneTradeFlag == false) stoneTradeCost += (2 + opposingPlayer->getStone()) * stoneCardDiff;
		else if (stoneCardDiff > 0 && currentPlayer.flags.stoneTradeFlag == true) stoneTradeCost += (1 + opposingPlayer->getStone()) * stoneCardDiff;

		if (clayCardDiff > 0 && currentPlayer.flags.clayTradeFlag == false) clayTradeCost += (2 + opposingPlayer->getClay()) * clayCardDiff;
		else if (clayCardDiff > 0 && currentPlayer.flags.clayTradeFlag == true) clayTradeCost += (1 + opposingPlayer->getClay()) * clayCardDiff;

		if (papyrusCardDiff > 0 && currentPlayer.flags.papyrusTradeFlag == false) papyrusTradeCost += (2 + opposingPlayer->getPapyrus()) * papyrusCardDiff;
		else if (papyrusCardDiff > 0 && currentPlayer.flags.papyrusTradeFlag == true) papyrusTradeCost += (1 + opposingPlayer->getPapyrus()) * papyrusCardDiff;

		if (glassCardDiff > 0 && currentPlayer.flags.glassTradeFlag == false) glassTradeCost += (2 + opposingPlayer->getGlass()) * glassCardDiff;
		else if (glassCardDiff > 0 && currentPlayer.flags.glassTradeFlag == true) glassTradeCost += (1 + opposingPlayer->getGlass()) * glassCardDiff;


		int totalCoinsNeeded = woodTradeCost + stoneTradeCost + clayTradeCost + papyrusTradeCost + glassTradeCost;
		if (totalCoinsNeeded <= 0) return -(card.getCoinCost());
		if (totalCoinsNeeded > 0) return -(totalCoinsNeeded + card.getCoinCost());

	}

	bool World::compareMilitary() //function to determine who has the weaker military to determine whom will pick the turn order
	{

		int player1ConflictPoints = 0;
		int player2ConflictPoints = 0;

		for (vector<Card*>::iterator it = player1.playerCity.begin(); it != player1.playerCity.end(); ++it)
		{
			player1ConflictPoints += (*it)->getShields();
		}

		for (vector<Card*>::iterator it = player2.playerCity.begin(); it != player2.playerCity.end(); ++it)
		{
			player2ConflictPoints += (*it)->getShields();
		}

		if (player1ConflictPoints < player2ConflictPoints)
		{
			return true;
		}

		else {
			return false;
		}
	}

	void World::militaryTokenZone() 
	{
		if (mConflict >= -2 && mConflict <= -1 && player2MilitaryRange0 == false) //add 2 victory points for player 2
		{
			player2MilitaryRange0 = true;
		}

		if (mConflict >= -5 && mConflict<=-3 && player2MilitaryRange1 == false) //add 5 victory points for player 1, and remove two coins for player 1
		{
			player1.setCoins(-2);
			player2.setCoins(2);
			player2MilitaryRange1 = true;
		}

		if (mConflict >= -8 && mConflict<= -6 && player2MilitaryRange2 == false) //add 10 victory points for player 1, and remove 5 coins for player 1
		{
			player1.setCoins(-5);
			player2.setCoins(5);
			player2MilitaryRange2 = true;
		}

		if (mConflict >= 1 && mConflict <= 2 && player1MilitaryRange0 == false) //add 2 victory points for player 1
		{
			player1MilitaryRange0 = true;
		}

		if (mConflict >= 3 && mConflict <= 5 && player1MilitaryRange1 == false) //add 5 victory points for player 1, and remove two coins for player 2
		{
			player2.setCoins(-2);
			player1.setCoins(2);
			player1MilitaryRange1 = true;
		}

		if (mConflict >= 6 && mConflict <= 8 && player1MilitaryRange2 == false) //add 10 victory points for player 1, and remove 5 coins for player 2
		{
			player2.setCoins(-5);
			player1.setCoins(5);
			player1MilitaryRange2 = true;
		}
	}

}



