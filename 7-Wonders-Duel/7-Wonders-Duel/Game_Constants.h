// 7 Wonders Duel
// Game Constants header

#pragma once

#include <vector>
#include <float.h>

namespace Seven_Wonders {

	// Defining players
	const int PLAYER_1 = 1;
	const int PLAYER_2 = 2;
	const int BOARD = 0;


	// Defining conflict pawn-related values
	const int P1_LOSES_TWO_GOLD = -2;
	const int P1_LOSES_FIVE_GOLD = -5;
	const int P2_LOSES_TWO_GOLD = 2;
	const int P2_LOSES_FIVE_GOLD = 5;
	const int P1_WINS_MILITARY_VICTORY = 9;
	const int P2_WINS_MILITARY_VICTORY = -9;
	const int NO_CONFLICT_EFFECT = 0;


	// Defining cards properties
	// Card types
	const int BROWN_CARD = 1;
	const int GRAY_CARD = 2;
	const int YELLOW_CARD = 3;
	const int GREEN_CARD = 4;
	const int BLUE_CARD = 5;
	const int RED_CARD = 6;
	const int GUILD_CARD = 7;
	const int WONDER_CARD = 8;
	// Card ages
	const int AGE_1 = 1;
	const int AGE_2 = 2;
	const int AGE_3 = 3;
	const int AGE_GUILD = 4;
	const int AGE_WONDER = 5;


	// Card indices
	// Age 1
	const int CARD_LUMBER_YARD = 0;
	const int CARD_LOGGING_CAMP = 1;
	const int CARD_CLAY_POOL = 2;
	const int CARD_CLAY_PIT = 3;
	const int CARD_QUARRY = 4;
	const int CARD_STONE_PIT = 5;
	const int CARD_GLASSWORKS = 6;
	const int CARD_PRESS = 7;
	const int CARD_GUARD_TOWER = 8;
	const int CARD_WORKSHOP = 9;
	const int CARD_APOTHECARY = 10;
	const int CARD_STONE_RESERVE = 11;
	const int CARD_CLAY_RESERVE = 12;
	const int CARD_WOOD_RESERVE = 13;
	const int CARD_STABLE = 14;
	const int CARD_GARRISON = 15;
	const int CARD_PALISADE = 16;
	const int CARD_SCRIPTORIUM = 17;
	const int CARD_PHARMACIST = 18;
	const int CARD_THEATER = 19;
	const int CARD_ALTAR = 20;
	const int CARD_BATHS = 21;
	const int CARD_TAVERN = 22;
	// Age 2
	const int CARD_SAWMILL = 23;
	const int CARD_BRICKYARD = 24;
	const int CARD_SHELF_QUARRY = 25;
	const int CARD_GLASS_BLOWER = 26;
	const int CARD_DRYING_ROOM = 27;
	const int CARD_WALLS = 28;
	const int CARD_FORUM = 39;
	const int CARD_CARAVANSERY = 30;
	const int CARD_CUSTOMS_HOUSE = 31;
	const int CARD_TRIBUNAL = 32;
	const int CARD_HORSE_BREEDERS = 33;
	const int CARD_BARRACKS = 34;
	const int CARD_ARCHERY_RANGE = 35;
	const int CARD_PARADE_GROUND = 36;
	const int CARD_LIBRARY = 37;
	const int CARD_DISPENSARY = 38;
	const int CARD_SCHOOL = 39;
	const int CARD_LABORATORY = 40;
	const int CARD_STATUE = 41;
	const int CARD_TEMPLE = 42;
	const int CARD_AQUEDUCT = 43;
	const int CARD_ROSTRUM = 44;
	const int CARD_BREWERY = 45;
	// Age 3
	const int CARD_ARSENAL = 46;
	const int CARD_COURTHOUSE = 47;
	const int CARD_ACADEMY = 48;
	const int CARD_STUDY = 49;
	const int CARD_CHAMBER_OF_COMMERCE = 50;
	const int CARD_PORT = 51;
	const int CARD_ARMORY = 52;
	const int CARD_PALACE = 53;
	const int CARD_TOWN_HALL = 54;
	const int CARD_OBELISK = 55;
	const int CARD_FORTIFICATIONS = 56;
	const int CARD_SIEGE_WORKSHOP = 57;
	const int CARD_CIRCUS = 58;
	const int CARD_UNIVERSITY = 59;
	const int CARD_OBSERVATORY = 60;
	const int CARD_GARDENS = 61;
	const int CARD_PANTHEON = 62;
	const int CARD_SENATE = 63;
	const int CARD_LIGHTHOUSE = 64;
	const int CARD_ARENA = 65;
	// Guilds
	const int CARD_MERCHANTS_GUILD = 66;
	const int CARD_SHIPOWNERS_GUILD = 67;
	const int CARD_BUILDERS_GUILD = 68;
	const int CARD_MAGISTRATES_GUILD = 69;
	const int CARD_SCIENTISTS_GUILD = 70;
	const int CARD_MONEYLENDERS_GUILD = 71;
	const int CARD_TACTICIANS_GUILD = 72;
	// Wonders, in order of manual p 17
	const int CARD_THE_APPIAN_WAY = 73;
	const int CARD_CIRCUS_MAXIMUS = 74;
	const int CARD_THE_COLOSSUS = 75;
	const int CARD_THE_GREAT_LIBRARY = 76;
	const int CARD_THE_GREAT_LIGHTHOUSE = 77;
	const int CARD_THE_HANGING_GARDENS = 78;
	const int CARD_THE_MAUSOLEUM = 79;
	const int CARD_PIRAEUS = 80;
	const int CARD_THE_PYRAMIDS = 81;
	const int CARD_THE_SPHINX = 82;
	const int CARD_THE_STATUE_OF_ZEUS = 83;
	const int CARD_THE_TEMPLE_OF_ARTEMIS = 84;

	// Green Card Science Symbols
	const int SCIENCE_SYMBOL_NONE = 0;
	const int SCIENCE_SYMBOL_GLOBE = 1;
	const int SCIENCE_SYMBOL_BALANCE = 2;
	const int SCIENCE_SYMBOL_TABLET = 3;
	const int SCIENCE_SYMBOL_MORTAR = 4;
	const int SCIENCE_SYMBOL_ARCH = 5;
	const int SCIENCE_SYMBOL_QUILL = 6;
	const int SCIENCE_SYMBOL_WHEEL = 7;

	// Game Properties
	const int GAME_WINDOW_WIDTH = 1600;
	const int GAME_WINDOW_HEIGHT = 900;

	// Card Sizes
	const std::vector<int> CARD_SIZE = { 110, 175 };
	const std::vector<int> WONDER_SIZE = { 110, 175 };
	const int progressTokenRadius= 100;

	// Card Positioning
	const int CARD_STRUCTURE_VERT_CENTER = 770;
	const int CARD_STRUCTURE_VERT_SPACING = 30;
	const int CARD_STRUCTURE_HORZ_SPACING = 98;
	const int CARD_STRUCTURE_AGE_1_START_X = 635;
	const int CARD_STRUCTURE_AGE_1_START_Y = 150;
	const std::vector<float> START_POSITION = { -400.0f,-400.0f };

	//Progress Tokens Positioning
	const std::vector<std::vector<int>> PROGRESS_TOKEN_POSITIONS = {
		{ 400, 200 }, 
		{ 600, 200 },
		{ 800, 200 },

		{ 500, 450 },
		{ 700, 450 },

	};


	const std::vector<std::vector<int>> WONDER_POSITIONS_1 = {
		{ 200, 80 }, // card 1 (top left)
		{ 800, 80 },

		{ 200, 450 },
		{ 800, 450 },

	};

	const std::vector<std::vector<float>> AGE_1_POSITIONS = {
		{ 635, 150 }, // card 1 (top left)
		{ 785, 150 },
 
		{ 560, 263 },
		{ 710, 263 },
		{ 860, 263 },

		{ 485, 376 },
		{ 635, 376 },
		{ 785, 376 },
		{ 935, 376 },

		{ 410, 489 },
		{ 560, 489 },
		{ 710, 489 },
		{ 860, 489 },
		{ 1010, 489 },

		{ 335, 602 },
		{ 485, 602 },
		{ 635, 602 },
		{ 785, 602 },
		{ 935, 602 },
		{ 1085, 602 }, // card 20 (bottom right)
	};

	const std::vector<std::vector<float>> AGE_2_POSITIONS = {
		{ 335, 150 }, // card 1 (top left)
		{ 485, 150 },
		{ 635, 150 },
		{ 785, 150 },
		{ 935, 150 },
		{ 1085, 150 },

		{ 410, 263 },
		{ 560, 263 },
		{ 710, 263 },
		{ 860, 263 },
		{ 1010, 263 },

		{ 485, 376 },
		{ 635, 376 },
		{ 785, 376 },
		{ 935, 376 },

		{ 560, 489 },
		{ 710, 489 },
		{ 860, 489 },

		{ 635, 602 },
		{ 785, 602 }, // card 20 (bottom right)

	};

	const std::vector<std::vector<float>> AGE_3_POSITIONS = {
		{ 635, 80 }, // card 1 (top left)
		{ 785, 80 },

		{ 560, 170 },
		{ 710, 170 },
		{ 860, 170 },

		{ 485, 260 },
		{ 635, 260 },
		{ 785, 260 },
		{ 935, 260 },

		{ 560, 350 },
		{ 860, 350 },

		{ 485, 440 },
		{ 635, 440 },
		{ 785, 440 },
		{ 935, 440 },

		{ 560, 530 },
		{ 710, 530 },
		{ 860, 530 },

		{ 635, 620 },
		{ 785, 620 },

	};

	// Game Textures


	// Game Fonts


	// Game Sounds/Music
}
