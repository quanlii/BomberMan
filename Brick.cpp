#include "Brick.h"
#include <iostream>
using namespace std;

void Brick::InitBrick(Map2D &map)
{
	int x, y; bool check;
	for (int i = 0; i < _numberOfBrick; ++i)
	{
		while (true)
		{
			x = GetRandomNumber(MAX_WIDTH - 2) + 1;
			y = GetRandomNumber(MAX_HEIGHT - 2) + 1;
			if(map._map[y][x].GetC() == ' ') 
			{
				_brick[i] = Point2D(x, y, 'B');
				map._map[y][x] = _brick[i];
				break;
			}
		} 
		_isDestroyed[i] = false;
	}
}

Brick::Brick(Map2D &map)
{
	_numberOfBrick = MAX_BRICK;
	InitBrick(map);
}

Brick::~Brick() {}
 
void Brick::DisplayBrick()
{
	for (int i = 0; i < _numberOfBrick; ++i) _brick[i].Display();
}

//bool Brick::IsDestroyed() { return _isDestroyed; }

int Brick::GetNumberOfBrick() { return _numberOfBrick; }
