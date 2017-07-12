#ifndef WONDERDECK_H
#define WONDERDECK_H

#include <iostream>
#include <string>
#include "Wonders.h"
#include <vector>
#include <iterator> //for ostream iterator to print out components of vector to be sure shuffle of cards work can be deleted

class WonderDeck
{
public:
	//create deck of wonder cards, will have to also implement creation of asset when the constructor is called or already have on gameboard
	WonderDeck()
	{
		for (int i = 0; i < 12; i++)
		{
			Wonder wonder(i);
			WonderCardDeck.push_back(wonder);
			shuffleWonderDeck();

		};

	}

	//shuffle wonderDeck, location corresponds to the location of the cards in the deck
	void shuffleWonderDeck()
	{
		for (int i = 0; i < 11; i++)
		{
			int location = rand() % 11 + 1;
			ShuffledWonderDeck.push_back(WonderCardDeck[location]);
		}

		//Print path of cards to console
		std::copy(ShuffledWonderDeck.begin(), ShuffledWonderDeck.end(), std::ostream_iterator<Wonder>(std::cout, " "));


	}

	std::vector <Wonder> WonderCardDeck;
	std::vector <Wonder> ShuffledWonderDeck;


private:







};

#endif #pragma once
