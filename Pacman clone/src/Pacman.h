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
	const float& getSpeed() const;
	const sf::Vector2f& getMovement() const;
	const sf::Vector2f& getPosition() const;
	Pacman_Directions::Directions getDirection();

	void setPosition(sf::Vector2f pos);

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

	sf::Vector2f movement;
	float mSpeed;

	Pacman_Directions::Directions mDir;
};

