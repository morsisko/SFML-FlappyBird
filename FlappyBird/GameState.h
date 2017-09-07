#pragma once
#include "State.h"
#include "Bird.h"

class GameState :
	public State
{
private:
	sf::Texture backgroundTexture;
	sf::Sprite background;

	Bird bird;
public:
	GameState(GameStateManager* manager, sf::RenderWindow* window);
	virtual void handleEvent(const sf::Event &event);
	virtual void render();
	virtual void update(int deltaTime);
	~GameState();
};

