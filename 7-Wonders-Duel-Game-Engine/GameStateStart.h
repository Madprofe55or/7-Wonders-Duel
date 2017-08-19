#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>

#include "GameState.h"

class GameStateStart : public GameState
{
public:
	// Sprites
	sf::Sprite background;
	sf::Sprite title;
	
	// Fonts
	sf::Font font;

	// Texts
	sf::Text startGameText;
	sf::Text exitGameText;
	
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	bool mRotating = false;

	int mRotatingSpeed = 1;

	GameStateStart(Game * game);
	// destructor not needed
	~GameStateStart() {};
private:

};

#endif // GAMESTATESTART_H

