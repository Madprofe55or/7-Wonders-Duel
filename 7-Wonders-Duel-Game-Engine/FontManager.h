#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <string>
#include <map>

#include "SFML/Graphics.hpp"


class FontManager
{
public:
	// Adds a font from a file
	void loadFont(const std::string & name, const std::string & fileName);

	// Get a font by passing an id
	sf::Font& getRef(const std::string & font);

	FontManager() {};
	~FontManager() {};

private:
	std::map <std::string, sf::Font> fontMap;
};

#endif // FONTMANAGER_H

