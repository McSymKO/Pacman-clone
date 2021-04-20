#pragma once

#include "TileMap.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	bool isGameRunning();

	void pollEvents();
	void updateDt();
	void update();
	void render();
	
private:
	sf::RenderWindow mWindow;
	bool gameRunning;

	//Map
	TileMap map;

	//Timer
	sf::Clock clock;
	float dt;
};