#include "AnimatedGround.h"
#include "Game.h"

AnimatedGround::AnimatedGround(sf::Texture& texture, int screenWidth, int screenHeight) : screenWidth(static_cast<float>(screenWidth))
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

bool AnimatedGround::checkForCollision(Bird & bird)
{
	return Collision::BoundingBoxTest(bird.getSprite(), sprite);
}

void AnimatedGround::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

AnimatedGround::~AnimatedGround()
{
}
