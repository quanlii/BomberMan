#pragma once
#include "Map2D.h"
#include "Point2D.h"
#include "Until.h"
#include <ctime>
class Monster
{
public:
	Monster();
	Monster(Map2D* map);
	~Monster();

	int		_start;
	Point2D _monster[MAX_MONSTER];
	bool	_checkDead[MAX_MONSTER];

	void 	Move(Map2D* map);
	void	TurnUp(Map2D* map, Point2D* monster, int& direction);
	void	TurnDown(Map2D* map, Point2D* monster, int& direction);
	void	TurnLeft(Map2D* map, Point2D* monster, int& direction);
	void	TurnRight(Map2D* map, Point2D* monster, int& direction);
	void	Display();
	bool	CheckPosition(int x, int y, Map2D* map);
	int		GetIdOfMonster(int x, int y);
	bool	IsDeadAll();
private:
	int		_direction[MAX_MONSTER];
};
