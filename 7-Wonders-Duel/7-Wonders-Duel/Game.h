// 7 Wonders Duel
// Game class header
// yo

#pragma once
#ifndef GAME_H
#define GAME_H
#include <string>
#include "Player.h"
#include "ConflictPawn.h"
#include "MilitaryToken.h"
#include "ProgressToken.h"
#include "Card.h"
#include "Game_Constants.h"
using namespace std;

class Game
{
public:
	Game();
	void Run();

private:
	void Setup();
	void gameLoop();
	void Shutdown();
	Player player1;
	Player player2;
	ConflictPawn conflictPawn;
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
};

#endif // GAME_H