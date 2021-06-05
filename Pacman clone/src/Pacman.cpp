#include "pch.h"
#include "Pacman.h"

Pacman::Pacman()
	: tileX(14), tileY(23), mSpeed(5.f), mDir(Pacman_Directions::Directions::IDLE)
{
	mTexture.loadFromFile("Textures/things.png", sf::IntRect(0, 0, 15, 15));
	mPlayer.setTexture(mTexture);
	mPlayer.setScale((sf::Vector2f(2.f, 2.f)));

	//Position of Pacman
	sf::FloatRect textRect = mPlayer.getLocalBounds();
	mPlayer.setOrigin(textRect.left + textRect.width / 2.0f,
					  textRect.top + textRect.height / 2.0f);

	mPlayer.setPosition(sf::Vector2f(tileX * 16.f, tileY * 16.f + 8.f));
}

//Getters & Setters
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

void Pacman::setDirection(Pacman_Directions::Directions direction)
{
	mDir = direction;
}

const float& Pacman::getSpeed() const
{
	return mSpeed;
}

void Pacman::setMovement()
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

//Functions
void Pacman::move()
{
	switch (mDir)
	{
	case Pacman_Directions::Directions::IDLE:
		movement.x += 0.f;
		movement.y += 0.f;
		break;
	case Pacman_Directions::Directions::UP:
		movement.y -= 1.f;
		break;
	case Pacman_Directions::Directions::DOWN:
		movement.y += 1.f;
		break;
	case Pacman_Directions::Directions::LEFT:
		movement.x -= 1.f;
		break;
	case Pacman_Directions::Directions::RIGHT:
		movement.x += 1.f;
		break;
	}
}

void Pacman::stop()
{
	mDir = Pacman_Directions::Directions::IDLE;
}

void Pacman::update(float& dt)
{
	setMovement();
}

void Pacman::render(sf::RenderTarget& target)
{
	target.draw(mPlayer);
}
