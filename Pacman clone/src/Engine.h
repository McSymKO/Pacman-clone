#pragma once

class Engine
{
public:
	Engine();
	~Engine();

	void run();
	bool isGameRunning();

	void pollEvents();
	void updateDt();
	void update();
	void render();
	
private:
	sf::RenderWindow mWindow;
	bool gameRunning;

	sf::Clock clock;
	float dt;
};