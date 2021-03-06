#pragma once
#include <SFML\Graphics.hpp>
#include "Collision.h"
#include "Bird.h"

class Pipe :
	public sf::Drawable
{
private:
	sf::Sprite upperPipe;
	sf::Sprite bottomPipe;
	bool skipped = false;
	const float SPEED = 150.0f;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	static constexpr float SPACE = 150.0f;

	Pipe(sf::Texture& upperTexture, sf::Texture& bottomTexture, float x, float y);
	void update(int ms);
	float getX();
	float getWidth();
	bool checkCollision(Bird& bird);
	void markAsSkipped();
	bool wasSkipped();
	~Pipe();
};

