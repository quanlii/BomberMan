#pragma once
#include "Point2D.h"
#include "Map2D.h"
#include "Until.h"

class Wall
{
public:
	Wall();
	~Wall();

	Point2D _wall[MAX_WALL];
	int		GetNumberOfWall();

	void	InitWall();
	void	DisplayWall();
private:
	int _numberOfWall;
};

