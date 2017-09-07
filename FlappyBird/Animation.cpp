#include "Animation.h"

Animation::Animation(int milisecondsPerFrame) : milisecondsPerFrame(milisecondsPerFrame)
{

}

void Animation::addFrame(sf::IntRect rect)
{
	frames.push_back(rect);
}

void Animation::update(int deltaTime, sf::Sprite & sprite)
{
	updateMiliseconds += deltaTime;

	if (updateMiliseconds >= milisecondsPerFrame)
	{
		updateMiliseconds = 0;

		currentFrame++;

		if (currentFrame >= frames.size())
			currentFrame = 0;

		sprite.setTextureRect(frames[currentFrame]);
	}
}

void Animation::setDefaultFrame(sf::Sprite& sprite)
{
	if (frames.empty())
		sprite.setTextureRect(sf::IntRect());

	else
		sprite.setTextureRect(frames.front());
}

Animation::~Animation()
{
}
