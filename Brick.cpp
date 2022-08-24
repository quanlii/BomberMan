#include "Brick.h"
#include <iostream>
using namespace std;

void Brick::InitBrick(Wall wall)
{
	int x, y; bool check;
	for (int i = 0; i < _numberOfBrick; ++i)
	{
		do
		{
			check = true;
			x = GetRandomNumber(MAX_WIDTH - 2) + 1;
			y = GetRandomNumber(MAX_HEIGHT - 2) + 1;
			for (int j = 0; j < wall.GetNumberOfWall(); ++j)
				if (x == wall._wall[j].GetX() && y == wall._wall[j].GetY()) { check = false; break; }
			for(int j = 0; j < i; ++j)
				if (x == _brick[j].GetX() && y == _brick[j].GetY()) { check = false; break; }
		} while (!check);
		_brick[i] = Point2D(x, y, 'B');
	}
}

Brick::Brick(Wall wall)
{
	_numberOfBrick = MAX_BRICK;
	_isDestroyed = false;
	InitBrick(wall);
}

Brick::~Brick() {}
 
void Brick::DisplayBrick()
{
	for (int i = 0; i < _numberOfBrick; ++i) _brick[i].Display();
}

bool Brick::IsDestroyed() { return _isDestroyed; }

int Brick::GetNumberOfBrick() { return _numberOfBrick; }