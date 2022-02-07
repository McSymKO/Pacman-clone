#include "pch.h"
#include "Pacman.h"

Pacman::Pacman()
	: tileX(14), tileY(23), movement(0.f, 0.f), mSpeed(40.f), mDir(Pacman_Directions::Directions::IDLE),
	points(0)
{
	mTexture.loadFromFile("Textures/things.png", sf::IntRect(0, 0, 15, 15));
	mPlayer.setTexture(mTexture);
	mPlayer.setScale(2.f, 2.f);

	//Position of Pacman
	sf::FloatRect rect = mPlayer.getLocalBounds();
	mPlayer.setOrigin(rect.left + rect.width / 2.0f,
		rect.top + rect.height / 2.0f);

	mPlayer.setPosition(sf::Vector2f(tileX * 16.f, tileY * 16.f + 8.f));
}

//Getters & Setters
void Pacman::setDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mDir = Pacman_Directions::Directions::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mDir = Pacman_Directions::Directions::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mDir = Pacman_Directions::Directions::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mDir = Pacman_Directions::Directions::RIGHT;
	}
}

void Pacman::setPosition(sf::Vector2f pos)
{
	mPlayer.setPosition(pos);
}

const int& Pacman::getTileX()
{
	return tileX;
}

const int& Pacman::getTileY()
{
	return tileY;
}

Pacman_Directions::Directions Pacman::getDirection()
{
	return mDir;
}

const sf::Vector2f& Pacman::getPosition() const
{
	return mPlayer.getPosition();
}

const float& Pacman::getSpeed() const
{
	return mSpeed;
}

const sf::Vector2f& Pacman::getMovement() const
{
	return movement;
}

const sf::FloatRect& Pacman::getBounds()
{
	return mPlayer.getGlobalBounds();
}

//Functions
void Pacman::move()
{
	movement.x = 0.f;
	movement.y = 0.f;

	switch (mDir)
	{
		case Pacman_Directions::Directions::UP:
			movement.y = -1.f;
			break;
		case Pacman_Directions::Directions::DOWN:
			movement.y = 1.f;
			break;
		case Pacman_Directions::Directions::LEFT:
			movement.x = -1.f;
			break;
		case Pacman_Directions::Directions::RIGHT:
			movement.x = 1.f;
			break;
	}
}

void Pacman::eatDot()
{
	++points;
}

void Pacman::update(float& dt)
{
	setDirection();
	move();
}

void Pacman::render(sf::RenderTarget& target)
{
	target.draw(mPlayer);
}
