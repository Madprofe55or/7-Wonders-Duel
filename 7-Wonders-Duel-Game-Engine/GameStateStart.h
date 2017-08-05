#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>

#include "GameState.h"

class GameStateStart : public GameState
{
public:
	sf::Sprite background;
	sf::Sprite title;
	sf::Font font;

	sf::Text startGameText;
	sf::Text exitGameText;
	
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput(Game * game);

	GameStateStart(Game * game);
	~GameStateStart();
private:

};

#endif // GAMESTATESTART_H

