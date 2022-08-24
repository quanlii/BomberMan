#pragma once
#include "Point2D.h"
#include "Wall.h"

class Brick
{
public:
	Brick(Wall wall);
	~Brick();

	Point2D _brick[MAX_BRICK];
	bool	IsDestroyed();
	int		GetNumberOfBrick();

	void	InitBrick(Wall wall);
	void	DisplayBrick();
private:
	int		_numberOfBrick;
	bool	_isDestroyed;
};

