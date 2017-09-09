#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class AssetsManager
{
private:
	sf::SoundBuffer hitBuffer;
	sf::SoundBuffer wingBuffer;
	sf::SoundBuffer pointBuffer;
public:
	sf::Texture backgroundTexture;
	sf::Texture birdTexture;
	sf::Texture upperPipeTexture;
	sf::Texture bottomPipeTexture;
	sf::Texture splashTexture;
	sf::Texture groundTexture;

	sf::Font font;

	sf::Sound hitSound;
	sf::Sound wingSound;
	sf::Sound pointSound;

	AssetsManager();
	~AssetsManager();
};

