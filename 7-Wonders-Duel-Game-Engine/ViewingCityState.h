#ifndef VIEWINGCITYSTATE_H
#define VIEWINGCITYSTATE_H

#include "SFML\Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"

class ViewingCityState : public GameState
{
public:
	GamePlayingState * p_GamePlayingState;
	
	
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	void deleteSprites();

	sf::Text cityViewTitle;

	vector<sf::Sprite*> mCityCardSprites;
	vector<sf::FloatRect*> mCardRects;

	sf::Sprite mouseoverCard;

	sf::RectangleShape rectMainArea;

	sf::Vector2f MAIN_AREA_SIZE = { 800, 450 };

	bool mouseover = false;

	ViewingCityState(Game * game, GamePlayingState * gameplayingstate);
	// destructor not needed
	~ViewingCityState() {};
};

#endif // VIEWINGCITYSTATE.H

