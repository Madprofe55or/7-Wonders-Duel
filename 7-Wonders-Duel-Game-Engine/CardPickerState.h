#ifndef CARDPICKERSTATE_H
#define CARDPICKERSTATE_H

#include "SFML/Graphics.hpp"

#include "GameState.h"
#include "GamePlayingState.h"
//#include "NewAgeChoosePlayerState.h"
//#include "WonderBuildingState.h"

class CardPickerState : public GameState
{
public:
	
	sf::RectangleShape testRectangle;
	sf::RectangleShape testRectangle2;
	sf::RectangleShape buildRectangle;
	sf::RectangleShape discardRectangle;
	sf::RectangleShape buildWonderRectangle;


	// Texts
	sf::Text textCardName;
	sf::Text textResourcesTitle;
	sf::Text textCostHeader;
	sf::Text textCoinCost;
	sf::Text textWoodCost;
	sf::Text textStoneCost;
	sf::Text textClayCost;
	sf::Text textPapyrusCost;
	sf::Text textGlassCost;

	sf::Text textCoinCostNum;
	sf::Text textWoodCostNum;
	sf::Text textStoneCostNum;
	sf::Text textClayCostNum;
	sf::Text textPapyrusCostNum;
	sf::Text textGlassCostNum;

	sf::Text textBuild;
	sf::Text textDiscard;
	sf::Text textDiscardValue;
	sf::Text textBuildWonder;


	// Sprites
	sf::Sprite cardToDisplay;

	// Sounds
	sf::Sound discardCardSound;



	sf::Vector2f const CARD_GUI_SIZE = { 600, 400 };
	sf::Vector2f const CARD_GUI_SIZE_2 = { 600, 50 };
	sf::Vector2f const BUTTON_SIZE = { 150, 50 };

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	CardPickerState(Game * game, GamePlayingState * gameplayingstate, Seven_Wonders::Card * card);

	void removeStateAfterWonderBuild();

	void removeStateAfterAgePlayerPick();


	GamePlayingState * p_GamePlayingState;
	Card * p_card;
	bool canBuildCard;
	bool builtWonder = false;
	bool playerChosen = false;

	
	// Don't need destructor
	~CardPickerState() {};
};

#endif // CARDPICKERSTATE_H

