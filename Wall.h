#pragma once
#include "Point2D.h"
#include "Map2D.h"
#include "Until.h"

class Wall
{
public:
	Wall(Map2D& map);
	~Wall();

	Point2D _wall[10000];
	int		GetNumberOfWall();

	void	InitWall(Map2D& map);
private:
	int _numberOfWall;
};
