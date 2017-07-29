#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>

#include "GameState.h"

class GameStateStart : public GameState
{
public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateStart(Game * game);
	~GameStateStart();
private:
	//sf::View view;
};

#endif // GAMESTATESTART_H

