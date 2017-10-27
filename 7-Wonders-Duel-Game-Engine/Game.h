#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Game_Constants.h"
#include "World.h"

class GameState;

/* Defines render window, texture manager, font manager, input manager, state manager functions
   and the main game loop, to be used for the rest of the game objects .
   Still needs a sounds/music manager, which would be simple. */
class Game
{
public:
	// game state stack
	std::stack<GameState*> states;

	// SFML objects
	sf::RenderWindow window;
	TextureManager textureManager;
	FontManager fontManager;
	InputManager inputManager;
	SoundManager soundManager;
	
	// 7 Wonders game world object (see 7_Wonders::World.h for interface)
	World world;

	// State manager functions
	void pushState(GameState * state);
	void popState();
	void changeState(GameState * state);
	GameState* peekState();

	// Game loop function
	void gameLoop();

	Game();
	~Game();
private:
	void loadTextures();
	void loadFonts();
	void loadSounds();
};

#endif // GAME_H
