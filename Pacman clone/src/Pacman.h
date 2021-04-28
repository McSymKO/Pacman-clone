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
	void move(const float& dt);
	void stop();

	void update(float& dt);
	void render(sf::RenderTarget& target);

private:
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	float mSpeed;

	Pacman_Directions::Directions mDir;
};

