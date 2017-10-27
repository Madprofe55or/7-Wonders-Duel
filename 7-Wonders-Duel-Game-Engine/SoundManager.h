#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>
#include <map>

#include "SFML/Audio.hpp"

class SoundManager
{
public:
	void loadSound(const std::string & name, const std::string & fileName);
	sf::SoundBuffer getRef(const std::string & sound);

	SoundManager() {};
	~SoundManager() {};

	std::map <std::string, sf::SoundBuffer> soundMap;

private:

};

#endif // SOUNDMANAGER_H

