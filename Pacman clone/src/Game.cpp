#include "pch.h"
#include "Game.h"

Game::Game()
	: gameRunning(true), dt(), pacmanDead(false),
	  tiles{ {1, 3, 3, 3, 3, 3, 3, 3, 3, 5, 44, 44, 44, 11, 44, 13, 44, 44, 44, 1, 3, 3, 3, 3, 7, 9, 3, 3, 3, 3, 5},
	  {10, 45, 45, 47, 45, 45, 45, 45, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 45, 45, 47, 15, 20, 45, 45, 45, 45, 12},
	  {10, 45, 23, 25, 27, 45, 39, 27, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 23, 27, 45, 22, 26, 45, 23, 27, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 35, 25, 25, 27, 45, 15, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 38, 26, 45, 22, 3, 3, 3, 26, 44, 38, 3, 3, 3, 26, 45, 22, 24, 24, 24, 26, 45, 15, 20, 45, 12},
	  {10, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 23, 25, 27, 45, 23, 25, 25, 25, 25, 25, 25, 27, 44, 39, 25, 25, 25, 27, 45, 39, 27, 45, 23, 25, 25, 37, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 22, 24, 24, 36, 23, 24, 24, 26, 44, 38, 24, 24, 24, 26, 45, 15, 20, 45, 22, 24, 24, 36, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 45, 45, 45, 15, 20, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 39, 27, 45, 15, 20, 44, 29, 2, 2, 2, 31, 44, 23, 27, 45, 15, 20, 45, 23, 27, 45, 15, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 15, 20, 45, 22, 26, 44, 13, 44, 44, 44, 11, 44, 15, 20, 45, 22, 26, 45, 15, 20, 45, 22, 26, 45, 12},
	  {10, 45, 45, 45, 45, 45, 15, 20, 45, 44, 44, 44, 33, 44, 44, 44, 11, 44, 15, 20, 45, 45, 45, 45, 15, 20, 45, 45, 45, 45, 12},
	  {43, 25, 25, 25, 27, 45, 15, 35, 25, 25, 27, 44, 44, 44, 44, 44, 11, 44, 15, 35, 25, 25, 27, 44, 15, 35, 25, 25, 27, 45, 12},
	  {42, 24, 24, 24, 26, 45, 15, 34, 24, 24, 26, 44, 44, 44, 44, 44, 11, 44, 15, 34, 24, 24, 26, 44, 15, 34, 24, 24, 26, 45, 12},
	  {10, 45, 45, 45, 45, 45, 15, 20, 45, 44, 44, 44, 32, 44, 44, 44, 11, 44, 15, 20, 45, 45, 45, 45, 15, 20, 45, 45, 45, 45, 12},
	  {10, 45, 23, 25, 27, 45, 15, 20, 45, 23, 27, 44, 13, 44, 44, 44, 11, 44, 15, 20, 45, 23, 27, 45, 15, 20, 45, 39, 27, 45, 12},
	  {10, 45, 15, 44, 21, 45, 38, 26, 45, 15, 20, 44, 28, 3, 3, 3, 30, 44, 22, 26, 45, 15, 21, 45, 22, 26, 45, 15, 21, 45, 12},
	  {10, 45, 15, 44, 21, 45, 45, 45, 45, 15, 20, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 23, 25, 25, 37, 35, 25, 25, 27, 44, 39, 25, 25, 25, 27, 45, 15, 21, 45, 23, 25, 25, 37, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 22, 24, 24, 24, 24, 24, 24, 26, 44, 38, 24, 24, 24, 26, 45, 38, 26, 45, 22, 24, 24, 36, 20, 45, 12},
	  {10, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 23, 25, 27, 45, 39, 27, 45, 23, 2, 2, 2, 27, 44, 39, 2, 2, 2, 27, 45, 23, 25, 25, 25, 27, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 34, 24, 24, 26, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 38, 26, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 22, 26, 45, 23, 27, 45, 38, 26, 45, 12},
	  {10, 45, 45, 47, 45, 45, 45, 45, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 45, 45, 47, 15, 20, 45, 45, 45, 45, 12},
	  {0, 2, 2, 2, 2, 2, 2, 2, 2, 4, 44, 44, 44, 11, 44, 13, 44, 44, 44, 0, 2, 2, 2, 2, 6, 8, 2, 2, 2, 2, 4}}
{
	//Window
	mWindow.create(sf::VideoMode(448, 496), "Pacman clone ", sf::Style::Close);
	mWindow.setFramerateLimit(60);
	std::cout << "[Game]: Window created" << "\n";

	//Tile map
	map.load("Textures/map.png", sf::Vector2u(16, 16), tiles, 28, 31);
}

Game::~Game()
{
	std::cout << "[Game]: Game is over" << "\n";
}

bool Game::isGameRunning()
{
	return gameRunning;
}

bool Game::isPacmanDead()
{
	return pacmanDead;
}

bool Game::pacmanCanMove()
{
	switch (pacman.getDirection())
	{
	case Pacman_Directions::Directions::UP:
		return !tileBlocksEntity(pacman.getTileX(), pacman.getTileY() - 1);
		break;
	case Pacman_Directions::Directions::DOWN:
		return !tileBlocksEntity(pacman.getTileX(), pacman.getTileY() + 1);
		break;
	case Pacman_Directions::Directions::LEFT:
		return !tileBlocksEntity(pacman.getTileX() - 1, pacman.getTileY());
		break;
	case Pacman_Directions::Directions::RIGHT:
		return !tileBlocksEntity(pacman.getTileX() + 1, pacman.getTileY());
		break;

	default:
		return false;
	}
}

void Game::pollEvents()
{
	sf::Event ev;

	while (mWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			gameRunning = false;
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameRunning = false;
	}
}

void Game::updatePacmanMovement()
{
	//Setting direction
	pacman.update(dt);

	//Tiles under pacman
	int pacmanTileX = pacman.getPosition().x / 16.f;
	int pacmanTileY = pacman.getPosition().y / 16.f;

	//Calculating new position
	sf::Vector2f newPosition = pacman.getPosition() + pacman.getMovement() * pacman.getSpeed() * dt;

	//if (pacmanCanMove())
		pacman.setPosition(newPosition);
	/*else
		pacman.stop();*/
}

void Game::updateDt()
{
	dt = clock.restart().asSeconds();
}

void Game::update()
{
	pollEvents();

	//Pacman movement
	updatePacmanMovement();
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(map);
	pacman.render(mWindow);
	mWindow.display();
}

void Game::run()
{
	while (isGameRunning())
	{
		updateDt();
		update();
		render();
	}
}

bool Game::tileBlocksEntity(int x, int y)
{
	return tiles[x][y] != 47 && tiles[x][y] != 45 && tiles[x][y] != 44;
}
