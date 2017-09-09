#include "GameState.h"



GameState::GameState(GameStateManager* manager, sf::RenderWindow* window) : State(manager, window),
	bird(manager->getAssets().birdTexture)
{
	background.setTexture(manager->getAssets().backgroundTexture);
	background.setScale(SCALE, SCALE);
}

void GameState::handleEvent(const sf::Event & event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		bird.jump();
		break;
	default:
		break;
	}
}

void GameState::render()
{
	window->draw(background);
	window->draw(bird);
}

void GameState::update(int deltaTime)
{
	bird.update(deltaTime);
}


GameState::~GameState()
{
}
