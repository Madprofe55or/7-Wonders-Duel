#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"

// Adds a state on top of state stack
void Game::pushState(GameState * state)
{
	this->states.push(state);
}

// Removes a state from the top of state stack
void Game::popState()
{
	delete this->states.top();
	this->states.pop();
}

// Removes a state from the top of state stack (if there is one) and adds another state
void Game::changeState(GameState * state)
{
	if (!this->states.empty())
		popState();
	pushState(state);
}

// Returns pointer to top state, if there is one
GameState * Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time timeElapsed = clock.restart();
		float dt = timeElapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput(this);
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	// Loading textures, but should probably be done depending on state
	this->loadTextures();
	
	// Loading fonts
	this->loadFonts();
	
	// Creating the window
	this->window.create(sf::VideoMode(1600, 900), "7 Wonders Duel", sf::Style::Titlebar | sf::Style::Close);
	this->window.setFramerateLimit(60);

}

Game::~Game()
{
	// Will remove states one at a time from stack until empty
	while (!this->states.empty()) popState();
}

void Game::loadTextures()
{
	textureManager.loadTexture("GameStateStart Background", "Resources/Backgrounds/gamestartbackground.jpg");
	textureManager.loadTexture("GameStateStart Title", "Resources/Backgrounds/gamestarttitle.png");
	textureManager.loadTexture("GameStatePlaying Background", "Resources/Backgrounds/gameplayingbackground.jpg");
}

void Game::loadFonts()
{
	fontManager.loadFont("Menu Font", "Resources/Fonts/americancaptain.ttf");
}




