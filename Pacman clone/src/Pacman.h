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
	void setDirection();
	const int& getTileX();
	const int& getTileY();
	Pacman_Directions::Directions getDirection();

	//Functions
	void move(const float& dirX, const float& dirY, const float& dt);

	void update(float& dt);
	void render(sf::RenderTarget& target);

private:
	sf::Texture mTexture;
	sf::Sprite mPlayer;

	int tileX;
	int tileY;

	float mSpeed;

	Pacman_Directions::Directions mDir;
};

