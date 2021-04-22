#pragma once

#include "TileMap.h"
#include "Pacman.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	bool isGameRunning();

	void pollEvents();
	void updateDt();
	void updatePacmanMovement();
	void update();
	void render();
	
private:
	sf::RenderWindow mWindow;
	bool gameRunning;

	//Map
	TileMap map;
	const int tiles[28][31];

	//Timer
	sf::Clock clock;
	float dt;

	//Entities
	Pacman pacman;
};