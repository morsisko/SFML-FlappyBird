#pragma once
#include <SFML\Graphics.hpp>

class Pipe :
	public sf::Drawable
{
private:
	sf::Sprite upperPipe;
	sf::Sprite bottomPipe;

public:
	Pipe();
	~Pipe();
};

