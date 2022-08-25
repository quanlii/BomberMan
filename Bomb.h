#pragma once
#include "Point2D.h"
#include "Wall.h"
#include "Brick.h"
#include "Portal.h"
#include <ctime>

class Bomb
{
public:
	Bomb();
	~Bomb();

	Point2D _bomb;
	int		_power;
	bool	_isExplosion;
	int		_start;

	bool	BombExplosion(Map2D& map, Portal portal, Brick &brick, Point2D player);
	void	SetBomb(int x, int y, Map2D map);
	void	PowerUp();
private:

};