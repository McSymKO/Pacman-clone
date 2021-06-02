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
	const sf::Vector2f& getPosition() const;
	const int& getTileX();
	const int& getTileY();
	const float& getSpeed() const;
	const sf::Vector2f& getMovement() const;

	//Functions
	void move();
	void stop();

	void update(float& dt);
	void render(sf::RenderTarget& target);

private:
	sf::Texture mTexture;
	sf::Sprite mPlayer;

	sf::Vector2f movement;
	float mSpeed;

	int tileX;
	int tileY;

	Pacman_Directions::Directions mDir;
};

