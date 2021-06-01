#pragma once

#include "TileMap.h"
#include "Pacman.h"

class Game
{
public:
	Game();
	~Game();

	const sf::FloatRect getTileBounds(int x, int y) const;

	void run();
	bool tileBlocksEntity(int x, int y);
	bool isGameRunning();
	bool isPacmanDead();

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
	const int tiles[28][31];

	//Delta time
	sf::Clock clock;
	float dt;

	//Entities
	Pacman pacman;
	bool pacmanDead;
};