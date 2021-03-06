#include "SplashScreen.h"



void SplashScreen::onTimeOver()
{
	manager->setState(std::make_unique<MenuState>(manager, window));
}

SplashScreen::SplashScreen(GameStateManager* manager, sf::RenderWindow* window, int miliseconds) : State(manager, window)
{
	const sf::Texture& splashTexture = manager->getAssets().splashTexture;
	splashSprite.setTexture(splashTexture);

	splashSprite.setPosition(window->getSize().x / 2.0f - splashTexture.getSize().x / 2.0f, window->getSize().y / 2.0f - splashTexture.getSize().y / 2.0f);

	this->disappearTime = miliseconds;
}

void SplashScreen::handleEvent(const sf::Event & event)
{
}

void SplashScreen::render()
{
	window->draw(splashSprite);
}

void SplashScreen::update(int deltaTime)
{
	elapsedTime += deltaTime;

	if (elapsedTime >= disappearTime)
		onTimeOver();
}


SplashScreen::~SplashScreen()
{
}
