#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"

class GameState;

/* Defines render window, texture manager, font manager, input manager, state manager functions
   and the main game loop, to be used for the rest of the game objects .
   Still needs a sounds/music manager, which would be simple. */
class Game
{
public:
	// game state stack
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
