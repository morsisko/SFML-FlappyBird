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
	hitBuffer.loadFromFile("assets/sfx_hit.wav");
	wingBuffer.loadFromFile("assets/sfx_wing.wav");
	pointBuffer.loadFromFile("assets/sfx_point.wav");

	hitSound.setBuffer(hitBuffer);
	wingSound.setBuffer(wingBuffer);
	pointSound.setBuffer(pointBuffer);
}


AssetsManager::~AssetsManager()
{
}
