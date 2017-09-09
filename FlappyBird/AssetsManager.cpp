#include "AssetsManager.h"



AssetsManager::AssetsManager()
{
	birdTexture.loadFromFile("assets/bird.png");
	upperPipeTexture.loadFromFile("assets/upper.png");
	bottomPipeTexture.loadFromFile("assets/bottom.png");
	backgroundTexture.loadFromFile("assets/background.png");
	splashTexture.loadFromFile("assets/logo.png");
	groundTexture.loadFromFile("assets/ground.png");
	font.loadFromFile("assets/ariblk.ttf");
}


AssetsManager::~AssetsManager()
{
}
