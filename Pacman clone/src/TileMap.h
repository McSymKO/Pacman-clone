#pragma once

class TileMap : public sf::Drawable
{
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int tiles[][31], unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

