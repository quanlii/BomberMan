#pragma once
#include "Point2D.h"
#include "Until.h"

class Map2D
{
public:
	Map2D();
	~Map2D();

	void	InitMap();
	void	DisplayMap();
private:
	Point2D _map[MAX_HEIGHT][MAX_WIDTH];
};

