#include "FontManager.h"

void FontManager::loadFont(const std::string & name, const std::string & fileName)
{
	sf::Font font;
	font.loadFromFile(fileName);

	this->fontMap[name] = font;
}

sf::Font & FontManager::getRef(const std::string & font)
{
	return this->fontMap.at(font);
}
