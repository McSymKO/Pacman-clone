#pragma once

#include "TileMap.h"
#include "Pacman.h"
#include "Ghost.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	bool tileBlocksEntity(int x, int y);
	bool isGameRunning();
	bool isPacmanDead();
	void pacmanCollision();
	void loop();

	void pollEvents();
	void updatePacmanMovement();
	void updateDt();
	void update();
	void render();
	
private:
	sf::RenderWindow mWindow;
	bool gameRunning;

	//Map
	TileMap map;
	int tiles[28][31];

	//Delta time
	sf::Clock clock;
	float dt;

	//Entities
	Pacman pacman;
	Ghost ghosts;
	bool pacmanDead;
};