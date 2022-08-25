#pragma once
#include "Point2D.h"
#include "Map2D.h"

class Brick
{
public:
	Brick(Map2D &map);
	~Brick();

	Point2D _brick[MAX_BRICK];
	bool	_isDestroyed[MAX_BRICK];

	//bool	IsDestroyed();
	int		GetNumberOfBrick();
	void	InitBrick(Map2D &map);
	void	DisplayBrick();
private:
	int		_numberOfBrick;
};
