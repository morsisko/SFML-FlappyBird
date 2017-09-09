#pragma once
#include <SFML\Graphics.hpp>

class Pipe :
	public sf::Drawable
{
private:
	sf::Sprite upperPipe;
	sf::Sprite bottomPipe;
	const float SPACE = 150.0f;
	const float SPEED = 10.0f;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Pipe(sf::Texture& upperTexture, sf::Texture& bottomTexture, float x, float y);
	void update(int ms);
	~Pipe();
};

