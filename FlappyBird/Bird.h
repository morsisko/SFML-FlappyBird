#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class Bird :
	public sf::Drawable
{
private:
	Animation animation;
	sf::Texture birdTexture;
	sf::Sprite sprite;

	static const int TEXTURE_WIDTH = 17;
	static const int TEXTURE_HEIGHT = 12;
public:
	Bird();
	void update(int deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~Bird();
};

