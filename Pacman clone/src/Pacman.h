#pragma once

namespace Pacman_Directions
{
	enum class Directions
	{
		IDLE, LEFT, RIGHT, UP, DOWN
	};
}

class Pacman
{
public:
	Pacman();
	
	//Getters & Setters
	const int& getTileX();
	const int& getTileY();
	Pacman_Directions::Directions getDirection();
	void setDirection(Pacman_Directions::Directions direction);

	//Functions
	void setMovement();
	void move();
	void stop();

	void update(float& dt);
	void render(sf::RenderTarget& target);

private:
	sf::Texture mTexture;
	sf::Sprite mPlayer;

	int tileX;
	int tileY;

	Pacman_Directions::Directions mDir;
};

