//#ifndef WONDERS_H
//#define WONDERS_H
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//class Wonder
//{
//
//public:
//	Wonder::Wonder(int i)
//	{
//		std::string WonderName = VectorWonderName[i];
//		int brickCost = VectorbrickCost[i];
//		int glassCost = VectorglassCost[i];
//		int papyrusCost = VectorpapyrusCost[i];
//		int stoneCost = VectorstoneCost[i];
//		int woodCost = VectorwoodCost[i];
//
//		std::cout << WonderName << " was added to the Wonders deck "
//			<< "with the following attributes-> \n Brick Cost: " << brickCost << " \n Glass Cost: " << glassCost << "\n Papyrus Cost: " << papyrusCost << "\n Stone Cost: " << stoneCost << "\n Wood Cost: " << woodCost << std::endl;
//	}
//
//	//Vectors to Store Name and Building Costs for each Wonder 
//	std::vector <std::string> VectorWonderName = { "The Appian Way", //Position 0
//		"Circus Maximus",	//Position 1
//		"The Colossuss",	//Position 2
//		"The Great Library", //Position 3
//		"The Great Lighthouse", //Position 4
//		"The Hanging Gardens", //Position 5
//		"The Mausoleum",		//Position 6
//		"Piraeus",          //Position 7
//		"The Pyramids",		//Position 8
//		"The Sphinx",		//Position 9
//		"The Statue of Zeus",	//Position 10
//		"The Temple of Artemis" };	//Position 11
//
//	std::vector <int> VectorbrickCost = { 2, //Appian Way Brick Cost 2
//		0, //Circus Maximus Brick Cost 0
//		3, //Colossus Brick Cost 3
//		0, //Great Library Brick Cost 0
//		0, //Great Lighthouse Brick Cost 0
//		0, //Hanging Gardens Brick Cost 0
//		2, //Masoleum Brick Cost 2
//		1, //Piraeus Brick Cost 1
//		0, //The Pyramids Brick Cost 0
//		1, //Sphinx Brick Cost 1
//		1, //Statue of Zeus Brick Cost 1
//		0 }; //Temple of Artemis Brick Cost 0
//
//	std::vector <int> VectorglassCost = { 0, //Appian Way Glass Cost 0
//		1, //Circus Maximus Glass Cost 1
//		1, //Colossus Glass Cost 1
//		1, //Great Library Glass Cost 1
//		0, //Great Lighthouse Glass Cost 0
//		1, //Hanging Gardens Glass Cost 1
//		2, //Masoleum Glass Cost 2
//		0, //Piraeus Glass Cost 0
//		0, //The Pyramids Glass Cost 0
//		2, //Sphinx Glass Cost 2
//		0, //Statue of Zeus Glass Cost 0
//		1 }; //Temple of Artemis Glass Cost 1
//
//	std::vector <int> VectorpapyrusCost = { 1, //Appian Way Pap Cost 1
//		0, //Circus Maximus Pap Cost 0
//		0, //Colossus Pap Cost 0
//		0, //Great Library Pap Cost 0
//		2, //Great Lighthouse Pap Cost 2
//		1, //Hanging Gardens Pap Cost 1
//		1, //Masoleum Pap Cost 1
//		0, //Piraeus Pap Cost 0
//		1, //The Pyramids Pap Cost 1
//		1, //Sphinx Pap Cost 1
//		2, //Statue of Zeus Pap Cost 2
//		1 }; //Temple of Artemis Brick Cost 1
//
//	std::vector <int> VectorstoneCost = { 2, //Appian Way Stone Cost 2
//		2, //Circus Maximus Stone Cost 2
//		0, //Colossus Stone Cost 0
//		0, //Great Library Stone Cost 0
//		1, //Great Lighthouse Stone Cost 1
//		0, //Hanging Gardens Stone Cost 0
//		0, //Masoleum Stone Cost 0
//		1, //Piraeus Stone Cost 1
//		3, //The Pyramids Stone Cost 3
//		1, //Sphinx Stone Cost 1
//		1, //Statue of Zeus Stone Cost 1
//		1 }; //Temple of Artemis Stone Cost 1
//
//	std::vector <int> VectorwoodCost = { 0, //Appian Way Wood Cost 0
//		1, //Circus Maximus Wood Cost 1
//		0, //Colossus Wood Cost 0
//		3, //Great Library Wood Cost 3
//		1, //Great Lighthouse Wood Cost 1
//		2, //Hanging Gardens Wood Cost 2
//		0, //Masoleum Wood Cost 0
//		2, //Piraeus Wood Cost 2
//		0, //The Pyramids Wood Cost 0
//		0, //Sphinx Wood Cost 0
//		1, //Statue of Zeus Wood Cost 1
//		1 }; //Temple of Artemis Wood Cost 1
//
//
//			 //Effects of each Wonder when Built
//
//			 //Storage of victory points effect for building wonder
//
//	std::vector <int> VectorvictoryPoints = { 3, //Appian Way V Points 3
//		3, //Circus Maximus V Points 3
//		3, //Colossus V Points 3
//		4, //Great Library V Points 4
//		4, //Great Lighthouse V Points 4
//		3, //Hanging Gardens V Points 3
//		2, //Mausoleum V Points 2
//		2, //Piraeus V Points 2
//		9, //The Pyramids V Points 9
//		6, //Sphinx V Points 6
//		3, //Statue of Zeus V Points 3
//		0 }; //Temple of Artemis v points 0
//
//			 //Storage of military token movement for building wonder, need function to handle
//			 //this number and change location of the military token
//
//	std::vector <int> militaryToken = { 0, //Appian Way Military Points 0
//		1, //Circus Maximus Military Points 1
//		2, //Colossus Mil Points 2
//		0, //Great Library Mil Points 0
//		0, //Great Lighthouse Mil Points 0
//		0, //Hanging Gardens Mil Points 0
//		0, //Mausoleum Mil Points 0
//		0, //Piraeus Mil Points 0
//		0, //The Pyramids Mil Points 0
//		0, //Sphinx Mil Points 0
//		1, //Statue of Zeus Mil Points 1
//		0 }; //Temple of Artemis Mil points 0
//
//			 //Storage if turn is repeated after building wonder
//			 //Need to create a function to check if true when built and keep players turn 
//			 //who built the wonder
//
//	std::vector <bool> repeatTurn = { true, //Appian Way True
//		false, //Circus Maximus false
//		false, //Colossus false
//		false, //Great Library false
//		false, //Great Lighthouse false
//		true, //Hanging Gardens true
//		false, //Mausoleum false
//		true, //Piraeus true
//		false, //The Pyramids false
//		true, //Sphinx true
//		false, //Statue of Zeus false
//		true }; //Temple of Artemis 
//
//
//				//store values of Wonders effect for gaining gold
//	std::vector <int> goldBonus = { 3, //Appian Way 3
//		0, //Circus Maximus 0
//		0, //Colossus 0
//		0, //Great Library 0
//		0, //Great Lighthouse 0
//		6, //Hanging Gardens 6
//		0, //Mausoleum 0
//		0, //Piraeus 0
//		0, //The Pyramids 0
//		0, //Sphinx Mil Points 0
//		0, //Statue of Zeus 0
//		12 }; //Temple of Artemis 12
//
//			  //store values of Wonders effect on opponents gold pot
//
//	std::vector <int> takeGold = { -3, //Appian Way Military -3
//		0, //Circus Maximus 0
//		0, //Colossus 0
//		0, //Great Library 0
//		0, //Great Lighthouse 0
//		0, //Hanging Gardens 0
//		0, //Mausoleum 0
//		0, //Piraeus 0
//		0, //The Pyramids 0
//		0, //Sphinx Mil 0
//		0, //Statue of Zeus 0
//		0 }; //Temple of Artemis 0
//
//			 //store true or false if player can destroy a gray card from opponent when wonder is built
//	std::vector <bool> destroyGrayCard = { false, //Appian Way false
//		true, //Circus Maximus true
//		false, //Colossus false
//		false, //Great Library false
//		false, //Great Lighthouse false
//		false, //Hanging Gardens false
//		false, //Mausoleum false
//		false, //Piraeus false
//		false, //The Pyramids false
//		false, //Sphinx Mil false
//		false, //Statue of Zeus false
//		false }; //Temple of Artemis false
//
//				 //store true or false if player can destroy a brown card from opponent when wonder is built
//	std::vector <bool> destroyBrownCard = { false, //Appian Way false
//		false, //Circus Maximus false
//		false, //Colossus false
//		false, //Great Library false
//		false, //Great Lighthouse false
//		false, //Hanging Gardens false
//		false, //Mausoleum false
//		false, //Piraeus false
//		false, //The Pyramids false
//		false, //Sphinx Mil false
//		true, //Statue of Zeus true
//		false }; //Temple of Artemis false
//
//				 //store true or false if player can bring a card back into play that was discarded
//				 //need to store locations of cards and set a true value for a function from this to put card into players hand
//	std::vector <bool> resurrectCard = { false, //Appian Way false
//		false, //Circus Maximus false
//		false, //Colossus false
//		false, //Great Library false
//		false, //Great Lighthouse false
//		false, //Hanging Gardens false
//		true, //Mausoleum true
//		false, //Piraeus false
//		false, //The Pyramids false
//		false, //Sphinx Mil false
//		false, //Statue of Zeus false
//		false }; //Temple of Artemis false
//
//				 //store true or false if player can bring a progress token into play that was discarded at start of game
//				 //need to store locations of cards and set a true value for a function from this to put card into players hand
//	std::vector <bool> resurrectProgressToken = { false, //Appian Way false
//		false, //Circus Maximus false
//		false, //Colossus false
//		true, //Great Library true
//		false, //Great Lighthouse false
//		false, //Hanging Gardens false
//		false, //Mausoleum true
//		false, //Piraeus false
//		false, //The Pyramids false
//		false, //Sphinx Mil false
//		false, //Statue of Zeus false
//		false }; //Temple of Artemis false
//
//				 //need to figure out how to store and use values for Piraues and the Great Lighthouse which allow
//				 //an additional resource to be used each turn
//
//
//};
//
//
//
//
//
//#endif 