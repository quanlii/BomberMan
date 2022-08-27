#include "Brick.h"
#include <iostream>
using namespace std;

Brick::Brick() {}

void Brick::InitBrick(Map2D* map)
{
	int x, y;
	for (int i = 0; i < _numberOfBrick; ++i)
	{
		while (true)
		{
			x = GetRandomNumber(MAX_WIDTH - 2) + 1;
			y = GetRandomNumber(MAX_HEIGHT - 2) + 1;
			if ((x < 3 && y < 3) || (x > 14 && y > 14)) continue;
			if (map->_map[y][x].GetC() == ' ')
			{
				_brick[i] = Point2D(x, y, 'B');
				map->_map[y][x] = _brick[i];
				_isDestroyed[y][x] = false;
				break;
			}
		}
	}
}

Brick::Brick(Map2D* map)
{
	_numberOfBrick = MAX_BRICK;
	for (int i = 0; i < MAX_HEIGHT; ++i)
		for (int j = 0; j < MAX_WIDTH; ++j) _isDestroyed[i][j] = true;
	InitBrick(map);
}

Brick::~Brick() {}

bool Brick::IsDestroyed()
{
	for (int i = 0; i < MAX_HEIGHT; ++i)
		for (int j = 0; j < MAX_WIDTH; ++j)
			if (!_isDestroyed[i][j]) return false;
	return true;
}

int Brick::GetNumberOfBrick() { return _numberOfBrick; }
