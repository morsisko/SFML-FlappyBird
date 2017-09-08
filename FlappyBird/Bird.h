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
	float speed = 0.0f;

	static const int TEXTURE_WIDTH = 17;
	static const int TEXTURE_HEIGHT = 12;

	const float GRAVITY = 10.0f;

public:
	Bird();
	void update(int deltaTime);
	void jump();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~Bird();
};

