#include "Wall.h"
#include <iostream>
using namespace std;

void Wall::InitWall(Map2D& map)
{
	/*int x, y;
	for (int i = 0; i < _numberOfWall; ++i)
	{
		while (true)
		{
			x = GetRandomNumber(MAX_WIDTH - 2) + 1;
			y = GetRandomNumber(MAX_HEIGHT - 2) + 1;
			if(map._map[y][x].GetC() == ' ')
			{
				_wall[i] = Point2D(x, y, 'W');
				map._map[y][x] = _wall[i];
				break;
			}
		}
	}*/
	_numberOfWall = 0;
	for (int y = 2; y < MAX_HEIGHT - 1; y += 2)
		for (int x = 2; x < MAX_WIDTH - 1; x += 2)
		{
			_wall[_numberOfWall] = Point2D(x, y, 'W');
			map._map[y][x] = Point2D(x, y, 'W');
			_numberOfWall++;
		}
}

Wall::Wall(Map2D& map)
{
	_numberOfWall = 0;
	InitWall(map);
}

Wall::~Wall()
{
}

int Wall::GetNumberOfWall() { return _numberOfWall; }