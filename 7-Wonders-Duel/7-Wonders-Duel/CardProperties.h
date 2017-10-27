// 7 Wonders Duel 
// Card Properties arrays
// This may not be the best way to do this but it should work for now

//#pragma once
#include <iostream>
#include <string>
#include "Game_Constants.h"

namespace Seven_Wonders {

	// Order is by index of cards, found in Game_Constants.h

	extern std::string cardName[85] =
	{
		"Lumber Yard", // lumber yard
		"Logging Camp", // logging camp
		"Clay Pool", // clay pool
		"Clay Pit", // clay pit
		"Quarry", // quarry
		"Stone Pit", // stone pit
		"Glassworks", // glassworks
		"Press", // press
		"Guard Tower", // guard tower
		"Workshop", // workshop
		"Apothecary", // apothecary
		"Stone Reserve", // stone reserve
		"Clay Reserve", // clay reserve
		"Wood Reserve", // wood reserve
		"Stable", // stable
		"Garrison", // garrison
		"Palisade", // palisade
		"Scriptorium", // scriptorium
		"Pharmacist", // pharmacist
		"Theater", // theater
		"Altar", // altar
		"Baths", // baths
		"Tavern", // tavern

		"Sawmill", // sawmill
		"Brickyard", // brickyard
		"Shelf Quarry", // shelf quarry
		"Glass-Blower", // glass blower
		"Drying Room", // drying room
		"Walls", // walls
		"Forum", // forum
		"Caravansery", // caravnsery
		"Customs House", // customs house
		"Tribunal", // tribunal
		"Horse Breeders", // horse breeders
		"Barracks", // barracks
		"Archery Range", // archery range
		"Parade Ground", // parade ground
		"Library", // library
		"Dispensary", // dispensary
		"School", // school
		"Laboratory", // laboratory
		"Statue", // statue
		"Temple", // temple
		"Aqueduct", // aqueduct
		"Rostrum", // rostrum
		"Brewery", // brewery

		"Arsenal", // arsenal
		"Courthouse", // courthouse
		"Academy", // academy
		"Study", // study
		"Chamber of Commerce", // chamber of commerce
		"Port", // port
		"Armory", // armory
		"Palace", // palace
		"Town Hall", // town hall
		"Obelisk", // obelisk
		"Fortifications", // fortifications
		"Siege Workshop", // siege workshop
		"Circus", // circus
		"University", // university
		"Observatory", // observatory 
		"Gardens", // gardens
		"Pantheon", // pantheon
		"Senate", // senate
		"Lighthouse", // lighthouse
		"Arena", // arena

		"Merchants Guild", // merchants guild
		"Shipowners Guild", // shipowners guild
		"Builders Guild", // builders guild
		"Magistrates Guild", // magistrates guild
		"Scientists Guild", // scientists guild
		"Moneylenders Guild", // moneylenders guild
		"Tacticians Guild", // tacticians guild

		"The Appian Way", // the appian way
		"Circus Maximus", // circus maximus
		"The Colossus", // the colossus
		"The Great Library", // the great library
		"The Great Lighthouse", // the great lighthouse
		"The Hanging Gardens", // the hanging gardens
		"The Mausoleum", // the mausoleum
		"Piraeus", // piraeus
		"The Pyramids", // the pyramids
		"The Sphinx", // the sphinx
		"The Statue of Zeus", // the statue of zeus
		"The Temple of Artemis", // the temple of artemis

	};

	extern int cardAge[85] =
	{
		AGE_1, // lumber yard
		AGE_1, // logging camp
		AGE_1, // clay pool
		AGE_1, // clay pit
		AGE_1, // quarry
		AGE_1, // stone pit
		AGE_1, // glassworks
		AGE_1, // press
		AGE_1, // guard tower
		AGE_1, // workshop
		AGE_1, // apothecary
		AGE_1, // stone reserve
		AGE_1, // clay reserve
		AGE_1, // wood reserve
		AGE_1, // stable
		AGE_1, // garrison
		AGE_1, // palisade
		AGE_1, // scriptorium
		AGE_1, // pharmacist
		AGE_1, // theater
		AGE_1, // altar
		AGE_1, // baths
		AGE_1, // tavern
		AGE_2, // sawmill
		AGE_2, // brickyard
		AGE_2, // shelf quarry
		AGE_2, // glass blower
		AGE_2, // drying room
		AGE_2, // walls
		AGE_2, // forum
		AGE_2, // caravnsery
		AGE_2, // customs house
		AGE_2, // tribunal
		AGE_2, // horse breeders
		AGE_2, // barracks
		AGE_2, // archery range
		AGE_2, // parade ground
		AGE_2, // library
		AGE_2, // dispensary
		AGE_2, // school
		AGE_2, // laboratory
		AGE_2, // statue
		AGE_2, // temple
		AGE_2, // aqueduct
		AGE_2, // rostrum
		AGE_2, // brewery
		AGE_3, // arsenal
		AGE_3, // courthouse
		AGE_3, // academy
		AGE_3, // study
		AGE_3, // chamber of commerce
		AGE_3, // port
		AGE_3, // armory
		AGE_3, // palace
		AGE_3, // town hall
		AGE_3, // obelisk
		AGE_3, // fortifications
		AGE_3, // siege workshop
		AGE_3, // circus
		AGE_3, // university
		AGE_3, // observatory 
		AGE_3, // gardens
		AGE_3, // pantheon
		AGE_3, // senate
		AGE_3, // lighthouse
		AGE_3, // arena
		AGE_GUILD, // merchants guild
		AGE_GUILD, // shipowners guild
		AGE_GUILD, // builders guild
		AGE_GUILD, // magistrates guild
		AGE_GUILD, // scientists guild
		AGE_GUILD, // moneylenders guild
		AGE_GUILD, // tacticians guild
		AGE_WONDER, // the appian way
		AGE_WONDER, // circus maximus
		AGE_WONDER, // the colossus
		AGE_WONDER, // the great library
		AGE_WONDER, // the great lighthouse
		AGE_WONDER, // the hanging gardens
		AGE_WONDER, // the mausoleum
		AGE_WONDER, // piraeus
		AGE_WONDER, // the pyramids
		AGE_WONDER, // the sphinx
		AGE_WONDER, // the statue of zeus
		AGE_WONDER, // the temple of artemis
	};

	extern int cardType[85] =
	{
		BROWN_CARD, // lumber yard
		BROWN_CARD, // logging camp
		BROWN_CARD, // clay pool
		BROWN_CARD, // clay pit
		BROWN_CARD, // quarry
		BROWN_CARD, // stone pit
		GRAY_CARD, // glassworks
		GRAY_CARD, // press
		RED_CARD, // guard tower
		GREEN_CARD, // workshop
		GREEN_CARD, // apothecary
		YELLOW_CARD, // stone reserve
		YELLOW_CARD, // clay reserve
		YELLOW_CARD, // wood reserve
		RED_CARD, // stable
		RED_CARD, // garrison
		RED_CARD, // palisade
		GREEN_CARD, // scriptorium
		GREEN_CARD, // pharmacist
		BLUE_CARD, // theater
		BLUE_CARD, // altar
		BLUE_CARD, // baths
		YELLOW_CARD, // tavern
		BROWN_CARD, // sawmill
		BROWN_CARD, // brickyard
		BROWN_CARD, // shelf quarry
		GRAY_CARD, // glass blower
		GRAY_CARD, // drying room
		RED_CARD, // walls
		YELLOW_CARD, // forum
		YELLOW_CARD, // caravnsery
		YELLOW_CARD, // customs house
		BLUE_CARD, // tribunal
		RED_CARD, // horse breeders
		RED_CARD, // barracks
		RED_CARD, // archery range
		RED_CARD, // parade ground
		GREEN_CARD, // library
		GREEN_CARD, // dispensary
		GREEN_CARD, // school
		GREEN_CARD, // laboratory
		BLUE_CARD, // statue
		BLUE_CARD, // temple
		BLUE_CARD, // aqueduct
		BLUE_CARD, // rostrum
		YELLOW_CARD, // brewery
		RED_CARD, // arsenal
		RED_CARD, // courthouse
		GREEN_CARD, // academy
		GREEN_CARD, // study
		YELLOW_CARD, // chamber of commerce
		YELLOW_CARD, // port
		YELLOW_CARD, // armory
		BLUE_CARD, // palace
		BLUE_CARD, // town hall
		BLUE_CARD, // obelisk
		RED_CARD, // fortifications
		RED_CARD, // siege workshop
		RED_CARD, // circus
		GREEN_CARD, // university
		GREEN_CARD, // observatory 
		BLUE_CARD, // gardens
		BLUE_CARD, // pantheon
		BLUE_CARD, // senate
		YELLOW_CARD, // lighthouse
		YELLOW_CARD, // arena
		GUILD_CARD, // merchants guild
		GUILD_CARD, // shipowners guild
		GUILD_CARD, // builders guild
		GUILD_CARD, // magistrates guild
		GUILD_CARD, // scientists guild
		GUILD_CARD, // moneylenders guild
		GUILD_CARD, // tacticians guild
		WONDER_CARD, // the appian way
		WONDER_CARD, // circus maximus
		WONDER_CARD, // the colossus
		WONDER_CARD, // the great library
		WONDER_CARD, // the great lighthouse
		WONDER_CARD, // the hanging gardens
		WONDER_CARD, // the mausoleum
		WONDER_CARD, // piraeus
		WONDER_CARD, // the pyramids
		WONDER_CARD, // the sphinx
		WONDER_CARD, // the statue of zeus
		WONDER_CARD, // the temple of artemis
	};

	extern int coinCost[85] =
	{
		0, // lumber yard
		1, // logging camp
		0, // clay pool
		1, // clay pit
		0, // quarry
		1, // stone pit
		1, // glassworks
		1, // press
		0, // guard tower
		0, // workshop
		0, // apothecary
		3, // stone reserve
		3, // clay reserve
		3, // wood reserve
		0, // stable
		0, // garrison
		2, // palisade
		2, // scriptorium
		2, // pharmacist
		0, // theater
		0, // altar
		0, // baths
		0, // tavern
		2, // sawmill
		2, // brickyard
		2, // shelf quarry
		0, // glass blower
		0, // drying room
		0, // walls
		3, // forum
		2, // caravnsery
		4, // customs house
		0, // tribunal
		0, // horse breeders
		3, // barracks
		0, // archery range
		0, // parade ground
		0, // library
		0, // dispensary
		0, // school
		0, // laboratory
		0, // statue
		0, // temple
		0, // aqueduct
		0, // rostrum
		0, // brewery
		0, // arsenal
		8, // courthouse
		0, // academy
		0, // study
		0, // chamber of commerce
		0, // port
		0, // armory
		0, // palace
		0, // town hall
		0, // obelisk
		0, // fortifications
		0, // siege workshop
		0, // circus
		0, // university
		0, // observatory 
		0, // gardens
		0, // pantheon
		0, // senate
		0, // lighthouse
		0, // arena
		0, // merchants guild
		0, // shipowners guild
		0, // builders guild
		0, // magistrates guild
		0, // scientists guild
		0, // moneylenders guild
		0, // tacticians guild
		0, // the appian way
		0, // circus maximus
		0, // the colossus
		0, // the great library
		0, // the great lighthouse
		0, // the hanging gardens
		0, // the mausoleum
		0, // piraeus
		0, // the pyramids
		0, // the sphinx
		0, // the statue of zeus
		0, // the temple of artemis
	};

	extern int woodCost[85] =
	{
		0, // lumber yard
		0, // logging camp
		0, // clay pool
		0, // clay pit
		0, // quarry
		0, // stone pit
		0, // glassworks
		0, // press
		0, // guard tower
		0, // workshop
		0, // apothecary
		0, // stone reserve
		0, // clay reserve
		0, // wood reserve
		1, // stable
		0, // garrison
		0, // palisade
		0, // scriptorium
		0, // pharmacist
		0, // theater
		0, // altar
		0, // baths
		0, // tavern
		0, // sawmill
		0, // brickyard
		0, // shelf quarry
		0, // glass blower
		0, // drying room
		0, // walls
		0, // forum
		0, // caravnsery
		0, // customs house
		2, // tribunal
		1, // horse breeders
		0, // barracks
		1, // archery range
		0, // parade ground
		1, // library
		0, // dispensary
		1, // school
		1, // laboratory
		0, // statue
		1, // temple
		0, // aqueduct
		1, // rostrum
		0, // brewery
		2, // arsenal
		0, // courthouse
		1, // academy
		2, // study
		0, // chamber of commerce
		1, // port
		0, // armory
		1, // palace
		2, // town hall
		0, // obelisk
		0, // fortifications
		3, // siege workshop
		0, // circus
		0, // university
		0, // observatory 
		2, // gardens
		1, // pantheon
		0, // senate
		0, // lighthouse
		1, // arena
		1, // merchants guild
		0, // shipowners guild
		1, // builders guild
		2, // magistrates guild
		2, // scientists guild
		2, // moneylenders guild
		0, // tacticians guild
		0, // the appian way
		1, // circus maximus
		0, // the colossus
		3, // the great library
		1, // the great lighthouse
		2, // the hanging gardens
		0, // the mausoleum
		2, // piraeus
		0, // the pyramids
		0, // the sphinx
		1, // the statue of zeus
		1, // the temple of artemis
	};

	extern int stoneCost[85] =
	{
		0, // lumber yard
		0, // logging camp
		0, // clay pool
		0, // clay pit
		0, // quarry
		0, // stone pit
		0, // glassworks
		0, // press
		0, // guard tower
		0, // workshop
		0, // apothecary
		0, // stone reserve
		0, // clay reserve
		0, // wood reserve
		0, // stable
		0, // garrison
		0, // palisade
		0, // scriptorium
		0, // pharmacist
		0, // theater
		0, // altar
		1, // baths
		0, // tavern
		0, // sawmill
		0, // brickyard
		0, // shelf quarry
		0, // glass blower
		0, // drying room
		2, // walls
		0, // forum
		0, // caravnsery
		0, // customs house
		0, // tribunal
		0, // horse breeders
		0, // barracks
		1, // archery range
		0, // parade ground
		1, // library
		1, // dispensary
		0, // school
		0, // laboratory
		0, // statue
		0, // temple
		3, // aqueduct
		1, // rostrum
		0, // brewery
		0, // arsenal
		0, // courthouse
		1, // academy
		0, // study
		0, // chamber of commerce
		0, // port
		2, // armory
		1, // palace
		3, // town hall
		2, // obelisk
		2, // fortifications
		0, // siege workshop
		2, // circus
		0, // university
		1, // observatory 
		0, // gardens
		0, // pantheon
		1, // senate
		0, // lighthouse
		1, // arena
		0, // merchants guild
		1, // shipowners guild
		2, // builders guild
		0, // magistrates guild
		0, // scientists guild
		2, // moneylenders guild
		2, // tacticians guild
		2, // the appian way
		2, // circus maximus
		0, // the colossus
		0, // the great library
		1, // the great lighthouse
		0, // the hanging gardens
		0, // the mausoleum
		1, // piraeus
		3, // the pyramids
		1, // the sphinx
		1, // the statue of zeus
		1, // the temple of artemis
	};

	extern int clayCost[85] =
	{
		0, // lumber yard
		0, // logging camp
		0, // clay pool
		0, // clay pit
		0, // quarry
		0, // stone pit
		0, // glassworks
		0, // press
		0, // guard tower
		0, // workshop
		0, // apothecary
		0, // stone reserve
		0, // clay reserve
		0, // wood reserve
		0, // stable
		1, // garrison
		0, // palisade
		0, // scriptorium
		0, // pharmacist
		0, // theater
		0, // altar
		0, // baths
		0, // tavern
		0, // sawmill
		0, // brickyard
		0, // shelf quarry
		0, // glass blower
		0, // drying room
		0, // walls
		1, // forum
		0, // caravnsery
		0, // customs house
		0, // tribunal
		1, // horse breeders
		0, // barracks
		0, // archery range
		2, // parade ground
		0, // library
		2, // dispensary
		0, // school
		0, // laboratory
		2, // statue
		0, // temple
		0, // aqueduct
		0, // rostrum
		0, // brewery
		3, // arsenal
		0, // courthouse
		0, // academy
		0, // study
		0, // chamber of commerce
		0, // port
		0, // armory
		1, // palace
		0, // town hall
		0, // obelisk
		1, // fortifications
		0, // siege workshop
		2, // circus
		1, // university
		0, // observatory 
		2, // gardens
		1, // pantheon
		2, // senate
		2, // lighthouse
		1, // arena
		1, // merchants guild
		1, // shipowners guild
		1, // builders guild
		1, // magistrates guild
		2, // scientists guild
		0, // moneylenders guild
		1, // tacticians guild
		2, // the appian way
		0, // circus maximus
		3, // the colossus
		0, // the great library
		0, // the great lighthouse
		0, // the hanging gardens
		2, // the mausoleum
		1, // piraeus
		0, // the pyramids
		1, // the sphinx
		1, // the statue of zeus
		0, // the temple of artemis
	};

	extern int papyrusCost[85] =
	{
		0, // lumber yard
		0, // logging camp
		0, // clay pool
		0, // clay pit
		0, // quarry
		0, // stone pit
		0, // glassworks
		0, // press
		0, // guard tower
		1, // workshop
		0, // apothecary
		0, // stone reserve
		0, // clay reserve
		0, // wood reserve
		0, // stable
		0, // garrison
		0, // palisade
		0, // scriptorium
		0, // pharmacist
		0, // theater
		0, // altar
		0, // baths
		0, // tavern
		0, // sawmill
		0, // brickyard
		0, // shelf quarry
		0, // glass blower
		0, // drying room
		0, // walls
		0, // forum
		1, // caravnsery
		0, // customs house
		0, // tribunal
		0, // horse breeders
		0, // barracks
		1, // archery range
		0, // parade ground
		0, // library
		0, // dispensary
		2, // school
		0, // laboratory
		0, // statue
		1, // temple
		0, // aqueduct
		0, // rostrum
		0, // brewery
		0, // arsenal
		0, // courthouse
		0, // academy
		1, // study
		2, // chamber of commerce
		1, // port
		0, // armory
		0, // palace
		0, // town hall
		0, // obelisk
		1, // fortifications
		0, // siege workshop
		0, // circus
		1, // university
		2, // observatory 
		0, // gardens
		2, // pantheon
		1, // senate
		0, // lighthouse
		0, // arena
		1, // merchants guild
		1, // shipowners guild
		0, // builders guild
		1, // magistrates guild
		0, // scientists guild
		0, // moneylenders guild
		1, // tacticians guild
		1, // the appian way
		0, // circus maximus
		0, // the colossus
		1, // the great library
		2, // the great lighthouse
		1, // the hanging gardens
		1, // the mausoleum
		0, // piraeus
		1, // the pyramids
		0, // the sphinx
		2, // the statue of zeus
		1, // the temple of artemis
	};

	extern int glassCost[85] =
	{
		0, // lumber yard
		0, // logging camp
		0, // clay pool
		0, // clay pit
		0, // quarry
		0, // stone pit
		0, // glassworks
		0, // press
		0, // guard tower
		0, // workshop
		1, // apothecary
		0, // stone reserve
		0, // clay reserve
		0, // wood reserve
		0, // stable
		0, // garrison
		0, // palisade
		0, // scriptorium
		0, // pharmacist
		0, // theater
		0, // altar
		0, // baths
		0, // tavern
		0, // sawmill
		0, // brickyard
		0, // shelf quarry
		0, // glass blower
		0, // drying room
		0, // walls
		0, // forum
		1, // caravnsery
		0, // customs house
		1, // tribunal
		0, // horse breeders
		0, // barracks
		0, // archery range
		1, // parade ground
		1, // library
		0, // dispensary
		0, // school
		2, // laboratory
		0, // statue
		0, // temple
		0, // aqueduct
		0, // rostrum
		0, // brewery
		0, // arsenal
		0, // courthouse
		2, // academy
		1, // study
		0, // chamber of commerce
		1, // port
		1, // armory
		2, // palace
		0, // town hall
		1, // obelisk
		0, // fortifications
		1, // siege workshop
		0, // circus
		1, // university
		0, // observatory 
		0, // gardens
		0, // pantheon
		0, // senate
		1, // lighthouse
		0, // arena
		1, // merchants guild
		1, // shipowners guild
		1, // builders guild
		0, // magistrates guild
		0, // scientists guild
		0, // moneylenders guild
		0, // tacticians guild
		0, // the appian way
		1, // circus maximus
		1, // the colossus
		1, // the great library
		0, // the great lighthouse
		1, // the hanging gardens
		2, // the mausoleum
		0, // piraeus
		0, // the pyramids
		2, // the sphinx
		0, // the statue of zeus
		1, // the temple of artemis
	};

}







