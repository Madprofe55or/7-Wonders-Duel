#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"

class GameState;

class Game
{
public:
	std::stack<GameState*> states;

	sf::RenderWindow window;
	TextureManager textureManager;
	FontManager fontManager;
	InputManager inputManager;

	void pushState(GameState * state);
	void popState();
	void changeState(GameState * state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
private:
	void loadTextures();
	void loadFonts();
};

#endif // GAME_H
