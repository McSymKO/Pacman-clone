#include "pch.h"
#include "Pacman.h"

Pacman::Pacman()
	: tileX(14), tileY(23), mDir(Pacman_Directions::Directions::IDLE)
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

//Functions
void Pacman::move()
{
	if (mDir == Pacman_Directions::Directions::IDLE)
	{
		tileX += 0;
		tileY += 0;
	}

	else
	{
		switch (mDir)
		{
		case Pacman_Directions::Directions::UP:
			movementHandling(0, -1);
			break;
		case Pacman_Directions::Directions::DOWN:
			movementHandling(0, 1);
			break;
		case Pacman_Directions::Directions::LEFT:
			movementHandling(-1, 0);
			break;
		case Pacman_Directions::Directions::RIGHT:
			movementHandling(1, 0);
			break;
		}
	}
	mPlayer.setPosition(tileX * 16.f, tileY * 16.f);
}

void Pacman::movementHandling(int x, int y)
{
	tileX += x;
	tileY += y;
}

void Pacman::stop()
{
	mDir = Pacman_Directions::Directions::IDLE;
}

void Pacman::update(float& dt)
{
	setDirection();
}

void Pacman::render(sf::RenderTarget& target)
{
	target.draw(mPlayer);
}
