#include <iostream>
#include "Point2D.h"
#include "Monster.h"
#include "Until.h"
using namespace std;

Monster::Monster(Map2D map)
{
	int x, y;
	for (int i = 0; i < MAX_MONSTER; ++i)
	{
		while (true)
		{
			x = GetRandomNumber(MAX_WIDTH - 2) + 1;
			y = GetRandomNumber(MAX_HEIGHT - 2) + 1;
			if (x < 3 && y < 3) continue;
			if (map._map[y][x].GetC() == ' ')
			{
				_monster[i] = Point2D(x, y, '$');
				break;
			}
		}
		_checkDead[i] = false;
		_direction[i] = 0;
	}
	_start = 0;
}

Monster :: ~Monster()
{
}

void Monster::Display()
{
	for (int i = 0; i < MAX_MONSTER; ++i)
		if (!_checkDead[i]) _monster[i].Display();
}

void Monster::TurnUp(Map2D map, Point2D& monster, int& direction)
{
	if (CheckPosition(monster.GetX(), monster.GetY() - 1, map)) monster.MoveUp();
	else direction = rand() % 4;
}

void Monster::TurnDown(Map2D map, Point2D& monster, int& direction)
{
	if (CheckPosition(monster.GetX(), monster.GetY() + 1, map)) monster.MoveDown();
	else direction = rand() % 4;
}

void Monster::TurnLeft(Map2D map, Point2D& monster, int& direction)
{
	if (CheckPosition(monster.GetX() - 1, monster.GetY(), map)) monster.MoveLeft();
	else direction = rand() % 4;
}

void Monster::TurnRight(Map2D map, Point2D& monster, int& direction)
{
	if (CheckPosition(monster.GetX() + 1, monster.GetY(), map)) monster.MoveRight();
	else direction = rand() % 4;
}

void Monster::Move(Map2D& map, Bomb bomb)
{
	if (((clock() - _start) / (double)CLOCKS_PER_SEC) < 0.5)
		return;
	for (int i = 0; i < MAX_MONSTER; ++i)
	{
		int x = _monster[i].GetX(), y = _monster[i].GetY();
		_monster[i].Clear();
		if (_direction[i] == 0) TurnUp(map, _monster[i], _direction[i]);
		else if (_direction[i] == 1) TurnDown(map, _monster[i], _direction[i]);
		else if (_direction[i] == 2) TurnLeft(map, _monster[i], _direction[i]);
		else if (_direction[i] == 3) TurnRight(map, _monster[i], _direction[i]);
	}
	_start = clock();
}

bool Monster::CheckPosition(int x, int y, Map2D map)
{
	if (map._map[y][x].GetC() == ' ') return true;
	return false;
}