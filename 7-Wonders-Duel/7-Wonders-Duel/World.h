// 7 Wonders Duel
// World class header

#pragma once
#ifndef WORLD_H
#define WORLD_H
#include <string>
#include "Player.h"
#include "MilitaryToken.h"
#include "ProgressToken.h"
#include "Card.h"
#include "Game_Constants.h"

using namespace std;
using namespace Seven_Wonders;

namespace Seven_Wonders {
	
	class World
	{
	public:
		World();
		int getAge();
		void setAge(int age);
		void buildCard(int clickedCardIndex);
		void ChoosePlayer();
		void buildProgressToken(int progressTokenNumber);
		void discardCard(int clickedCardIndex);
		void buildWonder(int wonderNumber, int clickCardIndex);
		void destroyCard(int cardIndex, Player & player);
		void exposeCards();
		vector<Card> age1Deck;
		vector<Card*> wonderCardDeck;
		vector<Card> age2Deck;
		vector<Card> age3Deck;
		vector<Card> guildDeck;
		vector<Card*> discardDeck;
		vector<ProgressToken*> progressTokenDeck;
		vector <ProgressToken*> progressTokenDiscardDeck;

		int wonderCount = 0; //value to store how many wonders have been built

		Card * board[20];

		void Setup();
		int mCurrentPlayer;

		bool checkForChoosePlayer = false;
		int player1CountPT = 0;
		int player2CountPT = 0;

		//bool value if linker value is true
		bool buildByLink = false;

		void ExitGame();
		bool checkForNewAge();
		bool player1Chosen = false;
		bool player2Chosen = false;

		bool checkForScienceVictory(Player & currentPlayer);

		bool playAgain = false;

		bool player1MilitaryRange0 = false; //bool flags to change after the military range has been achieved by a player as to allow it from not occuring more than one time
		bool player1MilitaryRange1 = false; //ranges (abs. value): 0=[1,2], 1=[3,5], 2=[6,8]
		bool player1MilitaryRange2 = false;
		bool player2MilitaryRange0 = false;
		bool player2MilitaryRange1 = false;
		bool player2MilitaryRange2 = false;


		bool playAge2Sound = false;
		bool playAge3Sound = false;

	
		bool canBuild(Player & currentPlayer, Card & card);
		void runCivilianVictory();
		void doEffect(Player & currentPlayer, Card & card);
		void doEffect(Player & currentPlayer, ProgressToken & progressToken); //overloaded function for doEffect for Progress Token
		int goldCost(Player & currentPlayer, Card & card);

		bool compareMilitary();

		void militaryTokenZone();

		bool player1MilitaryVictory = false;
		bool player2MilitaryVictory = false;

		bool player1ScienceVictory = false;
		bool player2ScienceVictory = false;

		bool player1CivilianVictory = false;
		bool player2CivlianVictory = false;

		bool repeatTurn = false;
		bool progressTokenState = false;
		int destroyBrownCard = 0;
		int destroyGrayCard = 0;
		bool buildFromDiscard = false;
		bool buildPTFromDiscard = false;


		int mAge = 1;
		int mConflict = 0;

		// All game objects
		Player * currentPlayer = nullptr;
		Player player1;
		Player player2;
		MilitaryToken militaryTokenP12;
		MilitaryToken militaryTokenP15;
		MilitaryToken militaryTokenP22;
		MilitaryToken militaryTokenP25;
		ProgressToken progressTokenAgriculture;
		ProgressToken progressTokenArchitecture;
		ProgressToken progressTokenEconomy;
		ProgressToken progressTokenLaw;
		ProgressToken progressTokenMasonry;
		ProgressToken progressTokenMathematics;
		ProgressToken progressTokenPhilosophy;
		ProgressToken progressTokenStrategy;
		ProgressToken progressTokenTheology;
		ProgressToken progressTokenUrbanism;
		Card cardLumberYard;
		Card cardLoggingCamp;
		Card cardClayPool;
		Card cardClayPit;
		Card cardQuarry;
		Card cardStonePit;
		Card cardGlassworks;
		Card cardPress;
		Card cardGuardTower;
		Card cardWorkshop;
		Card cardApothecary;
		Card cardStoneReserve;
		Card cardClayReserve;
		Card cardWoodReserve;
		Card cardStable;
		Card cardGarrison;
		Card cardPalisade;
		Card cardScriptorium;
		Card cardPharmacist;
		Card cardTheater;
		Card cardAltar;
		Card cardBaths;
		Card cardTavern;
		Card cardSawmill;
		Card cardBrickyard;
		Card cardShelfQuarry;
		Card cardGlassBlower;
		Card cardDryingRoom;
		Card cardWalls;
		Card cardForum;
		Card cardCaravansery;
		Card cardCustomsHouse;
		Card cardTribunal;
		Card cardHorseBreeders;
		Card cardBarracks;
		Card cardArcheryRange;
		Card cardParadeGround;
		Card cardLibrary;
		Card cardDispensary;
		Card cardSchool;
		Card cardLaboratory;
		Card cardStatue;
		Card cardTemple;
		Card cardAqueduct;
		Card cardRostrum;
		Card cardBrewery;
		Card cardArsenal;
		Card cardCourthouse;
		Card cardAcademy;
		Card cardStudy;
		Card cardChamberOfCommerce;
		Card cardPort;
		Card cardArmory;
		Card cardPalace;
		Card cardTownHall;
		Card cardObelisk;
		Card cardFortifications;
		Card cardSiegeWorkshop;
		Card cardCircus;
		Card cardUniversity;
		Card cardObservatory;
		Card cardGardens;
		Card cardPantheon;
		Card cardSenate;
		Card cardLighthouse;
		Card cardArena;
		Card cardMerchantsGuild;
		Card cardShipownersGuild;
		Card cardBuildersGuild;
		Card cardMagistratesGuild;
		Card cardScientistsGuild;
		Card cardMoneylendersGuild;
		Card cardTacticiansGuild;
		Card cardTheAppianWay;
		Card cardCircusMaximus;
		Card cardTheColossus;
		Card cardTheGreatLibrary;
		Card cardTheGreatLighthouse;
		Card cardTheHangingGardens;
		Card cardTheMausoleum;
		Card cardPiraeus;
		Card cardThePyramids;
		Card cardTheSphinx;
		Card cardTheStatueOfZeus;
		Card cardTheTempleOfArtemis;

		

	private:

	};
}

#endif // WORLD_H