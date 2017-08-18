#ifndef CARDPICKERSTATE_H
#define CARDPICKERSTATE_H

#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"

class CardPickerState : public GameState
{
public:
	
	sf::RectangleShape testRectangle;
	sf::Text testCardText;
	sf::Text textCardName;
	sf::Text textResourcesTitle;

	sf::Vector2f const CARD_GUI_SIZE = { 600, 400 };

	sf::Sprite testCard;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	CardPickerState(Game * game, GamePlayingState * gameplayingstate, Seven_Wonders::Card * card);

	GamePlayingState * p_GamePlayingState;
	
	
	
	// Don't need destructor
	~CardPickerState() {};
};

#endif // CARDPICKERSTATE_H

