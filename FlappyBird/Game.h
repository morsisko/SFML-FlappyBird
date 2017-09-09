#pragma once
#include <SFML\Graphics.hpp>
#include "GameStateManager.h"
#include "SplashScreen.h"
class Game
{
private:
	GameStateManager manager;
	sf::RenderWindow window;
	sf::Clock frameClock;
public:
	static constexpr float SCALE = 3.0f;

	Game(sf::String title, int width, int height);
	void start();
	~Game();
};

