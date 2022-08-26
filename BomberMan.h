#pragma once
#include "Point2D.h"
#include "Wall.h"
#include "Brick.h"
#include "Portal.h"
#include "Bomb.h"

class BomberMan
{
public:
	BomberMan();
	~BomberMan();

	Point2D	_bomberMan;
	int		_speed;
	int		_liveLeft;
	char	_direction;
	int		_start;

	void	Move(Map2D& map, char direction, Bomb bomb);
	void	TurnUp(Map2D map);
	void	TurnDown(Map2D map);
	void	TurnLeft(Map2D map);
	void	TurnRight(Map2D map);
	void	Display();
	void	ResetBomberMan(Bomb &bomb);

	void	SetBomb(Bomb& bomb, Map2D& map);
	void	GetPortal(Map2D& map, Bomb& bomb, Portal portal);
	void	SpeedUp();
	bool	CheckIsDead();
	bool	CheckPosition(int x, int y, Map2D map);
private:

};
