#include "pch.h"
#include "Ghost.h"

Ghost::Ghost()
{
	//Mapping textures to sprites
	textureArray[0].loadFromFile("Textures/things.png", sf::IntRect(0, 15, 15, 15));
	ghostArray[0].setTexture(textureArray[0]);

	textureArray[1].loadFromFile("Textures/things.png", sf::IntRect(0, 30, 15, 15));
	ghostArray[1].setTexture(textureArray[1]);

	textureArray[2].loadFromFile("Textures/things.png", sf::IntRect(0, 45, 15, 15));
	ghostArray[2].setTexture(textureArray[2]);

	textureArray[3].loadFromFile("Textures/things.png", sf::IntRect(0, 60, 15, 15));
	ghostArray[3].setTexture(textureArray[3]);

	//Setting size
	for (int i = 0; i < 4; ++i)
	{
		ghostArray[i].setScale(2.f, 2.f);
	}

	//Fixing origin
	for (int i = 0; i < 4; ++i)
	{
		sf::FloatRect ghostRect = ghostArray[i].getLocalBounds();
		ghostArray[i].setOrigin(ghostRect.left + ghostRect.width / 2.0f,
			ghostRect.top + ghostRect.height / 2.0f);
	}

	//Positioning
	ghostArray[2].setPosition(12 * 16.f, 15 * 16.f);
	ghostArray[1].setPosition(14 * 16.f, 15 * 16.f);
	ghostArray[3].setPosition(16 * 16.f, 15 * 16.f);
	ghostArray[0].setPosition(14 * 16.f, 12 * 16.f - 8.f);
	
}

void Ghost::move()
{

}

void Ghost::update(float& dt)
{

}

void Ghost::render(sf::RenderTarget& target)
{
	for (const auto& ghost : ghostArray)
	{
		target.draw(ghost);
	}
}
