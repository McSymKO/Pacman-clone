#pragma once

class Ghost
{
public:
	Ghost();

	void move();

	void update(float& dt);
	void render(sf::RenderTarget& target);

private:
	sf::Texture textureArray[4];
	sf::Sprite ghostArray[4];
	
};

