#include "Wall.h"
#include <iostream>
using namespace std;

void Wall::InitWall()
{
	int x, y; bool check;
	for (int i = 0; i < _numberOfWall; ++i)
	{
		do
		{
			check = true;
			x = GetRandomNumber(MAX_WIDTH - 2) + 1;
			y = GetRandomNumber(MAX_HEIGHT - 2) + 1;
			for (int j = 0; j < i; ++j)
				if (x == _wall[j].GetX() && y == _wall[j].GetY()) { check = false; break; }
		} while (!check);
		_wall[i] = Point2D(x, y, 'W');
	}
}

Wall::Wall() 
{ 
	_numberOfWall = MAX_WALL;
	InitWall(); 
}

Wall::~Wall()
{
}

int Wall::GetNumberOfWall() { return _numberOfWall; }

void Wall::DisplayWall()
{
	for (int i = 0; i < _numberOfWall; ++i)
		_wall[i].Display();
}
