#pragma once
#include "Point2D.h"
#include "Until.h"
#include "UI.h"

class Map2D
{
public:
	Map2D();
	~Map2D();
	Point2D _map[MAX_HEIGHT][MAX_WIDTH];

	void	InitMap();
	void	DisplayMap();
	void	DisplayMapUI(sf::Sprite& spBackground, sf::Sprite& spWall, sf::Sprite& spBrick, sf::RenderWindow& window);
private:

};
