#include "AnimatedGround.h"
#include "Game.h"

AnimatedGround::AnimatedGround(sf::Texture& texture, float screenWidth, float screenHeight) : screenWidth(screenWidth)
{
	sprite.setTexture(texture);
	sprite.setScale(Game::SCALE, Game::SCALE);
	sprite.setPosition(0, screenHeight - texture.getSize().y * Game::SCALE);
}

void AnimatedGround::update(int ms)
{
	sprite.move(-SPEED * ms / 1000, 0.0f);

	if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < screenWidth)
		sprite.setPosition(0, sprite.getPosition().y);
}

void AnimatedGround::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

AnimatedGround::~AnimatedGround()
{
}
