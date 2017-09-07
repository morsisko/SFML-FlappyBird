#include "GameState.h"



GameState::GameState(GameStateManager* manager, sf::RenderWindow* window) : State(manager, window)
{
	backgroundTexture.loadFromFile("assets/background.png");
	background.setTexture(backgroundTexture);
	background.setScale(3.0f, 3.0f);
}

void GameState::handleEvent(const sf::Event & event)
{
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
