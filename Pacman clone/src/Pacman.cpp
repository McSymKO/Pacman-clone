#include "pch.h"
#include "Pacman.h"

Pacman::Pacman()
	: mSpeed(50.f), tileX(14), tileY(17), mDir(Pacman_Directions::Directions::IDLE)
{
	mTexture.loadFromFile("Textures/animations.png", sf::IntRect(0, 0, 32, 30));
	mPlayer.setTexture(mTexture);

	//Position of Pacman
	sf::FloatRect textRect = mPlayer.getLocalBounds();
	mPlayer.setOrigin(textRect.left + textRect.width / 2.0f,
					  textRect.top + textRect.height / 2.0f);
	mPlayer.setPosition(sf::Vector2f(tileX * 16.f, 17.5f * 16.f));
}

//Getters & Setters
void Pacman::setDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		--tileY;
		mDir = Pacman_Directions::Directions::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		++tileY;
		mDir = Pacman_Directions::Directions::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		--tileX;
		mDir = Pacman_Directions::Directions::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		++tileX;
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
void Pacman::move(const float& dirX, const float& dirY, const float& dt)
{
	mPlayer.move(dirX * mSpeed * dt, dirY * mSpeed * dt);
}

void Pacman::update(float& dt)
{
	setDirection();
}

void Pacman::render(sf::RenderTarget& target)
{
	target.draw(mPlayer);
}
