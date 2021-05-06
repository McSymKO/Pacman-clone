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
	Pacman_Directions::Directions getDirection();
	void setPosition(sf::Vector2f pos);
	const sf::Vector2f& getPosition();
	const float& getSpeed();

	//Functions
	void stop();

	void update(float& dt);
	void render(sf::RenderTarget& target);

private:
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	float mSpeed;

	Pacman_Directions::Directions mDir;
};

