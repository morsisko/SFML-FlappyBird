#pragma once
#include <memory>
#include "State.h"
#include "AssetsManager.h"

class State;
class GameStateManager
{
private:
	std::unique_ptr<State> currentState;
	AssetsManager assets;
public:
	GameStateManager();
	void handleEvent(const sf::Event &event);
	void render();
	void update(int deltaTime);
	void setState(std::unique_ptr<State> state);
	AssetsManager& getAssets();
	~GameStateManager();
};

