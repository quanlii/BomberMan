#pragma once
#include "Map2D.h"
#include "Point2D.h"
#include "Until.h"
#include "Bomb.h"
class Monster
{
public:
	Monster(Map2D map);
	~Monster();

	int		_start;

	void 	Move(Map2D& map, Bomb bomb);
	void	TurnUp(Map2D map, Point2D& monster, int& direction);
	void	TurnDown(Map2D map, Point2D& monster, int& direction);
	void	TurnLeft(Map2D map, Point2D& monster, int& direction);
	void	TurnRight(Map2D map, Point2D& monster, int& direction);
	void	Display();
	bool	CheckPosition(int x, int y, Map2D map);
private:
	Point2D _monster[MAX_MONSTER];
	int		_direction[MAX_MONSTER];
	bool	_checkDead[MAX_MONSTER];
};
