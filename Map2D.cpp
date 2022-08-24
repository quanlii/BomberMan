#include "Map2D.h"

void Map2D::InitMap()
{
	for(int y = 0; y < MAX_HEIGHT; ++y)
		for (int x = 0; x < MAX_WIDTH; ++x)
		{
			if (x == 0 || x == MAX_WIDTH - 1 || y == 0 || y == MAX_HEIGHT - 1)
				_map[y][x] = Point2D(x, y, '#');
			else _map[y][x] = Point2D(x, y, ' ');
		}
}

Map2D::Map2D() { InitMap(); }

Map2D::~Map2D() {}

void Map2D::DisplayMap()
{
	for (int y = 0; y < MAX_HEIGHT; ++y)
		for (int x = 0; x < MAX_WIDTH; ++x)
		{
			GoToXY(x, y);
			_map[y][x].Display();
		}
}
