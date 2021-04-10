#include "pch.h"
#include "Engine.h"

Engine::Engine()
	: gameRunning(true), dt()
{
	mWindow.create(sf::VideoMode(800, 600), "Pacman clone ", sf::Style::Close);
	mWindow.setFramerateLimit(144);
	std::cout << "[Engine]: Window created" << "\n";
}

Engine::~Engine()
{
	std::cout << "[Engine]: Game is over" << "\n";
}

bool Engine::isGameRunning()
{
	return gameRunning;
}

void Engine::pollEvents()
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

void Engine::updateDt()
{
	dt = clock.restart().asSeconds();
}

void Engine::update()
{
	pollEvents();
}

void Engine::render()
{
	mWindow.clear();

	mWindow.display();
}

void Engine::run()
{
	while (isGameRunning())
	{
		updateDt();
		update();
		render();
	}
}
